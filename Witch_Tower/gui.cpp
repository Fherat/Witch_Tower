#include "globalstuff.h"

bool expandSelect = false;
bool showMenu = false;

int itemID = -1;
int selectedID = -1;

void textOutput(float lwidth,float scale, float pos_x, float pos_y,float pos_z,
                float r, float g, float b, void* font, char *string, int width, int height)
{
    glDisable(GL_LIGHTING);

    glLineWidth(lwidth);


    double matrix[16];
    glMatrixMode(GL_PROJECTION);
    glGetDoublev(GL_PROJECTION_MATRIX, matrix);
    glLoadIdentity();
    glOrtho(0.0, width, 0.0, height, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glPushMatrix();
        glLoadIdentity();
        glColor3f(r, g, b);
            glPushMatrix();
            glTranslatef(pos_x, pos_y, 0);
            glScalef(scale,scale,1);
            char *c;
            for (c = string; *c; c++)
            {
                glutStrokeCharacter(GLUT_STROKE_ROMAN, *c);
            }
            glPopMatrix();
    glPopMatrix();

    glEnable(GL_LIGHTING);
}

void fpsText(void)
{

    snprintf(screen_current_fps, 9, "%d", current_fps);
    char fps_text_cpy[6];
    memset(fps_text_cpy, '\0', sizeof(fps_text_cpy));
    strcpy(fps_text_cpy,screen_fps_text);
    strcat(fps_text_cpy,screen_current_fps);
    textOutput(1, 0.15, 1, height-20, 0, 1, 1, 0,
               GLUT_BITMAP_TIMES_ROMAN_24, fps_text_cpy, width, height);
}

void crosshair(void)
{
    glDisable(GL_LIGHTING);

    glLineWidth(3);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, width, height, 0, -1, 1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glPushMatrix();
        glLoadIdentity();
        glPushMatrix();
            glTranslatef(mouseX,mouseY,0);
            if(pos_y < 0.3 && pos_y > -0.1 && pos_x < 9.7
               && pos_x > -9.7 && pos_z < 9.7 && pos_z > -9.7) glColor3f(0.0,1.0,0.0);
            else glColor3f(1.0,0.0,0.0);
            float angulo;
            glBegin(GL_LINE_LOOP); //draws circle;
            for (int i=0; i<=10; i++)
            {
                angulo= 2 * M_PI * i / 10.0;
                glVertex3f(5*cos(angulo),5*sin(angulo),0);
            }
            glEnd();
        glPopMatrix();
    glPopMatrix();
    glLineWidth(1);

    glEnable(GL_LIGHTING);
}


void menuDraw()
{
    glEnable(GL_TEXTURE_2D);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, width, height, 0, -1, 1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glPushMatrix();
        glLoadIdentity();

    if(checkGuiColision(mouseX,mouseY,0.0,height/2-40.0,20.0,80.0)){
        glColor3f(0.5,0.5,0.5);
        expandSelect = true;
        selected_button = -1;
    }
    else{
         glColor3f(1.0,1.0,1.0);
         expandSelect = false;
    }
    glBindTexture(GL_TEXTURE_2D,texture_id[17]);
    glPushMatrix();
        glTranslatef(0.0,height/2-40.0,0.0);
        glScalef(20.0,20.0,20.0);
        glBegin(GL_POLYGON);
            glTexCoord2f(0.0,0.0);
            glVertex3f(0.0,0.0,0.0);
            glTexCoord2f(0.0,1.0);
            glVertex3f(0.0,4.0,0.0);
            glTexCoord2f(1.0,1.0);
            glVertex3f(1.0,4.0,0.0);
            glTexCoord2f(1.0,0.0);
            glVertex3f(1.0,0.0,0.0);
        glEnd();
    glPopMatrix();


    if(showMenu){
        button(40.0,100.0,1,18);
        button(130.0,100.0,2,19);

        button(40.0,130.0,3,20);
        button(130.0,130.0,4,21);

        button(40.0,160.0,5,22);
        button(130.0,160.0,6,23);

        button(40.0,190.0,7,24);
        button(130.0,190.0,8,25);

        button(40.0,220.0,9,26);
        button(130.0,220.0,10,27);

        button(40.0,250.0,11,28);
        button(130.0,250.0,12,29);

        button(40.0,280.0,13,30);
        button(130.0,280.0,14,31);

        button(40.0,310.0,15,32);
        button(130.0,310.0,16,33);

        button(40.0,340.0,17,34);
        button(130.0,340.0,18,35);

        button(40.0,370.0,19,36);
        button(130.0,370.0,20,37);

        button(40.0,400.0,21,38);
        button(130.0,400.0,22,39);

        button(80.0,430.0,23,40);

    }

    button(width/2-40.0,10.0,24,41);

    glPopMatrix();

    glDisable(GL_TEXTURE_2D);

}

bool checkGuiColision(float x, float y, float x2, float y2, float objwidth, float objheight)
{
    if(x >= x2 && x <= x2+objwidth && y >= y2 && y <= y2+objheight){
        return true;
    }
    return false;
}

void button(float x, float y, int id, int texID)
{
    if(id == selected_button)
    {
        glColor3f(1.0,0.5,0.5);
    }
    else if(checkGuiColision(mouseX,mouseY,x,y,80.0,20.0))
    {
        glColor3f(0.5,0.5,1.0);
        itemID = id;
    }
    else{
        glColor3f(1.0,1.0,1.0);
    }
    glBindTexture(GL_TEXTURE_2D,texture_id[texID]);
    glPushMatrix();
        glTranslatef(x,y,0.0);
        glScalef(20.0,20.0,20.0);
        glBegin(GL_POLYGON);
            glTexCoord2f(0.0,0.0);
            glVertex3f(0.0,0.0,0.0);
            glTexCoord2f(0.0,1.0);
            glVertex3f(0.0,1.0,0.0);
            glTexCoord2f(1.0,1.0);
            glVertex3f(4.0,1.0,0.0);
            glTexCoord2f(1.0,0.0);
            glVertex3f(4.0,0.0,0.0);
        glEnd();
    glPopMatrix();
}
