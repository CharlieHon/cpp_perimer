#include <iostream>

int main()
{
    //练习1.19
    int a, b;
    std::cin >> a >> b;
    if(a > b){
        for(int i=a; i<=b; ++i){
            std::cout << i << std::endl;
        }
    }else{
        for(int i=b; i<=a; ++i){
            std::cout << i << std::endl;
        }
    }


    return 0;
}