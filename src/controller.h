#ifndef _CONTROLLER_H_
#define _CONTROLLER_H_

#include "logic.h"
class BaseController
{
public:
    virtual ~BaseController();
};

class NormalController : public BaseController
{
public:
    NormalController(NormalLogic & logc) : _logic_(logic){}

    friend istream& operator>>(istream & in, NormalController& controller);
    {
        in >> controller.oper;
        return in;
    }

    
    virtual ~NormalController();

private:
    NormalLogic & _logic_;
    char oper;
};

#endif