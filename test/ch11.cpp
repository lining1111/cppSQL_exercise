//
// Created by lining on 2/14/25.
//
#include "dbCom/utils.h"
#include "dbCom/mydata.hpp"

// data/mydata.db---customers、orders
/*
 * customers
 * id           用户id
 * name         用户名
 *
 * orders
 * id           订单id
 * customerID   下单用户ID
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
            //查看没有下过订单的用户
//            stmt << "select name as customer from customers A where id not in (select customerID from orders);";
            stmt << "select name as customer from customers A left join orders B on A.id=B.customerID where B.customerID is null;";
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