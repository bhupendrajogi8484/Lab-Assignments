#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <iostream>

using namespace std;

void dda(){

float x1,y1,dx,dy,xin,yinc,step,x2,y2,x,y;

x1 = 0;
y1 = 100;
x2= 300;
y2= 300;

dx = abs(x2-x1);
dy = abs(y2-y1);

if(dx > dy)
    step = dx;
else
    step = dy;


    xin = (x2 - x1) / step;
    yinc = (y2 - y1) / step;

glBegin(GL_POINTS);
glVertex2i(x1,y1);
x = x1;
y = y1;


for(int i = 0; i< step; i++){
x = x + xin;
y = y + yinc;
glVertex2i(x,y);
}
glEnd();
glFlush();
}

int main(int argc, char** argv){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500,500);
    glutCreateWindow("DDA");
    glutInitWindowPosition(100,100);
    glClearColor(0,0,0,0);
    glColor3f(1,1,1);
    glPointSize(1.9);
    gluOrtho2D(-500,500,500,0);
    glutDisplayFunc(dda);
    glutMainLoop();

}
