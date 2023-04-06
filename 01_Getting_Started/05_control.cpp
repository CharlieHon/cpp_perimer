#include<iostream>

int main()
{
    std::cout << "Enter two numbers: " << std::endl;
    int v1, v2;
    std::cin >> v1 >> v2;
    int lower, upper;
    if(v1 >= v2){
        upper = v1;
        lower = v2;
    }else{
        lower = v1;
        upper = v2;
    }

    std::cout << "较大值：" << upper
            << " 较小值：" << lower << std::endl;

    int sum = 0, val = 1;
    while(val <= 100){
        sum += val++;
    }
    std::cout << "(while)Sum of 1 to 100 inclusive is "
            << sum << std::endl;

    int sum1 = 0;
    for(int i=1; i<=100; ++i){
        sum1 += i;
    }
    std::cout << "(for)Sum of 1 to 100 inclusive is "
            << sum1 << std::endl;

    int sum2 = 0, value;
    //当有输入时就继续循环，没有输入时就停止循环
    //当使用一个 istream 对象作为条件时，其效果是检测流的状态。如果流是有效的，即流未遇到错误，那么检测成功。
    //当遇到
    while(std::cin >> value){   //按Ctrl+Z表示输入结束
        sum2 += value;
    }
    std::cout << "Sum is: " << sum2 << std::endl;

    return 0;
}


