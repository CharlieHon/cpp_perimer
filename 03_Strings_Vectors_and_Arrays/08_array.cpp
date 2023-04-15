#include <iostream>
using namespace std;

int main()
{
    // 定义和初始化数组
    unsigned cnt = 42;  // 不是常量表达式
    constexpr unsigned sz = 42; // 常量表达式
    int arr[10];
    int *parr[sz];  // parr是一个包含42个元素的数组，每个元素都是指向int的指针
    // string bad[cnt];    // 错误：cnt不是常量表达式
    // string strs[get_size()];    // 当get_size是constexpr时正确;否则错误
    
    // 显式初始化数组元素
    const unsigned n = 3;
    int ia1[n] = {0, 1, 2}; // 含有3个元素的数组,元素值分别是0,1,2
    int a2[] = {0, 1, 2};   // 维度是3的数组
    int a3[5] = {0, 1, 2};  // 等价于 a3[] = {0,1,2,0,0}
    string a4[3] = {"hi", "world"}; // 等价于 a4[] = {"hi", "world", ""}
    // int a5[2] = {0, 1, 2};  // 错误:初始值过多

    // 字符数组的特殊性
    char c1[] = {'C', '+', '+'};    // 列表初始化,没有空字符
    char c2[] = {'C', '+', '+', '\0'};  // 列表初始化,含有显式的空字符
    char c3[] = "C++";  // 自动添加表示字符串结束的空字符
    // const char c4[6] = "Daniel";    // 错误:没有空间可存放空字符!

    // 不允许拷贝和赋值
    int a6[] = {0, 1, 2};
    // int a7[] = a6;  // 错误:不允许使用一个数组初始化另外一个数组
    // int a8[];       // 不允许使用不完整的类型,数组的大小也是其类型的一部分
    // a7 = a6;    // 错误:不能把一个数组直接赋值给另外一个数组

    // 理解复杂的数组声明
    int *ptrs[10];              // ptrs是一个含有10个元素数组,每个元素都是int*
    // int &refs[10] = /* ? */;    // 错误:不存在引用的数组
    int (*Parray)[10] = &arr;   // Parray是一个指针,指向一个含有10个int元素的数组 arr
    int (&arrRef)[10] = arr;    // arrRef是一个引用,绑定到一个含有10个int元素的数组 arr
    int *(&arry)[10] = ptrs;    // array是一个引用,绑定到一个int *[10],即含有10个int*的数组ptrs上

    // 用数组来记录各分数段的成绩个数
    unsigned scores[11] = {};    // 11各分数段,全部初始化为0
    unsigned grade;
    while(cin >> grade){
        if(grade <=100 )
            ++scores[grade/10]; // 将当前分数段的计数加1
    }
    for(auto s : scores){
        cout << s << " ";
    }
    cout << endl;

    return 0;
}