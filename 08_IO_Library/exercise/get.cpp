#include "get.h"

std::istream& get(std::istream &is){
    int ival;
    while(is >> ival, !is.eof()){
        if(is.bad())
            throw std::runtime_error("IO stream corrupted!");
        if(is.fail()){
            std::cerr << "Bad data, try again." << std::endl;
            is.clear(); // 清空流状态
            is.ignore(200, '\n');   // 忽略流中未读出的数据
            continue;
        }
        std::cout << "The input data: " << ival << std::endl;
    }
    is.clear(); // 清空流状态
    return is;
}