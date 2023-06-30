#include <iostream>
#include <string>

/**
 * @brief 委托构造函数
 * 一个委托构造函数使用它所属类的其他构造函数执行它自己的初始化过程，或者说它把它自己的一些(或者全部)职责委托给了其他构造函数
 * - 在委托构造函数内，成员初始值列表只有一个唯一的入口，就是类名本身。
 *      和其他成员初始值一样，类名后面紧跟圆括号括起来的参数列表，参数列表必须与类中另外一个构造函数匹配。
 * - 当一个构造函数委托给另一个构造函数时，受委托的构造函数的初始值列表和函数体依次执行，然后控制权才会交还给委托者的函数体。
 */

class Sales_data{
    friend std::istream& read(std::istream&, Sales_data&);
public:
    // 非委托构造函数使用对应的实参初始化成员
    Sales_data(std::string s, unsigned cnt, double price) :
                bookNo(s), unit_sold(cnt), revenue(cnt*price)   { std::cout << "Sales_data(std::string, unsigned, double)" << std::endl; }
    // 其余构造函数全部委托给另一个构造函数
    Sales_data() : Sales_data("", 0, 0) {   std::cout << "Sales_data()" << std::endl;   }
    Sales_data(std::string s) : Sales_data(s, 0, 0) {   std::cout << "Sales_data(std::string)" << std::endl;    }
    Sales_data(std::istream &is) : Sales_data() {read(is, *this);   std::cout << "Sales_data(std::istream)" << std::endl;}  // 这个函数体是 Sales_data(std::istream&is) 的

private:
    std::string bookNo;
    unsigned unit_sold = 0;
    double revenue = 0.0;
};

std::istream& read(std::istream&, Sales_data&);

int main()
{
    std::cout << "-----Sales_data s1-----" << std::endl;
    Sales_data s1("01-7-1", 28, 10);    // Sales_data(std::string, unsigned, double)
    std::cout << "-----Sales_data s2-----" << std::endl;
    Sales_data s2;  // Sales_data(std::string, unsigned, double)    Sales_data()
    std::cout << "-----Sales_data s3-----" << std::endl;
    Sales_data s3(std::cin);    // Sales_data(std::string, unsigned, double)    Sales_data()    02-10-1 100 2   Sales_data(std::istream)

    return 0;
}

std::istream& read(std::istream &is, Sales_data &rhs){
    double price = 0.0;
    is >> rhs.bookNo >> rhs.unit_sold >> price;
    rhs.revenue = rhs.unit_sold * price;
    return is;
}
