#include <iostream>
#include <list>
#include <vector>
#include <string>

using namespace std;

/**
 * @brief 9.3.1 向顺序容器添加元素
 * 除array外，所有标准库容器都提供灵活的内存管理。vector和string不支持push_front和emplace_front
 * c.push_back(t)   c.emplace_back(args)：在c的尾部创建一个值为t或由args创建的元素。返回void
 * c.push_front(t)  c.emplace_front(args)
 * c.insert(p, t)   c.emplace(p, args)：在迭代器p指向的元素之前创建一个值为t或由args创建的元素。返回指向新添加的元素的迭代器
 * c.insert(p, n, t)：在迭代器p指向的元素之前插入n个值为t的元素。返回指向新添加的第一个元素的迭代器；若n为0，则返回p
 * c.insert(p, b, e)：将迭代器b和e指定的范围内的元素插入到迭代器p指向的元素之前。
 * c.insert(p, i1)：i1是一个花括号包围的元素值列表。
 * 
 */

void pluralize(size_t cnt, string &word){   // 由于string是一个字符容器，也可以用push_back在string末尾添加字符
    if(cnt > 1)
        word.push_back('s');    // 等价于 word += 's';
}

class Sales_data{
public:
    Sales_data() = default;
    Sales_data(const string &s, int c, double price) : bookNo(s), cnt(c), revenue(c*price)  {}
    Sales_data(const string &s) : bookNo(s) {}
private:
    string bookNo;
    int cnt;
    double revenue;
};

int main()
{
    // 使用push_back
    string word;
    vector<string> container;
    while(cin >> word)
        container.push_back(word);  // 从标准输入读取数据，将每个单词放到容器末尾

    // 使用push_front
    list<int> ilist;
    for(size_t ix=0; ix!=4; ++ix)
        ilist.push_front(ix);   // 3 2 1 0

    // 在容器中的特定位置添加元素
    list<int> l = {2, 6};
    auto iter = l.begin();
    l.insert(iter, 3); // 将2添加到iter之前的位置

    vector<int> v1;
    list<int> l1;
    // l1.push_front(6);
    l1.insert(l1.begin(), 6);   // 与上等价
    v1.insert(v1.begin(), 6);   // vector不支持push_front，但可以插入到begin()之前

    // 插入范围内元素
    vector<int> v2;
    v2.insert(v2.end(), 6, 6);  // 将指定数量的元素添加到指定位置之前

    vector<int> v = {1,2,3,4,5,6};
    v2.insert(v2.begin(), v.end()-2, v.end());  // 将v的最后两个元素添加到v2的开始位置
    v2.insert(v2.begin(), {1,2,3,1,5}); // 将列表中的元素添加到v2的开始位置
    // v2.insert(v2.begin(), v2.begin(), v2.end());    // 运行时错误：迭代器表示要拷贝的范围，不能指向与目的位置相同的容器

    // 使用insert的返回值
    list<string> lst;
    auto i1 = lst.begin();
    while(cin >> word)  // 通过使用insert的返回值，可以在容器中一个特定位置反复插入元素
        i1 = lst.insert(i1, word);

    // 使用emplace操作
    // emplace将参数传递给元素类型的构造函数。emplace成员使用这些参数在容器管理的内存空间中直接构造元素
    list<Sales_data> c;
    c.emplace_back("978-0590353403", 25, 15.99);    // 使用三个参数的Sales_data构造函数
    // c.push_back("978-0590353403", 25, 15.99);    // 错误：没有接受三个参数的push_back版本
    c.push_back(Sales_data("666-12315"));    // 正确：创建一个临时的Sales_data对象传递给push_back
    c.emplace_back();   // 使用Sales_data的默认构造函数

    return 0;
}