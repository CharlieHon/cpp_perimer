#include <iostream>
#include <forward_list>

using namespace std;

/**
 * @brief 特殊的forward_list操作
 * forward_list是单向链表，无法获取一个元素的前驱，添加或删除元素的操作是通过改变给定元素之后的元素来完成的。
 * 为了删除elem3，应该指向elem2的迭代器调用erase_after。
 * lst.before_begin()：返回指向链表首元素之前不存在元素的迭代器
 * lst.cbefore_begin()
 * 
 * lst.insert_after(p, t)：在迭代器p之后的位置插入元素。t是一个对象，n是数量
 * lst.insert_after(p, n, t)
 * lst.insert_after(p, b, e)：b和e是表示范围的一对迭代器(不能指向lst内)
 * lst.insert_after(p, i1)：i1是一个花括号列表。返回指向最后一个插入元素的迭代器
 * 
 * emplace_after(p, args)：
 * 
 * lst.erase_after(p)：删除p指向的位置之后的元素，或删除从b之后直到(但不包含)e之间的元素
 * lst.erase_after(b, e)    返回一个指向被删元素之后元素的迭代器
 */

int main()
{
    // forward_list添加或删除元素时，必须关注两个迭代器——一个指向要处理的元素，另一个指向其前驱
    forward_list<int> flst = {9,6,6,3,6,8,7};
    auto prev = flst.before_begin(), curr = flst.begin();   // prev表示“首前元素”；curr表示第一个元素
    while(curr != flst.end()){  // 删除flst中的奇数元素
        if(*curr % 2)
            curr = flst.erase_after(prev);  // 找到奇数元素，将prev之后的元素删除，即，删除curr所指向的元素；然后将curr重置为erase_after的返回值
            // 此时，prev保持不变，仍指向(新)curr之前的元素
        else{
            prev = curr;    // 两个迭代器都向前移动
            ++curr;
        }
    }

    for(auto elem : flst)
        cout << elem << endl;

    return 0;
}