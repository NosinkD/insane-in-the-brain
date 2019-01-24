#include "Video.h"

Video * Video::m_singleton = nullptr;

Video::~Video(void){

}

Video * Video::getSingleton(void){
    if (!m_singleton) {
        m_singleton = new Video();
    }
    return m_singleton;
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height){
    glViewport(0, 0, width, height);
}

bool Video::createWindow(const char * title, int width, int height){
    this->m_window = glfwCreateWindow(width, height, title, nullptr, nullptr);
    if(this->m_window){
        glfwMakeContextCurrent(this->m_window);
        glfwSetFramebufferSizeCallback(this->m_window, framebuffer_size_callback);
        if (gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
            return true;
        }
        // ERROR - glad unable to initalize.
    }
    // ERROR - glfwCreateWindows fails
    glfwTerminate();
    return false;
}

bool Video::isExitTime(void){
    return glfwWindowShouldClose(this->m_window);
}

void Video::clearWindow(void){
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
}

void Video::updateWindow(void){
    glfwSwapBuffers(this->m_window);
}

GLFWwindow * Video::getWindow(void){
    return this->m_window;
}

Video::Video(void){
    if(glfwInit()){
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, OPEN_GL_MAJOR_VERSION);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, OPEN_GL_MINOR_VERSION);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__ 
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif
    } else {
        // ERROR - glfwInit unable to initialize.
    }
}