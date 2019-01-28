#ifndef INPUT_H
#define INPUT_H

#include "Internal.h"

#include "Video.h"

enum keyboard {
    keyboard_esc = GLFW_KEY_ESCAPE,
    keyboard_a = GLFW_KEY_A,
    keyboard_s = GLFW_KEY_S,
    keyboard_d = GLFW_KEY_D,
    keyboard_w = GLFW_KEY_W
};

class Input {

public:

    ~Input(void);
    static Input * getSingleton(void);

    void pollEvents(void);

    bool isPressed(keyboard key);

protected:

private:

    Input(void);
    static Input * m_singleton;

    GLFWwindow * m_window;

};

#endif // INPUT_H