#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

// 练习8.4：以读模式打开一个文件，将其内容读入到一个string的vector中，将每一行作为一个独立的元素存于vector中。
void ReadFileVector(const string &fileName, vector<string> &svec){
    ifstream in(fileName);
    if(in){ // 文件打开成功
        string s;
        while(getline(in, s))   // 练习8.5：将每个单词作为一个独立的元素进行存储while(in >> s)
            svec.push_back(s);
    }
    if(!svec.empty()){
        for(const auto &s : svec)
            cout << s << endl;
    }
    cout << endl;
    cout << "Totally: " << svec.size() << "row(s)." << endl;
}

int main()
{
    string fileName;
    vector<string> svec;
    cout << "Please enter the file name:" << ends;
    cin >> fileName;
    ReadFileVector(fileName, svec);
    return 0;
}