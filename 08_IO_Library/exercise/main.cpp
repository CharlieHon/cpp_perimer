#include "get.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    // Test1
	cout << "Test get(istream&):" << endl;
	double dval;
	get(cin);
	cout << "Entry a value again:" << endl;
	cin >> dval;
	cout << "your data is " << dval << endl;
	cin.clear();
	cin.ignore(200, '\n');

    // Test2
	cout << "Test get(ifstream&):" << endl;
	string fileName;
	cout << "Please enter the file name:" << endl;
	cin >> fileName;
	ifstream inFile(fileName);
	get(inFile);

	return 0;
}