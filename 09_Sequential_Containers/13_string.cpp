#include <iostream>
#include <string>

using namespace std;

/**
 * @brief string搜索操作
 * string类的搜索操作返回一个string::size_type值，表示匹配发生位置的下标，该类型是一个unsigned类型
 *  若搜索失败，则返回一个名为string::npos的static成员
 * 
 * s.find(args)：查找s中args第一次出现的位置
 * s.rfind(args)：          最后一次
 * s.find_first_of(args)：在s中查找args中任何一个字符第一次出现的位置
 * s.find_last_of(args)：                           最后一次
 * s.find_first_not_of(args)：在s中查找第一个不在args中的字符
 * s.find_last_not_of(args)：在s中查找最后一个不在args中的字符
 */

int main()
{
    // find查找参数指定的字符串，若找到，返回第一个匹配位置的下标，否则返回npos
    string name("AnnaBelle");
    auto pos1 = name.find("Anne");  // pos1 == 0

    // 搜索(以及其他string操作)是大小写敏感的
    string lowercase("annebelle");
    auto pos2 = lowercase.find("Anne"); // pos2 == npos

    // 查找与给定字符串中任何一个字符匹配的位置
    string numbers("0123456789"), names("r2d2");
    auto pos3 = names.find_first_of(numbers);   // 1，即names中第一个数字的下标

    // 搜索第一个不在参数中的字符
    string dept("13714p3");
    auto pos4 = dept.find_first_not_of(numbers);  // 5——字符'p'的下标

    // 指定在哪里开始搜索
    string::size_type pos = 0;
    while((pos=names.find_first_of(numbers, pos)) != string::npos){
        cout << "find number at index: " << pos
                << " element is " << names[pos] << endl;
        ++pos;
    }

    // 逆向搜索：由右向做搜索
    string river("Mississippi");
    auto first_pos = river.find("is");  // 1
    auto last_pos = river.rfind("is");  // 4

    return 0;
}