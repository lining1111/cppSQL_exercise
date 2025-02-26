//
// Created by lining on 2/26/25.
//
#include "dbCom/utils.h"
#include "dbCom/mydata.hpp"

// data/mydata.db---CH15_grade
/*
 * CH15_grade
 * id           id
 * job          工种
 * score        得分
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
            stmt << "with Avg_score as ( select job,avg(score) as score_avg from ch15_grade group by job ) "
                    "select ch15_grade.id,ch15_grade.job,ch15_grade.score from ch15_grade "
                    "join Avg_score on ch15_grade.job=Avg_score.job where ch15_grade.score>Avg_score.score_avg;";
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