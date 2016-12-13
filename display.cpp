#include "prototypes.h"

void display(void) {
    //struct house faces[7];

    float *M;
    int i, j;



    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f (1.0, 1.0, 1.0);
    //glMatrixMode(GL_PROJECTION);
    //glLoadIdentity ();
    //glFrustum(-15, 15, -15, 15, 1, 30);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity ();             /* clear the matrix */
    gluLookAt (18.0, 15.0, 6.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0);

    drawHouse();

    if (axisOn) drawAxes(5);
    if (fillOn) drawFill();
    if (signOn) drawSign();

    glFlush();
    glutSwapBuffers();

}

void drawHouse() {
    struct house4 faces4[5];
    struct house5 faces5[2];

    //floor 
    faces4[0].point[0].x = 10; faces4[0].point[0].y = -5; faces4[0].point[0].z = -5; faces4[0].point[0].w = 1;
    faces4[0].point[1].x = 10; faces4[0].point[1].y = 5; faces4[0].point[1].z = -5; faces4[0].point[1].w = 1;
    faces4[0].point[2].x = -10; faces4[0].point[2].y = 5; faces4[0].point[2].z = -5; faces4[0].point[2].w = 1;
    faces4[0].point[3].x = -10; faces4[0].point[3].y = -5; faces4[0].point[3].z = -5; faces4[0].point[3].w = 1;

    //right wall
    faces4[1].point[0].x = 10; faces4[1].point[0].y = 5; faces4[1].point[0].z = -5; faces4[1].point[0].w = 1;
    faces4[1].point[1].x = -10; faces4[1].point[1].y = 5; faces4[1].point[1].z = -5; faces4[1].point[1].w = 1;
    faces4[1].point[2].x = -10; faces4[1].point[2].y = 5; faces4[1].point[2].z = 5; faces4[1].point[2].w = 1;
    faces4[1].point[3].x = 10; faces4[1].point[3].y = 5; faces4[1].point[3].z = 5; faces4[1].point[3].w = 1;

    //right roof
    faces4[2].point[0].x = 10; faces4[2].point[0].y = 0; faces4[2].point[0].z = 8; faces4[2].point[0].w = 1;
    faces4[2].point[1].x = 10; faces4[2].point[1].y = 5; faces4[2].point[1].z = 5; faces4[2].point[1].w = 1;
    faces4[2].point[2].x = -10; faces4[2].point[2].y = 5; faces4[2].point[2].z = 5; faces4[2].point[2].w = 1;
    faces4[2].point[3].x = -10; faces4[2].point[3].y = 0; faces4[2].point[3].z = 8; faces4[2].point[3].w = 1;

    //left roof
    faces4[3].point[0].x = 10; faces4[3].point[0].y = -5; faces4[3].point[0].z = 5; faces4[3].point[0].w = 1;
    faces4[3].point[1].x = 10; faces4[3].point[1].y = 0; faces4[3].point[1].z = 8; faces4[3].point[1].w = 1;
    faces4[3].point[2].x = -10; faces4[3].point[2].y = 0; faces4[3].point[2].z = 8; faces4[3].point[2].w = 1;
    faces4[3].point[3].x = -10; faces4[3].point[3].y = -5; faces4[3].point[3].z = 5; faces4[3].point[3].w = 1;

    //left wall
    faces4[4].point[0].x = 10; faces4[4].point[0].y = -5; faces4[4].point[0].z = -5; faces4[4].point[0].w = 1;
    faces4[4].point[1].x = -10; faces4[4].point[1].y = -5; faces4[4].point[1].z = -5; faces4[4].point[1].w = 1;
    faces4[4].point[2].x = -10; faces4[4].point[2].y = -5; faces4[4].point[2].z = 5; faces4[4].point[2].w = 1;
    faces4[4].point[3].x = 10; faces4[4].point[3].y = -5; faces4[4].point[3].z = 5; faces4[4].point[3].w = 1;

    for (int i = 0;i < 5;i++) {
        glBegin(GL_LINE_LOOP);
        glVertex3i(faces4[i].point[0].x, faces4[i].point[0].y, faces4[i].point[0].z);
        glVertex3i(faces4[i].point[1].x, faces4[i].point[1].y, faces4[i].point[1].z);
        glVertex3i(faces4[i].point[2].x, faces4[i].point[2].y, faces4[i].point[2].z);
        glVertex3i(faces4[i].point[3].x, faces4[i].point[3].y, faces4[i].point[3].z);
        glEnd();
    }
}

void drawFill() {

}

void drawSign() {
    
}

void drawAxes(int length) {
    int i, len;

    // Set up some character arrays for axis labels
    char xaxis[] = "X"; 
    char yaxis[] = "Y";
    char zaxis[] = "Z";

    // Select the Stroke font we want to use
    void *font = GLUT_STROKE_ROMAN;

    // This provides a coordinate axis about the origin. 
    glPointSize(1.0);
    glBegin(GL_LINES);
    glVertex3i(0,length,0);
    glVertex3i(0,-length,0);
    glEnd();
    glBegin(GL_LINES);
    glVertex3i(length,0,0);
    glVertex3i(-length,0,0);
    glEnd();
    glBegin(GL_LINES);
    glVertex3i(0,0,length);
    glVertex3i(0,0,-length);
    glEnd();

    // And now we  add some lettering.

    // Z - Label
    glPushMatrix();
    glTranslatef(-0.2, 0.2, 4);
    glRotatef(90.0, 0.0, 0.0, 1.0);
    glRotatef(90.0, 1.0, 0.0, 0.0);
    glScalef(0.002,0.002,0.002);
    len = (int) strlen(zaxis);
    for (i = 0; i < len; i++) {
        glutStrokeCharacter(font, zaxis[i]);
    }
    glPopMatrix();

    // Y - Label
    glPushMatrix();
    glTranslatef(0.0, 4, -.4);
    glRotatef(90.0, 0.0, 0.0, 1.0);
    glRotatef(90.0, 1.0, 0.0, 0.0);
    glScalef(0.002,0.002,0.002);
    len = (int) strlen(yaxis);
    for (i = 0; i < len; i++) {
        glutStrokeCharacter(font, yaxis[i]);
    }
    glPopMatrix();

    // X - Label 
    glPushMatrix();
    glTranslatef(4.0, 0.0, -.4);
    glRotatef(90.0, 0.0, 0.0, 1.0);
    glRotatef(90.0, 0.0, 1.0, 0.0);
    glScalef(0.002,0.002,0.002);
    len = (int) strlen(xaxis);
    for (i = 0; i < len; i++) {
        glutStrokeCharacter(font, xaxis[i]);
    }
    glPopMatrix();
}


