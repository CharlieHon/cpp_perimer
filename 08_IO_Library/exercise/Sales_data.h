#ifndef SALES_DATA_H
#define SALES_DATA_H

#include <iostream>
#include <string>

class Sales_data{
    friend Sales_data add(const Sales_data&, const Sales_data&);
    friend std::istream& read(std::istream&, Sales_data&);
    friend std::ostream& print(std::ostream&, const Sales_data&);

public:
    // 构造函数
    Sales_data(std::string s, unsigned cnt, double price) :
                bookNo(s), units_sold(cnt), revenue(cnt*price)  {   std::cout << "Sales_data(std::string, unsigned, double)" << std::endl;  }
    // 委托构造函数
    Sales_data() : Sales_data("", 0, 0.0)   {   std::cout << "Sales_data()" << std::endl;}
    Sales_data(std::string s) : Sales_data(s, 0, 0.0)   {   std::cout << "Sales_data(std::string)" << std::endl;    }
    Sales_data(std::istream &is) : Sales_data() {   read(is, *this);    }
    // 函数成员
    std::string isbn() const {   return bookNo;  }
    Sales_data& combine(const Sales_data &rhs);


private:
    double avg_price() const
            {   return units_sold ? revenue/units_sold : 0; }
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

Sales_data add(const Sales_data&, const Sales_data&);
std::istream& read(std::istream&, Sales_data&);
std::ostream& print(std::ostream&, const Sales_data&);

// member function
Sales_data& Sales_data::combine(const Sales_data &rhs){
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

// nonmember function
Sales_data add(const Sales_data &lhs, const Sales_data &rhs){
    Sales_data sum = lhs;
    // s.units_sold += rhs.units_sold;
    // s.revenue += rhs.revenue;
    sum.combine(rhs);
    return sum;
}

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

#endif