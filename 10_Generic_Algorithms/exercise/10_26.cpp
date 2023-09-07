#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <list>
#include <string>
#include <iterator>
#include <fstream>

using namespace std;

template<typename T>
void print_vec(const vector<T> &vec){
    for(auto elem : vec){
        cout << elem << " ";
    }
    cout << endl;
}

int main()
{
    // 10.26 解释三种插入迭代器的不同之处
    /*
    - back_inserter 使用 push_back
    - front_inserter 使用 push_front
    - inserter 使用 insert，此函数接受第二个参数，这个参数必须是指向给定容器的迭代器。
                元素将被插入到给定迭代器所表示的元素之前
    */

    // 10.27
    vector<int> v1{0,1,1,1,2,7};
    list<int> lst1;
    unique_copy(v1.cbegin(), v1.cend(), inserter(lst1, lst1.begin()));
    for_each(lst1.cbegin(), lst1.cend(), [](const int &x){cout << x << " ";});
    cout << endl;   // 0 1 2 7

    // 10.28
    vector<int> v2{1,2,3,4,5,6,7,8,9}, v3, v4, v5;
    copy(v2.cbegin(), v2.cend(), inserter(v3, v3.begin()));
    print_vec(v3);  // 1 2 3 4 5 6 7 8 9
    copy(v2.cbegin(), v2.cend(), back_inserter(v4));
    print_vec(v4);  // 1 2 3 4 5 6 7 8 9
    // copy(v2.cbegin(), v2.cend(), front_inserter(v5));   // 错误：vector容器没有push_front操作

    // 10.29
    ifstream in_file("../afile.txt");
    istream_iterator<string> str_in(in_file), str_eof;
    vector<string> svec(str_in, str_eof);
    in_file.close();
    cout << "10.29:" << endl;
    print_vec(svec);    // hello world

    // 10.30
    istream_iterator<int> int_in(cin), int_eof;
    vector<int> v6;
    copy(int_in, int_eof, back_inserter(v6));   // 输入：1 9 4 9 2 0 2 3
    sort(v6.begin(), v6.end());
    // 10.31
    // unique(v6.begin(), v5.end());
    // print_vec(v6);  // 输出：0 1 2 2 3 4 9 9
    copy(v6.cbegin(), v6.cend(), ostream_iterator<int>(cout, " ")); // 输出：0 1 2 2 3 4 9 9
    cout << endl;

    // 10.32

    // 10.33
    cout << "10.33" << endl;
    ifstream in_file2("a.txt");
    ofstream out_file1("odd.txt", ios::trunc), out_file2("even.txt", ios::trunc);
    istream_iterator<int> int_in2(in_file2), int_eof2;
    ostream_iterator<int> int_out1(out_file1, "\n"), int_out2(out_file2, "\n");
    while(int_in2 != int_eof2){
        if(*int_in2 % 2){
            *int_out1++ = *int_in2++;
        }else{
            *int_out2++ = *int_in2++;
        }
    }

    // 10.34
    vector<int> v7{1,9,1,2};
    for(auto it_iter=v7.crbegin();
        it_iter!=v7.crend(); ++it_iter)
        cout << *it_iter << " ";    // 2 1 9 1
    cout << endl;

    // 10.35 使用普通迭代器逆序打印一个vector
    vector<int> vec{1,2,3,4,5,6,7};
    for(auto it=vec.cend(); true; --it){
        cout << *it << " ";
        if(it==vec.cbegin())
            break;
    }

    // 10.36 
    list<int> lst2{2,0,0,1};
    auto iter = find(lst2.cbegin(), lst2.cend(), 0);

    // 10.37
    vector<int> v8{1,2,3,4,5,6,7,8,9,10};
    list<int> lst3;
    copy(v8.crbegin()+3, v8.crend()+8, lst3.begin());   // 将位置3到7之间的元素按逆序拷贝到一个list中

    return 0;
}