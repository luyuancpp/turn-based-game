#include "mysql_database.h"

#include "mysql_database_table.pb.h"

using namespace common;

namespace database
{
void MysqlDatabase::Init()
{
    AddTable(account_database::default_instance());
    for (auto& it : tables_)
    {
        Execute(GetCreateTableSql(it.second.default_instance()));
        auto result =  query_one(it.second.GetDescSql());
        it.second.OnDesc(result);
        Execute(GetAlterTableAddFieldSql(it.second.default_instance()));
    }
}

}//namespace database

