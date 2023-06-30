#ifndef SALES_DATA_H
#define SALES_DATA_H

#include <iostream>
#include <string>

class Sales_data{
// 为Sales_data的非成员函数所做的友元声明
    friend Sales_data add(const Sales_data&, const Sales_data&);
    friend std::istream& read(std::istream&, Sales_data&);
    friend std::ostream& print(std::ostream&, const Sales_data&);

public:
    // 构造函数和部分成员函数在 public 说明符之后
    Sales_data() = default; // 合成默认构造函数
    Sales_data(const std::string &s, unsigned n, double p) :
                bookNo(s), units_sold(n), revenue(n*p)  {}  // 构造函数初始值列表
    
    // 关键字explicit只对一个实参地构造函数有效。需要多个实参的构造函数不能用于隐式转换，所以无须制定。
    // 只能在类内声明构造函数时使用explicit关键字，在类外部定义时不应重复
    explicit Sales_data(const std::string &s) : bookNo(s)    {} // 将构造函数声明为explicit，阻止隐式转换
    explicit Sales_data(std::istream &is)    {read(std::cin, *this);}
    
    std::string isbn() const {return bookNo;}
    Sales_data& combine(const Sales_data &);

private:
    // 数据成员和作为实现部分的成员函数跟在 private 说明符后面
    double avg_price() const;
            // {return units_sold ? revenue/units_sold : 0;}
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

// 友元声明仅指定了访问的权限，而非一个通常意义上的函数声明。
// 如果希望类用户能够调用某个友元函数，那么就必须在友元声明之外再专门对函数进行一次声明
Sales_data add(const Sales_data&, const Sales_data&);
std::istream& read(std::istream&, Sales_data&);
std::ostream& print(std::ostream&, const Sales_data&);

inline  // 练习7.26：将Sales_data::avg_price定义成内联函数
double Sales_data::avg_price() const {
    return units_sold ? revenue/units_sold : 0;
}

#endif