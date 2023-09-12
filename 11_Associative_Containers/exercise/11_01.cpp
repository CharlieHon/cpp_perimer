#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <list>
#include <unordered_map>
#include <unordered_set>
#include <cctype>
#include <utility>

using namespace std;

// 11.4 扩展单词计数程序，忽略大小写和标点。例如，"example", "example,"和"Example"应该递增相同的计数器
bool is_punct(char c){  // 判断单词是否是标点符号
    return ispunct(c)!=0;
}
void word_count_pro(map<string, size_t> &m){
    string word;
    while(cin >> word){
        for(auto &c : word)
            c = tolower(c); // 转为小写
        word.erase(find_if(word.begin(), word.end(), is_punct),
                word.end());    // 去除标点符号，并删除标点以后的所有字符
        ++m[word];
    }
    for(const auto &w : m){
        cout << w.first << " " << w.second << endl;
    }
}

// 11.11 不适用 decltype 重新定义 bookstore
class Sales_data{
public:
    Sales_data() = default;
    Sales_data(const string &s) : bookNo(s) {}
    string isbn() const{
        return this->bookNo;
    }
private:
    string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

using Less = bool (*) (const Sales_data&, const Sales_data&);   // 函数指针

class Families{
public:
    using Child = pair<string, string>; // {"first_name", "birthday"} (名, 生日)
    using Children = vector<Child>;
    using Data = map<string, Children>; // last_name -> Children (姓, 家庭)

    void add(const string &last_name, const string &first_name, const string &birthday){
        auto child = make_pair(first_name, birthday);
        _data[last_name].push_back(child);
    }

    void print() const{
        for(const auto &pair : _data){
            cout << pair.first << ":\n";
            for(const auto &child : pair.second)
                cout << child.first << " " << child.second << endl;
            cout << endl;
        }
    }

private:
    Data _data;
};

int main()
{
    // 11.1 map和vector的不同
    // map是关联容器，vector是顺序容器

    // 11.2
    // list：双向链表，适合频繁插入、删除元素的场景
    // vector：适合频繁访问元素的场景
    // deque：双端队列，适合频繁在头尾插入删除元素的场景
    // map：字典
    // set：适合有序不重复的元素的场景

    // 11.3 编写你自己的单词计数器
    // map<string, size_t> word_count;
    // string word;
    // while(cin >> word)
    //     ++word_count[word];
    // for(const auto &w : word_count){
    //     cout << w.first << " occurs " << w.second
    //         << ((w.second > 1) ? " times." : " time.") << endl;
    // }

    // 11.4 
    map<string, size_t> word_cout;
    word_count_pro(word_cout);

    // 11.5 map和set的区别
    // map是键值对；set只有键没有值

    // 11.6 set和list的区别
    // set是有序不重复集合，底层实现是红黑树，而list是无序可重复集合，底层实现是链表

    // 11.7
    map<string, vector<string>> family; // 姓到名的映射
    string fName, lName;
    family["Hon"] = {"Charlie", "Rachel"};
    family["Hon"].push_back("Tom"); // 向已有家庭添加新成员
    family["Lee"] = {"Bruce", "Dragon"};
    for(const auto &w : family){
        cout << w.first << ":" << endl;
        for(const auto &s : w.second){
            cout << s << " ";
        }
        cout << endl;
    }

    // 11.8
    vector<string> svec = {"aa", "aa", "cc", "bb", "cc", "Hg"};
    sort(svec.begin(), svec.end());
    unique(svec.begin(), svec.end());
    for_each(svec.cbegin(), find(svec.cbegin(), svec.cend(), ""), [](const string &s){cout << s << " ";});
    cout << endl;   // Hg aa bb cc

    // 11.9 定义一个map，将单词与一个行号的list关联，list中保存的是单词所出现的行号
    map<string, list<size_t>> m1;

    // 11.10
    // 可以定义一个 vector<int>::iterator 到 int 的 map
    // 不可以 list<int>::iterator 到 int 的 map
    // 因为 map 的键必须实现 < 操作，list的迭代器不支持比较操作

    // 11.11
    multimap<Sales_data, Less> bookstore(Less);

    // 11.12
    vector<pair<string, int>> v1;
    string s;
    int x;
    while(cin >> s >> x){
        v1.push_back(make_pair(s, x));  // 更容易理解
        v1.push_back({s, x});
        v1.push_back(pair<string, int>(s, x));
    }

    // 11.14
    Families families;
    auto msg = "Please enter last name, first name and birthday:\n";
    for(string l, f, b; cout << msg, cin >> l >> f >> b; families.add(l, f, b));
    families.print();

    return 0;
}