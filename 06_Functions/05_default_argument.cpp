#include <iostream>
#include <string>

using namespace std;
typedef string::size_type sz;

// 使用string对象表示窗口的内容，窗口的高、宽和背景字符都使用默认值
string screen(sz ht = 24, sz wd = 80, char backgrnd = ' '); // 一旦某个的形参被赋予了默认值，他后面的所有形参都必须是默认值
sz wd = 80;
char def = ' ';
sz ht();
string screen(sz = ht(), sz = wd, char = def);  // 局部变量不能作为默认值

// 用作默认实参的名字在函数声明所在的作用于内解析，而这些名字的求值过程发生在函数调用时
void f2(){
    def = '*';      // 改变默认实参的值
    sz wd = 100;    // 声明了一个局部变量隐藏外层的wd，但是该局部变量与传递给screen的默认实参没有任何关系
    string window = screen();   // 调用 screen(ht(), 80, '*')
}

// 练习6.42 给make_plural函数的第二个形参赋予默认值实参's'
string make_plural(const string &word, const string &ending = "s"){
    if(!word.empty())   return word + ending;
    return word;
}

int main()
{
    // 使用默认实参，只需在调用函数时省略该实参即可
    string window;
    window = screen();  // 等价于screen(24,80, ' ')
    window = screen(66);    // 等价于screen(66,80,' ')

    cout << make_plural("success", "es") << endl;
    cout << make_plural("apple") << endl;

    return 0;
}