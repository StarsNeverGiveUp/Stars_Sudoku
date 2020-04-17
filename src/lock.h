#ifndef _LOCK_
#define _LOCK_

#include<vector>
#include "common.h"

using namespace std;

class BaseLock
{
public:
    BaseLock(int size) : _size_(size), _block_(vector<lockPoint_t>(size)){}
   
    /**
     * 检查 在 (x,y)处 填入 value 是否有效， 此时value已经被转化为int类型了；
     */

    virtual void init(const string & s) = 0;

    virtual lockPoint_t get(point_t key, int value) = 0;

    /**
     * 在(x,y)处 填入value
     */
    virtual bool set(point_t key, int value) = 0;

    /**
     * 删去(x,y)处的value
     */

    virtual bool erase(point_t key, int value) = 0;
    virtual ~BaseLock();
   
protected:
    vector<lockPoint_t> _block_;
    int _size_;
    
};


class ColumnLock : public BaseLock
{
public:
    ColumnLock(int size) : BaseLock(size) {}
    
    void init(const string & s) override;
    lockPoint_t get(point_t key, int value) override;
    bool set(point_t key, int value) override;
    bool erase(point_t key, int value) override;
    
};

class RowLock : public BaseLock
{
public:
    RowLock(int size) : BaseLock(size) {}
    
    void init(const string & s) override;
    lockPoint_t get(point_t key, int value) override;
    bool set(point_t key, int value) override;
    bool erase(point_t key, int value) override;
};

class BlockLock : public BaseLock
{
public:
    BlockLock(int size) : BaseLock(size) {}
    
    void init(const string & s) override;
    lockPoint_t get(point_t key, int value) override;
    bool set(point_t key, int value) override;
    bool erase(point_t key, int value) override;
};

class ChangeLock : public BaseLock
{
public:
    ChangeLock(int size) : BaseLock(size) {}
    
    void init(const string & s) override;
    lockPoint_t get(point_t key, int value) override;
    bool set(point_t key, int value) override;
    bool erase(point_t key, int value) override;
};

#endif