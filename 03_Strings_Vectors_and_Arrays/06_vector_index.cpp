#include <iostream>
#include <vector>
using namespace std;

int main()
{
    // 计算vector内对象的索引
    // 根据输入成绩计算各成绩区间(0~9,10~19,...,90~99,100)中成绩的个数
    vector<unsigned> ivec(11, 0);    // 一共11各成绩区间
    unsigned score;
    while(cin >> score){
        if(score <= 100)
            ++ivec[score/10];   // score/4 得到成绩对应区间的索引
    }
    // 输出各区间元素个数
    for(auto s : ivec){
        cout << s << " ";
    }
    cout << endl;

    /* 不能用下标形式添加元素
    vector<int> vi; // 空 vector 对象
    for(decltype(vi.size()) ix=0; ix!=10; ++ix)
        vi[ix] = ix;    // 严重错误：vi不包含任何元素，但编译器不会提示错误
    */

    return 0;
}