#include "globalstuff.h"

GLfloat light_ambient[] = { 1.0, 1.0, 1.0, 1.0 };

GLfloat light1_ambient [] = { 0.2, 0.2, 0.2, 1.0 };
GLfloat light1_diffuse [] = { 1.2, 1.2, 0.3, 1.0 };
GLfloat light1_specular[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat light1_position[] = { 0.0, 9.0, 0.0, 1.0 };

GLfloat light2_diffuse [] = { 10.0, 10.0, 0.5, 1.0 };
GLfloat light2_position[] = { 0.0, 9.0, 0.0, 1.0 };

GLfloat light3_diffuse [] = { 0.0, 0.0, 50.0, 100.0 };
GLfloat light3_position[] = { 0.0, 2.0, 0.0, 1.0 };

GLfloat light4_diffuse [] = { 0.0, 5.0, 0.0, 100.0 };
GLfloat light4_position[] = { -9.0, 0.0, -9.0, 1.0 };
GLfloat light4_direction[] = { 0.0, 0.5, 0.0};

GLfloat light_spot_direction[] = { 0.0, -1.0, 0.0};

void setLights(void)
{
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, light_ambient);

    glLightfv(GL_LIGHT1, GL_AMBIENT , light1_ambient  );
    glLightfv(GL_LIGHT1, GL_DIFFUSE , light1_diffuse  );
    glLightfv(GL_LIGHT1, GL_SPECULAR, light1_specular );

//    glLightfv(GL_LIGHT2,GL_AMBIENT,light2_ambient);
    glLightfv(GL_LIGHT2, GL_DIFFUSE , light2_diffuse  );
    glLightfv(GL_LIGHT2, GL_POSITION, light2_position );
    glLightf (GL_LIGHT2, GL_SPOT_CUTOFF,  50.0 );
    glLightf (GL_LIGHT2, GL_SPOT_EXPONENT, 10.0 );

    glLightfv(GL_LIGHT3, GL_DIFFUSE , light3_diffuse  );
    glLightfv(GL_LIGHT3, GL_POSITION, light3_position );
    glLightf (GL_LIGHT3, GL_SPOT_CUTOFF,   50.0 );
    glLightf (GL_LIGHT3, GL_SPOT_EXPONENT, 0.0 );

    glLightfv(GL_LIGHT4, GL_DIFFUSE , light4_diffuse  );
    glLightfv(GL_LIGHT4, GL_POSITION, light4_position );
    glLightf (GL_LIGHT4, GL_SPOT_CUTOFF,   90.0 );
    glLightf (GL_LIGHT4, GL_SPOT_EXPONENT, 10.0 );

    GLfloat mat_ambient  [4] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat mat_diffuse  [4] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat mat_specular [4] = { 0.5, 0.5, 0.5, 1.0 };
    GLfloat mat_shininess[ ] = { 20 };
    glMaterialfv(GL_FRONT, GL_AMBIENT  , mat_ambient  );
    glMaterialfv(GL_FRONT, GL_DIFFUSE  , mat_diffuse  );
    glMaterialfv(GL_FRONT, GL_SPECULAR , mat_specular );
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);

    glEnable(GL_LIGHT1);
    glEnable(GL_LIGHT2);
    glEnable(GL_LIGHT3);
    glEnable(GL_LIGHT4);
}

void updateLightPosition(void)
{
    GLfloat light3_pos[] = { (float)pos_x, 2.0, (float)pos_z, 1.0 };

    glLightfv(GL_LIGHT1, GL_POSITION,light1_position);

    glLightfv(GL_LIGHT2, GL_POSITION,light2_position);
    glLightfv(GL_LIGHT2, GL_SPOT_DIRECTION, light_spot_direction);

    glLightfv(GL_LIGHT3, GL_POSITION,light3_pos);
    glLightfv(GL_LIGHT3, GL_SPOT_DIRECTION, light_spot_direction);


    glLightfv(GL_LIGHT4, GL_POSITION, light4_position );
    glLightfv(GL_LIGHT4, GL_SPOT_DIRECTION, light4_direction);
}
