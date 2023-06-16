#include <iostream>
#include <string>

using namespace std;

struct Sales_data{
    string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};


struct Sales_data1{
    // 所有成员都必须在类内*声明*，但是成员函数可以*定义*在类内也可以定义在类外
    // 成员函数：定义在类内部的函数是隐式的 inline 函数
    
    // 编译器先编译成员的声明，然后是成员函数体。因此，成员函数体可以随意使用类中的其他成员而无须在意成员出现的次序
    string isbn() const {return bookNo;}        // 常量成员函数：const表示隐式参数 this 是指向常量的指针
    Sales_data1& combine(const Sales_data1&);
    double avg_price() const;

    // 数据成员
    string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};
// Sales_data1的非成员接口函数
// Sales_data1 add(const Sales_data1&, const Sales_data1&);
ostream &print(ostream&, const Sales_data1&);
istream &read(istream&, Sales_data1&);
Sales_data1 add(const Sales_data1 &lhs, const Sales_data1 &rhs);

int main()
{
    Sales_data total;
    if (cin >> total.bookNo >> total.units_sold >> total.revenue){
        Sales_data trans;
        while (cin >> trans.bookNo >> trans.units_sold >> trans.revenue){
            if (trans.bookNo == total.bookNo){
                total.units_sold += trans.units_sold;
                total.revenue += trans.revenue;
            }else {
                cout << total.bookNo << " " << total.units_sold << " " << total.revenue << endl;
                total = trans;
            }
        }
        cout << total.bookNo << " " << total.units_sold << " " << total.revenue << endl;
    }else {
        cerr << "No data?" << endl;
    }

    return 0;
}

// 函数名使用作用域运算符
double Sales_data1::avg_price() const {
    if (units_sold)
        return revenue / units_sold;
    else
        return 0;
}

Sales_data1& Sales_data1::combine(const Sales_data1 &rhs){
    units_sold += rhs.units_sold;   // 把 rhs 的成员加到 this 对象的成员上
    revenue += rhs.revenue;
    return *this;   // 返回调用该函数的对象
}

// 类相关的非成员函数
istream& read(istream &is, Sales_data1 &item){
    double price = 0;
    is >> item.bookNo >> item.units_sold >> price;
    item.revenue = price * item.units_sold;
    return is;
}

ostream& print(ostream &os, const Sales_data1 &item){
    os << item.isbn() << " " << item.units_sold << " "
        << item.revenue << " " << item.avg_price();
    return os;
}

Sales_data1 add(const Sales_data1 &lhs, const Sales_data1 &rhs){
    Sales_data1 sum = lhs;  // 把 lhs 的数据成员拷贝给 sum
    sum.combine(rhs);   // 把 rhs 的数据成员加到 sum 当中
    return sum;
}
