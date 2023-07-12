#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <list>
#include <forward_list>
#include <array>

using namespace std;

using index = vector<int>::iterator;

// 9.4
bool find1(index begin, index end, int x){
    if(begin > end) return find1(end, begin, x);
    while(begin != end){
        if(*begin == x) return true;
        ++begin;
    }
    return false;
}

// 9.5：返回迭代器指向找到的元素
index find2(index begin, index end, int x){
    if(begin > end) return find2(end, begin, x);
    while (begin != end){
        if(*begin == x) return begin;
        ++begin;
    }
    return end;
}

int main()
{
    // 9.2：定义一个list对象，其元素类型是int的deque
    deque<int> a;

    // 9.3：构成迭代器范围的迭代器有何限制
    /*
     * 如果满足以下条件，两个迭代器begin和end构成一个迭代器范围：
     * - 指向同一个容器中的元素，或者是容器最后一个元素之后的位置，且
     * - 可以通过反复递增begin来达到end，即end不在begin之前
     */

    vector<int> b = {4,7,6,4,1,8,9};
    index beg1 = b.begin(), end1 = b.end();
    int x = 5;
    if(find1(end1, beg1, x))    cout << "find: " << x << endl;
    else    cout << "Not find!" << endl;

    // 9.7：索引int的vector中的元素
    vector<int>::size_type c;
    // 9.8：读取和写入string的list中的元素
    list<string>::const_iterator d; // 读
    list<string>::iterator e;   // 写

    // 9.11：对6中创建和初始化vector对象的方法，每一种都给出一个实例
    vector<int> v1;
    vector<int> v2(5);
    vector<int> v3(5, -1);
    vector<int> v4{0,1,2,3,4,5};
    vector<int> v5 = {6,7,8,9};
    vector<int> v6(v5); // v6和v5的容器类型和元素类型必须相同
    vector<int> v7(v6.begin(), v6.end());   // v7的元素类型必须和v6的元素类型相容

    // 9.13：从一个list<int>初始化一个vector<double>？(从一个vector<int>？)
    list<int> f{0,1,2,3,5};
    vector<double> g(f.begin(), f.end());
    vector<double> h(v4.begin(), v4.end());

    // 9.14：将一个list中的char*指针元素赋值给一个vector中的string
    list<char *> i = {"Hi", "Lee"};
    vector<string> j;
    j.assign(i.begin(), i.end());


    return 0;
}