#ifndef _SCENE_H_
#define _SCENE_H_

#include<string>

class BaseScene
{
    virtual void show() = 0;
    ~BaseScene();
};


class NormalScene : public BaseScene
{
    virtual void show();

    void show(const string & );

    void show(int i);
};


#endif