#ifndef _LOGIC_H_
#define _LOGIC_H_


class BaseLogic
{
public:
    virtual ~BaseLogic();
};


class NormalLogic : public BaseLogic
{
public:
    virtual ~NormalLogic();
};

#endif