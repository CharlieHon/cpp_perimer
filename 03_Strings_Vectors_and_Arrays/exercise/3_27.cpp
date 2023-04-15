#include <iostream>
#include <string>
#include <vector>
#include <cstddef>
using namespace std;

string sa[10];  // 初始值为10个空串
int ia[10];     // 初始值为10个0

int main()
{
    // 练习3.27,txt_size是一个无参数函数
    unsigned buf_size = 1024;
    // int ia1[buf_size];   // 错误:数组的维度必须是一个常量表达式
    int ia2[4*7 - 14];   // √
    // int ia3[txt_size()];    // 错误:txt_size()的值必须到运行时才能得到
    // char st[11] = "fundamental";    // 错误:数组大小应该是12,字符串字面值还有一个空字符没包含进去

    // 练习3.28:下列数组中元素的值是什么
    string sa2[10]; // 初始值是10个空串
    int ia4[10];    // 在main函数内部,元素值全部未定义

    // 练习3.31:编写一段程序,定义一个含有10个int的数组,令每个元素的值就是其下标值
    int a[10];
    for(int i=0; i<10; ++i){
        a[i] = i;
    }
    for(auto x : a){
        cout << x << " ";
    }
    cout << endl;

    // 练习3.32:将上一题刚刚创建的数组拷贝给另外一个数组
    int b[10];
    for(int i=0; i<10; ++i){
        b[i] = a[i];
    }
    for(auto x : b){
        cout << x << " ";
    }
    cout << endl;
    
    // 利用vector重写程序,实现类似功能
    vector<int> v1;
    for(int i=0; i<10; ++i)
        v1.push_back(i);
    vector<int> v2(v1);

    return 0;
}