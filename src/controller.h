#ifndef _CONTROLLER_H_
#define _CONTROLLER_H_

#include "logic.h"
#include "scene.h"
#include "common.h"

class NormalController
{
public:

    NormalController(NormalScene & scene, NormalLogic & logic);

    NormalController& operator<< (char c);
   
    void doSomething();
    
private:
    int _size_;
    int _blank_;
    char _oper_;

    NormalLogic & _logic_;
    NormalScene & _scene_;

    point_t _cursor_;
    warningPoint_t _warning_;
    

    void set(char value);
    void erase();
    void undoWarning();
    void show();
    bool isComplete();
};

#endif