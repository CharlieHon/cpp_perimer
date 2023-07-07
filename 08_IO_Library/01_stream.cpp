#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

// void print(std::ofstream of){    // 错误：不可复制
//     std::cout << "test: print(std::ofstream)" << std::endl;
// }

std::ofstream& print(std::ofstream &of){    // 可以传引用
    std::cout << "test: print(std::ofstream &)" << std::endl;

    std::ofstream of2;
    return of2; // 返回引用(不应该返回局部对象的引用)
}

void foo(std::ostream &os){
    std::cout << "test ostream!" << std::endl;
}

int main()
{
    // cout是ostream输出流对象
    std::cout << "Hello, C++!" << std::endl;

    std::fstream f;
    std::stringstream ss;

    // IO对象不可复制或赋值
    std::ofstream out1, out2;

    // out1 = out2;    // 错误：不可复制

    print(out1);

    // std::vector<std::ofstream> v;
    // v.push_back(out1);
    // v.push_back(out2);

    foo(std::cout); // cout就是ostream
    std::ofstream ofs;
    foo(ofs);   // ostream的派生类对象也可以

    return 0;
}