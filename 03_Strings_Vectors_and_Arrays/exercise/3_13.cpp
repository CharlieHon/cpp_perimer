#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    // 练习3.13
    vector<int> v1; // v1为空
    vector<int> v2(10); // v2为10个0
    vector<int> v3(10, 42); // v3为10个42
    vector<int> v4{10}; // v4为1个10
    vector<int> v5{10, 42}; // v5包含10和42
    vector<string> v6{10};  // v6为10个空串
    vector<string> v7{10, "hi"};    // v7为10个空串

    // 练习3.14：编写程序，用cin读入一组整数并把它们存入一个 vector 对象
    int a;
    vector<int> ivec;
    while(cin >> a){
        ivec.push_back(a);
    }

    // 练习3.15：读入的是字符串，其他要求同上
    string word;
    vector<string> svec;
    while(cin >> word){
        svec.push_back(word);
    }

    return 0;
}