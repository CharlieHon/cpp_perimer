#include <iostream>

int main()
{
    // 练习 1.9
    int sum = 0, val = 50;
    while(val <= 100){
        sum += val++;
    }
    std::cout << "Sum of 50 to 100 inclusive is: " << sum << std::endl;

    //练习 1.10
    sum = 0, val = 10;
    while(val >= 0){
        std::cout << val-- << std::endl;
    }

    //练习 1.11
    std::cout << "Enter two numbers:" << std::endl;
    int a, b;
    std::cin >> a >> b;
    int i = (a <= b ? a : b), j = a+b-i;
    while(i<=j){
        std::cout << i++ << std::endl;
    }

    return 0;
}