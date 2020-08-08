#include "../include/vertexarray.h"
#include <iostream>

VertexArray::VertexArray(){

    glGenVertexArrays(1 , &id);
    glBindVertexArray(id);  

}
VertexArray::~VertexArray(){
    glDeleteVertexArrays(1,&id);
}

void VertexArray::addBuffer(const VertexBuffer &buffer, const VertexBufferLayout &layout){
    bind();
    buffer.bind();  
    const auto &elements = layout.getElements();
    unsigned int offset = 0;

    for(int i = 0; i < elements.size(); i++){
        auto element = elements[i];
        glEnableVertexAttribArray(i);
        glVertexAttribPointer(i, element.count , element.type, element.normalized, layout.getStride(), (const void*)offset);
        offset += (element.count * element.size);
    }                   
}

void VertexArray::bind() const{
    glBindVertexArray(id);
}

void VertexArray::unbind() const{
    glBindVertexArray(0);
}
