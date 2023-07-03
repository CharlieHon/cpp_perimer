#include <iostream>
#include <string>

/**
 * @brief 类的静态成员
 * 有时候类需要它的一些成员与类本身直接相关，而不是与类的各个对象保持关联。
 * - 静态成员可以是public的或private的；静态数据成员的类型可以是常量、引用、指针、类类型等
 * - static关键字只能出现在类内部的声明语句中
 * - 静态成员函数不与任何对象绑定在一起，它们不包含this指针。
 * - 因此，静态成员函数不能声明成const的，而且不能在static函数体内使用this指针。
 * 
 * 静态成员能用于某些场景，而普通成员不能
 * - 静态数据成员可以是不完全类型
 * - 可以使用静态成员作为默认实参
 */

class Account{
public:
    void calculate() { amount += amount * interestRate; }   // 成员函数不用通过作用域运算符就能直接使用静态成员
    static double rate() { return interestRate; }
    static void rate(double);
private:
    std::string owner;
    double amount;
    static double interestRate;
    static double initRate();

    // 静态成员的类内初始化
    static constexpr int period = 30;   // period是常量表达式
    double daily_tbl[period];
};

// 一个不带初始值的静态成员定义
constexpr int period;   // 如果在类内部提供了一个初始值，则成员的定义不能再制定一个初始值

// 在类的外部定义静态成员，不能重复static关键字
void Account::rate(double newRate){
    interestRate = newRate;
}

double Account::initRate()  { return 0.1; }

// 必须在类的外部定义和初始化每个静态成员
double Account::interestRate = initRate();  // 定义并初始化一个静态成员。从类名开始，这条语句的剩余部分就都位于类的作用域之内了


// 静态成员可以是不完全类型
class Bar{
public:
    // ...
private:
    static Bar mem1;    // 正确：静态成员可以是不完全类型
    Bar *mem2;      // 正确：指针成员可以是不完全类型
    // Bar mem3;   // 错误：数据成员必须是完全类型
};

// 可以使用静态成员作为默认实参
class Screen{
public:
    // bkground表示一个再类中稍后定义的静态成员
    Screen& clear(char = bkground); 
private:
    static const char bkground;
    // 非静态成员不能作为默认实参，因为它本身属于对象的一部分，无法真正提供一个对象以便从中获取成员的值，最终将引发错误
};

int main()
{
    // 使用类的静态成员
    double r;
    r = Account::rate();    // 使用作用域运算符访问静态成员
    // 可以使用类的对象、引用或者指针来访问静态成员
    Account ac1;
    Account *ac2 = &ac1;
    // 调用静态成员函数rate的等价形式
    r = ac1.rate();
    r = ac2->rate();

    return 0;
}