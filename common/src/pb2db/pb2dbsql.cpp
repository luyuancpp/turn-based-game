#include "pb2dbsql.h"

#include <boost/algorithm/string.hpp>

#include "db_base.pb.h"
#include "src/util/utility.h"

namespace common
{
    const char* table_name[google::protobuf::FieldDescriptor::MAX_CPPTYPE + 1] =
    {
        "",
        "int NOT NULL  ",
        "bigint NOT NULL  ",
        "int unsigned NOT NULL  ",
        "bigint unsigned NOT NULL  ",
        "double NOT NULL DEFAULT '0'",
        "float NOT NULL DEFAULT '0'",
        "bool ",
        "int NOT NULL  ",
        "varchar(256)",
        "Blob",
    };

    static int32_t kPrimaryKeyIndex = 0;

#undef  GetMessage
    std::string ConvertFieldValue(const ::google::protobuf::Message& message, const google::protobuf::FieldDescriptor* fieldDesc)
    {
        const auto reflect = message.GetReflection();
        std::string field_value;
        switch (fieldDesc->cpp_type())
        {
        case google::protobuf::FieldDescriptor::CPPTYPE_INT32:
            field_value = std::to_string(reflect->GetInt32(message, fieldDesc));
            break;
        case google::protobuf::FieldDescriptor::CPPTYPE_UINT32:
            field_value = std::to_string(reflect->GetUInt32(message, fieldDesc));
            break;
        case google::protobuf::FieldDescriptor::CPPTYPE_FLOAT:
            field_value = std::to_string(reflect->GetFloat(message, fieldDesc));
            break;
        case google::protobuf::FieldDescriptor::CPPTYPE_STRING:
            field_value = reflect->GetString(message, fieldDesc);
            break;
        case google::protobuf::FieldDescriptor::CPPTYPE_INT64:
            field_value = std::to_string(reflect->GetInt64(message, fieldDesc));
            break;
        case  google::protobuf::FieldDescriptor::CPPTYPE_UINT64:
            field_value = std::to_string(reflect->GetUInt64(message, fieldDesc));
            break;
        case  google::protobuf::FieldDescriptor::CPPTYPE_DOUBLE:
            field_value = std::to_string(reflect->GetDouble(message, fieldDesc));
            break;
        case  google::protobuf::FieldDescriptor::CPPTYPE_BOOL:
            field_value = std::to_string(reflect->GetBool(message, fieldDesc));
            break;
        case google::protobuf::FieldDescriptor::CPPTYPE_MESSAGE://message结构的类型,有这个结构再序列化，没有的话就是空串;
            field_value = (reflect->HasField(message, fieldDesc)) ? (reflect->GetMessage(message, fieldDesc)).SerializeAsString() : "";
            break;
        default:
            return field_value;
        }
        return field_value;
    }

    void Pb2DbSql::fillMessageField(::google::protobuf::Message& message, const ResultRow& row)
    {
        const auto reflection = message.GetReflection();
        const auto p_desc = message.GetDescriptor();

        for (int32_t i = 0; i < message.GetDescriptor()->field_count(); ++i)
        {
            const ::google::protobuf::FieldDescriptor* fieldDesc = p_desc->FindFieldByName(p_desc->field(i)->name());

            switch (p_desc->field(i)->cpp_type())
            {
            case ::google::protobuf::FieldDescriptor::CPPTYPE_INT32:
            {
                int32_t type_value = StringToNumber<int32_t>(row[i]);
                reflection->SetInt32(&message, fieldDesc, type_value);
            }
            break;
            case ::google::protobuf::FieldDescriptor::CPPTYPE_INT64:
            {
                int64_t type_value = StringToNumber<int64_t>(row[i]);
                reflection->SetInt64(&message, fieldDesc, type_value);
            }
            break;
            case  ::google::protobuf::FieldDescriptor::CPPTYPE_UINT32:
            {
                uint32_t type_value = StringToNumber<uint32_t>(row[i]);
                reflection->SetUInt32(&message, fieldDesc, type_value);
            }
            break;
            case  ::google::protobuf::FieldDescriptor::CPPTYPE_UINT64:
            {
                uint64_t type_value = StringToNumber<uint64_t>(row[i]);
                reflection->SetUInt64(&message, fieldDesc, type_value);
            }
            break;
            case ::google::protobuf::FieldDescriptor::CPPTYPE_FLOAT:
            {
                float type_value = StringToNumber<float>(row[i]);
                reflection->SetFloat(&message, fieldDesc, type_value);
            }
            break;
            case ::google::protobuf::FieldDescriptor::CPPTYPE_STRING:
            {
                if (row[i] == nullptr)
                {
                    std::string type_value = "";
                    reflection->SetString(&message, fieldDesc, type_value);
                }
                else
                {
                    std::string type_value(row[i]);
                    reflection->SetString(&message, fieldDesc, type_value);
                }
            }
            break;
            case  ::google::protobuf::FieldDescriptor::CPPTYPE_DOUBLE:
            {
                double type_value = StringToNumber<double>(row[i]);
                reflection->SetDouble(&message, fieldDesc, type_value);
            }
            break;
            case  ::google::protobuf::FieldDescriptor::CPPTYPE_BOOL:
            {
                auto length = row.length(i);
                if (length != 0 && row[i] != nullptr)
                {
                    bool typeValue = StringToNumber<bool>(row[i]);
                    reflection->SetBool(&message, fieldDesc, typeValue);
                }
                else
                {
                    reflection->SetBool(&message, fieldDesc, false);
                }

            }
            break;
            case  ::google::protobuf::FieldDescriptor::CPPTYPE_MESSAGE:
            {
                auto length = row.length(i);
                if (length != 0 && row[i] != NULL)
                {
                    google::protobuf::Message* sub_message = reflection->MutableMessage(&message, fieldDesc);//不会为null;
                    sub_message->ParseFromArray(row[i], length);
                }
            }
            break;
            default:

                return;
            }
        }
    }

    std::string Pb2DbSql::GetCreateTableSql(const ::google::protobuf::Message& message)
    {
        std::string sql = "CREATE TABLE IF NOT EXISTS " + message.GetTypeName();

        const ::google::protobuf::MessageOptions& options = message.GetDescriptor()->options();
        primarykeys_.clear();
        indexes_.clear();
        auto_increase_key_.clear();
        foreign_keys_.clear();
        foreign_references_.clear();
        unique_keys_.clear();
        if (options.HasExtension(OptionPrimaryKey))
        {
            boost::split(primarykeys_, options.GetExtension(OptionPrimaryKey), boost::is_any_of(","));
        }
        if (options.HasExtension(OptionIndex))
        {
            boost::split(indexes_, options.GetExtension(OptionIndex), boost::is_any_of(","));
        }
        if (options.HasExtension(OptionUniqueKey))
        {
            boost::split(unique_keys_, options.GetExtension(OptionUniqueKey), boost::is_any_of(","));
        }
        auto_increase_key_ = options.GetExtension(OptionAutoIncrementKey);
        foreign_keys_ = options.GetExtension(OptionForeignKey);
        foreign_references_ = options.GetExtension(OptionForeignReferences);

        sql += " (";
        bool need_comma = false;
        for (int32_t i = 0; i < message.GetDescriptor()->field_count(); ++i)
        {
            if (need_comma == true)
            {
                sql += ", ";
            }
            else
            {
                need_comma = true;
            }
            sql += message.GetDescriptor()->field(i)->name();

            sql += " ";
            sql += table_name[message.GetDescriptor()->field(i)->cpp_type()];
            if (i == kPrimaryKeyIndex)
            {
                sql += " NOT NULL ";
            }
            if (message.GetDescriptor()->field(i)->name() == auto_increase_key_)
            {
                sql += " AUTO_INCREMENT ";
            }
        }

        sql += ", PRIMARY KEY (";
        sql += options.GetExtension(OptionPrimaryKey);
        sql += ")";
        if (!foreign_keys_.empty() && !foreign_references_.empty())
        {
            sql += ", FOREIGN KEY (";
            sql += foreign_keys_;
            sql += ")";
            sql += "REFERENCES ";
            sql += foreign_references_;
        }
        if (options.GetExtension(OptionUniqueKey).length() > 0)
        {
            sql += ", UNIQUE KEY (";
            sql += options.GetExtension(OptionUniqueKey);
            sql += ")";
        }

        for (const auto& it : indexes_)
        {
            sql += ",INDEX (";
            sql += it;
            sql += ")";
        }
        sql += ") ENGINE = INNODB ";
        if (sql.find("AUTO_INCREMENT") != std::string::npos)
        {
            if (message.GetTypeName() == "user")
            {
                sql += "AUTO_INCREMENT = " ;
            }
        }
        return sql;
    }

    std::string Pb2DbSql::GetAlterTableAddFieldSql(::google::protobuf::Message& message)
    {
        std::string sql;

        bool bNeedComma = false;
        bool bNeedAlter = false;
        sql += "ALTER TABLE " + message.GetTypeName();

        for (int32_t i = 0; i < message.GetDescriptor()->field_count(); ++i)
        {
            if (fileds_.find(message.GetDescriptor()->field(i)->name()) != fileds_.end())
            {
                continue;
            }

            bNeedAlter = true;
            sql += " ADD COLUMN ";
            sql += message.GetDescriptor()->field(i)->name();
            sql += " ";
            sql += table_name[message.GetDescriptor()->field(i)->cpp_type()];
            sql += ",";
        }
        sql[sql.length() - 1] = ';';
        if (bNeedAlter)
        {
            return sql;
        }
        else
        {
            return "";
        }

    }

    std::string Pb2DbSql::GetInsertSql(::google::protobuf::Message& message, MYSQL* mysql)
    {
        std::string sql = "INSERT INTO " + message.GetTypeName();
        sql += " (";
        bool bNeedComma = false;
        const ::google::protobuf::Descriptor* pDesc = message.GetDescriptor();
        const ::google::protobuf::FieldDescriptor* pFileDesc = NULL;
        for (int32_t i = 0; i < pDesc->field_count(); ++i)
        {

            if (bNeedComma == true)
            {
                sql += ", ";
            }
            else
            {
                bNeedComma = true;
            }

            sql += pDesc->field(i)->name();
        }

        sql += ") VALUES (";

        bNeedComma = false;
        for (int32_t i = 0; i < pDesc->field_count(); ++i)
        {

            if (bNeedComma == true)
            {
                sql += ", ";
            }
            else
            {
                bNeedComma = true;
            }

            pFileDesc = pDesc->FindFieldByName(pDesc->field(i)->name());
            std::string value = ConvertFieldValue(message, pFileDesc);
            EscapeString(value, mysql);
            sql += "'";
            sql += value;
            sql += "'";
        }
        sql += ")";
        return sql;
    }

    std::string Pb2DbSql::GetInsertOnDupUpdateSql(::google::protobuf::Message& message, MYSQL* mysql)
    {
        std::string sql = GetInsertSql(message, mysql);
        sql += " ON DUPLICATE KEY UPDATE ";
        sql += getUpdateSet(mysql, message);
        return sql;
    }

    void Pb2DbSql::EscapeString(std::string& str, MYSQL* mysql)
    {
        std::string buffer;
        // reserve space in the buffer according to the mysql documentation
        unsigned long resultSize = 0;
        buffer.resize(str.size() * 2 + 1);
        resultSize = mysql_real_escape_string(mysql, (char*)buffer.c_str(), str.c_str(), (unsigned long)str.size());
        buffer.resize(resultSize);
        str = buffer;
    }

    std::string Pb2DbSql::GetSelectSql(::google::protobuf::Message& pb, const std::string& key, const std::string& val)
    {
        const ::google::protobuf::FieldDescriptor* pFileDesc = pb.GetDescriptor()->FindFieldByName(pb.GetDescriptor()->field(kPrimaryKeyIndex)->name());
        if (NULL == pFileDesc)
        {
            return "";
        }
        std::string sql = "select ";
        bool bNeedComma = false;
        for (int32_t i = 0; i < pb.GetDescriptor()->field_count(); ++i)
        {
            if (bNeedComma == true)
            {
                sql += ", ";
            }
            else
            {
                bNeedComma = true;
            }

            sql += " " + pb.GetDescriptor()->field(i)->name();
        }

        sql += " from ";
        sql += pb.GetTypeName();
        if (!key.empty() && !val.empty())
        {
            sql += " where ";
            sql += key;
            sql += " = '";
            sql += val;
            sql += "'";
        }
        return sql;
    }

    std::string Pb2DbSql::GetSelectSql(::google::protobuf::Message& message, const std::string& where_clause)
    {
        const ::google::protobuf::FieldDescriptor* pFileDesc = message.GetDescriptor()->FindFieldByName(message.GetDescriptor()->field(kPrimaryKeyIndex)->name());
        if (NULL == pFileDesc)
        {
            return "";
        }
        std::string sql = "select ";
        bool bNeedComma = false;
        for (int32_t i = 0; i < message.GetDescriptor()->field_count(); ++i)
        {
            if (bNeedComma == true)
            {
                sql += ", ";
            }
            else
            {
                bNeedComma = true;
            }

            sql += " " + message.GetDescriptor()->field(i)->name();
        }

        sql += " from ";
        sql += message.GetTypeName();
        if (!where_clause.empty())
        {
            sql += " where ";
            sql += where_clause;
        }
        else
        {
            sql = "";
        }
        return sql;
    }

    std::string Pb2DbSql::GetSelectAllSql(::google::protobuf::Message& message)
    {
        const ::google::protobuf::FieldDescriptor* pFileDesc = message.GetDescriptor()->FindFieldByName(message.GetDescriptor()->field(kPrimaryKeyIndex)->name());
        if (NULL == pFileDesc)
        {
            return "";
        }
        std::string sql = "select ";
        bool bNeedComma = false;
        for (int32_t i = 0; i < message.GetDescriptor()->field_count(); ++i)
        {
            if (bNeedComma == true)
            {
                sql += ", ";
            }
            else
            {
                bNeedComma = true;
            }

            sql += " " + message.GetDescriptor()->field(i)->name();
        }
        sql += " from ";
        sql += message.GetTypeName();
        return sql;
    }

    std::string Pb2DbSql::GetDeleteSql(::google::protobuf::Message& message)
    {
        const ::google::protobuf::FieldDescriptor* pFileDesc = message.GetDescriptor()->FindFieldByName(message.GetDescriptor()->field(kPrimaryKeyIndex)->name());
        if (NULL == pFileDesc)
        {
            return "";
        }
        std::string sql = "delete ";
        sql += " from ";
        sql += message.GetTypeName();
        sql += " where ";
        sql += message.GetDescriptor()->field(kPrimaryKeyIndex)->name();
        std::string value = ConvertFieldValue(message, pFileDesc);
        sql += " = '";
        sql += value;
        sql += "'";;
        return sql;
    }

    std::string Pb2DbSql::GetDeleteSql(::google::protobuf::Message& message, const std::string& where_clause)
    {
        const ::google::protobuf::FieldDescriptor* pFileDesc = message.GetDescriptor()->FindFieldByName(message.GetDescriptor()->field(kPrimaryKeyIndex)->name());
        if (NULL == pFileDesc)
        {
            return "";
        }
        std::string sql = "delete ";

        sql += " from ";
        sql += message.GetTypeName();
        sql += " where ";
        if (!where_clause.empty())
        {
            sql += where_clause;
        }
        else
        {
            sql = "";
        }
        return sql;
    }

    std::string Pb2DbSql::GetReplaceSql(::google::protobuf::Message& pb, MYSQL* mysql)
    {
        std::string sql = "REPLACE INTO " + pb.GetTypeName();
        sql += " (";
        bool bNeedComma = false;
        const ::google::protobuf::Descriptor* pDesc = pb.GetDescriptor();
        const ::google::protobuf::FieldDescriptor* pFileDesc = NULL;
        for (int32_t i = 0; i < pDesc->field_count(); ++i)
        {
            if (bNeedComma == true)
            {
                sql += ", ";
            }
            else
            {
                bNeedComma = true;
            }
            sql += pDesc->field(i)->name();
        }
        sql += ") VALUES (";
        bNeedComma = false;
        for (int32_t i = 0; i < pDesc->field_count(); ++i)
        {
            if (bNeedComma == true)
            {
                sql += ", ";
            }
            else
            {
                bNeedComma = true;
            }
            pFileDesc = pDesc->FindFieldByName(pDesc->field(i)->name());
            std::string value = ConvertFieldValue(pb, pFileDesc);
            EscapeString(value, mysql);
            sql += "'";
            sql += value;
            sql += "'";
        }
        sql += ")";
        return sql;
    }

    std::string Pb2DbSql::getUpdateSet(MYSQL* mysql, ::google::protobuf::Message& message)
    {
        std::string sql;
        const ::google::protobuf::FieldDescriptor* pFileDesc = message.GetDescriptor()->FindFieldByName(message.GetDescriptor()->field(kPrimaryKeyIndex)->name());
        if (NULL == pFileDesc)
        {
            return "";
        }
        bool bNeedComma = false;
        int field_count = message.GetDescriptor()->field_count();
        for (int32_t i = 0; i < field_count; ++i)
        {
            const::std::string& field_name = message.GetDescriptor()->field(i)->name();
            pFileDesc = message.GetDescriptor()->FindFieldByName(field_name);
            const google::protobuf::Reflection* reflect = message.GetReflection();
            bool hasField = reflect->HasField(message, pFileDesc);
            if (hasField)
            {
                if (bNeedComma == true)
                {
                    sql += ", ";
                }
                else
                {
                    bNeedComma = true;
                }
                sql += " " + field_name;
                std::string value = ConvertFieldValue(message, pFileDesc);
                EscapeString(value, mysql);
                sql += "=";
                sql += "'";
                sql += value;
                sql += "'";
            }
        }
        return sql;
    }

    std::string Pb2DbSql::GetUpdateSql( ::google::protobuf::Message& message, MYSQL* mysql)
    {
        const ::google::protobuf::FieldDescriptor* pFileDesc = message.GetDescriptor()->FindFieldByName(message.GetDescriptor()->field(kPrimaryKeyIndex)->name());
        if (NULL == pFileDesc)
        {
            return "";
        }
        std::string sql = "UPDATE " + message.GetTypeName();
        bool bNeedComma = false;
        sql += " SET ";
        sql += getUpdateSet(mysql, message);
        sql += " where ";
        bNeedComma = false;
        for (auto& strPrimary : primarykeys_)
        {
            pFileDesc = message.GetDescriptor()->FindFieldByName(strPrimary);
            const google::protobuf::Reflection* reflect = message.GetReflection();
            bool hasField = reflect->HasField(message, pFileDesc);
            if (hasField)
            {
                if (bNeedComma == true)
                {
                    sql += " and ";
                }
                else
                {
                    bNeedComma = true;
                }
                sql += strPrimary;
                std::string value = ConvertFieldValue(message, pFileDesc);
                EscapeString(value, mysql);
                sql += "='";
                sql += value;
                sql += "'";
            }
        }
        return sql;
    }

    std::string Pb2DbSql::GetUpdateSql(::google::protobuf::Message& message, MYSQL* mysql, std::string where_clause)
    {
        const ::google::protobuf::FieldDescriptor* pFileDesc = message.GetDescriptor()->FindFieldByName(message.GetDescriptor()->field(kPrimaryKeyIndex)->name());
        if (NULL == pFileDesc)
        {
            return "";
        }
        std::string sql = "UPDATE " + message.GetTypeName();
        bool bNeedComma = false;
        sql += " SET ";
        for (int32_t i = 0; i < message.GetDescriptor()->field_count(); ++i)
        {
            if (bNeedComma == true)
            {
                sql += ", ";
            }
            else
            {
                bNeedComma = true;
            }
            sql += " " + message.GetDescriptor()->field(i)->name();
            pFileDesc = message.GetDescriptor()->FindFieldByName(message.GetDescriptor()->field(i)->name());
            std::string value = ConvertFieldValue(message, pFileDesc);
            EscapeString(value, mysql);
            sql += "=";

            sql += "'";
            sql += value;
            sql += "'";
        }

        if (!where_clause.empty())
        {
            sql += " where ";
            sql += where_clause;
        }
        else
        {
            sql = "";
        }
        return sql;
    }

    std::string Pb2DbSql::GetTruncateSql(::google::protobuf::Message& message)
    {
        std::string sql = "Truncate " + message.GetTypeName();
        return sql;
    }

    std::string Pb2DbTables::GetCreateTableSql(const ::google::protobuf::Message& message)
    {
        std::string table_name = message.GetTypeName();
        PbSqlMap::iterator it = tables_.find(table_name);
        if (it == tables_.end())
        {
            return "";
        }
        return it->second.GetCreateTableSql(message);
    }

    std::string Pb2DbTables::GetAlterTableAddFieldSql(::google::protobuf::Message& message)
    {
        std::string table_name = message.GetTypeName();
        PbSqlMap::iterator it = tables_.find(table_name);
        if (it == tables_.end())
        {
            return "";
        }
        return it->second.GetAlterTableAddFieldSql(message);
    }

    void Pb2DbTables::InsertFiled(const std::string& table_name, const std::string& field)
    {
        PbSqlMap::iterator it = tables_.find(table_name);
        if (it == tables_.end())
        {
            return;
        }
        return it->second.InsertFiled(field);
    }


    void Pb2DbTables::AddTable(const ::google::protobuf::Message& message_default_instance)
    {
        tables_.emplace(message_default_instance.GetTypeName(), Pb2DbSql(message_default_instance)); 
    }

    std::string Pb2DbTables::GetInsertSql(::google::protobuf::Message& message, MYSQL* mysql)
    {
        std::string table_name = message.GetTypeName();
        PbSqlMap::iterator it = tables_.find(table_name);
        if (it == tables_.end())
        {
            return "";
        }
        return it->second.GetInsertSql(message, mysql);
    }

    std::string Pb2DbTables::GetReplaceSql(::google::protobuf::Message& message, MYSQL* mysql)
    {
        std::string table_name = message.GetTypeName();
        PbSqlMap::iterator it = tables_.find(table_name);
        if (it != tables_.end())
        {
            return "";
        }
        return it->second.GetReplaceSql(message, mysql);
    }

    std::string Pb2DbTables::GetInsertOnDupUpdateSql(::google::protobuf::Message& message, MYSQL* mysql)
    {
        std::string table_name = message.GetTypeName();
        PbSqlMap::iterator it = tables_.find(table_name);
        if (it != tables_.end())
        {
            return "";
        }
        return it->second.GetInsertOnDupUpdateSql(message, mysql);
    }

    std::string Pb2DbTables::GetUpdateSql(::google::protobuf::Message& message, MYSQL* mysql)
    {
        std::string table_name = message.GetTypeName();
        PbSqlMap::iterator it = tables_.find(table_name);
        if (it != tables_.end())
        {
            return "";
        }
        return it->second.GetUpdateSql(message, mysql);
    }

    std::string Pb2DbTables::GetUpdateSql(::google::protobuf::Message& message, MYSQL* mysql, std::string where_clause)
    {
        std::string table_name = message.GetTypeName();
        PbSqlMap::iterator it = tables_.find(table_name);
        if (it != tables_.end())
        {
            return "";
        }
        return it->second.GetUpdateSql(message, mysql, where_clause);
    }

    std::string Pb2DbTables::GetSelectSql(::google::protobuf::Message& message, const std::string& key, const std::string& val)
    {
        std::string table_name = message.GetTypeName();
        PbSqlMap::iterator it = tables_.find(table_name);
        if (it != tables_.end())
        {
            return "";
        }
        return it->second.GetSelectSql(message, key, val);
    }

    std::string Pb2DbTables::GetSelectSql(::google::protobuf::Message& message, const std::string& where_clause)
    {
        std::string table_name = message.GetTypeName();
        PbSqlMap::iterator it = tables_.find(table_name);
        if (it != tables_.end())
        {
            return "";
        }
        return it->second.GetSelectSql(message, where_clause);
    }

    std::string Pb2DbTables::GetSelectAllSql(::google::protobuf::Message& message)
    {
        std::string table_name = message.GetTypeName();
        PbSqlMap::iterator it = tables_.find(table_name);
        if (it != tables_.end())
        {
            return "";
        }
        return it->second.GetSelectAllSql(message);
    }

    std::string Pb2DbTables::GetDeleteSql(::google::protobuf::Message& message)
    {
        std::string table_name = message.GetTypeName();
        PbSqlMap::iterator it = tables_.find(table_name);
        if (it != tables_.end())
        {
            return "";
        }
        return it->second.GetDeleteSql(message);
    }

    std::string Pb2DbTables::GetDeleteSql(::google::protobuf::Message& message, std::string where_clause)
    {
        std::string table_name = message.GetTypeName();
        PbSqlMap::iterator it = tables_.find(table_name);
        if (it != tables_.end())
        {
            return it->second.GetDeleteSql(message, where_clause);
        }
        return "";
    }

    std::string Pb2DbTables::GetTruncateSql(::google::protobuf::Message& message)
    {
        std::string table_name = message.GetTypeName();
        PbSqlMap::iterator it = tables_.find(table_name);
        if (it != tables_.end())
        {
            return "";
        }
        return it->second.GetTruncateSql(message);
    }

}//namespace common
