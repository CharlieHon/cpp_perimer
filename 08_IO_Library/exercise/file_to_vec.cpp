#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int fileToVector(const string &fileName, vector<string> &svec){
    fstream inFile(fileName);
    if(!inFile)
        return 1;
    string s;
    while(getline(inFile, s))   // 按行输出
        svec.push_back(s);
    if(inFile.eof())
        return 2;
    if(inFile.bad())
        return 3;
    if(inFile.fail())
        return 4;

    return 2;
}

int main()
{
    string fileName;
    cout << "Please enter the file name:" << endl;
    cin >> fileName;
    vector<string> svec;
    switch (fileToVector(fileName, svec))
    {
    case 1:
        cout << "error: can not open the file:" << fileName << endl;
        break;
    case 2:
        cout << "Success!" << endl;
        break;
    case 3:
        cout << "error: system failure." << endl;
        break;
    case 4:
        cout << "error: read failure." << endl;
        break;
    }
    cout << "The contents in the vector: ";
    for(const string &s : svec){
        cout << s << endl;
    }
    cout << "Totally " << svec.size() << " row(s)." << endl;
    return 0;
}