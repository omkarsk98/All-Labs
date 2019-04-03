// compile as
// g++ test.cpp -o box -lGL -lGLU -lglut
#include <GL/glut.h> // GLUT, includes glu.h and gl.h
#include <unistd.h>

/* Handler for window-repaint event. Call back when the window first appears and
   whenever the window needs to be re-painted. */
void display()
{
    glClearColor(255, 255, 255, 1.0f); // Set background color to black and opaque
    /* void glClearColor(GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha) */
    glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer

    // Draw a Red 1x1 Square centered at origin
    glBegin(GL_QUADS);           // Each set of 4 vertices form a quad
    glColor3f(1.0f, 0.0f, 0.0f); // Red
    glVertex2f(-1, -1);          // x, y
    // glVertex2f(0.5f, -0.5f);
    glVertex2f(1, -1);
    glVertex2f(1, 1);
    glVertex2f(-1, 1);
    sleep(2);
    glTranslatef(0.1, 0, 0);
    // glColor3f(0, 0, 0);
    // glVertex2f(0, 0);
    glEnd();

    glFlush(); // Render now
}

/* Main function: GLUT runs as a console application starting at main()  */
int main(int argc, char **argv)
{
    glutInit(&argc, argv);           // Initialize GLUT
    glutCreateWindow("Box");         // Create a window with the given title
    glutInitWindowSize(320, 320);    // Set the window's initial width & height
    glutInitWindowPosition(150, 50); // Position the window's initial top-left corner
    glutDisplayFunc(display);        // Register display callback handler for window re-paint
    glutMainLoop(); // Enter the infinitely event-processing loop
    return 0;
}