#include<windows.h>
#include <GL/glut.h>
#include <stdlib.h>
#include<cstdio>
#include <GL/gl.h>
#include<math.h>

void circle(GLfloat rx,GLfloat ry,GLfloat x,GLfloat y)
{
    int i;
    float rad = 0;
    glBegin(GL_POLYGON);
    glVertex2f(x,y);
    for(i = 0;i<=360; i++)
        {
            rad = i*(3.1416/180);
            glVertex2f(x+rx*cos(rad),y+ry*sin(rad));
    }
    glEnd();
}

void sun()
{
    glPushMatrix();
    glTranslated(-210,260,0);
    glColor3f(1.0, 0.76, 0.3);
    circle(20,40,0,0);
    glPopMatrix();
}

void myDisplay()
{
    glClear(GL_COLOR_BUFFER_BIT);

    sun();
    glFlush();
}

void init()
{
    glClearColor(0.3, .65, 1, 1.0);  //light blue

}

// Mouse Functionality........
void mouse(int btn,int state,int x,int y)
{
    if(btn==GLUT_LEFT_BUTTON && state==GLUT_UP)
exit(0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv); // Initialize GLUT
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1200, 700);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("City View");
    glOrtho(-300,300,-300,300,-150,500);
    //init();
    glutDisplayFunc(myDisplay);
    glutMouseFunc(mouse);

    glutMainLoop();
    return 0;
}


