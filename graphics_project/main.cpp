#include<windows.h>
#include <GL/glut.h>
#include <stdlib.h>
#include<cstdio>
#include <GL/gl.h>
#include<math.h>

//positions of the car, bus, plane and train.
static float    cm=  -300.0; //for car
static float    bm=  400.0;  //for bus
static float    pm=  300.0; // for plane
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
void tree(int a,int b,int c,int d, int e,int f,int g, int h , int i)
{
   glColor3f(0.0, 0.0, 0.0);
   rectangle(a,b,c,d);
   glColor3f(0.0, 0.5, 0.0);
   triangle(e,f,g,h,i);

}
void tree1()
{
    tree(-270,110,-268,140,-275,140,-263,-269,170);
    tree(-240,110,-238,140,-245,140,-233,-239,170);
    tree(-200,110,-202,140,-195,140,-205,-200,170);
    tree(-150,110,-148,140,-155,140,-143,-149,170);
    tree(-120,110,-118,140,-125,140,-113,-119,170);
    tree(-90,110,-88,140,-95,140,-83,-89,170);
    tree(-60,110,-58,140,-65,140,-53,-59,170);
    tree(-30,110,-28,140,-35,140,-23,-29,170);
    tree(0,110,2,140,-5,140,7,1,170);
    tree(30,110,32,140,25,140,37,31,170);
    tree(60,110,62,140,55,140,67,61,170);
    tree(90,110,92,140,85,140,97,91,170);
    tree(120,110,122,140,115,140,127,121,170);
    tree(150,110,152,140,145,140,157,151,170);
    tree(180,110,182,140,175,140,187,181,170);
    tree(210,110,212,140,205,140,217,211,170);
    tree(240,110,242,140,235,140,247,241,170);
    tree(270,110,272,140,265,140,277,271,170);
}
void make_tree2()
{
    glColor3f(0.0, 0.8, 0.0);
    circle(20,30,0,0);
    circle(20,30,20,0);
    circle(20,30,40,0);
    circle(20,30,30,30);    //Bigger part of the tree
    circle(20,30,10,30);
    circle(20,30,10,-30);
    circle(20,30,30,-30);


    circle(10,20,50,-70);
    circle(10,20,60,-60);   //Small part of Tree
    circle(10,20,60,-80);

    glColor3f(0.75, 0.25,0.12);
    rectangle1(10,-130,30,-130,10,-30,30,-30);
    rectangle1(10,-30,17,-30,5,0,5,0);
    rectangle1(17,-30,22,-30,19,0,19,0);
    rectangle1(22,-30,30,-30,35,0,35,0);
    rectangle1(30,-90,30,-100,55,-70,55,-75);

}

void tree2()
{
    //1st big tree
    glPushMatrix();
    glTranslated(-320,120,0);
    make_tree2();
    glPopMatrix();

    // 2nd big tree
    glPushMatrix();
    glTranslated(100,120,0);
   make_tree2();
    glPopMatrix();

    //3rd big tree
    glPushMatrix();
    glTranslated(270,120,0);
    make_tree2();
    glPopMatrix();

}
void college()
{
    glColor3f(0.73, 0.94, 0.32); //Front Show
    rectangle(-100,-9,60,120);
    glColor3f(0.96, 0.96, 0.37); //Top
    rectangle1(-100,120,60,120,-90,140,70,140);
    glColor3f(0.4, 1.0, 1.0); //Side show
    rectangle1(60,-9,70,0,60,120,70,140);

        glColor3f(0, 0, 0); //Windows
        rectangle(-90,100,-70,80);
        rectangle(-60,100,-40,80);
        rectangle(-35,-9,-5,30); //door
        rectangle(-30,100,-10,80);
        rectangle(0,100,20,80);
        rectangle(30,100,50,80);

        rectangle(-90,70,-70,50);
        rectangle(-60,70,-40,50);
        rectangle(-30,70,-10,50);
        rectangle(0,70,20,50);
        rectangle(30,70,50,50);
}

void hospital()
{
    glColor3f(0.97, 0.28, 0.09);  //Front show
    rectangle(-210,-9,-120,150);
    glColor3f(0.92, 0.49, 0.06); //Top
    rectangle1(-210,150,-120,150,-190,170,-110,170);
    glColor3f(0.09, 0.47, 0.89); // Side
    rectangle1(-120,-9,-110,0,-120,150,-110,170);


        glColor3f(1, 0.31, 1);  //window
        rectangle(-170,-9,-155,10); // hospital gate...

        rectangle(-140,130,-125,110);  //Right top
        rectangle(-140,100,-125,80);
        rectangle(-140,70,-125,50);
        rectangle(-140,40,-125,20);

        rectangle(-160,130,-145,110);
        rectangle(-160,100,-145,80);
        rectangle(-160,70,-145,50);
        rectangle(-160,40,-145,20);

        rectangle(-180,130,-165,110);
       rectangle(-180,100,-165,80);
        rectangle(-180,70,-165,50);
        rectangle(-180,40,-165,20);

        rectangle(-200,130,-185,110); //Left top
        rectangle(-200,100,-185,80);
        rectangle(-200,70,-185,50);
        rectangle(-200,40,-185,20);
}

void house()
{
    glColor3f(0.77, 1.0, 0.77); //Front Show
    rectangle1(200,-9,350,-9,200,80,350,80);
    rectangle1(200,80,250,80,200,120,250,120);

    glColor3f(0.0f, 0.1f, 0.0f); //Top
    triangle(195,120,255,225,150);


    glColor3f(0.97, 0.65, 0.14); //Window small one
    rectangle1(215,95,235,95,215,115,235,115);

    glColor3f(0., 0.1, 0.1); //Door
    rectangle1(220,-9,250,-9,220,40,250,40);

}
void makePrivateCar(){

    glColor3f(1.0, 0.0, 0.0);
    circle(5,15,0,0);        // back circle
    rectangle(0,-15,60,15);  //Middle part


    glColor3f(0.2, 0.47, 1.0);
    triangle(5,15,20,20,45);
    triangle(40,15,60,40,45);


    glColor3f(0, 0, 0);
    rectangle(20,15,40,45);  //sunroof

    glColor3f(1.0, 0.0, 0.0);
    circle(5,10,80,-5);        //front circle

    glColor3f(1.0, 0.0, 0.0);
    rectangle1(60,-15,80,-15,60,15,80,5);  //front part

    glColor3f(0, 0, 0);
    circle(7,14,10,-15);
    circle(7,14,60,-15);      //tire

    glColor3f(1.0, 1.0, 1.0);
    circle(6,12,10,-15);      //tire border
    circle(6,12,60,-15);


}

void privatecarMove(){
// cm= -300 (-x to x)
cm=cm+.5;
    if(cm>330)
        cm = -350;
        glutPostRedisplay();
}

void privatecar()
{

     glPushMatrix();
     glTranslatef(cm,-50,0);
     makePrivateCar();
     glPopMatrix();

   privatecarMove();
}

void busmake()
{
    glColor3f(0.9, 0.72, 0.0);
    rectangle(-60,-15,0,15);
    rectangle(-80,-15,-60,25);
    glColor3f(0, 0, 0);
    rectangle(-60,15,-2,50);
    rectangle(-70,25,-60,50);
    glColor3f(0.76, 0.84, 0.84);
    rectangle1(-2,50,-70,50,-7,55,-76,55);

    glColor3f(0.2, 0.8, 1.0);
    rectangle1(-70,25,-74,25,-70,50,-76,55);


    glColor3f(1, 1, 1.0);
    rectangle(-58,0,-50,35);     //door
    glColor3f(0.2, 0.8, 1.0);
    rectangle(-45,30,-40,40);    //four windows serially
    rectangle(-35,30,-30,40);
    rectangle(-25,30,-20,40);
    rectangle(-15,30,-10,40);


    glColor3f(0.9, 0.72, 0.0);
    circle(3,15,0,0);           //back part
    circle(3,20,-80,5);         // front part

    glColor3f(0, 0, 0);           //tire border
    circle(8,16,-10,-15);
    circle(8,16,-70,-15);

    glColor3f(1, 1, 1);             //tire
    circle(6,12,-10,-15);
    circle(6,12,-70,-15);

}
void busMove(){
    //bm= 400 (x to -x)
bm=bm-.4;
    if(bm<-350)
        bm = 350;

        glutPostRedisplay();
}
void bus()
{
     glPushMatrix();
     glTranslatef(bm,-165,0);
     busmake();
     glPopMatrix();
    // busMove();

}


void myDisplay()
{
    glClear(GL_COLOR_BUFFER_BIT);

    sun();
    hill();
    soil();
    ground();
    road();
    tree1(); // 18 small tree
    tree2(); // 3 big tree
    college();
    hospital();
    house();
    privatecar();
    bus();


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


