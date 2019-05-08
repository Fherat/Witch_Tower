#include "globalstuff.h"

GLdouble pos_x = 0;
GLdouble pos_y = 0;
GLdouble pos_z = 0;

GLdouble projection_matrix[16];
GLdouble view_matrix[16];
GLint viewport_matrix[16];

bool cam_motion;

int mleft_button_signal = 0;

int selected_button = -1;

void keyboardHandler(unsigned char key, int x, int y )
{
    if(!game_pause)
    {
        switch ( key )
        {
        case 'm':
        case 'M':
            GLint polygonMode;
            glGetIntegerv(GL_POLYGON_MODE, &polygonMode);
            if(polygonMode == GL_FILL)glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
            else glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
            break;
        }
    }
    switch(key)
    {
    case '1':
        walk_y +=0.1;
        break;
    case '2':
        walk_y -=0.1;
        break;
    case 'P':
    case 'p':
        pickupCount = 0;
        walkCount = 0;
        finish_pickup = !finish_pickup;
        finish_walk = !finish_walk;
        break;
    case 'f':
    case 'F':
        glutPositionWindow(0,0);
        glutReshapeWindow(glutGet(GLUT_SCREEN_WIDTH),glutGet(GLUT_SCREEN_HEIGHT));
        break;
    case 'g':
    case 'G':
        width = 800;
        height = 600;
        glutPositionWindow(350,50);
        glutReshapeWindow(width,height);
        break;
    case 'o':
    case 'O':
        printf("%f -- %f,%f,%f,%f,%f,%f,%f,%f,%f,%f -- %f - %f\n\n",walk_y,left_arm_rz,right_arm_rz,left_leg_rz,right_leg_rz,
               left_elbow_rz,right_elbow_rz,left_knee_rz,right_knee_rz,left_foot_rz,right_foot_rz,torso_rz,head_rz);
        break;
    case 27:
        glutDestroyWindow(glutGetWindow());
        freeList(mhead);
        printf("Free list\n");
        exit(0);
        break;
    }
}

void specialKeys(int key, int x, int y)
{
    switch(key)
    {
    case GLUT_KEY_UP:
        switch(selected_button)
        {
        case 1:
            if(left_arm_rz < 180)left_arm_rz += 5;
            break;
        case 2:
            if(right_arm_rz < 180)right_arm_rz += 5;
            break;
        case 3:
            if(left_arm_rx < 110)left_arm_rx += 5;
            break;
        case 4:
            if(right_arm_rx > -110)right_arm_rx -= 5;
            break;
        case 5:
            if(left_arm_ry < 90)left_arm_ry += 5;
            break;
        case 6:
            if(right_arm_ry < 90)right_arm_ry += 5;
            break;
        case 7:
            if(left_elbow_rz < 170)left_elbow_rz += 5;
            break;
        case 8:
            if(right_elbow_rz < 170)right_elbow_rz += 5;
            break;
        case 9:
            if(left_leg_rz < 90)left_leg_rz += 5;
            break;
        case 10:
            if(right_leg_rz < 90)right_leg_rz += 5;
            break;
        case 11:
            if(left_leg_rx < 60)left_leg_rx += 5;
            break;
        case 12:
            if(right_leg_rx > -60)right_leg_rx -= 5;
            break;
        case 13:
            if(left_leg_ry < 90)left_leg_ry += 5;
            break;
        case 14:
            if(right_leg_ry > -90)right_leg_ry -= 5;
            break;
        case 15:
            if(left_knee_rz < 0)left_knee_rz += 5;
            break;
        case 16:
            if(right_knee_rz < 0)right_knee_rz += 5;
            break;
        case 17:
            if(left_foot_rz < 60)left_foot_rz += 5;
            break;
        case 18:
            if(right_foot_rz < 60)right_foot_rz += 5;
            break;
        case 19:
            if(torso_rz < 30)torso_rz += 5;
            break;
        case 20:
            if(torso_ry < 20)torso_ry += 5;
            break;
        case 21:
            if(head_rz < 70)head_rz += 5;
            break;
        case 22:
            if(head_ry < 90)head_ry += 5;
            break;
        }
        break;
    case GLUT_KEY_DOWN:
        switch(selected_button)
        {
        case 1:
            if(left_arm_rz > -20)left_arm_rz -= 5;
            break;
        case 2:
            if(right_arm_rz > -20)right_arm_rz -= 5;
            break;
        case 3:
            if(left_arm_rx > 0)left_arm_rx -= 5;
            break;
        case 4:
            if(right_arm_rx < 0)right_arm_rx += 5;
            break;
        case 5:
            if(left_arm_ry > -90)left_arm_ry -= 5;
            break;
        case 6:
            if(right_arm_ry > -90)right_arm_ry -= 5;
            break;
        case 7:
            if(left_arm_rx > 0)left_elbow_rz -= 5;
            break;
        case 8:
            if(left_arm_rx > 0)right_elbow_rz -= 5;
            break;
        case 9:
            if(left_leg_rz > -20)left_leg_rz -= 5;
            break;
        case 10:
            if(right_leg_rz > -20)right_leg_rz -= 5;
            break;
        case 11:
            if(left_leg_rx > 0)left_leg_rx -= 5;
            break;
        case 12:
            if(right_leg_rx < 0)right_leg_rx += 5;
            break;
        case 13:
            if(left_leg_ry > 0)left_leg_ry -= 5;
            break;
        case 14:
            if(right_leg_ry < 0)right_leg_ry += 5;
            break;
        case 15:
            if(left_knee_rz > -170)left_knee_rz -= 5;
            break;
        case 16:
            if(right_knee_rz > -170)right_knee_rz -= 5;
            break;
        case 17:
            if(left_foot_rz > -60)left_foot_rz -= 5;
            break;
        case 18:
            if(right_foot_rz > -60)right_foot_rz -= 5;
            break;
        case 19:
            if(torso_rz > -90)torso_rz -= 5;
            break;
        case 20:
            if(torso_ry > -90)torso_ry -= 5;
            break;
        case 21:
            if(head_rz > -80)head_rz -= 5;
            break;
        case 22:
            if(head_ry > -90)head_ry -= 5;
            break;
        }
    }
}

void mouseHandler(int button, int state, int x, int y)
{
    switch(button)
    {
    case GLUT_RIGHT_BUTTON:

        if((state == GLUT_DOWN))
        {
            cam_motion = true;
            glutWarpPointer(width/2,height/2);
        }
        if(state == GLUT_UP)
        {
            cam_motion = false;
            glutWarpPointer(mouseX,mouseY);
        }
        break;
    case GLUT_LEFT_BUTTON:
        if((state == GLUT_DOWN) )
        {
            if(pos_y < 0.3 && pos_x < 9.7
                    && pos_x > -9.7 && pos_z < 9.7 && pos_z > -9.7 && selected_button != 24)
            {
                insertFirst(&mhead,pos_x,pos_z,id_count,rand()%360);
                id_count++;
            }
            if(expandSelect)
            {
                showMenu = !showMenu;
            }
            switch(itemID)
            {
            case 1:
                selected_button = 1;
                break;
            case 2:
                selected_button = 2;
                break;
            case 3:
                selected_button = 3;
                break;
            case 4:
                selected_button = 4;
                break;
            case 5:
                selected_button = 5;
                break;
            case 6:
                selected_button = 6;
                break;
            case 7:
                selected_button = 7;
                break;
            case 8:
                selected_button = 8;
                break;
            case 9:
                selected_button = 9;
                break;
            case 10:
                selected_button = 10;
                break;
            case 11:
                selected_button = 11;
                break;
            case 12:
                selected_button = 12;
                break;
            case 13:
                selected_button = 13;
                break;
            case 14:
                selected_button = 14;
                break;
            case 15:
                selected_button = 15;
                break;
            case 16:
                selected_button = 16;
                break;
            case 17:
                selected_button = 17;
                break;
            case 18:
                selected_button = 18;
                break;
            case 19:
                selected_button = 19;
                break;
            case 20:
                selected_button = 20;
                break;
            case 21:
                selected_button = 21;
                break;
            case 22:
                selected_button = 22;
                break;
            case 23:
                selected_button = -1;
                resetPlayerPose();
                break;
            case 24:
                if(next_chase == NULL && finish_walk && finish_pickup){
                        selected_button = 24;
                }
                break;
            }
        }
        break;
    case 3: //wheel down
        if(distp < 100) distp += 0.6;
        break;
    case 4: //wheel up
        if(distp > 0.5) distp -= 0.6;
        break;
    }
}

void mousePicking(void)
{
    glGetDoublev( GL_MODELVIEW_MATRIX, view_matrix );
    glGetDoublev( GL_PROJECTION_MATRIX, projection_matrix );
    glGetIntegerv( GL_VIEWPORT, viewport_matrix );

    GLfloat winX;
    GLfloat winY;
    GLfloat winZ;

    winX = (float)mouseX;
    winY = ((float)viewport_matrix[3] - (float)mouseY);
    glReadPixels( mouseX, int(winY), 1, 1, GL_DEPTH_COMPONENT, GL_FLOAT, &winZ );

    gluUnProject( winX, winY, winZ, view_matrix, projection_matrix, viewport_matrix, &pos_x, &pos_y, &pos_z);
}

void mouseMotion(int x, int y)
{
    mouseX = x;
    mouseY = y;
}
