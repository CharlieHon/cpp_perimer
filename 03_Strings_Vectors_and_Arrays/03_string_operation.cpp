#include <iostream>
#include <string>
using std::cin; using std::cout; using std::endl;
using std::string;

int main()
{
    // 读string对象
    string s;
    //在执行读取操作时，string会自动忽略开头的空白(即空格符、换行符、制表符等)
    //并从第一个真正的字符开始读起，知道遇到下一处空白为止
    cin >> s;   // 将string对象读入s，遇到空白停止

    // 读取未知数量的string对象
    string word;
    while(cin >> word){         // 反复读取，直到到达文件末尾EOF
        cout << word << endl;
    }

    // 使用getline读取一整行
    string line;
    //每次读入一整行，直到达到文件末尾
    while(getline(cin, line)){
        cout << line << endl;
    }

    // string 的 empty 和 size 操作
    //每次读入一行整数，遇到空行直接跳过
    while(getline(cin, line)){
        if(!line.empty())       // 如果非空
            cout << line << endl;
    }
    // 每次读入一整行，输出其中超过80个字符的行
    while(getline(cin, line)){
        if(line.size() > 80)
            cout << line << endl;
    }

    // string::size_type类型
    // 可以通过auto或者decltype推断变量类型
    // string::size_type len = s.size();
    auto len = s.size();

    // 两个string对象相加
    string a = "hello", b = "world\n";
    string c = a + b;
    a += b;     // 等价于 a = a + b

    //字面值和string对象
    string s1("hiya");
    string s2 = s1 + ", ";
    // string s3 = "hello" + ", world";    //错误：两个对象都不是string
    string s4 = s2 + ", " + "TiKi";
    //等价于 string s4 = (s2 + ", ") + "TiKi";  // ()括号内运算结果是string对象
    // string s5 = "hello" + ", world" + s1;   //错误，运算从左到右进行
    
    return 0;
}