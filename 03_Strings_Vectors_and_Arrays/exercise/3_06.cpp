#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main()
{
    // 练习3.6：编写程序，使用范围for语句将字符串内的所有字符用 X 代替
    string s1("hello world!");
    for(auto &c : s1){
        c = 'X';
    }
    cout << s1 << endl;

    // 练习3.8：分别用while和传统for循环重写练习3.6
    s1 = "some thing";
    for(string::size_type index=0; index!=s1.size(); ++index)
        s1[index] = 'X';

    cout << s1 << endl;

    s1 = "This is a string";
    string::size_type n = 0;
    while(n != s1.size()){
        s1[n] = 'X';
        ++n;
    }
    cout << s1 << endl;

    // 练习3.10：读入一个包含标点符号的字符串，将标点符号去除后输出字符串剩余的部分
    string s2, res;
    getline(cin, s2);   //getline将输入的一行读入到s2中，包括开头的空白。直到遇到第一个换行符
    for(auto c : s2){
        if(!ispunct(c))
            res += c;
    }
    cout << res << endl;

    return 0;
}