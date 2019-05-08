#include "globalstuff.h"

int   initial_time = time(NULL), final_time, frame_count = 0;
int   current_fps  = 0;
float todeg        = 180/M_PI;

GLint mouseX = 0;
GLint mouseY = 0;

char screen_current_fps[9];
char screen_fps_text   [6] = "FPS: ";

int game_pause = 0;

struct Points* pts;

bool isEmpty(Points* head)
{
    return head == NULL;
}

/*Insert link at the first location*/
void insertFirst(struct Points** head,float x, float y,int id,int rotation)
{
    struct Points *link = (struct Points*) malloc(sizeof(struct Points));

    link->x = x;
    link->y = y;
    link->id = id;
    link->rotation = rotation;

    link->next = (*head);

    (*head) = link;
}
//------------------------

/*Delete first item*/
struct Points* deleteFirst(struct Points** head)
{
    struct Points *tempLink = (*head);

    if(!isEmpty(*head))
        (*head) = (*head)->next;

    return tempLink;
}
//-----------------------

/*Counts the list length*/
int length(struct Points* head)
{
    int length = 0;
    struct Points *current;

    for(current = head; current != NULL; current = current->next)
    {
        length++;
    }

    return length;
}
//-----------------------

/*Find a link with given key*/
struct Points* findObj(struct Points** head,int id)
{
    struct Points* current = (*head);

    if((*head) == NULL)
    {
        return NULL;
    }

    while(current->id != id)
    {
        if(current->next == NULL)
        {
            return NULL;
        }
        else
        {
            current = current->next;
        }
    }

    return current;
}
//--------------------------

/*Delete a link with given key*/
struct Points* removeObj(struct Points** head,float x,float y)
{
    struct Points* current = (*head);
    struct Points* previous = NULL;

    if((*head) == NULL)
    {
        return NULL;
    }

    while(current->x != x || current->y !=y)
    {
        if(current->next == NULL)
        {
            return NULL;
        }
        else
        {
            previous = current;
            current = current->next;
        }
    }

    if(current == (*head))
    {
        (*head) = (*head)->next;
    }
    else
    {
        previous->next = current->next;
    }

    return current;
}
//---------------------------

/*Free allocated memory used to create list*/
void freeList(struct Points* he)
{
    if (he == NULL)
    {
        return;
    }
    freeList(he->next);
}
//---------------------------

/*Check collision */
bool checkCollision(float obj1x, float obj1y, float obj2x, float obj2y, float size1, float size2)
{
    if(size1+size2 >= fabs(sqrt(pow(obj2x-obj1x,2) + pow(obj2y-obj1y,2))))
    {
        return true;
    }

    return false;
}

int fpsCounter(void)
{
    int fps = 0;

    frame_count++;
    final_time = time(NULL);
    if(final_time - initial_time > 0)
    {
        fps = frame_count/(final_time - initial_time);
        frame_count = 0;
        initial_time = final_time;
        current_fps = fps;
    }
    return fps;
}

// convert degrees to radians
double degToRadians(double degrees)
{
    return (degrees * M_PI / 180.0);
}
//----------------
