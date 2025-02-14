//
// Created by lining on 2/14/25.
//
#include "dbCom/utils.h"
#include "dbCom/mydata.hpp"

// data/mydata.db---ch13_products
/*
 * ch13_products
 * id           产品id
 * store        售卖商店
 * price        价格
 */

int main(int argc, char **argv) {
    int ret = 0;
    //1、注册
    SQLite::Connector::registerConnector();
    string dbFile = "data/mydata.db";
    try {
        //2、打开数据库
        Session session(SQLite::Connector::KEY, dbFile, 3);
        Statement stmt(session);
        stmt.reset(session);
        //3、操作
        if (1) {
            //查找每位用户旅行的总距离
            stmt << "select id as pid,ifnull(sum(case when store='s1' then price end),0) as 's1', ifnull(sum(case when store='s2' then price end),0) as 's2',ifnull(sum(case when store='s3' then price end),0) as 's3' from ch13_products group by id ;";
            if (stmt.execute() <= 0) {
                ret = -1;
            }
            RecordSet rs1(stmt);
            showResult(rs1);
        }

    } catch (Poco::Data::ConnectionFailedException &ex) {
        cout << ex.displayText();
        ret = -1;
    }
    catch (Poco::Data::SQLite::InvalidSQLStatementException &ex) {
        cout << ex.displayText();
        ret = -1;
    }
    catch (Poco::Data::ExecutionException &ex) {
        cout << ex.displayText();
        ret = -1;
    }
    catch (Poco::Exception &ex) {
        cout << ex.displayText();
        ret = -1;
    }

    //4、注销
    SQLite::Connector::unregisterConnector();
    return ret;
}