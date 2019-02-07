#ifndef SPRITE_RENDERER_H
#define SPRITE_RENDERER_H

#include "Internal.h"

#include "Component.h"

#include "Color.h"
#include "Video.h"
#include "File.h"
#include "Vector3.h"

class SpriteRenderer : public Component {

CLASS_DECLARATION(SpriteRenderer);

public:

    SpriteRenderer(void);
    ~SpriteRenderer(void);

    void render(void);

protected:

private:

    Color m_color;

    unsigned int VBO, VAO, EBO;
    unsigned int shaderProgram;

    File * m_file;

};

#endif // SPRITE_RENDERER_H