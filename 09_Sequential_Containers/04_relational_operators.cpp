#include <vector>
#include <list>
#include <deque>
#include <array>
#include <forward_list>
#include <iostream>
#include <string>
using namespace std;

/**
 * @brief 容器大小操作与关系运算符
 * 每个容器类型都有三个与大小相关的操作(forward_list支持max_size和empty，但不支持size)：
 * 1. size：返回容器中元素的数目
 * 2. empty：当size为0时返回布尔值true，否则返回false
 * 3. max_size：返回一个大于等于该类型容器所能容纳的最大元素数的值。
 * 
 * 每个容器都支持相等运算符(==和!=)，除了无序关联容器外的所有容器都支持关系运算符(>,>=,<.<=)：
 * - 比较两个容器实际上是进行 元素的逐对比较
 * - 容器的关系运算符使用元素的关系运算符完成比较，只有当其元素类型也定义了相应的比较运算符时，
 *      才可以使用关系运算符比较两个容器
 */

int main()
{
    vector<int> v1 = {1,3,5,7,9,12};
    vector<int> v2 = {1,3,9};
    vector<int> v3 = {1,3,5,7};
    vector<int> v4 = {1,3,5,7,9,12};
    v1 < v2;    // true; v1和v2在元素[2]处不同且v1[2]<v2[2]
    v1 < v3;    // false; 所有元素都相等，但v3中元素数目更少
    v1 == v4;   // true
    v1 == v2;   // false; v2元素数目比v1少




    return 0;
}