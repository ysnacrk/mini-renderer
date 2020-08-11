# Mini Renderer

Mini renderer is an opengl application that creates simple objects (square, circle, sphere, etc.). Contains the following libraries:

 - [glfw](https://github.com/glfw/glfw) Create window and some input events
 - [glad](https://github.com/Dav1dde/glad) Easy pointer complex opengl functions
 - [glm](https://github.com/g-truc/glm) Math and matrix operations
 - [ImGui](https://github.com/ocornut/imgui) Easy-to-use graphical interface library, for moving objects, etc.

## Installation

You need to install your device `glfw` and `glm` libraries and  imgui and glad already exist 
These links can help you [glfw](https://www.glfw.org/download.html) [glm](https://glm.g-truc.net/0.9.9/index.html)

## Build and Run

Create build folder in the project directory and go into it

```
mkdir build
cd build
cmake ..
make 
./OpenGLModel

```

## Gallery

![Screen Shot](/assests/screenshot1.png)

### Camera Movement

![Screen Shot](/assests/screenshot2.gif)

## TO-DO

- [x] Dynamically generate cubes
- [ ] Rotate, translate, and scale matrix operations
- [x] Camera movement
- [ ] Select specific object
- [ ] Import and export mesh files

