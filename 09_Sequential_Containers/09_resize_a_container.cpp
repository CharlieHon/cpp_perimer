#include <iostream>
#include <vector>
#include <string>
#include <list>

using namespace std;

/**
 * @brief 9.3.5 改变容器大小
 * resize不适用于array
 * c.resize(n)：调整c的大小为n个元素。若n<c.size()，则多出的元素被丢弃
 *              若必须添加新元素，对新元素进行值初始化
 * c.resize(n, t)：调整c的大小为n个元素。任何新添加的元素都被初始化为值t
 * 
 */

int main()
{
    list<int> ilist(10, 42);    // 10个int：每个的值都是42
    ilist.resize(15);   // 将5个值为0的元素添加到ilist的末尾
    ilist.resize(25, -1);   // 将10个值为-1的元素添加到ilist的末尾
    ilist.resize(5);    // 从ilist末尾删除20个元素


    return 0;
}