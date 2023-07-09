#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

struct PersonInfo{  // 练习8.12：为什么没有在PersonInfo中使用类内初始化
    string name;    // 因为这里只需要聚合类就够了，没必要使用类内初始化
    vector<string> phones;
};

int main()
{
    // 练习8.10
    ifstream input("a.txt");
    string line, word;
    vector<string> svec;
    while(getline(input, line)) // 将来自一个文件中的行保存在一个vector<string>中
        svec.push_back(line);
    for(vector<string>::iterator it=svec.begin(); it!=svec.end(); ++it){
        istringstream record(*it);
        while(record >> word)   // 使用一个istringstream从vector读取数据元素，每次读取一个单词
            cout << word << endl;
    }
    input.close();

    // 练习8.11：将record对象定义在外层while循环之外
    vector<PersonInfo> people;
    istringstream record;
    while(getline(cin, line)){  // 从输入流中读取数据
        PersonInfo info;
        record.str(line);
        record >> info.name;
        while(record >> word)
            info.phones.push_back(word);
        record.clear(); // 清空内容以待下次输入
        people.push_back(info);
    }

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