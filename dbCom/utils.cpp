//
// Created by lining on 2/12/25.
//

#include "utils.h"



/**
 * 适合不知道表内字段名称，或者想要整体的看下结果的时候
 * @param rs
 */
void showResult(const RecordSet &rs) {
    //以poco库格式化好的内容来输出
    string name;
    string value;
    for (auto iter: rs) {
        //表头 name 内容 value
        if (name.empty()) {
            name = iter.namesToString();
            cout << name << endl;
        }
        value = iter.valuesToString();
        cout << value << endl;
    }
}