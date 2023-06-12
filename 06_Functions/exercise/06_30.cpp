#include <iostream>
#include <vector>
#include <string>
using namespace std;

using arrT = string[10];

// 6.33 编写一个递归函数，输出vector对象的内容
void print_vector(const vector<int> &vi, int n){
    if(n>0){
        print_vector(vi, n-1);
        printf("%d\n", vi[n-1]);
    }
}

void print_vector2(vector<int>::iterator first, vector<int>::iterator last){
    if(first != last){
        printf("%d\n", *first++);
        print_vector2(first, last);
    }
}

// 6.36 编写函数声明，返回数组的引用并且该数组包含10个string对象
string (&func())[];

// 6.37 
// 使用类型别名
arrT &func1();

// 使用尾置返回类型；使用尾置返回类型最好，只需要一行代码
auto func2() -> string(&)[10];

// 使用decltype关键字
string s[10];
decltype(s) &func3();

// 6.38 修改arrPtr函数，使其返回数组的引用
int odd[] = {1,3,5,7,9};
int even[] = {0,2,4,8,6};
decltype(odd) &arrPtr(int i){
    return (i % 2) ? odd : even;
}

int main()
{
    vector<int> vi{4, 7, 6, 4, 1, 1, 0};
    // print_vector(vi, 7);
    print_vector2(vi.begin(), vi.end());

    return 0;
}