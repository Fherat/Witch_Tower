#include "globalstuff.h"

GLint woodFloor;
GLint web;

GLint ambient;

void skyBox(void)
{
    glCullFace(GL_BACK);

    glEnable(GL_TEXTURE_2D);
    glEnable(GL_BLEND);
    glAlphaFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
    glColor4f(1.0,0.5,1.0,1.0);
    glDisable(GL_LIGHT1);
    glDisable(GL_LIGHT2);

    int width = 250;
    int height = 250;
    int length = 250;

    //start in this coordinates
    int x = 0;
    int y = 0;
    int z = 0;

    //center the square
    x =  - width / 2;
    y =  - height / 2;
    z =  - length / 2;

    glColor3f(1.0,1.0,1.0);

    glPushMatrix();

    //BACK
    glBindTexture(GL_TEXTURE_2D,texture_id[1]);
//    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, texturesl[1].width,texturesl[1].height, 0, GL_RGB, GL_UNSIGNED_BYTE,texturesl[1].data);
    glBegin(GL_QUADS);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(x + width, y,  z);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(x + width, y + height, z);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(x, y + height, z);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(x, y, z);
    glEnd();


    //FRONT
    glBindTexture(GL_TEXTURE_2D,texture_id[0]);
//    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, texturesl[0].width,texturesl[0].height, 0, GL_RGB, GL_UNSIGNED_BYTE,texturesl[0].data);
    glBegin(GL_QUADS);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(x, y,  z + length);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(x, y + height, z + length);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(x + width, y + height, z + length);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(x + width, y,  z + length);
    glEnd();

    //BOTTOM
    glBindTexture(GL_TEXTURE_2D,texture_id[2]);
//    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, texturesl[2].width,texturesl[2].height, 0, GL_RGB, GL_UNSIGNED_BYTE,texturesl[2].data);
    glBegin(GL_QUADS);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(x, y,  z);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(x, y,  z + length);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(x + width, y,  z + length);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(x + width, y,  z);
    glEnd();

    //TOP
    glBindTexture(GL_TEXTURE_2D,texture_id[3]);
//    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, texturesl[3].width,texturesl[3].height, 0, GL_RGB, GL_UNSIGNED_BYTE,texturesl[3].data);
    glBegin(GL_QUADS);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(x + width, y + height, z);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(x + width, y + height, z + length);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(x, y + height, z + length);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(x, y + height, z);
    glEnd();

    //LEFT
    glBindTexture(GL_TEXTURE_2D,texture_id[4]);
//    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, texturesl[4].width,texturesl[4].height, 0, GL_RGB, GL_UNSIGNED_BYTE,texturesl[4].data);
    glBegin(GL_QUADS);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(x, y + height, z);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(x, y + height, z + length);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(x, y,  z + length);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(x, y,  z);
    glEnd();

    //RIGHT
    glBindTexture(GL_TEXTURE_2D,texture_id[5]);
//    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, texturesl[5].width,texturesl[5].height, 0, GL_RGB, GL_UNSIGNED_BYTE,texturesl[5].data);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(x + width, y,  z);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(x + width, y,  z + length);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(x + width, y + height, z + length);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(x + width, y + height, z);
    glEnd();

    glPopMatrix();

    glColor3f(0.5,0.5,0.5);
    glDisable(GL_TEXTURE_2D);
    glEnable(GL_LIGHT1);
    glEnable(GL_LIGHT2);
}


//void defineGroundMesh(void)
//{
//    glEnable(GL_DEPTH_TEST);
//    glMap2f(GL_MAP2_VERTEX_3, 0, 1, 3, 10,0,
//            1, 30, 10, &ctrlpoints[0][0][0]);
//    glEnable(GL_MAP2_VERTEX_3);
//    glEnable(GL_AUTO_NORMAL);
//    glMapGrid2f(50, 0.0, 1.0, 50, 0.0, 1.0);
//}




void createAmbient(void)
{
    ambient = glGenLists(13);
    glNewList(ambient,GL_COMPILE);
    {
        glCullFace(GL_FRONT);
        glDisable(GL_LIGHT1);
        glEnable(GL_TEXTURE_2D);

        glBindTexture(GL_TEXTURE_2D,texture_id[6]);
//    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, texturesl[6].width,texturesl[6].height, 0, GL_RGB, GL_UNSIGNED_BYTE,texturesl[6].data);
        glCallList(woodFloor);

        if(cameraX > 20 || cameraX <-20 || cameraZ > 20 || cameraZ < -20) glDisable(GL_CULL_FACE);

        glBindTexture(GL_TEXTURE_2D,texture_id[7]);
//    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, texturesl[7].width,texturesl[7].height, 0, GL_RGB, GL_UNSIGNED_BYTE,texturesl[7].data);
        glPushMatrix();
        glTranslatef(0.0,10.0,-10.0);
        glRotatef(90.0,1.0,0.0,0.0);
        glCallList(woodFloor);
        glPopMatrix();
        glPushMatrix();
        glTranslatef(10.0,10,0.0);
        glRotatef(90.0,0.0,0.0,1.0);
        glRotatef(-90.0,0.0,1.0,0.0);
        glCallList(woodFloor);
        glPopMatrix();
        glPushMatrix();
        glTranslatef(0.0,10.0,10.0);
        glRotatef(-90.0,1.0,0.0,0.0);
        glRotatef(180.0,0.0,1.0,0.0);
        glCallList(woodFloor);
        glPopMatrix();
        glPushMatrix();
        glTranslatef(-10.0,10.0,0.0);
        glRotatef(90.0,1.0,0.0,0.0);
        glRotatef(-90.0,0.0,0.0,1.0);
        glCallList(woodFloor);
        glPopMatrix();

        glBindTexture(GL_TEXTURE_2D,texture_id[14]);
//    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, texturesl[14].width,texturesl[14].height, 0, GL_RGB, GL_UNSIGNED_BYTE,texturesl[14].data);
        glPushMatrix();
        glTranslatef(-3.0,4.5,9.85);
        glRotatef(-90,1.0,0.0,0.0);
        glBegin(GL_POLYGON);
        glTexCoord2f(0.0f, 0.0f);
        glVertex3f(0.0,0.0,0.0);
        glTexCoord2f(1.0f, 0.0f);
        glVertex3f(6.0,0.0,0.0);
        glTexCoord2f(1.0f, 1.0f);
        glVertex3f(6.0,0.0,4.0);
        glTexCoord2f(0.0f, 1.0f);
        glVertex3f(0.0,0.0,4.0);
        glEnd();
        glPopMatrix();



        glEnable(GL_CULL_FACE);
        glCullFace(GL_BACK);
        glEnable(GL_LIGHT1);
        glDisable(GL_TEXTURE_2D);

        lampDraw();
        glPushMatrix();
        glTranslatef(9.0,0.0,-4.0);
        glRotatef(-14,0.0,0.0,1.0);
        broomDraw();
        glPopMatrix();
        glPushMatrix();
        glTranslatef(5,0.03,8.0);
        glRotatef(-90.0,0.0,0.0,1.0);
        glRotatef(-32.0,1.0,0.0,0.0);
        broomDraw();
        glPopMatrix();
        glPushMatrix();
        glTranslatef(0.0,1.0,0.0);
        drawWeb();
        glPopMatrix();
        caldronDraw();

        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D,texture_id[13]);
//    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, texturesl[13].width,texturesl[13].height, 0, GL_RGB, GL_UNSIGNED_BYTE,texturesl[13].data);
        glPushMatrix();
        glTranslatef(-6.75,0.05,0.0);
        glRotatef(-90,0.0,1.0,0.0);
        glBegin(GL_POLYGON);
        glTexCoord2f(0.0f, 0.0f);
        glVertex3f(0.0,0.0,0.0);
        glTexCoord2f(0.0f, 1.0f);
        glVertex3f(0.0,0.0,3.0);
        glTexCoord2f(1.0f, 1.0f);
        glVertex3f(3.0,0.0,3.0);
        glTexCoord2f(1.0f, 0.0f);
        glVertex3f(3.0,0.0,0.0);
        glEnd();
        glPopMatrix();
        glDisable(GL_TEXTURE_2D);

    }
    glEndList();
}

void drawAmbient(void)
{
    glCallList(ambient);
}

int row = 10,col = 10;
double textSize = 1/(double)row;

void createFloorMesh(void)
{
    woodFloor = glGenLists(2);
    glNewList(woodFloor,GL_COMPILE);
    {
        for(int i =0; i < 4; i++)
        {
            for(int j = 0; j < 4; j++)
            {
                glPushMatrix();
                glTranslatef(-7.5+(j*5),0.0,-7.5+(i*5));
                for(int x = 0; x < row ; x++)
                {
                    glPushMatrix();
                    glTranslatef(-2.5,0,-2.5);
                    glBegin(GL_TRIANGLE_STRIP);
                    for(int z = 0; z <= col; z++)
                    {
                        glNormal3f(0,1,0);
                        glTexCoord2f((x*textSize),z*textSize);
                        glVertex3f(0.5*x,0,0.5*z);
                        glNormal3f(0,1,0);
                        glTexCoord2f((x*textSize)+textSize,z*textSize);
                        glVertex3f(0.5*(x+1),0,0.5*z);
                    }
                    glEnd();
                    glPopMatrix();
                }
                glPopMatrix();
            }
        }
    }

    glEndList();
}

void lampDraw(void)
{
    glDisable(GL_CULL_FACE);
    glDisable(GL_LIGHT1);
    glDisable(GL_LIGHT2);
    glPushMatrix();
    glColor3f(0,0,0);
    glTranslatef(0.0,9.5,0.0);
    glLineWidth(2);
    glBegin(GL_LINES);
    glVertex3f(0.0,0.0,0.0);
    glVertex3f(0.0,10.0,0.0);
    glEnd();
    glLineWidth(1);
    drawCylinder(1,0.0,1);
    glEnable(GL_BLEND);
    glDepthMask(GL_FALSE);
    glColor4f(1.0,1.0,0.0,0.2);
    glTranslatef(0.0,-0.1,0.0);
    glutSolidSphere(0.3,10,10);
    glDisable(GL_BLEND);
    glDepthMask(GL_TRUE);
    glTranslatef(0.0,-0.02,0.0);
    glutSolidSphere(0.1,10,10);
    glPopMatrix();

    glEnable(GL_CULL_FACE);
    glEnable(GL_LIGHT1);
    glEnable(GL_LIGHT2);
}

void drawWebCircle(GLfloat x, GLfloat y, GLfloat radius,GLint triangleAmount)
{
    int i;
    float radius1 = 1.0;
    float radius2 = 2.0;

    GLfloat twicePi = 2.0f * M_PI;
    GLfloat radiusX[triangleAmount];
    GLfloat radiusY[triangleAmount];
    GLfloat radiusX1[triangleAmount];
    GLfloat radiusY1[triangleAmount];
    GLfloat radiusX2[triangleAmount];
    GLfloat radiusY2[triangleAmount];

    for(i = 0; i <= triangleAmount; i++)
    {
        radiusX[i] = (radius * cos(i *  twicePi / triangleAmount));
        radiusY[i] = (radius * sin(i *  twicePi / triangleAmount));
    }
    for(i = 0; i <= triangleAmount; i++)
    {
        radiusX1[i] = (radius1 * cos(i *  twicePi / triangleAmount));
        radiusY1[i] = (radius1 * sin(i *  twicePi / triangleAmount));
    }
    for(i = 0; i <= triangleAmount; i++)
    {
        radiusX2[i] = (radius2 * cos(i *  twicePi / triangleAmount));
        radiusY2[i] = (radius2 * sin(i *  twicePi / triangleAmount));
    }

    glBegin(GL_LINES);
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex3f(x + radiusX1[i], y + radiusY1[i], 0.0);
        glVertex3f(x + radiusX2[i], y + radiusY2[i], 0.0);
    }
    glEnd();


    glPushMatrix();
    for(i = 0; i <= triangleAmount; i++)
    {
    glBegin(GL_LINES);
        glVertex2f(0.0, 0.0); // center of circle
        glVertex3f(radiusX[i],radiusY[i], 0.0);
    glEnd();
    }
    glPopMatrix();

    glPushMatrix();
    glBegin(GL_LINE_LOOP); //draws circle;
    for (int i=0; i<=triangleAmount; i++)
    {
        glVertex3f(radiusX[i],radiusY[i],0);
    }
    glEnd();
    glPopMatrix();
}

void defineWeb(void)
{
    web = glGenLists(3);
    glNewList(web,GL_COMPILE);
    {
        glPushMatrix();
        drawWebCircle(0.0,0.0,0.5,8.0);
        drawWebCircle(0.0,0.0,0.75,8.0);
        drawWebCircle(0.0,0.0,1.0,8.0);
        glPopMatrix();
    }
    glEndList();
}

void drawWeb(void)
{
    glColor3f(1.0,1.0,1.0);
    glPushMatrix();
    glTranslatef(9.0,0.0,-9.25);
    glRotatef(45,-1.0,0.0,1.0);
    glCallList(web);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(9.9,0.0,0.0);
    glRotatef(90,0.0,1.0,0.0);
    glCallList(web);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-9.9,4.0,5.0);
    glRotatef(90,0.0,1.0,0.0);
    glCallList(web);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0.0,4.0,-9.98);
//        glRotatef(90,0.0,1.0,0.0);
    glCallList(web);
    glPopMatrix();
}

void broomDraw(void)
{
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,texture_id[6]);
    glPushMatrix();
    glTranslatef(0.0,1.0,0.0);
        drawCylinder(3.0,0.05,0.05);
    glPopMatrix();

    glBindTexture(GL_TEXTURE_2D,texture_id[11]);
    glPushMatrix();
        glScalef(0.5,1.0,1.0);
        drawCylinder(1.0,0.05,0.4);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
}

void caldronDraw(void)
{
    glPushMatrix();
    glTranslatef(-8.8,0.0,-8.8);
    glColor3f(0.0,0.0,0.0);
    glPushMatrix();
        glTranslatef(0.0,1.0,0.0);
        glutSolidSphere(1.0,20,20);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(0.0,1.5,0.0);
        drawCylinder(0.5,1.0,0.0);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(-0.5,0.0,0.75);
        glRotatef(-35.0,1.0,0.0,0.75);
        drawCylinder(0.5,0.1,0.05);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(1.0,0.0,0.0);
        glRotatef(35.0,0.0,0.0,1.0);
        drawCylinder(0.5,0.1,0.05);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(-0.75,0.0,-0.75);
        glRotatef(35.0,1.0,0.0,-1.0);
        drawCylinder(0.5,0.1,0.05);
    glPopMatrix();

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,texture_id[15]);
    glColor3f(0.5,0.5,0.5);
    glPushMatrix();
        glTranslatef(0.0,2.0,0.0);
        glRotatef(180.0,1.0,0.0,0.0);
        glScalef(1.0,0.1,1.0);
        gluSphere(head,0.8,20,20);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();
    glColor3f(0.5,0.5,0.5);
}

void towerDraw()
{
    glEnable(GL_TEXTURE_2D);

    glCullFace(GL_FRONT_AND_BACK);
    if(cameraX > 25 || cameraX <-25 || cameraZ > 25 || cameraZ < -25)
    {
        glDisable(GL_CULL_FACE);
    }
    glBindTexture(GL_TEXTURE_2D,texture_id[12]);
//    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, texturesl[12].width,texturesl[12].height, 0, GL_RGB, GL_UNSIGNED_BYTE,texturesl[12].data);
    glPushMatrix();
    glTranslatef(0.0,-30.0,0.0);
    drawCylinder(50.0,15.0,15.0);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0.0,-80.0,0.0);
    drawCylinder(50.0,15.0,15.0);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0.0,-130.0,0.0);
    drawCylinder(50.0,15.0,15.0);
    glPopMatrix();

    glCullFace(GL_FRONT);

    glBindTexture(GL_TEXTURE_2D,texture_id[8]);
//    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, texturesl[8].width,texturesl[8].height, 0, GL_RGB, GL_UNSIGNED_BYTE,texturesl[8].data);
    glDisable(GL_CULL_FACE);
    glPushMatrix();
    glTranslatef(0.0,20.0,0.0);
    drawCylinder(10.0,0.0,18.0);
    glPopMatrix();
    glEnable(GL_CULL_FACE);

    glDisable(GL_TEXTURE_2D);
}
