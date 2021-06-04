#include "db_table.h"

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

    void DBTable::fillMessageField(::google::protobuf::Message& pb, const ResultRow& row)
    {
        const auto reflection = pb.GetReflection();
        const auto p_desc = pb.GetDescriptor();

        for (int32_t i = 0; i < pb.GetDescriptor()->field_count(); ++i)
        {
            const ::google::protobuf::FieldDescriptor* fieldDesc = p_desc->FindFieldByName(p_desc->field(i)->name());

            switch (p_desc->field(i)->cpp_type())
            {
            case ::google::protobuf::FieldDescriptor::CPPTYPE_INT32:
            {
                int32_t type_value = StringToNumber<int32_t>(row[i]);
                reflection->SetInt32(&pb, fieldDesc, type_value);
            }
            break;
            case ::google::protobuf::FieldDescriptor::CPPTYPE_INT64:
            {
                int64_t type_value = StringToNumber<int64_t>(row[i]);
                reflection->SetInt64(&pb, fieldDesc, type_value);
            }
            break;
            case  ::google::protobuf::FieldDescriptor::CPPTYPE_UINT32:
            {
                uint32_t type_value = StringToNumber<uint32_t>(row[i]);
                reflection->SetUInt32(&pb, fieldDesc, type_value);
            }
            break;
            case  ::google::protobuf::FieldDescriptor::CPPTYPE_UINT64:
            {
                uint64_t type_value = StringToNumber<uint64_t>(row[i]);
                reflection->SetUInt64(&pb, fieldDesc, type_value);
            }
            break;
            case ::google::protobuf::FieldDescriptor::CPPTYPE_FLOAT:
            {
                float type_value = StringToNumber<float>(row[i]);
                reflection->SetFloat(&pb, fieldDesc, type_value);
            }
            break;
            case ::google::protobuf::FieldDescriptor::CPPTYPE_STRING:
            {
                if (row[i] == nullptr)
                {
                    std::string type_value = "";
                    reflection->SetString(&pb, fieldDesc, type_value);
                }
                else
                {
                    std::string type_value(row[i]);
                    reflection->SetString(&pb, fieldDesc, type_value);
                }
            }
            break;
            case  ::google::protobuf::FieldDescriptor::CPPTYPE_DOUBLE:
            {
                double type_value = StringToNumber<double>(row[i]);
                reflection->SetDouble(&pb, fieldDesc, type_value);
            }
            break;
            case  ::google::protobuf::FieldDescriptor::CPPTYPE_BOOL:
            {
                auto length = row.length(i);
                if (length != 0 && row[i] != nullptr)
                {
                    bool typeValue = StringToNumber<bool>(row[i]);
                    reflection->SetBool(&pb, fieldDesc, typeValue);
                }
                else
                {
                    reflection->SetBool(&pb, fieldDesc, false);
                }

            }
            break;
            case  ::google::protobuf::FieldDescriptor::CPPTYPE_MESSAGE:
            {
                auto length = row.length(i);
                if (length != 0 && row[i] != NULL)
                {
                    google::protobuf::Message* sub_message = reflection->MutableMessage(&pb, fieldDesc);//不会为null;
                    sub_message->ParseFromArray(row[i], length);
                }
            }
            break;
            default:

                return;
            }
        }
    }

    std::string DBTable::GetCreateTableSql(::google::protobuf::Message& pb)
    {
        std::string sql = "CREATE TABLE IF NOT EXISTS " + pb.GetTypeName();

        const ::google::protobuf::MessageOptions& options = pb.GetDescriptor()->options();
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
        for (int32_t i = 0; i < pb.GetDescriptor()->field_count(); ++i)
        {
            if (need_comma == true)
            {
                sql += ", ";
            }
            else
            {
                need_comma = true;
            }
            sql += pb.GetDescriptor()->field(i)->name();

            sql += " ";
            sql += table_name[pb.GetDescriptor()->field(i)->cpp_type()];
            if (i == kPrimaryKeyIndex)
            {
                sql += " NOT NULL ";
            }
            if (pb.GetDescriptor()->field(i)->name() == auto_increase_key_)
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
            if (pb.GetTypeName() == "user")
            {
                
                sql += "AUTO_INCREMENT = " ;
            }
        }
        return sql;
    }

    std::string DBTable::GetAlterTableAddFieldSql(::google::protobuf::Message& pb)
    {
        std::string sql;

        bool bNeedComma = false;
        bool bNeedAlter = false;
        sql += "ALTER TABLE " + pb.GetTypeName();

        for (int32_t i = 0; i < pb.GetDescriptor()->field_count(); ++i)
        {
            if (fileds_.find(pb.GetDescriptor()->field(i)->name()) != fileds_.end())
            {
                continue;
            }

            bNeedAlter = true;
            sql += " ADD COLUMN ";
            sql += pb.GetDescriptor()->field(i)->name();
            sql += " ";
            sql += table_name[pb.GetDescriptor()->field(i)->cpp_type()];
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

    std::string DBTable::GetInsertSql(MYSQL* conn, ::google::protobuf::Message& pb)
    {
        std::string sql = "INSERT INTO " + pb.GetTypeName();
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
            escapeString(value, conn);
            sql += "'";
            sql += value;
            sql += "'";
        }
        sql += ")";
        return sql;
    }

    std::string DBTable::GetInsertOnDupUpdateSql(MYSQL* conn, ::google::protobuf::Message& pb)
    {
        std::string sql = GetInsertSql(conn, pb);
        sql += " ON DUPLICATE KEY UPDATE ";
        sql += getUpdateSet(conn, pb);
        return sql;
    }

    void DBTable::escapeString(std::string& str, MYSQL* conn)
    {
        std::string buffer;
        // reserve space in the buffer according to the mysql documentation
        unsigned long resultSize = 0;
        buffer.resize(str.size() * 2 + 1);
        resultSize = mysql_real_escape_string(conn, (char*)buffer.c_str(), str.c_str(), (unsigned long)str.size());
        buffer.resize(resultSize);
        str = buffer;
    }

    std::string DBTable::GetSelectSql(::google::protobuf::Message& pb, const std::string& key, const std::string& val)
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

    std::string DBTable::GetSelectSql(::google::protobuf::Message& pb, const std::string& where_clause)
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

    std::string DBTable::GetSelectAllSql(::google::protobuf::Message& pb)
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
        return sql;
    }

    std::string DBTable::GetDeleteSql(::google::protobuf::Message& pb)
    {
        const ::google::protobuf::FieldDescriptor* pFileDesc = pb.GetDescriptor()->FindFieldByName(pb.GetDescriptor()->field(kPrimaryKeyIndex)->name());
        if (NULL == pFileDesc)
        {
            return "";
        }
        std::string sql = "delete ";
        sql += " from ";
        sql += pb.GetTypeName();
        sql += " where ";
        sql += pb.GetDescriptor()->field(kPrimaryKeyIndex)->name();
        std::string value = ConvertFieldValue(pb, pFileDesc);
        sql += " = '";
        sql += value;
        sql += "'";;
        return sql;
    }

    std::string DBTable::GetDeleteSql(::google::protobuf::Message& pb, const std::string& where_clause)
    {
        const ::google::protobuf::FieldDescriptor* pFileDesc = pb.GetDescriptor()->FindFieldByName(pb.GetDescriptor()->field(kPrimaryKeyIndex)->name());
        if (NULL == pFileDesc)
        {
            return "";
        }
        std::string sql = "delete ";

        sql += " from ";
        sql += pb.GetTypeName();
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

    std::string DBTable::GetReplaceSql(MYSQL* conn, ::google::protobuf::Message& pb)
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
            escapeString(value, conn);
            sql += "'";
            sql += value;
            sql += "'";
        }
        sql += ")";
        return sql;
    }

    std::string DBTable::getUpdateSet(MYSQL* conn, ::google::protobuf::Message& pb)
    {
        std::string sql;
        const ::google::protobuf::FieldDescriptor* pFileDesc = pb.GetDescriptor()->FindFieldByName(pb.GetDescriptor()->field(kPrimaryKeyIndex)->name());
        if (NULL == pFileDesc)
        {
            return "";
        }
        bool bNeedComma = false;
        int field_count = pb.GetDescriptor()->field_count();
        for (int32_t i = 0; i < field_count; ++i)
        {
            const::std::string& field_name = pb.GetDescriptor()->field(i)->name();
            pFileDesc = pb.GetDescriptor()->FindFieldByName(field_name);
            const google::protobuf::Reflection* reflect = pb.GetReflection();
            bool hasField = reflect->HasField(pb, pFileDesc);
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
                std::string value = ConvertFieldValue(pb, pFileDesc);
                escapeString(value, conn);
                sql += "=";
                sql += "'";
                sql += value;
                sql += "'";
            }
        }
        return sql;
    }

    std::string DBTable::GetUpdateSql(MYSQL* conn, ::google::protobuf::Message& pb)
    {
        const ::google::protobuf::FieldDescriptor* pFileDesc = pb.GetDescriptor()->FindFieldByName(pb.GetDescriptor()->field(kPrimaryKeyIndex)->name());
        if (NULL == pFileDesc)
        {
            return "";
        }
        std::string sql = "UPDATE " + pb.GetTypeName();
        bool bNeedComma = false;
        sql += " SET ";
        sql += getUpdateSet(conn, pb);
        sql += " where ";
        bNeedComma = false;
        for (auto& strPrimary : primarykeys_)
        {
            pFileDesc = pb.GetDescriptor()->FindFieldByName(strPrimary);
            const google::protobuf::Reflection* reflect = pb.GetReflection();
            bool hasField = reflect->HasField(pb, pFileDesc);
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
                std::string value = ConvertFieldValue(pb, pFileDesc);
                escapeString(value, conn);
                sql += "='";
                sql += value;
                sql += "'";
            }
        }
        return sql;
    }

    std::string DBTable::GetUpdateSql(MYSQL* conn, ::google::protobuf::Message& pb, std::string where_clause)
    {
        const ::google::protobuf::FieldDescriptor* pFileDesc = pb.GetDescriptor()->FindFieldByName(pb.GetDescriptor()->field(kPrimaryKeyIndex)->name());
        if (NULL == pFileDesc)
        {
            return "";
        }
        std::string sql = "UPDATE " + pb.GetTypeName();
        bool bNeedComma = false;
        sql += " SET ";
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
            pFileDesc = pb.GetDescriptor()->FindFieldByName(pb.GetDescriptor()->field(i)->name());
            std::string value = ConvertFieldValue(pb, pFileDesc);
            escapeString(value, conn);
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

    std::string DBTable::GetTruncateSql(::google::protobuf::Message& pb)
    {
        std::string sql = "Truncate " + pb.GetTypeName();
        return sql;
    }

    std::string DbTable::GetCreateTableSql(::google::protobuf::Message& pb)
    {
        std::string table_name = pb.GetTypeName();
        PbTableMap::iterator it = tables_.find(table_name);
        if (it == tables_.end())
        {
            return "";
        }
        return it->second.GetCreateTableSql(pb);
    }

    std::string DbTable::GetAlterTableAddFieldSql(::google::protobuf::Message& pb)
    {
        std::string table_name = pb.GetTypeName();
        PbTableMap::iterator it = tables_.find(table_name);
        if (it == tables_.end())
        {
            return "";
        }
        return it->second.GetAlterTableAddFieldSql(pb);
    }

    void DbTable::InsertFiled(const std::string& table_name, const std::string& field)
    {
        PbTableMap::iterator it = tables_.find(table_name);
        if (it == tables_.end())
        {
            return;
        }
        return it->second.InsertFiled(field);
    }

    std::string DbTable::GetInsertSql(MYSQL* mysql_conection, ::google::protobuf::Message& pb)
    {
        std::string table_name = pb.GetTypeName();
        PbTableMap::iterator it = tables_.find(table_name);
        if (it == tables_.end())
        {
            return "";
        }
        return it->second.GetInsertSql(mysql_conection, pb);
    }

    std::string DbTable::GetReplaceSql(MYSQL* mysql_conection, ::google::protobuf::Message& pb)
    {
        std::string table_name = pb.GetTypeName();
        PbTableMap::iterator it = tables_.find(table_name);
        if (it != tables_.end())
        {
            return "";
        }
        return it->second.GetReplaceSql(mysql_conection, pb);
    }

    std::string DbTable::GetInsertOnDupUpdateSql(MYSQL* mysql_conection, ::google::protobuf::Message& pb)
    {
        std::string table_name = pb.GetTypeName();
        PbTableMap::iterator it = tables_.find(table_name);
        if (it != tables_.end())
        {
            return "";
        }
        return it->second.GetInsertOnDupUpdateSql(mysql_conection, pb); 
    }

    std::string DbTable::GetUpdateSql(MYSQL* mysql_conection, ::google::protobuf::Message& pb)
    {
        std::string table_name = pb.GetTypeName();
        PbTableMap::iterator it = tables_.find(table_name);
        if (it != tables_.end())
        {
            return "";
        }
        return it->second.GetUpdateSql(mysql_conection, pb);
    }

    std::string DbTable::GetUpdateSql(MYSQL* mysql_conection, ::google::protobuf::Message& pb, std::string where_clause)
    {
        std::string table_name = pb.GetTypeName();
        PbTableMap::iterator it = tables_.find(table_name);
        if (it != tables_.end())
        {
            return "";
        }
        return it->second.GetUpdateSql(mysql_conection, pb, where_clause);
    }

    std::string DbTable::GetSelectSql(::google::protobuf::Message& pb, const std::string& key, const std::string& val)
    {
        std::string table_name = pb.GetTypeName();
        PbTableMap::iterator it = tables_.find(table_name);
        if (it != tables_.end())
        {
            return "";
        }
        return it->second.GetSelectSql(pb, key, val);
    }

    std::string DbTable::GetSelectSql(::google::protobuf::Message& pb, const std::string& where_clause)
    {
        std::string table_name = pb.GetTypeName();
        PbTableMap::iterator it = tables_.find(table_name);
        if (it != tables_.end())
        {
            return "";
        }
        return it->second.GetSelectSql(pb, where_clause);
    }

    std::string DbTable::GetSelectAllSql(::google::protobuf::Message& pb)
    {
        std::string table_name = pb.GetTypeName();
        PbTableMap::iterator it = tables_.find(table_name);
        if (it != tables_.end())
        {
            return "";
        }
        return it->second.GetSelectAllSql(pb);
    }

    std::string DbTable::GetDeleteSql(::google::protobuf::Message& pb)
    {
        std::string table_name = pb.GetTypeName();
        PbTableMap::iterator it = tables_.find(table_name);
        if (it != tables_.end())
        {
            return "";
        }
        return it->second.GetDeleteSql(pb);
    }

    std::string DbTable::GetDeleteSql(::google::protobuf::Message& pb, std::string where_clause)
    {
        std::string table_name = pb.GetTypeName();
        PbTableMap::iterator it = tables_.find(table_name);
        if (it != tables_.end())
        {
            return it->second.GetDeleteSql(pb, where_clause);
        }
        return "";
    }

    std::string DbTable::GetTruncateSql(::google::protobuf::Message& pb)
    {
        std::string table_name = pb.GetTypeName();
        PbTableMap::iterator it = tables_.find(table_name);
        if (it != tables_.end())
        {
            return "";
        }
        return it->second.GetTruncateSql(pb);
    }

}//namespace common
