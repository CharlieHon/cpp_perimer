#include <iostream>
#include <string>
using std::cin; using std::cout; using std::endl;
using std::string;

int main()
{
    string s1;      // 默认初始化，s1是一个空字符串
    string s2 = s1; // 拷贝初始化，s2是s1的副本
    string s3 = "hiya"; // s3是该字符串字面值的副本
    string s4(10, 'h'); //直接初始化，s4的内容是hhhhhhhhhh

    // 直接初始化和拷贝初始化
    // 如果使用等号(=)初始化一个变量，实际上执行的是拷贝初始化
    // 编译器把等号右侧的初始值拷贝到新建的对象中去
    string s5 = "hiya";
    //如果不适用等号，则执行的是直接初始化
    string s6("hiya");
    string s7(10, 'c');

    return 0;
}