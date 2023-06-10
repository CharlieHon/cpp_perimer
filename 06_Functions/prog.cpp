#include <iostream>
#include <cstring>
#include <string>

// 6.25 main：处理命令行选项
int main(int argc, char *argv[]){
    // 第二个形参 agrv 是一个数组，它的元素是指向C风格字符串的指针
    // 当实参传给 main 函数之后，argv的第一个元素指向程序的名字或者一个空字符串
    // 接下来的元素一次传递命令行提供的实参。最后一个指针之后的元素值保证为0.
    // 第一个形参 argc 表示数组中字符串的数量
    std::cout << "The name of the program is " << argv[0] << std::endl;
    std::cout << "The num of the arguments is " << argc << std::endl;
    // 6.25
    // if(argc>=3){    // 传入参数超过3个，即不算函数名还有2个参数，再进行拼接
    //     std::string s(strcat(argv[1], argv[2]));
    //     std::cout << s << std::endl;
    // }

    // 6.26
    for(size_t i=0; i!=argc; ++i){
        std::cout << argv[i] << std::endl;
    }

}