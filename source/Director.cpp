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
    this->p_input->pollEvents();
    this->m_scenes[this->m_current_scene]->onUpdate();
}

void Director::render(void){
    this->p_video->clearWindow();
    this->m_scenes[this->m_current_scene]->onRender();
    this->p_video->updateWindow();
}

bool Director::isExitTime(void){
    return (this->m_scenes[this->m_current_scene]->isExit() || this->p_input->isExitTime());
}

Director::Director(void){
    this->p_video = Video::getSingleton();
    this->p_input = Input::getSingleton();
    this->m_current_scene = -1;
}