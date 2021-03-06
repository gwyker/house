#include "prototypes.h"

float spinX = 0;
float angleX = 0;
float spinY = 0;
float angleY = 0;
float spinZ = 0;
float angleZ = 0;

float customLeft = -1.0;
float customRight = 1.0;
float customBottom = -1.0;
float customTop = 1.0;
float customNear = 1.5;
float customFar = 40.0;

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
    
    glPushMatrix();
    glRotatef(angleX, 1.0, 0.0, 0.0);
    glRotatef(angleY, 0.0, 1.0, 0.0);
    glRotatef(angleZ, 0.0, 0.0, 1.0);
    drawHouse();
    if (signOn) drawSign();
    glPopMatrix();

    if (axisOn) drawAxes(50);
    
    changeView();
    drawCurrentView();
    
    glFlush();
    glutPostRedisplay();
    glutSwapBuffers();

}

void spinHouse() {
    angleX += spinX;
    if (angleX > 360.0)
        angleX -= 360.0;
    angleY += spinY;
    if (angleY > 360.0)
        angleY -= 360.0;
    angleZ += spinZ;
    if (angleZ > 360.0)
        angleZ -= 360.0;
    glutPostRedisplay();
}

int lineCompare(int x, int y, bool isLeft) {

    //returns 1 for above, 2 for below, 0 for on line
    int port[4];
    glGetIntegerv(GL_VIEWPORT, port);
    float slope, yLine;
    //true is left-to-center line, false is right-to-center line
    if (isLeft) {
        slope = ((float)port[3] / 2.0) / ((float)port[2] / 2.0);
        //y=mx+b
        yLine = slope * x;
        if (y > yLine)
            return 1;
        else if (y < yLine)
            return 2;
        else
            return 0;
    }
    else {
        slope = ((float)port[3] / 2.0) / ((float)port[2] / -2.0);
        //y=mx+b
        yLine = slope * x + port[3];
        if (y > yLine)
            return 1;
        else if (y < yLine)
            return 2;
        else
            return 0;
    }
}

void changeSpin(int x, int y, bool pos) {
    int port[4];
    glGetIntegerv(GL_VIEWPORT, port);

    int lineResult;

    if (x < (port[2] / 2)) { //left side of viewport
        lineResult = lineCompare(x, port[3] - y, true); //true is left line
        cout << "lineresult is: " << lineResult << endl;
        if (lineResult == 1) { //left and above the line, spin Y
            if (pos) {
                spinY += 1.0;
                if (spinY > 10.0)
                    spinY = 10.0;
            }
            else {
                spinY -= 1.0;
                if (spinY < -10.0)
                    spinY = -10.0;
            }
        }
        else if (lineResult == 2) { //left and below the line, spin Z
            if (pos) {
                spinZ += 1.0;
                if (spinZ > 10.0)
                    spinZ = 10.0;
            }
            else {
                spinZ -= 1.0;
                if (spinZ < -10.0)
                    spinZ = -10.0;
            }
        }
    }
    else if (x > (port[2] / 2)) { //right side of viewport
        lineResult = lineCompare(x, port[3] - y, false); //false is right line
        cout << "lineresult is: " << lineResult << endl;
        if (lineResult == 1) { //right and above the line, spin X
            if (pos) {
                spinX += 1.0;
                if (spinX > 10.0)
                    spinX = 10.0;
            }
            else {
                spinX -= 1.0;
                if (spinX < -10.0)
                    spinX = -10.0;
            }
        }
        else if (lineResult == 2) { //right and below the line, spin Z
            if (pos) {
                spinZ += 1.0;
                if (spinZ > 10.0)
                    spinZ = 10.0;
            }
            else {
                spinZ -= 1.0;
                if (spinZ < -10.0)
                    spinZ = -10.0;
            }
        }
    }
    glutPostRedisplay();
}

void changeView() {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    switch (viewMode) {
    	case 1: //Perspective
   		glFrustum(-1.0*zoom, 1.0*zoom, -1.0*zoom, 1.0*zoom, 1.5, 40.0);
   		//cout << "reshape: viewmode = " << viewMode << endl;
   		//cout << "reshape: using Frustum" << endl;
   		break;
   	case 2: //Orthographic
   		glOrtho(-1.0*(zoom + 13.0), 1.0*(zoom + 13.0), -1.0*(zoom + 13.0), 1.0*(zoom + 13.0), 1.5, 40.0);
   		//cout << "reshape: viewmode = " << viewMode << endl;
   		//cout << "reshape: using Ortho" << endl;
   		break;
   	case 3: //Custom
   		glFrustum(customLeft, customRight, customBottom, customTop, customNear, customFar);
   		break;
    }
    
    glMatrixMode (GL_MODELVIEW);
}

void drawHouse() {
    struct house4 faces4[5];
    struct house5 faces5[2];

    //floor 
    faces4[0].point[0].x = 7; faces4[0].point[0].y = -5; faces4[0].point[0].z = -3; faces4[0].point[0].w = 1;
    faces4[0].point[1].x = 7; faces4[0].point[1].y = 5; faces4[0].point[1].z = -3; faces4[0].point[1].w = 1;
    faces4[0].point[2].x = -7; faces4[0].point[2].y = 5; faces4[0].point[2].z = -3; faces4[0].point[2].w = 1;
    faces4[0].point[3].x = -7; faces4[0].point[3].y = -5; faces4[0].point[3].z = -3; faces4[0].point[3].w = 1;

    faces4[0].color.red = 1.0; faces4[0].color.green = 0.0; faces4[0].color.blue = 0.0; //red

    //right wall
    faces4[1].point[0].x = 7; faces4[1].point[0].y = 5; faces4[1].point[0].z = -3; faces4[1].point[0].w = 1;
    faces4[1].point[1].x = -7; faces4[1].point[1].y = 5; faces4[1].point[1].z = -3; faces4[1].point[1].w = 1;
    faces4[1].point[2].x = -7; faces4[1].point[2].y = 5; faces4[1].point[2].z = 3; faces4[1].point[2].w = 1;
    faces4[1].point[3].x = 7; faces4[1].point[3].y = 5; faces4[1].point[3].z = 3; faces4[1].point[3].w = 1;

    faces4[1].color.red = 0.0; faces4[1].color.green = 0.0; faces4[1].color.blue = 1.0; //blue

    //right roof
    faces4[2].point[0].x = 7; faces4[2].point[0].y = 0; faces4[2].point[0].z = 7; faces4[2].point[0].w = 1;
    faces4[2].point[1].x = 7; faces4[2].point[1].y = 5; faces4[2].point[1].z = 3; faces4[2].point[1].w = 1;
    faces4[2].point[2].x = -7; faces4[2].point[2].y = 5; faces4[2].point[2].z = 3; faces4[2].point[2].w = 1;
    faces4[2].point[3].x = -7; faces4[2].point[3].y = 0; faces4[2].point[3].z = 7; faces4[2].point[3].w = 1;

    faces4[2].color.red = 1.0; faces4[2].color.green = 0.41; faces4[2].color.blue = 0.705; //pink

    //left roof
    faces4[3].point[0].x = 7; faces4[3].point[0].y = -5; faces4[3].point[0].z = 3; faces4[3].point[0].w = 1;
    faces4[3].point[1].x = 7; faces4[3].point[1].y = 0; faces4[3].point[1].z = 7; faces4[3].point[1].w = 1;
    faces4[3].point[2].x = -7; faces4[3].point[2].y = 0; faces4[3].point[2].z = 7; faces4[3].point[2].w = 1;
    faces4[3].point[3].x = -7; faces4[3].point[3].y = -5; faces4[3].point[3].z = 3; faces4[3].point[3].w = 1;

    faces4[3].color.red = 0.0; faces4[3].color.green = 1.0; faces4[3].color.blue = 1.0; //cyan

    //left wall
    faces4[4].point[0].x = 7; faces4[4].point[0].y = -5; faces4[4].point[0].z = -3; faces4[4].point[0].w = 1;
    faces4[4].point[1].x = -7; faces4[4].point[1].y = -5; faces4[4].point[1].z = -3; faces4[4].point[1].w = 1;
    faces4[4].point[2].x = -7; faces4[4].point[2].y = -5; faces4[4].point[2].z = 3; faces4[4].point[2].w = 1;
    faces4[4].point[3].x = 7; faces4[4].point[3].y = -5; faces4[4].point[3].z = 3; faces4[4].point[3].w = 1;

    faces4[4].color.red = 1.0; faces4[4].color.green = 0.0; faces4[4].color.blue = 1.0; //magenta

    //front pentagon
    faces5[0].point[0].x = 7; faces5[0].point[0].y = -5; faces5[0].point[0].z = -3; faces5[0].point[0].w = 1;
    faces5[0].point[1].x = 7; faces5[0].point[1].y = 5; faces5[0].point[1].z = -3; faces5[0].point[1].w = 1;
    faces5[0].point[2].x = 7; faces5[0].point[2].y = 5; faces5[0].point[2].z = 3; faces5[0].point[2].w = 1;
    faces5[0].point[3].x = 7; faces5[0].point[3].y = 0; faces5[0].point[3].z = 7; faces5[0].point[3].w = 1;
    faces5[0].point[4].x = 7; faces5[0].point[4].y = -5; faces5[0].point[4].z = 3; faces5[0].point[4].w = 1;

    faces5[0].color.red = 1.0; faces5[0].color.green = 1.0; faces5[0].color.blue = 0.0; //yellow

    //rear pentagon
    faces5[1].point[0].x = -7; faces5[1].point[0].y = -5; faces5[1].point[0].z = -3; faces5[1].point[0].w = 1;
    faces5[1].point[1].x = -7; faces5[1].point[1].y = 5; faces5[1].point[1].z = -3; faces5[1].point[1].w = 1;
    faces5[1].point[2].x = -7; faces5[1].point[2].y = 5; faces5[1].point[2].z = 3; faces5[1].point[2].w = 1;
    faces5[1].point[3].x = -7; faces5[1].point[3].y = 0; faces5[1].point[3].z = 7; faces5[1].point[3].w = 1;
    faces5[1].point[4].x = -7; faces5[1].point[4].y = -5; faces5[1].point[4].z = 3; faces5[1].point[4].w = 1;

    faces5[1].color.red = 0.0; faces5[1].color.green = 1.0; faces5[1].color.blue = 0.0; //green

    for (int i = 0;i < 7;i++) {
        if (i < 5) {
            if (fillOn)
                glBegin(GL_POLYGON);
            else
                glBegin(GL_LINE_LOOP);
            glColor3f(faces4[i].color.red, faces4[i].color.green, faces4[i].color.blue);
            glVertex3i(faces4[i].point[0].x, faces4[i].point[0].y, faces4[i].point[0].z);
            glVertex3i(faces4[i].point[1].x, faces4[i].point[1].y, faces4[i].point[1].z);
            glVertex3i(faces4[i].point[2].x, faces4[i].point[2].y, faces4[i].point[2].z);
            glVertex3i(faces4[i].point[3].x, faces4[i].point[3].y, faces4[i].point[3].z);
            glEnd();
        }
        else {
            if (fillOn)
                glBegin(GL_POLYGON);
            else
                glBegin(GL_LINE_LOOP);
            glColor3f(faces5[i-5].color.red, faces5[i-5].color.green, faces5[i-5].color.blue);
            glVertex3i(faces5[i-5].point[0].x, faces5[i-5].point[0].y, faces5[i-5].point[0].z);
            glVertex3i(faces5[i-5].point[1].x, faces5[i-5].point[1].y, faces5[i-5].point[1].z);
            glVertex3i(faces5[i-5].point[2].x, faces5[i-5].point[2].y, faces5[i-5].point[2].z);
            glVertex3i(faces5[i-5].point[3].x, faces5[i-5].point[3].y, faces5[i-5].point[3].z);
            glVertex3i(faces5[i-5].point[4].x, faces5[i-5].point[4].y, faces5[i-5].point[4].z);
            glEnd();
        }
    }
}

void drawCurrentView() { //Draws current viewmode in top right corner
   int vPort[4];

   glGetIntegerv(GL_VIEWPORT, vPort);

   glMatrixMode(GL_PROJECTION);
   glPushMatrix();
   glLoadIdentity();

   glOrtho(0, vPort[2], 0, vPort[3], -1, 1);
   glMatrixMode(GL_MODELVIEW);
   glPushMatrix();
   glLoadIdentity();
   
   //draw code
   int i, len;
   char messageP[] = "Perspective ";
   char messageO[] = "Orthographic";
   char messageC[] = "Custom";
   
   void *font = GLUT_STROKE_ROMAN;
    
   glLineWidth(2);

   glPushMatrix();
   glColor3f(0.0,1.0,1.0);
   glTranslatef(vPort[2] - 230, vPort[3] - 50, 0);
   //glRotatef(135.0 + 10, 1.0, 0.0, 0.0);
   //glRotatef(180.0, 0.0, 1.0, 0.0);
   glScalef(0.3,0.3,0.3);
   switch (viewMode) {
   	case 1:
   		len = (int) strlen(messageP);
   		for (i = 0; i < len; i++) {
      			glutStrokeCharacter(font, messageP[i]);
  		}
  		//cout << "drawing perspective\n";
   		break;
   	case 2:
   		len = (int) strlen(messageO);
   		for (i = 0; i < len; i++) {
      			glutStrokeCharacter(font, messageO[i]);
  		}
   		break;
   	case 3:
   		len = (int) strlen(messageC);
   		for (i = 0; i < len; i++) {
      			glutStrokeCharacter(font, messageC[i]);
  		}   		
   		break;
   }
   glPopMatrix();
   

   glMatrixMode(GL_PROJECTION);
   glPopMatrix();   
   glMatrixMode(GL_MODELVIEW);
   glPopMatrix();	

}

void drawSign() {
    int i, len;
    char message1[] = "Hello";
    char message2[] = "World!";

    void *font = GLUT_STROKE_ROMAN;
    
    glLineWidth(4);

    glPushMatrix();
    glColor3f(0.0,1.0,1.0);
    glTranslatef(5.5 + xT, 2.8 + yT, 5.2 + zT); //debugging coordinates to find best location
    glRotatef(135.0 + 10, 1.0, 0.0, 0.0);
    glRotatef(180.0, 0.0, 1.0, 0.0);
    glScalef(0.03,0.03,0.03);
    len = (int) strlen(message1);
    for (i = 0; i < len; i++) {
        glutStrokeCharacter(font, message1[i]);
    }
    glPopMatrix();


    glPushMatrix();
    glColor3f(0.0,1.0,1.0);
    glTranslatef(5.5 + xT, 2.8 + yT + 2.0, 5.2 + zT - 2.0);
    glRotatef(135.0 + 7, 1.0, 0.0, 0.0);
    glRotatef(180.0, 0.0, 1.0, 0.0);
    glScalef(0.03,0.03,0.03);
    len = (int) strlen(message2);
    for (i = 0; i < len; i++) {
        glutStrokeCharacter(font, message2[i]);
    }
    glPopMatrix();
}

void drawAxes(int length) {

    glColor3f(1.0, 1.0, 1.0);
    int i, len;

    // Set up some character arrays for axis labels
    char xaxis[] = "X"; 
    char yaxis[] = "Y";
    char zaxis[] = "Z";

    // Select the Stroke font we want to use
    void *font = GLUT_STROKE_ROMAN;
    
    glLineWidth(2);

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
    glTranslatef(-0.2, 0.2, 12.0);
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
    glTranslatef(0.0, 12.0, -.4);
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
    glTranslatef(12.0, 0.0, -0.4);
    glRotatef(90.0, 0.0, 0.0, 1.0);
    glRotatef(90.0, 0.0, 1.0, 0.0);
    glScalef(0.002,0.002,0.002);
    len = (int) strlen(xaxis);
    for (i = 0; i < len; i++) {
        glutStrokeCharacter(font, xaxis[i]);
    }
    glPopMatrix();
}


