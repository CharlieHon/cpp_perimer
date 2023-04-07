#include <iostream>

int main()
{
    //分多行书写的字符串字面值
    std::cout << "a really, really long string literal "
                "that spans two lines" << std::endl;    // a really, really long string literal that spans two lines

    // 指定字面值的类型
    L'a';   //宽字符型字面值，类型是wchar_t
    u8"hi!";    // utf-8字符串字面值(utf-8用8位编码一个Unicode字符)，类型是 char
    42ULL;  // 无符号整型字面值，类型是 unsigned long long 
    1E-3F;  // 单精度浮点型字面值，类型是 float
    3.14159L;   //扩展精度浮点型字面值，类型是 long double

    // 布尔字面值和指针字面值
    bool test = false;
    nullptr;    //指针字面值
    return 0;
}