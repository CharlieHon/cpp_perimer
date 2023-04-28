#include <iostream>

using std::cout; using std::cin; using std::endl;

int f();
int g();
int h();
int j();

int main()
{
    // 优先级和结合律
    int ia[] = {0,2,4,6,8};
    int last = *(ia+4); // 等价于 int last = ia[4]
    last = *ia + 4; // last = ia[0] + 4

    // IO相关的运算符满足左结合律，可以把几个IO运算对象结合在一条表达式当中
    int v1, v2;
    cin >> v1 >> v2;

    // 求值顺序
    int i = 0;
    cout << i << " " << ++i << endl;    // 未定义，无论编译器是否报错，该段代码都是错误的

    // 求值顺序、优先级、结合律
    int x = f()+ g()*h()+j();
    // 优先级规定，g()的返回值和h()的返回值相乘
    // 结合律规定，f()的返回值先与g()和h()的乘积相加，所得结果再与j()的返回值相加
    // 求值顺序：对于这些函数的调用顺序没有明确规定

    return 0;
}

int f(){
    return 1;
}
int g(){
    return 2;
}
int h(){
    return 3;
}
int j(){
    return 4;
}