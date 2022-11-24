#include <stdlib.h>
#include <GL/glut.h>
#include <iostream>

using namespace std;

void drawCasa() {
    glBegin( GL_LINES ); 
        glColor3f(0.0f,0.0f,1.0f); 
        glVertex3f(0.0f,0.0f,0.0f); 
        glVertex3f(0.7f,0.0f,0.0f); 
        glColor3f(1.0f,0.0f,0.0f); 
        glVertex3f(0.0f,0.0f,0.0f); 
        glVertex3f(0.0f,0.5f,0.0f); 
        glColor3f(0.0f,1.0f,0.0f); 
        glVertex3f(0.0f,0.0f,0.0f); 
        glVertex3f(0.0f,0.0f,0.7f); 
    glEnd(); 

    glColor3f(1.0f,1.0f,1.0f); 
    glBegin( GL_LINE_STRIP ); 
        glVertex3f(0.0f,0.2f,0.4f); 
        glVertex3f(0.0f,0.2f,0.0f); 
        glVertex3f(0.2f,0.3f,0.0f); 
        glVertex3f(0.4f,0.2f,0.0f); 
        glVertex3f(0.4f,0.0f,0.0f); 
        glVertex3f(0.4f,0.0f,0.4f); 
    glEnd(); 

    glBegin( GL_LINE_LOOP ); 
        glVertex3f(0.0f,0.0f,0.4f); 
        glVertex3f(0.0f,0.2f,0.4f); 
        glVertex3f(0.2f,0.3f,0.4f); 
        glVertex3f(0.4f,0.2f,0.4f); 
        glVertex3f(0.4f,0.0f,0.4f); 
    glEnd(); 

    glBegin( GL_LINES ); 
        glVertex3f(0.2f,0.3f,0.0f); 
        glVertex3f(0.2f,0.3f,0.4f); 
        glVertex3f(0.4f,0.2f,0.0f); 
        glVertex3f(0.4f,0.2f,0.4f); 
    glEnd();
}

void Desenha() {
    glClear( GL_COLOR_BUFFER_BIT );

    drawCasa();

    glFlush();
}

void recortar() {
    GLdouble eqn[4] = {0.0, 1.0, 0.0, 0.0};
    GLdouble eqn2[4] = {1.0, 0.0, 0.0, 0.0};

    glPushMatrix();
    glTranslatef (0.0, 0.0, -5.0);

    glClipPlane (GL_CLIP_PLANE0, eqn);
    glEnable (GL_CLIP_PLANE0);
    glClipPlane (GL_CLIP_PLANE1, eqn2);
    glEnable (GL_CLIP_PLANE1);

    glRotatef (90.0, 1.0, 0.0, 0.0);
    drawCasa();
    glPopMatrix();
}

void Teclado (unsigned char key, int x, int y) {
	switch (key) {
        case 27:
            exit(0);
        break;
        case 'r':
            recortar();
        break;
        default:
            cout << "Comando inválido " << endl;
        break;
    }
    glutPostRedisplay();
}

void reshape (int w, int h) {
    glViewport(0,0,w,h); 
    glMatrixMode( GL_PROJECTION ); 
    glLoadIdentity(); 
    gluPerspective(30.0,w/h,1.0,10.0); 
    glMatrixMode( GL_MODELVIEW ); 
    glLoadIdentity(); 
    glTranslatef(0.0f,0.0f,-3.0f); 
    glRotatef(30.0f,1.0f,0.0f,0.0f); 
    glRotatef(-45,0.0f,1.0f,0.0f); 
}

void init(void) {
   glClearColor (0.0, 0.0, 0.0, 0.0);
   glShadeModel (GL_FLAT);
}


int main(int argc, char* argv[]) {
    glutInit(&argc, argv);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (500, 500); 
    glutInitWindowPosition (100, 100);
	glutCreateWindow("Exercício Prático 02 - 1ª parte");
    init();
	glutDisplayFunc(Desenha);
    glutReshapeFunc(reshape); 
	glutKeyboardFunc(Teclado);
	glutMainLoop();

	return 0;
}
