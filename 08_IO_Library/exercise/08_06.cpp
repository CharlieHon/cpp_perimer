#include "Sales_data.h"
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char **argv)
{
    ifstream input(argv[1]);
    cout << "The input file is " << string(argv[1]) << endl;
    Sales_data total;
    if(read(input, total)){
        Sales_data trans;
        while(read(input, trans)){
            if(trans.isbn() == total.isbn())
                total.combine(trans);
            else{
                print(cout, total) << endl;
                total = trans;
            }
        }
        print(cout, total) << endl;
    }else
        cerr << "No data." << endl;

    return 0;
}