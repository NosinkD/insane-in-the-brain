
#include "Director.h"

#include "Demo.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#define DEMO_SCENE 0

int main(){

    Director * sDirector = Director::getSingleton();

    sDirector->addScene(new Demo());

    sDirector->load(DEMO_SCENE);

    while(!sDirector->isExitTime()){

        sDirector->update();

        sDirector->render();

    }

    delete sDirector;

    std::cin.clear();
    std::cin.sync();
    std::cin.get();

    return 0;
}