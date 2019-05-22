/*#include <GL/gl.h>
#include <GL/glu.h>*/
#include <Gl/glut.h>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>
#include <iostream>
#include <windows.h>

using namespace std;

struct c
{
    int x;
    int y;
};


void display();
void reshape(int,int);
void timer(int);
void init();

char board[8][8];
int boardcheck;
c zaz;
c send;
bool zazwlaczone;

void boardload();
void tboardload();

void boardload()
{


    fstream plik1;
    string linia="";
    char actchar=' ';
    char char_array[2];

    plik1.open("mapa.txt", ios::in);

    int x=0; int y=0;

    while (getline(plik1, linia))
    {
        strcpy(char_array, linia.c_str());

        actchar = char_array[0];
        board[x][y]=char_array[0];

        x++;
        if(x==8) {x=0;y++;}
        if(y==8) break;
    }
    plik1.close();
}

void tboardload()
{
    zaz.x=0;
    zaz.y=0;
    zazwlaczone=1;

    srand(time(NULL));

    int rn;
    char actchar;

    for(int x = 0; x<8 ; x++)
    {
        for(int y = 0; y<8; y++)
        {
            int rn = rand() % 5;
            char actchar = ' ';

            switch(rn)
            {
            case 0: actchar = ' '; break;
            case 1: actchar = 'b'; break;
            case 2: actchar = 'B'; break;
            case 3: actchar = 'c'; break;
            case 4: actchar = 'C'; break;
            }
            //cout<<board[x][y];
            board[x][y]=actchar;
            //board[x][y]=' ';
        }
        //cout<<endl;
    }
}


void mouseClicks(int button, int state, int x, int y)
{
    if(button == GLUT_LEFT_BUTTON )
    {
        /*if(zazwlaczone)
        {
            zazwlaczone=0;
        }
        else
        {*/
            cout<<x<<endl;
            cout<<y<<endl;
            cout<<"y: "<<(y/80)<<endl;


            zaz.x = x/80;
            zaz.y = 7 - (y/80);
            cout<<"y: "<<zaz.y<<endl;
            zazwlaczone=1;
            Sleep(200);
        //}
    }
}

int main(int argc, char**argv)
{
    zazwlaczone=0;

    glutInit(&argc,argv); // initialize the glut
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE); // initialize the display mode */| GLUT_DOUBLE - double buffer*/

    glutInitWindowPosition(200,100); // initialize window
    glutInitWindowSize(640,640);

    glutCreateWindow("Warcaby GFX"); // creates window

    glutDisplayFunc(display);//callback
    glutReshapeFunc(reshape);//reshape
    glutTimerFunc(0,timer,0); // timer

    glutMouseFunc(mouseClicks);
    init();

    glutMainLoop(); // loop
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT); //clears frame buffer
    glLoadIdentity(); // resets coordinate system(current matrix)

    //glShadeModel(GL_FLAT); //one colored primitive

     // size of points
    //draw

    //glTranslatef(x_pos/5,y_pos/20,0); // changes the 0,0 position
    glPointSize(80);
    glBegin(GL_POINTS); // GL_POINTS, GL_TRIANGLES, GL_QUADS, GL_POLYGON
    // specifying vertexes counter-clock wise - shows its front
    bool print;

    for(int x = 0; x<8; x++)
    {
        for(int y = 0; y<8; y++)
        {

            glPointSize(80);
            if((x%2)==(y%2)) glColor3f(0,0,0);
            else glColor3f(1,1,1);

            if(zaz.x==x&&zaz.y==y&&zazwlaczone) glColor3f(1,0,0);

            glVertex2f((float)(x + 0.5f),(float)(y + 0.5f));
        }
    }
    glEnd();
    //end draw

    glPointSize(55);
    glBegin(GL_POINTS); // GL_POINTS, GL_TRIANGLES, GL_QUADS, GL_POLYGON
    // specifying vertexes counter-clock wise - shows its front

    for(int x = 0; x<8; x++)
    {
        for(int y = 0; y<8; y++)
        {
            switch(board[x][y])
            {
            case ' ':
            {
                print = 0;
            } break;
            case 'b': {glPointSize(50); glColor3f(1,1,1); print = 1;} break;
            case 'B': {glPointSize(50); glColor3f(1,1,0); print = 1;} break;
            case 'c': {glPointSize(50); glColor3f(1,1,1); print = 1;} break;
            case 'C': {glPointSize(50); glColor3f(1,1,0); print = 1;} break;
            }


            //glVertex2f(x,y);
            if(print) glVertex2f((float)(x + 0.5f),(float)(y + 0.5f));
        }
    }
    glEnd();

    glPointSize(50);
    glBegin(GL_POINTS); // GL_POINTS, GL_TRIANGLES, GL_QUADS, GL_POLYGON
    // specifying vertexes counter-clock wise - shows its front

    for(int x = 0; x<8; x++)
    {
        for(int y = 0; y<8; y++)
        {
            switch(board[x][y])
            {
            case ' ':
            {
                print = 0;
            } break;
            case 'b': {glPointSize(50); glColor3f(0.8,0.8,0.8); print = 1;} break;
            case 'B': {glPointSize(50); glColor3f(0.9,0.9,0.9); print = 1;} break;
            case 'c': {glPointSize(50); glColor3f(0.2,0.2,0.2); print = 1;} break;
            case 'C': {glPointSize(50); glColor3f(0.1,0.1,0.1); print = 1;} break;
            }
            //glVertex2f(x,y);
            if(print) glVertex2f((float)(x + 0.5f),(float)(y + 0.5f));
        }
    }
    glEnd();

    glFlush(); // display frame buffer

    glutSwapBuffers(); // swaps front buffer with back buffer
}

void init()
{
    //glClearColor(1.0,1.0,0.0,1.0); yellow
    glClearColor(0.0,0.0,0.0,1.0);
}

void reshape(int w,int h)
{
    //glViewport(0,0,(GLsizei)w,(GLsizei)h);//square displaying image
    glViewport(0,0,640,640);//square displaying image
    glMatrixMode(GL_PROJECTION); //matrix mode
    glLoadIdentity();

    gluOrtho2D(0,8,0,8); // ort. projection (middle of the screen is 0,0)e

    glMatrixMode(GL_MODELVIEW); //you can draw stuff
}

void timer(int)
{
    glutPostRedisplay();
    glutTimerFunc(1000/1,timer,0);

    boardload();
}
