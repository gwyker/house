#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <iostream>
#include <string.h>
#include <sstream>
#include <cstdlib>
#include <cmath>

void switchView (int msg);
void showAxis (int msg);
void fillSides (int msg);
void showSign (int msg);
void setupMenu ();
void display(void);
void drawAxes(int length);
void refresh();
void reshape (int w, int h);