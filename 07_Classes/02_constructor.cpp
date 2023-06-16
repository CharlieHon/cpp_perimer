#include <iostream>

/**
 * @brief 构造函数
 * 每个类都分别定义了它的对象被初始化的方式，类通过一个或几个特殊的函数来控制其对象的初始化过程，这些函数叫做构造函数(constructor)
 * - 初始化类的数据成员，只要类的对象被创建，就会执行构造函数
 * - 构造函数的名字和类名相同
 * - 构造函数没有返回类型
 * - 不能被声明成 const的
 * 
 * - 当类没有声明任何构造函数时，编译器才会自动地生成默认构造函数，称为合成的默认构造函数
 *  - 如果存在类内的初始值，用它来初始化成员
 *  - 否则，默认初始化该成员
 */

struct Sales_data{
    // 构造函数
    Sales_data() = default; // 默认构造函数，在定义了其他构造函数后，编译器不会在隐式合成默认构造函数
    // Sales_data() : units_sold(0), revenue(0)    {}   // 练习7.14
    Sales_data(const std::string &s) : bookNo(s) {} // 构造函数初始值列表，被忽略的成员以与合成默认构造函数相同的方式隐式初始化
    // 等价于 Sales_data(const std::string &s) : bookNo(s), units_sold(0), revenue(0.0) {}  // 如果编译器不支持类内初始值，则所有构造函数都应该显示地初始化每个内置类型的成员
    Sales_data(const std::string &s, unsigned n, double p) :
            bookNo(s), units_sold(n), revenue(p*n) {}
    Sales_data(std::istream &);
    // Sales_data(std::istream &is){   // 练习7.12
    //     read(is, *this);
    // }

    // 之前已有的其他成员
    std::string isbn() const {return bookNo;}
    Sales_data& combine(const Sales_data &);
    double avg_price() const;
    // 数据成员
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};
// 非成员函数
std::istream& read(std::istream &is, Sales_data &item);
std::ostream& print(std::ostream &os, const Sales_data &item);
Sales_data add(const Sales_data &lhs, const Sales_data &rhs);

int main()
{
    // Sales_data item1;   // 使用默认构造函数
    // print(std::cout, item1) << std::endl;   // "" 0 0
    
    // Sales_data item2("C++ Primer");
    // print(std::cout, item2) << std::endl; // C++ Primer 0 0

    // Sales_data item3("Fluent Python", 1, 36.2);
    // print(std::cout, item3) << std::endl;    // Fluent Python 1 36.2

    // Sales_data item4(std::cin); // 从输入中定义 Sales_data 对象
    // print(std::cout, item4) << std::endl;

    // 练习7.13
    Sales_data total(std::cin);
    if(!total.isbn().empty()){
        std::istream &is = std::cin;
        while(is){
            Sales_data trans(is);
            if(!is) break;  // trans为空
            if(total.isbn() == trans.isbn())
                total.combine(trans);
            else{
                print(std::cout, total) << std::endl;
                total = trans;
            }
        }
        print(std::cout, total) << std::endl;
    }else{
        std::cerr << "No data?" << std::endl;
        return -1;
    }

    return 0;
}

// 在类的外部定义构造函数
Sales_data::Sales_data(std::istream &is){
    read(is, *this);    // read函数的作用是从is中读取一条交易信息然后
                        // 存入this对象中
}

Sales_data& Sales_data::combine(const Sales_data &item){
    units_sold += item.units_sold;
    revenue += item.revenue;
    return *this;
}

double Sales_data::avg_price() const {
    return this->revenue / this->units_sold;
}

// 非成员函数
// 输入Sales_data内容
std::istream& read(std::istream &is, Sales_data &item){
    double price = 0.0;
    is >> item.bookNo >> item.units_sold >> price;
    item.revenue = item.units_sold * price;
    return is;
}
// 输出Sales_data对象内容
std::ostream& print(std::ostream &os, const Sales_data &item){
    os << item.isbn() << " " << item.units_sold << " " << item.revenue;
    return os;
}
// 两个Sales_data对象相加
Sales_data add(const Sales_data &lhs, const Sales_data &rhs){
    Sales_data sum = lhs;
    sum.combine(rhs);
    return sum;
}