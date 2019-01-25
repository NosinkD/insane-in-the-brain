#include "SpriteRenderer.h"

SpriteRenderer::SpriteRenderer(void):Component(){

    this->m_file = File::getSingleton();

    vertices[0] = -0.5f;
    vertices[1] = -0.5f;
    vertices[2] = 0.0f;
    vertices[3] = 0.5f;
    vertices[4] = -0.5f;
    vertices[5] = 0.0f;
    vertices[6] = 0.0f;
    vertices[7] = 0.5f;
    vertices[8] = 0.0f;
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO); 
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    vertexShaderSource = this->m_file->readAllText("resources/vertex.shader");

    vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);
}

SpriteRenderer::~SpriteRenderer(void){

}