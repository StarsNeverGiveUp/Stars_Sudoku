
#include "logic.h"
#include "map"
#include "utility.h"

NormalLogic :: NormalLogic(int choice, int size) 
: level(choice), _size_(size), _blank_(0),
  _init_(),
  Clock(size), Rlock(size), Block(size), Chlock(size)
{
    switch(choice)
    {
        case 0 :
            _blank_ = 1;
            break;
        case 1 :
            _blank_ = 20;
            break;
        case 2 :
            _blank_ = 35;
            break;
        case 3 :
            _blank_ = 50;
            break;
        default :
            cout << "难度输入错误" << endl;
    }
    
    /* 数独模板 */
    static string map_pattern = 
        "ighcabfde"
        "cabfdeigh"
        "fdeighcab"
        "ghiabcdef"
        "abcdefghi"
        "defghiabc"
        "higbcaefd"
        "bcaefdhig"
        "efdhigbca"; 
    /**
     *  完成随机映射的过程
     */

    vector<char> mapping(_size_);

    for (int i = 0; i < 9; ++i)
    {
        mapping[i] = ('a' + i);
    }
    map<char, char> hash_map;

    for(int i = 0; i < _size_; ++i)
    {
        int r = random(0, mapping.size() - 1);
        char key = mapping[r];
        mapping.erase(mapping.begin() + r);
        hash_map[key] = i + '1';
    }

    for(int i = 0; i < _size_ * _size_; ++i)
    {
        _init_ += hash_map[map_pattern[i]];
    }
    
    randomErase();

    initLock();
}


bool NormalLogic :: isChangeable(point_t key, char value)
{
    return !Chlock.get(key, value).valid;
}

void NormalLogic :: set(point_t key, char value)
{
    Clock.set(key, value);
    Rlock.set(key, value);
    Block.set(key, value);
    return;
}

void NormalLogic::erase(point_t key, char value)
{
    if (value == ' ')
    {
        return;
    }
    Clock.erase(key, value);
    Rlock.erase(key, value);
    Block.erase(key, value);
    return;
}

vector<point_t> NormalLogic :: get(point_t key, char value)
{
    vector<point_t> ret;
    lockPoint_t temp;

    temp = Clock.get(key, value);
   
    if(temp.valid)
    {
        ret.push_back(point_t(temp.x,temp.y));
    }

    temp = Rlock.get(key, value);
   
    if(temp.valid)
    {
        ret.push_back(point_t(temp.x,temp.y));
    }

    temp = Block.get(key, value);
   
    if(temp.valid)
    {
        ret.push_back(point_t(temp.x,temp.y));
    }

    return ret;
}

/**
 *  @brief 擦除多个点
 */

void NormalLogic ::  randomErase()
{
    vector<int> v(_size_ * _size_);

    for(int i = 0; i < _size_ * _size_; ++i)
    {
        v[i] = i;
    }

    for(int i = 0; i < _blank_; ++i)
    {
        int r = random(0, v.size() - 1);
        _init_[v[r]] = ' ';
        v.erase(v.begin() + r);
        
    }
}

void NormalLogic :: initLock()
{
    Clock.init(_init_);
    Rlock.init(_init_);
    Block.init(_init_);
    Chlock.init(_init_);
}

const string & NormalLogic :: getInit()
{
    return _init_;
}

int NormalLogic :: getBlank()
{
    return _blank_;
}