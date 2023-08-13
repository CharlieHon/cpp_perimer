#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 9.43：编写一个程序，接受三个string参数s、oldVal和newVal。
// 使用迭代器及insert和erase函数将s中所有oldVal替换为newVal。
void replace_with(string &s, const string &oldVal, const string &newVal){
    for(auto iter=s.begin(); iter<=s.end()-oldVal.size();){
        if(oldVal == string(iter, iter+oldVal.size())){
            iter = s.erase(iter, iter+oldVal.size());               // 返回第一个删除删除字符的迭代器
            iter = s.insert(iter, newVal.begin(), newVal.end());    // 返回第一个插入字符的迭代器
            iter += newVal.size();
        }else
            ++iter;
    }
}

// 9.44：重写上一题的函数，这次使用一个下标和replace
void replace_with2(string &s, const string &oldVal, const string &newVal){
    for(string::size_type i=0; i<=s.size()-oldVal.size();){
        if(oldVal == s.substr(i, oldVal.size())){
            s.replace(i, oldVal.size(), newVal);
            i += newVal.size();
        }else
            ++i;
    }
}

// 9.45：编写一个函数，接受一个表示名字的string参数和两个分别表示前缀和后缀的字符串
// 使用迭代器及insert和append函数将前缀和后缀添加到给定的名字中，将生成的心string返回。
string &add_string(string &s, const string &pre, const string &suf){
    // auto begin = s.begin();
    // s.insert(begin, pre.begin(), pre.end());
    // auto end = s.end();
    // s.append(suf);
    // return s;
    s.insert(s.begin(), pre.begin(), pre.end());
    return s.append(suf);
}

// 9.46：重写上题，这次使用位置和长度来管理string，并只使用insert
string &add_string2(string &s, const string &pre, const string &suf){
    s.insert(0, pre);
    s.insert(s.size(), suf);
    return s;
}

int main()
{
    // 9.41：编写程序，从一个vector<char>初始化一个string
    vector<char> vc{'h', 'e', 'l', 'l', 'o'};
    string s(vc.begin(), vc.end());

    // 9.43
    string s1{"To drive straight thru is a foolish, tho courageous act."}, s2(s1);
    replace_with(s1, "tho", "though");
    replace_with(s1, "thru", "through");
    cout << s1 << endl; // To drive straight through is a foolish, though courageous act.

    // 9.44
    replace_with2(s2, "tho", "though");
    replace_with2(s2, "thru", "through");
    cout << s2 << endl; // To drive straight through is a foolish, though courageous act.

    // 9.45
    string s3 = "Charlie";
    cout << add_string(s3, "Mr.", "III") << endl;   // Mr.CharlieIII

    // 9.46
    string s4 = "Bruce";
    cout << add_string2(s4, "Mr.", "Jr.") << endl;  // Mr.BruceJr.

    return 0;
}