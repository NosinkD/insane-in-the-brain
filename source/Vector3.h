#ifndef VECTOR3_H
#define VECTOR3_H

struct Vector3{

    float x, y, z;

    Vector3(void){
        this->x = 0.0f; this->y = 0.0f; this->z = 0.0f;
    }

    Vector3(float x, float y):Vector3(){
        this->x = x; this->y = y;
    }

    Vector3(float x, float y, float z):Vector3(x, y){
        this->z = z;
    }

};

#endif // VECTOR3_H