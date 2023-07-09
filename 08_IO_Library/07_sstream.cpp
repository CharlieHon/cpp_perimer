#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

/**
 * @brief string流：使用istringstream
 * sstream头文件定义了三个类型来支持内存IO:
 * 1. istringstream从string读取数据
 * 2. ostringstream从string写入数据
 * 3. stringstream既可以从string读数据也可向string写数据
 */

struct PersonInfo{
    string name;
    vector<string> phones;
};

// 使用istringstream：当我们某些工作对整行文本进行处理，而其他一些工作是处理行内的单个单词时，通常可以使用istringstream
int main()
{
    // 假定有一个文件，列出了一些人和他们的电话号码。某些人只有一个号码，而另一些人则有多个
    // morgan 2015552368 8625550123
    // drew 9735550130
    // lee 6095550132 2015550175 80055550000
    
    string fileName, line, word;    // 分别保管文件名、来自文件的一行和单词
    cout << "Please enter the file name: " << flush;
    cin >> fileName;
    ifstream input(fileName);
    vector<PersonInfo> people;  // 保存来自文件的所有记录

    if(!input){
        cerr << "can't open the file: " << fileName << endl;
        return -1;
    }

    while(getline(input, line)){    // 逐行从文件读取数据，直至getline遇到文件结尾(或其他错误)
        PersonInfo info;            // 创建一个保存此纪录的对象
        istringstream record(line); // 将记录绑定到读入的行
        record >> info.name;        // 读取名字
        while(record >> word)       // 读取电话号码
            info.phones.push_back(word);    // 保持它们
        people.push_back(info);     // 将此记录追加到people末尾
    }
    input.close();

    // 输出记录
    for(const auto& person : people){
        cout << "Name: " << person.name << endl;
        cout << "\tphone(s): " << flush;
        for(const auto& phone : person.phones)
            cout << phone << " ";
        cout << endl;
    }

    return 0;
}