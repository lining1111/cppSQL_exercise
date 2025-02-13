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
        // 查询所有有成绩的考生的总成绩
        if (0){
            stmt << "select distinct id,name,sum(score) over (partition by id) as total from stu_score;";
            stmt.execute();
            RecordSet rs(stmt);
            showResult(rs);
        }
        // 查询所有有成绩的考生的平均成绩
        if (0){
            stmt << "select distinct id,name,avg(score) over (partition by id) as avg from stu_score;";
            stmt.execute();
            RecordSet rs(stmt);
            showResult(rs);
        }
        // 查询所有有成绩的考生的最高/最低科目成绩,带科目名称
        if (1){
            //最高
//            stmt << "with t_r as ( select id,name,subject,score,rank() over (partition by id order by score desc ) as rank from stu_score) select id,name,subject,score from t_r where rank=1;";
            //最低
            stmt << "with t_r as ( select id,name,subject,score,rank() over (partition by id order by score asc ) as rank from stu_score) select id,name,subject,score from t_r where rank=1;";
            stmt.execute();
            RecordSet rs(stmt);
            showResult(rs);
        }
        // 查询所有有成绩的考生的最高/最低科目成绩,不带科目名称
        if (1){
            //最高
//            stmt << "select distinct id,name,first_value(score) over (partition by id order by score  desc ) as score from stu_score;";
            //最低
            stmt << "select distinct id,name,first_value(score) over (partition by id order by score  asc ) as score from stu_score;";
            stmt.execute();
            RecordSet rs(stmt);
            showResult(rs);
        }


        // 查询所有参加考试的学生成绩，并对每个学生自己的各科成绩进行排名
        if (1){
            stmt << "select id,name,subject,score,row_number() over (partition by id order by score desc ) from stu_score;";
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