#include <iostream>

using namespace std;

void check_cin_state(istream &is){

    if(is.bad())
        cout << "is.bad()" << endl;
    else
        cout << "is not bad()" << endl;

    if(is.fail())
        cout << "is.fail()" << endl;
    else
        cout << "is not fail()" << endl;

    // end of file(Ctrl+Z)
    if(is.eof())
        cout << "is eof()" << endl;
    else
        cout << "is not eof()" << endl;
    
    if(is.good())
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

    // 保存流的状态
    istream::iostate old_state = cin.rdstate();
    // 清空流状态
    cin.clear();
    // 还原流状态
    cin.setstate(old_state);

    // 清除流状态
    // cin.clear(istream::eofbit); // 清除一种状态
    cin.clear();    // 清空所有状态

    cout << "输入一个整数：" << endl;
    int n;
    cin >> n;
    cout << "再次检查cin的状态" << endl;
    check_cin_state(cin);

    return 0;
}