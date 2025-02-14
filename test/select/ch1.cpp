//
// Created by lining on 2/12/25.
//

#include "dbCom/utils.h"
#include "dbCom/mydata.hpp"

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
        // 查询整体的结果
        if (1){
            stmt << "select name,price,amount,categoryID,notes from product;";
            stmt.execute();
            RecordSet rs(stmt);
            showResult(rs);
            //将结果存入到结构体内
            vector<mydata::Product> products;
            for (auto iter:rs) {
                mydata::Product item;
                item.name = iter.get(0).toString();
                item.price = strtof(iter.get(1).toString().c_str(), nullptr);
                item.amount = strtol(iter.get(2).toString().c_str(), nullptr,10);
                item.categoryID  = iter.get(3).toString();
                item.notes = iter.get(4).toString();
                products.push_back(item);
            }
        }


        // 按价格升序进行结果存储 order by xxx asc/desc
        if (0){
            stmt <<"select * from product order by price asc";
            stmt.execute();
            RecordSet rs1(stmt);
            showResult(rs1);
        }
        //查看价格大于1的并且/或者存储数量大于600的 where xxx and/or xxx
        if (0){
//            stmt <<"select * from product where price > 2 and amount > 600;";
            stmt <<"select * from product where price > 2 or amount > 600;";
            stmt.execute();
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