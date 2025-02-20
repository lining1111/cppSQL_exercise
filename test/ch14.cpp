//
// Created by lining on 2/20/25.
//
#include "dbCom/utils.h"
#include "dbCom/mydata.hpp"

// data/mydata.db---CH14_department CH14_employee
/*
 * CH14_department
 * id           部门id
 * name         部门名称
 *
 * CH14_employee
 * id           雇员id
 * name         雇员姓名
 * salary       薪资
 * departmentID 部门id
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
            stmt << " select D.name,E.name,E.salary from "
                    "(select name,salary,departmentID,rank() over (partition by departmentID order by salary desc ) as r from ch14_employee)  E "
                    "inner join ch14_department D on E.departmentID=D.id "
                    "where E.r=1;";
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