#include <glad/glad.h>

class VertexBuffer {

    private:
        unsigned int id;
    public:
        VertexBuffer(const float * vertices, unsigned int size);
        ~VertexBuffer();
        void bind() const;
        void unbind() const;
};