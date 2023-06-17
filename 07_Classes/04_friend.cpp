#include <iostream>
#include <string>
/**
 * @brief 友元(friend)
 * - 类可以允许其他类或者函数访问它的非公有成员，方法是令其他类或者函数成为它的友元
 * - 友元声明只能出现在类定义的内部，但是在类内出现的具体位置不限。
 * - 友元不是类的成员，也不受它所在区域访问控制级别的约束。
 */

class Sales_data{
// 为Sales_data的非成员函数所做的友元声明
    friend Sales_data add(const Sales_data&, const Sales_data&);
    friend std::istream& read(std::istream&, Sales_data&);
    friend std::ostream& print(std::ostream&, const Sales_data&);

public:
    // 构造函数和部分成员函数在 public 说明符之后
    Sales_data() = default; // 合成默认构造函数
    Sales_data(const std::string &s, unsigned n, double p) :
                bookNo(s), units_sold(n), revenue(n*p)  {}
    Sales_data(const std::string &s) : bookNo(s)    {}
    Sales_data(std::istream &)  {read(std::cin, *this);}

    std::string isbn() const {return bookNo;}
    Sales_data& combine(const Sales_data &);

private:
    // 数据成员和作为实现部分的成员函数跟在 private 说明符后面
    double avg_price() const
            {return units_sold ? revenue/units_sold : 0;}
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

// 友元声明仅指定了访问的权限，而非一个通常意义上的函数声明。
// 如果希望类用户能够调用某个友元函数，那么就必须在友元声明之外再专门对函数进行一次声明
Sales_data add(const Sales_data&, const Sales_data&);
std::istream& read(std::istream&, Sales_data&);
std::ostream& print(std::ostream&, const Sales_data&);


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
std::istream& read(std::istream &is, Sales_data &rhs){
    double price = 0.0;
    is >> rhs.bookNo >> rhs.units_sold >> price;
    rhs.revenue = rhs.units_sold * price;
    return is;
}

std::ostream& print(std::ostream &os, const Sales_data &rhs){
    os << rhs.isbn() << " " << rhs.avg_price();
    return os;
}

Sales_data sum(const Sales_data &lhs, const Sales_data &rhs){
    Sales_data sum = lhs;
    sum.combine(rhs);
    return sum;
}
