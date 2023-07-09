#include <iostream>
#include <string>
#include <vector>

// 练习7.56：什么是类的静态成员？有何优点？静态成员与普通成员有何区别？
/**
 * - 静态成员与类本身相关，而不是与类的各个对象相关的成员
 * - 静态成员能用于某些场景而普通成员不能
 */

// 练习7.57
class Account{
public:
    void calculate()  { amount += amount * interestRate; }
    static double rate() { return interestRate; }
    static void rate(double newRate) { interestRate = newRate; }
private:
    std::string owner;
    double amount;
    static double interestRate;
    static constexpr double todayRate = 7.3;
    static double initRate()    { return todayRate; };
};

double Account::interestRate = initRate();


// 练习7.58
/*
// Example.h
class Example{
public:
    static double rate = 6.5;
    static const int vecSize = 20;
    static vector<double> vec(vecSize);
};
// example.cpp
#include "example.h"
double Example::rate;
vector<double> Example::vec;
 */

class Example{
public:
    static constexpr double rate = 6.5;
    static const int vecSize = 20;
    static std::vector<double> vec;  // 类内只能初始化整型类型的静态常量，所以不能在类内初始化vec
};

constexpr double Example::rate;
std::vector<double> Example::vec(vecSize);

int main()
{

    return 0;
}
