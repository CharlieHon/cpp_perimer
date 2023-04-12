#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    // 定义和初始化 vector 对象
    vector<string> svec;    // 默认初始化vector对象，创建一个指定类型的空vector
    // 允许把一个vector对象的元素拷贝给另外一个。两者类型必须相同
    vector<int> ivec;
    vector<int> ivec2(ivec);    // 把ivec的元素拷贝给ivec2
    vector<int> ivec3 = ivec;   //同上
    // vector<string> svec(ivec);  //错误：类型不匹配

    // 列表初始化 vector 对象
    vector<string> articles = {"a", "an", "the"};
    vector<string> svec1{"a", "an", "the"};
    // vector<string> v2("a", "an", "the");    // 错误，初始值列表只能放在花括号{}内

    // 创建指定数量的元素
    vector<int> ivec4(11, 21);  // 11个int类型的元素，每个都被初始化为21
    vector<string> svec2(12, "Han");    // 12个string类型的元素，每个都被初始化为 "Han"

    // 值初始化
    vector<int> ivec5(6);   // 6个元素，每个都初始化为0
    vector<string> svec3(9);    // 9个元素，每个元素都初始化为9

    // 列表初始化还是元素数量？
    vector<int> v1(10);         // v1有10个元素，每个元素都是0
    vector<int> v2{10};         // v2有1个元素，值为10
    vector<int> v3(10, 1);      // v3有10个元素，每个元素都是1
    vector<int> v4{10, 1};      // v4有2个元素，值为10和1
    vector<string> v5{"hi"};    // v5有1个元素，"hi"
    // vector<string> v6("hi");    // 错误：不能使用字符串字面值构建 vector 对象
    vector<string> v7{10};      // v7有10个元素，全部为空串
    vector<string> v8{10, "hi"};    // v8有10个元素，每个元素都是"hi

    // 向 vector 对象中添加元素
    vector<int> a;      // 空vector对象
    for(int i=0; i<100; ++i)
        a.push_back(i); // 依次把整数值放到a尾端
    // 循环结束后a有100个元素，值从0到99

    // 从标准输入中读取单词，将其作为vector对象的元素存储
    string word;
    vector<string> text;
    while (cin >> word)
    {
        text.push_back(word);
    }
    

    return 0;
}