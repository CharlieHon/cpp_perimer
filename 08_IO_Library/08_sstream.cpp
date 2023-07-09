#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

/**
 * @brief string流：使用ostringstream
 * 当我们逐步构造输出，希望最后一起打印时，ostringstream是很有用的。
 * 例如，对上一节的例子，逐个验证电话号码并改变其格式。如果所有号码都是有效的，输出一个新文件，包含改变格式的号码。
 * 对于无效的号码，不会将它们输出到新文件中，而是打印一条包含人名和无效号码的错误信息。
 */

struct PersonInfo
{
    string name;
    vector<string> phones;
};

bool valid(const string &phone){    // 电话号码验证
    return phone.size() == 11;
}

string format(string phone){    // 改变格式
    char a[14];
    for(size_t i=0, j=0; i<phone.size();){
        if(j == 3 || j == 8){
            a[j] = '-';
            ++j;
            continue;
        }
        a[j] = phone[i];
        ++i;
        ++j;
    }
    return string(a);
}

int main()
{
    string fileName, line, word;
    cout << "Enter the file(phones.txt) name: " << flush;
    cin >> fileName;
    ifstream input(fileName);
    vector<PersonInfo> people;
    if(!input){
        cerr << "can't open the file: " << fileName << endl;
        return -1;
    }
    // 从文件中读取数据
    while(getline(input, line)){
        PersonInfo info;
        istringstream record(line);
        record >> info.name;
        while(record >> word)
            info.phones.push_back(word);
        people.push_back(info);
    }
    input.close();

    // 向文件中写入数据
    ofstream output("phone_format.txt", fstream::app);
    for(const auto &person : people){   // 对people中每一项
        ostringstream formatted, badNums;   // 每个循环步创建的对象
        for(const auto &phone : person.phones){ // 对每个数
            if(valid(phone))
                formatted << " " << format(phone);  // 将格式化的字符串“写入”formatted
            else
                badNums << " " << phone;    // 将数的字符串形式存入badNums
        }
        if(badNums.str().empty())   // 没有错误的数
            output << person.name << " "    // 打印名字
                    << formatted.str() << endl; // 和格式化的数
        else    // 否则，打印名字和错误的数
            cerr << "input error: " << person.name
                    << " invalid number(s)" << badNums.str() << endl;
    }
    output.close();

    return 0;
}