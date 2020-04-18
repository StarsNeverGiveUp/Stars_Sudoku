#ifndef _CONTROLLER_H_
#define _CONTROLLER_H_

#include "logic.h"
#include "scene.h"
#include "common.h"
class BaseController
{
public:
    virtual ~BaseController(){}
};

class NormalController : public BaseController
{
public:
    
    friend istream& operator>>(istream & in, NormalController& controller);
   
    NormalController(NormalScene & scene, NormalLogic & logic) : _oper_(0),_scene_(scene), _logic_(logic), _size_(9){}

    void doSomething();
    void show();
    void init();
    
    void getCom(char key)
    {
        _oper_ = key;
    }

    
    virtual ~NormalController(){}

private:
    int _size_;
    NormalLogic & _logic_;
    NormalScene & _scene_;
    point_t _cursor_;
    warningPoint_t _warning_;
    char _oper_;

    void set(char value);
    void erase();
    void undoWarning();
};

#endif