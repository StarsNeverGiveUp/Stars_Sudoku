#ifndef _LOGIC_H_
#define _LOGIC_H_

#include "scene.h"
#include "lock.h"

class BaseLogic
{
public:
    virtual ~BaseLogic();
};


class NormalLogic : public BaseLogic
{
public:

    NormalLogic(int choice, int size = 9);
    vector<point_t> get(point_t key, char value);
    void set(point_t key, char value);
    bool isChangeable(point_t key, char value);
    const string & getInit();
    
    virtual ~NormalLogic();

private:

    int level;
    int _size_;
    int _blank_;
    string _init_;
    ColumnLock Clock;
    RowLock Rlock;
    BlockLock Block;
    ChangeLock Chlock;

    void randomErase();
    void initLock();
    
    
};

#endif