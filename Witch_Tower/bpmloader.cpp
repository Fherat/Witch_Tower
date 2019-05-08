#include "globalstuff.h"

GLuint texture_id[50];
int tnum = 1;

BMPImage texturesl[50];

void getBitmapImageData( char *pFileName, BMPImage *pImage )
{
    FILE *pFile = NULL;
    unsigned short nNumPlanes;
    unsigned short nNumBPP;
    int i;

    if( (pFile = fopen(pFileName, "rb") ) == NULL )
        printf("ERROR: getBitmapImageData - %s not found.\n", pFileName);

    // Seek forward to width and height info
    fseek( pFile, 18, SEEK_CUR );

    if( (i = fread(&pImage->width, 4, 1, pFile) ) != 1 )
        printf("ERROR: getBitmapImageData - Couldn't read width from %s.\n ", pFileName);

    if( (i = fread(&pImage->height, 4, 1, pFile) ) != 1 )
        printf("ERROR: getBitmapImageData - Couldn't read height from %s.\n ", pFileName);

    if( (fread(&nNumPlanes, 2, 1, pFile) ) != 1 )
        printf("ERROR: getBitmapImageData - Couldn't read plane count from %s.\n", pFileName);

    if( nNumPlanes != 1 )
        printf("ERROR: getBitmapImageData - Plane count from %s.\n ", pFileName);

    if( (i = fread(&nNumBPP, 2, 1, pFile)) != 1 )
        printf( "ERROR: getBitmapImageData - Couldn't read BPP from %s.\n ", pFileName);

    if( nNumBPP != 24 )
        printf("ERROR: getBitmapImageData - BPP from %s.\n ", pFileName);

    // Seek forward to image data
    fseek( pFile, 24, SEEK_CUR );

    // Calculate the image's total size in bytes. Note how we multiply the
    // result of (width * height) by 3. This is becuase a 24 bit color BMP
    // file will give you 3 bytes per pixel.
    int nTotalImagesize = (pImage->width * pImage->height) * 3;

    pImage->data = (char*) malloc( nTotalImagesize );

    if( (i = fread(pImage->data, nTotalImagesize, 1, pFile) ) != 1 )
        printf("ERROR: getBitmapImageData - Couldn't read image data from %s.\n ", pFileName);

    //
    // Finally, rearrange BGR to RGB
    //
    char charTemp;
    for( i = 0; i < nTotalImagesize; i += 3 )
    {
        charTemp = pImage->data[i];
        pImage->data[i] = pImage->data[i+2];
        pImage->data[i+2] = charTemp;
    }
}

BMPImage loadTexture(char* Filename,int num)
{
    BMPImage textura;

    getBitmapImageData( Filename, &textura);

    glGenTextures(tnum, &texture_id[num]);
    tnum++;

    // Defina os parâmetros da textura

    glBindTexture(GL_TEXTURE_2D, texture_id[num]);


    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
//    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

    return textura;
}

void loadAllTextures()
{
    char cwd[1024];
    char tmp[1024];

    getcwd(cwd, sizeof(cwd));

    memset(tmp, '\0', sizeof(tmp));
    strcpy(tmp,cwd);
    strcat(tmp,"\\textures\\back.bmp");
    texturesl[0] = loadTexture(tmp,0); //back sky
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, texturesl[0].width,texturesl[0].height, 0, GL_RGB, GL_UNSIGNED_BYTE,texturesl[0].data);


    memset(tmp, '\0', sizeof(tmp));
    strcpy(tmp,cwd);
    strcat(tmp,"\\textures\\front.bmp");
    texturesl[1] = loadTexture(tmp,1); //front sky
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, texturesl[1].width,texturesl[1].height, 0, GL_RGB, GL_UNSIGNED_BYTE,texturesl[1].data);

    memset(tmp, '\0', sizeof(tmp));
    strcpy(tmp,cwd);
    strcat(tmp,"\\textures\\bottom.bmp");
    texturesl[2] = loadTexture(tmp,2); //bottom sky
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, texturesl[2].width,texturesl[2].height, 0, GL_RGB, GL_UNSIGNED_BYTE,texturesl[2].data);

    memset(tmp, '\0', sizeof(tmp));
    strcpy(tmp,cwd);
    strcat(tmp,"\\textures\\top.bmp");
    texturesl[3] = loadTexture(tmp,3);  //top sky
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, texturesl[3].width,texturesl[3].height, 0, GL_RGB, GL_UNSIGNED_BYTE,texturesl[3].data);

    memset(tmp, '\0', sizeof(tmp));
    strcpy(tmp,cwd);
    strcat(tmp,"\\textures\\left.bmp");
    texturesl[4] = loadTexture(tmp,4); //left sky
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, texturesl[4].width,texturesl[4].height, 0, GL_RGB, GL_UNSIGNED_BYTE,texturesl[4].data);

    memset(tmp, '\0', sizeof(tmp));
    strcpy(tmp,cwd);
    strcat(tmp,"\\textures\\right.bmp");
    texturesl[5] = loadTexture(tmp,5); //right sky
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, texturesl[5].width,texturesl[5].height, 0, GL_RGB, GL_UNSIGNED_BYTE,texturesl[5].data);

    memset(tmp, '\0', sizeof(tmp));
    strcpy(tmp,cwd);
    strcat(tmp,"\\textures\\woodFloor.bmp");
    texturesl[6] = loadTexture(tmp,6); //wood floor
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, texturesl[6].width,texturesl[6].height, 0, GL_RGB, GL_UNSIGNED_BYTE,texturesl[6].data);

    memset(tmp, '\0', sizeof(tmp));
    strcpy(tmp,cwd);
    strcat(tmp,"\\textures\\rockWall.bmp");
    texturesl[7] = loadTexture(tmp,7); //rock wall
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, texturesl[7].width,texturesl[7].height, 0, GL_RGB, GL_UNSIGNED_BYTE,texturesl[7].data);

    memset(tmp, '\0', sizeof(tmp));
    strcpy(tmp,cwd);
    strcat(tmp,"\\textures\\tileRoof.bmp");
    texturesl[8] = loadTexture(tmp,8); //rock wall
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, texturesl[8].width,texturesl[8].height, 0, GL_RGB, GL_UNSIGNED_BYTE,texturesl[8].data);

    memset(tmp, '\0', sizeof(tmp));
    strcpy(tmp,cwd);
    strcat(tmp,"\\textures\\witchFace.bmp");
    texturesl[9] = loadTexture(tmp,9); //rock wall
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, texturesl[9].width,texturesl[9].height, 0, GL_RGB, GL_UNSIGNED_BYTE,texturesl[9].data);

    memset(tmp, '\0', sizeof(tmp));
    strcpy(tmp,cwd);
    strcat(tmp,"\\textures\\noseSkin.bmp");
    texturesl[10] = loadTexture(tmp,10); //nose Skin
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, texturesl[10].width,texturesl[10].height, 0, GL_RGB, GL_UNSIGNED_BYTE,texturesl[10].data);

    memset(tmp, '\0', sizeof(tmp));
    strcpy(tmp,cwd);
    strcat(tmp,"\\textures\\broomTexture.bmp");
    texturesl[11] = loadTexture(tmp,11); //nose Skin
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, texturesl[11].width,texturesl[11].height, 0, GL_RGB, GL_UNSIGNED_BYTE,texturesl[11].data);

    memset(tmp, '\0', sizeof(tmp));
    strcpy(tmp,cwd);
    strcat(tmp,"\\textures\\towerWall.bmp");
    texturesl[12] = loadTexture(tmp,12); //nose Skin
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, texturesl[12].width,texturesl[12].height, 0, GL_RGB, GL_UNSIGNED_BYTE,texturesl[12].data);

    memset(tmp, '\0', sizeof(tmp));
    strcpy(tmp,cwd);
    strcat(tmp,"\\textures\\trapDoor.bmp");
    texturesl[13] = loadTexture(tmp,13); //nose Skin
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, texturesl[13].width,texturesl[13].height, 0, GL_RGB, GL_UNSIGNED_BYTE,texturesl[13].data);

    memset(tmp, '\0', sizeof(tmp));
    strcpy(tmp,cwd);
    strcat(tmp,"\\textures\\frame.bmp");
    texturesl[14] = loadTexture(tmp,14); //nose Skin
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, texturesl[14].width,texturesl[14].height, 0, GL_RGB, GL_UNSIGNED_BYTE,texturesl[14].data);

    memset(tmp, '\0', sizeof(tmp));
    strcpy(tmp,cwd);
    strcat(tmp,"\\textures\\caldronLiquid.bmp");
    texturesl[15] = loadTexture(tmp,15); //nose Skin
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, texturesl[15].width,texturesl[15].height, 0, GL_RGB, GL_UNSIGNED_BYTE,texturesl[15].data);

    memset(tmp, '\0', sizeof(tmp));
    strcpy(tmp,cwd);
    strcat(tmp,"\\textures\\caldronLiquid.bmp");
    texturesl[16] = loadTexture(tmp,16); //nose Skin
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, texturesl[16].width,texturesl[16].height, 0, GL_RGB, GL_UNSIGNED_BYTE,texturesl[16].data);

    memset(tmp, '\0', sizeof(tmp));
    strcpy(tmp,cwd);
    strcat(tmp,"\\gui\\expandButton.bmp");
    texturesl[17] = loadTexture(tmp,17); //nose Skin
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, texturesl[17].width,texturesl[17].height, 0, GL_RGB, GL_UNSIGNED_BYTE,texturesl[17].data);

    memset(tmp, '\0', sizeof(tmp));
    strcpy(tmp,cwd);
    strcat(tmp,"\\gui\\leftShoulder_rz.bmp");
    texturesl[18] = loadTexture(tmp,18); //nose Skin
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, texturesl[18].width,texturesl[18].height, 0, GL_RGB, GL_UNSIGNED_BYTE,texturesl[18].data);

    memset(tmp, '\0', sizeof(tmp));
    strcpy(tmp,cwd);
    strcat(tmp,"\\gui\\rightShoulder_rz.bmp");
    texturesl[19] = loadTexture(tmp,19); //nose Skin
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, texturesl[19].width,texturesl[19].height, 0, GL_RGB, GL_UNSIGNED_BYTE,texturesl[19].data);

    memset(tmp, '\0', sizeof(tmp));
    strcpy(tmp,cwd);
    strcat(tmp,"\\gui\\leftShoulder_rx.bmp");
    texturesl[20] = loadTexture(tmp,20); //nose Skin
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, texturesl[20].width,texturesl[20].height, 0, GL_RGB, GL_UNSIGNED_BYTE,texturesl[20].data);

    memset(tmp, '\0', sizeof(tmp));
    strcpy(tmp,cwd);
    strcat(tmp,"\\gui\\rightShoulder_rx.bmp");
    texturesl[21] = loadTexture(tmp,21); //nose Skin
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, texturesl[21].width,texturesl[21].height, 0, GL_RGB, GL_UNSIGNED_BYTE,texturesl[21].data);

    memset(tmp, '\0', sizeof(tmp));
    strcpy(tmp,cwd);
    strcat(tmp,"\\gui\\leftShoulder_ry.bmp");
    texturesl[22] = loadTexture(tmp,22); //nose Skin
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, texturesl[22].width,texturesl[22].height, 0, GL_RGB, GL_UNSIGNED_BYTE,texturesl[22].data);

    memset(tmp, '\0', sizeof(tmp));
    strcpy(tmp,cwd);
    strcat(tmp,"\\gui\\rightShoulder_ry.bmp");
    texturesl[23] = loadTexture(tmp,23); //nose Skin
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, texturesl[23].width,texturesl[23].height, 0, GL_RGB, GL_UNSIGNED_BYTE,texturesl[23].data);

    memset(tmp, '\0', sizeof(tmp));
    strcpy(tmp,cwd);
    strcat(tmp,"\\gui\\leftElbow_rz.bmp");
    texturesl[24] = loadTexture(tmp,24); //nose Skin
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, texturesl[24].width,texturesl[24].height, 0, GL_RGB, GL_UNSIGNED_BYTE,texturesl[24].data);

    memset(tmp, '\0', sizeof(tmp));
    strcpy(tmp,cwd);
    strcat(tmp,"\\gui\\rightElbow_rz.bmp");
    texturesl[25] = loadTexture(tmp,25); //nose Skin
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, texturesl[25].width,texturesl[25].height, 0, GL_RGB, GL_UNSIGNED_BYTE,texturesl[25].data);

    memset(tmp, '\0', sizeof(tmp));
    strcpy(tmp,cwd);
    strcat(tmp,"\\gui\\leftLeg_rz.bmp");
    texturesl[26] = loadTexture(tmp,26); //nose Skin
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, texturesl[26].width,texturesl[26].height, 0, GL_RGB, GL_UNSIGNED_BYTE,texturesl[26].data);

    memset(tmp, '\0', sizeof(tmp));
    strcpy(tmp,cwd);
    strcat(tmp,"\\gui\\rightLeg_rz.bmp");
    texturesl[27] = loadTexture(tmp,27); //nose Skin
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, texturesl[27].width,texturesl[27].height, 0, GL_RGB, GL_UNSIGNED_BYTE,texturesl[27].data);

    memset(tmp, '\0', sizeof(tmp));
    strcpy(tmp,cwd);
    strcat(tmp,"\\gui\\leftLeg_rx.bmp");
    texturesl[28] = loadTexture(tmp,28); //nose Skin
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, texturesl[28].width,texturesl[28].height, 0, GL_RGB, GL_UNSIGNED_BYTE,texturesl[28].data);

    memset(tmp, '\0', sizeof(tmp));
    strcpy(tmp,cwd);
    strcat(tmp,"\\gui\\rightLeg_rx.bmp");
    texturesl[29] = loadTexture(tmp,29); //nose Skin
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, texturesl[29].width,texturesl[29].height, 0, GL_RGB, GL_UNSIGNED_BYTE,texturesl[29].data);

    memset(tmp, '\0', sizeof(tmp));
    strcpy(tmp,cwd);
    strcat(tmp,"\\gui\\leftLeg_ry.bmp");
    texturesl[30] = loadTexture(tmp,30); //nose Skin
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, texturesl[30].width,texturesl[30].height, 0, GL_RGB, GL_UNSIGNED_BYTE,texturesl[30].data);

    memset(tmp, '\0', sizeof(tmp));
    strcpy(tmp,cwd);
    strcat(tmp,"\\gui\\rightLeg_ry.bmp");
    texturesl[31] = loadTexture(tmp,31); //nose Skin
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, texturesl[31].width,texturesl[31].height, 0, GL_RGB, GL_UNSIGNED_BYTE,texturesl[31].data);

    memset(tmp, '\0', sizeof(tmp));
    strcpy(tmp,cwd);
    strcat(tmp,"\\gui\\leftKnee_rz.bmp");
    texturesl[32] = loadTexture(tmp,32); //nose Skin
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, texturesl[32].width,texturesl[32].height, 0, GL_RGB, GL_UNSIGNED_BYTE,texturesl[32].data);

    memset(tmp, '\0', sizeof(tmp));
    strcpy(tmp,cwd);
    strcat(tmp,"\\gui\\rightKnee_rz.bmp");
    texturesl[33] = loadTexture(tmp,33); //nose Skin
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, texturesl[33].width,texturesl[33].height, 0, GL_RGB, GL_UNSIGNED_BYTE,texturesl[33].data);

    memset(tmp, '\0', sizeof(tmp));
    strcpy(tmp,cwd);
    strcat(tmp,"\\gui\\leftFoot_rz.bmp");
    texturesl[34] = loadTexture(tmp,34); //nose Skin
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, texturesl[34].width,texturesl[34].height, 0, GL_RGB, GL_UNSIGNED_BYTE,texturesl[34].data);

    memset(tmp, '\0', sizeof(tmp));
    strcpy(tmp,cwd);
    strcat(tmp,"\\gui\\rightFoot_rz.bmp");
    texturesl[35] = loadTexture(tmp,35); //nose Skin
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, texturesl[35].width,texturesl[35].height, 0, GL_RGB, GL_UNSIGNED_BYTE,texturesl[35].data);

    memset(tmp, '\0', sizeof(tmp));
    strcpy(tmp,cwd);
    strcat(tmp,"\\gui\\torso_rz.bmp");
    texturesl[36] = loadTexture(tmp,36); //nose Skin
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, texturesl[36].width,texturesl[36].height, 0, GL_RGB, GL_UNSIGNED_BYTE,texturesl[36].data);

    memset(tmp, '\0', sizeof(tmp));
    strcpy(tmp,cwd);
    strcat(tmp,"\\gui\\torso_ry.bmp");
    texturesl[37] = loadTexture(tmp,37); //nose Skin
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, texturesl[37].width,texturesl[37].height, 0, GL_RGB, GL_UNSIGNED_BYTE,texturesl[37].data);

    memset(tmp, '\0', sizeof(tmp));
    strcpy(tmp,cwd);
    strcat(tmp,"\\gui\\head_rz.bmp");
    texturesl[38] = loadTexture(tmp,38); //nose Skin
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, texturesl[38].width,texturesl[38].height, 0, GL_RGB, GL_UNSIGNED_BYTE,texturesl[38].data);

    memset(tmp, '\0', sizeof(tmp));
    strcpy(tmp,cwd);
    strcat(tmp,"\\gui\\head_ry.bmp");
    texturesl[39] = loadTexture(tmp,39); //nose Skin
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, texturesl[39].width,texturesl[39].height, 0, GL_RGB, GL_UNSIGNED_BYTE,texturesl[39].data);

    memset(tmp, '\0', sizeof(tmp));
    strcpy(tmp,cwd);
    strcat(tmp,"\\gui\\reset.bmp");
    texturesl[40] = loadTexture(tmp,40); //nose Skin
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, texturesl[40].width,texturesl[40].height, 0, GL_RGB, GL_UNSIGNED_BYTE,texturesl[40].data);

    memset(tmp, '\0', sizeof(tmp));
    strcpy(tmp,cwd);
    strcat(tmp,"\\gui\\makePotion.bmp");
    texturesl[41] = loadTexture(tmp,41); //nose Skin
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, texturesl[41].width,texturesl[41].height, 0, GL_RGB, GL_UNSIGNED_BYTE,texturesl[41].data);
}
