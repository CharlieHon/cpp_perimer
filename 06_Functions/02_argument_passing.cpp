#include <iostream>
#include <string>
using namespace std;

void reset(int &i){ // i是传给reset函数的对象的另一个名字
    i = 0;  // 改变了i所引用对象的值
}

// 使用引用避免拷贝
bool isShorter(const string &s1, const string &s2){
    // 比较长度无须改变string对象的内容，所以把形参定义成对常量的引用
    return s1.size() < s2.size();
}

// 返回string对象中某个制定字符第一次出现的位置，同时返回该字符出现的总次数
string::size_type find_char(const string &s, char c,
                            string::size_type &occurs){
    auto ret = s.size();
    occurs = 0; // 置0，如果s中不存在字符c，则occurs所引用对象值为0
    for(decltype(ret) i=0; i!=s.size(); ++i){
        if(s[i]==c){
            // 相等表示，字符c在字符串s中第一次出现
            if(ret==s.size())   ret = i;
            ++occurs;
        }
    }
    return ret;
}

int main()
{
    string s("hello, world!");
    char w;
    cout << "Please enter a char:" << endl;
    cin >> w;
    string::size_type ctr = -1;
    auto index = find_char(s, w, ctr);
    if(index!=0)  cout << "The index of " << index << " is " << w << endl;
    else    cout << "Not found!" << endl;

    return 0;
}