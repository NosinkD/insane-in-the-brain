#ifndef SCENE_H
#define SCENE_H

#include "Internal.h"

#include "Input.h"

class Scene {

public:

    Scene(void);
    virtual ~Scene(void);

    void onLoad(void);
    void onUpdate(void);
    void onRender(void);

    void exit(void);
    bool isExit(void);

protected:

    virtual void load(void);
    virtual void update(void);
    virtual void render(void);

    virtual void input(void);

    Input * m_input;

private:

    bool m_exit;

};

#endif // SCENE_H