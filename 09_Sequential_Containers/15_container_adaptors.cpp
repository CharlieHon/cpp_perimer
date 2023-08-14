#include <iostream>
#include <stack>
#include <vector>
#include <list>
#include <queue>
#include <deque>

using namespace std;

/**
 * @brief 容器适配器
 * 是一个封装了序列容器的一个类模板，它在一般序列容器的基础上提供了一些不同的功能。
 * 容器适配器都不存在迭代器
 * 
 * stack栈
 * 1.后进先出。其删除和插入操作只能在容器的一端进行。
 * 2.stack的底层容器可以是任何标准的容器类模板或者其他特定的类容器。
 *  但这些容器必须支持以下操作：empty, back, push_back, pop_back, size
 * 3.vector，list，deque都可以作为stack的底层容器。默认情况下，是deque
 * 
 * queue队列
 * 1.先进先出，其中从容器的一端插入，另一端提取元素。
 * 2.底层容器时标准容器类模板之一，也可以用自定义容器类。
 *  容器必须支持：empty、front、back、push_back、pop_front、size
 * 3.vector、list和deque都开。默认情况下，使用deque
 * 
 * priority_queue优先队列
 * 1.优先队列是容器适配器，根据排序标准，第一个元素总是它所包含的元素中优先级最高的
 * 2.优先队列默认形成大堆
 * 3.优先队列的元素从顶部弹出，顶部的优先级最高
 * 4.vector和deque满足需求。默认使用vector
 * 
 */

int main()
{
    // stack栈
    stack<int> s;   // 调用构造函数，构造空栈
    s.push(1);  // 在栈顶插入元素
    s.push(2);
    s.push(3);
    
    cout << s.size() << endl;   // 3，返回元素个数

    while(!s.empty()){
        cout << s.top() << endl;    // 获取栈顶元素
        s.pop();    // 弹出栈顶元素
    }

    // queue队列
    queue<int> q;   // 创建空队列
    q.push(1);  // 在queue末尾创建一个元素
    q.push(2);
    q.push(3);

    cout << q.size() << endl;   // 3
    cout << q.back() << endl;   // 3
    cout << q.front() << endl;  // 1

    while(!q.empty()){
        cout << q.front() << endl;
        q.pop();    // 删除queue首元素
    }

    // priority_queue优先队列
    priority_queue<int> pq1;
    pq1.push(8);
    pq1.push(4);
    pq1.push(6);
    pq1.push(2);
    pq1.push(10);

    cout << "priority_queue" << endl;
    cout << pq1.size() << endl; // 5

    while(!pq1.empty()){    // 10 8 6 4 2
        cout << pq1.top() << endl;
        pq1.pop();
    }

    int arr[] = {8, 4, 6, 2, 10};   // 迭代器构造
    priority_queue<int> pq2(arr, arr+sizeof(arr)/sizeof(int));  // 10 8 6 4 2

    return 0;
}