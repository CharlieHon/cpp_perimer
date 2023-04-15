#include <iostream>
using std::cout; using std::endl;
using int_array = int[4];    // int_array是含有4个元素的int数组类型

int main()
{
    int ia[3][4] = {
        {0,1,2,3},
        {4,5,6,7},
        {8,9,10,11}
    };

    // 练习3.43：编写3个不同版本的程序，令其均能输出ia的元素。
    // 在所有版本中的程序中都要直接写出数据类型，不能使用类型别名，auto，decltype
    // 1.使用范围for语句管理迭代器
    cout << "3.43 for range:" << endl;
    for(int (&row)[4] : ia){    // row是指向含有4个元素int数组的引用
        for(int col : row)      // col遍历含有4元素数组的每个元素
            cout << col << " ";
        cout << endl;
    }
    // 2.使用普通for语句，下标运算符
    cout << "3.43 for-index:" << endl;
    for(size_t i=0; i<3; ++i){
        for(size_t j=0; j<4; ++j)
            cout << ia[i][j] << " ";
        cout << endl;
    }
    // 3.使用普通for语句，用指针
    cout << "3.43 for-pointer:" << endl;
    for(int (*p)[4]=ia; p!=ia+3; ++p){  // p是指向含有4个元素数组的指针
        for(int *q=*p; q!=*p+4; ++q)    // 解引用p得到含有4个元素的数组，其名字*p即数组首元素的地址
            cout << *q << " ";
        cout << endl;
    }


    // 练习3.44：改写上一个练习中的程序，使用类型别名来代替所有循环变量的类型
    cout << "3.44 for range:" << endl;
    for(int_array &row : ia){
        for(int col : row)
            cout << col << " ";
        cout << endl;
    }
    // 2.使用普通for语句，下标运算符
    cout << "3.44 for-index:" << endl;  // 无变化
    for(size_t i=0; i<3; ++i){
        for(size_t j=0; j<4; ++j)
            cout << ia[i][j] << " ";
        cout << endl;
    }
    // 3.使用普通for语句，用指针
    cout << "3.44 for-pointer:" << endl;
    for(int_array *p=ia; p!=ia+3; ++p){
        for(int *q=*p; q!=*p+4; ++q)
            cout << *q << " ";
        cout << endl;
    }


    // 3.45：再一次改写程序，这次使用auto关键字
    cout << "3.45 for range:" << endl;
    for(auto &row : ia){    // 外层范围类型需要是引用类型
        for(auto col : row)
            cout << col << " ";
        cout << endl;
    }
    // 2.使用普通for语句，下标运算符
    cout << "3.45 for-index:" << endl;  // 无变化
    for(auto i=0; i<3; ++i){
        for(auto j=0; j<4; ++j)
            cout << ia[i][j] << " ";
        cout << endl;
    }
    // 3.使用普通for语句，用指针
    cout << "3.45 for-pointer:" << endl;
    for(auto p=ia; p!=ia+3; ++p){
        for(auto q=*p; q!=*p+4; ++q)
            cout << *q << " ";
        cout << endl;
    }

    return 0;
}