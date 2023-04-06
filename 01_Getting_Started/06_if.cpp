#include <iostream>

int main()
{
    //统计在输入中每个值连续出现了多少次
    //currVal是正在统计的数，将读入的新值存入val
    int currVal = 0, val = 0;
    if(std::cin >> currVal){    //保证输入不为空
        int cnt = 1;
        while(std::cin >> val){
            if(val == currVal){
                ++cnt;
            }else{
                std::cout << currVal << " occurs "
                        << cnt << " times" << std::endl;
                currVal = val;
                cnt = 1;
            }
        }
        std::cout << currVal << " occurs "
                << cnt << " times" << std::endl;
    }

    return 0;
}