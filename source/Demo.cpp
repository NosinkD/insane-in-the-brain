#include "Demo.h"

Demo::Demo(void):Scene(){
    obj.addComponent<SpriteRenderer>();
}

Demo::~Demo(void){

}

void Demo::load(void){

}

void Demo::update(void){

}

void Demo::render(void){
    obj.getComponent<SpriteRenderer>().render();
}

void Demo::input(void){
    if(this->m_input->isPressed(keyboard_esc)){
        exit();
    }
}