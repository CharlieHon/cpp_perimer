#include <iostream>

int main()
{
    // 把一个非布尔类型的算术值赋给布尔类型时，初始值为0则结果为false，否则结果为true
    bool b = 42;        // b为真(true)
    int i = b;          // i = 1
    // 把浮点数赋给整数类型时，进行了近似处理。结果值将仅保留浮点数中小数点之前的部分
    i = 3.14;           // i = 3
    // 把整数赋给浮点数时，小数部分记为0.
    double pi = i;      // pi = 3.0
    // 当赋给无符号类型一个超出它表示范围的值时，结果是
    // 初始值对无符号类型表示数值总数取模后的余数。256 - 1 = 255 
    unsigned char c = -1;   // c = 255
    // 当赋给带符号类型一个超过它表示范围的值时，结果是未定义的(undefined)
    signed char c2 = 256;   //假设char占8比特，c2值是未定义的

    // 含有无符号类型的表达式
    unsigned u = 10;
    i = -42;
    std::cout << i + i << std::endl; // -84
    std::cout << u + i << std::endl; // 2^32-42+10 = 42949672564

    unsigned u1 = 42, u2 = 10;
    std::cout << u1 - u2 << std::endl;  // 32
    std::cout << u2 - u1 << std::endl;  // -32 -> 2^32-32 = 42949672564

    //无符号数不会小于这一事实同样关系到循环的写法。
    for(int j=10; j>=0; --j)
        std::cout << i << std::endl;

    /* 错误：变量k永远也不会小于0，循环条件一直成立
     * for(unsigned k=10; k>=0; --k)
     *    std::cout << j << std::endl;
     */

    return 0;
}