#include "lock.h"


void BaseLock :: init(const string& s)
{
    int length = s.size();

    point_t  key;

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

/**
 * 列锁函数
 */



void ColumnLock :: set(const point_t & key, char value)
{
    _block_[key.x * _size_ + value - '1'] = lockPoint_t(key, true);
}

void ColumnLock :: erase(const point_t & key, char value)
{
    _block_[key.x * _size_ + value - '1'].valid = false;
}

lockPoint_t ColumnLock :: get(const point_t & key, char value)
{
    return _block_[key.x * _size_ + value - '1'];
}

/**
 * 行锁函数
 */


void RowLock :: set(const point_t & key, char value)
{
    _block_[key.y * _size_ + value - '1'] = lockPoint_t(key, true);
}

void RowLock :: erase(const point_t & key, char value)
{
    _block_[key.y * _size_ + value - '1'].valid = false;
}

lockPoint_t RowLock :: get(const point_t & key, char value)
{
    return _block_[key.y * _size_ + value - '1'];
}

/**
 *  块锁函数
 */ 

void BlockLock :: set(const point_t & key, char value)
{
    _block_[((key.y - key.y % 3 + key.x / 3) * _size_) + value - '1'] = lockPoint_t(key, true);
}

void BlockLock :: erase(const point_t & key, char value)
{
    _block_[((key.y - key.y % 3 + key.x / 3) * _size_) + value - '1'].valid = false;
}

lockPoint_t BlockLock :: get(const point_t & key, char value)
{
    return _block_[((key.y - key.y % 3 + key.x / 3) * _size_) + value - '1'];
}

/**
 *  固定锁
 */

void ChangeLock :: set(const point_t & key, char value)
{
    _block_[key.y * _size_ + key.x] = lockPoint_t(key, true);
}

void ChangeLock :: erase(const point_t & key, char value)
{
   _block_[key.y * _size_ + key.x].valid = false;
}

lockPoint_t ChangeLock :: get(const point_t & key, char value)
{
    return _block_[key.y * _size_ + key.x];
}