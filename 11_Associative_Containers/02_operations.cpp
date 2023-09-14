#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <utility>

using namespace std;

/**
 * @brief 11.3 关联容器操作
 * 关联容器额外的类型别名
 * key_type：关键字类型
 * mapped_type：每个关键字关联的(值)类型，只适用于map
 * value_type：对于set与key_type相同；对于map，为pair<const key_type, mapped_type>
 * 
 * 关联容器的迭代器
 *  当解引用一个关联容器迭代器时，会得到一个类型为容器的value_type的值的引用
 * 关联容器和算法
 *  通常不对关联容器使用泛型算法。关键字是const这一特性意味着不能将关联容器传递给修饰或重排容器元素的算法
 * 
 * 添加元素
 * insert向容器添加一个元素或一个元素范围。由于map和set包含不重复的关键字，因此插入一个已存在元素对容器没有任何影响
 * c.insert(b, e)
 * c.insert(i1)
 * 
 * 删除元素
 * c.erase(k)：从c中删除每个关键字为k的元素。返回一个size_type值，指出删除元素的数量
 * c.erase(p)：从c中删除迭代器p指定的元素。返回一个指向p之后元素的迭代器
 * c.erase(b, e)：删除迭代器b和e所表示的范围中的元素。返回e
 * 
 * map的下标操作
 * c[k]：返回关键字为k的元素；如果k不在c中，添加一个关键字k的元素，对其进行值初始化
 * c.at(k)：返回关键字为k的元素，带参数检查；若k不在c中，抛出一个 out_of_range 异常
 * 因为下标操作符可能插入一个新元素，因此只可以对非 const 的map使用下标操作符
 * 对一个map进行下标操作时，会获得一个mapped_type对象；但当解引用一个map迭代器时，会得到一个value_type对象
 * map下标运算符返回一个左值，既可以读也可以写元素
 * 
 * 访问元素
 * c.find(k)：返回一个迭代器，指向第一个关键字为k的元素，若k不在容器中，则返回尾后迭代器
 * c.count(k)：返回关键字等于k的元素的数量。对不允许重复关键字的容器，返回值永远是0或1
 * c.lower_bound(k)：返回一个迭代器，指向第一个关键字 不小于k 的元素
 * c.upper_count(k)：返回一个迭代器，指向第一个关键字 大于k 的元素
 * c.equal_range(k)：返回一个迭代器pair，表示关键字等于k的元素的范围。若k不存在，pair的两个成员，均等于c.end()
 * 
 */

int main()
{
    // set中保存的值就是关键字
    set<string>::key_type v1;
    set<string>::value_type v2; // 都是string
    // map的每个元素是一个pair对象，包含一个关键字和一个关联的值
    map<string, int>::key_type v3;  // string
    map<string, int>::mapped_type v4;   // int
    map<string, int>::value_type v5;    // pair<const string, int> pair的关键字是const的

    // 关联容器的迭代器
    map<string, int> word_count1;
    auto it1 = word_count1.begin(); // *it1是指向一个pair<const string, int>对象的引用
    while(it1 != word_count1.end()){    // 遍历迭代器
        cout << it1->first << " occurs "
            << it1->second << " times." << endl;
        ++it1;  // 递增迭代器，移动到下一个元素
    }

    // set的迭代器是const的
    set<int> iset = {1,8,9,5};
    set<int>::iterator set_it = iset.begin();
    if(set_it != iset.end()){
        // *set_it = 42;   // 错误：set的关键字是只读的
        cout << *set_it << endl;
    }

    // 添加元素
    vector<int> ivec={2,4,6,8,2,4,6,8};
    set<int> set2;  // 空集合
    set2.insert(ivec.begin(), ivec.end());
    set2.insert({1,3,5,7,1,3,5,7});

    // 向map添加元素
    string word = "Bruce";
    map<string, size_t> word_count2;
    word_count2.insert({"Bruce", 1});
    word_count2.insert(make_pair(word, 1));
    word_count2.insert(pair<string, int>(word, 1));
    word_count2.insert(map<string, int>::value_type(word, 1));

    // 检测insert的返回值
    map<string, size_t> word_count3;
    while(cin >> word){
        // 对于不包含重复关键字的容器，添加单一元素的insert和emplace返回一个pair
        // pair的first成员是一个迭代器，指向具有给定关键字的元素
        //      second成员是一个bool值，指出元素是插入成功还是已经存在于容器中
        auto ret = word_count3.insert({word, 1});
        // ret的类型是 pair<map<string, int>::iterator, bool>
        if(!ret.second)
            ++ret.first->second;    // 递增迭代器
        /*
        ret 保存insert返回的值，是一个pair
        ret.first是pair的第一个成员，是一个map迭代器，指向具有给定关键字的元素
        ret.first-> 解引用此迭代器，提取map的元素，元素也是一个pair
        ret.first->second map中元素的值部分
        ++ret.first->second 递增此值
        */
    }

    // 向multiset或multimap添加元素
    multimap<string, string> authors;
    authors.insert({"Han", "C++入门"}); // 插入第一个元素，关键字为 Han
    authors.insert({"Han", "C++劝退"}); // 正确：添加第二个元素，关键字也是 Han
    // 对允许重复关键字的容器，接受单个元素的insert操作返回一个指向新元素的迭代器
    // 无须返回一个bool值，因为insert总是向这类容器中加入一个新元素

    // 删除元素
    string removal_word("Han");
    if(authors.erase(removal_word))
        cout << "ok: " << removal_word << " removed\n";
    else    cout << "oops: " << removal_word << " not found!\n";

    // map的下标操作
    map<string, size_t> word_count4;    // 空map
    word_count4["Anna"] = 1;    // 插入一个关键字为Anna的元素，关联值进行值初始化；然后将1赋予它

    // 访问元素
    if(word_count4.find("Anna") == word_count4.end())
        cout << "Anna is not in the map" << endl;   // 向知道一个给定关键字是否在map中，而不想改变map

    // 在multimap或multiset中查找元素
    string search_item("Han");  // 要查找的作者
    auto entries = authors.count(search_item);  // 元素的数量
    auto iter = authors.find(search_item);  // 此作者的第一本书
    while(entries){
        cout << iter->second << endl;   // 打印书名
        ++iter; // 前进到下一本书
        --entries;  // 记录已经打印了多少本书
    }

    multimap<string, string> authors2 = {
        {"Han", "abc"},
        {"Han", "efg"},
        {"LZ", "Tao"},
    };
    search_item = "Han";
    // 一种不同的面向迭代器的解决方法
    for(auto beg=authors2.lower_bound(search_item), end=authors2.upper_bound(search_item);
        beg != end; ++beg){
        cout << beg->second << endl;    // 打印书名
    }

    // equal_range函数
    for(auto pos=authors2.equal_range(search_item);
        pos.first!=pos.second; ++pos.first){
        cout << pos.first->second << endl;
    }

    return 0;
}