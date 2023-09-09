#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <string>
#include <list>

using namespace std;

/**
 * @brief 10.5 泛型算法结构
 * 5类迭代器
 * 1.输入迭代器：只读，不写；单边扫描，智能递增
 * 2.输出迭代器：只写，不读；单边扫描，只能递增
 * 3.前向迭代器：可读写；多遍扫描，只能递增
 * 4.双向迭代器：可读写；多遍扫描，可递增递减
 * 5.随机访问迭代器：可读写，多遍扫描，支持全部迭代器运算
 * 
 * 算法形参模式
 * alg(beg, end, other args);
 * alg(beg, end, dest, other args);
 * alg(beg, end, beg2, other args);
 * alg(beg, end, beg2, end2, other args);
 */

void print_list(const list<int> &lst){
    for(int elem : lst){
        cout << elem << " ";
    }
    cout << endl;
}

int main()
{
    // 一些算法使用重载形式传递一个谓词
    vector<int> v1{0,1,1,1,2,5,5}, v2, v3;
    // unique(v1.begin(), v1.end());   // 使用 == 运算符比较元素
    // unique(v1.begin(), v1.end(), comp);  // 使用comp比较元素

    // _if版本的算法
    // 接受一个元素值的算法通常有另一个不同名的(非重载)版本，接受一个谓词代替元素值
    find(v1.cbegin(), v1.cend(), 0);    // 查找输入范围中 0 第一次出现的位置
    find_if(v1.cbegin(), v1.cend(), [](int x){return x>3;}); // 查找第一个 >3 的元素

    // 区分拷贝元素的版本和不拷贝的版本
    // 默认情况下，重排元素的算法将重排后的元素写回给定的输入序列中。
    // 写到额外目的空间的算法都在名字后面附加一个 _copy
    reverse(v1.begin(), v1.end());
    reverse_copy(v1.begin(), v1.end(), back_inserter(v2));

    remove_if(v1.begin(), v1.end(), [](int x){return x%2;});    // 从v1中删除奇数元素
    remove_copy_if(v1.begin(), v1.end(), back_inserter(v3),
                    [](int x){return x%2;});    // 将偶数元素从v1拷贝到v3；v1不变

    // 特定容器(list, forward_list)算法
    list<int> lst1{1,8,9,5}, lst2{1,9,4,9};
    lst1.sort();    // 链表排序
    lst2.sort();
    lst1.merge(lst2);   // 将来自lst2的元素合并入lst1.二者都必须是有序的
    print_list(lst1);   // 1 1 4 5 8 9 9 9

    lst1.remove(1); // 调用erase删除掉与给定值或令一元谓词为真的每个元素
    lst1.remove_if([](int x){return x%2;}); // 删除奇数元素
    print_list(lst1);   // 4 8

    // splice成员
    list<int> lst3{1,0,2,4,6,8,7}, lst4{4,7,6,4,1,0};
    lst3.splice(lst3.begin(), lst4);    // 将lst4的所有元素移动到lst3.begin()之前的位置
    print_list(lst3);   // 4 7 6 4 1 0 1 0 2 4 6 8 7
    print_list(lst4);   // lst4中元素都被删除

    list<int> lst5{3,6,7,5};
    lst3.splice(lst3.end(), lst5, lst5.begin());    // 将lst5中lst5.begin()位置的元素移动到lst3.end()之前
    print_list(lst5);   // 6 7 5
    print_list(lst3);   // 4 7 6 4 1 0 1 0 2 4 6 8 7 3


    return 0;
}