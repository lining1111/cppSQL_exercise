//
// Created by lining on 2/13/25.
//
#include "dbCom/utils.h"
#include "dbCom/mydata.hpp"

// data/mydata.db---stu_info stu_score
/*
 *  stu_info
 *  id                  学号
 *  name                姓名
 *  age                 年龄
 *  height              身高
 *  weight              体重
 *  birthday            生日
 *  id_card_number      身份证号码
 *  telephone_number    电话号码
 *  email               电子邮件
 *
 *  stu_score
 *  id                  学号
 *  name                姓名
 *  subject             科目
 *  score               得分
 *  record_date         考试时间
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
        // stu_score表中，score大于95的为优秀 大于90为良 大于85为及格,其他不及格
        if (1) {
            //这种方式，只能以变量名的形式用，直接给值，就写进sql的字符串就行
            stmt << "select id,name,subject,score,(case when score>95 then '优秀' when score>90 then '良' when score>85 then '及格' else '不及格' end) as evaluate from stu_score;";
            if (stmt.execute() <= 0) {
                ret = -1;
            }

            RecordSet rs(stmt);
            showResult(rs);

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