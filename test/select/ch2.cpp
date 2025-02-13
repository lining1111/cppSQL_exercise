//
// Created by lining on 2/12/25.
//

#include "dbCom/utils.h"

// data/mydata.db---product
/*
 * product
 * name         产品名称
 * price        价格
 * amount       库存
 * categoryID   分类
 * notes        备注
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
        // 查询价格最小/最大的
        if (0){
//            stmt << "select min(price) from product;";
            stmt << "select max(price) from product;";
            stmt.execute();
            RecordSet rs(stmt);
            showResult(rs);
        }
        //查询库存的总和/平均值
        if (0){
//            stmt << "select sum(amount) from product;";
            stmt << "select avg(amount) from product;";
            stmt.execute();
            RecordSet rs(stmt);
            showResult(rs);
        }
        //查询总共有多少个商品
        if (1){
            stmt << "select count(*) from product;";
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