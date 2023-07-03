#include <iostream>
#include <string>

/**
 * @brief 聚合类
 * 聚合类使得用户可以直接访问其成员，并且具有特殊的初始化语法形式。当一个类满足以下条件时，是聚合类：
 * - 所有成员都是public
 * - 没有定义任何构造函数
 * - 没有类内初始值
 * - 没有基类，也没有virtual函数
 */

// 下面的类是一个聚合类
struct Data{
    int ival;
    std::string s;
};

int main()
{
    // 可以提供一个花括号括起来的成员初始值列表，并用它初始化聚合类的数据成员
    // Data d1;
    // d1.ival = 0; d1.s = std::string("Anna");
    Data d2 = {1, "Leslie"};    // 初始值的顺序必须与声明的顺序一致

    // 初始值列表中的元素个数少于成员数量，则靠后的成员被值初始化；但是不能超过类的成员数量
    Data d3 = {2};  // d3.s = "";

    return 0;
}