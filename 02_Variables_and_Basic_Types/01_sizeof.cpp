#include <iostream>

int main()
{
    int a;  //内置类型

    //
    std::cout << "bool:\t\t" << sizeof(bool) << std::endl;  //1
    std::cout << "char:\t\t" << sizeof(char) << std::endl;  //1
    std::cout << "wchar_t:\t" << sizeof(wchar_t) << std::endl;    //2
    std::cout << "short:\t\t" << sizeof(short) << std::endl;  //2
    std::cout << "int:\t\t" << sizeof(int) << std::endl;    //4
    std::cout << "long:\t\t" << sizeof(long) << std::endl;  //4
    std::cout << "long long:\t" << sizeof(long long) << std::endl;    //8
    std::cout << "float:\t\t" << sizeof(float) << std::endl;    //4
    std::cout << "double:\t\t" << sizeof(double) << std::endl;  //8
    std::cout << "long double:\t" << sizeof(long double) << std::endl;  //16
    unsigned u1 = 42, u2 = 10;
    std::cout << u1 - u2 << std::endl;  //32
    std::cout << u2 - u1 << std::endl;  //4294967264
    int b = -4;
    unsigned c = 1;
    std::cout << b * c << std::endl;    // 4294967292

    return 0;
}