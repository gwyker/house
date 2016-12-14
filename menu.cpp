#include "prototypes.h"

int viewMode = 1;
int axisOn = 1;
int fillOn = 1;
int signOn = 1;
int customX, customY;


void switchView (int msg) { //Switches between views
	switch (msg) {
		case 1: //Perspective
			viewMode = 1;
			break;
		case 2: //Orthographic
			viewMode = 2;
			break;
		case 3: //Custom
			viewMode = 3;
			//Choose custom settings
			cout << "Enter left clipping plane: ";
			cin >> customLeft;
			cout << "Enter right clipping plane: ";
			cin >> customRight;
			cout << "Enter bottom clipping plane: ";
			cin >> customBottom;
			cout << "Enter top clipping plane: ";
			cin >> customTop;
			cout << "Enter near clipping distance: ";
			cin >> customNear;
			cout << "Enter far clipping distance: ";
			cin >> customFar;
			break;
	}
	cout << "viewmode = " << viewMode << endl;
	glutPostRedisplay();
}

void showAxis (int msg) { //Shows or hides axes
	switch (msg) {
		case 1:
			axisOn = 1;
			break;
		case 2:
			axisOn = 0;
			break;
	}
	glutPostRedisplay();
}

void fillSides (int msg) { //Fills house polygons with random colors
	switch (msg) {
		case 1:
			fillOn = 1;
			break;
		case 2:
			fillOn = 0;
			break;
	}
	glutPostRedisplay();
}

void showSign (int msg) { //Shows "Hello World!"" on roof
	switch (msg) {
		case 1:
			signOn = 1;
			break;
		case 2:
			signOn = 0;
			break;
	}
	glutPostRedisplay();
}

void control(int msg) { //Contains quit and reset
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

void setupMenu () {
	int view, axis, fill, sign, menu;

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
 
    menu = glutCreateMenu(control);
    glutAddSubMenu("View", view);
    glutAddSubMenu("Axes", axis);
    glutAddSubMenu("Fill", fill);
    glutAddSubMenu("See Rock City", sign);
    glutAddMenuEntry("Reset", 1);
    glutAddMenuEntry("Quit", 2);

    glutAttachMenu(GLUT_MIDDLE_BUTTON);
}
