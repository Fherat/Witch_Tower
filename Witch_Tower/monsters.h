#ifndef MONSTERS_H_INCLUDED
#define MONSTERS_H_INCLUDED

#include "globalstuff.h"

extern GLfloat rat[4][3];

extern struct Points *mhead;
extern struct Points *mcurrent;

extern int wave;
extern int colision_signal;

extern int id_count;


extern GLint monster_list;

void genMonsters(void);
void createMonsterList(void);
void renderMonsters(void);
void colisionAction(float, float);
void seekPlayer(struct Points*, float, float);

#endif // MONSTERS_H_INCLUDED
