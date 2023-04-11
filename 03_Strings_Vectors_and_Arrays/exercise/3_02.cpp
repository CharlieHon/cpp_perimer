#include <iostream>
#include <string>
using std::string;
using std::cin; using std::cout; using std::endl;

int main()
{
    // 练习3.2
    string line, word;
    while(getline(cin, line)){
        cout << line << endl;
    }

    while(cin >> word){
        cout << word << endl;
    }

    // 练习3.4
    string s1, s2;
    cin >> s1 >> s2;
    
    if(s1 == s2)
        cout << "s1 == s2" << endl;
    else{
        if(s1 > s2)
            cout << s1 << endl;
        else
            cout << s2 << endl;
    }

    if(s1.size() == s2.size()){
        cout << "s1.size() == s2.size()" << endl;
    }else{
        if(s1.size() > s2.size())
            cout << s1 << endl;
        else
            cout << s2 << endl;
    }

    // 练习3.5
    string s, res;
    while(cin >> s){
        // res += s;
        res = res + s + " ";
    }
    cout << res << endl;

    return 0;
}