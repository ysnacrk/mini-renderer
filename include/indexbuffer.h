#include <glad/glad.h>

class IndexBuffer {

    private:
        unsigned int id;
        unsigned int m_count; // ne kadar indis var

    public:
        IndexBuffer(const unsigned int * indices, unsigned int count);
        ~IndexBuffer();
        void bind() const;
        void unbind() const;

        unsigned int getCount() { return m_count; }

};