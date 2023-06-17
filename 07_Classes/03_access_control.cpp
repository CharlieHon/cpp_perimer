#include <iostream>
#include <string>
/**
 * @brief 访问说明符(access specifiers)加强类的封装性
 * - 每个访问说明符指定了接下来的成员的访问级别，其有效范围直到出现下一个
 *  访问说明符或者达到类的结尾处为止。
 * - struct和class的唯一区别是，默认访问权限不同
 *  struct默认是public；而class默认是private(即在第一个访问说明符之前定义的成员)
 * - 封装将类内部成员设置为外部不可见，而提供部分接口给外面
 */

class Sales_data{
public:
    // 构造函数和部分成员函数在 public 说明符之后
    Sales_data() = default;
    Sales_data(const std::string &s, unsigned n, double p) :
                bookNo(s), units_sold(n), revenue(n*p)  {}
    Sales_data(const std::string &s) : bookNo(s)    {}
    Sales_data(std::istream &);
    std::string isbn()  {return bookNo;}
    Sales_data& combine(const Sales_data &);

private:
    // 数据成员和作为实现部分的成员函数跟在 private 说明符后面
    double avg_price()  {return units_sold ? revenue/units_sold : 0;}
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

std::istream& read(std::istream &is, Sales_data &item);
std::ostream& print(std::ostream &os, const Sales_data &item);
Sales_data add(const Sales_data &lhs, const Sales_data &rhs);

int main()
{


    return ;
}

// member function
Sales_data::Sales_data(std::istream &is){
    read(is, *this);
}

Sales_data& Sales_data::combine(const Sales_data &rhs){
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

// nonmember function
// std::istream& read(std::istream &is, Sales_data &rhs){
//     double price = 0.0;
//     is >> rhs.bookNo >> rhs.units_sold >> price;
//     rhs.revenue = rhs.units_sold * price;
//     return is;
// }

