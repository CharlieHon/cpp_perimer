#include <iostream>
#include <fstream>

using namespace std;

/**
 * @brief 管理输出缓冲
 * 每个输出流都管理一个缓冲区，用来保存程序读写的数据。导致缓冲刷新(即，数据真正写到输出设备或文件)的原因有很多：
 * 1. 程序正常结束，作为main函数的return操作的一部分，缓冲刷新被执行。
 * 2. 缓冲区满时，需要刷新缓冲，而后新的数据继续写入缓冲区。
 * 3. 可以使用操作符endl来显式刷新缓冲区。
 * 4. 在每个输出操作之后，对cerr是设置unitbuf的，因此写到cerr的内容都是立即刷新的。
 * 5. 一个输出流可能被关联到另一个流。在这种情况下，当读写被关联的流时，关联到的流的缓冲区会被刷新。例如，默认情况下，cin和cerr都
 * 关联到cout。因此，读cin或写cerr都会导致cout的缓冲区被刷新。
 */

int main()
{
    // 刷新输出缓冲区
    cout << "hi" << endl;   // 输出hi和一个换行，然后刷新缓冲区
    cout << "hi" << flush;  // 输出hi，然后刷新缓冲区，不附加任何额外字符
    cout << "hi" << ends;   // 输出hi和一个空字符，然后刷新缓冲区

    // unitbuf操作符
    cout << unitbuf;    // 使用unitbuf操作符，在每次输出操作后都刷新缓冲区。它告诉流在接下来的读写操作之后都进行依次flush操作
    // 任何输出都立即刷新，无缓冲
    cout << nounitbuf;  // 回到正常的刷新方式

    // 关联输入和输出流
    int ival;
    cin >> ival;    // 标准库将cout和cin关联在一起，因此该语句会导致cout缓冲区被刷新
    // tie有两个重载的版本：1.不带参数，返回指向输出流的指针；2.接收一个指向ostream的指针，将自己关联到此ostream。
    // cin.tie(&cout); // 仅用作展示：标准库将cin和cout关联在一起
    // old_tie指向当前关联到cin的流(如果有的话)
    ostream *old_tie = cin.tie(nullptr);    // cin不再与其他流关联
    cin.tie(&cerr); // 不提倡，因此cin应关联到cout
    cin.tie(old_tie);   // 重建cin和cout间的正常关联

    return 0;
}