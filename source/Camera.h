#ifndef CAMERA_H
#define CAMERA_H

#include "Internal.h"

#include "Component.h"

class Camera : public Component {

CLASS_DECLARATION(Camera);

public:

    Camera(void);
    ~Camera(void);

};

#endif // CAMERA_H