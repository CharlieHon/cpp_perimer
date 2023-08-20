#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <list>
using namespace std;

/**
 * @brief 泛型算法
 * 大多数算法都在头文件algorithm中。标准库还在头文件numeric中定义了一组数值泛型算法
 * 泛型算法本身不会执行容器的操作，它们指挥运行于迭代器之上，执行迭代器的操作。
 * 
 * 除了少数例外，标准库算法都对一个范围内的元素进行操作。将此元素范围称为“输入范围”。
 * 接受输入范围的算法总是使用前两个参数来表示此范围，两个参数分别是指向要处理的第一个元素和尾元素之后位置的迭代器。
 */

int main()
{
    // find前两个参数是表示元素范围的迭代器，第三个参数是一个值。返回指向第一个等于给定值的元素的迭代器
    // 如果范围中无匹配元素，则find返回第二个参数来表示搜索失败
    int val1 = 42;
    vector<int> v1{12,35,46,42,9,5,17};
    auto res1 = find(v1.cbegin(), v1.cend(), val1);
    cout << "The value " << val1
        << (res1==v1.cend() ? " is not present" : " is present") << endl;
    
    string val2 = "Hon";
    list<string> lst{"Zhao", "Qian", "Sun", "Lee"};
    auto res2 = find(lst.cbegin(), lst.cend(), val2);
    cout << "The value " << val2
        << (res2==lst.cend() ? " is not present" : " is present") << endl;

    int ia[] = {27, 46, 85, 12, 33, 4, 60}; // 指针就像内置数组上的迭代器
    int val3 = 33;
    // int *res3 = find(ia, ia+7, val3);    // 同下
    int *res3 = find(begin(ia), end(ia), val3);
    if(res3==end(ia)){
        cout << "Not Found!" << endl;
    }else{
        cout << "Find " << *res3 << endl;   // Find 33
    }

    return 0;
}