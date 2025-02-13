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
        // 更新product中添加一个新的物品种类，eggplant 价格变为2.5 库存为3000
        mydata::Product product{
                .name = "eggplant",
                .price = 2.5,
                .amount = 3000,
        };

        if (1) {
            //这种方式，只能以变量名的形式用，直接给值，就写进sql的字符串就行
            stmt << "update product set price=?,amount=? where name=?;",
                    use(product.price), use(product.amount), use(product.name);
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