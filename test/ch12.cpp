//
// Created by lining on 2/14/25.
//
#include "dbCom/utils.h"
#include "dbCom/mydata.hpp"

// data/mydata.db---users、rides
/*
 * users
 * id           用户id
 * name         用户名
 *
 * rides
 * id           旅行id
 * userID       用户ID
 * distance     旅行距离
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
            stmt << "select A.name,ifnull(sum(B.distance),0) as distance from users A left join rides B on A.id=B.userID group by A.id order by 2 desc,1 asc;";
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