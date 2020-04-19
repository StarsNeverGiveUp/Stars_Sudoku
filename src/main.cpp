/**
 * 程序分为 表示层、逻辑层、控制层；
 * 分别构建表示对象，逻辑对象，控制对象
 */
#include <iostream>
#include "scene.h"
#include "logic.h"
#include "controller.h"
#include "common.h"
#include "utility.h"

#include <conio.h>

using namespace std;

int main(int argc, char* argv[])
{
    NormalScene & scene = NormalScene :: getInstance();
    
    scene.showGreeting();
    pause();
    scene.showChoose();

    /**
     *  choice 必须为 0, 1, 2, 3 这几个数
     *  其中0 为调试难度
     */

    int choice = 0;
    while(!(cin >> choice) || choice < 0 || choice > 3)
    {
        cout << "please input a valid value!" << endl;
        scene.showChoose();
    }

    NormalLogic logic(choice);
    NormalController controller(scene, logic);

    while(1)
    {
        controller << getch();
        controller.doSomething();
    }




}