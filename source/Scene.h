#ifndef SCENE_H
#define SCENE_H

#include "includes_std.h"

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

private:

    bool m_exit;

};

#endif // SCENE_H