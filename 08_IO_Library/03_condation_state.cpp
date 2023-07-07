#include <iostream>

using namespace std;

int main()
{
    int sum = 0, val;

    // while(cin >> val){   // 每次检测三个状态:bad, fail, eof.任何一个状态改变都会结束
    //     sum += val;
    //     cout << "sum = " << sum << endl;
    // }

    // 仅当dof时，循环结束
    while(cin >> val, !cin.eof()){  // 逗号表达式第二个表达式结果为表达式返回值
        if(cin.bad())   // bad为系统级错误
            throw std::runtime_error("IO stream corrupted.");
        if(cin.fail()){ // fail错误
            cerr << "bad data, try again" << endl;
            cin.clear();    // 清空标志，恢复流状态
            // fail数据会留在cin流里
            cin.ignore(200, '\n');  // 清除流数据，要么200个，要么到"\n"
            continue;
        }
        sum += val;
        cout << "sum = " << sum << endl;
    }

    return 0;
}