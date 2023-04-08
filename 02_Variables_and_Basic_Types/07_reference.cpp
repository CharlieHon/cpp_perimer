#include <iostream>

int main()
{
    int ival = 1024;
    int &refVal = ival;
    // int &refVal2;   // 报错：引用必须初始化！

    refVal = 2;
    int ii = refVal;    //与 ii = ival 执行结果一样

    //引用只能绑定在对象上，而不能与字面值或某个表达式的结果绑定在一起
    // int &refVal2 = 10;  //错误：引用类型的初始值必须是一个对象
    double dval = 3.14;
    // int &refVal3 = dval;    //错误：此处引用类型的初始值必须是int型对象

    return 0;
}