#include <iostream>
#include <string>
#include <vector>
/**
 * @brief 类的其他特性
 * - 无须在声明和定义的地方同时说明 inline，最好只在类外部定义的地方说明inline，这样更容易理解
 * - 可变数据成员(mutable data number)永远不会是const，即使它是const对象的成员。
 *  一个const成员函数可以改变一个可变成员的值。
 * - 类内初始值必须使用 = 初始化形式(初始化Screen的数据成员时)  或者    花括号括起来的直接初始化形式(如初始化screens)
 * - 通过区分成员函数是否是 const 的，可以对其进行重载。
 * - 友元函数，友元类，……，友元关系不具有传递性。
 */

class Window_mgr;   // 先声明

class Screen{
    // Window_mgr的成员可以访问Screen类的私有部分
    friend class Window_mgr;    // 友元类
    // friend void Window_mgr::clear(ScreenIndex);  // Window_mgr::clear必须在Screen类之前声明
    // 表示显示器的一个窗口，包含一个用于保存Screen内容的string成员和三个string::size_type类型的成员
    // 它们分别表示光标的位置以及屏幕的高和宽。
public:
    // typedef std::string::size_type pos;  // 类型成员：用来定义类型，必须先定义后使用。
    using pos = std::string::size_type; // 因此，类型成员通常出现在类开始的地方。
    
    // 构造函数
    Screen() = default; // 合成默认的构造函数
    Screen(pos ht, pos wd, char c)  : height(ht), width(wd),    // cursor被类内初始化值为0
            contents(ht * wd, c)  {}    // string的构造函数，ht*wd个字符c
    Screen(pos ht, pos wd)  : height(ht), width(wd), contents(ht*wd, ' ')    {}

    // 返回字符
    char get() const                    // 读取光标当前位置处的字符，隐式内联
        { return contents[cursor]; }
    inline char get(pos r, pos c) const;  // 显式内联
    // 移动光标
    Screen &move(pos r, pos c);         // 能在之后被设为内联
    // 设定字符
    Screen &set(char);
    Screen &set(pos, pos, char);
    
    //打印Screen的内容
    Screen &display(std::ostream &os)
                        {   do_display(os); return *this;}
    const Screen &display(std::ostream &os)    const   // 基于const的重载
                        {   do_display(os); return *this;}
    void some_member() const;   // 记录函数被调用的次数
    size_t get_number() const {
        return access_ctr;      // 返回这个调用次数
    }

private:
    // 该函数负责显示Screen的内容
    void do_display(std::ostream &os) const {os << contents;}   // 定义一个do_display的私有成员，由它负责打印Screen的实际工作，所有display操作都将调用该函数。
    
    pos cursor = 0;
    pos height = 0, width = 0;
    std::string contents;
    mutable size_t access_ctr;  // 可变数据成员，在const对象内也能被修改
};


class Window_mgr{   // 窗口管理类，表示显示器上的一组Screen。包含一个Screen类型的vector，每个元素表示一个特定的Screen
public:
    // 窗口中每个屏幕的编号
    using ScreenIndex = std::vector<Screen>::size_type;
    // 按照编号将指定的Screen重置为空白
    void clear(ScreenIndex);

private:
    // 默认情况下，一个Window_mgr包含一个标准尺寸的空白Screen
    std::vector<Screen> screens{Screen(24, 80, ' ')};
};
void Window_mgr::clear(ScreenIndex i){
    // s是一个Screen的引用，指向想要清空的那个屏幕
    Screen &s = screens[i];
    // 将那个选定的Screen重置为空白
    s.contents = std::string(s.height * s.width, ' ');
}

int main()
{
    Screen myscreen(5, 6, 'x');
    char ch = myscreen.get();   // char get()
    std::cout << ch << std::endl;
    
    ch = myscreen.get(2, 2);    // char get(pos r, pos c)
    std::cout << ch << std::endl;

    for(int i=0; i<5; ++i){
        myscreen.some_member();
        std::cout << myscreen.get_number() << std::endl;    // 1,2,3,4,5
    }

    // 把光标移动到指定的位置，然后设置该位置的字符值
    myscreen.move(4, 0).set('#');
    std::cout << myscreen.get() << std::endl;
    
    // 调用display
    myscreen.display(std::cout);    // xxxxxxxxxxxxxxxxxxxxxxxx#xxxxx
    std::cout << std::endl;
    
    Screen myScreen(5, 3);
    const Screen blank(5, 3);
    
    myScreen.set('#').display(std::cout);   // 调用非常量版本   #
    std::cout << std::endl;
    blank.display(std::cout);   // 调用常量版本
    std::cout << std::endl;

    // 练习7.27
    Screen screen1(5, 5, 'X');
    screen1.move(4, 0).set('#').display(std::cout); // XXXXXXXXXXXXXXXXXXXX#XXXX
    std::cout << "\n";
    screen1.display(std::cout); // XXXXXXXXXXXXXXXXXXXX#XXXX
    std::cout << "\n";

    return 0;
}

inline  // 可以在函数的定义处指定 inline
Screen& Screen::move(pos r, pos c){
    pos row = r * width;    // 计算行的位置
    cursor = row + c;       // 在行内将光标移动到指定的列
    return *this;           // 以左值的形式返回对象
}

char Screen::get(pos r, pos c) const  { // 在类的内部声明成 inline
    return contents[r*width + c];   // 返回指定位置的字符
}

inline Screen& Screen::set(char c){
    contents[cursor] = c;   // 设置当前光标所在位置的新值
    return *this;   // 将 this 对象作为左值返回
}

inline Screen& Screen::set(pos r, pos col, char ch){
    contents[r*width + col] = ch;   // 设置给定位置的新值
    return *this;
}

void Screen::some_member()  const   {
    ++access_ctr;   // 保存一个计数值，用于记录成员函数被调用的次数
}