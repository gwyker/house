#include "prototypes.h"

void myGlutInit(int argc, char** argv){

	glutInit(&argc,argv);
	glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(winWidth,winHeight);
	glutInitWindowPosition(0,0);
	glutCreateWindow("You're Too SLOOOooooOOoOOOWWwW");

}

void myinit()
{
    glClearColor(0.0, 0.0, 0.0, 1.0);


    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glMatrixMode(GL_MODELVIEW);
}

void drawAxes(int length)
{   
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

void keyboard( unsigned char key, int x, int y )
{ 
    if ( key == 'q' || key == 'Q')
    	exit(0);
	if (key == 's') //stop animation
		//
	if (key == 'r') //return house to original position/size
		//	
	if (key == 'R') //reset house AND reset camera
		//capital R
	if (key == 'pgup') //camera moves closer to house
		//USE GLUTSPECIALFUNC
	if (key == 'pgdown') //camera moves further from house (still in view)
		//USE GLUTSPECIALFUNC
}

void refresh(){
	
	display();
}

void reshape (int w, int h)
{
    glViewport (0, 0, (GLsizei) w, (GLsizei) h); 
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity ();
    glFrustum (-1.0, 1.0, -1.0, 1.0, 1.5, 20.0);
    glMatrixMode (GL_MODELVIEW);
}

void system(int msg) { //Contains quit and reset
	switch (msg) {
        case 1: //reset
            //
            break;
        case 2: //quit
            exit(0);
            break;
    }
    glutPostRedisplay();
}

void switchView (int msg) { //Switches between views

}

void showAxis (int msg) { //Shows or hides axes

}

void fillSides (int msg) { //Fills house polygons with random colors

}

void showSign (int msg) { //Shows "Hello World!"" on roof

}

void setupMenu () {
	view = glutCreateMenu(switchView);
    glutAddMenuEntry("Perspective", 1);
    glutAddMenuEntry("Orthographic", 2);
    glutAddMenuEntry("Custom...", 3);

    axis = glutCreateMenu(showAxis); //Display labels!
    glutAddMenuEntry("On", 1);
    glutAddMenuEntry("Off", 2);

    fill = glutCreateMenu(fillSides);
    glutAddMenuEntry("On", 1);
    glutAddMenuEntry("Off", 2);

    sign = glutCreateMenu(showSign);
    glutAddMenuEntry("On", 1);
    glutAddMenuEntry("Off", 2);
 
    menu = glutCreateMenu(system);
    glutAddSubMenu("View", view);
    glutAddSubMenu("Axes", axis);
    glutAddSubMenu("Fill", fill);
    glutAddSubMenu("See Rock City", sign);
    glutAddMenuEntry("Reset", 1);
    glutAddMenuEntry("Quit", 2);

    glutAttachMenu(GLUT_MIDDLE_BUTTON);
}

int main(int argc, char** argv)
{
	/*myGlutInit(argc,argv);
	myinit(); 
	viewportInit();
	playerInit();
	glutMouseFunc(mouse);
	glutKeyboardFunc(keyboard);
	glutDisplayFunc(display); 
	glutIdleFunc(refresh);
	glutMainLoop();
	*/

	int menu, axis, sphere;

    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize (500, 500); 
    glutInitWindowPosition (100, 100);
    glutCreateWindow (argv[0]);
    init();
    glutDisplayFunc(display); 
    glutReshapeFunc(reshape);

    setupMenu();

    glutMainLoop();
}
