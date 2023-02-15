#include <GL/glut.h>
#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "main.h"
using namespace std;

//Create initial vertex and start recursion for drawing every triangle
void triangle_reflection()
{
    vector<float> vertex_1 = {-0.9,-0.9};
    vector<float> vertex_2 = {0.9,-0.9};
    vector<float> vertex_3 = {0.0,0.9};
    points_division(vertex_1, vertex_2, vertex_3,0);
}
//Getting middle points of vertex and drawing recursively
void points_division(vector<float>&p1, vector<float>&p2, vector<float>&p3, int depth)
{   
    //Base case
    if(depth >= limit_depth) 
        return;
    draw_triangle(p1,p2,p3);
    //Auxiliar vector variables to get middle points
    vector<float> aux_vector1 = {(p1[0]+p2[0])/2, (p1[1]+p2[1])/2};
    vector<float> aux_vector2 = {(p1[0]+p3[0])/2, (p1[1]+p3[1])/2};
    //Recursive call
    points_division(p1,aux_vector1,aux_vector2,depth+1);
    vector<float> aux_vector3 = {(p2[0]+p3[0])/2, (p2[1]+p3[1])/2};
    vector<float> aux_vector4 = {(p2[0]+p1[0])/2, (p2[1]+p1[1])/2};
    points_division(p2,aux_vector3,aux_vector4,depth+1);
    vector<float> aux_vector5 = {(p3[0]+p2[0])/2, (p3[1]+p2[1])/2};
    vector<float> aux_vector6 = {(p3[0]+p1[0])/2, (p3[1]+p1[1])/2};
    points_division(p3,aux_vector5,aux_vector6,depth+1);
}
//Draws a single triangle with random color edges
void draw_triangle(vector<float>&p1, vector<float>&p2, vector<float>&p3)
{
    //Generating random seed
    srand( (unsigned)time( NULL ) );
    //Giving random color to the triangle
    glColor3f((float) rand()/RAND_MAX, (float) rand()/RAND_MAX, (float) rand()/RAND_MAX);
    //Begins drawing of triangle
    glBegin(GL_TRIANGLES);
    glVertex2f(p1[0],p1[1]);//(x1,y1)
    glVertex2f(p2[0],p2[1]);//(x2,y2)
    glVertex2f(p3[0],p3[1]);//(X3,Y3)
    glEnd();
    //Printing info
    cout << "Triangle drawn in: V1(" << p1[0] << ", "<< p1[1] << ") -- V2("<< p2[0] << ", "<< p2[1] << ") -- V3("<< p3[0] << ", "<<p3[1] << ")"<< endl;
}
