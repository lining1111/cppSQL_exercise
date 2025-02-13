//
// Created by lining on 2/13/25.
//

#ifndef MYDATA_HPP
#define MYDATA_HPP

#include <string>
#include <vector>
#include <cstdint>

using namespace std;

namespace mydata {
    typedef struct Product {
        string name;//产品名称
        float price = 0.0;//价格
        uint64_t amount = 0;//库存
        string notes;//备注
        string categoryID;//分类
    } Product;

    typedef struct StuInfo {
        string id;//学号
        string name;//姓名
        uint64_t age = 0;//年龄
        float height = 0.0;//身高
        float weight = 0.0;//体重
        string birthday;//生日
        string id_card_number;//身份证号码
        string telephone_number;//电话号码
        string email;//电子邮件
    } StuInfo;

    typedef struct StuScore {
        string id;//学号
        string name;//姓名
        string subject;//科目
        float score;//得分
        string record_date;//考试时间
    } StuScore;

}


#endif //MYDATA_HPP
