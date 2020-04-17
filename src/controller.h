#ifndef _CONTROLLER_H_
#define _CONTROLLER_H_

#include "logic.h"
#include "scene.h"
#include "common.h"
class BaseController
{
public:
    virtual ~BaseController();
};

class NormalController : public BaseController
{
public:
    
    friend istream& operator>>(istream & in, NormalController& controller);
   
    NormalController(NormalScene & scene, NormalLogic & logic);

    void doSomething();
    void show();

    
    virtual ~NormalController();

private:
    int _size_;
    NormalLogic & _logic_;
    NormalScene & _scene_;
    point_t _cursor_;
    char oper;

    void setValue(int value);
};

#endif