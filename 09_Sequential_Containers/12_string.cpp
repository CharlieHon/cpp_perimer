#include <iostream>
#include <string>

using namespace std;

/**
 * @brief 额外的string操作
 * 
 * 构造string的其他方法
 * string s(cp, n)：s是cp指向的数组的前n个字符的拷贝
 *      当从一个const char *创建string时，指针指向的数组必须以空字符结尾，拷贝操作遇到空字符时结束
 * string s(s2, pos2)：s是stirng s2从下标pos2开始的(len2个)字符的拷贝
 * string s(s2, pos2, len2)
 * 
 * // 子字符串操作
 * s.substr(pos, n)：返回一个string，包含s中从pos开始的n个字符的拷贝。
 * 
 * // 修改string的操作
 * s.insert(pos, args)：在pos之前插入args指定的字符。pos可以是一个下标或一个迭代器
 * s.erase(pos, len)：删除从位置pos开始的len个字符。如果len被省略，则删除从pos开始直至s末尾的所有字符
 * s.assign(pos, args)：将s中的字符替换为args指定的字符
 * s.append(args)：将args追加到s。
 * s.replace(range, args)：删除s中范围range内的字符，替换为args指定的字符。
 * args可以是下列形式之一；append和assign可以使用所有形式。str不能与s相同
 * str：字符串str
 * str,pos,n：str中从pos开始最多len个字
 * cp,len：cp指向的以空字符结尾的字符数组
 * n, c：n个字符c
 * b,e：迭代器b和e指定的范围内的字符
 * 初始化列表：花括号包围，以逗号分隔的字符列表
 * 
 */

int main()
{
    // 构造string的其他方法
    const char *cp = "hello world!!!";
    char noNull[] = {'H', 'i'};
    string s1(cp);  // 拷贝cp中字符直到遇到空字符：s1 == "hello world!!!"
    string s2(noNull, 2);   // 从noNull拷贝两个字符：s2 == "Hi"
    string s3(noNull);  // 未定义：noNull不是以空字符结束
    string s4(cp+6, 5); // 从cp[6]开始拷贝5个字符：s4 == "world!!!"
    string s5(s1, 6, 5);    // 从s1[6]开始拷贝5个字符：s5 == "world!!!"
    string s6(s1, 6);    // 从s1[6]开始拷贝5个字符，直到s1末尾：s6 == "world!!!"
    string s7(s1, 6, 20);   // 正确，只拷贝到s1末尾：s7 == "world!!!"
    // string s8(s1, 16);  // 抛出一个out_of_range异常

    // substr操作
    string s("hello world");
    string s9 = s.substr(0, 5); // s9 = hello
    string s10 = s.substr(6);   // s10 = world
    string s11 = s.substr(6, 11);   // s11 = world
    // string s12 = s.substr(12);  // 抛出一个out_of_range异常

    // 改变string的其他方法
    cout << s << endl;  // hello world
    s.insert(s.size(), 3, '!'); // 在s末尾插入3个感叹号
    cout << s << endl;  // hello world!!!
    s.erase(s.size()-5, 5); // 从s中删除最后5个字符
    cout << s << endl;  // hello wor

    const char *ccp = "Bruce Lee."; // 接受C风格字符数组
    s.assign(ccp, 5);   // s == "Bruce"
    s.insert(s.size(), ccp+5);   // s == "Bruce Lee"

    // 将来自其他string或字符串的字符插入到当前string中或赋予当前string
    string ss1 = "some string", ss2 = "some other string";
    ss1.insert(0, ss2);  // 在ss1中位置0之前插入ss2的拷贝
    ss1.insert(0, ss2, 0, ss2.size());  // 在ss1[0]之前插入ss2中从ss2[0]开始的ss2.size()个字符

    // append和replace函数
    string a("C++ Primer"), b = a;
    a.insert(a.size(), " 4th Ed.");  // a == "C++ Primer 4th Ed."
    b.append(" 4th Ed.");    // b == "C++ Primer 4th Ed."

    // 将4th替换为5th
    a.erase(11, 3); // a == "C++ Primer Ed."
    a.insert(11, "5th");    // a == "C++ Primer 5th Ed."
    b.replace(11, 3, "5th");    // b == "C++ Primer 5th Ed."

    // 插入的文本和删除的文本可以不一样长
    a.replace(11, 3, "fifth");  // s == "C++ Primer fifth Ed."

    return 0;
}