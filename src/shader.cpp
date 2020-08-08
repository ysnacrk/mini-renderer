#include <../include/glad/glad.h>

#include<../include/shader.h>
#include <iostream>
#include <fstream>

Shader::Shader(const char * vertexPath, const char* fragmentPath){

    std::ifstream vertexSource(vertexPath);
    std::ifstream fragmentSource(fragmentPath);
    std::string vertexCode;
    std::string fragmentCode;


    if(!vertexSource || !fragmentSource){
        std::cout << (vertexSource ? "Fragment file doesn't exist" : "Vertex file doesn't exist");
    }
    else{
        std::string line;
        while(getline(vertexSource, line))
            vertexCode += line + "\n";
    
        while(getline(fragmentSource, line))
            fragmentCode += line + "\n";
    }   

    id = createShader(vertexCode, fragmentCode);
}


unsigned int Shader::createShader(const std::string vertexShader , const std::string fragmentShader){

    unsigned int programId = glCreateProgram();
    unsigned int vertexShaderId = compileShader(GL_VERTEX_SHADER, vertexShader);
    unsigned int fragmentShaderId = compileShader(GL_FRAGMENT_SHADER, fragmentShader);
    

    glAttachShader(programId, vertexShaderId);
    glAttachShader(programId, fragmentShaderId);

    glLinkProgram(programId);
    glValidateProgram(programId);

    glDeleteShader(vertexShaderId);
    glDeleteShader(fragmentShaderId);


    int success;
    glGetProgramiv(programId, GL_LINK_STATUS, &success);
    if(!success){

        char infoLog[1024];
        glGetProgramInfoLog(programId, 1024, NULL, infoLog);
        std::cout << "Error occured linking program :" << infoLog << std::endl;
        glDeleteProgram(programId);
        return 0;
    }
    return programId;
}   


unsigned int Shader::compileShader(unsigned int type , std::string shaderCode){

    unsigned int id = glCreateShader(type);
    const char * code = shaderCode.c_str();
    glShaderSource(id, 1, &code, nullptr);
    glCompileShader(id);

    int success;
    glGetShaderiv(id, GL_COMPILE_STATUS, &success);
    if(!success){

        char infoLog[1024];
        glGetShaderInfoLog(id, 1024 , nullptr, infoLog); 
        std::cout<<"Error occured compile shader : "<<(type == GL_VERTEX_SHADER ?  "VERTEX_SHADER" : "FRAGMENT_SHADER" )<<infoLog<<std::endl;
        glDeleteShader(id);
        return 0;
    }

    return id;

}



void Shader::setUniform4f(const char* name , float v0, float v1, float v2, float v3){
    int location = glGetUniformLocation(id, name);
    if(location == -1){
        std::cout << "Error occured ,"<<name<<"variables not found !"<<std::endl;
    }
    else{
        glUniform4f(location, v0, v1, v2, v3);
    }
}

void Shader::setUniformMat4f(const char* name, const glm::mat4 &matrix){
    int location = glGetUniformLocation(id, name);
    if(location == -1){
        std::cout << "Error occured ,"<<name<<" variable not found !"<<std::endl;
    }
    else{
        glUniformMatrix4fv(location, 1, GL_FALSE, &matrix[0][0]);
    }
}


void Shader::useProgram(unsigned int program) const{
    glUseProgram(program);
}

void Shader::unbind() const{
    glUseProgram(0);
}