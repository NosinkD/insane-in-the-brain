#ifndef VIDEO_H
#define VIDEO_H

#include "Internal.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Video {

public:

    ~Video(void);
    static Video * getSingleton(void);

    bool createWindow(const char * title, int width, int height);

    bool isExitTime(void);

    void clearWindow(void);
    void updateWindow(void);

protected:

private:

    Video(void);
    static Video * m_singleton;

    GLFWwindow * m_window;

};

#endif // VIDEO_H