#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

// 重排容器元素的算法

// 消除重复单词
void elimDups(vector<string> &words){
    // 按字典序排序words，以便查找重复单词
    sort(words.begin(), words.end()); // 利用元素类型的<运算符来实现排序
    // unique重排输入序列，将相邻的重复项“消除”，并返回一个指向不重复范围末尾的迭代器
    auto end_unique = unique(words.begin(), words.end());   // unique覆盖相邻的重复元素，使得不重复元素出现在序列的开始部分
    // 使用容器操作erase删除重复单词
    words.erase(end_unique, words.end());
}

// 输出序列
void printVec(const vector<string> &svec){
    for(const auto &word : svec){
        cout << word << " ";
    }
    cout << endl;
}

int main()
{
    // 消除重复单词
    vector<string> svec{"the","quick","red","fox","jumps","over","the","slow","red","turtle"};
    elimDups(svec);
    printVec(svec); // fox jumps over quick red slow the turtle

    return 0;
}