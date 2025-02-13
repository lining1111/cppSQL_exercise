//
// Created by lining on 2/13/25.
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
        // 向product中添加一个新的物品种类，eggplant 2 2000 茄子 vegetable
        mydata::Product product{
                .name = "eggplant",
                .price = 2.0,
                .amount = 2000,
                .notes = "茄子",
                .categoryID = "vegetable",
        };

        if (1) {
            //这种方式，只能以变量名的形式用，直接给值，就写进sql的字符串就行
            stmt << "insert into product(name, price, amount, notes, categoryID) values(?,?,?,?,?);",
                    use(product.name), use(product.price), use(product.amount), use(product.notes), use(
                    product.categoryID);
            if (stmt.execute() <= 0) {
                ret = -1;
            }

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