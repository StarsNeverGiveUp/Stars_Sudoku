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

    stLockPoint() = default;
    stLockPoint(const point_t &p, bool b) : point_t(p), valid(b){}

} lockPoint_t;

typedef struct stWarningPoint : public lockPoint_t
{
    char value;
} warningPoint;

typedef struct stBoardPoint
{
    char value;
    bool warning;
    Color :: Code color;
} boardPoint_t;




#endif