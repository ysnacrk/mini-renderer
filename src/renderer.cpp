#include<../include/renderer.h>


Renderer::Renderer(){

}

Renderer::~Renderer(){

}


void Renderer::draw(const VertexArray &vertexArray, const IndexBuffer &indexBuffer , const Shader &shader) const{

    vertexArray.bind();
    indexBuffer.bind();
    shader.useProgram(shader.id);
    glDrawArrays(GL_TRIANGLES, 0, 42);
}

void Renderer::clear(){

    glClear(GL_COLOR_BUFFER_BIT);
    
}

void Renderer::meshStateChanged(unsigned int value){

    switch (value){
        case 1:
            glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        case 2:
            glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
        case 3:
            glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);
    }
}