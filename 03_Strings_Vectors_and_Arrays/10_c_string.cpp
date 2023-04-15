#include <iostream>
#include <string>
#include <cstring>
#include <vector>
using namespace std;

int main()
{
    // 传入C风格字符串的函数的指针必须是指向以空字符作为结束的数组
    char ca[] = {'C', '+', '+'};
    cout << strlen(ca) << endl; // 严重错误：ca没有以空字符结束，但是编译器不报错
    
    // 比较字符串
    string s1 = "A string example";
    string s2 = "A different string";
    if(s1 < s2)  cout << "s1 < s2" << endl;
    else        cout << "s1 > s2" << endl;  // s1 > s2

    // 如果把上述比较运算符用在两个C风格字符串上，实际比较的将是指针而非字符本身
    const char ca1[] = "A string example";
    const char ca2[] = "A different string";
    // 当使用数组的时候其实真正用的是指向数组首元素的指针
    // if(ca1 < ca2)   // 未定义的：试图比较两个无关地址

    cout << "strlen(ca1): " << strlen(ca1) << endl; // 16
    cout << "strlen(ca2): " << strlen(ca2) << endl; // 18

    // 使用 strcmp函数 比较两个C风格字符串，此时比较的就不再是指针
    if(strcmp(ca1, ca2) < 0)    cout << "ca1 < ca2" << endl;
    else    cout << "ca1 > ca2" << endl;

    // 拼接字符串
    string s3 = s1 + " " + s2;
    cout << s3 << endl;     // A string example A different string

    // 表达式 ca1+ca2试图将两个指针相加，显然这样的操作没什么意义，也肯定是非法的
    char ca3[35];   // 16 + 18 + 1(空字符)
    strcpy(ca3, ca1);   // 把ca1拷贝给ca3
    strcat(ca3, " ");   // 在ca3末尾加上一个空格
    strcat(ca3, ca2);   // 把ca2连接到ca3后面
    // 输出拼接后的结果
    for(auto c : ca3)
        cout << c;      // A string example A different string
    cout << endl;

    // 允许使用字符串字面值来初始化string对象
    string s("Hello World");
    // 任何出现字符串字面值的地方都可以用以空字符结束的字符数组来替代
    const char ca4[] = "happy";
    string s4 = ca4;    // happy 允许使用以空字符结束的字符数组来初始化string对象或为string对象赋值
    cout << s4 << endl;
    string s5 = s4 + ca4;
    cout << s5 << endl; // happyhappy 在string对象的加法运算中允许使用以空字符结束的字符数组作为其中一个运算对象(不能两个都是)

    // 反之不成立，不能用string对象直接初始化指向字符的指针
    // char *str = s;  // 错误：不能用string对象初始化char *
    const char *str = s.c_str();    // string专门提供了一个名为c_str的成员函数，实现该功能
    
    // 使用数组初始化vector对象
    int int_arr[] = {1,9,4,9,2,0,2,3};
    // 前闭后开区间
    vector<int> ivec(begin(int_arr), end(int_arr)); // ivec有8个元素，分别是int_arr中对应元素的副本
    vector<int> ivec2(int_arr+1, int_arr+4);    // ivec2中的元素分别是int_arr[1]到int_arr[3]，即9，4，9



    return 0;
}