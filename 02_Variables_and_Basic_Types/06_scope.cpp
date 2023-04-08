#include <iostream>
//该程序仅用于说明：函数内部不宜定义与全局变量同名的新变量。
int reused = 42;    //reused拥有全局作用域
int main()
{
    int unique = 0; //块作用域
    std::cout << reused << " " << unique << std::endl;      // 42 0
    int reused = 0; //新建局部变量，覆盖了全局变量 reused
    std::cout << reused << " " << unique << std::endl;      // 0 0
    //显式地访问全局变量reused
    std::cout << ::reused << " " << unique << std::endl;    // 42 0

    return 0;
}