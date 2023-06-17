#include <iostream>
#include <string>

// 练习7.31：定义一对类X和Y，其中X包含一个指向Y的指针，而Y包含一个类型为X的对象
class Y;
class X{
    Y *py = nullptr;    // 类声明后，就可以定义指向该类型的指针
};

class Y{
    X x;    // 只有类全部完成后，才能一定该类类型的成员
};

int main()
{

    return 0;
}