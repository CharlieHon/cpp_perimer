#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/**
 * @brief 文件输入输出
 * 头文件fstream定义了三个类型来支持文件IO：
 * 1. ifstream从一个给定文件读取数据
 * 2. ofstream向一个给定文件写入数据
 * 3. fstream可以读写给定文件
 */

void read_file(ofstream &of){
    
}

int main()
{
    // 1.向文件中写入内容
    ofstream of1("test.txt");   // 输出流，创建新文件
    of1 << "hello file!";
    of1.close();    // 关闭与of1绑定的文件。返回void

    // 2.从文件中读取内容
    string file("a.txt");
    // 在创建文件时绑定
    // ifstream if1(file); // 老版本使用C风格字符串，file.c_str()，C++11可以使用string
    
    ifstream if1;   // 创建一个未绑定的文件流
    if1.open(file); // 打开名为file的文件，并将文件与if1绑定

    // if(if1)  // 打开文件成功
    if(!if1){
        cerr << "error: unable to open input file:" 
            << file << endl;
        return -1;
    }

    string s;
    while(if1 >> s) // 读取文件，if1状态为eof时结束
        cout << s << endl;
    if1.close();
    if(if1.eof())   cout << "eof!" << endl; // 关闭后，流的状态不会改变

    if1.open("b.txt");  // 如果open成功，则open会设置流的状态，使得good()为true
    if(if1) cout << "Open success." << endl;

    return 0;
}