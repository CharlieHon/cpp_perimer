#include <iostream>

using namespace std;

/*
 * 调用函数一般比等价表达式的值要慢一些
 * 在大多数机器上，一次函数调用包含一系列工作：调用前要先保存寄存器，并在返回时恢复
 * 可能需要拷贝实参；程序转向一个新的位置继续执行。
 * 
 * constexpr函数：返回类型及所有形参类型都得是字面值类型，而且函数体内必须有且只有一条return语句
*/

// 将函数制定为内联函数(inline)，通常是将它在每个调用点上“内联地”展开
inline const string &shorterString(const string &s1, const string &s2){
    return (s1.size() <= s2.size()) ? s1 : s2;
}

// constexpr函数    不一定返回常量表达式
constexpr int new_sz()  {return 42;}
constexpr int foo = new_sz();   // 常量表达式
constexpr size_t scale(size_t cnt)    {return new_sz() * cnt;}
// 当scale的实参是常量表达式时，它的返回值也是常量表达式；反之不然
int arr[scale(2)];      // 正确：scale(2)是常量是表达式
int i = 2;
// int a2[scale(i)];    // 错误：scale(i)不是常量表达式

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    cout << shorterString(s1, s2) << endl;  // 在编译过程中展开成类似于下面的形式
    // cout << (s1.size()<=s2.size()?s1:s2) << endl;

    return 0;
}