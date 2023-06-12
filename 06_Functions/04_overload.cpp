#include <iostream>


using namespace std;
/*
    如果同一作用域内的几个函数名字相同但形参列表不同，称之为重载(overload)函数
    当调用函数时，编译器会根据传递的实参推断想要的是哪个函数

    对于重载的函数，应该在 形参数量 或 形参类型 上有所不同，与函数返回类型无关。
*/

void print(const char *);
void print(int ia[], size_t size);
void print(const int *beg, const int *end);

// 顶层const不影响传入函数的对象，一个拥有顶层const的形参无法和另一个没有顶层的const的形参区分开来
int func(int);
int func(const int);    // 重复声明了 int func(int)

int func(int *);
int func(int* const );  // 顶层指针对象。重复声明了 int func(int *)

// 如果形参是某种类型的指针或引用，则通过区分其指向的常量对象还是非常量对象可以实现函数重载，此时的const是底层的
int func(int &);
int func(const int &);  // 新函数，作用于常量引用

int func(int *);
int func(const int *);  // 新函数，作用于指向常量的指针


string read();
void print1(const string &);
void print1(double);

void fooBar(int ival){
    bool read = false;  // 新作用域：隐藏了外层的read
    // string s = read();  // read是一个布尔值，而非函数
    void print1(int);   // 新作用于：隐藏之前print1
    // print1("Value: ");  // 错误：print1(const string &)被隐藏掉了
    print1(ival);       // 正确：当前print1(int)可见
    print1(3.14);       // 正确：调用print1(int)

}

int main()  // main函数不能重载
{
    int j[2] = {0, 1};
    print("Hello World");
    print(j, end(j)-begin(j));
    print(begin(j), end(j));

    return 0;
}