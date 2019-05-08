#ifndef CAMERA_H_INCLUDED
#define CAMERA_H_INCLUDED

#include "globalstuff.h"

/*Camera Parameters */
extern GLfloat angle, fAsp, distp, angleY; // camera definitions
extern GLfloat transX, transY, transZ;
extern GLfloat cameraX, cameraY, cameraZ; //Camera Position
extern GLdouble  yaw, pitch;
//--------------

/*Camera Motion */
extern int oldCamx,oldCamy;
//---------------

/* Window Size */
extern GLsizei width,height;
//---------------

void updateCameraView(void);
void cameraMotion(int,int);
void resizeWindow(GLsizei, GLsizei);

#endif // CAMERA_H_INCLUDED
