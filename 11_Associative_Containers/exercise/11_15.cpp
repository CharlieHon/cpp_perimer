#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <list>
#include <cctype>

using namespace std;

class Sales_data{
public:
    Sales_data() = default;
    Sales_data(const string &s) : bookNo(s) {}
    Sales_data(const string &s, int x, double price) : bookNo(s), units_sold(x), revenue(x*price) {}

    string isbn() const{
        return this->bookNo;
    }

private:
    string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

bool compareIsbn(const Sales_data &lhs, const Sales_data &rhs){
    return lhs.isbn() < rhs.isbn();
}

using compareType = bool (*) (const Sales_data&, const Sales_data&);    // 类型别名

int main()
{
    // 11.15
    map<int, vector<int>> m1;
    /*
    mapped_type: pair<int, vector<int>>
    key_type:   int
    value_type: vector<int>
    */

    // 11.16
    map<int, string> m2 = {{1, "hello"}};
    auto it2 = m2.begin();
    it2->second = "Hello";

    // 11.18
    map<string, size_t> m3;
    map<string, size_t>::iterator it3 = m3.begin();

    // 11.19
    multiset<Sales_data, decltype(compareIsbn)*> bookstore;
    multiset<Sales_data, compareType>::const_iterator it4 = bookstore.cbegin();

    // 11.20
    // string word1;
    // map<string, size_t> word_count1;
    // while(cin >> word1){
    //     auto ret = word_count1.insert({word1, 1});
    //     if(!ret.second)
    //         ++ret.first->second;
    // }

    // 11.21
    /*
    while(cin >> word)
        ++word_count.insert({word, 0}).first->second;   // 单词计数
    */

    // 11.22
    map<string, vector<int>> m4;
    m4.insert({"A", {1,8,9,5}});
    // 返回值类型 pair<map<string, vector<int>>::iterator, bool>

    // 11.23
    multimap<string, string> families;
    families.insert({"Han", "Bruce"});
    families.insert({"Han", "Charlie"});

    // 11.24 下面的程序完成什么功能？
    map<int, int> m5;   // 创建一个空map
    m5[0] = 1;  // 插入新元素，关键字为0，值默认初始化为0；再对m[0]幅值为1

    // 11.25
    vector<int> v1;
    // v1[0] = 1;  // 未定义行为，下标越界

    // 11.26
    map<string, size_t> m6;
    using ketType = map<string, size_t>::key_type;  // 下标类型
    using returnType = map<string, size_t>::mapped_type;    // 下标运算符返回类型

    // 11.27
    // 对于允许重复关键字的容器，应该用count；对于不允许重复关键字的容器，应该用find

    // 11.28
    // map<string, vector<int>>::iterator

    // 11.29 如果给定的关键字不在容器中
    // upper_bound返回第一个大于给定关键字或者尾后元素的迭代器
    // lower_bound返回值同上
    // equal_range返回一个pair，pair中的两个迭代器指向关键字可以插入的位置

    // 11.30
    // pos.first->second pos第一个迭代器指向元素的值

    // 11.31
    multimap<string, string> authors1 = {
        {"Han", "abc"},
        {"Han", "abc"},
        {"Zhao", "Alpha"}
    };
    string search_item("Han");
    auto pos = authors1.equal_range(search_item);
    if(pos.first == pos.second)
        cout << "Not Found!" << endl;
    else    authors1.erase(pos.first, pos.second);

    // 11.32
    multimap<string, string> authors2{
        {"wang", "cpp"},
        {"Han", "abc"},
        {"Han", "abc"},
        {"Zhao", "Alpha"},
        {"wang", "c#"}
    };
    map<string, multiset<string>> order_authors;
    for(const auto &author : authors2){
        order_authors[author.first].insert(author.second);
    }
    for(const auto &author : order_authors){
        cout << author.first << ": ";
        for(const auto &s : author.second){
            cout << s << " ";
        }
        cout << endl;
    }

    return 0;
}