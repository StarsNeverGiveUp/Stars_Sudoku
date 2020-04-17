#ifndef _SCENE_H_
#define _SCENE_H_

#include<string>
#include<vector>

#include "common.h"

using namespace std;

class BaseScene
{
public:
    virtual ~BaseScene(){}
};


class NormalScene : public BaseScene
{
public:
    NormalScene(int size) : _size_(size), _board_(vector<boardPoint_t>(size * size)){}
    void showGreeting();
    void showChoose();
    void showAll();
    void changeCursor(const point_t & curPoint);
    void init(const string &s);
    void set(point_t key, char value, Color :: Code c= Color :: FG_GREEN);
    void setWarning(point_t key, bool w);
    void erase(point_t key);
    virtual ~NormalScene(){}

private:
    int _size_;
    point_t _cursor_; //当前的光标位置
    vector<boardPoint_t> _board_; //棋盘

    void printUnderLine(int line = -1);
    void printRow(int row);
};


#endif