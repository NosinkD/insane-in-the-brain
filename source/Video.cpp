#include "Video.h"

Video * Video::m_singleton = nullptr;

Video::~Video(void){
    SDL_DestroyWindow(this->m_window);
    this->m_context = nullptr;
    SDL_QuitSubSystem(SDL_INIT_VIDEO);
}

Video * Video::getSingleton(void){
    if (!m_singleton) {
        m_singleton = new Video();
    }
    return m_singleton;
}

bool Video::createWindow(const char * title, int width, int height, screen_flag flags){
    this->m_window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_OPENGL | flags);
    if (this->m_window != nullptr) {
        SDL_GetWindowSize(this->m_window, &this->m_screen_width, &this->m_screen_height);
        this->m_context = SDL_GL_CreateContext(this->m_window);
        if (this->m_context != nullptr) {
            glewExperimental = GL_TRUE;
            if(glewInit() == 0){
                if (SDL_GL_SetSwapInterval(1) < 0){
                    return false;
                }
            } else {
                return false;
            }
        } else {
            return false;
        }
    } else {
        return false;
    }
    return true;
}

void Video::clearWindow(void){
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);
}

void Video::updateWindow(void){
    SDL_GL_SwapWindow(this->m_window);
}

void Video::setBackgroundColor(unsigned char r, unsigned char g, unsigned char b, unsigned char a){
    this->m_background_color = { r, g, b, a };
}

Video::Video(void){
    if (SDL_InitSubSystem(SDL_INIT_VIDEO) == 0) {
        SDL_GL_SetAttribute( SDL_GL_CONTEXT_MAJOR_VERSION, OPEN_GL_MAJOR_VERSION ); 
        SDL_GL_SetAttribute( SDL_GL_CONTEXT_MINOR_VERSION, OPEN_GL_MINOR_VERSION ); 
        SDL_GL_SetAttribute( SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE );
        this->m_screen_width = 0;
        this->m_screen_height = 0;
        this->m_background_color = { 255, 255, 255, 255 };
    } else {
        // error
    }
}