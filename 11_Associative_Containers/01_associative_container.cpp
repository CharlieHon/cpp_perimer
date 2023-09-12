#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <utility>

using namespace std;

/**
 * @brief 11. 关联容器
 * 两个主要的关联容器是map和set。
 * map中的元素是一些关键字-值(key-value)对；set支持高效的关键字查询操作——检查一个给定关键字是否在set中
 * map和multimap定义在头文件map中；set和multiset定义在头文件set中
 * 关联容器的迭代器都是双向的
 * 
 * 关键字类型的要求
 * 对于有序容器——map、multimap、set以及multiset，关键字类型必须定义元素比较方法
 * 可以提供自定义的操作来代替关键字上的<运算符，必须在关键字类型上定义严格弱序
 * 
 * pair类型
 * pair标准库类型，定义在头文件utility中
 * pair的默认构造函数对数据成员进行值初始化
 */

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

bool compareIsbn(const Sales_data &lhs, const Sales_data &rhs){
    return lhs.isbn() < rhs.isbn();
}

pair<string, int>
process(vector<string> &v){ // 返回一个pair
    if(!v.empty())    return {v.back(), v.size()};  // 列表初始化
    // return pair<string, int>(v.back(), v.size());   // 早期C++版本，不允许使用花括号包围的初始化器来返回pair对象，必须显式构造返回值
    else    return pair<string, int>(); // 隐式构造返回值
}

int main()
{
    // 使用map
    map<string, size_t> word_count; // string到size_t的空map
    string word;
    while(cin >> word)  // 统计每个单词出现的次数
        // 如果word还未在map中，下标运算符会创建一个新元素，其关键字为word，值为0
        ++word_count[word]; // 提取word的计数器并将其加1
    for(const auto &w : word_count) // 从map中提取一个元素时，会得到一个pair类型的对象
        cout << w.first << " occurs " << w.second   // pair是一个模板类型，保存两个名为first和second的(公有)数据成员
            << ((w.second>1) ? " times." : " time.") << endl;   // first保存关键字，second保存对应的值

    // 使用set
    map<string, size_t> word_count2;
    set<string> exclude = {"The", "But", "And", "Or", "An", "A",
                        "the", "but", "and", "or", "an", "a"};  // 忽略常见单词
    string word2;
    while(cin >> word2){
        if(exclude.find(word2) == exclude.end())    // 只统计不在exclude中的单词
            ++word_count2[word2];
    }

    // 定义关联容器
    map<string, size_t> m1; // 空容器
    set<string> s1 = {"hello", "thanks"};    // 列表初始化
    map<string, string> m2 = {{"Bruce", "Lee"}, // map初始化时，必须提供关键字类型和值类型
                                {"Leslie", "Zhang"},
                                {"Charlie", "Hon"}};
    
    // 初始化 multimap 或 multiset
    vector<int> ivec;
    for(vector<int>::size_type i=0; i<10; ++i){
        ivec.push_back(i);
        ivec.push_back(i);
    }
    set<int> iset(ivec.cbegin(), ivec.cend());
    multiset<int> miset(ivec.cbegin(), ivec.cend());
    cout << ivec.size() << endl;    // 20
    cout << iset.size() << endl;    // 10
    cout << miset.size() << endl;   // 20

    // 有序容器的关键字类型
    // bookstore中多条记录可以有相同的ISBN，以IBN的顺序进行排序
    multiset<Sales_data, decltype(compareIsbn)*> booksore(compareIsbn);

    // pair类型
    // 一个pair保存两个数据成员，pair是一个用来生成特定类型的模板。
    pair<string, string> anon;  // 保存两个string，初始化为空
    pair<string, size_t> word_count3;
    pair<string, vector<int>> line;

    pair<string, string> author = {"James", "Joyce"};
    // pair的数据成员是public的，两个成员分别命名为first和second
    cout << author.first << " " << author.second << endl;   // James Joyce

    return 0;
}