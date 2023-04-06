#include<iostream>  //预处理指令

int main()
{
    //std名称空间 ::作用域操作符 endl换行，操作符，刷新与显示相关的内容
    std::cout << "Enter two numbers:" << std::endl;
    int v1, v2;
    std::cin >> v1 >> v2;   //cin: 标准输入对象
    std::cout << "The sum of " << v1 << " and " << v2
        << " is " << v1+v2 << std::endl;

    return 0;
}