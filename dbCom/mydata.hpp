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

    typedef struct Customers {
        string id;//用户id
        string name;//用户名
    } Customers;

    typedef struct Orders {
        string id;//订单id
        string customerID;//下单用户ID
    } Orders;

    typedef struct Users {
        string id;//用户id
        string name;//用户名
    } Users;

    typedef struct Rides {
        string id;//旅行id
        string UserID;//用户ID
        float distance;//旅行距离
    } Rides;

    typedef struct CH13_products {
        string id;//产品id
        string store;//产品售卖商店
        float price;//产品价格
    } CH13_products;

    typedef struct CH14_department {
        string id;//部门id
        string name;//部门名称
    } CH14_department;

    typedef struct CH14_employee {
        string id;//雇员id
        string name;//雇员姓名
        float salary;//薪资
        string departmentID;//部门id
    } CH14_employee;

    typedef struct CH15_grade{
        string id;//
        string job;
        float score;
    }CH15_grade;

}


#endif //MYDATA_HPP
