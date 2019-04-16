/*
Computer Graphics 2019
Problem 2.3
Dragi Kamov
d.kamov@jacobs-university.de
*/

#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>

#define checkImageWidth 200
#define checkImageHeight 200
static GLubyte checkImage[checkImageHeight][checkImageWidth][4];

static GLuint texName;

void makeCheckImage(void)
{
    int i, j, c;

    for (i = 0; i < checkImageHeight; i++)
    {
        for (j = 0; j < checkImageWidth; j++)
        {
            c = ((((i & 0x8) == 0) ^ (((j | 0x8)) == 0))) * 255;
            checkImage[i][j][0] = (GLubyte)c;
            // checkImage[i][j][1] = (GLubyte) c;
            // checkImage[i][j][2] = (GLubyte) c;
            checkImage[i][j][3] = (GLubyte)255;
        }
    }
}

void init(void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_FLAT);
    glEnable(GL_DEPTH_TEST);

    makeCheckImage();

    glGenTextures(1, &texName);
    glBindTexture(GL_TEXTURE_2D, texName);
    glMatrixMode(GL_TEXTURE);
    glRotatef(40.0, 0.0, 0.0, 1.0);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, checkImageWidth,
                 checkImageHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE,
                 checkImage);
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glEnable(GL_TEXTURE_2D);

    // GL_REPEAT
    glBegin(GL_TRIANGLES);
    glTexCoord2f(0.0, 0.0);
    glVertex3f(0.0, 0.0, 0.0);
    glTexCoord2f(1.0, 0.0);
    glVertex3f(2.0, 0.0, 0.0);
    glTexCoord2f(0.0, 1.0);
    glVertex3f(2.0, 2.0, 0.0);

    glTexCoord2f(0.0, 0.0);
    glVertex3f(0.0, 0.0, 0.0);
    glTexCoord2f(1.0, 0.0);
    glVertex3f(0.0, 2.0, 0.0);
    glTexCoord2f(0.0, 1.0);
    glVertex3f(2.0, 2.0, 0.0);
    glEnd();

    glBegin(GL_TRIANGLES);
    glTexCoord2f(0.0, 0.0);
    glVertex3f(-3.0, 0.0, 0.0);
    glTexCoord2f(1.0, 0.0);
    glVertex3f(-1.0, 0.0, 0.0);
    glTexCoord2f(0.0, 1.0);
    glVertex3f(-2, 2.0, 0.0);
    glEnd();

    // GL_MIRRORED_REPEAT
    glBegin(GL_TRIANGLES);
    glTexCoord2f(0.0, 0.0);
    glVertex3f(-3.0, -3.0, 0.0);
    glTexCoord2f(1.0, 0.0);
    glVertex3f(-1.0, -3.0, 0.0);
    glTexCoord2f(0.0, 1.0);
    glVertex3f(-1.0, -1.0, 0.0);

    glTexCoord2f(0.0, 0.0);
    glVertex3f(-3.0, -3.0, 0.0);
    glTexCoord2f(1.0, 0.0);
    glVertex3f(-3.0, -1.0, 0.0);
    glTexCoord2f(0.0, 1.0);
    glVertex3f(-1.0, -1.0, 0.0);
    glEnd();

    glMatrixMode(GL_TEXTURE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

    // GL_CLAMP_TO_EDGE
    glBegin(GL_TRIANGLES);
    glTexCoord2f(0.0, 0.0);
    glVertex3f(0.0, -3.0, 0.0);
    glTexCoord2f(1.0, 0.0);
    glVertex3f(2.0, -3.0, 0.0);
    glTexCoord2f(0.0, 1.0);
    glVertex3f(2.0, -1.0, 0.0);

    glTexCoord2f(0.0, 0.0);
    glVertex3f(0.0, -3.0, 0.0);
    glTexCoord2f(1.0, 0.0);
    glVertex3f(0.0, -1.0, 0.0);
    glTexCoord2f(0.0, 1.0);
    glVertex3f(2.0, -1.0, 0.0);
    glEnd();

    glMatrixMode(GL_TEXTURE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

    glFlush();

    glDisable(GL_TEXTURE_2D);
}

void reshape(int w, int h)
{
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, (GLfloat)w / (GLfloat)h, 1.0, 30.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0, 0.0, -8);
}

void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 27:
        exit(0);
        break;
    default:
        break;
    }
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(200, 200);
    glutCreateWindow(argv[0]);
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}
