#include <iostream>

int main()
{
    //指向指针的引用
    int i = 42;
    int *p;         //p是一个int型指针
    int *&r = p;    //r是指针p的引用
    r = &i;         //使p指向i
    *r = 0;         //使i值为0

    return 0;
}