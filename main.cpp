#include <windows.h>
#include <GL/glut.h>
#include<bits/stdc++.h>
using namespace std;
 float Pi = 3.1416;
void DrawStar(float fX, float fY) {
	const float Radius = 1.3;
	const float InnerRadius = Radius*(1.0/(sin((2.0*Pi)/5.0)*2.0*cos(Pi/10.0) + sin((3.0*Pi)/10.0)));
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_TRIANGLE_FAN);
		glVertex3f(fX, fY, 0.0);
		for (int i = 0; i < 10; ++i) {
			float fAngleStart	= Pi/2.0 + (i*2.0*Pi)/10.0;
			float fAngleEnd		= fAngleStart + Pi/5.0;
			if (i % 2 == 0) {
				glVertex3f((fX + Radius*cos(fAngleStart)/1.9), (fY + Radius*sin(fAngleStart)), 0.0);
				glVertex3f((fX + InnerRadius*cos(fAngleEnd)/1.9), (fY + InnerRadius*sin(fAngleEnd)), 0.0);
			} else {
				glVertex3f((fX + InnerRadius*cos(fAngleStart)/1.9), (fY + InnerRadius*sin(fAngleStart)), 0.0);
				glVertex3f((fX + Radius*cos(fAngleEnd)/1.9), (fY + Radius*sin(fAngleEnd)), 0.0);
			}
		}
	glEnd();
}
void Draw()
{
glClear(GL_COLOR_BUFFER_BIT);

//Quad
glColor3f(255,255,0);
glBegin(GL_QUADS);
glVertex2d(-10,5);
glVertex2d(10,5);
glVertex2d(10,-5);
glVertex2d(-10,-5);
glEnd();
glFlush();

//Triangle
glColor3f(0,0,1);
glBegin(GL_TRIANGLES);
glVertex2d(-10,5);
glVertex2d(9,5);
glVertex2d(-10,-4.5);
glEnd();
glFlush();

//Triangle
glColor3f(0.0588235294117647,0.4588235294117647,0.1529411764705882);
glBegin(GL_TRIANGLES);
glVertex2d(10,4.5);
glVertex2d(10,-5);
glVertex2d(-9,-5);
glEnd();
glFlush();

DrawStar(-8.5,3.5);
DrawStar(-3.5,3.5);
DrawStar(-8.5,0.5);
DrawStar(-3.5,0.5);
DrawStar(-6.0,2.0);
glFlush();
}
void Initialize()
{
glClearColor(0, 0, 0, 1.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
glOrtho(-10.0, 10.0, -10.0, 10.0, -10.0, 10.0);
}
int main(int Argc, char** Argv)
{
glutInit(&Argc, Argv);
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize(625, 600);
glutInitWindowPosition(200, 200);
glutCreateWindow("Solomon Island");
Initialize();
glutDisplayFunc(Draw);
glutMainLoop();
return 0;
}
