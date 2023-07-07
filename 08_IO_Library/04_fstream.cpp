#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void read_file(ofstream &of){
    
}

int main()
{
    // 1.向文件中写入内容
    ofstream of1("test.txt");   // 输出流，创建新文件
    of1 << "hello file!";
    of1.close();

    // 2.从文件中读取内容
    string file("a.txt");
    // 在创建文件时绑定
    // ifstream if1(file); // 老版本使用C风格字符串，file.c_str()，C++11可以使用string
    
    ifstream if1;
    if1.open(file); // 通过open绑定文件

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

    if1.open("b.txt");  // 如果打开成功，流的状态会被重置
    if(if1) cout << "Open success." << endl;

    return 0;
}