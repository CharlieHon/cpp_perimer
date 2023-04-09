#include <iostream>

int main()
{
    //练习2.26
    // const int buf;  //错误：未初始化
    int cnt = 0;
    const int sz = cnt;
    ++cnt;
    // ++sz;               //错误：值不能改变

    return 0;
}