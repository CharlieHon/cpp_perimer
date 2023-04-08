#include <iostream>

int main()
{
    //练习2.18
    int a = 10, *pi = &a, b = 20;
    pi = &b;    //更改指针的值
    *pi = 30;   //更改指针所指对象的值
    std::cout << a << " " << b << " " << *pi << std::endl;  // 10 30 30

    //练习2.23:给定指针p,能知道它是否指向了一个合法的对象吗?
    /*
     * 能,可以使用try catch的异常处理来分辨指针p是否指向一个合法对象,
     * 但通过普通控制结果无法实现
    */

   //练习2.24
    int i = 24;
    void *p = &i;    //void*可以存储任何类型对象的地址
    //    long *lp = &i;   //错误:类型不匹配

    //练习2.25
    int *ip, ii, &r = ii;   // ip指针;ii整型;r引用
    int iii, *iip = 0;      //iii整型;iip空指针

    return 0;
}