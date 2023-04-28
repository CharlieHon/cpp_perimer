#include <iostream>

using std::cin; using std::cout; using std::endl;

int main()
{
    // 练习4.13
    int i;
    double d;
    d = i = 3.5;
    cout << "i: " << i << " d: " << d << endl; // i = 3, d = 3.0
    i = d = 3.5;
    cout << "i: " << i << " d: " << d << endl; // i = 3, d = 3.5

    // 练习4.14：执行下述if语句后将发生什么情况
    // if(42 = i)   // 报错：赋值运算符左侧必须是一个可修改的左值。而字面值是右值
    if(i = 42);  // 赋值表达式 i = 42 的返回值是左侧运算对象i，结果为42，永为真

    // 练习4.15：下面的赋值是非法的，为什么？应该如何修改？
    double dval; int ival; int *pi;
    // dval = ival = pi = 0;
    // 赋值语句遵循右结合律，上式等价于 dval = (ival = (pi = 0))
    // 不能将 int* 赋值给 int
    dval = ival = 0;
    pi = 0;

    // 练习4.16
    // 1.
    // if(p = getPtr() != 0)
    /*
    * 赋值运算符优先级相对较低，上面条件表达式等价于 p = (getPtr() != 0)
    * 首先判断 getPtr() 返回的指针是否非空，然后将结果赋值给 p，
    */
    // if((p=getPtr()) != 0);

    // 2.
    // if(i = 1024)
    /*
    * 将1024赋值给i，赋值表达式 i = 1024 的结果为左侧运算对象，即i。条件永远为真
    */
    if(i == 1024);

    return 0;
}