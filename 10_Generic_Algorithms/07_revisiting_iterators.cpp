#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <deque>
#include <list>
#include <string>
#include <fstream>

using namespace std;

/**
 * @brief 10.4 再探迭代器
 * 除了为每个容器定义的迭代器外，标准库在头文件iterator中定义了额外几种迭代器
 * - 插入迭代器：绑定到一个容器上，可用来向容器插入元素
 * - 流迭代器：绑定到输入或输出流上，可用来遍历所关联的IO流
 * - 反向迭代器：向后而不是向前移动，除了forward_list之外的标准库容器都有反向迭代器
 * - 移动迭代器：专用的迭代器不是拷贝其中的元素，而是移动它们
 * 
 * iostream迭代器
 * istream_iterator读取输入流，ostream_iterator向一个输出流写数据
 * 
 * 反向迭代器
 * 反向迭代器就是容器中从尾元素向首元素反向移动的迭代器
 */

template<class T>
void print_vec(const vector<T> &vec){
    for(auto elem : vec){
        cout << elem << " ";
    }
    cout << endl;
}

int main()
{
    // 插入迭代器
    // 一种迭代器适配器，接受一个容器，生成一个迭代器，能实现向给定容器添加元素
    /*
    it = t      在it制定的当前位置插入值t
    *it,++it,,it++      不会对it做任何事情。每个操作都返回it
    */
    vector<int> v1{1,8,9,5,2,0,2,3}, v2;
    copy(v1.begin(), v1.end(), back_inserter(v2));
    print_vec(v2);  // 1 8 9 5 2 0 2 3

    list<int> lst1{1,9,4,9,2,0,0,1}, lst2, lst3;
    
    copy(lst1.cbegin(), lst1.cend(), front_inserter(lst2)); // 每个元素被插入到容器c中时，它变为c的新的首元素
    for_each(lst2.cbegin(), lst2.cend(), [](const int &x){cout << x << " ";});  // front_inserter生成的迭代器会将插入的元素序列的顺序颠倒过来
    cout << endl;   // 1 0 0 2 9 4 9 1
    
    // 当调用inserter(c, iter)时，得到一个迭代器，接下来使用它时，会将元素插入到iter原来所指的元素之前的位置
    /*
    *it = val;
    // 其效果与下面代码一样
    it = c.insert(it, val);
    ++it;   // 递增it使它指向原来的元素
    */
    copy(lst1.cbegin(), lst1.cend(), inserter(lst3, lst3.begin()));
    for_each(lst3.cbegin(), lst3.cend(), [](const int &x){cout << x << " ";});
    cout << endl;   // 1 9 4 9 2 0 0 1

    // iostream迭代器
    ifstream in("afile.txt");
    istream_iterator<string> str_it(in);    // 从"afile"读取字符串
    istream_iterator<string> str_eof;
    while(str_it != str_eof){
        cout << *str_it++ << " ";   // hello world
    }
    cout << endl;
    in.close();

    vector<int> v3;
    istream_iterator<int> in_iter(cin);  // 从标准输入读取数据
    istream_iterator<int> eof;  // eof定义为空，可以当作尾后迭代器来使用
    while(in_iter != eof){  // 对于一个绑定到流的迭代器，一旦其关联的流遇到文件尾或遇到IO错误，迭代器值就与尾后迭代器相等
        // 后置递增运算读取流，返回迭代器的旧值
        // 解引用迭代器，获得从流读取的前一个值
        v3.push_back(*in_iter++);
    }
    print_vec(v3);

    // 上述程序可以重写成如下形式
    // istream_iterator<int> in_iter2(cin), eof2;
    // vector<int> v4(in_iter2, eof);  // 从迭代器范围构造v3
    // print_vec(v4);

    // ostream_iterator操作
    // 必须将ostream_iterator绑定到一个指定的流，不允许空的或表示尾后位置的ostream_iterator
    ostream_iterator<int> out_iter(cout, " ");  // 可选的第二参数，是一个字符串，在输出每个元素后都会打印此字符串
    for(auto e : v3)
        // out_iter = e;    // 与下等价
        *out_iter++ = e;    // 赋值语句实际上将元素写到cout
    cout << endl;

    // 反向迭代器
    vector<int> v4 = {0,1,2,3,4,5,6,7,8,9};
    for(auto r_iter=v4.crbegin();
        r_iter!=v4.crend(); ++r_iter)
        cout << *r_iter << " ";
    cout << endl;   // 9 8 7 6 5 4 3 2 1 0

    sort(v4.rbegin(), v4.rend());   // 按逆序排序：将最小元素放在v4的末尾

    // 反向迭代器和其他迭代器间的关系
    string line = "FIRST,MIDDLE,LAST";
    // 查找第一个单词
    auto comma1 = find(line.cbegin(), line.cend(), ',');    // 查找line中第一个 ','
    cout << string(line.cbegin(), comma1) << endl;  // FIRST
    // 查找最后一个单词
    auto comma2 = find(line.crbegin(), line.crend(), ',');
    // cout << string(line.crbegin(), comma2) << endl; // 错误：TSAL
    
    // reverse_iterator的base成员函数将反向迭代器转换为普通迭代器
    cout << string(comma2.base(), line.cend()) << endl; // LAST
    


    return 0;
}