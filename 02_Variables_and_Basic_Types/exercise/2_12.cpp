#include <iostream>

int main()
{
    //练习2.12：请说明下面的名字中哪些是非法的？
    // int double = 3.14;  //错误：变量名不能与关键字相同
    int _;              //可以
    // int catch-22;       //错误：不能有字母、下划线、数字之外的字符
    // int 1_or_2;         //错误：不能以数字开头
    double Double = 3.14;   //对

    return 0;
}