
#include "Director.h"
#include "Video.h"
#include "Input.h"

#include "Demo.h"

#define DEMO_SCENE 0

Video * sVideo;
Input * sInput;
Director * sDirector;

void init(void);
void quit(void);

int main(int argc, char * argv[]) {
    argc = 0; argv = nullptr;

    init();

    sDirector->addScene(new Demo());

    sDirector->load(DEMO_SCENE);

    while(!sDirector->isExitTime()){

        sDirector->update();

        sDirector->render();

    }

    quit();

    return 0;
}

void init(void){
    sVideo = Video::getSingleton();
    sVideo->createWindow("Test", 800, 600);
    sInput = Input::getSingleton();
    sDirector = Director::getSingleton();
}

void quit(void){
    delete sDirector;
    delete sInput;
    delete sVideo;
}