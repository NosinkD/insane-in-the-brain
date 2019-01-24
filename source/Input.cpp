#include "Input.h"

Input * Input::m_singleton = nullptr;

Input::~Input(void){
    this->m_window = nullptr;
}

Input * Input::getSingleton(void){
    if(!m_singleton){
        m_singleton = new Input();
    }
    return m_singleton;
}

void Input::pollEvents(void){
    glfwPollEvents();
}

bool Input::isPressed(keyboard key){
    if(glfwGetKey(this->m_window, static_cast<int>(key)) == GLFW_PRESS){
        return true;
    }
    return false;
}

Input::Input(void){
    this->m_window = Video::getSingleton()->getWindow();
}