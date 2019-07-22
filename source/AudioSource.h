#ifndef AUDIOSOURCE_H
#define AUDIOSOURCE_H

#include "Internal.h"

#include "Component.h"

class AudioSource : public Component {

CLASS_DECLARATION(AudioSource);

public:

    AudioSource(void);
    ~AudioSource(void);

};

#endif // AUDIOSOURCE_H