#include <iostream>

int main()
{
    int ival = 42;
    int *p = &ival; //p存放变量ival的地址，或者说p是指向变量ival的指针

    //指针的类型要和它所指的对象严格匹配
    double dval;
    double *pd = &dval;
    double *pd2 = pd;

    // int *pi = pd;   //错误：类型不匹配
    // pi = &dval;     //错误：类型不匹配

    //利用指针访问对象
    std::cout << *p << std::endl;   // 42

    //空指针
    int *p1 = nullptr;  //nullptr空指针字面值
    int *p2 = 0;        //与上等价
    // 需要首先 #include <cstdlib>
    int *p3 = NULL;     //等价于 int *p3 = 0;

    //把int变量直接赋给指针是错误的操作,即使int变量的值恰好等于0也不行
    int zero = 0;
    // int *pi = zero;  //错误:不能把int变量直接赋给指针

    //其他指针操作
    int *pi = 0;
    if(pi)
        std::cout << "pi的值为0,因此条件的值是false" << std::endl;
    
    if(*pi)
        std::cout << "pi指向的值是0,因此条件是false" << std::endl;

    //如果两个指针存放的地址值相同,则它们相等
    //地址值相等由三种可能:都为空;都指向同一个对象;都指向了用一个对象的下一个地址

    //void*指针
    double obj = 3.14, *pd3 = &obj;
    void *pv = &obj;    //obj可以是任意类型的对象
    pv = pd3;

    return 0;
}