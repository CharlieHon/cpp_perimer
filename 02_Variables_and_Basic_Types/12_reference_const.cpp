#include <iostream>

int main()
{
    //对常量的引用
    const int ci = 1024;
    const int &r = ci;
    // r = 42;    //错误：引用及其对应的对象都是常量
    //因为不允许直接为ci赋值,当然也就不能通过引用去改变ci.
    //因此,对r2的初始化时错误的.
    // int &r2 = ci;   //错误：试图让一个非常量引用指向一个常量对象

    //初始化和对const的引用
    int i = 42;
    const int &r1 = i;      //允许将一个const int& 绑定到一个普通int对象上
    const int &r2 = 42;
    const int &r3 = r1 * 2;
    // int &r4 = r1 * 2;   //错误:r4是一个普通的非常量引用

    double dval = 3.14;
    const int &ri = dval;   //正确:常量引用可以类型不匹配

    /*编译器把上述代码编程了如下形式:
    const int temp = dval;  //由双精度浮点数生成一个临时的整型变量
    const int &ri = temp;   //让ri绑定这个临时量
    */


    //对const的引用可能引用一个并非const的对象
    int j = 12;
    int &rj = i;
    const int &rj2 = i;
    const int &rj3 = rj;
    rj = 13;
    // rj2 = 20;       //错误:rj2是一个常量引用,不允许对其赋值

    return 0;
}