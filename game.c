#include <GL/glut.h>

#define WIDTH 640
#define HEIGHT 480

#define WIDTH_HALF WIDTH / 2
#define HEIGHT_HALF HEIGHT / 2

#define FPS 60

typedef struct {
  int x;
  int y;
  int size;
} gameObject;

gameObject player;

void mouse();

void render();

int main(int argc, char** argv)
{
  player.size = 50;
  player.x = 0;
  player.y = 0;

  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
  glutInitWindowPosition(100, 100);
  glutInitWindowSize(WIDTH, HEIGHT);
  glutCreateWindow("Scroll a ball");

  gluOrtho2D(0, WIDTH, 0, HEIGHT);
  glClearColor(0.5, 0.5, 0.5, 0);

  glutDisplayFunc(render);
  glutMainLoop();

  return 0;
}

void render()
{
  glClear(GL_COLOR_BUFFER_BIT);

  glColor3f(1, 1, 0.5);

  glRectf(WIDTH_HALF - 0.5 * player.size + player.x, HEIGHT_HALF - 0.5 * player.size + player.y, WIDTH_HALF + 0.5 * player.size + player.x, HEIGHT_HALF + 0.5 * player.size + player.y);
  glFlush();
  glutSwapBuffers();

  glutPostRedisplay();
  glutTimerFunc(1000 / FPS, render, 1);
}
