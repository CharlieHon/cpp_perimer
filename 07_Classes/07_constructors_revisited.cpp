#include <iostream>
#include <string>

/**
 * @brief 构造函数再探
 * - 如果没有在构造函数的初始值列表中显式地初始化成员，则该成员将在构造函数体之前执行默认初始化
 * - 随着构造函数一开始执行，初始化就完成了。我们初始化 const 或者引用类型的数据成员的唯一机会就是通过构造函数初始值
 */

class ConstRef{
public:
    ConstRef(int ii);
private:
    int i;
    const int ci;
    int &ri;
};

// 正确：显式地初始化引用和const成员
ConstRef::ConstRef(int ii) : i(ii), ci(ii), ri(i)   {}

/*
// 错误：ci和ri必须被初始化
ConstRef::ConstRef(int ii){
    // 赋值
    i = ii;     // 正确
    // ci = ii;    // 错误：不能给const赋值
    // ri = i;     // 错误：ri没被初始化
}
*/

// 成员初始化的顺序
// 成员的初始化顺序与它们在类定义中的出现顺序一致：第一个成员先被初始化，然后第二个，以此类推。
// 构造函数初始值列表的前后位置关系不会影响实际的初始值顺序。

class X{
    int i;
    int j;
public:
    // 错误：i在j之前被初始化，此时i(j)中j未定义
    X(int val) : j(val), i(j)   {}
};

// 默认参数和构造函数
// 如果一个构造函数为所有参数都提供了默认值，则它实际也定义了默认构造函数
class Sales_data{
    friend std::istream& read(std::istream&, Sales_data&);
public:
    // 定义默认构造函数，令其与只接受一个string实参的构造函数功能相同
    Sales_data(std::string s = "") : bookNo(s) {}
    // Sales_data(std::istream &is = std::cin) {   read(is, *this);  }  // 练习7.38
    // 其他构造函数与之前一致
    Sales_data(std::string s, unsigned cnt, double rev) :
                bookNo(s), unit_sold(cnt), revenue(rev*cnt) {}
    Sales_data(std::istream &is)    { read(is, *this); }

private:
    std::string bookNo;
    unsigned unit_sold = 0;
    double revenue = 0.0;
};

std::istream& read(std::istream&, Sales_data&);

int main()
{

    return 0;
}

std::istream& read(std::istream &is, Sales_data &s){
    double price = 0.0;
    is >> s.bookNo >> s.unit_sold >> price;
    s.revenue = price * s.unit_sold;
    return is;
}
