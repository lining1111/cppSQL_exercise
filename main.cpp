
#include "dbCom/utils.h"

int main() {
    cout << "sql exercise base Poco and sqlite" << endl;
    cout << "follow website @ https://www.bilibili.com/video/BV1V3DUYtEjt/" << endl;

    int ret = 0;
    //1、注册
    SQLite::Connector::registerConnector();

    try {
        //2、打开数据库
        //3、操作
        //获取所有表结构
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
