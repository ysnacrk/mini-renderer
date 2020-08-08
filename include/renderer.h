#include <glad/glad.h>
#include <iostream>
#include "shader.h"
#include "indexbuffer.h"
#include "vertexarray.h"

class Renderer {

    public:
        Renderer();
        ~Renderer();
        
        void draw(const VertexArray &vertexArray, const IndexBuffer &indexBuffer , const Shader &shader) const;
        void clear();
        void meshStateChanged(unsigned int);
};