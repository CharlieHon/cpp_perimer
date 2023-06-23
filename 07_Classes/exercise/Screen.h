#ifndef SCREEN_H
#define SCREEN_H

#include <iostream>
#include <string>
#include <vector>

class Screen;

class Window_mgr{
public:
    using ScreenIndex = std::vector<Screen>::size_type;
    inline void clear(ScreenIndex);
    ScreenIndex addScreen(const Screen&);   // 想窗口添加一个Screen，返回它的编号

private:
    std::vector<Screen> screens;
};

class Screen{
    friend void Window_mgr::clear(ScreenIndex); // 练习7.32：定义Screen和Window_mgr，其中clear是Window_mgr的成员，是Screen的友元

public:
    using pos = std::string::size_type;

    Screen() = default;
    Screen(pos ht, pos wd) : height(ht), width(wd), contents(ht*wd, ' ')    {}
    Screen(pos ht, pos wd, char c) : height(ht), width(wd), contents(ht*wd, c)  {}

    char get() const    {return contents[cursor];}
    char get(pos r, pos c)  const   {return contents[r*width+c];}

    inline Screen &move(pos, pos);
    inline Screen &set(char);
    inline Screen &set(pos, pos, char);

    // 显示
    const Screen& display(std::ostream &os) const { do_display(os);   return *this;}
    Screen& display(std::ostream &os)   { do_display(os);   return *this;}

private:
    void do_display(std::ostream &os) const { os << contents;}
private:
    pos cursor = 0;
    pos height = 0, width = 0;
    std::string contents;
};

Screen& Screen::move(pos r, pos c){
    cursor = r*width + c;
    return *this;
}
Screen& Screen::set(char c){
    contents[cursor] = c;
    return *this;
}
Screen& Screen::set(pos r, pos col, char c){
    contents[r*width + col] = c;
    return *this;
}

// Window_mge::clear
void Window_mgr::clear(ScreenIndex i){
    Screen &s = screens[i];
    s.contents = std::string(s.width * s.width, ' ');
}

Window_mgr::ScreenIndex // 返回类型位于函数名之前，在类的作用域之外时，必须指明它是哪个类的成员
Window_mgr::addScreen(const Screen &s){
    screens.push_back(s);
    return screens.size() - 1;
}

#endif