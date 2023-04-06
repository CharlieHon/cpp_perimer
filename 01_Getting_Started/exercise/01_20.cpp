#include <iostream>
#include "../Sales_item.h"

int main()
{
    //练习1.20
    for(Sales_item book; std::cin >> book; std::cout << book << std::endl);
    //编译：g++ --std=c++11 01_20.cpp -o main
    //文件重定向：main.exe < add_item

    //练习1.21
    Sales_item item1, item2;
    std::cin >> item1 >> item2;
    std::cout << "sum of item1 and item2 is " << item1 + item2 << std::endl;

    //练习1.22
    Sales_item sum_item, item;
    std::cin >> sum_item;
    while(std::cin >> item){
        sum_item += item;
    }
    std::cout << "sum of items is " << sum_item << std::endl;

    return 0;
}