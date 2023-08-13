#include <string>
#include <iostream>
#include <vector>

using namespace std;

// 9.51：设计一个类，它有三个unsigned成员，分别表示年、月和日。为其编写构造函数，接受一个表示日期的string参数
// 构造函数能处理不同数据格式，如January 1,1900、1/1/1990、Jan 1 1900等
class Date{
public:
    Date(const string &s){
        
    }
    void showDate() const {
        cout << month << "/" << day << "/" << year << endl;
    }

private:
    unsigned year;
    unsigned month;
    unsigned day;
};


int main()
{
    // 9.47：查找string"ab2c3d7R4E6"中的每个数字字符，然后查找其中每个字符字符
    string s("ab2c3d7R4E6"), numbers("0123456789");
    string::size_type pos = 0;
    while((pos = s.find_first_of(numbers, pos)) != string::npos){   // 查找数字
        cout << "find number at index: " << pos
            << " element is: " << s[pos] << endl;
        ++pos;  // 没有会导致死循环
    }
    pos = 0;
    while((pos = s.find_first_not_of(numbers, pos)) != string::npos){   // 查找字符
        cout << "find alphabetic at index: " << pos
            << " element is: " << s[pos] << endl;
        ++pos;
    }

    // 9.48
    string name("r2d2");
    cout << numbers.find(name) << endl; // 18446744073709551615，即string::npos

    // 9.49：编写程序，读入一个单词文件，输出最长的既不包含上出头部分，也不包含下出头部分的单词

    // 9.50
    vector<string> v1{"12", "34", "5"}, v2{"1.2", "3.6", "0.2"};
    int sum1 = 0;
    double sum2 = 0.0;
    for(const auto elem : v1){
        int x = stoi(elem);
        sum1 += x;
    }
    cout << "sum1 = " << sum1 << endl;    // 42
    for(const string elem : v2){
        double x = stod(elem);
        sum2 += x;
    }
    cout << "sum2 = " << sum2 << endl;    // 5

    return 0;
}