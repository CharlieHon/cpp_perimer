#include <iostream>
#include <vector>
#include <string>
#include <deque>
#include <list>
#include <array>

using namespace std;

/**
 * @brief 删除元素
 * 顺序容器的删除操作会改变容器的大小，所以不适用于array
 * forward_list有特殊版本的erase，不支持pop_back; vector和string不支持pop_front
 * c.pop_back()：删除c中尾元素。若c为空，则函数行为未定义。函数返回void
 * c.pop_front()：删除c中首元素。若c为空，则函数行为未定义。函数返回void
 * c.erase(p)：删除迭代器p所指定的元素，返回一个指向被删除元素之后元素的迭代器，若p指向尾元素，则返回尾后迭代器。
 *  若p是尾后迭代器，则函数行为未定义。
 * c.erase(b, e)：删除迭代器b和e所指定范围内的元素。返回一个指向最后一个被删除元素之后的迭代器。
 *  若e本身是尾后迭代器，则函数也返回尾后迭代器
 * c.clear()：删除c中的所有元素。返回void
 * 
 * - 删除deque中除首尾位置之外的任何元素都会使所有迭代器、引用和指针失效
 * - 指向vector和string中删除点之后位置的迭代器、指针和引用都会失效
 */

int main()
{
    // pop_front和pop_back成员函数
    list<int> ilist = {2,0,2,3};
    while(!ilist.empty()){  // 这些操作返回void。如果需要弹出的元素的值，需要提前处理
        // process(ilist.front());  // 对ilist的首元素进行一些处理
        ilist.pop_front();  // 完成处理后删除首元素
    }

    // 从容器内部删除一个元素：erase从容器中指定位置删除元素，返回指向删除的元素之后位置的迭代器
    list<int> lst = {0,1,2,3,4,5,6,7,8,9};
    auto it = lst.begin();
    while(it != lst.end()){ // 删除一个list中所有奇数元素
        if(*it % 2)
            it = lst.erase(it);
        else
            ++it;
    }

    // 删除多个元素
    list<string> slist = {"abandon", "back", "cover", "deque"};
    // elem1 = slist.erase(elem1, elem2);   // 删除两个迭代器表示的范围内的元素，返回指向最后一个被删元素之后位置的迭代器
    slist.erase(slist.begin(), slist.end());    // 删除容器中的所有元素
    slist.clear();  // 等价调用

    return 0;
}