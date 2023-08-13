#include <iostream>
#include <string>

using namespace std;

/**
 * @brief compare函数
 * 根据s是等于、大于还是小于参数指定的字符串，s.compare返回0，正数或负数
 * s.compare的几种参数形式
 * s2
 * pos1, n1, s2
 * pos1, n1, s2, pos2, n2：将s中从pos1开始的n1个字符与s2中从pos2开始的n2个字符进行比较
 * cp
 * pos1, n1, cp
 * pos1, n1, cp, n2：将s中从pos1开始的n1个字符与指针cp指向的地址开始的n2个字符进行比较
 * 
 * 数值转换：字符串中常常包含表示数值的字符
 * to_string(val)：返回数值val的string表示
 * stoi(s, p, b)：返回s的其实子串(表示整数内容)的数值，返回值类型是int、long……
 *                  b表示转换所用的基数，默认值为10.p是size_t指针，原来保存s中第一个非数值字符的下标，p默认为0，不保存下标
 * stol, stoul, stoll, stoull
 * stof(s, p)
 * stod(s, p), stold(s, p)
 */

int main()
{
    // compare函数
    string s1("abcefg"), s2("aacd");
    const char *cp = "angle";
    cout << s1.compare(0, 2, s2, 0, 2) << endl; // 1
    cout << s1.compare(0, 5, cp) << endl;   // -1

    // 数值转换
    int i = 42;
    string s = to_string(i);    // 将整数i转换为字符串表示形式"42"
    double d = stod(s); // 将字符串s转换为浮点数42

    // 要转换为数值的string中第一个非空白符必须是数值中可能出现的字符
    string s3 = "pi = 3.14";
    d = stod(s3.substr(s3.find_first_of("+-.0123456789")));
    cout << d << endl;  // 3.14

    // s3.find_first_of查找第一个可能是数值的一部分的字符的位置，将s中从此位置开始的字串传递给stod
    // stod函数读取此参数，处理其中的字符，指导遇到不可能是数值的一部分的字符。

    return 0;
}