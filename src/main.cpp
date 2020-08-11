#include <../include/glad/glad.h>
#include <GLFW/glfw3.h>
#include<iostream>
#include "../include/renderer.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <../src/imgui/imgui.h>
#include <../src/imgui/imgui_impl_glfw_gl3.h>
#include <../include/utils.h>


int main(void)
{
    if (!glfwInit()){
        std::cout << "Error occured initialized object "<<std::endl;
        return -1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    // being window 
    GLFWwindow* window = glfwCreateWindow(SCR_HEIGHT, SCR_HEIGHT, "Mini Renderer", NULL, NULL);
    if (!window)
    {
        std::cout << "Error occured creating window "<<std::endl;
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    glfwSetCursorPosCallback(window, mouse_callback);
    glfwSetScrollCallback(window, scroll_callback);


    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Error occured to initialize GLAD" << std::endl; 
        return -1;
    }    

    std::cout << glGetString(GL_VERSION)<<std::endl;
    float positions[] = {
        -0.5f, -0.5f, -0.5f,  
         0.5f, -0.5f, -0.5f,  
         0.5f,  0.5f, -0.5f,  
         0.5f,  0.5f, -0.5f,  
        -0.5f,  0.5f, -0.5f,  
        -0.5f, -0.5f, -0.5f,  

        -0.5f, -0.5f,  0.5f, 
         0.5f, -0.5f,  0.5f, 
         0.5f,  0.5f,  0.5f, 
         0.5f,  0.5f,  0.5f, 
        -0.5f,  0.5f,  0.5f, 
        -0.5f, -0.5f,  0.5f, 

        -0.5f,  0.5f,  0.5f, 
        -0.5f,  0.5f, -0.5f, 
        -0.5f, -0.5f, -0.5f, 
        -0.5f, -0.5f, -0.5f, 
        -0.5f, -0.5f,  0.5f, 
        -0.5f,  0.5f,  0.5f, 
         0.5f,  0.5f,  0.5f, 
         0.5f,  0.5f, -0.5f, 
         0.5f, -0.5f, -0.5f, 
         0.5f, -0.5f, -0.5f, 
         0.5f, -0.5f,  0.5f, 
         0.5f,  0.5f,  0.5f, 

        -0.5f, -0.5f, -0.5f, 
         0.5f, -0.5f, -0.5f, 
         0.5f, -0.5f,  0.5f, 
         0.5f, -0.5f,  0.5f, 
        -0.5f, -0.5f,  0.5f, 
        -0.5f, -0.5f, -0.5f, 

        -0.5f,  0.5f, -0.5f, 
         0.5f,  0.5f, -0.5f, 
         0.5f,  0.5f,  0.5f, 
         0.5f,  0.5f,  0.5f, 
        -0.5f,  0.5f,  0.5f, 
        -0.5f,  0.5f, -0.5f,
    };

    unsigned int indices[] = {
        0 , 1 , 2,
        3 , 1 , 2
    };

    VertexArray vao;

    VertexBuffer vertexbuffer(positions, sizeof(positions));
    IndexBuffer  indexbuffer(indices,  sizeof(indices)/(sizeof(unsigned int)));
  
    VertexBufferLayout layout;
    layout.push(GL_FLOAT, 3);
    vao.addBuffer(vertexbuffer, layout);

    Shader program("../shaders/vertex.glsl" , "../shaders/fragment.glsl");
    program.useProgram(program.id);

    vao.unbind();
    vertexbuffer.unbind();
    indexbuffer.unbind();
    program.unbind();

    Renderer renderer;

    ImGui::CreateContext();
    ImGui_ImplGlfwGL3_Init(window, true);
    ImGui::StyleColorsDark();

    std::vector<glm::vec3> cubeList;
    glm::vec3 translation;
    ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

    cubeList.push_back(glm::vec3(0.0, 0.0, 0.0));

    //glm::mat4 projection = glm::perspective(glm::radians(45.0f), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);

    while (!glfwWindowShouldClose(window))
    {

        float currentFrame = glfwGetTime();
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;

        // input
        // -----
        processInput(window);

        renderer.clear();
        ImGui_ImplGlfwGL3_NewFrame();
        //begin view matrix processing

        glm::mat4 projection = glm::perspective(glm::radians(45.0f), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);
        glm::mat4 view = camera.GetViewMatrix();

        for(int i = 0; i < cubeList.size() ; i++){
            glm::mat4 model = glm::translate(glm::mat4(1.0f), cubeList[i]);
            glm::mat4 mvp = projection * view * model;
            program.useProgram(program.id);
            program.setUniformMat4f("mvp", mvp);
            renderer.draw(vao, indexbuffer, program);
        }

        program.setUniform4f("out_color", clear_color.x, clear_color.y, clear_color.z, 1.0);

        {
            ImGui::Begin("Mesh State");
            if (ImGui::Button("Line Mode"))
                    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
            else if (ImGui::Button("Fill Mode"))
                    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
            else if (ImGui::Button("Point Mode"))
                    glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);
            ImGui::End();
        }
        {
            ImGui::Begin("Add Cube");
            ImGui::SliderFloat3("Position", &translation.x, -20.0f, 20.0f);               
            if (ImGui::Button("Add")){
                cubeList.push_back(translation);
            }
            ImGui::End();
        }
        {
            ImGui::Begin("Information");
            ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
            ImGui::End();
        }


        ImGui::Render();
        ImGui_ImplGlfwGL3_RenderDrawData(ImGui::GetDrawData());

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    ImGui_ImplGlfwGL3_Shutdown();
    ImGui::DestroyContext();
    glDeleteProgram(program.id);  

    return 0;
}


