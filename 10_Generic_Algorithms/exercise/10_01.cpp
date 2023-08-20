#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <list>
#include <numeric>

using namespace std;

int main()
{
    // 10.1&10.2
    vector<int> v1;
    int val1 = 10;
    int x;
    while(cin >> x){
        v1.push_back(x);
    }
    auto res1 = count(v1.cbegin(), v1.cend(), val1);
    cout << "Find " << val1 << " in v1 " << res1 << " times!" << endl;

    // 10.3
    vector<int> v2{4,7,6,4,1,1,0,2,6,9};
    int sum2 = accumulate(v2.cbegin(), v2.cend(), 0);
    cout << "The sum of the v2 is " << sum2 << endl;    // 40

    // 10.4
    vector<double> v3{1.1, 2.2, 3.1, 4.5};
    double sum3 = accumulate(v3.cbegin(), v3.cend(), 0);    // 以整数0作为求和起点，求浮点数的和会导致精度损失
    cout << "The sum of the v3 is " << sum3 << endl;    // 10  0 + 1 + 2 + 3 + 4

    // 10.5
    vector<const char*> v4{"hi", "New", "Spider"};
    vector<const char*> v5{"hi", "New", "Spider"};
    cout << (equal(v4.cbegin(), v4.cend(), v5.cbegin()) ? "Equal!" : "Not Equal!") << endl; // Equal

    // 10.6
    vector<int> v6(10, 7);  // 初始化为10个7
    fill_n(v6.begin(), v6.size(), 0);   // 将序列中的int值都设置为0

    // 10.8: 标准库算法不会改变它们所操作的容器的大小。为什么使用back_inserter不会使这一断言失效？
    // back_inserter是插入迭代器，在iterator.h头文件中，不是标准库的算法

    return 0;
}