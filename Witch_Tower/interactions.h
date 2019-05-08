#ifndef INTERACTIONS_H_INCLUDED
#define INTERACTIONS_H_INCLUDED

#include "globalstuff.h"

extern GLdouble pos_x;
extern GLdouble pos_y;
extern GLdouble pos_z;

extern GLdouble projection_matrix[16];
extern GLdouble view_matrix[16];
extern GLint viewport_matrix[16];

extern int mouseX;
extern int mouseY;

extern bool cam_motion;
extern int mleft_button_signal;

extern int selected_button;

void keyboardHandler(unsigned char, int, int);
void specialKeys(int, int, int);
void mouseHandler(int, int, int, int);
void mousePicking(void);
void mouseMotion(int x, int y);

#endif // INTERACTIONS_H_INCLUDED
