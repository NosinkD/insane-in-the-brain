#pragma once

#include "Scene.h"

class Demo : public Scene {

public:

    Demo(void);
    ~Demo(void);

    void load(void);
    void update(void);
    void render(void);

protected:

    void input(void);

private:

};