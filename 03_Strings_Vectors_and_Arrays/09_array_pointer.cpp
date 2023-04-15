#include <iostream>
#include <string>
#include <vector>
#include <cstddef>

using namespace std;

int main()
{
    string nums[] = {"one", "two", "three"};    // 数组的元素是string对象
    string *p = &nums[0];   // p指向nums的第一个元素
    string *p1 = nums;      // 与上等价,nums自动转换为首元素地址

    // 当使用数组作为一个auto变量的初始值时,推断得到的类型是指针而非数组
    int ia[] = {0,1,2,3,4,5,6,7,8,9};
    auto ia2(ia);   // 等价于 auto ia2(&ia[0]);  ia2是一个整型指针,指向ia的第一个元素
    // ia2 = 42;   // 错误:不能用int值给指针赋值

    // 当使用decltype关键字时,上述转换不会发生
    decltype(ia) ia3 = {0,1,2,3,4,5,6,7,8,9};   // ia3是一个含有10个整数的数组
    ia3[4] = 42;    // 把42赋值给ia3的一个元素

    // 指针也是迭代器
    int arr[] = {0,1,2,3,4,5,6,7,8,9};
    int *p2 = arr;  // p2指向arr的第一个元素
    ++p2;           // p2指向arr[1]

    // 使用指针遍历数组中的元素
    int *e = &arr[10];  // 指向arr尾元素的下一位置的指针
    for(int *b=arr; b!=e; ++b)
        cout << *b << endl; // 输出arr的元素

    int a[] = {0,1,2,3,-4,5,6,7,8,9};
    int *beg = begin(a), *last = end(a); // 指向a首元素和尾元素的下一位置的指针
    // 寻找第一个负值元素,如果已检查完全部元素则结束循环,输出结果-4
    while(beg != last){     // 通过比较beg和last来确保可以安全对beg解引用
        if(*beg < 0){
            cout << *beg << endl;
            break;
        }
        ++beg;
    }

    // 指针运算
    constexpr size_t sz = 5;
    int b[sz] = {0,1,2,3,4};
    int *ip = b;    // 等价于 int *ip = &b[0]
    int *ip2 = b+4; // ip2指向b的尾元素b[4]
    int *ip3 = b+sz;    // 正确:ip3指向了b尾元素的下一位置,不要解引用
    // int *ip4 = b+10;    // 错误:b只有5个元素,ip4的值未定义,编译器不会报错
    auto d = end(b) - begin(b); // d的值为5,即b中元素的数量

    // 下标和指针
    int arr1[] = {0,2,4,6,8};
    int x = arr1[2];    // arr1[2]使用了数组名的表达式,对数组执行下标运算其实是对指向数组元素的指针指向下标运算

    int *ip5 = arr1;
    x = *(ip5+2);   // 等价于 x = arr1[2]

    int *ip6 = &arr1[2];    // ip6指向索引为2的元素
    int y = ip6[1];         // ip6[1]等价于 *(ip6+1),就是ip6[3]表示的那个元素
    int z = ip6[-2];        // ip6[-2]是arr1[0]表示的那个元素

    


    return 0;
}

