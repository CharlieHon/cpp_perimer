#include <iostream>
#include <string>
#include "Sales_data.h"

int main()
{
    Sales_data total(std::cin);
    if(!total.isbn().empty()){
        std::istream &is = std::cin;
        while(is){  // 有输入
            Sales_data trans(is);
            if(!is) break;  // 输出不为空
            if(trans.isbn() == total.isbn())
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