#include "lock.h"


void BaseLock :: init(const string& s)
{
    int length = s.size();

    point_t key;

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



void ColumnLock :: set(point_t key, char value)
{
    _block_[key.x * _size_ + value - '1'] = lockPoint_t(key, true);
}

void ColumnLock :: erase(point_t key, char value)
{
    _block_[key.x * _size_ + value - '1'].valid = false;
}

lockPoint_t ColumnLock :: get(point_t key, char value)
{
    return _block_[key.x * _size_ + value - '1'];
}

/**
 * 行锁函数
 */


void RowLock :: set(point_t key, char value)
{
    _block_[key.y * _size_ + value - '1'] = lockPoint_t(key, true);
}

void RowLock :: erase(point_t key, char value)
{
    _block_[key.y * _size_ + value - '1'].valid = false;
}

lockPoint_t RowLock :: get(point_t key, char value)
{
    return _block_[key.y * _size_ + value - '1'];
}

/**
 *  块锁函数
 */ 

void BlockLock :: set(point_t key, char value)
{
    _block_[((key.y - key.y % 3 + key.x / 3) * _size_) + value - '1'] = lockPoint_t(key, true);
}

void BlockLock :: erase(point_t key, char value)
{
    _block_[((key.y - key.y % 3 + key.x / 3) * _size_) + value - '1'].valid = false;
}

lockPoint_t BlockLock :: get(point_t key, char value)
{
    return _block_[((key.y - key.y % 3 + key.x / 3) * _size_) + value - '1'];
}

/**
 *  固定锁
 */

void ChangeLock :: set(point_t key, char value)
{
    _block_[key.y * _size_ + key.x] = lockPoint_t(key, true);
}

void ChangeLock :: erase(point_t key, char value)
{
   _block_[key.y * _size_ + key.x].valid = false;
}

lockPoint_t ChangeLock :: get(point_t key, char value)
{
    return _block_[key.y * _size_ + key.x];
}