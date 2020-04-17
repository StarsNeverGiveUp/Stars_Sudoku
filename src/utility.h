#ifndef _UTILITY_H_
#define _UTILITY_H_
#include <cstdlib>
#include <ctime>
#include <cassert>

inline void clear(void)
{
    system("cls");
}

//not real random,return number between [begin,end]
inline unsigned int random(int begin, int end)
{
    assert(end >= begin && begin >= 0);
    srand(time(NULL));
    return (unsigned int)rand() % (end - begin + 1) + begin;
}

#endif