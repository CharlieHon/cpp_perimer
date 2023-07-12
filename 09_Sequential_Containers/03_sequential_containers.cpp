#include <vector>
#include <list>
#include <deque>
#include <array>
#include <forward_list>
#include <iostream>
#include <string>

using namespace std;

/**
 * @brief 赋值和swap
 * c1=c2;   将c1的元素替换为c2中元素的拷贝。c1和c2必须具有相同的类型
 * c={a,b,c...}; 将c1中元素替换为初始化列表中元素的拷贝(array不适用)
 * swap(c1,c2); 交换c1和c2中的元素。c1和c2必须具有相同的类型。swap通常比从c2向c1拷贝元素快得多
 * c1.swap(c2);
 * assign操作不适用于关联容器和array
 * seq.assign(b,e); 将seq中元素替换为迭代器b和e所表示的范围中的元素。迭代器b和e不能指向seq中元素
 * seq.assign(i1);  将seq中元素替换为初始化列表i1中元素
 * seq.assign(n,t); 将seq中元素替换为n个值为t的元素
 */

int main()
{
    // c1 = c2;    // 将c1的内容替换为c2中元素的拷贝
    // c1 = {a,b,c};   // 赋值后，c1大小为3

    // 由于右边运算对象的大小可能于左边的不同，因此array类型不支持assign，也不允许用花括号包围的列表进行赋值
    array<int, 10> a1 = {0,1,2,3,4,5,6,7,8,9};
    array<int, 10> a2 = {0};    // 所有元素均为0
    a1 = a2;    // 替换a1中的元素
    // a2 = {0};   // 错误：不能将一个花括号列表赋予数组

    // 使用assign(仅顺序容器)：assign允许从一个不同但相容的类型赋值，或者从容器的一个子序列赋值
    list<string> names;
    vector<const char*> oldstyle;
    // names = oldstyle;    // 错误：容器类型不匹配
    names.assign(oldstyle.begin(), oldstyle.end()); // 正确：可以将const char *转换为string

    // seq.assign(n, t)
    list<string> slist1(1); // 1个元素，为空string
    slist1.assign(10, "Hiya");  // 10个元素，每个都是"Hiya"

    // swap：交换两个相同类型容器的内容
    vector<string> svec1(10);
    vector<string> svec2(24);
    swap(svec1, svec2); // 两个容器中的元素将会交换
    


    return 0;
}