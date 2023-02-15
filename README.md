# sierpinski-triangle-opengl

Basic drawing of sierpinski triangle in c++ with OpenGL free library.

## Compilation

The program can be compiled attaching three files main.cpp drawing.cpp and main.h and OpenGL libraries.
Like this example.
```
  g++ main.cpp drawing.cpp -lGL -lglut -o triangle
```
## Execution
The program can recieve one parameter and is the limit depth of generations of triangles.
By example.
```
./triangle 7
```
If theres not input the **default  limit depth is 5**.
