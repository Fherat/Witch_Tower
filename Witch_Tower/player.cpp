#include "globalstuff.h"

double player_ang = 0;
float walk_dir = 0;
double lastang = 0;

int chase_next = 0;

float scale = 0.2;

GLfloat player_X;
GLfloat player_Y;
GLfloat player_Z;
GLfloat player_rotate = 0;

float walk_y = 0;
float left_arm_rz = 0;
float right_arm_rz = 0;
float left_leg_rz = 0;
float right_leg_rz = 0;
float left_knee_rz = 0;
float right_knee_rz = 0;
float left_elbow_rz = 0;
float right_elbow_rz = 0;
float left_foot_rz = 0;
float right_foot_rz = 0;

float left_arm_rx = 0;
float right_arm_rx = 0;
float left_leg_rx = 0;
float right_leg_rx = 0;

float left_arm_ry = 0;
float right_arm_ry = 0;
float left_leg_ry = 0;
float right_leg_ry = 0;

float torso_rz = 0;
float torso_rx = 0;
float torso_ry = 0;

float head_rz = 0;
float head_ry = 0;

int player_HP = 20;


float pickup_frames[27][13] = {
                            {0.000000,0.000000,0.000000,10.000000,-10.000000,0.000000,0.000000,-20.000000,-10.000000,10.000000,0.000000,0.000000,-40.000000},
                            {-0.100000,0.000000,0.000000,20.000000,-10.000000,0.000000,0.000000,-45.000000,-30.000000,25.000000,0.000000,-10.000000,-45.000000},
                            {-0.300000,15.000000,10.000000,30.000000,-10.000000,0.000000,0.000000,-70.000000,-50.000000,40.000000,0.000000,-10.000000,-45.000000},
                            {-0.500000,25.000000,20.000000,40.000000,-10.000000,0.000000,0.000000,-85.000000,-65.000000,45.000000,0.000000,-20.000000,-45.000000},
                            {-0.700000,30.000000,25.000000,50.000000,-10.000000,0.000000,0.000000,-100.000000,-75.000000,50.000000,0.000000,-25.000000,-50.000000},
                            {-0.900000,35.000000,25.000000,60.000000,-10.000000,0.000000,0.000000,-115.000000,-80.000000,55.000000,0.000000,-25.000000,-50.000000},
                            {-1.200000,55.000000,30.000000,70.000000,-10.000000,0.000000,0.000000,-135.000000,-100.000000,65.000000,20.000000,-40.000000,-50.000000},
                            {-1.200000,55.000000,40.000000,70.000000,-10.000000,0.000000,0.000000,-135.000000,-100.000000,65.000000,20.000000,-40.000000,-50.000000},
                            {-1.200000,55.000000,45.000000,70.000000,-10.000000,0.000000,0.000000,-135.000000,-100.000000,65.000000,20.000000,-40.000000,-50.000000},
                            {-1.200000,55.000000,50.000000,70.000000,-10.000000,0.000000,0.000000,-135.000000,-100.000000,65.000000,20.000000,-40.000000,-50.000000},
                            {-1.200000,65.000000,55.000000,70.000000,-10.000000,0.000000,0.000000,-135.000000,-100.000000,65.000000,20.000000,-50.000000,-50.000000},
                            {-1.200000,45.000000,60.000000,70.000000,-10.000000,35.000000,0.000000,-135.000000,-100.000000,65.000000,20.000000,-50.000000,-50.000000},
                            {-1.200000,40.000000,60.000000,70.000000,-10.000000,45.000000,0.000000,-135.000000,-100.000000,65.000000,20.000000,-50.000000,-50.000000},
                            {-1.200000,35.000000,70.000000,70.000000,-10.000000,55.000000,0.000000,-135.000000,-100.000000,65.000000,20.000000,-50.000000,-50.000000},
                            {-1.200000,35.000000,70.000000,70.000000,-10.000000,55.000000,0.000000,-135.000000,-100.000000,65.000000,20.000000,-50.000000,-50.000000},
                            {-1.200000,65.000000,55.000000,70.000000,-10.000000,0.000000,0.000000,-135.000000,-100.000000,65.000000,20.000000,-50.000000,-50.000000},
                            {-1.200000,55.000000,50.000000,70.000000,-10.000000,0.000000,0.000000,-135.000000,-100.000000,65.000000,20.000000,-40.000000,-50.000000},
                            {-1.200000,55.000000,45.000000,70.000000,-10.000000,0.000000,0.000000,-135.000000,-100.000000,65.000000,20.000000,-40.000000,-50.000000},
                            {-1.200000,55.000000,40.000000,70.000000,-10.000000,0.000000,0.000000,-135.000000,-100.000000,65.000000,20.000000,-40.000000,-50.000000},
                            {-1.200000,55.000000,30.000000,70.000000,-10.000000,0.000000,0.000000,-135.000000,-100.000000,65.000000,20.000000,-40.000000,-50.000000},
                            {-0.900000,35.000000,25.000000,60.000000,-10.000000,0.000000,0.000000,-115.000000,-80.000000,55.000000,0.000000,-25.000000,-50.000000},
                            {-0.700000,30.000000,25.000000,50.000000,-10.000000,0.000000,0.000000,-100.000000,-75.000000,50.000000,0.000000,-25.000000,-50.000000},
                            {-0.500000,25.000000,20.000000,40.000000,-10.000000,0.000000,0.000000,-85.000000,-65.000000,45.000000,0.000000,-20.000000,-45.000000},
                            {-0.300000,15.000000,10.000000,30.000000,-10.000000,0.000000,0.000000,-70.000000,-50.000000,40.000000,0.000000,-10.000000,-45.000000},
                            {-0.100000,0.000000,0.000000,20.000000,-10.000000,0.000000,0.000000,-45.000000,-30.000000,25.000000,0.000000,-10.000000,-45.000000},
                            {0.000000,0.000000,0.000000,10.000000,-10.000000,0.000000,0.000000,-20.000000,-10.000000,10.000000,0.000000,0.000000,-40.000000}
                            };

float walk_frames[29][11] = {
                            {0.0,0.000000,0.000000,0.000000,20.000000,0.000000,0.000000,0.000000,-50.000000,0.000000,-60.000000},
                            {0.0,0.000000,0.000000,-5.000000,25.000000,5.000000,0.000000,0.000000,-50.000000,0.000000,-60.000000},
                            {0.05,0.000000,0.000000,-10.000000,30.000000,10.000000,0.000000,0.000000,-45.000000,-5.000000,-35.000000},
                            {0.05,10.000000,-5.000000,-15.000000,35.000000,20.000000,0.000000,0.000000,-45.000000,-15.000000,0.000000},
                            {0.0,15.000000,-10.000000,-20.000000,30.000000,25.000000,0.000000,0.000000,-25.000000,-5.000000,0.000000},
                            {0.0,20.000000,-15.000000,-20.000000,25.000000,30.000000,0.000000,0.000000,-15.000000,-5.000000,0.000000},
                            {0.0,20.000000,-15.000000,-15.000000,25.000000,30.000000,0.000000,-10.000000,-5.000000,-5.000000,0.000000},
                            {-0.05,20.000000,-15.000000,-15.000000,25.000000,30.000000,0.000000,-20.000000,-15.000000,-10.000000,-5.000000},
                            {-0.1,20.000000,-15.000000,-10.000000,30.000000,30.000000,0.000000,-30.000000,-25.000000,-0.000000,-5.000000},
                            {-0.1,20.000000,-15.000000,-10.000000,30.000000,30.000000,0.000000,-35.000000,-25.000000,-35.000000,-5.000000},
                            {-0.05,15.000000,-10.000000,-5.000000,25.000000,20.000000,0.000000,-30.000000,-20.000000,-45.000000,-5.000000},
                            {0.0,10.000000,-5.000000,0.000000,15.000000,10.000000,0.000000,-30.000000,-10.000000,-45.000000,-5.000000},
                            {0.0,10.000000,-5.000000,0.000000,0.000000,10.000000,0.000000,-30.000000,0.000000,-45.000000,0.000000},
                            {0.0,0.000000,0.000000,15.000000,0.000000,0.000000,0.000000,-45.000000,0.000000,-60.000000,0.000000},
                            {0.0,0.000000,0.000000,20.000000,0.000000,0.000000,0.000000,-50.000000,0.000000,-60.000000,0.000000},
                            {0.0,0.000000,0.000000,25.000000,-5.000000,0.000000,5.000000,-50.000000,0.000000,-60.000000,0.000000},
                            {0.05,0.000000,0.000000,30.000000,-10.000000,0.000000,10.000000,-45.000000,0.000000,-35.000000,-5.000000},
                            {0.05,-5.000000,10.000000,35.000000,-15.000000,0.000000,20.000000,-45.000000,0.000000,0.000000,-15.000000},
                            {0.0,-10.000000,15.000000,30.000000,-20.000000,0.000000,25.000000,-25.000000,0.000000,0.000000,-5.000000},
                            {0.0,-15.000000,20.000000,25.000000,-20.000000,0.000000,30.000000,-15.000000,0.000000,0.000000,-5.000000},
                            {0.0,-15.000000,20.000000,25.000000,-15.000000,0.000000,30.000000,-5.000000,-10.000000,0.000000,-5.000000},
                            {-0.05,-15.000000,20.000000,25.000000,-15.000000,0.000000,30.000000,-15.000000,-20.000000,-5.000000,-10.000000},
                            {-0.1,-15.000000,20.000000,30.000000,-10.000000,0.000000,30.000000,-25.000000,-30.000000,-5.000000,0.000000},
                            {-0.1,-15.000000,20.000000,30.000000,-10.000000,0.000000,30.000000,-25.000000,-35.000000,-5.000000,-35.000000},
                            {-0.05,-10.000000,15.000000,25.000000,-5.000000,0.000000,20.000000,-20.000000,-30.000000,-5.000000,-45.000000},
                            {0.0,-5.000000,10.000000,15.000000,0.000000,0.000000,10.000000,-10.000000,-30.000000,-5.000000,-45.000000},
                            {0.0,-5.000000,10.000000,0.000000,0.000000,0.000000,10.000000,0.000000,-30.000000,0.000000,-45.000000},
                            {0.0,0.000000,0.000000,0.000000,15.000000,0.000000,0.000000,0.000000,-45.000000,0.000000,-60.000000},
                            };

float potion_frames[24][14]={
                            {0.000000,10.000000,10.000000,0.000000,0.000000,0.000000,0.000000,0.000000,0.000000,0.000000,0.000000,-10.000000,-15.000000,0.000000},
                            {0.000000,15.000000,10.000000,0.000000,0.000000,10.000000,0.000000,0.000000,0.000000,0.000000,0.000000,-10.000000,-20.000000,0.000000},
                            {0.000000,15.000000,10.000000,0.000000,0.000000,20.000000,0.000000,0.000000,0.000000,0.000000,0.000000,-10.000000,-25.000000,0.000000},
                            {0.000000,15.000000,5.000000,0.000000,0.000000,20.000000,10.000000,0.000000,0.000000,0.000000,0.000000,-10.000000,-25.000000,0.000000},
                            {0.000000,15.000000,-5.000000,0.000000,0.000000,20.000000,35.000000,0.000000,0.000000,0.000000,0.000000,-10.000000,-25.000000,0.000000},
                            {0.000000,15.000000,-5.000000,0.000000,0.000000,20.000000,50.000000,0.000000,0.000000,0.000000,0.000000,-10.000000,-25.000000,0.000000},
                            {0.000000,15.000000,-5.000000,0.000000,0.000000,20.000000,80.000000,0.000000,0.000000,0.000000,0.000000,-10.000000,-25.000000,0.000000},
                            {0.000000,15.000000,-5.000000,0.000000,0.000000,20.000000,120.000000,0.000000,0.000000,0.000000,0.000000,-10.000000,-25.000000,0.000000},
                            {0.000000,15.000000,5.000000,0.000000,0.000000,20.000000,100.000000,0.000000,0.000000,0.000000,0.000000,-10.000000,-25.000000,0.000000},
                            {0.000000,15.000000,15.000000,0.000000,0.000000,20.000000,90.000000,0.000000,0.000000,0.000000,0.000000,-10.000000,-25.000000,0.000000},
                            {0.000000,15.000000,15.000000,0.000000,0.000000,20.000000,80.000000,0.000000,0.000000,0.000000,0.000000,-10.000000,-25.000000,0.000000},
                            {0.000000,15.000000,15.000000,0.000000,0.000000,20.000000,70.000000,0.000000,0.000000,0.000000,0.000000,-10.000000,-25.000000,0.000000},
                            {0.000000,15.000000,15.000000,0.000000,0.000000,20.000000,70.000000,0.000000,0.000000,0.000000,0.000000,-10.000000,-25.000000,5.000000},
                            {0.000000,15.000000,15.000000,0.000000,0.000000,20.000000,70.000000,0.000000,0.000000,0.000000,0.000000,-10.000000,-25.000000,10.000000},
                            {0.000000,15.000000,15.000000,0.000000,0.000000,20.000000,70.000000,0.000000,0.000000,0.000000,0.000000,-10.000000,-25.000000,15.000000},
                            {0.000000,15.000000,15.000000,0.000000,0.000000,20.000000,70.000000,0.000000,0.000000,0.000000,0.000000,-10.000000,-25.000000,20.000000},
                            {0.000000,15.000000,15.000000,0.000000,0.000000,20.000000,70.000000,0.000000,0.000000,0.000000,0.000000,-10.000000,-25.000000,25.000000},
                            {0.000000,15.000000,15.000000,0.000000,0.000000,20.000000,70.000000,0.000000,0.000000,0.000000,0.000000,-10.000000,-25.000000,30.000000},
                            {0.000000,15.000000,15.000000,0.000000,0.000000,20.000000,70.000000,0.000000,0.000000,0.000000,0.000000,-10.000000,-25.000000,25.000000},
                            {0.000000,15.000000,15.000000,0.000000,0.000000,20.000000,70.000000,0.000000,0.000000,0.000000,0.000000,-10.000000,-25.000000,20.000000},
                            {0.000000,15.000000,15.000000,0.000000,0.000000,20.000000,70.000000,0.000000,0.000000,0.000000,0.000000,-10.000000,-25.000000,15.000000},
                            {0.000000,15.000000,15.000000,0.000000,0.000000,20.000000,70.000000,0.000000,0.000000,0.000000,0.000000,-10.000000,-25.000000,10.000000},
                            {0.000000,15.000000,15.000000,0.000000,0.000000,20.000000,70.000000,0.000000,0.000000,0.000000,0.000000,-10.000000,-25.000000,5.000000},
                            {0.000000,15.000000,15.000000,0.000000,0.000000,20.000000,70.000000,0.000000,0.000000,0.000000,0.000000,-10.000000,-25.000000,0.000000}
                            };

bool finish_walk = true;
bool finish_pickup = true;
bool finish_potion = true;

int pickupCount = 0;
int walkCount = 0;
int potionCount = 0;
int mixCount = 0;

struct Points* next_chase;

GLUquadricObj *leg;
GLUquadricObj *head;

void drawCircle(GLfloat x, GLfloat y, GLfloat radius,GLint triangleAmount)
{
    int i;

    GLfloat twicePi = 2.0f * M_PI;
    GLfloat radiusX[triangleAmount];
    GLfloat radiusY[triangleAmount];

    for(i = 0; i <= triangleAmount; i++)
    {
        radiusX[i] = (radius * cos(i *  twicePi / triangleAmount));
        radiusY[i] = (radius * sin(i *  twicePi / triangleAmount));
    }
    glBegin(GL_TRIANGLE_FAN);
    glNormal3f(0.0,0.0,1.0);
    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glNormal3f(radiusX[i],radiusY[i],1.0);
        glVertex3f(x + radiusX[i], y + radiusY[i], 0.0);
    }
    glEnd();
}


void defineLegCylinder(void)
{
    leg = gluNewQuadric();
    gluQuadricDrawStyle(leg, GLU_FILL);
    gluQuadricNormals(leg, GLU_SMOOTH);
    gluQuadricOrientation(leg, GLU_OUTSIDE);
    gluQuadricTexture(leg, GL_TRUE);
}

void defineHeadSphere(void)
{
    head = gluNewQuadric();
    gluQuadricDrawStyle( head, GLU_FILL);
    gluQuadricNormals( head, GLU_SMOOTH);
    gluQuadricOrientation( head, GLU_OUTSIDE);
    gluQuadricTexture( head, GL_TRUE);
}

void drawCylinder(float height, float top_diam, float bottom_diam)
{
    glPushMatrix();
        glTranslatef(0.0, 0.5, -0.5);
        glTranslatef(0.0, 0.0, 0.5);
        glRotatef(90,1,0,0);
        glRotatef(180,0,1,0);
        glTranslatef(0.0, 0.0, -0.5);
        glPushMatrix();
            drawCircle(0.0, 0.0, bottom_diam,20);
        glPopMatrix();
        glPushMatrix();
            glScalef(1.0, 1.0, height);
            gluCylinder(leg, bottom_diam, top_diam, 1.0, 20.0, 20.0);
        glPopMatrix();
        glPushMatrix();
            glTranslatef(0.0, 0.0, 1.0*height);
            drawCircle(0.0, 0.0, top_diam,20);
        glPopMatrix();
    glPopMatrix();
}

void headDraw()
{
    glBindTexture(GL_TEXTURE_2D,texture_id[9]);
    glPushMatrix();
    glColor3f(0.5,0.5,0.5);
        glTranslatef(0.0,21.6,0.0);
        glEnable(GL_TEXTURE_2D);
        glPushMatrix();
            glScalef(2,3,2);
            glRotatef(90,0.0,0.0,1.0);
            gluSphere(head,0.5,20,20);
        glPopMatrix();
        glBindTexture(GL_TEXTURE_2D,texture_id[10]);
        glPushMatrix();
            glTranslatef(1.0,0.0,0.0);
            glRotatef(-90,0.0,0.0,1.0);
            drawCylinder(0.7,0.0,0.2);
        glPopMatrix();
        glDisable(GL_TEXTURE_2D);
        glColor3f(0.1,0.1,0.1);
        glPushMatrix();
            glTranslatef(-0.5,1.0,0.0);
            glRotatef(45.0,0.0,0.0,1.0);
            drawCylinder(3.0,0.0,1.0);
        glPopMatrix();
        glPushMatrix();
            glTranslatef(-0.5,1.0,0.0);
            glRotatef(45.0,0.0,0.0,1.0);
            glRotatef(90.0,1.0,0.0,0.0);
            glDisable(GL_CULL_FACE);
            drawCircle(0.0,0.0,2.0,20);
            glEnable(GL_CULL_FACE);
        glPopMatrix();
    glPopMatrix();
}

void chestDraw()
{
    glDisable(GL_TEXTURE_2D);
    glColor3f(0.1,0.1,0.1);
    glPushMatrix();
        glTranslatef(0.0, 17.0, 0.0);
        glPushMatrix();
            glTranslatef(0.0,2.5,0.0);
            drawCylinder(1,0.4,0.4);
        glPopMatrix();
        glScalef(3,6,4);
        glutSolidSphere(0.5,20,20);
    glPopMatrix();
}

void waistDraw()
{
    glPushMatrix();
        glTranslatef(0.0, 12.5, 0.0);
        glPushMatrix();
            glScalef(2,2.5,4);
            glutSolidSphere(0.5,20,20);
        glPopMatrix();
        glPushMatrix();
            drawCylinder(3,0.7,0.7);
        glPopMatrix();
    glPopMatrix();
}

void upperArmDraw(float bottom_diam,float top_diam,
             float tX, float tY, float tZ)
{
if(top_diam == 0) top_diam = 0.1;
    if(bottom_diam == 0) bottom_diam = 0.1;
    glPushMatrix();
        glTranslatef(tX, tY, tZ);
        glPushMatrix();
            glTranslatef(0.0, 1.0, 0.0);
            drawCylinder(3.0, bottom_diam, top_diam);
        glPopMatrix();
        glPushMatrix();
            glTranslatef(0.0, 0.5, 0.0);
            glutSolidSphere(0.5,20,20);
        glPopMatrix();
        glPushMatrix();
            glTranslatef(0.0, 4.5, 0.0);
            glutSolidSphere(0.5,20,20);
        glPopMatrix();
    glPopMatrix();
}

void lowerArmDraw(float bottom_diam,float top_diam,
             float tX, float tY, float tZ)
{
    if(top_diam == 0) top_diam = 0.1;
    if(bottom_diam == 0) bottom_diam = 0.1;
    glPushMatrix();
            glTranslatef(tX, tY, tZ);
        glPushMatrix();
            glTranslatef(0.0, 1.0, 0.0);
            drawCylinder(3.0, bottom_diam, top_diam);
        glPopMatrix();
        glPushMatrix();
            glTranslatef(0.0, 0.5, 0.0);
            glutSolidSphere(0.5,20,20);
        glPopMatrix();
    glPopMatrix();
}


void tightDraw(float bottom_diam,float top_diam,
             float tX, float tY, float tZ)
{
    if(top_diam == 0) top_diam = 0.1;
    if(bottom_diam == 0) bottom_diam = 0.1;
    glPushMatrix();
        glTranslatef(tX, tY, tZ);
        glPushMatrix();
            glTranslatef(0.0, 1.0, 0.0);
            drawCylinder(4.0, bottom_diam, top_diam);
        glPopMatrix();
        glPushMatrix();
            glTranslatef(0.0, 0.5, 0.0);
            glutSolidSphere(0.5,20,20);
        glPopMatrix();
        glPushMatrix();
            glTranslatef(0.0, 5.5, 0.0);
            glutSolidSphere(0.5,20,20);
            glPopMatrix();
    glPopMatrix();

}

//leg has '''5.0''' of Height
void shinDraw(float bottom_diam,float top_diam,
             float tX, float tY, float tZ)
{
    if(top_diam == 0) top_diam = 0.1;
    if(bottom_diam == 0) bottom_diam = 0.1;
    glPushMatrix();
            glTranslatef(tX, tY, tZ);
        glPushMatrix();
            glTranslatef(0.0, 1.0, 0.0);
            drawCylinder(4.0, bottom_diam, top_diam);
        glPopMatrix();
        glPushMatrix();
            glTranslatef(0.0, 0.5, 0.0);
            glutSolidSphere(0.5,20,20);
        glPopMatrix();
    glPopMatrix();
}

//foot has '''0.5''' of height
void footDraw(float angToes,float angFoot,float tZ)
{
    float y_scale = 0.5;

    glPushMatrix();
        glTranslatef(0.0, y_scale/2, tZ);
        glTranslatef(0.0,-(y_scale-1.25),0);
        glRotatef(angFoot,0,0,1);
        glTranslatef(0.0,y_scale-1.25,0);
        glPushMatrix();//foot
            glScalef(2.0,y_scale,1.0);
            glutSolidCube(1);
        glPopMatrix();
        glPushMatrix();//toes
            glTranslatef(1.5,0.0,0.0);//translate this related to the last part size.
            glTranslatef(-0.5,0.0,0.0);
            glRotatef(angToes,0.0,0.0,1.0);
            glScalef(1.0,y_scale,1.0);
            glTranslatef(0.5,0.0,0.0);
            glutSolidCube(1);
        glPopMatrix();
    glPopMatrix();
}

void drawPlayer(int type)
{
    chaseRats();

    glCullFace(GL_BACK);
    glDisable(GL_LIGHT3);

    glPushMatrix();
        glTranslatef(player_X,walk_y,player_Z);
        glRotatef(player_rotate,0.0,1.0,0.0);
        glScalef(scale,scale,scale);

        glColor3f(0.2,0.2,0.2);
        //Begin Chest and Arms -----------
        glPushMatrix();
            glTranslatef(0.0, 15.0, 0.0);
            glRotatef(torso_rz,0.0,0.0,1.0);
            glRotatef(torso_ry,0.0,1.0,0.0);
            glTranslatef(0.0, -15.0, 0.0);
            chestDraw();
            //Begin head Draw --------------
            glPushMatrix();
                glTranslatef(0.0, 20.5, 0.0);
                glRotatef(head_rz,0.0,0.0,1.0);
                glRotatef(head_ry,0.0,1.0,0.0);
                glTranslatef(0.0, -20.5, 0.0);
                headDraw();
            glPopMatrix();
            //End head Draw ----------------
            glTranslatef(0.0, 10.0, 0.0);
            //Begin left arm draw
            glPushMatrix();
                glTranslatef(0.0, 9.0, -2.0);
                glRotatef(left_arm_rz,0.0,0.0,1.0);
                glRotatef(left_arm_rx,1.0,0.0,0.0);
                glRotatef(left_arm_ry,0.0,1.0,0.0);
                glTranslatef(0.0, -9.0, 2.0);

                upperArmDraw(0.5, 0.5, 0.0, 4.5, -2.0);
                glPushMatrix();//upper Arm
                    glTranslatef(0.0, 5.0, 0.0);
                    glRotatef(left_elbow_rz, 0.0, 0.0, 1.0);
                    glTranslatef(0.0, -5.0, 0.0);
                    lowerArmDraw(0.5, 0.5, 0.0, 0.5, -2.0);
                glPopMatrix();
            glPopMatrix();
            //End left arm draw
            //Begin right arm draw
            glPushMatrix();
                glTranslatef(0.0, 9.0, 2.0);
                glRotatef(right_arm_rz,0.0,0.0,1.0);
                glRotatef(right_arm_rx,1.0,0.0,0.0);
                glRotatef(right_arm_ry,0.0,1.0,0.0);
                glTranslatef(0.0, -9.0, -2.0);
                upperArmDraw(0.5, 0.5, 0.0, 4.5, 2.0);
                glPushMatrix();//Shin
                    glTranslatef(0.0, 5.0, 0.0);
                    glRotatef(right_elbow_rz, 0.0, 0.0, 1.0);
                    glTranslatef(0.0, -5.0, 0.0);
                    lowerArmDraw(0.5, 0.5, 0.0, 0.5, 2.0);
                glPopMatrix();
            glPopMatrix();
            //End right arm draw
        glPopMatrix();
        //Ends Chest and Arms--------------


        //Begin Legs and Waist--------------------------------
        glPushMatrix();
            waistDraw();
            //Begin left leg draw
            glPushMatrix();//Thigh
                glTranslatef(0.0, 11.0, -1.0);
                glRotatef(left_leg_rz,0.0,0.0,1.0);
                glRotatef(left_leg_rx,1.0,0.0,0.0);
                glRotatef(left_leg_ry,0.0,1.0,0.0);
                glTranslatef(0.0, -11.0, 1.0);
                tightDraw(0.5, 0.5, 0.0, 5.5, -1.0);
                glPushMatrix();//Shin
                    glTranslatef(0.0, 6, 0.0);
                    glRotatef(left_knee_rz, 0.0, 0.0, 1.0);
                    glTranslatef(0.0, -6, 0.0);
                    shinDraw(0.5, 0.5, 0.0, 0.5, -1.0);//draw
                    footDraw(0.0, left_foot_rz, -1.0);//draw and rotate foot
                glPopMatrix();
            glPopMatrix();
            //End left leg draw
            //Begin right leg draw
            glPushMatrix();//Tight
                glTranslatef(0.0, 11.0, 1.0);
                glRotatef(right_leg_rz,0.0,0.0,1.0);
                glRotatef(right_leg_rx,1.0,0.0,0.0);
                glRotatef(right_leg_ry,0.0,1.0,0.0);
                glTranslatef(0.0, -11.0, -1.0);
                tightDraw(0.5, 0.5, 0.0, 5.5, 1.0);
                glPushMatrix();//Shin
                    glTranslatef(0.0, 6, 0.0);
                    glRotatef(right_knee_rz, 0.0, 0.0, 1.0);
                    glTranslatef(0.0, -6, 0.0);
                    shinDraw(0.5, 0.5, 0.0, 0.5, 1.0);
                    footDraw(0.0, right_foot_rz, 1.0);//draw and rotate foot
                glPopMatrix();
            glPopMatrix();
            //End
        glPopMatrix();
        //End Legs and Waist--------------------------------
    glPopMatrix();

    glEnable(GL_LIGHT3);
}

void chaseRats(void)
{
    next_chase = findObj(&mhead,chase_next);

    if(next_chase != NULL){
        if(!checkCollision(player_X,player_Z,next_chase->x,next_chase->y,0.5,1.2))
        {
            if(finish_walk){
                glutTimerFunc(1,doWalk,0);
            }
            if(finish_pickup){
                player_ang = atan2( next_chase->y - player_Z, next_chase->x - player_X);
                player_X += 0.05*cos(player_ang);
                player_Z += 0.05*sin(player_ang);
                player_rotate = -atan2( next_chase->y - player_Z, next_chase->x - player_X) * todeg;
            }
        }
        else
        {
            if(finish_pickup){
                glutTimerFunc(1,doPickup,0);
            }
        }
    }
    else{
        if(selected_button != 24) finish_walk = true;
        if(selected_button == 24) chaseCaldron();
    }
}

void chaseCaldron(void)
{
    if(!checkCollision(player_X,player_Z,-8.8,-8.8,1.0,0.3))
    {
        if(finish_walk) glutTimerFunc(1,doWalk,0);
        player_ang = atan2(-8.8 - player_Z,-8.8 - player_X);
        player_X += 0.05*cos(player_ang);
        player_Z += 0.05*sin(player_ang);
        player_rotate = -atan2( -8.8 - player_Z,-8.8 - player_X) * todeg;
    }
    else{
        if(finish_potion) glutTimerFunc(1,doPotion,0);
    }
}

void doPickup(int i){
    finish_pickup = false;
    walk_y = pickup_frames[pickupCount][0];
    left_arm_rz = pickup_frames[pickupCount][1];
    right_arm_rz = pickup_frames[pickupCount][2];
    left_leg_rz = pickup_frames[pickupCount][3];
    right_leg_rz = pickup_frames[pickupCount][4];
    left_elbow_rz = pickup_frames[pickupCount][5];
    right_elbow_rz = pickup_frames[pickupCount][6];
    left_knee_rz = pickup_frames[pickupCount][7];
    right_knee_rz = pickup_frames[pickupCount][8];
    left_foot_rz = pickup_frames[pickupCount][9];
    right_foot_rz = pickup_frames[pickupCount][10];
    torso_rz = pickup_frames[pickupCount][11];
    head_rz = pickup_frames[pickupCount][12];
    pickupCount++;
    if(pickupCount > 27){
        pickupCount = 0;
        finish_pickup = true;
        finish_walk = true;
        chase_next++;
        resetPlayerPose();
    }
    if(pickupCount == 12){
        removeObj(&mhead,next_chase->x,next_chase->y);
    }
    if(!finish_pickup)glutTimerFunc(1000/27,doPickup,0);
}

void doWalk(int i)
{
    finish_walk = false;
    walk_y = walk_frames[walkCount][0];
    left_arm_rz = walk_frames[walkCount][1];
    right_arm_rz = walk_frames[walkCount][2];
    left_leg_rz = walk_frames[walkCount][3];
    right_leg_rz = walk_frames[walkCount][4];
    left_elbow_rz = walk_frames[walkCount][5];
    right_elbow_rz = walk_frames[walkCount][6];
    left_knee_rz = walk_frames[walkCount][7];
    right_knee_rz = walk_frames[walkCount][8];
    left_foot_rz = walk_frames[walkCount][9];
    right_foot_rz = walk_frames[walkCount][10];
    walkCount++;
    if(walkCount > 27){
        walkCount = 0;
        finish_walk = true;
        resetPlayerPose();
    }
    if(!finish_walk && finish_pickup && finish_potion)glutTimerFunc(1000/(40),doWalk,0);
    else{
        walkCount = 0;
        resetPlayerPose();
    }
}

void doPotion(int i)
{
    finish_potion = false;
    walk_y = potion_frames[potionCount][0];
    left_arm_rz = potion_frames[potionCount][1];
    right_arm_rz = potion_frames[potionCount][2];
    left_leg_rz = potion_frames[potionCount][3];
    right_leg_rz = potion_frames[potionCount][4];
    left_elbow_rz = potion_frames[potionCount][5];
    right_elbow_rz = potion_frames[potionCount][6];
    left_knee_rz = potion_frames[potionCount][7];
    right_knee_rz = potion_frames[potionCount][8];
    left_foot_rz = potion_frames[potionCount][9];
    right_foot_rz = potion_frames[potionCount][10];
    torso_rz = potion_frames[potionCount][11];
    head_rz = potion_frames[potionCount][12];
    right_arm_ry = potion_frames[potionCount][13];
    potionCount++;
    if(mixCount < 10 && potionCount > 23 ){
        mixCount++;
        potionCount = 12;
    }
    if(potionCount > 24){
        potionCount = 0;
        mixCount = 0;
        resetPlayerPose();
        finish_potion = true;
        selected_button = -1;
        itemID = -1;
    }
    if(!finish_potion)glutTimerFunc(1000/27,doPotion,0);
}

void resetPlayerPose(void)
{
    walk_y = 0;

    left_arm_rz = 0;
    right_arm_rz = 0;
    left_leg_rz = 0;
    right_leg_rz = 0;
    left_knee_rz = 0;
    right_knee_rz = 0;
    left_elbow_rz = 0;
    right_elbow_rz = 0;
    left_foot_rz = 0;
    right_foot_rz = 0;

    left_arm_rx = 0;
    right_arm_rx = 0;
    left_leg_rx = 0;
    right_leg_rx = 0;

    left_arm_ry = 0;
    right_arm_ry = 0;
    left_leg_ry = 0;
    right_leg_ry = 0;

    torso_rz = 0;
    torso_ry = 0;

    head_rz = 0;
    head_ry = 0;
}
