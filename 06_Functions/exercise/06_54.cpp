#include <iostream>
#include <vector>
using namespace std;

using funcP = int(*)(int, int);

// f1是一个函数，参数为一个int类型，返回一个指针；指针指向一个返回类型为int，有两个参数的函数
int (*f1(int))(int*, int);
auto f2(int) -> int(*)(int*, int);  // 尾置返回类型

// 6.54 编写函数声明，令其接受两个int形参并且返回类型也是int
int func(int, int);
// 声明一个vector对象，令其元素是指向该函数的指针
vector<int(*)(int,int)> v1; // 如下等价
// vector<decltype(func)*> v2;
// vector<funcP> v3;

// 6.55 编写4个函数，分别对两个int值执行加减乘除运算
// 在上面创建的vector对象中保存指向这些函数的指针
int sum(int a, int b){
    return a + b;
}
int sub(int a, int b){
    return a - b;
}
int mult(int a, int b){
    return a * b;
}
int divide(int a, int b){
    if(b==0)    return -1;
    return a / b;
}

int main()
{
    v1.push_back(sum);  // 函数名隐式转换为指向该函数的指针
    v1.push_back(sub);
    v1.push_back(*mult);    // 显示的表示指向函数mult的指针
    v1.push_back(*divide);

    // 结果同上
    vector<decltype(func)*> vec{sum, sub, mult, divide};

    // 6.56 调用上述vector对象中的每个元素并输出其结果
    for(auto elem : v1)
        cout << elem(10, 5) << endl;

    return 0;
}