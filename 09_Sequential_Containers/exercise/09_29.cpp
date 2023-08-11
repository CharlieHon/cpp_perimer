#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <list>
#include <forward_list>

using namespace std;

int main()
{
    // 9.29
    vector<int> vec(25, 1);
    vec.resize(100);    // 添加75个值为0的元素
    vec.resize(10);     // 删除后90个元素

    // 9.30 接受单个参数的resize版本对元素类型有什么限制？
    // 元素类型必须提供一个默认构造函数

    // 9.31 对list和forward_list进行复制和删除操作
    list<int> ilist = {0,1,2,3,4,5,6,7,8,9};
    auto iter = ilist.begin();
    while(iter != ilist.end()){
        if(*iter % 2){
            iter = ilist.insert(iter, *iter);
            ++iter; // 复合赋值语句只能用于string, vector, deque, array
            ++iter;
        }else
            iter = ilist.erase(iter);
    }

    forward_list<int> flist = {0,1,2,3,4,5,6,7,8,9};
    auto prev = flist.before_begin(), curr = flist.begin();
    while(curr != flist.end()){
        if(*curr % 2){
            flist.insert_after(prev, *curr);
            prev = curr;
            ++curr;
        }else
            curr = flist.erase_after(prev); // erase_after返回被删元素之后的元素
    }

    // 9.32 下面语句是否合法
    // iter = vi.insert(iter, *iter++); // 不合法，因为参数的求值顺序是未指定的

    return 0;
}