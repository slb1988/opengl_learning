// hello.cpp : 定义控制台应用程序的入口点。
//

#include <math.h>
#include <gl/glut.h>

#define BUFFER_OFFSET(offset) ((GLvoid *)NULL + offset)

#define XStart -0.8
#define XEnd 0.0
#define YStart -0.8
#define YEnd 0.8

#define NumXPoints					11
#define NumYPoints					11
#define NumPoints					(NumXPoints * NumYPoints)
#define NumPointsPerStrip			(2*NumXPoints)
#define NumStrips					(NumYPoints-1)
#define RestartIndex				0xffff

void display()
{
	//	int i;
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0);
	glLoadIdentity();
	
	glEnable(GL_LINE_STIPPLE);

	glLineStipple(1, 0xF00F);
	gluLookAt(0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	glScalef(1.0, 2.0, 1.0);
	glutWireCube(1.0);

	glDisable(GL_LINE_STIPPLE);
// 	glBegin(GL_TRIANGLES);
// 	glEnd();

	glFlush();
}

void init()
{
	glClearColor(0,0,0,0);
	glShadeModel(GL_FLOAT);
}

void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//glFrustum(-1.0, 1.0, -1.0, 1.0, 1.5, 20.0);
	gluPerspective(30, 1.0, 1.5, 20.0);
	glMatrixMode(GL_MODELVIEW);
	//gluOrtho2D(0.0,	(GLdouble)w, 0.0, (GLdouble)h);
}

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow(argv[0]);
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);

	glutMainLoop();
	return 0;
}

