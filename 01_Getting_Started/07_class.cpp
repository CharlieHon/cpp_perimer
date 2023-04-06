#include <iostream>
#include "Sales_item.h"
//包含来自标准库的头文件是，应该使用尖括号(<>)包围文件名
//对于不属于标准库的头文件，则用双引号("")包围。

int main()
{
    //读写 Sales_item
    Sales_item book;    //定义类类型的变量
    //读入ISBN号、售出的册数以及销售价格
    std::cin >> book;
    //写入ISBN、售出的册数、总销售额和平均价格
    std::cout << book << std::endl;

    //Sales_item对象的加法
    Sales_item item1, item2;
    std::cin >> item1 >> item2;                 //读取一对交易记录
    std::cout << item1 + item2 << std::endl;    //打印它们的和

    return 0;
}