#include <iostream>
#include <string>
#include <vector>

// 练习7.43 
// NoDefault类，有一个接受int的构造函数，但是没有默认构造函数
class NoDefault{
public:
    NoDefault(int)  {}
};
// C类，有一个NoDefault类型的成员，定义C的默认构造函数
class C{
public:
    C() : def(0) {}
private:
    NoDefault def;
};

// 7.44 下面的声明合法吗？如果不，为什么？
std::vector<NoDefault> v1(10); // v1初始化有10个元素。不合法，NoDefault没有默认构造函数
std::vector<C> v2(10);  // 合法，C有默认构造函数

// 7.46
/*
* - 默认构造函数是参数列表为空，或者为每个参数都提供了默认值的构造函数。
* - 如果类没有定义任何构造函数，则编译器将为其生成一个并把所有数据成员初始化成相应类型的默认值。
*/