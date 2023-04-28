#include <iostream>
#include <vector>
#include <string>

using std::cin; using std::cout; using std::endl;
using std::vector;
using std::string;

int main()
{
    // 练习4.17
    // 前置递增运算符：将运算对象+1，并返回+1后的对象本身
    // 后置递增运算符：将运算对象+1，返回+1前对象的副本

    // 练习4.18
    vector<int> vi{1,2,3,5,6,-2,9,0};
    auto beg = vi.begin();
    while(beg != vi.end() && *beg >= 0)
        // 后置递增运算符优先级高于解引用运算符，下式等价于 *(beg++)
        cout << *beg++ << endl; // 1 2 3 5 6
    // 如果使用前置递增运算符 *++beg 会漏掉第一个数，并且当数组中没有负数时会解引用不存在的数

    // 练习4.19
    int a = 1;
    int *ptr = &a;              // ptr时指向int的指针
    vector<int> vec(11, 21);    // vec是vector<int>
    int ival = 0;               // ival是int类型
    if(ptr != 0 && *ptr++){
        cout << "ptr不是空指针 并且 ptr所指内容非空 然后指针指向下一个元素" << endl;
    }
    if(ival++ && ival){
        cout << "ival不等于0或-1" << endl;
    }
    // <=运算符未定义求值顺序，下表达式有误
    // vec[ival++] <= vec[ial]
    if(vec[ival] <= vec[ival+1]){
        cout << "vec[0] <= vec[1]" << endl;
    }

    // 练习4.20
    vector<string> vs{"hello", "world", "beautiful", "life"};
    auto iter = vs.begin();
    
    // 输出 hello iter指向world
    cout << *iter++ << endl;    // 返回iter指向的内容，并将迭代器前进1位
    
    // cout << (*iter)++ << endl;  // 错误：先解引用得到的是个string类型对象，是不可变类型，不能后置递增
    
    // cout << *iter.empty() << endl;  // 错误：点运算符优先级高于解引用运算符，等价于 *(iter.empty()) 对一个bool类型解引用，错
    cout << (*iter).empty() << endl;    // 判断迭代器所指字符序列string是否为空
    // 输出 0 iter指向world

    cout << iter->empty() << endl;  // 等价于 (*iter).empty() 判断迭代器所指内容是否为空
    // 输出 0 iter指向world

    // cout << ++*iter << endl;    // 同 (*iter)++

    // 输出0 iter指向beautiful
    cout << iter++->empty() << endl;    // 判断迭代器当前所指内容是否为空，并将迭代器位置前进一位

    return 0;
}