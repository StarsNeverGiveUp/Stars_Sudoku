#include <iostream>
#include "scene.h"
#include "utility.h"
#include "color.h"



using namespace std;

void NormalScene:: showGreeting()
{
    clear();
    cout << "Welcome to play this sudoku game!" << endl;
    return;
}

void NormalScene :: showChoose()
{
    clear();
    cout << "Please input a number to choose game level,as following:" << endl;
    cout << "easy(1)   medium(2)   difficulty(3)" << endl;
}

void NormalScene :: showAll()
{
    clear();
    printUnderLine();

    for(int row = 0; row < _size_; ++row)
    {
        printRow(row);
        printUnderLine(row);
    }

}

void NormalScene :: showComplete()
{
    cout << "Victory!!" << endl;
}

void NormalScene :: changeCursor(const point_t  &curPoint)
{
    _cursor_ = curPoint;
}

/**
 *  在光标处特殊化处理
 */

void NormalScene :: printUnderLine(int line)
{
    for(int col = 0; col < _size_; ++col)
    {
        if(_cursor_.y == line && _cursor_.x == col)
        {
            cout << "--^-";
        }
        else
        {
            cout << "----";
        }
    }
    cout << "-" << endl;
}

void NormalScene :: printRow(int row)
{
    cout << "| ";
    for(int col = 0; col < _size_; ++col)
    {
        if(_board_[row * _size_ + col].warning)
        {
            std::cout << Color::Modifier(Color :: FG_LIGHT_RED);
        }
        else
        {
            std::cout << Color::Modifier(_board_[row * _size_ + col].color);
        }

        cout << _board_[row * _size_ + col].value 
             << Color::Modifier(Color::RESET) 
             << " | ";
    }
    cout << endl;
}

void NormalScene :: set(point_t key, char value, Color :: Code c)
{
    _board_[key.y * _size_ + key.x].value = value;
    _board_[key.y * _size_ + key.x].color = c;
}

char NormalScene::get(point_t key)
{
    return _board_[key.y * _size_ + key.x].value;
}

void NormalScene :: setWarning(point_t key, bool w)
{
    _board_[key.y * _size_ + key.x].warning = w;
}

void NormalScene :: erase(point_t key)
{
    _board_[key.y * _size_ + key.x].value = ' ';
}

void NormalScene :: init(const string & s)
{
    int length = s.size();

    point_t key;

    for(int i = 0; i < length; ++i)
    {
        key.y = i / _size_;
        key.x = i % _size_;

        if(s[i] != ' ')
        {
            set(key, s[i]);
        }
    }
}

NormalScene & NormalScene :: getInstance()
{
    static NormalScene scene;
    return scene;
}