#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main()
{
    //处理每个字符？使用基于范围的for语句
    string str("some string");
    // 使用auto关键字让编译器来决定变量c的类型，这里是char
    for(auto c : str){  // 每次迭代，str的下一个字符被 拷贝 给c
        cout << c << endl;
    }

    //统计string对象中标点符号的个数
    string s("Hello World!!!");
    // string::size_type n = 0;
    decltype(s.size()) n = 0;   // 效果同上
    for(auto c : s){
        if(ispunct(c))
            ++n;
    }
    cout << n << " punctuation characters in "
        << s << endl;

    //使用范围for语句改变字符串中的字符
    for(auto &c : s){
        c = toupper(c);
    }
    cout << s << endl;

    //使用下标运算符输出字符串的第一个字符
    if(!s.empty()){
        cout << s[0] << endl;
    }

    //使用下标执行迭代
    string s1("some thing");
    // 把s1的第一个词改为大写
    for(decltype(s1.size()) index = 0; index != s1.size() && !isspace(s1[index]);
        ++index)
        s1[index] = toupper(s1[index]);

    cout << s1 << endl;     // SOME thing

    //使用下标执行随机访问
    const string hexdigits = "0123456789ABCDEF";    // 可能的十六进制数字
    cout << "Enter a series of numbers between 0 and 15"
            << " separated by space. Hit ENTER when finished:"
            << endl;
    string result;
    string::size_type n1;
    while(cin >> n1){                                   // 12 0 5 15 8 15
        if(n1 < hexdigits.size()){      //无论何时用到字符串的下标，都应该注意检查其合法性
            result += hexdigits[n1];
        }
    }
    cout << "Your hex number is: " << result << endl;   // C05F8F

    return 0;
}