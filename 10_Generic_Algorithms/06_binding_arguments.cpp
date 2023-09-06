#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>

using namespace std;
using namespace std::placeholders;

/**
 * @brief 10.3.4 参数绑定
 * bind定义在头文件 functional 中，
 * 可以看作一个通用函数适配器，接受一个可调用对象，生成一个新的可调用对象来适应原对象的参数列表
 * auto newCallable = bind(callable, arg_list)
 * 
 */

bool check_size(const string &s, size_t sz){
    return s.size() > sz;
}

bool isShorter(const string &s1, const string &s2){
    return s1.size() < s2.size();
}

ostream& print(ostream &os, const string &s, char c = ' '){
    return os << s << c;
}

int main()
{
    // 绑定check_size的sz参数
    auto check6 = bind(check_size, _1, 6);  // check6是一个可调用对象，接受一个string类型参数，check6(s) -> check_size(s, 6)
    // 此bind调用只有一个占位符，表示check6只接受单一参数
    // 占位符出现在arg_list的第一个位置，表示check6的此参数对应check_size的第一个参数

    string s = "hello";
    bool b1 = check6(s);    // check6(s)会调用check_size(s, 6)

    vector<string> wc{"Bruce", "Charlie", "John", "Rachel"};
    auto ws = find_if(wc.begin(), wc.end(), check6);
    // auto wc = find_if(wc.begin(), wc.end(), [sz](const string &s){return s.size()>sz;});

    // 使用placeholders名字
    /*
    名字 _n 都定义在一个名为 placeholders 的命名空间中，而这个命名空间本身定义在std命名空间中
    using std::placeholders::_1
    对每个占位符名字，都必须提供一个单独的 using 声明
    使用另一种不同形式的using语句，可以不用分别声明每个占位符
    using namespace std::placeholders
    */

    // bind的参数
    // auto g = bind(f, a, b, _2, c, _1);   // 假设f是一个可调用对象
    /*
    - 生成一个新的可调用对象g，它有两个参数，分别用占位符_2和_1表示。
    - g将它自己的参数作为第三个和第五个参数传递给f。f的第一个、第二个和第四个参数分别被绑定到给定的值a、b和c上
    - 传递给g的参数按位置绑定到占位符。即，第一个参数绑定到_1，第二个参数绑定到_2
    - 因此，当调用g时，其第一个参数将被传递给f作为最后一个参数，第二个参数将被传递给f作为第三个参数。
    g(_1, _2) -> f(a, b, _2, c, _1)
    */

    // 用bind重排参数顺序
    sort(wc.begin(), wc.end(), isShorter);  // 按单词长度由短至长排序
    sort(wc.begin(), wc.end(), bind(isShorter, _2, _1));    // 由长至短排序

    // 绑定引用参数
    // 默认情况下，bind的那些不是占位符的参数被拷贝到bind返回的可调用对象中
    ostream &os = cout;
    char c = ' ';
    for_each(wc.begin(), wc.end(), [&os, c](const string &s){os << s << c;});
    cout << endl;
    // 不能直接用bind来代替os的捕获
    // for_each(wc.begin(), wc.end(), bind(print, os, _1, c));  // 错误：不能拷贝os

    for_each(wc.begin(), wc.end(), bind(print, ref(os), _1, ' '));  // 使用标准库ref函数，传递给bind一个对象的引用
    cout << endl;

    return 0;
}