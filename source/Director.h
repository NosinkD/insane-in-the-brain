#ifndef DIRECTOR_H
#define DIRECTOR_H

#include "Internal.h"

#include "Scene.h"

#include "Video.h"
#include "Input.h"

class Director {

public:

    static Director * getSingleton(void);
    ~Director(void);

    void addScene(Scene * scene);

    void load(int index);
    void update(void);
    void render(void);
    
    bool isExitTime(void);

protected:

private:

    Director(void);
    static Director * m_singleton;

    int m_current_scene;
    std::vector<Scene*> m_scenes;

    Video * p_video;
    Input * p_input;

};

#endif // DIRECTOR_H