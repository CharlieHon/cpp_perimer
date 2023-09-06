#include <iostream>
#include <vector>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

using std::placeholders::_1;
using namespace std;

string make_plural(size_t cnt, const string &word, const string &ending){
    return cnt > 1 ? word+ending : word;
}

bool check6(const string &s, size_t sz){
    return s.size() > sz;
}

// 10.24 给定一个string，使用bind和check_size在一个int的vector中查找第一个大于string长度的值
bool check_size(const int &x, const string &s){
    return x > s.size();
}

int main()
{
    // 10.20
    vector<string> svec{"the","quick","red","fox","jumps","over","the","slow","red","turtle"};
    auto count = count_if(svec.begin(), svec.end(), [](const string &s){return s.size()>5;});
    cout << count << " " << make_plural(count, "word", "s")
        << " of length " << 5 << " or longer" << endl;
    
    // 10.21
    int a = 7;
    auto f = [&] () -> bool {return (a==0) ? true : --a;};
    while(true){
        cout << "a: " << a << endl;
        cout << "f(): " << f() << endl;
        if(a == 0){
            cout << "a: " << a << endl;
            break;
        }
    }

    // 10.22
    auto b = count_if(svec.begin(), svec.end(), bind(check6, _1, 5));
    cout << "There are(is) " << b << " word(s) longer than 5." << endl; // 1

    // 10.23
    // 如果bind绑定的函数接受n的参数，则bind接受n+1个参数

    // 10.24
    string s = "hello";
    vector<int> vec{1,2,3,7,5,6};
    auto it = find_if(vec.begin(), vec.end(), bind(check_size, _1, s));
    if(it == vec.end()){
        cout << "None of vec is bigger than s.size!" << endl;
    }else{
        cout << *it << " is bigger than " << s.size() << endl;  // 7 is bigger than 5
    }

    return 0;
}