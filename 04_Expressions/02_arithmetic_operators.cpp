#include <iostream>
#include <vector>
#include <string>

using std::cin; using std::cout; using std::endl;
using std::vector;
using std::string;

int main()
{
    // 算术运算符的运算对象和求值结果都是右值
    // 在表达式求值之前，小整数的运算对象被提升成较大的整数类型，所有运算对象最终会转换成同一类型。
    bool b = true;
    // 布尔变量b的值为真，参与运算时将被提升成整数值1，对它求负后的结果是-1
    // 将-1再转换回布尔值并将其作为b2的初始值
    bool b2 = -b;   // b2是true

    // 溢出
    short short_value = 32767;  // 如果short类型占16位，则能表示的最大值是32767
    short_value += 1;   // 该计算导致溢出
    // 该值发生了“环绕”，符号位本来是0，由于溢出被改成了1，于是结果变成一个负值
    cout << "short_value: " << short_value << endl; // -32768

    // C++11新标准规定商一律向0取整(即直接切除小数部分)
    int ival1 = 21/6;
    int ival2 = -21/6;
    cout << "21/6 = " << ival1 << " ival2 = " << ival2 << endl;

    // 在除法运算中，如果两个对象的符号相同则商为正，否则商为负
    // 除了-m导致溢出的特殊情况外，其他时候(-m)/n和m/(-n)都等于-(m/n)

    // 运算符%俗称“取余”，负责计算两个整数相除所得的余数，参与取余运算的运算对象必须是整数类型
    // 如果 m%n 不等于0，则它的符号和 m 相同
    // m%(-n) 等于 m%n; (-m)%n等于-(m%n)
    cout << 21%6 << endl;   // 3
    cout << -21%-8 << endl; // -5
    cout << 21%-5 << endl;  // 1
    cout << 21/6 << endl;   // 3
    cout << -21/-8 << endl; // 2
    cout << 21/-5 << endl;  // -4

    return 0;
}