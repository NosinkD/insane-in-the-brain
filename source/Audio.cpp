#include "Audio.h"

Audio * Audio::m_singleton = nullptr;

Audio::~Audio(void){

}

Audio * Audio::getSingleton(void){
    if(!m_singleton){
        m_singleton = new Audio();
    }
    return m_singleton;
}

Audio::Audio(void){

}