#ifndef _LOCK_
#define _LOCK_

#include<vector>
#include "common.h"

using namespace std;

class BaseLock
{
public:
    BaseLock(int size) : _size_(size), _block_(vector<lockPoint_t>(size * size)){}
   
    void init(const string & s);
  
    virtual lockPoint_t get(const point_t & key, char value) = 0;
    virtual void set(const point_t & key, char value) = 0;
    virtual void erase(const point_t & key, char value) = 0;
  
    virtual ~BaseLock(){}
   
protected:

    int _size_; 
    vector<lockPoint_t> _block_;
    
};


class ColumnLock : public BaseLock
{
public:
    ColumnLock(int size) : BaseLock(size) {}
    
    lockPoint_t get(const point_t & key, char value) override;
    void set(const point_t & key, char value) override;
    void erase(const point_t & key, char value) override;
    
};

class RowLock : public BaseLock
{
public:
    RowLock(int size) : BaseLock(size) {}
    
    lockPoint_t get(const point_t & key, char value) override;
    void set(const point_t & key, char value) override;
    void erase(const point_t & key, char value) override;
};

class BlockLock : public BaseLock
{
public:
    BlockLock(int size) : BaseLock(size) {}
    
    lockPoint_t get(const point_t & key, char value) override;
    void set(const point_t & key, char value) override;
    void erase(const point_t & key, char value) override;
};

class ChangeLock : public BaseLock
{
public:
    ChangeLock(int size) : BaseLock(size) {}
    
    lockPoint_t get(const point_t & key, char value) override;
    void set(const point_t & key, char value) override;
    void erase(const point_t & key, char value) override;
};

#endif