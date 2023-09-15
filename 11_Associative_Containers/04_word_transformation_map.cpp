#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <utility>

using namespace std;

/**
 * @brief 11.3.6 一个单词转换的map
 * 给定一个string，将它转换为另一个string
 * 程序的输入是两个文件。第一个文件保存的是一些规则，用来转换第二个文件中的文本。
 * 每条规则由两部分组成：一个可能出现在输入文件中的单词和一个用来替换它的短语。
 * 
 * 转换文件内容如下所示：
 * brb be right back
 * k okey?
 * y why
 * r are
 * u you
 * pic picture
 * thk thanks
 * 18r later
 * 希望转换的文本为
 * where r u
 * y dont u send me a pic
 * k thk 18r
 * 程序应该生成这样的输出：
 * where are you
 * why dont you send me a picture
 * okay? thanks! later
 */

map<string, string> buildMap(ifstream &map_file){   // 建立转换映射
    map<string, string> trans_map;  // 保存转换规则
    string key, value;  // 要转换的单词
    // 读取第一个单词存入key中，行中剩余内容存入value
    while(map_file >> key && getline(map_file, value)){
        if(value.size() > 1)    // 检查是否有转换规则
            trans_map[key] = value.substr(1);   // 跳过前导空格
            /* 11.35 如果改为 trans_map.insert({key, value.substr(1)});
            当关键字多次出现时
            trans_map[key] = value.substr(1);   会保留最后一次添加的规则
            trans_map.insert({key, value.substr(1)});   保留第一次添加的规则
            */
        else
            // 11.36 当关键字没有对应的规则，程序会抛出一个 `runtime_error`
            throw runtime_error("no rule for " + key);
    }
    return trans_map;
}

const string&
transform(const string &s, const map<string, string> &m){   // 生成转换文本
    // 实际的转换工作；此部分是程序的核心
    auto map_it = m.find(s);
    
    /* 11.34 如果替换为下标运算符，会发生什么
    当关键字不在转换规则中时，会往容器中添加一个元素
    */
    
    // 如果单词在转换规则map中
    if(map_it != m.cend()){
        return map_it->second;  // 使用替换短语
    }else{
        return s;   // 否则返回原string
    }
}

void word_transform(ifstream &map_file, ifstream &input){   // 单词转换程序
    auto trans_map = buildMap(map_file);    // 保存转换规则
    string text;    // 保存输入的每一行
    while(getline(input, text)){    // 读取一行输入
        istringstream stream(text); // 读取每个单词
        string word;
        bool firstword = true;
        while(stream >> word){
            if(firstword)
                firstword = false;
            else
                cout << " ";    // 在除第一个单词前打印一个空格
            // transform返回它的第一个参数或者其转换之后的形式
            cout << transform(word, trans_map); // 打印输出
        }
        cout << endl;   // 完成一行的转换
    }
}


int main()
{
    ifstream map_file("map_file.txt"), input("input.txt");

    word_transform(map_file, input);

/*
where are you
why dont you send me a picture
okey? thanks later
*/

    map_file.close();
    input.close();

    return 0;
}