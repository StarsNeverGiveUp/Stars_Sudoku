#ifndef _SCENE_H_
#define _SCENE_H_

#include<string>
#include<vector>

#include "common.h"

using namespace std;

class NormalScene
{
public:
    static NormalScene & getInstance();
    
    void showGreeting();
    void showChoose();
    void showAll();
    void showComplete();
    
    void changeCursor(const point_t & curPoint);
    void init(const string &s);
   
    void set(point_t key, char value, Color :: Code c= Color :: FG_GREEN);
    char get(point_t key);
    void erase(point_t key);
    void setWarning(point_t key, bool w);

private:
    int _size_;
    point_t _cursor_; //当前的光标位置
    vector<boardPoint_t> _board_; //棋盘

    NormalScene(int size = SIZE) : _size_(size), _board_(vector<boardPoint_t>(size * size)){}
    void printUnderLine(int line = -1);
    void printRow(int row);
};


#endif