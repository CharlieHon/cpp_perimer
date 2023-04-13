#include <iostream>
#include <string>
#include <vector>
#include <cctype>
using namespace std;

int main()
{
    // 利用迭代器把string对象的第一个字母改成大写
    string s("some thing");
    if(s.begin() != s.end()){   // 确保s非空，等价于 !s.empty()
        auto iter = s.begin();
        (*iter) = toupper(*iter);
    }

    // 把string对象中第一个单词改写成大写形式
    for(auto it=s.begin(); it!=s.end() && !isspace(*it); ++it)
        (*it) = toupper(*it);

    // 迭代器类型
    vector<int>::iterator it;   // it能读写vector<int>的元素
    string::iterator it2;       // it2能读写string对象中的字符

    vector<int>::const_iterator it3;    // it3只能读元素，不能写元素
    string::const_iterator it4;         // it4只能读字符，不能写字符

    // begin和end运算符
    vector<int> v;
    auto it5 = v.begin();   // it5的类型是vector<int>::iterator
    const vector<int> cv;
    auto it6 = cv.begin();  // it6的类型是vector<int>::const_iterator
    auto it7 = v.cbegin();  // it7的类型是vector<int>::const_iterator

    // 结合解引用和成员访问操作
    vector<string> a{"", "hello", "world"};
    for(auto it=a.begin(); it!=a.end(); ++it){
        // *it.empty();        // 错误：试图访问it的名为empty的成员，但it是个迭代器
        if((*it).empty())   // 解引用it，然后调用结果对象的empty成员
            cout << "空串" << endl;
        else
            cout << *it << endl;
    }

    // 箭头运算符
    auto it8 = a.begin();
    cout << "->: " << it8->empty()  // 1
            << "\n*: " << (*it8).empty() << endl;   // 1

    return 0;
}