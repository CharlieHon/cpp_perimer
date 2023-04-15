#include <iostream>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

int main()
{
    // 练习3.37：下面程序的含义，程序的输出结果是什么
    /*
    * 程序含义是输出数组中的每个元素，直到遇到空字符
    * 但是ca结尾没有'\0'，扫面完数组后程序不能正常结束
    */
    const char ca[] = {'h', 'e', 'l', 'l', 'o'};
    const char *cp = ca;    // cp是指向ca首元素的指针
    while(*cp){     // 解引用得到ca中的元素，该元素非空(空字符)持续循环
        cout << *cp << endl;    // 输出该元素
        ++cp;       // 指针递增，指向下一个元素
    }

    // 练习3.38
    /*
    - 两个指针(指向同一个数组)相减可以表示两个指针(在同一个数组中)的距离
    - 指针加或减去一个整数，表示指针向后或向前移动到某个位置
    - 指针相加并没有逻辑上的意义，因此两个指针不能相加
    */

   // 练习3.39
    string s1 = "hello";
    string s2 = "beautiful";
    if(s1 > s2)  cout << "s1 > s2" << endl;
    else if(s1 < s2) cout << "s1 < s2" << endl;
    else     cout << "s1 == s2" << endl;
    // 比较C风格字符串用strcmp，此处略

    // 练习3.40
    const char ca1[] = "hello";
    const char ca2[] = "world";
    char ca3[100];
    strcpy(ca3, ca1);   // 把ca1拷贝给ca3
    strcat(ca3, " ");   // 在ca3末尾添加空格
    strcat(ca3, ca2);   // 将ca2拼接到ca3
    for(char c : ca3)
        cout << c;
    cout << endl;   // hello world

    // 练习3.41：编写一段程序，用整型数组初始化一个vector对象
    int arr[] = {2,0,0,8};
    vector<int> vi1(begin(arr), end(arr));
    // 练习3.42：将含有整数元素的vector对象拷贝给一个整型数组
    vector<int> vi2{1,2,3,4,5,6,7,8,9,10};
    int arr2[10];
    for(int i=0; i<vi2.size(); ++i){
        arr2[i] = vi2[i];
    }
    for(int x : arr2)
        cout << x << " ";
    cout << endl;
    
    return 0;
}