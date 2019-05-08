#include "globalstuff.h"




void createMenu(void){

    menu_id = glutCreateMenu(menu);
    glutAddMenuEntry("1- ombro esquerdo rx", 1);
    glutAddMenuEntry("2- ombro direito rx", 2);
    glutAddMenuEntry("3- ombro esquerdo ry", 3);
    glutAddMenuEntry("4- ombro direito ry", 4);
    glutAddMenuEntry("5- ombro esquerdo rz", 5);
    glutAddMenuEntry("6- ombro direito rz", 6);
    glutAddMenuEntry("7- perna esquerda rx", 7);
    glutAddMenuEntry("8- perna direita rx", 8);
    glutAddMenuEntry("9- perna esqueda ry", 9);
    glutAddMenuEntry("10- perna direita ry, 10);
    glutAddMenuEntry("11- perna esquerda rz", 11);
    glutAddMenuEntry("12- perna direita rz", 12);
    glutAddMenuEntry("13- pé esquerdo rz", 13);
    glutAddMenuEntry("14- pée direito rz", 14);
    glutAddMenuEntry("15- head rx", 15);
    glutAddMenuEntry("16- head rz", 16);
    glutAddMenuEntry("17- altura", 17);
    glutAddMenuEntry("cintura rx", 18);
    glutAddMenuEntry("cintura ry", 19);
    glutAddMenuEntry("cintura rz", 20);
    glutAddMenuEntry("Sair", 0);
    glutAttachMenu(GLUT_MIDDLE_BUTTON);

}
