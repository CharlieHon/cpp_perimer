#include <iostream>
#include <vector>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Sales_data{
public:
    Sales_data() = default;
    Sales_data(const string &s, double price, unsigned n) : unit_sold(n), revenue(double(n)*price), bookNo(s) {}
    string isbn() const { return bookNo; }
private:
    unsigned unit_sold;
    double revenue;
    string bookNo;
};

void printVec(const vector<string> &words){
    for(const auto &word : words){
        cout << word << " ";
    }
    cout << endl;
}

void elimDups(vector<string> &words){
    cout << "before sort:" << endl;
    printVec(words);
    sort(words.begin(), words.end());
    cout << "after sort:" << endl;
    printVec(words);
    auto end_unique = unique(words.begin(), words.end());
    cout << "after unique:" << endl;
    printVec(words);
    words.erase(end_unique, words.end());
    cout << "after erase:" << endl;
    printVec(words);
}

// 10.12：编写名为compareIsbn函数，比较两个Sales_data对象的isbn()
bool compareIsbn(const Sales_data &s1, const Sales_data &s2){
    return s1.isbn().size() < s2.isbn().size(); // 按照ISBN编号长度从小打到排序
}

// 10.13
bool predicate(const string &s){
    return s.size() >= 5;
}

// 根据计数值是否大于1，返回单词复数或原形
string make_plural(size_t sz, const string &word,
                                const string &ending){
        return (sz > 1) ? word+ending : ending;
}

// 10.16
void biggies(vector<string> &words, vector<string>::size_type sz){
    elimDups(words);    // 按字典序排序
    // 按字符串长度排序，长度相同的维持字典序
    stable_sort(words.begin(), words.end(), [](const string &a, const string &b){return a.size()>=b.size();});
    // 查找 size >= sz 的位置
    auto wc = find_if(words.begin(), words.end(), [sz](const string &s){return s.size()>=sz;});
    // auto wc = partition(words.begin(), words.end(), [sz](const string &s){return s.size()>=sz;})
    // 个数
    auto count = words.end() - wc;
    cout << count << " " << make_plural(count, "word", "s")
        << " of length " << sz << " or longer" << endl;
    for_each(wc, words.end(), [](const string s){cout << s << " ";});
    cout << endl;
}

int main()
{
    // 10.9
    vector<string> svec{"the","quick","red","fox","jumps","over","the","slow","red","turtle"};
    vector<string> svec2(svec);
    elimDups(svec);
/*
before sort:
the quick red fox jumps over the slow red turtle 
after sort:
fox jumps over quick red red slow the the turtle 
after unique:
fox jumps over quick red slow the turtle the  
after erase:
fox jumps over quick red slow the turtle
 */

    // 10.10: 算法不改变容器大小的原因
    // 算法操作的是迭代器

    // 10.12：编写名为compareIsbn函数，比较两个Sales_data对象的isbn()

    // 10.13: partition接受一个谓词，对容器内容进行划分，使得谓词为true的值会排在容器的前半部分
    //          返回一个迭代器，指向最后一个使谓词为true的元素之后的位置
    auto pivot = partition(svec2.begin(), svec2.end(), predicate);
    for(auto it=svec2.begin(); it!=pivot; ++it){
        cout << *it << " ";
    }
    cout << endl;

    // 10.14
    [](const int &a, const int &b){return a+b;};

    // 10.15
    int a = 10;
    [a](const int &b){return a+b;};


    return 0;
}