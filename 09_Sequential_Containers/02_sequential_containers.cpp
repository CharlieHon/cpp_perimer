#include <vector>
#include <list>
#include <deque>
#include <array>
#include <forward_list>
#include <iostream>
#include <string>

using namespace std;

/**
 * @brief 容器定义和初始化
 * C c; 默认构造函数
 * C c1(c2);    c1初始化为c2的拷贝。c1和c2必须是相同类型(相同容器类型，相同元素类型)
 * C c{a,b,c...};   c初始化为初始化列表中元素的拷贝。列表中的元素类型必须与C的元素类型相容。
 * C c={a,b,c...};  对于array类型，列表中元素数目必须等于或小于array的大小。
 * C c(b,e);    c初始化为迭代器b和e指定范围中元素的拷贝。
 * 只有顺序容器(不包括array)的构造函数才能接收大小参数
 * C seq(n);    seq包含n个元素，这些元素进行了值初始化；此构造函数是explicit的(string不适用)
 * C seq(n,t);  seq包含n个初始化为值t的元素
 */

int main()
{
    // 列表初始化
    list<string> authors = {"Milton", "Shakespeare", "Austen"}; // 显式指定容器中每个元素的值，隐含指定了容器的大小
    vector<const char*> articles = {"a", "an", "the"};
    
    // 将一个容器初始化为另一个容器的拷贝
    list<string> list2(authors);    // 直接拷贝整个容器，两个容器的类型及其元素类型必须匹配
    // deque<string> authList(authors);    // 错误：容器类型不匹配
    // vector<string> words(articles);     // 错误：容器类型必须匹配
    forward_list<string> words(articles.begin(), articles.end());

    // 与顺序容器大小相关的构造函数：内置类型或具有默认构造函数的类类型不需要提供初始值
    vector<int> ivec(10, -1);   // 10个int元素，每个初始化为-1
    list<string> svec(10, "hi");    // 10个strings；每个都初始化为"hi"
    forward_list<int> ivec2(10);    // 10个元素，每个初始化为0
    deque<string> svec2(10);    // 10个元素，每个都是空string

    // 标准库array具有固定大小
    // array<int, 42> // 类型为：保存42个int的数组
    // array<string, 42> // 类型为：保存10个string的数组
    array<int, 10>::size_type i;    // 数组类型包括元素类型和大小

    array<int, 10> ia1; // 10个默认初始化的int
    array<int, 10> ia2 = {0,1,2,3,4,5,6,7,8,9}; // 列表初始化
    array<int, 10> ia3 = {42};  // ia3[0]为42，剩余元素为0

    // 可以对array进行拷贝或赋值操作
    int digs[10] = {0,1,2,3,4,5,6,7,8,9};
    // int cpy[10] = digs; // 错误：内置数组不支持拷贝或赋值
    array<int, 10> digits = {0,1,2,3,4,5,6,7,8,9};
    array<int, 10> copy = digits;   // 正确：只要数组类型匹配即可

    return 0;
}