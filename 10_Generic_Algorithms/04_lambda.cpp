#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
/**
 * @brief 可调用对象(callable object)
 * 对于一个对象或一个表达式，如果可以对其使用调用运算符，则称它为可调用的
 * 函数、函数指针、重载了函数调用运算符的类和lambda表达式都是可调用对象
 * lambda表达式具有如下形式
 * 
 * [capture list](parameter list) -> return type {function body}
 * 可以忽略参数列表和返回类型，但必须永远包含捕获列表和函数体
 * 如果函数体只有一个return语句，则返回类型从返回的表达式的类型推断而来。否则，返回类型为void
 * 捕获列表只用于局部非static变量，lambda可以直接使用局部static变量和它所在函数之外声明的名字
 */


bool isShorter(const string &s1, const string &s2){ // 比较函数，用来按长度排序单词
    return s1.size() < s2.size();
}

void printVec(const vector<string> &words){ // 打印函数，输出字符串向量
    for(const auto &word : words){
        cout << word << " ";
    }
    cout << endl;
}

void elimDups(vector<string> &words){   // 按照字典序排序
    sort(words.begin(), words.end());
    auto end_unique = unique(words.begin(), words.end());
    words.erase(end_unique, words.end());
}

// 根据计数值是否大于1，返回单词复数或原形
string make_plural(size_t sz, const string &word,
                                const string &ending){
        return (sz > 1) ? word+ending : ending;
}

// 完整的biggies
void biggies(vector<string> &words,
            vector<string>::size_type sz);

int main()
{
    // 谓词是一个可调用的表达式，其返回结果是一个能用作条件的值
    // 谓词分为一元谓词和二元谓词
    vector<string> svec{"the","quick","red","fox","jumps","over","the","slow","red","turtle"};
    // sort(svec.begin(), svec.end(), isShorter);  // 二元谓词接受两个参数
    elimDups(svec);
    stable_sort(svec.begin(), svec.end(), isShorter);   // 将长度重新排序，长度相同的单词维持字典序
    printVec(svec); // fox red the over slow jumps quick turtle

    // find_if接受一对迭代器，表示一个范围，第三个参数是一个谓词
    // 对输入序列中的每个元素调用给定的谓词，返回第一个使谓词返回非0的元素，如果并不存在这样的元素，则返回尾迭代器

    // lambda
    auto f = [] { return 42; };  // 定义了一个可调用对象f，不接受参数，返回42
    cout << f() << endl;    // 42

    // 向lambda传递参数
    // lambda不能有默认参数，一个lambda调用的实参数目永远与形参数目相等
    // stable_sort(svec.begin(), svec.end(), [](const string &a, const string &b) {return a.size()<b.size();}); // 同上，按长度排序

    // 使用捕获列表
    // lambda可以出现在一个函数中，使用局部变量，但lambda只能通过将局部变量包含在其捕获列表中来指出将会使用这些变量
    /*
    [sz](const string &a)           // lambda以一对[]开始，可以在其中提供一个以逗号分隔的名字列表，这些名字都是在函数中定义的
        { return a.size() >= sz;};
    */

    // 调用find_if
    /*
    // 获取一个迭代器，指向第一个满足size()>=sz的元素
    auto wc = find_if(words.begin(), words.end(),
                    [sz](const string &a) { return a.size()>=sz;})
    auto count = words.end() - wc;  // 计算满足size >= sz的元素数目
    */

    //for_each接受一个可调用对象，并对输入序列中每个元素调用此对象
    /*
    // 打印长度大于等于给定值的单词，每个单词后面接一个空格
    for_each(wc, words.end(), [](const string &){cout << s << " ";});   // lambda可以直接使用定义在当前函数之外的名字，如cout
    cout << endl;
    */

    return 0;
}

void biggies(vector<string> &words, vector<string>::size_type sz){
    elimDups(words);    // 将words按字典序排序，删除重复单词
    // 按长度排序，长度相同的单词维持字典序
    stable_sort(words.begin(), words.end());
    // 获取一个迭代器，指向第一个满足 size()>=sz 的元素
    auto wc = find_if(words.begin(), words.end(),
                        [sz](const string &a){return a.size()>=sz;});
    // 计算满足 size>=sz 的元素的数目
    auto count = words.end() - wc;
    cout << count << " " << make_plural(count, "word", "s")
        << " of length " << sz << " or longer" << endl;
    // 打印长度大于等于给定值的单词，每个单词后面接一个空格
    for_each(wc, words.end(),
            [](const string &s){cout << s << " ";});
    cout << endl;
}
