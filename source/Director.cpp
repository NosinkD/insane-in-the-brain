#include "Director.h"

Director * Director::m_singleton = nullptr;

Director * Director::getSingleton(void){
    if (!m_singleton) {
        m_singleton = new Director();
    }
    return m_singleton;
}

Director::~Director(void){
    for(unsigned int index = 0; index < this->m_scenes.size(); index++){
        delete this->m_scenes[index];
    }
    this->m_scenes.clear();
}

void Director::addScene(Scene * scene){
    this->m_scenes.push_back(scene);
}

void Director::load(int index){
    this->m_current_scene = index;
    this->m_scenes[this->m_current_scene]->onLoad();
}

void Director::update(void){
    this->m_scenes[this->m_current_scene]->onUpdate();
}

void Director::render(void){
    this->m_scenes[this->m_current_scene]->onRender();
}

bool Director::isExitTime(void){
    return this->m_scenes[this->m_current_scene]->isExit();
}

Director::Director(void){
    this->m_current_scene = -1;
}