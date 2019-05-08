#include "globalstuff.h"

void renderScene(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    //2D plane stuff
    fpsText();
    crosshair();
    menuDraw();
    //--------------

    //3D and Camera Definition
    updateCameraView();
    //--------------

    //Update light position relative to new view Matrix
    updateLightPosition();
    //--------------

    //Render Blue Arrow !
    if(pos_y < 0.3 && pos_y > -0.1 && pos_x < 9.7
       && pos_x > -9.7 && pos_z < 9.7 && pos_z > -9.7)
    {
        glColor3f(0.0,0.0,1.0);
        glPushMatrix();
            glTranslatef(pos_x,2.0,pos_z);
            drawCylinder(0.5,0.1,0.1);
            glTranslatef(0.0,-0.2,0.0);
            drawCylinder(0.25,0.2,0.0);
        glPopMatrix();
    }
    //--------------------

    glColor3f(0.5,0.5,0.5);
    //Render Objects and Scenario
    drawAmbient();
    towerDraw();
    drawPlayer(1);
    renderMonsters();
    skyBox();
    //--------------

    glutSwapBuffers();

    //Transform ViewPort space to 3D world space and store in variables. (x,y)->(x,z);
    mousePicking();
    //--------------

    //Counts frames
    fpsCounter();
    //--------------
}

static void fpsLimiter(int)
{
    glutPostRedisplay();
    glutTimerFunc(1000/FRAMES,fpsLimiter,0);
}

/* Initial Setup*/
void initialSetup()
{
    glClearColor(0.0, 0.0, 0.0, 0.0);

    glutSetCursor(GLUT_CURSOR_NONE);

    glEnable(GL_DEPTH_TEST    );
    glEnable(GL_LIGHTING      );
    glEnable(GL_CULL_FACE     );
    glEnable(GL_AUTO_NORMAL   );
    glEnable(GL_NORMALIZE     );
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_MAP1_VERTEX_3);

    glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glHint(GL_LINE_SMOOTH_HINT,    GL_NICEST        );
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
    glHint(GL_POLYGON_SMOOTH_HINT, GL_NICEST        );

    glShadeModel(GL_SMOOTH);

    loadAllTextures();
    defineLegCylinder();
    defineHeadSphere();
    defineWeb();
    createFloorMesh();
    createAmbient();
}
//------------------

void callbacks()
{
    glutDisplayFunc(renderScene);
    glutReshapeFunc(resizeWindow);
    glutMouseFunc(mouseHandler);
    glutKeyboardFunc(keyboardHandler);
    glutSpecialFunc(specialKeys);
    glutMotionFunc(cameraMotion);
    glutPassiveMotionFunc(mouseMotion);
    glutIgnoreKeyRepeat(1);
    glutTimerFunc(1000/FRAMES,fpsLimiter,0);
}

/* Program entry point */
int main(int argc, char *argv[])
{
    srand(time(NULL));

    FreeConsole();

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(width,height);
    glutInitWindowPosition(350,50);
    glutCreateWindow("Game");

    callbacks();

    initialSetup();
    setLights();
    createMonsterList();

    glutMainLoop();

    return EXIT_SUCCESS;
}
//------------------------
