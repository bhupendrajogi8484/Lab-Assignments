#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <iostream>

using namespace std;

void display(){

float x1,y1,dx,dy,p,x2,y2,x,y;

x1 = 100;
y1 = 100;
x2= 300;
y2= 300;

dx = abs(x2-x1);
dy = abs(y2-y1);

p = (2*dy - dx);

x = x1;
y = y1;

glBegin(GL_POINTS);
glVertex2i(x1,y1);
   
  while (x < x2) {
        if (p < 0) {
            glVertex2i(x + 1, y);
            p += 2 * dy;
        } else {
            glVertex2i(x + 1, y + 1);
            p += 2 * dy - 2 * dx;
            y++;
        }
        x++;
    }

glEnd();
glFlush();
}

int main(int argc, char** argv){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500,500);
    glutCreateWindow("Bresenham");
    glutInitWindowPosition(100,100);
    glClearColor(0,0,0,0);
    glColor3f(1,1,1);
    glPointSize(1.9);
    gluOrtho2D(-500,500,500,0);
    glutDisplayFunc(display);
    glutMainLoop();
}
