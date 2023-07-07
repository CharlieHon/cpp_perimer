#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void process(const string &s){
    cout << s << endl;
}

int main()
{
    vector<string> files;
    files.push_back("a.txt");
    files.push_back("b.txt");
    files.push_back("c.txt");   // 文件不存在
    files.push_back("d.txt");

    string s;
    vector<string>::const_iterator it = files.begin();
    while(it != files.end()){
        ifstream input(*it);
        if(!input){
            cerr << "error: can not open file: "
                    << *it << endl;
            // input.clear();   // 清空流状态，C++11可有可无
            ++it;   // 处理下一个文件
            continue;   // 不用continue，则if-else
        }
        while(input >> s)
            process(s); // 处理文件内容
        input.close();
        // input.clear();
        ++it;
    }

    return 0;
}