#include "prototypes.h"

int winWidth = 400;
int winHeight = 400;

void myGlutInit(int argc, char** argv){

	glutInit(&argc,argv);
	glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(winWidth,winHeight);
	glutInitWindowPosition(0,0);
	glutCreateWindow("See Rock City");
}

void myInit() {
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glClearDepth(1.0); //set depth
	glEnable(GL_DEPTH_TEST); //enable z-buffer
	glDepthFunc(GL_LEQUAL); //depth test mode

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glMatrixMode(GL_MODELVIEW);
}

void keyboard( unsigned char key, int x, int y ) {
    if ( key == 'q' || key == 'Q')
    	exit(0);
	//if (key == 's') //stop animation
		//
	//if (key == 'r') //return house to original position/size
		//	
	//if (key == 'R') //reset house AND reset camera
		//capital R
	//if (key == 'pgup') //camera moves closer to house
		//USE GLUTSPECIALFUNC
	//if (key == 'pgdown') //camera moves further from house (still in view)
		//USE GLUTSPECIALFUNC
}

void reshape (int w, int h) {
    glViewport (0, 0, (GLsizei) w, (GLsizei) h); 
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity ();
    glFrustum (-1.0, 1.0, -1.0, 1.0, 1.5, 40.0);
    glMatrixMode (GL_MODELVIEW);
}

void refresh() {
    display();
}

int main(int argc, char** argv) {
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

    myGlutInit(argc, argv);
    myInit();
    glutDisplayFunc(display); 
    glutReshapeFunc(reshape);

    setupMenu();

    glutMainLoop();
}
