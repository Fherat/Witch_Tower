#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

extern double player_ang;
extern float walk_dir;
extern double lastang;

extern int chase_next;

extern struct Points* next_chase;

extern float scale;

extern GLfloat player_X;
extern GLfloat player_Y;
extern GLfloat player_Z;
extern GLfloat player_rotate;

extern float walk_y;
extern float left_arm_rz;
extern float right_arm_rz;
extern float left_leg_rz;
extern float right_leg_rz;
extern float left_knee_rz;
extern float right_knee_rz;
extern float left_elbow_rz;
extern float right_elbow_rz;
extern float left_foot_rz;
extern float right_foot_rz;

extern float left_arm_rx;
extern float right_arm_rx;
extern float left_leg_rx;
extern float right_leg_rx;

extern float left_arm_ry;
extern float right_arm_ry;
extern float left_leg_ry;
extern float right_leg_ry;

extern float torso_rz;
extern float torso_rx;
extern float torso_ry;

extern float head_rz;
extern float head_ry;

extern int player_HP;

extern GLUquadricObj *leg;
extern GLUquadricObj *head;

extern float pickup_frames[27][13];
extern float walk_frames[29][11];
extern float potion_frames[24][14];

extern bool finish_walk;
extern bool finish_pickup;
extern bool finish_potion;

extern int pickupCount;
extern int walkCount;
extern int potionCount;

void drawCircle(GLfloat, GLfloat, GLfloat,GLint);
void defineLegCylinder(void);
void defineHeadSphere(void);
void drawCylinder(float, float, float);
void tightDraw(float, float, float, float, float);
void shinDraw(float, float, float , float , float);
void footDraw(float ,float ,float);
void defineLegCylinder(void);
void drawPlayer(int);
void chaseRats(void);
void chaseCaldron(void);
void doWalk(int);
void doPickup(int);
void doPotion(int);
void resetPlayerPose(void);

#endif // PLAYER_H_INCLUDED
