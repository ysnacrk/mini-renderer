#include <glad/glad.h>
#include "../include/vertexbuffer.h"
#include "../include/vertexbufferlayout.h"

class VertexArray
{

private:
    unsigned int id;

public:
    VertexArray();
    ~VertexArray();

    void addBuffer(const VertexBuffer &buffer, const VertexBufferLayout &layout);
    void bind() const;
    void unbind() const;
};