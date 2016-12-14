#ifndef PROTOTYPE
#define PROTOTYPE

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <iostream>
#include <string.h>
#include <sstream>
#include <cstdlib>
#include <cmath>

using namespace std;

extern int winWidth, winHeight;
extern int axisOn, fillOn, signOn;
extern int viewMode;
extern int customX, customY;
extern float angle, spin;
extern float zoom;

//Debug
extern float xT, yT, zT;

void switchView (int msg);
void showAxis (int msg);
void fillSides (int msg);
void showSign (int msg);
void system(int msg);
void setupMenu ();
void display(void);
void drawAxes(int length);
void refresh();
void reshape (int w, int h);
void drawSign();
void drawHouse();
void changeView();
void spinHouse();

typedef struct vertex {
    float x;
    float y;
    float z;
    float w;
} vertex;

typedef struct colortype {
    float red;
    float green;
    float blue;
} colortype;

typedef struct house4 {
    vertex point[4];
    colortype color;	
} house4;

typedef struct house5 {
    vertex point[5];
    colortype color;	
} house5;

#endif
