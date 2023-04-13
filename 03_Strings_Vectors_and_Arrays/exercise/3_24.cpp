#include <iostream>
#include <string>
#include <vector>
#include <cctype>
using namespace std;

int main()
{
    // 练习3.24
    int i;
    vector<int> vi;
    while(cin >> i){
        vi.push_back(i);
    }

    // 两个紧邻的元素相加
    cout << "ex1:" << endl;
    for(auto it=vi.begin(); it!=vi.end()-1; ++it){
        cout << *it + *(it+1) << endl;
    }
    // 两端相加
    cout << "ex2:" << endl;
    for(auto beg=vi.begin(),end=vi.end()-1; beg<end; ++beg,--end){
        cout << *beg + *end << endl;
    }

    // 练习3.25：使用迭代器完成之前分数划分区间的练习
    vector<int> scores(11,0);
    // auto it = scores.begin();
    int x;
    while(cin >> x){
        if(x <= 100){
            // ++*(it+(x/10));
            ++*(scores.begin() + x/10);
        }
    }
    // 输出结果
    for(auto score : scores)
        cout << score << " ";
    cout << endl;

    return 0;
}