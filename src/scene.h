#ifndef _SCENE_H_
#define _SCENE_H_

#include<string>
#include<vector>

#include "common.h"

using namespace std;

class BaseScene
{
public:
    virtual ~BaseScene();
};


class NormalScene : public BaseScene
{
public:
    NormalScene(int size);
    void showGreeting();
    void showChoose();
    void showAll();
    void changeCursor(const point_t & curPoint);
    virtual ~NormalScene();

private:
    int _size_;
    point_t _cursor_; //当前的光标位置
    vector<boardPoint_t> _board_; //棋盘

    void printUnderLine(int line = -1);
    void printRow(int row);
};


#endif