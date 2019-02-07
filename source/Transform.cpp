#include "Transform.h"

Transform::Transform(void):Component(){
    position = { 0,0,0 };
    rotation = { 0,0,0 };
    scale = { 1,1,1 };
}

Transform::~Transform(void){
}