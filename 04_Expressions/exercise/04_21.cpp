#include <iostream>
#include <vector>
#include <string>

using std::cin; using std::cout; using std::endl;
using std::vector;
using std::string;

int main()
{
    // 练习4.21
    vector<int> vi1{1,9,4,9,2,0,2,3};
    for(auto &x : vi1){
        (x % 2) ? x*=2 : x; // 如果x是奇数，则值翻倍
    }
    for(const auto &x : vi1)
        cout << x << " ";   // 2 18 4 18 2 0 2 6
    cout << endl;

    // 练习4.22
    int score;
    cout << "Please Enter the Score:(EOF)" << endl;
    
    // - 只是用条件运算符
    while(cin >> score){
        cout << (score > 90 ? "high pass\n"
                    : score > 75 ? "pass\n"
                    : score >= 60 ? "low pass\n"
                    : "fail\n");
    }

    // - 使用if语句
    // while(cin >> score){
    //     if(score > 90)
    //         cout << "high pass" << endl;
    //     else if(score > 75)
    //         cout << "pass" << endl;
    //     else if(score >= 60)
    //         cout << "low pass" << endl;
    //     else
    //         cout << "fail" << endl;
    // }


    // 练习4.23
    string s = "word";
    // 如果字符串不以s结尾，则加上s
    string p1 = s + (s[s.size()-1] == 's' ? "" : "s");
    cout << p1 << endl;

    // 练习4.24
    // 如果条件运算符满足的是左结合律，求值过程是怎么样的？
    // 加括号？


    return 0;
}