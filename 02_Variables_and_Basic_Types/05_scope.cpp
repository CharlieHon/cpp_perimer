#include <iostream>

/*
 * 程序定义了3个名字：main、sum和val
 * 同时使用了命名空间名字std，该空间提供了2个名字cout和cin供程序使用。
 * main定义于所有花括号意之外，拥有全局作用域
 * sum拥有块作用域
 * val定义于for语句内，在for语句之内可以访问val，但是在main函数的其他部分就不能访问它了
*/
int main()
{
    int sum = 0;
    for(int val=1; val<=10; ++val){
        sum += val;
    }
    std::cout << "Sum pf i to 10 inclusive is "
                << sum << std::endl;

    return 0;
}