#include <iostream>
#include <vector>
#include <string>
#include <cstring>

using std::cin; using std::cout; using std::endl;
using std::vector;
using std::string;

int main()
{
    // 逻辑运算符的优先级低于关系运算符
    string s("hello world");
    size_t index = 0;
    // 首先检查index是否到达string对象的末尾，然后再判断是否是空格
    // 等价于(index != s.size()) && (!isspace(s[index]))
    while(index != s.size() && !isspace(s[index])){
        s[index] = toupper(s[index]);
        ++index;
    }
    cout << s << endl;

    // 在遇到空字符或者以句号结束的字符串时进行换行，否则用空格隔开
    // vector<string> vs{10,"a"};  // 花括号{}可以转换成()，反之不可
    vector<string> vs{"hello","world","","I","love","China."};
    for(const auto &text : vs){
        cout << text;
        // 只有确保text非空才会用下标运算符去访问它
        if(text.empty() || text[text.size()-1]=='.')
            cout << endl;
        else
            cout << " ";
    }

    // 逻辑非运算符(!)
    // 将运算对象的值取反后返回
    vector<int> vi1;
    if(!vi1.empty())    cout << vi1[0] << endl;
    else    cout << "vi1 is empty!" << endl;

    // 关系运算符
    // 因为关系运算符的求值结果是布尔值，所以将几个关系运算符连写在一起回产生意想不到的结果
    int i = 1, j = 3, k = 2;
    // 等价于(i<j)<k，将i<j的结果true/false与k比较
    if(i < j < k)   cout << "if(i<j<k) is true" << endl;
    else    cout << "if(i<j<k) is false" << endl;

    // 正确逻辑关系
    if(i<j && j<k)  cout << "i<j<k" << endl;
    else    cout << "not i<j<k" << endl;

    // 相等性测试与布尔字面值
    int x = 1, *p = 0;
    if(x)   cout << "x是任意非0值" << endl;
    if(!p)  cout << "p是空指针" << endl;
    return 0;
}