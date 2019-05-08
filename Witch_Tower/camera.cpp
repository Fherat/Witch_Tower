#include "globalstuff.h"

/*Camera Parameters*/
GLfloat angle = 60.0, fAsp, distp = 80.0, angleY = 0; // camera definitions
GLfloat cameraX = 0, cameraY = 0, cameraZ = 0; //Camera Position
//-----------------

/*Camera Rotations*/
GLdouble yaw = 0, pitch = 40;
//------------------

/*Camera Motion */
int oldCamx = 0,oldCamy = 0;
//---------------

/* Window Size */
GLsizei width = 800,height = 600;
//---------------

/*Sets the camera view. Used on the display function*/
void updateCameraView(void)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(angle,fAsp,0.1,1500);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    yaw   = fmod(yaw,360   );
    pitch = fmod(pitch,360 );
    GLfloat camX = player_X + distp*cos(degToRadians(pitch))*sin(degToRadians(yaw));
    GLfloat camY = player_Y + distp*sin(degToRadians(pitch));
    GLfloat camZ = player_Z + distp*cos(degToRadians(pitch))*cos(degToRadians(yaw));
    cameraX = camX;
    cameraY = camY;
    cameraZ = camZ;
    gluLookAt(cameraX, cameraY+3.5, cameraZ, player_X, player_Y+3.5, player_Z, 0.0, 1.0, 0.0);
}
//----------------

/*Resize Window*/
void resizeWindow(GLsizei w, GLsizei h)
{
    width = w;
    height = h;

    if ( h == 0 )
    {
        h = 1;
    }

    glViewport(0, 0, w, h);

    fAsp = (GLfloat)w / (GLfloat)h;
}
//------------------

/*Handle camera motion (angles). It makes 'pitch' and 'yaw' movements. */
void cameraMotion(int x,int y)
{
    if(cam_motion)
    {
        if(x > oldCamx)
        {
            yaw -= 1.8;
        }
        if(x < oldCamx)
        {
            yaw += 1.8;
        }
        if(y > oldCamy && pitch < 89)
        {
            pitch += 0.8;
        }
        if(y < oldCamy && pitch > 0)
        {
            pitch -= 0.8;
        }
    }
    else
    {
        mouseX = x;
        mouseY = y;
    }
    oldCamx = x;
    oldCamy = y;
}
//-----------------------------------
