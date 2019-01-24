#ifndef TRANSFORM_H
#define TRANSFORM_H

#include "includes_std.h"

#include "Component.h"

#include "Vector3.h"

class Transform : public Component {

CLASS_DECLARATION(Transform);

public:

    Transform(void);
    ~Transform(void);

    Vector3 position;
    Vector3 rotation;
    Vector3 scale;

};

#endif // TRANSFORM_H