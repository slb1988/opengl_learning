// hello.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <math.h>
#include <gl/glut.h>

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0);
	glLineWidth(12);
	glLineStipple(1, 0x3F07);
	glEnable(GL_LINE_STIPPLE);
#define PI 3.1415926535898
	GLint circle_points = 100;
	glBegin(GL_LINE_LOOP);
		glColor3f(0.0, 1.0, 0.0);
		glVertex3f(0.25, 0.25, 0.0);
		glColor3f(1.0,0.0,0.0);
		glVertex3f(0.75, 0.25, 0.0);
		glColor3f(1.0,1.0,0.0);
		glVertex3f(0.75, 0.75, 0.0);
		glColor3f(0.0,0.0,1.0);
		glVertex3f(0.25, 0.75, 0.0);
		/*
		glVertex2f(0.0, 0.0);
		glVertex2f(0.0, 3.0);
		glVertex2f(4.0, 3.0);
		glVertex2f(6.0, 1.5);
		glVertex2f(4.0, 0.0);
		for (int i=0;i<circle_points;++i)
		{
			float angle = 2*PI*i/circle_points;
			glVertex2f(cos(angle), sin(angle));
			}
			*/
	glEnd();

	glFlush();
}

void init()
{
	glClearColor(0.0, 0.0,0.0,0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, 1.0, 0.0, 1.0, -1, 1.0);
}

void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0,	(GLdouble)w, 0.0, (GLdouble)h);
}

int _tmain(int argc, _TCHAR* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(250, 250);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("hello");
	init();
	glutDisplayFunc(display);

	//glutReshapeFunc(reshape);

	glutMainLoop();
	return 0;
}

