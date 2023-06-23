/**
 * @brief - 每个类都会定义自己的作用域，在类的作用域之外，对于类类型成员使用作用域运算符访问。
 * - 一个类就是一个作用域
 * - 编译器处理完类中的全部声明后才会处理成员函数的定义
 */
#include <iostream>
#include <string>
#include "exercise/Screen.h"

typedef double Money;
std::string bal;
class Account{
public:
    Money balance() {return bal;}   // 返回名为bal的成员，而非外层作用域的string对象
private:
    // typedef double Money;   // 错误：不能重新定义Money，编译器检查不出
    Money bal;  // 外层作用域中的bal被隐藏啦
};

int main()
{
    Screen::pos ht = 24, wd = 80;
    Screen scr(ht, wd, 'x');
    Screen *p = &scr;
    char c = scr.get();
    c = p->get();
    std::cout << c << std::endl;    // x

    return 0;
}
