#ifndef BPMLOADER_H_INCLUDED
#define BPMLOADER_H_INCLUDED

#include "globalstuff.h"
#include <unistd.h>

struct BMPImagem
{
    int   width;
    int   height;
    char *data;
};

typedef struct BMPImagem BMPImage;

extern GLuint texture_id[50];
extern int tnum;

extern BMPImage texturesl[50];

void getBitmapImageData(char*, BMPImage*);
BMPImage loadTexture(char*, int);
void loadAllTextures(void);

#endif // BPMLOADER_H_INCLUDED
