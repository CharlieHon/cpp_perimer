#include <iostream>

int get_size(){
    return 1;
}

int main()
{
    //const对象必须初始化，初始值可以是任意复杂的表达式
    const int a = get_size();
    // const int b;    //错误：b是一个未经初始化的常量

    //初始化和const
    int c = 42;
    const int d = c;    //正确：c的值被拷贝给了d
    int e = d;          //正确：d的值被拷贝给了e

    int i = -1;
    const int i2 = i;
    // int *const p1 = &i2;    //错误：必须用指向常量的指针，指向i2
    const int *const p2 = &i2;

    return 0;
}