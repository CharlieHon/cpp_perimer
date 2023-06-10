#include <cstdio>
#include <string>
#include <cstring>
#include <vector>
#include <initializer_list>
using namespace std;

void swap1(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
    return;
}

void reset(int &a){
    a = 996;
    return;
}

void swap2(int &a, int &b){
    int tmp = a;
    a = b;
    b = tmp;
    return;
}

// 练习6.14
int add(int a, int b){  // 不能是引用类型
    return a+b;
}

// 练习6.16：只能作用于string对象，而字面值、const string都不能用
bool is_empty(string &s){   return s.empty();   }

// 练习6.17：编写函数判断string对象中是否包含大写字母；编写另一个函数把stirng对象全都改成小写形式。
bool find_lower(const string &s){
    for(string::size_type i=0; i!=s.size(); ++i){
        if(s[i]>'a' && s[i]<='z'){
            return true;
        }
    }
    return false;
}

void to_lower(string &s){
    for(string::size_type i=0; i!=s.size(); ++i){
        s[i] = tolower(s[i]);
    }
}

// 6.18 编写函数声明
// bool compare(const matrix &, const matrix &);
// vector<int>::iterator change_val(int, vector<int>::iterator);

// 6.21
int compare_two_int(const int a, const int *const b){
    return (a>*b) ? a : *b;
}

// 6.22 编写一个函数，令其交换两个int指针
void swap_pointer(const int* &a, const int* &b){    // 形参为引用格式
    auto tmp = a;
    a = b;
    b = tmp;
    return;
}

// 编写print函数
void print(const int *pi){
    if(pi)  printf("%d\n", *pi);
}

// void print(const int *p){
//     if(p){
//         while(*p)  printf("%d ", *p++);
//     }
// }

void print(const int *beg, const int *end){
    while(beg != end){
        printf("%d ", *beg++);
    }
}

void print(const int (&a)[2]){
    for(auto elem : a)
        printf("%d ", elem);
}

void print(const int ia[], size_t size){
    for(size_t i=0; i!=size; ++i)
        printf("%d ", ia[i]);
}

// 6.27
int sum_list(initializer_list<int> const &lst){ // 常量引用
    int sum = 0;
    for(const auto elem : lst){
        sum += elem;
    }
    return sum;
}

int main()
{
    // 6.10 编写一个函数，使用指针形参交换两个整数的值。
    // 在代码调用该函数并输出交换后的结果
    int a = 1, b = 2;
    printf("a=%d, b=%d\n", a, b);
    swap1(&a, &b);
    printf("after swap:a=%d, b=%d\n", a, b);

    // 6.11
    reset(a);
    printf("after reset:a=%d\n", a);

    // 6.12
    // 使用引用交换两个整数更方便，因为不需要传地址，而且不需要对指针指向的内容赋值

    // 6.13
    // void f(T) 的参数通过值传递，在函数中T是实参的副本，改变T不会影响原来的实参。
    // void f(&T) 为引用传递，在函数中的T是实参的引用，改变T实参也会改变。

    // 6.14 举一个形参不能是引用类型的例子
    // 当实参的值是右值时，形参不能为引用类型。

    // 6.15
    // 字符串可能很长，使用引用可以避免拷贝，因为不需要改变字符串s的内容，所以用常量引用
    // occurs需要统计字符c出现的次数，是变量
    // 只需要c的值，这个实参可能是右值(右值无法用于引用形参)，所以c不能用引用类型

    // 6.17
    string s1("HELLO"), s2("Thanks");
    if(find_lower(s1))  printf("%s has any of a~z!\n", s1.c_str());
    else    printf("NOT FOUND\n");
    if(find_lower(s2))  printf("%s has any of a~z!\n", s2.c_str());
    printf("before is %s\n", s1.c_str());
    to_lower(s1);
    printf("after to_lower is %s\n", s1.c_str());

    // 6.21 
    int i=0, j[2] = {0, 1};
    print(&i);
    print(begin(j), end(j));

    auto i1 = {1, 2, 3, 4, 9};
    printf("Sum of the list is %d\n", sum_list(i1));   // 19

    return 0;
}