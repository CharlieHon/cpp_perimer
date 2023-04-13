#include <iostream>
#include <vector>
#include <string>
#include <cctype>
using namespace std;

int main()
{
    // 练习3.17：从cin读入一组词并把它们存入一个vector对象，然后设法把所有词
    // 改写成大写形式。输出改变后的结果，每个词占一行
    string word;
    vector<string> svec;
    while(cin >> word){
        svec.push_back(word);
    }

    for(auto &w : svec){    // 每个词
        for(auto &c : w){   // 词的每个单词
            c = toupper(c);
        }
    }

    for(decltype(svec.size()) ix=0; ix!=svec.size(); ++ix)
        cout << svec[ix] << endl;

    // 练习3.19：定义一个含有10个元素的vector对象，所有元素的值都是42，列举三种不同的实现方法
    vector<int> v1(10, 42);     // 这个更好，因为初始值全相同，使用()构造更简洁
    vector<int> v2{42,42,42,42,42,42,42,42,42,42};
    // vector<int> v3 = v1;
    vector<int> v3;
    for(int i=0; i<10; ++i)
        v3.push_back(42);

    // 练习3.20：将每对相邻整数的和输出出来
    int x;
    vector<int> vi;
    while(cin >> x){
        vi.push_back(x);
    }
    for(decltype(vi.size()) ix=0; ix!=vi.size()-1; ++ix){
        cout << vi[ix]+vi[ix+1] << endl;
    }

    // 先输出第1个和倒数第1个元素的和，接着输出第2个和倒数第2个元素的和，一次类推
    auto len = vi.size();
    cout << "the size of vi is: " << len << endl;
    for(decltype(vi.size()) i=0,j=len-1; i<j; ++i,--j){
        cout << vi[i] + vi[j] << endl;
    }

    return 0;
}