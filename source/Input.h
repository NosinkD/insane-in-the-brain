#ifndef INPUT_H
#define INPUT_H

#include "Internal.h"

enum button_state {
    pressed = SDL_PRESSED, released = SDL_RELEASED
};

enum keyboard_key {
    keyboard_a, keyboard_b, keyboard_c, keyboard_d, keyboard_e, keyboard_f, keyboard_g, keyboard_h, keyboard_i, keyboard_j, keyboard_k, keyboard_l, keyboard_m, keyboard_n, keyboard_o, keyboard_p, keyboard_q, keyboard_r, keyboard_s, keyboard_t, keyboard_u, keyboard_v, keyboard_w, keyboard_x, keyboard_y, keyboard_z,
    keyboard_space, keyboard_enter, keyboard_esc,
    keyboard_total
};

struct Key {
    SDL_Scancode scancode;
    button_state state;
    Key(SDL_Scancode scancode) {
        this->scancode = scancode;
    }
};

class Input {

public:

    ~Input(void);
    static Input * getSingleton(void);

    bool pollEvents(void);

    bool isExitTime(void);

    bool isPressed(keyboard_key key);

protected:

private:

    Input(void);
    static Input * m_singleton;

    void loadKeyboard(void);

    bool m_exit;
    SDL_Event * m_events;

    std::vector<Key*> m_keyboard;

};

#endif // INPUT_H