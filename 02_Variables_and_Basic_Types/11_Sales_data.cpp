#include <iostream>
#include <string>
#include "Sales_data.h"

// struct Sales_data{
//     std::string bookNo;         //书籍ISBN编号
//     unsigned units_sold = 0;    //销量
//     double revenue = 0.0;       //总价
// };

int main()
{
    Sales_data data1, data2;
    //读入1笔交易：ISBN、销售数量、单价
    std::cin >> data1.bookNo >> data1.units_sold;
    double price = 0;
    std::cin >> price;
    //计算销售收入
    data1.revenue = data1.units_sold * price;
    //读入第2笔交易
    std::cin >> data2.bookNo >> data2.units_sold >> price;
    data2.revenue = data2.units_sold * price;

    //输出两个Sales_data对象的和
    if(data1.bookNo == data2.bookNo){
        unsigned totalCnt = data1.units_sold + data2.units_sold;
        double totalRevenue = data1.revenue + data2.revenue;
        //输出：ISBN、总销售量、总销售额、平均价格
        std::cout << data1.bookNo << " " << totalRevenue << " "
                    << " ";
        if(totalCnt)
            std::cout << totalRevenue/totalCnt << std::endl;
        else
            std::cout << "(no sales)" << std::endl;
    }else{
        std::cerr << "Data must refer to the same ISBN"
                    << std::endl;
        return -1;
    }

    return 0;
}
