#include <iostream>
#include "Sales_item.h"

int main()
{
    //demo1：输入一本书，输出书的信息
    // Sales_item book;
    // std::cout << "请输入销售的第一本书的信息：" << std::endl;
    // std::cin >> book;
    
    // std::cout << "你输入的信息是：" << std::endl;
    // std::cout << book << std::endl;


    //demo2：输入两本书，isbn相同则加起来，不同则报错
    // Sales_item item1, item2;
    // std::cout << "Enter two sale items:" << std::endl;
    // std::cin >> item1 >> item2; //0-201-78345-X 3 20.00 0-201-78345-X 2 15.00
    // if(item1.isbn()==item2.isbn()){
    //     std::cout << item1 + item2 << std::endl;    //0-201-78345-X 5 90 18
    // }else{
    //     std::cerr << "Data must refer to same ISBN"
    //         << std::endl;
    //     return -1;
    // }


    //demo3：连续输入书的信息，相同则加起来
    Sales_item total, trans;
    if(std::cin >> total){
        while(std::cin >> trans){
            if(total.isbn() == trans.isbn()){
                //如果是同一种书，则相加
                total = total + trans;
            }else{
                //输出已统计的书
                std::cout << total << std::endl;
                //继续统计下一种书
                total = trans;
            }
        }
    }else{
        std::cerr << "NO DATA?" << std::endl;
        return -1;
    }


    return 0;
}