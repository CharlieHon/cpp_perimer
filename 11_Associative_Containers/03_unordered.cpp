#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <utility>

using namespace std;

/**
 * @brief 11.4 无序容器
 * 新标准定义了4个无序关联容器，使用一个哈希函数(hash function)和关键字类型的==运算符组织元素
 * 
 * 管理桶
 * 无序容器在存储上组织为一组桶，每个桶保存零个或多个元素。
 * 无序容器使用一个哈希函数将元素映射到桶。为了访问一个元素，容器首先计算元素的哈希值，他指出应该搜索哪个桶
 * 容器将具有一个特定哈希值的所有元素都保存在相同的桶中
 * 
 * 无序容器对关键字类型的要求
 * 可以直接定义关键字是内置类型(包括指针类型)、string还是智能指针类型的无序容器
 * 不能直接定义关键字类型为自定义类类型的无序容器
 */

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

size_t hasher(const Sales_data &sd){
    return hash<string>()(sd.isbn());
}

bool eqOp(const Sales_data &lhs, const Sales_data &rhs){
    return lhs.isbn() == rhs.isbn();
}

int main()
{
    // 使用无序哦那个其
    unordered_map<string, size_t> word_count;
    string word;
    while(cin >> word)
        ++word_count[word];
    for(const auto &w : word_count)
        cout << w.first << " occurs "
            << (word_count[word]>1 ? "times." : "time.") << endl;

    // 无序容器对关键字的要求
    using SD_multiset = unordered_multiset<Sales_data, decltype(hasher)*, decltype(eqOp)*>;
    SD_multiset bookstore(42, hasher, eqOp);    // 参数是痛大小，哈希函数指针和相等性判断运算符指针

    // 如果类定义了==运算符，则可以直接重载哈希函数

    // 11.37
    // 无序版本通用性能更好，使用也更为简单
    // 有序版本的有序是维护了关键字的序

    return 0;
}