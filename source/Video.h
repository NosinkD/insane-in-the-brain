#ifndef VIDEO_H
#define VIDEO_H

#include "Internal.h"

#include "Color.h"

enum screen_flag {
    screen_fullscreen = SDL_WINDOW_FULLSCREEN,
    screen_fullscreen_windowed = SDL_WINDOW_FULLSCREEN_DESKTOP,
    screen_open_gl = SDL_WINDOW_OPENGL,
    sceen_vulkan = SDL_WINDOW_VULKAN,
    screen_hidden = SDL_WINDOW_HIDDEN,
    screen_borderless = SDL_WINDOW_BORDERLESS,
    screen_resizable = SDL_WINDOW_RESIZABLE,
    screen_minimized = SDL_WINDOW_MINIMIZED,
    screen_maximized = SDL_WINDOW_MAXIMIZED,
    screen_input_grabbed = SDL_WINDOW_INPUT_GRABBED,
    screen_high_dpi = SDL_WINDOW_ALLOW_HIGHDPI,
    screen_shown = SDL_WINDOW_SHOWN
};

class Video {

public:

    ~Video(void);
    static Video * getSingleton(void);

    bool createWindow(const char * title, int width, int height, screen_flag flags = screen_shown);

    void clearWindow(void);
    void updateWindow(void);

    void setBackgroundColor(unsigned char r, unsigned char g, unsigned char b, unsigned char a);

protected:

private:

    Video(void);
    static Video * m_singleton;

    SDL_Window * m_window;
    SDL_GLContext m_context;

    int m_screen_width;
    int m_screen_height;

    Color m_background_color;

};

#endif // VIDEO_H