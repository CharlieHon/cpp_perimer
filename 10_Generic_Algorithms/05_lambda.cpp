#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

/**
 * @brief 10.3.3 lambda捕获和返回
 * 当定义一个lambda时。编译器生成一个与lambda对应的新的(未命名的)类类型
 * 当向一个函数传递一个lambda时，同时定义了一个新类型和该类型的一个对象：传递的参数就是此编译器生成的类类型的未命名对象
 * 默认情况下，从lambda生成的对象都包含一个对应该lambda所捕获的变量的数据成员。
 * 
 * 当采用引用方式捕获一个变量，就必须确保被引用的对象在lambda执行的时候是存在的
 * 
 * lambda捕获列表
 * []：空捕获列表。lambda不能使用所在函数中的变量
 * [names]：names是一个逗号分隔的名字列表。默认情况下，捕获列表中的变量都被拷贝，名字前如果使用&，则采用引用捕获方式
 * [&] 或 [=]：隐式捕获列表，采用引用(&)捕获或值(=)捕获
 * [&, identifier_list] 或 [=, identifier_list]: identifier_list采用另外的方式捕获
 * 
 * 指定lambda返回类型
 * 默认情况下，如果一个lambda体包含return之外的任何语句，则编辑器假定此lambda返回void
 * 
 */

void fcn1(){    // 值捕获
    size_t v1 = 42; // 局部变量
    auto f = [v1]{return v1;};  // 将v1拷贝到名为f的可调用对象
    v1 = 0;
    auto j = f();
    cout << j << endl;  // j为42，f保存了我们创建时对v1的拷贝
}

void fcn2(){    // 引用捕获
    size_t v1 = 42;
    auto f = [&v1]{return v1;}; // 对象f包含v1的引用
    v1 = 0;
    int j = f();
    cout << j << endl;  // j为0
}

void biggies(vector<string> &words, vector<string>::size_type sz,
            ostream &os = cout, char c = ' '){
    // 与之前例子一样的重排words的代码
    // 打印 count 的语句改为打印到os
    // for_each(words.begin(), words.end(), [&os, c](const string &s){os << s << c;});
    // 不能拷贝ostream对象，因此捕获os的唯一方法就是捕获其引用(或指向os的指针)

    // 隐式捕获
    // os隐式捕获，引用捕获方式；c显式捕获，值捕获方式
    // for_each(words.begin(), words.end(), [&, c](const string &s){os << s << c;});
    // os显式捕获，引用捕获方式；c隐式捕获，值捕获方式
    // for_each(words.begin(), words.end(), [=, &os](const string &s){os << s << c;});
    
    // !: 当混合使用隐式捕获和显式捕获时，捕获列表中的第一个元素必须是一个&或=
    // 此符号指定了默认捕获方式为引用或值
    // 当混合使用时，显式捕获的变量必须使用与隐式捕获不同的方式
}

void fcn3(){    // 可变lambda
    size_t v1 = 42; // 局部变量
    // f可以改变它所捕获变量的值
    auto f = [v1] () mutable { return ++v1; };
    v1 = 0;
    auto j = f();   // 43
    cout << j << endl;
}

void fcn4(){    // 可变lambda
    size_t v1 = 42; // 局部变量
    // f可以改变它所捕获变量的值
    auto f = [&v1] { return ++v1; };
    v1 = 0;
    auto j = f();   // 1
    cout << j << endl;
}

int main()
{
    // 值捕获
    // 采用值捕获的前提是变量可以拷贝。不参数不同，被捕获的变量的值是在lambda创建时拷贝，而不是拷贝
    fcn1(); // 42

    // 引用捕获
    fcn2(); // 0

    // 隐式捕获
    // 为了指示编译器推断捕获列表，应在捕获列表中写一个&或=，&告诉编译器采用捕获引用方式，=则采用值捕获方式

    // 可变lambda
    // 默认情况下，对于一个值被拷贝的变量，lambda不会改变其值。如果希望改变，就必须在参数列表首加上关键字mutable
    fcn3(); // 43
    fcn4(); // 1

    // 指定lambda返回类型
    vector<int> vi{-1, 5, 6, -6, 10, 7, 12};
    transform(vi.begin(), vi.end(), vi.begin(),
                [](int i){return i<0 ? -i : i;});    // 将一个序列中的每个负数替换为其绝对值
    /*
    transform(vi.begin(), vi.end(), vi.begin(),
                [](int i){ if(i<0) return -i; return i;});  // 错误：不能推断lambda的返回类型
    */

    // 当需要为一个lambda定义返回类型时。必须使用 尾置返回类型
    transform(vi.begin(), vi.end(), vi.begin(),
                [](int i) -> int { if(i<0) return -i; return i;});


    return 0;
}