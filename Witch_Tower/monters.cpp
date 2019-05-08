#include "globalstuff.h"

GLfloat rat[4][3] = {
        { -4.0, -2.0, 0.0}, { -1.0, 3.0, 0.0},
        {2.0, -4.0, 0.0}, {4.0, 4.0, 0.0}};

struct Points *mhead = NULL;
struct Points *mcurrent = NULL;

int wave = 3;

int id_count = 0;

GLint monster_list;

void createMonsterList(void)
{
    monster_list = glGenLists(1);
    glNewList(monster_list,GL_COMPILE);
    {
        glLineWidth(3);
        int i;
        glMap1f(GL_MAP1_VERTEX_3, 0.0, 1.0, 3, 4, &rat[0][0]); // Spline Definition!
        glPushMatrix();
        glTranslatef(-0.2,0.0,-0.2);
        glScalef(0.5,0.5,0.5);
        glPushMatrix();
        glDisable(GL_LIGHTING);
        glColor3f(0.8,0.2,0.2);
        glTranslatef(0.0,0.05,0.0);
        glRotatef(90.0,1.0,0.0,0.0);
        glScalef(0.1,0.2,0.1);
        glBegin(GL_LINE_STRIP);
        for (i = 0; i <= 10; i++)
        {
            glEvalCoord1f((GLfloat) i/10.0);
        }
        glEnd();
        glEnable(GL_LIGHTING);
        glPopMatrix();
        glColor3f(0.0,0.0,0.0);
        glPushMatrix();
        glScalef(0.5,0.5,0.8);
        glTranslatef(0.6,0.0,0.9);
        glutSolidSphere(0.5,10,10);
        glPopMatrix();

        glPushMatrix();
        glScalef(0.5,0.5,0.8);
        glTranslatef(0.6,0.0,0.9);
        glutSolidSphere(0.5,10,10);
        glPopMatrix();

        glPopMatrix();
        glLineWidth(1);
    }
    glEndList();
}

void renderMonsters(void)
{
    glCullFace(GL_BACK);

    struct Points* pts;
    pts = mhead;

    while(pts != NULL)
    {
        glPushMatrix();
        glTranslatef(pts->x,0,pts->y);
        glRotatef(pts->rotation,0.0,1.0,0.0);
        glCallList(monster_list);
        glPopMatrix();
        pts = pts->next;
    }
}
