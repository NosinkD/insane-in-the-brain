
#include "Director.h"
#include "Video.h"

#include "Demo.h"

#define DEMO_SCENE 0

Video * sVideo;
Director * sDirector;

void init(void);
void quit(void);

int main(){

    init();

    sDirector->addScene(new Demo());

    sDirector->load(DEMO_SCENE);

    while(!sDirector->isExitTime()){

        sDirector->update();

        sDirector->render();

    }

    quit();
    
    std::cin.clear();
    std::cin.sync();
    std::cin.get();

    return 0;
}

void init(void){
    sVideo = Video::getSingleton();
    sDirector = Director::getSingleton();
}

void quit(void){
    delete sDirector;
    delete sVideo;
}