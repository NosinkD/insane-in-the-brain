#ifndef AUDIO_H
#define AUDIO_H

#include "Internal.h"

class Audio {

public:

    ~Audio(void);
    static Audio * getSingleton(void);

protected:

public:

    Audio(void);
    static Audio * m_singleton;

};

#endif // AUDIO_H