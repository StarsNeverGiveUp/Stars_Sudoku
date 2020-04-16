/**
 * 程序分为 表示层、逻辑层、控制层；
 * 分别构建表示对象，逻辑对象，控制对象
 */
#include <iostream>
#include "scene.h"
#include "logic.h"
#include "controller.h"

using namespace std;

int main(int argc, char* argv[])
{
    NormalScene scene;
    

    scene.showGreeting();
    system("pause");
    scene.showChoose();

    int choice = 0;

    while(!(cin >> choice))
    {
        cout << "please input a valid value!"
        scene.showChoose();
    }
    
    NormalLogic logic(scene, choice);
    NormalController controller(logic);




}