#include <iostream>
#include <string>

// 7.2
struct Sales_data{
    
    // 成员函数
    Sales_data& combine(const Sales_data &rhs);
    std::string const isbn() const {return bookNo;}
    // 数据成员
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

std::istream& read(std::istream &is, Sales_data &item);
std::ostream& print(std::ostream &os, const Sales_data &item);
Sales_data add(const Sales_data &lhs, const Sales_data &rhs);

// 7.3
struct Person
{
    // 构造函数
    Person() = default;
    Person(const std::string &n, const std::string &add) : name(n), address(add)  {}
    Person(std::istream &is)    {read(is, *this);}

    std::string getName() const  {return name;}
    std::string getAddress() const {return address;}

    std::string name;
    std::string address;
};

std::istream& read(std::istream &is, Person &p){
    is >> p.name >> p.address;
    return is;
}

std::ostream& print(std::ostream &os, Person &p){
    os << p.getName() << " " << p.getAddress();
    return os;
}

// 练习7.10：在下面if语句中，条件部分的作用是什么？
/*
    if(read(read(cin, data1), data2))
    // 等价于 read(cin, data1); read(cin, data2);
    // read函数返回值是`istream`对象，`if`语句中条件部分的作用是从输入流中读取数据给两个`data`对象。
*/

int main()
{
    Sales_data total;
    if (std::cin >> total.bookNo >> total.units_sold >> total.revenue){
        Sales_data trans;
        while(std::cin >> trans.bookNo >> trans.units_sold >> trans.revenue){
            if(trans.isbn() == total.isbn()){
                // total.units_sold += trans.units_sold;
                // total.revenue += trans.revenue;
                total.combine(trans);
            }else{
                // std::cout << total.bookNo << " " << total.units_sold << " " << total.revenue << std::endl;
                print(std::cout, total) << std::endl;   // print不负责输出格式
                total = trans;
            }
        }
        // std::cout << total.bookNo << " " << total.units_sold << " " << total.revenue << std::endl;
        print(std::cout, total) << std::endl;
    }else{
        std::cerr << "No data?" << std::endl;
        return -1;
    }
    return 0;
}

// member function
Sales_data& Sales_data::combine(const Sales_data &rhs){
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

// 非成员函数

// 读入数据
std::istream& read(std::istream &is, Sales_data &item){
    double price = 0.0;
    is >> item.bookNo >> item.units_sold >> price;
    item.revenue = price * item.units_sold;
    return is;
}

// 输出数据
std::ostream& print(std::ostream &os, const Sales_data &item){
    os << item.isbn() << " " << item.units_sold << " " << item.revenue; // 不负责换行，输出格式应由类用户决定
    return os;
}

// 计算相加
Sales_data add(const Sales_data &lhs, const Sales_data &rhs){
    Sales_data sum = lhs;
    sum.combine(rhs);
    return sum;
}
