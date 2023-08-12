#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    // 9.35
    // size的值指容器已经保存的元素的数量
    // capacity的值表明，在不重新分配内存空间的情况下，容器可以保存多少元素

    // 9.36
    // 一个容器的capacity大于等于它的size

    // 9.37 为什么list或array没有capacity成员函数
    // 因为list是链表，而array不允许改变容器大小

    // 9.38 编写程序，探究在你的标准库实现中，vector是如何增长的
    vector<int> vi;
    for(vector<int>::size_type ix=0; ix<100; ++ix){
        cout << "vi.size(): " << vi.size()
                << " vi.capacity(): " << vi.capacity() << endl;
        vi.push_back(ix);
    }

    // 9.39
    vector<string> svec;
    svec.reserve(1024); // 为sevc分配1024个元素的空间
    string word;
    while(cin >> word)  // 从标准输入中读入字符串，添加到svec末尾
        svec.push_back(word);
    svec.resize(svec.size() + svec.size()/2);   // 改变容器元素个数为原来的1.5倍。如果超出容器容量，将会重新分配空间

    // 9.40 如果上一题读入了 256 512 1000 或 1048个词结果如何？
    // 256、512时，容量仍为1024
    // 1000、1048，容量取决于具体实现

    return 0;
}