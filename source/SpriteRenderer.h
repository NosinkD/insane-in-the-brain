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

protected:

private:

    Color m_color;

    float vertices[9];
    unsigned int VBO;
    unsigned int vertexShader;
    unsigned int fragmentShader;
    unsigned int shaderProgram;
    const char * vertexShaderSource;
    const char * fragmentShaderSource;
    int  success;
    char infoLog[512];

    File * m_file;

};

#endif // SPRITE_RENDERER_H