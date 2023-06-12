#include <iostream>

using namespace std;

typedef int arrT[10];   // arrT是一个类型别名，表示的类型是含有10个整数的数组
using arrT2 = int[10];  // 与上等价

arrT* func(int i);  // 返回一个指向含有10个整数的数组的指针

int (*func2(int i))[10];    // 不使用类型别名，返回数组的指针

/*
func(int i) 表示调用func函数需要传入一个整型实参
(*func(int i)) 表示可以对函数调用结果执行解引用操作
(*func(int i))[10] 表示解引用func的调用将得到一个大小是10的数组
int (*func(int i))[10] 表示数组中的元素是int类型
*/

// 尾置返回类型
// 尾置返回类型跟在形参列表后面并以->开头，为表示函数真正的返回类型跟在形参列表之后，
// 在本应该出现返回类型的地方放置一个auto
auto func3(int i) -> int(*)[];

// 使用decltype
int odd[] = {1, 3, 5, 7, 9};
int even[] = {2, 4, 6, 8, 0};
// decltype并不负责把数组类型转换成对应的指针，所以decltype的结果是个数组
decltype(odd) *arrPtr(int i){
    // 这里不能去掉取地址运算符&
    return (i % 2) ? &odd : &even;  // 返回一个指向数组的指针
}

// 无返回值函数
void swap(int &a, int &b){
    if(a == b)  return;
    int tmp = a;
    a = b;
    b = tmp;
    // 最后一句后面会隐式地执行return
}

int main()
{


    return 0;
}