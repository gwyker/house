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
