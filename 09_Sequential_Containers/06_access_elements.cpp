#include <iostream>
#include <vector>
#include <string>
#include <deque>
#include <list>
#include <array>

using namespace std;

/**
 * @brief 9.3.2 访问元素
 * at和下标运算符只适用于string、vector、deque和array
 * back不适用于forward_list。
 * c.back()：返回c中尾元素的引用。若c为空，函数行为未定义
 * c.front()：返回c中首元素的引用。若c为空，函数行为未定义
 * c[n]：返回c中下标为n的元素的引用，n是一个无符号整数。若n>=c.size()，则函数行为未定义
 * c.at(n)：返回下标为n的元素的引用。如果下标越界，则抛出一个out_of_range异常
 */

int main()
{
    //首元素和尾元素
    vector<int> v1 = {0,1,2,3,4,5,6};
    if(!v1.empty()){    // 确保容器非空
        // val1和val2是v1中第一个元素值的拷贝
        auto val1 = *v1.begin(), val2 = v1.front();
        // val3和val4是v1中最后一个元素值的拷贝
        auto last = v1.end();
        auto val3 = *(--last);  // 不能递减forward_list迭代器
        auto val4 = v1.back();  // forward_list不支持
    }

    // 访问成员函数返回的引用
    if(!v1.empty()){
        v1.front() = 42;    // 将42赋予v1中的一个元素
        auto &val5 = v1.back(); // 获得指向最后一个元素的引用
        val5 = 1024;    // 改变v1中元素
        auto val6 = v1.back();  // val6不是一个引用，他是v1.back()的一个拷贝
        val6 = 9;
    }

    // 下标操作和安全的随机访问
    vector<string> svec;    // 空vector
    // cout << svec[0];    // 运行时错误：svec中没有元素
    cout << svec.at(0); // 抛出一个out_of_range异常

    // 

    return 0;
}