#ifndef GUI_H_INCLUDED
#define GUI_H_INCLUDED

extern bool expandSelect;
extern bool showMenu;

extern int itemID;
extern int selectedID;

void textOutput(float, float, float, float, float, float,
                 float, float, void*, char*, int, int);
void fpsText(void);
void crosshair(void);
void menuDraw(void);
bool checkGuiColision(float, float, float, float, float, float);
void button(float, float, int, int);

#endif // GUI_H_INCLUDED
