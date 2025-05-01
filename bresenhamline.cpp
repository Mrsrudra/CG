#include <GL/glut.h>
#include <cmath>

void init() {
    glClearColor(0.0, 0.0, 0.0, 1);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, 500, 0, 500);
}

void setPixel(int x, int y) {
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
    glFlush();
}

void bresenham(int x1, int y1, int x2, int y2) {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int x = x1, y = y1;
    int sx = (x2 >= x1) ? 1 : -1;
    int sy = (y2 >= y1) ? 1 : -1;
    int p;

    if (dx > dy) {
        p = 2 * dy - dx;
        for (int i = 0; i <= dx; i++) {
            setPixel(x, y);
            x += sx;
            if (p < 0)
                p += 2 * dy;
            else {
                y += sy;
                p += 2 * (dy - dx);
            }
        }
    } else {
        p = 2 * dx - dy;
        for (int i = 0; i <= dy; i++) {
            setPixel(x, y);
            y += sy;
            if (p < 0)
                p += 2 * dx;
            else {
                x += sx;
                p += 2 * (dx - dy);
            }
        }
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    bresenham(50, 50, 450, 400);
    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Bresenham Line Drawing");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
