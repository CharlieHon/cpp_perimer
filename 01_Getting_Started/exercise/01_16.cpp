#include <iostream>

int main()
{
    //练习1.16
    int sum = 0, value;
    while(std::cin >> value){
        sum += value;
    }
    std::cout << "sum is " << sum << std::endl;
    return 0;
}