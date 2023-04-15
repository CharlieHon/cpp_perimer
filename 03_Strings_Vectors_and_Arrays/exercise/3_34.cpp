#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
* 分别输入两个数组的首地址和尾后地址,比较两个数组是否相等
*/
bool compare_array(int* const b1, int* const e1, int* const b2, int* const e2){
    if((e1-b1) != (e2-b2))
        return false;
    for(int *i=b1,*j=b2; (i!=e1) && (j!=e2); ++i,++j){
        if(*i != *j)
            return false;
    }
    return true;
}

int main()
{
    // 练习3.34
    constexpr unsigned sz = 7;
    int a[7] = {0,5,9,6,12,21,10};
    int *p1 = begin(a), *p2 = &a[4];
    p1 += p2 - p1;  // 将p1移动到p2位置,任何情况下都是合法的

    // 练习3.35:编写一段程序,利用指针将数组中的元素置为0
    int *beg = begin(a), *last = end(a);
    while(beg != last){
        *beg = 0;
        ++beg;
    }
    for(int i : a){
        cout << i << " ";
    }
    cout << endl;

    // 练习3.36:编写一段程序,比较两个数组是否相等
    int b[] = {0,5,9,6,12,21,10};
    int c[] = {0,5,9,6,12,21,10};
    int d[] = {1,9,4,9,2,0,2,3};
    if(compare_array(begin(b), end(b), begin(c), end(c)))
        cout << "The two arrays are equal!" << endl;
    else
        cout << "Not equal!" << endl;

    // 再写一段程序,比较两个vector对象是否相等
    // 判断vector对象是否相等,可以直接使用 == 

    return 0;
}