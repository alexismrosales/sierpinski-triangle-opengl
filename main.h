
#include <vector>
//Display shapes on screen
void display(void);
//Drawing functions
void triangle_reflection();
void points_division(std::vector<float>&, std::vector<float>&, std::vector<float>&, int);
void draw_triangle(std::vector<float>&, std::vector<float>&, std::vector<float>&);
//Global variable
extern int limit_depth;