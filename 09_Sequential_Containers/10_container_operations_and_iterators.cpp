#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <forward_list>
#include <deque>

using namespace std;

/**
 * @brief 9.3.6 容器操作可能使迭代器失效
 * 向容器中添加元素和从容器中删除元素的操作可能会使指向容器的元素的指针、引用或迭代器失效。
 * 对于list和forward_list：向容器添加或删除元素，迭代器、引用和指针仍有效
 * 对于vector或string：向容器添加元素且存储看见被重新分配，则全部失效；未重新分配，则指向插入之前的有效
 *                  删除元素则，被删元素之前的有效；尾后迭代器总会失效
 * 对于deque：插入到除首尾位置之外的任何位置都失效；插入在首尾，仅迭代器失效。删除同理
 */

int main()
{
    // 编写改变容器的循环程序
    vector<int> vi = {0,1,2,3,4,5,6,7,8,9}; // 删除偶数元素。复制每个奇数元素
    auto iter = vi.begin();
    while(iter != vi.end()){
        if(*iter % 2){
            iter = vi.insert(iter, *iter);
            iter += 2;  // 向前移动迭代器，跳过当前元素以及插入到它之前的元素
        }
        else
            iter = vi.erase(iter);  // iter指向删除的元素之后的元素
    }

    // 不要保存end返回的迭代器
    vector<int> v = {1,4,5,7,9,6,8,2,3};    // 向每个元素后插入42
    auto begin = v.begin();
    while(begin != v.end()){    // 不能提前保存v.end()，因为会失效
        ++begin;
        begin = v.insert(begin, 42);
        ++begin;
    }

    return 0;
}