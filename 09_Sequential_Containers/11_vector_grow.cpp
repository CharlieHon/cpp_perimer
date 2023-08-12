#include <iostream>
#include <vector>
#include <string>

using namespace std;

/**
 * @brief 9.4 vector对象是如何增长的
 * 为了支持快速随机访问，vector将元素连续存储——每个元素紧挨着前一个元素存储
 * 向vector或string中添加元素：
 *      如果没有空间容纳新元素，容器必须分配新的内存空间来保存已有元素和新元素。
 *          将已有元素从旧位置移动到新空间中，然后添加新元素，释放旧存储空间
 * 管理容量的成员函数
 * shrink_to_fit只适用于vector、string和deque
 * capacity和reverse只适用于vector和string
 * - c.shrink_to_fit()    将capacity()减少为与size()相同大小
 * - c.capacity()         不重新分配内存空间的话，c可以保存多少元素
 * - c.reverse()          分配至少能容纳n个元素的内存空间
 */

int main()
{
    // 管理容量的成员函数
    vector<int> v1;
    cout << "v1.size(): " << v1.size()  // 0
            << " v1.capacity(): " << v1.capacity() << endl; // 0，一个空的vector的size为0，capacity也为0
    
    for(vector<int>::size_type ix=0; ix!=24; ++ix)
        v1.push_back(ix);   // 向v1添加24个元素
    
    cout << "v1.size(): " << v1.size()  // 24
        << " v1.capacity(): " << v1.capacity() << endl; // 32

    v1.reserve(50); // 将capacity至少设定为50，可能会更大
    cout << "v1.size(): " << v1.size()  // 24
        << " v1.capacity(): " << v1.capacity() << endl; // 50

    // 添加元素用光多余容量：只要没有操作需求超过vector的容量，vector就不能重新分配内存空间
    while(v1.size() != v1.capacity())
        v1.push_back(0);
    cout << "v1.size(): " << v1.size()  // 50
        << " v1.capacity(): " << v1.capacity() << endl; // 50，容量不变

    v1.push_back(6);
    cout << "v1.size(): " << v1.size()  // 51
        << " v1.capacity(): " << v1.capacity() << endl; // 100

    // 调用shrink_to_fit要求vector将超出当前大小的多余内存退回给系统(只有一个请求，不一定有效)
    v1.shrink_to_fit();
    cout << "v1.size(): " << v1.size()  // 51
        << " v1.capacity(): " << v1.capacity() << endl; // 51

    return 0;
}