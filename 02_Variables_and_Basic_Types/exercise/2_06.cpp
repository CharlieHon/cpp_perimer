#include <iostream>

int main()
{
    // 练习2.6
    int month = 9, day = 7;
    // int m = 09, d = 07; //八进制，且09无效的八进制

    // 练习2.8
    std::cout << "2" << "\115\n" << std::endl;       // 先输出2M，然后转到新一行
    std::cout << "2" << "\t\115\n" << std::endl;

    return 0;
}