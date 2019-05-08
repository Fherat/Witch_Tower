#ifndef GLOBALSTUFF_H_INCLUDED
#define GLOBALSTUFF_H_INCLUDED

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

#include "camera.h"
#include "gui.h"
#include "interactions.h"
#include "lights.h"
#include "ambient.h"
#include "monsters.h"
#include "player.h"
#include "bpmLoader.h"

#define FRAMES 60

extern int initial_time, final_time, frame_count;
extern int current_fps;
extern float todeg;

extern GLint mouseX;
extern GLint mouseY;

extern char screen_current_fps[9];
extern char screen_fps_text[6];

extern int game_pause;

struct Point
{
    int x;
    int y;
};

struct Points
{
    float x;
    float y;
    int id;
    int rotation;

    struct Points *next;
};

//Linked List Functions
bool   isEmpty(struct Points* head);
void   insertFirst(struct Points**, float, float,int,int);
struct Points* deleteFirst(struct Points**);
int    length(struct Points*);
struct Points* findObj(struct Points**, int);
struct Points* removeObj(struct Points**, float, float);
void   freeList(struct Points*);
//---------------------

void renderScene(void);
void callbacks(void);
void initialSetup(void);

bool checkCollision(float, float, float, float, float, float);

int fpsCounter(void);

double degToRadians(double);

void doJump(int);
void doWalk(int);

#endif // GLOBALSTUFF_H_INCLUDED
