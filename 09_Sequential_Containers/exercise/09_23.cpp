#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <list>
#include <forward_list>

using namespace std;

//9.28：编写函数，接受一个forward_list<string>和两个string共三个参数。函数在链表中查找第一个string，
// 并将第二个string插入到紧接着第一个string之后的位置。若第一个string未在链表中，则将第二个string插入到链表末尾
void insert_elem(forward_list<string> &flst, const string &s1, const string &s2){
    auto prev = flst.before_begin(), curr = flst.begin();
    while(curr != flst.end()){
        if(*curr == s1) curr = flst.insert_after(curr, s2); // curr更新为插入元素的迭代器
        prev = curr;    // 移动两个迭代器
        ++curr;
    }
    flst.insert_after(prev, s2);
}

int main()
{
    // 9.23：若v1.size()为1，结果全是5
    vector<int> v1 = {6};
    if(!v1.empty()){
        auto val1 = *v1.begin(), val2 = v1.front();
        auto last = v1.end();
        auto val3 = *(--last);
        auto val4 = v1.back();
        cout << "val1: " << val1
            << " val2: " << val2
            << " val3: " << val3
            << " val4:" << val4 << endl;
    }

    // 9.24
    // vector<int> v2;  // 空vector会报错
    vector<int> v2 = {3,6,0};
    cout << "at: " << v2.at(0) << endl;
    cout << "v2[]: " << v2[0] << endl;
    cout << "v2.front(): " << v2.front() << endl;
    cout << "*v2.begin(): " << *v2.begin() << endl;

    // 9.25
    list<int> ilist = {4,5,6,7,9,5,3};
    for(auto elem : ilist)  cout << elem << " ";
    // auto elem1 = ilist.begin(), elem2 = ilist.end(); // 所有元素
    // auto elem1 = ilist.begin(), elem2 = ilist.begin();  // 二者相同，不会删除任何元素
    auto elem1 = ilist.end(), elem2 = ilist.end();    // 二者皆为尾后迭代器，也什么都不会发生
    ilist.erase(elem1, elem2);
    cout << endl;
    for(auto elem : ilist)  cout << elem << " ";

    // 9.27：查找并删除forward_list<int>中的奇数元素
    forward_list<int> flst = {4,7,6,9,8,5,1,0};
    auto prev = flst.before_begin(), curr = flst.begin();
    while(curr != flst.end()){
        if(*curr % 2)
            curr = flst.erase_after(prev);
        else{
            prev = curr;
            ++curr;
        }
    }

    // TEST 9.28
    forward_list<string> slst = {"hi", "world", "like", "Tao"};
    string s1 = "hi", s2 = "hk";
    insert_elem(slst, s1, s2);
    cout << endl;
    for(auto elem : slst)   cout << elem << endl;

    return 0;
}