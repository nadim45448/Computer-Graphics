#include<windows.h>
#include <GL/glut.h>
#include <stdlib.h>
#include<cstdio>
#include <GL/gl.h>
#include<math.h>

//positions of the bus, plane, car, and train.
static float    bm=  400.0;  //for bus
static float    pm=  300.0; // for plane
static float    cm=  -300.0; //for car
static float    tm=  300.0; // for Train


void circle(GLfloat rx,GLfloat ry,GLfloat x,GLfloat y) // for sun, hill
{
    int i;
    float rad = 0;
    glBegin(GL_POLYGON);
    glVertex2f(x,y);
    for(i = 0; i<=360; i++)
    {
        rad = i*(3.1416/180);
        glVertex2f(x+rx*cos(rad),y+ry*sin(rad));
    }
    glEnd();
}

void sun()
{
    glPushMatrix();
    glTranslated(-210,260,0); // sun position
    glColor3f(1.0, 0.76, 0.3); // sun color
    circle(20,40,0,0); // sun shape
    glPopMatrix();
}

void hill()
{
    glColor3f(0.5, 0.87, 1.0);
    circle(70,120,-250,90);
    circle(70,120,-100,90);
    circle(70,120,50,100);
    circle(70,120,200,90);
}


void rectangle(int x, int y, int x1, int y1)
{
    // glVertex2d()-> avoid z coordinates.rendiring shapes in 2d

    glBegin(GL_QUADS);
    glVertex2d(x,y);  // One corner of the rectangle.
    glVertex2d(x,y1); // Corner directly above or below (x, y), aligned vertically.
    glVertex2d(x1,y1); // Opposite corner of (x, y).
    glVertex2d(x1,y); // Corner directly to the right or left of (x, y), aligned horizontally.
    glEnd();

    // soil, ground
}

void triangle(int x, int y, int x1, int x2,int y1)
{
    // x,y
    // x1,y
    // x2, y1
    glBegin(GL_POLYGON);
    glVertex2d(x,y);
    glVertex2d(x1,y);

    glVertex2d(x1,y);
    glVertex2d(x2,y1);

    glVertex2d(x2,y1);
    glVertex2d(x,y);
    glEnd();
}

void rectangle1(int x1,int y1, int x2, int y2, int x3, int y3, int x4, int y4)
{
    glBegin(GL_QUADS);
        glVertex2d(x1,y1);
        glVertex2d(x3,y3);
        glVertex2d(x4,y4);
        glVertex2d(x2,y2);
        glEnd();
}

void soil()
{
    glColor3f(0.75, 0.75, 0.75);
    rectangle(-300,-10,300,130);
}

void ground()
{
     glColor3f(0.72, 0.56, 0.26);  //Bottom part
     rectangle(-300,-300,300,-10);  //(x,y,x1,y1)-->(x,y),(x,y1),(x1,y1),(x1,y)
}

void road()
{
        //Road Area
        glColor3f(0.3, 0.3, 0.3);
        rectangle(-300,-200,300,-30);
        //road side broader up
        glColor3f(0.0, 0.0, 0.0);
        rectangle(-300,-30,300,-33);
        //road side broader down
        glColor3f(0.0, 0.0, 0.0);
        rectangle(-300,-205,300,-200);
        //divider 1st
        glColor3f(1.0, 1.0, 1.0);
        rectangle(-270,-120,-230,-110);
        //divider 2nd
        glColor3f(1.0, 1.0, 1.0);
        rectangle(-150,-120,0,-110);
        //divider  3rd
        glColor3f(1.0, 1.0, 1.0);
        rectangle(50,-120,150,-110);
        //divider  4th
        glColor3f(1.0, 1.0, 1.0);
        rectangle(200,-120,290,-110);
}




void myDisplay()
{
    glClear(GL_COLOR_BUFFER_BIT);

    sun();
    hill();
    soil();
    ground();
    road();


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

int main(int argc, char** argv)
{
    glutInit(&argc, argv); // Initialize GLUT
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1200, 700);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("City View");
    glOrtho(-300,300,-300,300,-150,500);


    init(); // set background color light blue
    glutDisplayFunc(myDisplay);
    glutMouseFunc(mouse);

    glutMainLoop();
    return 0;
}


