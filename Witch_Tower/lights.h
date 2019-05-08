#ifndef LIGHTS_H_INCLUDED
#define LIGHTS_H_INCLUDED

extern GLfloat light_ambient[];

extern GLfloat light1_ambient[];
extern GLfloat light1_diffuse [];
extern GLfloat light1_specular[];
extern GLfloat light1_position[];

extern GLfloat light2_diffuse[];
extern GLfloat light2_position[];

extern GLfloat light3_diffuse [];
extern GLfloat light3_position[];

extern GLfloat light4_diffuse [];
extern GLfloat light4_position[];
extern GLfloat light4_direction[];

extern GLfloat light_spot_direction[];

void setLights(void);
void updateLightPosition(void);

#endif // LIGHTS_H_INCLUDED
