#include "prototypes.h"

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
			cout << "Enter 1st parameter: "
			cin >> customX;
			cout << "Enter 2nd parameter: "
			cin >> customY;
			break;
	}
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
