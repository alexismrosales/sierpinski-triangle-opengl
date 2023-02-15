#include <GL/glut.h>
#include "main.h"

//Limit depth
int limit_depth = 5;

int main(int argc, char** argv)
{
    //If a depth limit is given by the user
    if(argc > 1)
        limit_depth = atoi(argv[1]);
    glutInit(&argc, argv);
    glutInitWindowSize(800,800);//Initial size
    glutCreateWindow("Sierpinski triangle");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}

//Display the Sierpinski triangle
void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    //Accesing to polygon mode
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    //Drawing of Sierpinski triangle
    triangle_reflection();
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glFlush();
}