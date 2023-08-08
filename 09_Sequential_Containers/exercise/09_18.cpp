#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <deque>

using namespace std;

int main()
{
    // 9.18
    string word;
    deque<string> d1;
    while(cin >> word)
        d1.push_back(word);
    for(auto iter=d1.cbegin(); iter!=d1.cend(); ++iter)
        cout << *iter << endl;
    
    // 9.20：从一个list<int>拷贝元素到两个deque中。值为偶数的所有元素都拷贝到一个deque中，而奇数值元素都拷贝到另一个deque中
    deque<int> d2, d3;
    list<int> l1 = {1,2,3,5,7,9,8,6,10};
    for(auto elem : l1){
        if(elem%2)  d3.push_back(elem);
        else    d2.push_back(elem);
    }

    // 9.21
    vector<int> v1;
    auto iter = v1.begin();
    int x;
    while(cin >> x)
        iter = v1.insert(iter, x);

    // 9.22
    vector<int> iv = {1,2,4,6,6,8,7,8,6};
    int some_val = 6;
    vector<int>::iterator iter = iv.begin(), mid = iv.begin() + iv.size()/2;
    while(iter != mid){
        if(*iter == some_val){
            iv.insert(iter, 2*some_val);
            ++iter;
        }
    }

    return 0;
}
