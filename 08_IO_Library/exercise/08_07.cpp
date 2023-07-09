#include "Sales_data.h"
#include <iostream>
#include <fstream>

using namespace std;

// 修改8.6程序，将结果保存到一个文件中。将输出文件名作为第二个参数传递给main函数
int main(int argc, char **argv)
{
    // argv[0]: 函数名
    // argv[1]: 读取文件
    // argv[2]: 写入文件
    // argv[3]: '0'

    ifstream input(argv[1]);
    ofstream output(argv[2], ofstream::app);    // 8.8：将结果追加到给定的文件末尾
    Sales_data total;
    if(read(input, total)){
        Sales_data trans;
        while(read(input, trans)){
            if(trans.isbn() == total.isbn())
                total.combine(trans);
            else{
                // print(cout, total) << endl;
                output << total.isbn() << " " << total.avg_price() << endl; // 将结果保存到output打开的文件中
                total = trans;
            }
        }
        // print(cout, trans) << endl;
        output << total.isbn() << " " << total.avg_price() << endl;
    }else
        cerr << "No data." << ends;

    return 0;
}