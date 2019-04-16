"""
Computer Graphics 2019
Problem 2.1
Dragi Kamov
d.kamov@jacobs-university.de
"""

from OpenGL.GLUT import *
from OpenGL.GLU import *
from OpenGL.GL import *
import sys

name = 'Human'

def display():
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT)
    glPushMatrix()
    color = [1., 0., 1., 0.]
    glMaterialfv(GL_FRONT, GL_DIFFUSE, color)
    glTranslate(0, 2.5, 0)
    glutSolidSphere(1, 20, 20)
    glPopMatrix()

    # Main body
    glPushMatrix()
    glTranslate(0, 0.5, 0)
    glutSolidCube(2)
    glPopMatrix()

    # Left arm
    glPushMatrix()
    glTranslate(1, 1, 0)
    glRotatef(-90, 0, 1, 0)
    glutSolidCylinder(0.25, 4, 10, 1)
    glPopMatrix()

    # Right arm
    glPushMatrix()
    glTranslate(-1, 1, 0)
    glRotatef(90, 0, 1, 0)
    glutSolidCylinder(0.25, 4, 10, 1)
    glPopMatrix()

    # Left leg
    glPushMatrix()
    glTranslate(-0.5, 0, 0)
    glRotatef(90, 1, 0, 0)
    glutSolidCylinder(0.25, 2, 10, 1)
    glPopMatrix()

    # Right leg
    glPushMatrix()
    glTranslate(0.5, -2, 0)
    glRotatef(-90, 1, 0, 0)
    glutSolidCylinder(0.25, 2, 10, 1)
    glPopMatrix()

    # Nose
    glPushMatrix()
    glTranslate(0, 2.5, 0)
    glutSolidCone(0.25, 2, 10, 1)
    glPopMatrix()

    # Pond
    color[0] = 0
    color[2] = 1
    glPushMatrix()
    glMaterialfv(GL_FRONT,GL_DIFFUSE,color)
    glBegin(GL_TRIANGLES)
    glVertex3f(0, -3, 3)
    glVertex3f(0, -3, -5)
    glVertex3f(-3, -3, 0)
 
    glEnd()

    glPopMatrix()
    glPushMatrix()
    glRotatef(180, 0, 1, 0)
    glTranslate(0, 0, 2)
    glBegin(GL_TRIANGLES)
    glVertex3f(0, -3, 3)
    glVertex3f(0, -3, -5)
    glVertex3f(-3, -3, 0)
 
    glEnd()
    glPopMatrix()

    glutSwapBuffers()
    return

glutInit(sys.argv)
glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH)
glutInitWindowSize(600, 600)
glutCreateWindow(name)

glClearColor(0., 0., 0., 1.)
glShadeModel(GL_SMOOTH)
glEnable(GL_CULL_FACE)
glEnable(GL_DEPTH_TEST)
glEnable(GL_LIGHTING)
lightZeroPosition = [10., 4., 10., 1.]
lightZeroColor = [0.8, 1., 0.8, 1.0]
glLightfv(GL_LIGHT0, GL_POSITION, lightZeroPosition)
glLightfv(GL_LIGHT0, GL_DIFFUSE, lightZeroColor)
glLightf(GL_LIGHT0, GL_CONSTANT_ATTENUATION, 0.1)
glLightf(GL_LIGHT0, GL_LINEAR_ATTENUATION, 0.05)
glEnable(GL_LIGHT0)
glutDisplayFunc(display)
glMatrixMode(GL_PROJECTION)
gluPerspective(40., 1., 1., 40.)
glMatrixMode(GL_MODELVIEW)
gluLookAt(0, 2, 13, 0, 0, 0, 0, 1, 0)
glPushMatrix()
glutMainLoop()
