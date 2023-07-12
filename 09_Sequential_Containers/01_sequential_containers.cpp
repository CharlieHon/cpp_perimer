#include <vector>
#include <list>
#include <deque>
#include <iostream>
#include <string>

using namespace std;

/**
 * @brief 顺序容器概述
 * vector：可变大小数组。支持快速随机访问。在尾部之外的位置插入或删除元素可能很慢
 * deque：双端队列。支持快速随机访问。在头尾位置插入/删除速度很快
 * list：双向链表。只支持双向顺序访问。在list中任何位置进行插入/删除操作速度都很快
 * forward_list：单向链表。只支持单向顺序访问。在链表任何位置进行插入/删除操作都很快
 * array：固定大小数组。支持快速随机访问。不能添加或删除元素
 * string：与vector相似的容器，但专门用于字符。随机访问块。在尾部插入/删除速度快
 * 
 * - string和vector将元素保存在连续的内存空间，由元素的下标来计算其地址非常快速。
 * - list和forward_list设计目的是令容器任何位置的添加和删除操作都很快速。作为代价，不支持元素的随机访问
 * - deque支持快速的随机访问。
 */

int main()
{
    // 迭代器范围：由一堆迭代器表示，两个迭代器分别指向同一个容器中的元素或者是尾元素之后的位置
    vector<int> a = {0,1,2,3,4,5};
    vector<int>::iterator begin = a.begin(), end = a.end(); // 元素范围左闭右开[begin, end)
    while(begin != end){
        cout << *begin << endl;
        ++begin;
    }

    // 容器类型成员
    vector<int>::value_type val_type;  // value_type返回元素类型
    vector<int>::iterator iter; // 迭代器类型
    vector<int>::difference_type count; // 两个迭代器之间的距离
    vector<int>::reference ref = *begin; // 返回元素类型的引用
    vector<int>::const_reference const_ref = *end;  // 常量引用
    vector<int>::size_type size = a.size(); // size_t

    // begin和end成员
    list<string> b = {"Milton", "Shakespeare", "Austen"};
    auto it1 = b.begin();   // list<string>::iterator
    cout << *it1 << endl;   // Milton
    auto it2 = b.rbegin();  // list<string>::reverse_iterator
    cout << *it2 << endl;   // Austen
    auto it3 = b.cbegin();  // list<string>::const_iterator
    cout << *it3 << endl;   // Milton
    auto it4 = b.crbegin(); // list<string>::const_reference_iterator
    cout << *it4 << endl;   // Austen

    return 0;
}