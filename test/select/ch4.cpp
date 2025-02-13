//
// Created by lining on 2/12/25.
//

#include "dbCom/utils.h"

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
        // 查询所有有考试成绩的学生信息 inner join
        if (0){
            stmt << "select * from stu_info inner join stu_score where stu_info.id=stu_score.id;";
            stmt.execute();
            RecordSet rs(stmt);
            showResult(rs);
        }
        // 查询所有学生的考试信息 left join
        if (1){
            stmt << "select * from stu_info left join stu_score on stu_info.id=stu_score.id;";
            stmt.execute();
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