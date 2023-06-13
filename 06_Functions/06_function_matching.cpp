#include <iostream>

using namespace std;

void f();
void f(int);
void f(int, int);
void f(double, double = 3.14);
// f(5.6); // 调用 f(double, double)

/**
 * 候选函数：1.与被调用函数同名；2.其声明在调用点可见
 * ↓
 * 可选函数：1.其形参数量与本次调用提供的实参数量相等
 *          2.每个实参的类型与对应的形参类型相同，或者能转换成形参的类型
 */

/**
 * @实参类型转换等级
 * 1. 精确匹配：
 *      - 实参类型和形参类型相同
 *      - 实参从数组类型或函数类型转换成对应的指针类型
 *      - 向实参添加顶层const或者从实参删除顶层const
 * 2. 通过const转换实现的匹配
 * 3. 通过类型提升实现的匹配
 * 4. 通过算术类型转换或指针转换实现的匹配
 * 5. 通过类类型转换实现的匹配
 */

void ff(int);
void ff(short);
// ff('a');    // char提升成int；调用ff(int)

void mainp(int, int);
// mainp('a', 'z');    // 类型提升
// mainp(55.4, 3.14);  // 算术类型转换

int main()
{
    
    return 0;
}