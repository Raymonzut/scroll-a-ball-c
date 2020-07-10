#include <GL/glut.h>

void render(void)
{
  glClear(GL_COLOR_BUFFER_BIT);
  
  glColor3f(1, 1, 0.5);

  glBegin(GL_POLYGON);
  glVertex2i(100, 300);
  glVertex2i(100, 100);
  glVertex2i(200, 100);
  glVertex2i(200, 300);
  glEnd();
  
  glFlush();
  glutSwapBuffers();
}

int main(int argc, char** argv)
{ 
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
  glutInitWindowPosition(100, 100);
  glutInitWindowSize(640, 480);
  glutCreateWindow("Scroll a ball");

  glutDisplayFunc(render);
  gluOrtho2D(0, 640, 0, 640);
  glClearColor(0.5, 0.5, 0.5, 0);

  glutMainLoop();

  return 0;
}
