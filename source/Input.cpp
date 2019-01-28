#include "Input.h"

Input * Input::m_singleton = nullptr;

Input::~Input(void){
    for (unsigned int index = 0; index < this->m_keyboard.size(); index++) {
        delete this->m_keyboard[index];
    }
    this->m_keyboard.clear();
    delete this->m_events;
    SDL_QuitSubSystem(SDL_INIT_EVENTS);
}

Input * Input::getSingleton(void){
    if(!m_singleton){
        m_singleton = new Input();
    }
    return m_singleton;
}

bool Input::pollEvents(void){
    while (SDL_PollEvent(this->m_events)) {
        switch (this->m_events->type) {
        case SDL_QUIT:
            this->m_exit = true;
            break;
        case SDL_KEYUP:
        case SDL_KEYDOWN:
            for (unsigned int index = 0; index < this->m_keyboard.size(); index++) {
                if (this->m_keyboard[index]->scancode == this->m_events->key.keysym.scancode) {
                    this->m_keyboard[index]->state = static_cast<button_state>(this->m_events->key.state);
                }
            }
            break;
        default:
            break;
        }
    }
    return this->m_exit;
}

bool Input::isExitTime(void){
    return this->m_exit;
}

bool Input::isPressed(keyboard_key key){
    return (this->m_keyboard[key]->state == pressed);
}

Input::Input(void){
    if(SDL_InitSubSystem(SDL_INIT_EVENTS) == 0){
        this->m_exit = false;
        this->m_events = new SDL_Event();
        loadKeyboard();
    }
}

void Input::loadKeyboard(void){
    this->m_keyboard.resize(keyboard_total);
    this->m_keyboard[keyboard_a] = new Key(SDL_SCANCODE_A);
    this->m_keyboard[keyboard_b] = new Key(SDL_SCANCODE_B);
    this->m_keyboard[keyboard_c] = new Key(SDL_SCANCODE_C);
    this->m_keyboard[keyboard_d] = new Key(SDL_SCANCODE_D);
    this->m_keyboard[keyboard_e] = new Key(SDL_SCANCODE_E);
    this->m_keyboard[keyboard_f] = new Key(SDL_SCANCODE_F);
    this->m_keyboard[keyboard_g] = new Key(SDL_SCANCODE_G);
    this->m_keyboard[keyboard_h] = new Key(SDL_SCANCODE_H);
    this->m_keyboard[keyboard_i] = new Key(SDL_SCANCODE_I);
    this->m_keyboard[keyboard_j] = new Key(SDL_SCANCODE_J);
    this->m_keyboard[keyboard_k] = new Key(SDL_SCANCODE_K);
    this->m_keyboard[keyboard_l] = new Key(SDL_SCANCODE_L);
    this->m_keyboard[keyboard_m] = new Key(SDL_SCANCODE_M);
    this->m_keyboard[keyboard_n] = new Key(SDL_SCANCODE_N);
    this->m_keyboard[keyboard_o] = new Key(SDL_SCANCODE_O);
    this->m_keyboard[keyboard_p] = new Key(SDL_SCANCODE_P);
    this->m_keyboard[keyboard_q] = new Key(SDL_SCANCODE_Q);
    this->m_keyboard[keyboard_r] = new Key(SDL_SCANCODE_R);
    this->m_keyboard[keyboard_s] = new Key(SDL_SCANCODE_S);
    this->m_keyboard[keyboard_t] = new Key(SDL_SCANCODE_T);
    this->m_keyboard[keyboard_u] = new Key(SDL_SCANCODE_U);
    this->m_keyboard[keyboard_v] = new Key(SDL_SCANCODE_V);
    this->m_keyboard[keyboard_w] = new Key(SDL_SCANCODE_W);
    this->m_keyboard[keyboard_x] = new Key(SDL_SCANCODE_X);
    this->m_keyboard[keyboard_y] = new Key(SDL_SCANCODE_Y);
    this->m_keyboard[keyboard_z] = new Key(SDL_SCANCODE_Z);
    this->m_keyboard[keyboard_space] = new Key(SDL_SCANCODE_SPACE);
    this->m_keyboard[keyboard_enter] = new Key(SDL_SCANCODE_RETURN);
    this->m_keyboard[keyboard_esc] = new Key(SDL_SCANCODE_ESCAPE);
}