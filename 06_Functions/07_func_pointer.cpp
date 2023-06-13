#include <iostream>

using namespace std;

// Func和Func2是函数类型
typedef bool Func(const string &, const string &);
typedef bool (*Func2)(const string &, const string &);
// decltype返回函数类型，不将函数类型自动转换成指针类型
// decltype(lengthCompare) Func;    // Func是函数类型
// decltype(lengthCompare) *Func2;  // Func2是函数指针


/**
 * 函数指针指向的是函数而非对象。函数的类型由它的返回类型和形参类型共同决定，与函数名无关
 * 
 */

bool lengthCompare(const string &s1, const string &s2){
    return s1.size()<=s2.size();
}
// 声明一个可以指向该函数指针，只需要用指针替换函数名即可
bool (*pf)(const string &, const string &);
// *pf两端的括号必不可少，不屑则pf是一个返回值为bool指针的函数
// bool *pf(const string &, const string &);    // 非上函数的重载，因为仅返回类型不同

// 重载函数的指针
void ff(int *){}
void ff(unsigned int){}

// 编译器通过指针类型决定选用哪个函数，指针类型必须与重载函数中的某一个精确匹配
void (*pf1)(int *) = ff;    // pf1指向ff(int*)

// 函数指针形参，函数类型的形参可以自动转换为函数指针
void useBigger(const string &s1, const string &s2,
                bool pf2(const string &, const string &));   // 第三个参数是函数类型，可以自动转换成指向函数的指针
// void useBigger(const string &s1, const string &s2,
//                 bool (*pf2)(const string &, const string &)); // 显示地将形参定义成指向函数的指针

// 返回指向函数的指针。虽然不能返回一个函数，但是能返回指向函数类型的指针
using F = int(int*, int);       // F是函数类型，不是指针
using PF = int(*)(int*, int);   // PF是指针类型

PF f1(int); // 正确：PF是指向函数的指针，f1返回指向函数的指针
// F f2(int);  // 错误：F是函数类型，f1不能返回一个函数
F *f3(int); // 正确：显示地指定返回类型是指向函数地指针


int main()
{
    pf = lengthCompare;
    // pf = &lengthCompare; // 等价的赋值语句：取地址符是可选的

    // 直接使用指向函数的指针调用该函数，无须提前解引用指针
    bool b1 = pf("hello", "goodbye");
    bool b2 = (*pf)("hello", "world");  // 等价调用
    bool b3 = lengthCompare("hello", "world");  // 另一个等价的调用

    // 在指向不同函数类型的指针间不存在转换规则，可以为函数指针赋一个nullptr或者值为0的整型常量表达式
    pf = 0;
    // pf = nullptr;

    return 0;
}