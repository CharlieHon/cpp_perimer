#include <iostream>
#include <string>
#include <cstring>
#include <vector>
using namespace std;

// 使用类型别名简化多维数组的指针
using int_array1 = int[4];   // int_array是一个含有4个int的数组类型
typedef int int_array2[4];      // 等价的typedef声明

int main()
{
    int ia1[3][4];   // 大小为3的数组，每个元素是含有4个元素的数组
    // 大小为10的数组，它的每个元素都是大小为20的数组
    // 这些数组的元素是含有30个整数的数组
    int arr[10][20][30] = {};   // 将所有元素初始化为0

    // 多维数组的初始化
    int ia2[3][4] = {   // 三个元素，每个元素都是大小为4的数组
        {0,1,2,3},      // 第1行的初始值
        {4,5,6,7},
        {8,9,10,11}
    };

    // 其中内嵌的花括号并非必须的
    int ia3[3][4] = {0,1,2,3,4,5,6,7,8,9,10,11};    // 与上等价
    // 类似于一维数组，在初始化多维数组时也并非所有元素的值都必须包含在初始化列表之内
    int ia4[3][4] = {{0}, {4}, {8}};    // 显式地初始化每行地首元素，其他未列出的元素执行默认初始化
    // 在这种情况下如果再省略内层的花括号，结果就不一样了
    int ix[3][4] = {0, 3, 6, 9};    // 显式地初始化第1行，其他元素执行值初始化

    // 多维数组的下标引用
    ia4[2][3] = arr[0][0][0];   // 用arr的首元素为ia4最后一行的最后一个元素赋值
    int (&row)[4] = ia4[1];     // 把row绑定到ia4的第二个4元素数组上

    // 程序中经常会用到两层嵌套的for循环来处理多维数组的元素
    constexpr size_t rowCnt = 3, colCnt = 4;
    int ia[rowCnt][colCnt]; // 12个未初始化的元素
    // 对于每一行
    for(size_t i=0; i<rowCnt; ++i){
        // 对于行内的每一列
        for(size_t j=0; j<colCnt; ++j){
            // 将元素的位置索引作为它的值
            ia[i][j] = i*colCnt + j;
        }
    }

    // 使用范围for循环
    int ia5[rowCnt][colCnt];
    size_t cnt = 0;
    for(auto &row : ia5){       // 因为要改变元素的值，所以声明成引用类型
        for(auto &col : row){
            col = cnt;      // 功能同上
            ++cnt;
        }
    }

    // 将循环中控制变量声明成引用类型，避免数组被自动转成指针
    // for(auto row : ia5){
    //     for(auto col : row)     // 报错：row是指向ia5中每个数组的指针
    //         cout << col << endl;
    // }

    // 指针和多维数组
    int (*ip)[4] = ia5;  // ip指向含有4个整数的数组 等价于 int (*ip)[4] = &ia6[0];
    ip = &ia5[2];       // ip指向ia6的尾元素

    for(auto p=ia5; p!=ia5+3; ++p){     // p是指向含有4个元素数组的指针
        for(auto q=*p; q!=*p+4; ++q)    // 解引用p，得到含有4个元素的数组，所以*p可转换为指向该数组首元素的指针，q为指向每个元素的指针
            cout << *q << " ";  // 解引用q得到数组中的元素
        cout << endl;
    }

    // 使用标准库函数begin和end也能实现同样的功能
    for(auto p=begin(ia5); p!=end(ia5); ++p){
        for(auto q=begin(*p); q!=end(*p); ++q)
            cout << *q << " ";
        cout << endl;
    }

    // 使用类型别名简化多维数组的指针
    for(int_array1 *p=ia5; p!=ia5+3; ++p){
        for(int *q=*p; q!=*p+4; ++q)
            cout << *q << " ";
        cout << endl;
    }


    return 0;
}