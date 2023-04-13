#include <iostream>
#include <string>
#include <vector>
#include <cctype>
using namespace std;

int main()
{
    // 练习3.22：text是一个字符串向量存放文本文件中的数据，其中的元素或者是一句话或者
    // 是一个用于表示段落分隔的空字符串。利用迭代器写一个循环令其遍历text，直到遇到空字符串的元素为止。
    vector<string> text{"hello", "world", "my", "name", "is", "bruce", ""};
    for(auto it=text.begin(); it!=text.end() && !it->empty(); ++it)
        cout << *it << endl;
    
    // 改写上程序，首先把text的第一段全都改成大写形式，然后再输出它
    for(auto &word : text){
        if(!word.empty()){
            for(auto &c : word){
                c = toupper(c);
            }
            cout << word << endl;
        }
    }

    // 练习3.23：创建一个含有10个整数的vector对象，然后使用迭代器将所有元素的值
    // 都变成原来的两倍。
    vector<int> vi(10, 3);
    for(auto it=vi.begin(); it!=vi.end(); ++it)
        (*it) *= 2;

    for(auto x : vi)
        cout << x << endl;

    // 迭代器的算术运算
    vector<int> v(20, 1);
    // 计算得到最接近v中间元素的一个迭代器
    auto middle = v.begin() + v.size()/2;  // v.size()/2得10，已知下标从0开始，则迭代器所指的元素是v[10]
    /* 假设it和mid是同一个vector对象的两个迭代器，可以如下比较位置前后
    if(it < mid)
        // 处理 v 前半部分的元素
    */

    // 使用迭代器运算：二分搜索
    vector<int> a{1,2,3,5,9,10,15,19,20,26,30,34,40,42,48,49};
    auto beg = a.begin(), end = a.end();
    auto mid = beg + (end - beg)/2; // 初始状态下的中间点
    int target = 0;
    cout << "请输入查询数字(范围0~50):" << endl;
    cin >> target;
    while(mid != end && *mid != target){
        if(*mid > target)
            end = mid;
        else
            beg = mid + 1;
        mid = beg + (end-beg)/2;
    }

    if(mid == end)  cout << "NOT FIND!" << endl;
    else    cout << "GET: " << *mid << endl;

    return 0;
}