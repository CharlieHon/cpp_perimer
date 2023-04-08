#include <iostream>
#include <string>

// 在函数体内部，如果试图初始化一个由extern关键字标记的变量，将引发错
extern double pi = 3.1415926;   //定义

int main()
{
    int sum = 0, value,
        unit_sold = 0;
    std::string book("0-201-78345-X");  //book通过一个string字面值初始化

    double salary = 9999.99, wage = salary;

    /*
    //列表初始化
    int a = 0;
    int a = {0};	//列表初始化
    int a{0};	//列表初始化
    int a(0);
    */

    //使用列表初始化且初始值存在丢失信息的风险时，编译器将报错
    long double ld = 3.1415926536;
    int a{ld}, b = {ld};    //错误：转换未执行，因为存在丢失信息的危险
    int c(ld), d = ld;  //正确：转换执行，且确实丢失了部分值

    //声明
    extern int i;   //声明i而非定义i
    int j;          //声明并定义j

    return 0;
}