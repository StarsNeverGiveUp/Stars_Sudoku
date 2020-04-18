/**
 * 程序分为 表示层、逻辑层、控制层；
 * 分别构建表示对象，逻辑对象，控制对象
 */
#include <iostream>
#include "scene.h"
#include "logic.h"
#include "controller.h"
#include "common.h"

#include <conio.h>

static const int SIZE = 9;

using namespace std;

istream& operator>>(istream & in, NormalController& controller)
{
    in >> controller._oper_;
    return in;
}

int main(int argc, char* argv[])
{
    NormalScene scene(SIZE);
    
    scene.showGreeting();
    system("pause");
    scene.showChoose();

    int choice = 0;

    while(!(cin >> choice) || choice < 1 || choice > 3)
    {
        cout << "please input a valid value!" << endl;
        scene.showChoose();
    }

    NormalLogic logic(choice);
    NormalController controller(scene, logic);

    controller.init();
    
    controller.show();
   
    while(1)
    {
        controller.getCom(_getch());
        controller.doSomething();
    }




}