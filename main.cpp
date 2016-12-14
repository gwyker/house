#include "prototypes.h"

int winWidth = 800;
int winHeight = 800;
float zoom = 1.0;

//Debug
float xT = 0.0;
float yT = 0.0;
float zT = 0.0;

void myGlutInit(int argc, char** argv){

	glutInit(&argc,argv);
	glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(winWidth,winHeight);
	glutInitWindowPosition(200,200);
	glutCreateWindow("See Rock City");
}

void myInit() {
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glClearDepth(1.0); //set depth
    glEnable(GL_DEPTH_TEST); //enable z-buffer
    glDepthFunc(GL_LESS); //depth test mode
}

void mouse(int button, int state, int x, int y) 
{
    switch (button) {
        case GLUT_LEFT_BUTTON:
            if (state == GLUT_DOWN)
            {
                spin += 1.0;
                if (spin > 10.0) spin = 10.0;
                glutIdleFunc(spinHouse);
            }
            break;
        case GLUT_RIGHT_BUTTON:
            if (state == GLUT_DOWN)
            {
                spin -= 1.0;
                if (spin < -10.0) spin = -10.0;
                glutIdleFunc(spinHouse);
            }
            break;
        default:
            break;
    }
}

void keyboard( unsigned char key, int x, int y ) {
    if ( key == 'q')
    	exit(0);
    if ( key == 'f') //DEBUG
    	fillOn = 1 - fillOn;
    if (key == 's') //stop animation
	spin = 0.0;
    if (key == 'r') {//return house to original position/size
	angle = 0.0;
	spin = 0.0;
	}
    if (key == 'R') { //reset house AND reset camera
	zoom = 1.0;
	angle = 0.0;
	spin = 0.0;
	}
    if ( key == 'j')
    	xT -= 0.5; cout << "x = " << xT << endl;
    if ( key == 'k')
    	yT -= 0.5; cout << "y = " << yT << endl;
    if ( key == 'l')
    	zT -= 0.5; cout << "z = " << zT << endl;
    if ( key == 'u')
    	xT += 0.5; cout << "x = " << xT << endl;
    if ( key == 'i')
    	yT += 0.5; cout << "y = " << yT << endl;
    if ( key == 'o')
    	zT += 0.5; cout << "z = " << zT << endl;

}

void specialKeyboard(int key, int x, int y) {
    if ( key == GLUT_KEY_PAGE_UP )
    	{zoom -= 0.1; cout << "zoom = " << zoom << endl;}
    if ( key == GLUT_KEY_PAGE_DOWN )
    	{zoom += 0.1; cout << "zoom = " << zoom << endl;}
}

void reshape (int w, int h) {
    glViewport(0, 0, (GLsizei) w, (GLsizei) h); 
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    changeView();
    glMatrixMode (GL_MODELVIEW);
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
    glutMouseFunc(mouse);
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(specialKeyboard);

    setupMenu();

    glutMainLoop();
}
