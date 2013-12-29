// DOODLE JUMP
//Team name: CodeKnights
//Team members:
//Rahul K Bhojwani      (11c073)
//Radheshyam Verma      (11co71)
//Submitted to :         Sir Vivekraj V.K.
#include<windows.h>
#include <gl\glut.h>
#include<math.h>
#include<stdio.h>
GLint page=8;                               //Setting initial page to home page.
//GLfloat dy=0.002;
GLfloat x=0.0;                              //initial x absica of ball
//GLfloat ymin;
GLfloat dx=0.06;                            // INcremnt in x while 'a' or 'd' is pressed
GLfloat ymax;                               // max value of y
GLfloat v1=0.0;                             // amount Shift of the screen
//GLfloat dy1=0.0002;
GLfloat p=-4;                               //parameters used
int v=1,r=1;                                //in generating random bricks and screen translation.
GLfloat vold=0.0,count=-1;
GLfloat width=680,height=650;               //Width and height of screen
int xScreen,yScreen;
unsigned char pic_col[3];                   //stores color combination of pixel just below ball
//int jump=0,check=0,checkb=0,checkc=0;
GLfloat jumpHeight=1.5;                     //max height that can be jumped
GLfloat y=0.15+jumpHeight;                  //initial y position of ball
GLfloat vmax,yref=1.5,screenShift;          //Yref is the refrence y screen value after which screen is to be shifted.
GLfloat acceleration=0.00002,Velocity=0.0;  //acceleration of ball.
GLfloat angle=0.0;                          //initial angle
GLfloat transX=0.0,transdX=0.002;           //variables for translation motion of bricks.
int Score=0.0;
char *ch;


void resetpar();                            //Resets the basic parameters anytime required.
void game_over()                            // Function which is displayed when variable page=12. End of the game. Displays message and score.
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    resetpar();
    int i;

    glDisable(GL_TEXTURE);
    glDisable(GL_TEXTURE_2D);
    glDisable(GL_LIGHTING);
    char *ins="GAME OVER.\n\nPress Space for Restart \n\nYour Score :";
    float xt=-.5,yt=0,zt=3;
    glColor3f(1,0,0);
    glRasterPos3f(xt,yt,zt);
    for(i=0;ins[i]!='\0';i++)
    {
	  if(ins[i]=='\n')
	  {
	     yt-=0.08;
		  glRasterPos3f(xt,yt,zt);
	  }
	  else
	    glutBitmapCharacter(GLUT_BITMAP_9_BY_15,ins[i]);
    }
    ins=(char *)malloc(1);
    itoa(Score,ins,10);
    for(i=0;ins[i]!='\0';i++)
    {
	  if(ins[i]=='\n')
	  {   yt-=0.08;
		  glRasterPos3f(xt,yt,zt);
	  }
	  else
	    glutBitmapCharacter(GLUT_BITMAP_9_BY_15,ins[i]);
    }

    glEnable(GL_TEXTURE);
    glEnable(GL_TEXTURE_2D);
    glEnable(GL_LIGHTING);
    glFlush();
    //glutSwapBuffers();
    //glutPostRedisplay();
}

void display_doodle()       //Displays the home page. DOODLE JUMP . when page=11;
{
    glClear(GL_COLOR_BUFFER_BIT);
    GLfloat xt=-1.6,yt=1.25,zt=0;
    glBegin(GL_LINES);                  //Basic lines are used to display Doodle jump.
        //display d
        glVertex3f(xt,yt,zt);
        glVertex3f(xt+.4,yt,zt);

        glVertex3f(xt+.4,yt,zt);
        glVertex3f(xt+.4,yt-.7,zt);

        glVertex3f(xt+.4,yt-.7,zt);
        glVertex3f(xt,yt-.7,zt);

        glVertex3f(xt+.1,yt,zt);
        glVertex3f(xt+.1,yt-.7,zt);
        //display o
        xt=xt+.5;
        glVertex3f(xt,yt,zt);
        glVertex3f(xt+.4,yt,zt);

        glVertex3f(xt+.4,yt,zt);
        glVertex3f(xt+.4,yt-.7,zt);

        glVertex3f(xt+.4,yt-.7,zt);
        glVertex3f(xt,yt-.7,zt);

        glVertex3f(xt,yt-.7,zt);
        glVertex3f(xt,yt,zt);
        //display o
        xt=xt+.5;
        glVertex3f(xt,yt,zt);
        glVertex3f(xt+.4,yt,zt);

        glVertex3f(xt+.4,yt,zt);
        glVertex3f(xt+.4,yt-.7,zt);

        glVertex3f(xt+.4,yt-.7,zt);
        glVertex3f(xt,yt-.7,zt);

        glVertex3f(xt,yt-.7,zt);
        glVertex3f(xt,yt,zt);
        //display d
        xt=xt+.5;
        glVertex3f(xt,yt,zt);
        glVertex3f(xt+.4,yt,zt);

        glVertex3f(xt+.4,yt,zt);
        glVertex3f(xt+.4,yt-.7,zt);

        glVertex3f(xt+.4,yt-.7,zt);
        glVertex3f(xt,yt-.7,zt);

        glVertex3f(xt+.1,yt,zt);
        glVertex3f(xt+.1,yt-.7,zt);
        //display l
        xt=xt+.5;
        glVertex3f(xt,yt,zt);
        glVertex3f(xt,yt-.7,zt);

        glVertex3f(xt,yt-.7,zt);
        glVertex3f(xt+.4,yt-.7,zt);
        //display e
        xt=xt+.5;
        glVertex3f(xt,yt,zt);
        glVertex3f(xt,yt-.7,zt);

        glVertex3f(xt,yt-.7,zt);
        glVertex3f(xt+.4,yt-.7,zt);

        glVertex3f(xt,yt,zt);
        glVertex3f(xt+.4,yt,zt);

        glVertex3f(xt,yt-.35,zt);
        glVertex3f(xt+.3,yt-.35,zt);
        //display j
        xt=-1.1;
        yt=yt-1;
        glVertex3f(xt,yt,zt);
        glVertex3f(xt+.4,yt,zt);

        glVertex3f(xt+.2,yt,zt);
        glVertex3f(xt+.2,yt-.7,zt);

        glVertex3f(xt+.2,yt-.7,zt);
        glVertex3f(xt,yt-.7,zt);

        glVertex3f(xt,yt-.7,zt);
        glVertex3f(xt,yt-.5,zt);
        //display u
        xt=xt+.5;
        glVertex3f(xt,yt,zt);
        glVertex3f(xt,yt-.7,zt);

        glVertex3f(xt,yt-.7,zt);
        glVertex3f(xt+.4,yt-.7,zt);

        glVertex3f(xt+.4,yt-.7,zt);
        glVertex3f(xt+.4,yt,zt);
        //display m
        xt=xt+.5;
        glVertex3f(xt,yt,zt);
        glVertex3f(xt,yt-.7,zt);

        glVertex3f(xt,yt,zt);
        glVertex3f(xt+.2,yt-.35,zt);

        glVertex3f(xt+.2,yt-.35,zt);
        glVertex3f(xt+.4,yt,zt);

        glVertex3f(xt+.4,yt,zt);
        glVertex3f(xt+.4,yt-.7,zt);
        //display p
        xt=xt+.5;
        glVertex3f(xt,yt,zt);
        glVertex3f(xt+.3,yt,zt);

        glVertex3f(xt+.3,yt,zt);
        glVertex3f(xt+.3,yt-.3,zt);

        glVertex3f(xt+.3,yt-.3,zt);
        glVertex3f(xt,yt-.3,zt);

        glVertex3f(xt,yt,zt);
        glVertex3f(xt,yt-.7,zt);


    glEnd();
    int i;
    resetpar();
    glDisable(GL_TEXTURE);
    glDisable(GL_TEXTURE_2D);
    glDisable(GL_LIGHTING);
    char *ins="beta version by:-\nRAHUL BHOJWANI\nRADHESHYAM VERMA\nPRESS M";
    float xt2=-1.5,yt2=-1.0,zt2=3;
    glColor3f(1,0,0);
    glRasterPos3f(xt2,yt2,zt2);
    for(i=0;ins[i]!='\0';i++)
    {
	  if(ins[i]=='\n')
	  {   yt2-=0.20;
		  glRasterPos3f(xt2,yt2,zt2);
	  }
	  else
	    glutBitmapCharacter(GLUT_BITMAP_9_BY_15,ins[i]);
    }
    glEnable(GL_TEXTURE);
    glEnable(GL_TEXTURE_2D);
    glEnable(GL_LIGHTING);
    glFlush();
    glutSwapBuffers();
    glutPostRedisplay();
 //  glutSwapBuffers();
  // glutPostRedisplay();
}
void page_8()                                           //Displaying the initial vedio.When page=8;
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    int i;

    GLfloat j;
    glColor3f(1,0,0);
    for(j=0;j<=2;j+=.001)
    {
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
            glColor3f(1,0,0);
        glRectf(-2,-2,j-2,0);
        /*glColor3f(0,1,0);
        glRectf(2,-2,2-j,0);
        glColor3f(0,0,1);
        glRectf(-2,2,j-2,0);*/
        glColor3f(1,1,0);
        glRectf(2,2,2-j,0);
            glutSwapBuffers();

    }
        page=9;
        glutSwapBuffers();
        glutPostRedisplay();
}
void page_9()                               //Displays the initial vedio.
{
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    int i;

    GLfloat j;
    glColor3f(1,0,0);
    for(j=0;j<=2;j+=.001)
    {
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glColor3f(1,0,0);
        glRectf(-2,-2,0,0);
        glColor3f(0,1,0);
        glRectf(2,-2,2-j,0);
        glColor3f(0,0,1);
        glRectf(-2,2,j-2,0);
        glColor3f(1,1,0);
        glRectf(2,2,0,0);
            glutSwapBuffers();

    }
        page=11;
        glutSwapBuffers();
        glutPostRedisplay();

}
void page_5()                                               //displays main menu. when page = 5;
{
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    int i;
    resetpar();
    glDisable(GL_TEXTURE);
    glDisable(GL_TEXTURE_2D);
    glDisable(GL_LIGHTING);
    char *ins="START GAME            : PRESS SPACE\nINSTRUCTIONS          : I\nABOUT THE PROJECT     : H\nOPTIONS               : RIGHT MOUSE BUTTON\nMAIN MENU             : M\nHOME-PAGE             : S\nQUIT                  : Q\n";
    float xt=-.7,yt=0.7,zt=3;
    glColor3f(1,0,0);
    glRasterPos3f(xt,yt,zt);
    for(i=0;ins[i]!='\0';i++)
    {
	  if(ins[i]=='\n')
	  {   yt-=0.20;
		  glRasterPos3f(xt,yt,zt);
	  }
	  else
	    glutBitmapCharacter(GLUT_BITMAP_9_BY_15,ins[i]);
    }
    glEnable(GL_TEXTURE);
    glEnable(GL_TEXTURE_2D);
    glEnable(GL_LIGHTING);
    glFlush();
}
void display_pro()                      //Displays  about project.
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    int i;
    resetpar();
    glDisable(GL_TEXTURE);
    glDisable(GL_TEXTURE_2D);
    glDisable(GL_LIGHTING);
    char *ins="\n\nIn our Doodle Jump the Doodle is the ball which jumps over the stairs. \nObjective of the game is to score as high as possible. As the doodle \nreaches to the top of the screen new stairs are inserted in the screen \nand screen scrolls down. The ball now jumps over these new stairs and\n the game goes on.";
    float xt=-2,yt=2,zt=3;
    glColor3f(1,0,0);
    glRasterPos3f(xt,yt,zt);
    for(i=0;ins[i]!='\0';i++)
    {
	  if(ins[i]=='\n')
	  {   yt-=0.08;
		  glRasterPos3f(xt,yt,zt);
	  }
	  else
	    glutBitmapCharacter(GLUT_BITMAP_9_BY_15,ins[i]);
    }
    glEnable(GL_TEXTURE);
    glEnable(GL_TEXTURE_2D);
    glEnable(GL_LIGHTING);
    glFlush();
}
void resetpar()                         //Program that resets the basic parameters anytime the new game is started.
{

//dy=0.002;
 x=0.0;
// ymin;
 dx=0.06;
 ymax;
 v1=0.0;
// dy1=0.0002;
 p=-4;
 v=1,r=1;
 vold=0.0;
 count=-1;
 width=680;
 height=650;
//jump=0;
//check=0;
//checkb=0;
 jumpHeight=1.5;
 y=0.15+jumpHeight;
 acceleration=0.00002;
 Velocity=0.0;
 angle=0.0;
 transX=0.0;
 transdX=0.002;
}

void buffer(int r,GLfloat a)                //The function that takes displays random screens everytime its called. r=random variable.
{
//    r=5;
    switch (r)
    {
         case 0:
          angle+=0.15;                  //Rotational and translation effects are given to the bricks using functions and pushmatrix popmatrix operations.
          glPushMatrix();
          glTranslatef(0.0,v1,-2.0);
          glRectf(-1.5,a-1.5,-1.0,a-1.4);
          glRectf(1.0,a-1.0,1.5,a-0.9);
          glPushMatrix();
          glTranslatef(0,+a-0.05,0);
          glRotatef(angle,0,0,1);
          glTranslatef(0,-a+0.05,0);
          glRectf(-0.25,a-0.1,0.25,a+0.0);
          glPopMatrix();
          glRectf(-0.75,a-0.7,-0.25,a-0.6);
          glRectf(-1.0,a+0.7,-.5,a+0.8);
          glRectf(0.5,a+1.4,1.0,a+1.5);
          glPopMatrix();
          break;
    case 1:
          transX+=transdX;
        if(transX>=0.5)
                transdX=-transdX;
        else if(transX<=-3.5)
            transdX=-transdX;
          glPushMatrix();
          glTranslatef(0.0,v1,-2.0);
          glRectf(1.85,a+1.85,1.35,a+1.75);
          glRectf(-1.8,a+1.15,-1.3,a+1.25);
          glRectf(-0.25,a-0.85,0.25,a-0.75);
          //glRectf(-0.75,a-0.7,-0.25,a-0.6);
          glPushMatrix();
          glTranslatef(transX,0,0);
          glRectf(1.85,a+0.15,1.35,a+0.25);
          glPopMatrix();
          glRectf(-1.85,a-1.85,-1.35,a-1.75);
          glPopMatrix();
          break;
        case 2:
        transX+=transdX;
        if(transX>=3.5)
                transdX=-transdX;
        else if(transX<=-0.5)
            transdX=-transdX;
         glPushMatrix();
          glTranslatef(0.0,v1,-2.0);
          glRectf(-0.25,a-1.87,0.25,a-1.77);
          glRectf(-0.97,a-0.9,-1.47,a-0.8);
          glRectf(1.43,a+0.1,1.93,a+0.2);
          glRectf(-0.35,a+1.0,0.15,a+1.1);
          glPushMatrix();
          glTranslatef(transX,0,0);
          glRectf(-1.80,a+1.9,-1.50,a+1.8);
          glPopMatrix();
          //glRectf(0.5,a+1.4,1.0,a+1.5);
          glPopMatrix();
          break;
        case 3:
          angle+=0.15;
          glPushMatrix();
          glTranslatef(0.0,v1,-2.0);
          glPushMatrix();
          glTranslatef(1.25,a+1.45,0);
          glRotatef(angle,0,0,1);
          glTranslatef(-1.25,-a-1.45,0);
          glRectf(1.5,a+1.5,1.0,a+1.4);
          glPopMatrix();
          glRectf(-1.0,a+1.0,-1.5,a+0.9);
          glRectf(0.25,a+0.1,-0.25,a+0.0);
          glRectf(0.75,a+0.7,0.25,a+0.6);
          glRectf(1.0,a-0.7,0.5,a-0.8);
          glRectf(-0.5,a-1.4,-1.0,a-1.5);
          glPopMatrix();
          break;
        case 4:
            angle+=0.15;
          glPushMatrix();
          glTranslatef(0.0,v1,-2.0);
          glRectf(-1.85,a-1.85,-1.35,a-1.75);
          glRectf(1.8,a-1.15,1.3,a-1.25);
          glPushMatrix();
          glTranslatef(0,a+0.80,0);
          glRotatef(angle,0,0,1);
          glTranslatef(0,-a-0.80,0);
          glRectf(0.25,a+0.85,-0.25,a+0.75);
          glPopMatrix();


          //glRectf(-0.75,a-0.7,-0.25,a-0.6);
          glRectf(-1.85,a-0.15,-1.35,a-0.25);
          glRectf(1.85,a+1.85,1.35,a+1.75);
          glPopMatrix();
          break;
        case 5:
        transX+=transdX;
        if(transX>=0.5)
            transdX=-transdX;
        else if(transX<=-1.5)
            transdX=-transdX;
          glPushMatrix();
          glTranslatef(0.0,v1,-2.0);
          glPushMatrix();
          glTranslatef(transX,0,0);
          glRectf(-1.85,a-1.85,-1.35,a-1.75);
          glPopMatrix();
          glPushMatrix();
          glTranslatef(-transX,0,0);
          glRectf(1.8,a-1.15,1.3,a-1.25);
          glPopMatrix();
          glPushMatrix();
          glTranslatef(transX,0,0);
          glRectf(1.7,a-0.15,1.2,a-0.05);
          glPopMatrix();
          glPushMatrix();
          glTranslatef(-transX,0,0);
          glRectf(-1.0,a+1.0,-0.5,a+1.11);
          glPopMatrix();
          glPushMatrix();
          glTranslatef(transX,0,0);
          glRectf(0.25,a+0.85,-0.25,a+0.75);
          glPopMatrix();
          glPushMatrix();
          glTranslatef(-transX,0,0);
          glRectf(-1.75,a-0.7,-1.25,a-0.6);
          glPopMatrix();
          glPushMatrix();
          glTranslatef(transX,0,0);
          glRectf(-1.85,a-0.15,-1.35,a-0.25);
          glPopMatrix();
          glPushMatrix();
          glTranslatef(-transX,0,0);
          glRectf(1.85,a+1.85,1.35,a+1.75);
          glPopMatrix();
          glPushMatrix();
          glTranslatef(transX,0,0);
          glRectf(-0.25,a-0.95,0.25,a-1.05);
          glPopMatrix();
          glPushMatrix();
          glTranslatef(-transX,0,0);
          glRectf(0.75,a-1.70,1.25,a-1.80);
          glPopMatrix();

          glPopMatrix();
          break;
        case 6:
            glPushMatrix();
          glTranslatef(0.0,v1,-2.0);
          glRectf(1.85,a+1.85,1.35,a+1.75);
          glRectf(-1.8,a+1.15,-1.3,a+1.25);
          glRectf(-1.7,a+0.15,-1.2,a+0.05);
          glRectf(1.0,a-1.0,0.5,a-1.11);
          glRectf(-0.25,a-0.85,0.25,a-0.75);
          glRectf(1.75,a+0.7,1.25,a+0.6);
          glRectf(1.85,a+0.15,1.35,a+0.25);
          glRectf(-1.85,a-1.85,-1.35,a-1.75);
          glRectf(0.25,a+0.95,-0.25,a+1.05);
          glRectf(-0.75,a+1.70,-1.25,a+1.80);

          glPopMatrix();
          break;
          case 7:
            glPushMatrix();
          glTranslatef(0.0,v1,-2.0);
          glRectf(1.85,a-1.85,1.35,a-1.75);
          glRectf(-1.8,a-1.15,-1.3,a-1.25);
          glRectf(-1.7,a-0.15,-1.2,a-0.05);
          glRectf(1.0,a+1.0,0.5,a+1.11);
          glRectf(-0.25,a+0.85,0.25,a+0.75);
          glRectf(1.75,a-0.7,1.25,a-0.6);
          glRectf(1.85,a-0.15,1.35,a-0.25);
          glRectf(-1.85,a+1.85,-1.35,a+1.75);
          glRectf(0.25,a-0.95,-0.25,a-1.05);
          glRectf(-0.75,a-1.70,-1.25,a-1.80);

          glPopMatrix();
          break;
          case 8:
            glPushMatrix();
          glTranslatef(0.0,v1,-2.0);
          glRectf(-1.85,a+1.85,-1.35,a+1.75);
          glRectf(1.8,a+1.15,1.3,a+1.25);
          glRectf(1.7,a+0.15,1.2,a+0.05);
          glRectf(-1.0,a-1.0,-0.5,a-1.11);
          glRectf(0.25,a-0.85,-0.25,a-0.75);
          glRectf(-1.75,a+0.7,-1.25,a+0.6);
          glRectf(-1.85,a+0.15,-1.35,a+0.25);
          glRectf(1.85,a-1.85,1.35,a-1.75);
          glRectf(-0.25,a+0.95,0.25,a+1.05);
          glRectf(0.75,a+1.70,1.25,a+1.80);

          glPopMatrix();
          break;

         default :
                break;
    };
}


void display_ins();                             //Function that displays instructions.
void drawBitmapText(char *string,float x,float y)
{
    char *c;
    glRasterPos3f(x, y,3);
    glColor3f(1,0,0);
    for (c=string; *c != '\0'; c++)
    {
        glutBitmapCharacter(GLUT_BITMAP_9_BY_15, *c);
    }
}

                                    //This is the main fuction called everytime when GlutDisplayFunc is called.
void Draw() {
    if(page==0)
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


        page=8;
        glutSwapBuffers();
        glutPostRedisplay();
    }
    else if(page==1)                    //Main game code page.
    {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glEnable(GL_DEPTH_TEST);

	// Set material properties
	GLfloat qaBlack[] = {0.0, 0.0, 0.0, 1.0};
	GLfloat qaGreen[] = {0.0, 0.1, 0.0, 1.0};
	//GLfloat qaCustom[]= {0.728,0.476,0.132,1.0};     // Brown custom
	//GLfloat qaCustom[]= {0.132,0.728,0.672,1.0};        // Bluish
	//GLfloat qaCustom[]= {0.8392,0.6392,0.3294,1.0};        // Wood Brown
	GLfloat qaCustom[]= {0.9992,0.7992,0.4894,1.0};        // Wood Brown
	//GLfloat qaYellow[] = {1.0, 1.0, 0.0, 1.0};              //NOrmal yellow
	GLfloat qaYellow[] = {1.0, 0.847059, 0.0, 1.0};              //Dark yellow
	GLfloat qaRed[] = {1.0, 0.0, 0.0, 1.0};
	GLfloat qaBlue[] = {0.0, 0.0, 1.0, 1.0};
	GLfloat qaWhite[] = {1.0, 1.0, 1.0, 1.0};
	GLfloat qaGray[] = {0.7529, 0.7529, 0.7529, 1.0};
	//glClearColor(0.7529,0.7529,0.7529, 0.0);   //Gray
	GLfloat qaLowAmbient[] = {0.2, 0.2, 0.2, 1.0};
	GLfloat qaFullAmbient[] = {1.0, 1.0, 1.0, 1.0};


    glShadeModel(GL_SMOOTH);



  //  glMaterialfv(GL_FRONT, GL_AMBIENT, qaCustom);
	//	glMaterialfv(GL_FRONT, GL_DIFFUSE, qaCustom);
		glMaterialfv(GL_FRONT, GL_SPECULAR, qaWhite);
		glMaterialf(GL_FRONT, GL_SHININESS, 128.0);
		glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);
        //glRectf(0.1,0.1,0.3,0.2);
      //  glMatrixMode(GL_MODELVIEW);
	//	glLoadIdentity();
      //  glPushMatrix();
      //  glRotatef(0.785,1.0,0.0,0.0);
       // glTranslatef(.15,0.1,0);

       // glTranslatef(-0.5 , 0.5, -2.0);
      //  glRectf(0,0,0.2,0.1);
      //  glutSolidSphere(0.5,20,20);
       //   glutSolidTorus(0.1,0.2,50,50);


        glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		/*glPushMatrix();
		glMaterialfv(GL_FRONT, GL_AMBIENT, qaGray);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, qaGray);
		glTranslatef(0,0,-3);
		float q,w;
		for(q=-2;q<=2;)
        {
            for(w=-2;w<=2;)
            {
                glBegin(GL_LINES);
                    glVertex2f(q,w);
                    glVertex2f(q,w+0.2);
                    glVertex2f(q,w);
                    glVertex2f(q+0.2,w);
                glEnd();
                w+=0.2;
            }
            glFlush();
            q+=0.2;
        }
        glPopMatrix();
*/
        glMaterialfv(GL_FRONT, GL_AMBIENT, qaCustom);               //Setting color of bricks
		glMaterialfv(GL_FRONT, GL_DIFFUSE, qaCustom);



		Score=(int)150*-v1;                                         //updates score in variable Score.

   //     itoa(Score,ch,10);
        drawBitmapText("Score:",1.2,1.8);
        ch=(char*)malloc(1);
        itoa(Score,ch,10);
        drawBitmapText(ch,1.52,1.8);
       /*   glPushMatrix();
          glTranslatef(0.0,0.0,-2.0);
          glRectf(-1.5,-1.5,-1.0,-1.4);
          glRectf(1.0,-1.0,1.5,-0.9);
          glRectf(-0.25,-0.1,0.25,0.0);
          glRectf(-0.75,-0.7,-0.25,-0.6);
          glRectf(-1.0,0.7,-.5,0.8);
          glRectf(0.5,1.4,1.0,1.5);
          glPopMatrix();*/

        // LOgic

         //   if((fmodf(-v1,4.0))==0)
           if(count==-1||count>=4)          //When above buffer screen comes to main screen then count=vold-v1=4
            {

                v=r;                        //inthis loop v takes initial value of r
                //r=random();
                r=rand()%9;                 // and takes new random
             //   printf("Yes it did");

                p+=4;
                count=0;
                vold=v1;                    //vold is assigned v1
               // buffer(1,y1);
               // buffer(1,y1+4);
  //             if(checkc==0)
    //            {
      //              count=1;
        //            checkc=1;
          //      }
            }

            buffer(v,p);
            buffer(r,p+4);


           // printf("\n%f\t %f",v1,fmodf(v1,4.0));
          //  v1-=0.001;
            //count++;

          //Ball Drawing


        glMaterialfv(GL_FRONT, GL_AMBIENT, qaYellow);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, qaYellow);


          glPushMatrix();
          glTranslatef(x,y,-2.0);
          glutSolidSphere(0.15,50,50);
          glPopMatrix();

          xScreen=(int)((width+(width*x)/2)/2);                     //contains the x and y coordinates on screen of
          yScreen=(int)((height+(height*(y-0.16))/2)/2);            //pixel below the ball
          glReadPixels(xScreen,yScreen,1,1,GL_RGB,GL_UNSIGNED_BYTE,pic_col); // reads pixel color.



             //   printf("\n  %d   %d   %d   %d   %d    %f   %f down" ,xScreen,yScreen, pic_col[0],pic_col[1], pic_col[2],Velocity,ymax-y);
        if(pic_col[2]<150&&Velocity>0)              //Condition is satisfied when color below ball is color of brick and ball is going down.
        {
            Velocity=-0.006900;
           // Velocity=-0.008900;
        }
        if(y>=yref&&Velocity<0)
        {
            Velocity+=acceleration;                         //when y of ball is greater than yref then ball motion is stopped and screen moves.
                v1+=Velocity;
                count=vold-v1;
         //       printf("\n%f",count);
        }
        else
        {
            Velocity+=acceleration;                         //Velocity is increased by acceleration
            y-=Velocity;                                    //position is dependent on Velocity
           // printf("\n %f",Velocity);
        }

        if(y<=-2)
        {
            page=12;                                        //if the ball falls out of the screen then end game screen is displayed.
        }

     /*     if(jump==1)
          {
              if(check==0)
              {
                  ymax=y+jumpHeight;
                  check=1;
              }
              /*if(ymax>yref)
              {
                  if(checkb==0)
                  {
                    screenShift=ymax-yref;
                    vmax=v1-screenShift;
                    if(y>=yref)
                        checkb=1;
                    else
                        Velocity-=acceleration;
                        //y+=dy;
                        y+=Velocity;
                  }
                  else
                  {
                    v1-=0.002;
                   // y+=dy;
                    count++;
                    if(v1<=vmax)
                    {
                        jump=0;
                        checkb=0;
                        check=0;
                    }
                  }
              }*/
        //      else
             // {
    /*          Velocity-=acceleration;
             // y+=dy;
            y+=Velocity;
            printf("\n  %d   %d   %d   %d   %d    %f   %f up" ,xScreen,yScreen, pic_col[0],pic_col[1], pic_col[2],Velocity,ymax-y);
              if(y>=ymax)
              {
                  jump=0;
                  check=0;
              }
             // }
            }
            else if(jump==0)
            {
                Velocity+=acceleration;
                //y-=dy;
                y-=Velocity;
                printf("\n  %d   %d   %d   %d   %d    %f   %f down" ,xScreen,yScreen, pic_col[0],pic_col[1], pic_col[2],Velocity,ymax-y);
                if(pic_col[2]>10)
                    jump=1;
            }*/
         //printf("\n  %d   %d   %d   %d   %d " ,xScreen,yScreen, pic_col[0],pic_col[1], pic_col[2]);

          //glReadPixels()
   /*        y+=dy;
          if(y>=1.0)
          {
              dy=-dy;
          }
          else if(y<=0.15)
          {
              dy=-dy;
          }
*/

  //        printf("\n  %d   %d   %f   %f   %f " ,xScreen,yScreen, pic_col[0]/250.0f,pic_col[1]/250.0f, pic_col[2]/250.0f);


	glutSwapBuffers();
	glutPostRedisplay();
    }
    else if(page==2)                            //Displays page about project.
    {
        display_pro();
        glutSwapBuffers();
        glutPostRedisplay();
    }
    else if(page==3)                            //Displays page about instructions
    {
        display_ins();
        glutSwapBuffers();
        glutPostRedisplay();
    }
    else if(page==4)                        //Quits the game.
    {
        exit(0);
    }
    else if(page==5)                //Displays main menu.
    {
            page_5();
            glutSwapBuffers();
            glutPostRedisplay();
    }
    else if(page==8)
    {
        page_8();
    }
    else if(page==9)
    {
        page_9();
    }
    else if(page==11)
    {
        display_doodle();
    }
    else if(page==12)
    {
        game_over();

        glutSwapBuffers();
        glutPostRedisplay();
    }
    else
    {
    glutSwapBuffers();
    glutPostRedisplay();
    }
}

void reshape(int x,int y)                   //Function is calld when screen is resized
{
    width=x;
    height=y;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glViewport(0,0,(GLsizei)x,(GLsizei)y);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-2.0, 2.0, -2.0, 2.0, -3.0, 3.0);
}



void input(unsigned char key,int a,int b)
{
    if(key=='s')                                        //When keyboard input is 's' Initial vedio is displayed
    {
        page=0;
    }
    else if(key=='i')                                   //When keyboard input is 'i' instructions are displayed
    {
        page=3;
    }
    else if(key=='q')                                   //When keyboard input is 'q' game quits.
    {
        page=4;
    }
    else if(key=='d')                                   //When keyboard input is 'd' doodle moves right.
    {
        x+=dx;
        if(x>=2.0)
            x=-2.0;
    }
    else if(key=='a')                                      //When keyboard input is 'a' doodle moves left.
    {
        x-=dx;
        if(x<=-2.0)
            x=2.0;
    }
    else if(key==' ')                                      //When Space is pressed new game starts.
    {
        page=1;
        glutPostRedisplay();
    }
    else if(key=='h')                                       //if h is displayed About project window comes.
    {
        page=2;
    }
    else if(key=='m')                                       //if 'm' is pressed main menu comes.
    {
        page=5;
    }
}
                                                                    //Function for initializing the window
void Initialize() {
	//glClearColor(1.0, 1.0, 1.0, 0.0);
	glClearColor(0.9921, 0.9725, 0.9490, 0.0);   //Cream
	//glClearColor(0.7529,0.7529,0.7529, 0.0);   //Gray
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-2.0, 2.0, -2.0, 2.0, -3.0, 3.0);

	// Lighting set up
	glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	// Set lighting intensity and color                         //Setting light parameters
	GLfloat qaAmbientLight[]	= {0.2, 0.2, 0.2, 1.0};
	GLfloat qaDiffuseLight[]	= {0.8, 0.8, 0.8, 1.0};
	GLfloat qaSpecularLight[]	= {1.0, 1.0, 1.0, 1.0};
	glLightfv(GL_LIGHT0, GL_AMBIENT, qaAmbientLight);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, qaDiffuseLight);
	glLightfv(GL_LIGHT0, GL_SPECULAR, qaSpecularLight);

	// Set the light position//
	GLfloat qaLightPosition[]	= {2.0, 0.0, 0.0, 2.0};
	glLightfv(GL_LIGHT0, GL_POSITION, qaLightPosition);
}
void display_ins()                                          //Displays game instruction screen and controls.
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    int i;
    resetpar();
    glDisable(GL_TEXTURE);
    glDisable(GL_TEXTURE_2D);
    glDisable(GL_LIGHTING);
    char *ins="AIM:-\nAIM:-\nAim of the game is to score as high as possible use  \n keyboard to move the ball horizontally and use the stairs to go\n up.Score is dependent on the height you travel\n\nCONTROLS:-\nUse a to move ball left and d to move the ball right.\n";
    float xt=-2,yt=2,zt=3;
    glColor3f(1,0,0);
    glRasterPos3f(xt,yt,zt);
    for(i=0;ins[i]!='\0';i++)
    {
	  if(ins[i]=='\n')
	  {   yt-=0.08;
		  glRasterPos3f(xt,yt,zt);
	  }
	  else
	    glutBitmapCharacter(GLUT_BITMAP_9_BY_15,ins[i]);
    }
    glEnable(GL_TEXTURE);
    glEnable(GL_TEXTURE_2D);
    glEnable(GL_LIGHTING);
    glFlush();
}

void option(int id)                 //function for mouse right click menu options
{
    page=id;
    if(id==3)
    {
        display_ins();
    }
    else if(id==2)
    {
        display_pro();
    }
    else if(id==4)
    {
        exit(0);
    }
    else if(id==1)
    {
        resetpar();
    }
}
                                            //The main function.
int main(int iArgc, char** cppArgv) {
	glutInit(&iArgc, cppArgv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(680, 650);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Doodle Jump");
	glutCreateMenu(option);
	glutAddMenuEntry("NEW GAME",1);
	glutAddMenuEntry("ABOUT THE PROJECT",2);
	glutAddMenuEntry("INSTRUCTIONS",3);
	glutAddMenuEntry("QUIT",4);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	Initialize();
	glutDisplayFunc(Draw);
	glutKeyboardFunc(input);
	glutReshapeFunc(reshape);
	glutMainLoop();
	return 0;
}
