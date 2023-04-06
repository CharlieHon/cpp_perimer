#include <iostream>
#include "../Sales_item.h"

int main()
{
    //练习1.23 编写程序，读取多条销售记录，并统计每个ISBN(每本书)有几条销售记录
    // Sales_item currItem, item;
    // if(std::cin >> currItem){
    //     int cnt = 1;
    //     while(std::cin >> item){
    //         if(item.isbn() == currItem.isbn()){
    //             ++cnt;
    //         }else{
    //             std::cout << currItem.isbn() << " occurs "
    //                         << cnt << " times" << std::endl;
    //             currItem = item;
    //             cnt = 1;
    //         }
    //     }
    //     std::cout << currItem.isbn() << " occurs "
    //                 << cnt << " times" << std::endl;
    // }

    //练习1.24
    Sales_item total;
    if(std::cin >> total){
        Sales_item trans;
        while(std::cin >> trans){
            if(trans.isbn() == total.isbn()){
                total += trans;
            }else{
                std::cout << total << std::endl;
                total = trans;
            }
        }
        std::cout << total <<  std::endl;
    }else{
        std::cerr << "No data?" << std::endl;
        return -1;
    }

    return 0;
}