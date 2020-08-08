#include <../include/vertexbuffer.h>

VertexBuffer::VertexBuffer(const float  * vertices , unsigned int size){

    glGenBuffers(1, &id);
    glBindBuffer(GL_ARRAY_BUFFER, id);
    glBufferData(GL_ARRAY_BUFFER, size , vertices,  GL_STATIC_DRAW);
}


VertexBuffer::~VertexBuffer(){
    glDeleteBuffers(1, &id);
}
void VertexBuffer::bind() const{
    glBindBuffer(GL_ARRAY_BUFFER, id);
}

void VertexBuffer::unbind() const{

    glBindBuffer(GL_ARRAY_BUFFER, 0);
}