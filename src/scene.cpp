#include <iostream>
#include "scene.h"
#include "utility.h"
#include "color.h"



using namespace std;

void NormalScene:: showGreeting()
{
    cout << "Welcome to play this sudoku game!" << endl;
    return;
}

void NormalScene :: showChoose()
{
    cout << "Please input number to choose game level,as following:" << endl;
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
        cout << "-" << endl;
    }
}

void NormalScene :: printRow(int row)
{
    cout << "| ";
    for(int col = 0; col < _size_; ++col)
    {
        std::cout << Color::Modifier(_board_[row * _size_ + col].color) 
                  << _board_[row * _size_ + col].value 
                  << Color::Modifier(Color::RESET) 
                  << " | ";
    }
    cout << endl;
}