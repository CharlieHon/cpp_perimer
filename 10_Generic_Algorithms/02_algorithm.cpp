#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <string>
#include <list>
#include <iterator>
using namespace std;

/**
 * @brief 
 * - 只读算法
 * 一些算法指挥读取其输入范围内的元素，而不改变元素
 * - 写容器元素的算法
 * 一些算法将新值赋予序列中的元素，必须注意确保序列原大小至少不小于我们要求算法写入的元素的数目
 * 插入迭代器(insert iterator)是一种向容器中添加元素的迭代器。
 * - 拷贝算法
 */

int main()
{
    // accumulate定义在头文件numeric，前两个参数指出需要求和元素的范围，第三个参数是和的初值
    vector<int> v1{1,2,3,4,5,6,7,8,9,10};;
    int sum1 = accumulate(v1.cbegin(), v1.cend(), 0);
    cout << "Sum from 1 to 10 is " << sum1 << endl; // helloworldThanks

    // accumulate将第三个参数作为求和起点。这蕴含着一个假定：将元素类型加到和的类型上的操作必须是可行的
    vector<string> svec{"hello", "world", "Thanks"};
    string sum2 = accumulate(svec.cbegin(), svec.cend(), string(""));   // string定义了+运算符
    // string sum2 = accumulate(svec.cbegin(), svec.cend(), "");   // 错误：const char*没有定义+运算符
    cout << sum2 << endl;   // helloworldThanks

    // 操作两个序列的算法
    // equal：确定两个序列是否保存相同的值。接受三个迭代器，前两个表示第一个序列中的元素范围，第三个表示第二个序列的首元素
    // 它假定第二个序列至少于第一个序列一样长
    vector<int> v2{1,5,6,8,9,7,4,5,6,3,2};
    vector<int> v3{1,5,6,8,9,7,4,5,6,3,2};
    cout << (equal(v2.cbegin(), v2.cend(), v3.cbegin()) ? "Equal!" : "Not Equal!") << endl;

    // fill将给定值赋予输入序列中的每个元素
    vector<int> v4{1,2,3,4,5,6};
    fill(v4.begin(), v4.end(), 0);  // 0 0 0 0 0 0

    // fill_n: fill_n(dest, n, bal)
    // 接受一个单迭代器，一个计数器和一个值。它将给定值赋予迭代器指向的元素开始的指定个元素
    vector<int> v5(10); // 初始值10个0
    fill_n(v5.begin(), v5.size(), 6);   // 将所有元素重置为6

    // fill_n假定写入指定个元素是安全的，从dest开始的序列至少包含n个元素
    vector<int> vec;    // 空向量
    // fill_n(vec.begin(), 10, 0); // 灾难：修改vec中的10个不存在元素

    // back_inserter定义在头文件iterator中
    auto it = back_inserter(vec);   // 接受一个指向容器的引用，返回一个与该容器绑定的插入迭代器
    *it = 42;   // 通过此迭代器赋值，会调用push_back将一个具有给定值的新元素添加到容器
    
    // 常使用back_inserter来创建一个迭代器，作为算法的目的位置来使用
    vector<int> vec2;   // 空向量
    fill_n(back_inserter(vec), 10, 0);  // 添加10个元素到vec2

    // 拷贝(copy)
    int a1[] = {0,1,2,3,4,5,6,7,8,9};
    int a2[sizeof(a1)/sizeof(*a1)]; // a2与a1大小一样
    // ret指向拷贝到a2的尾元素之后的位置
    auto ret = copy(begin(a1), end(a1), a2);    // 把a1的内容拷贝给a2

    // replace: 读入一个序列，并将其中所有等于给定值的元素都改为另一个值
    list<int> lst1{42,5,6,2,4,1,41,9};
    replace(lst1.begin(), lst1.end(), 42, 0);   // 将所有值为0的元素改为42
    // 如果希望保留原序列不变，可以调用replace_copy
    vector<int> vec3;
    // replace_copy接受额外的第三个迭代器参数，指出调整后序列的保存位置
    replace_copy(lst1.begin(), lst1.end(), back_inserter(vec3), 42, 0);

    return 0;
}