#include<iostream>
#include <glm/glm.hpp>


class Shader {
    public:
        unsigned int id;
        Shader(const char * vertexPath , const char * fragmentPath);
        void useProgram(unsigned int program) const;
        void setUniform4f(const char * name, float v0, float v1, float v2, float v3);
        void setUniformMat4f(const char * name, const glm::mat4 &matrix);
        void unbind() const;
    private:

        unsigned int createShader(const std::string vertexShader , const std::string fragmentShader);
        unsigned int compileShader(unsigned int type , std::string shaderCode);

};