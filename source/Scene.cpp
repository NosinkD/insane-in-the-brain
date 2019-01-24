#include "Scene.h"

Scene::Scene(void){
    this->m_input = Input::getSingleton();
    this->m_exit = false;
}

Scene::~Scene(void){
    this->m_input = nullptr;
}

void Scene::onLoad(void){
    load();
}

void Scene::onUpdate(void){
    input();
    update();
}

void Scene::onRender(void){
    render();
}

void Scene::exit(void){
    this->m_exit = true;
}

bool Scene::isExit(void){
    return this->m_exit;
}

void Scene::load(void){
}

void Scene::update(void){
}

void Scene::render(void){
}

void Scene::input(void){
}