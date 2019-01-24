#include "Demo.h"

Demo::Demo(void){

}

Demo::~Demo(void){

}

void Demo::load(void){
    std::cout << "Load" << std::endl;
}

void Demo::update(void){
    std::cout << "Update" << std::endl;
}

void Demo::render(void){
    std::cout << "Render" << std::endl;
    exit();
}

void Demo::input(void){
    std::cout << "Input" << std::endl;
}