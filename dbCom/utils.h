//
// Created by lining on 2/12/25.
//

#ifndef UTILS_H
#define UTILS_H

#include <iostream>

using namespace std;

#include <Poco/Data/Session.h>
#include <Poco/Data/SQLite/SQLite.h>
#include <Poco/Data/SQLite/Connector.h>
#include <Poco/Data/SQLite/SQLiteException.h>
#include <Poco/Data/RecordSet.h>
//添加需要的的类
using namespace Poco;
using namespace Poco::Data;
using Poco::Data::Session;
using Poco::Data::Keywords::now;
using Poco::Data::Keywords::use;
using Poco::Data::Keywords::bind;
using Poco::Data::Keywords::into;
using Poco::Data::Statement;


void showResult(const RecordSet &rs);


#endif //UTILS_H
