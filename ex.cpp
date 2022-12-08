#include <GL/glut.h>
#include <stdlib.h>

float opacTorus = 1.0;
float opacCone = 1.0;
float opacSphere = 1.0;

void display() {
   glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

   glPushMatrix ();
   glRotatef (20.0, 1.0, 0.0, 0.0);

   glPushMatrix ();
   glTranslatef (-0.75, 0.5, 0.0); 
   glRotatef (90.0, 1.0, 0.0, 0.0);
   glColor4f (1.0, 1.0, 0.0, opacTorus);
   glutSolidTorus (0.275, 0.85, 15, 15);
   glPopMatrix ();

   glPushMatrix ();
   glTranslatef (-0.75, -0.5, 0.0); 
   glRotatef (270.0, 1.0, 0.0, 0.0);
   glColor4f (0.0, 1.0, 0.0, opacCone);
   glutSolidCone (1.0, 2.0, 15, 15);
   glPopMatrix ();

   glPushMatrix ();
   glTranslatef (0.75, 0.0, -1.0); 
   glColor4f (0.0, 0.0, 1.0, opacSphere);
   glutSolidSphere (1.0, 15, 15);
   glPopMatrix ();

   glPopMatrix ();
   glFlush ();
}

void reshape(int w, int h) {
   glViewport (0, 0, (GLsizei) w, (GLsizei) h);
   glMatrixMode (GL_PROJECTION);
   glLoadIdentity ();
   if (w <= h) 
      glOrtho (-2.5, 2.5, -2.5*(GLfloat)h/(GLfloat)w, 
               2.5*(GLfloat)h/(GLfloat)w, -10.0, 10.0);
   else 
      glOrtho (-2.5*(GLfloat)w/(GLfloat)h, 
               2.5*(GLfloat)w/(GLfloat)h, -2.5, 2.5, -10.0, 10.0);
   glMatrixMode (GL_MODELVIEW);
   glLoadIdentity ();
}

void keyboard(unsigned char key, int x, int y) {
   switch (key) {
      case 27:
         exit(0);
      break;
      case 'q':
         if(opacTorus <= 1.0)
            opacTorus += 0.1f;
      break;
      case 'w':
         if(opacTorus >= 0.0)
            opacTorus -= 0.1f;
      break;
      case 'a':
         if(opacCone <= 1.0)
            opacCone += 0.1f;
      break;
      case 's':
         if(opacCone >= 0.0)
            opacCone -= 0.1f;
      break;
      case 'z':
         if(opacSphere <= 1.0)
            opacSphere += 0.1f;
      break;
      case 'x':
         if(opacSphere >= 0.0)
            opacSphere -= 0.1f;
      break;
   }
   glutPostRedisplay();
}

void init() {
   glEnable(GL_BLEND);
   glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
   glShadeModel(GL_FLAT);
   glClearColor(0.0, 0.0, 0.0, 0.0);
}

int main(int argc, char** argv) {
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH | GLUT_RGBA);
   glutInitWindowSize (500, 500);
   glutCreateWindow("Exercício Prático 03 - 1ª parte");
   init();
   glutReshapeFunc (reshape);
   glutDisplayFunc(display);
   glutKeyboardFunc (keyboard);
   glutMainLoop();
   return 0; 
}