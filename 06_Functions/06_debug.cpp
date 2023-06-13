#include <iostream>
#include <cassert>
#include <vector>
using namespace std;
using it = vector<int>::iterator;
const int threshold = 10;
/**
 * 程序可以包含一些用于调试的代码，在开发程序时使用。
 * 当应用程序编写完成准备发布时，要先屏蔽掉调试代码。
 * 这种方法用到两项预处理功能：assert和NDEBUG
 */

// assert预处理宏
// assert(expr);
// 首先对expr求值，如果表达式为假，assert输出信息并终止程序的执行。如果是真，什么也不做

// NDEBUG预处理变量

void print(const int ia[], size_t size){
    #ifndef NDEBUG
        // __func__ 是编译器定义的一个局部静态变量，用于存放函数的名字
        cerr << __func__ << ": array size is " << size << endl;
    #endif
}

// 练习6.47
void print_vector(it beg, it end){
    if(beg != end){
        cout << *beg++ << " vi.size: " << (end-beg+1) <<endl;
        print_vector(beg, end);
    }
}

int main()
{
    string word;
    cin >> word;
    if(word.size() < threshold)
        cerr << "Error: " << __FILE__           // 存放文件名的字符串字面值
            << " : in function " << __func__    // 存放函数的名字
            << " at line " << __LINE__ << endl  // 存放当前行号的整型字面值
            << "    Compiled on " << __DATE__   // 存放文件编译日期的字符串字面值
            << " at " << __TIME__ << endl       // 存放文件编译时间的字符串字面值
            << "    Word read was \"" << word
            << "\": Length too short" << endl;

    // 6.47
    vector<int> vi{2, 0, 2, 3, 0, 6, 1, 3};
    print_vector(vi.begin(), vi.end());

    // 6.47
    string s, sought = "K&R";
    while(cin >> s && s != sought)  {}  // 空函数体，死循环直到输入sought
    assert(cin);

    return 0;
}