#ifndef _COMMON_H_
#define _COMMON_H_

#include "color.h"

typedef struct stPoint
{
    int x;
    int y;

    stPoint() : stPoint(0,0){}
    stPoint(int a, int b) : x(a), y(b) {} 
} point_t;


typedef struct stLockPoint : public stPoint
{
    bool valid;

    stLockPoint() : point_t(), valid(false){}
    stLockPoint(const point_t &p, bool b) : point_t(p), valid(b){}

} lockPoint_t;

typedef struct stWarningPoint
{
    bool valid;
    char value;
    point_t key;
} warningPoint_t;

typedef struct stBoardPoint
{
    char value;
    bool warning;
    Color :: Code color;
    stBoardPoint() : value(' '), warning(false){};
} boardPoint_t;




#endif