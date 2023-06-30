#include <iostream>
#include <string>
#include "./exercise/Sales_data.h"

/**
 * @brief 隐式的类类型转换
 * 如果构造函数只接受一个实参，则它实际上定义了转换为此类类型的隐式转换机制，有时把这种构造函数称作转换构造函数(converting constructor)
 * 
 */

int main()
{
    std::string null_book = "9-999-99999-9";
    // 构造一个临时的Sales_data对象
    // 该对象的units_sold和revenue等于0，bookNo等于null_book
    Sales_data item;
    item.combine(null_book);    // 编译器用给定的string自动创建了一个Sales_data对象

    // 只允许一步类类型转换
    // 错误：需要用户定义的两种转换
    // 1.把"9-999-99999-9"转换成string
    // 2.再把这个(临时的)string转换成Sales_data
    // item.combine("9-999-99999-9");

    // 可以显式地把字符串转换成string或者Sales_data对象
    // 正确：显式地转换成string，隐式地转换成Sales_data
    item.combine(std::string("9-999-99999-9"));
    // 正确：隐式地转换成string，显式地转换成Sales_data
    item.combine(Sales_data("9-999-99999-9"));

    // 使用istream构造函数创建一个函数传递给combine
    item.combine(std::cin); // 隐式地把cin转换成Sales_data

    // explicit构造函数只能用于直接初始化
    Sales_data item1(null_book);    // 正确：直接初始化
    //当声明为explicit时错误： 不能将explicit构造函数用于拷贝形式的初始化过程
    Sales_data item2 = null_book;   // 执行拷贝形式的初始化时(使用=)会发生隐式转换

    // 为转换显式地使用构造函数
    // 正确：实参是一个显式构造的Sales_data对象
    item.combine(Sales_data(null_book));
    // 正确：static_cast可以使用explicit的构造函数
    item.combine(static_cast<Sales_data>(std::cin));

    return 0;
}