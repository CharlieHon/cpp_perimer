#include <iostream>

using namespace std;

/**
 * @brief 条件状态
 * - 一个流一旦发生错误，其上后续的IO操作都会失败
 * - badbit表示系统级错误，如不可恢复的读写错误。通常情况下，一旦badbit被置位，流就无法再使用
 * - failbit表示可恢复错误，如期望读取数值却读出一个字符等错误
 * - 如果达到文件结束位置，eofbit和failbit都会被置位。
 * - goodbit表示流未发生错误
 */

void check_cin_state(istream &is){

    if(is.bad())    // 流是否崩溃
        cout << "is.bad()" << endl;
    else
        cout << "is not bad()" << endl;

    if(is.fail())   // IO操作是否失败
        cout << "is.fail()" << endl;
    else
        cout << "is not fail()" << endl;

    // end of file(Ctrl+Z)
    if(is.eof())    // 流是否达到了文件结束
        cout << "is eof()" << endl;
    else
        cout << "is not eof()" << endl;
    
    if(is.good())   // 流是否处于错误状态
        cout << "is good()" << endl;
    else
        cout << "is not good()" << endl;
}

int main()
{
    cout << "检查cin的状态" << endl;

    // 强制改变流状态(二进制位)
    // cin.setstate(istream::badbit);
    // cin.setstate(istream::failbit);
    // 二进制位或(|)操作
    cin.setstate(istream::eofbit | istream::failbit);   // 同时改变两个

    check_cin_state(cin);

    // 管理条件状态
    istream::iostate old_state = cin.rdstate(); // 记住cin的当前状态
    cin.clear();    // 使cin有效
    cin.setstate(old_state);    // 将cin置为原有状态

    // cin.clear(istream::eofbit); // 清除一种状态
    cin.clear();    // 将流中所有条件状态复位，将流的状态设置为有效
    cin.clear(cin.rdstate() & ~cin.failbit & ~cin.badbit);  // 复位failbit和badbit，保持其他标志位不变



    cout << "输入一个整数：" << endl;
    int n;
    cin >> n;
    cout << "再次检查cin的状态" << endl;
    check_cin_state(cin);

    return 0;
}