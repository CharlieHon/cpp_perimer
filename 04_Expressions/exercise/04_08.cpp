#include <iostream>

using namespace std;

int main()
{
    // 练习4.8
    /*
    1.逻辑与运算符和逻辑或运算符都是先求左侧运算对象的值再求右侧运算对象的值，
    当且仅当左侧运算对象无法确定表达式的结果时，才会计算右侧运算对象的。这种策略成为短路求值。
    2.相等性运算符未定义求值顺序
    */

    // 练习4.9
    const char *cp = "Hello World";
    while(cp && *cp){   // 指针非空 且 指针指向的内容非空('\0')
        cout << *cp;
        ++cp;
    }
    cout << endl;

    // 练习4.10
    int x;
    while(cin >> x && x != 42){ // 从标准输入中读取整数，遇到42时停止
        cout << x << endl;
    }

    // 练习4.11
    int a = 5, b = 4, c = 3, d = 2;
    if(a > b && b > c && c > d){    // 确保a大于b，b大于c，c大于d
        cout << "a > b > c > d" << endl;
    }

    // 练习4.12
    int i = 1, j = 2, k = 3;
    // 先判断j和k的大小，然后比较结果与i的相等性。下例输出0
    cout << (i != j<k) << endl; // 大小关系优先级高于相等性关系，所以等价于 i != (j < k)

    return 0;
}