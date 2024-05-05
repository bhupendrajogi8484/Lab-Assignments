#include <GL/glut.h>
#include <math.h>

GLfloat oldx=-0.5,oldy=0.5;

void drawkoch(GLfloat dir,GLfloat len,int iter) {
GLdouble dirRad = 0.0174533 * dir;
GLfloat newX = oldx + len * cos(dirRad);
float newY = oldy + len * sin(dirRad);
if (iter==0) {
glVertex2f(oldx, oldy);
glVertex2f(newX, newY);
oldx = newX;
oldy = newY;
}
else {
iter--;


drawkoch(dir, len, iter);
dir += 60.0;
drawkoch(dir, len, iter);
dir -= 120.0;
drawkoch(dir, len, iter);
dir += 60.0;
drawkoch(dir, len, iter);
}
}
void mydisplay()
{
glClear( GL_COLOR_BUFFER_BIT );
glBegin(GL_LINES);
glColor3f(1.0, 1.0, 1.0);
drawkoch(0.0,0.05,3);
drawkoch(-120.0, 0.05, 3);
drawkoch(120.0,0.05,3);
glEnd();
glFlush();
}

int main(int argc, char** argv)
{
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
glutInitWindowSize(500,500);
glutInitWindowPosition(0,0);
glutCreateWindow("Koch Snowflake");
glutDisplayFunc(mydisplay);
glutMainLoop();
}
