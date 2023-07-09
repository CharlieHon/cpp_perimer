#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/**
 * @brief 文件模式
 * in：以读方式打开。只可以对ifstream或fstream对象设定in模式
 * out：以写方式打开。只可以对ofstream或fstream对象设定in模式
 * app：每次操作前均定位到文件末尾。只要trunc没被设定，就可以设定app模式。
 * ate：打开文件后立即定位到文件末尾
 * trunc：截断文件。只有当out也被设定时才可设定trunc模式。
 * binary：以二进制方式进行IO
 */

int main()
{
    // 以out模式打开文件会丢失已有数据
    ofstream out("file1");  // 隐含以输出模式打开文件并截断文件
    ofstream out2("file1", ofstream::out);  // 隐含地截断文件
    ofstream out3("file1", ofstream::out | ofstream::trunc);
    // 为了保留文件内容，我们必须显式指定app模式
    ofstream app("file2", ofstream::app);   // 隐含为输出模式
    ofstream app2("file2", ofstream::out | ofstream::app);

    // 每次调用open时都会确定文件模式
    ofstream out1;  // 未指定文件打开模式
    out1.open("scratchpad");    // 模式隐含设置为输出和截断。通常情况下，out模式意味着同时使用trunc模式
    out1.close();   // 关闭out，以便将其用于其他文件
    out1.open("precious", ofstream::app);   // 模式为输出和追加
    out1.close();

    return 0;
}