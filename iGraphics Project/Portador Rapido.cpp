#include "iGraphics.h"
#include "bitmap_loader.h"

int x = 1300, y = 650, r = 20;//default

int win_b = 400, win_l = 400;
float delay = 0;
int speed = 0;
int counter = 0;

/*function iDraw() is called again and again by the system.*/

int clickX = 0;
int clickY = 0;


///////////////////////////////////////////////

int music = 0;


int m_x = 1700, m_y = 500; // monkey coordinate
int m_xt = 50, m_yt = 50; // monkey coordinate

int mm_x = 1300, mm_y = 300; // monkey coordinate


int mmm_x = 2000, mmm_y = 100; // monkey coordinate


int k = 0;

int xx = 200;
int yy = 200;

int rr = 0;
int gg = 0;
int bb = 0;

int dx = 10;
int dy = 10;


int gameState = 0;

////////////////////GameSateOne////////////////////////////

int image1;
int image2;
int image3;
int image4;
int image5;
int image6;


int mox=200;
int moy=200;

int max=100;
int may=100;

int background[6];
int background_x[] = {0,1300};
int	background_y[]={0,0};

int timecount=0;
char str_time[10];
int Score;
void showTime()
{
	if(gameState == 0)
	{
		timecount = 0;
		Score = 0;
	}
	timecount ++;
	Score = timecount;
}


/////////////////////////////////Genie///////////////////////////
int genieCheck = 0;
int genie[15];
int genieInitial;

void geineWorking()
{
	if(genieCheck == 0)
	{
		iShowImage(xx,yy, 100, 100, genieInitial);
	}
	else if(genieCheck == 1)
	{
		for(int i = 0; i < 6; i++)
		{
			iShowImage(xx,yy, 100, 100, genie[i]);
		}
	}
}


//////////////////////backGraound////////////////////////
void change_background()
{ 
	for(int i=0;i<2;i++)
	{ 
		
		background_x[i] -= 10;
		if(background_x[i]+400<0) 
			background_x[i] = background_x[(i+1)%2]+400; 
	}
}


void changeFisrtBackground()
{ 
	for(int i=1;i<2;i++)
	{
		iShowImage(0,0,1300,650,background[i]);
		iShowImage(200,200, 200, 200, genieInitial);
	}
}

int gameStart = 0;

void gameSateTwo()
{
	iClear();
	changeFisrtBackground();

	if(gameStart == 1)
	{
		iShowImage(0,0,1300,650,background[2]);
		iShowImage(200,200, 100, 100, image2);
		for(int i=2;i<5;i++)
		{

		iShowImage(background_x[i],0,1300,650,background[i]);

		

		iShowImage(m_x,m_y,m_xt,m_yt,image1);

		iShowImage(mm_x,mm_y,50,50,image2);

		iShowImage(mmm_x,mmm_y,50,50,image3);

		
		iShowImage(xx,yy, 200, 200, genie[i]);


		//iUnRotate();
	
		iSetColor(255,0,0);
		sprintf(str_time,"%d\n",timecount);
		iText(200, 100, str_time, GLUT_BITMAP_HELVETICA_18);
		
		}
	}
	
}

void collisionCheck()
{
	if((((yy+200)>= m_y) && ((yy) <= (m_y))) && (((xx+200) >= m_x) && ((m_x) >= (xx))))      //yy for jenie y axis and my for monkeys axis
	{
		gameState = 5;
	}

	if((((yy+200)>= mm_y) && ((yy) <= (mm_y))) && (((xx+200) >= mm_x) && ((mm_x+50) >= (xx))))
	{
		gameState = 5;
	}
	if((((yy+200)>= mmm_y) && ((yy) <= (mmm_y))) && (((xx+200) >= mmm_x) && ((mmm_x+50) >= (xx))))
	{
		gameState = 5;
	}

	/*else if((((yy)>= mmmm_y) && ((yy) <= (mmmm_y))) && ((xx) >= mmmm_x) && ((mmmm_x+50) >= (xx)))
	{
		exit(0);
	}
	else if((((yy)>= mmmmm_y) && ((yy) <= (mmmmm_y))) && ((xx) >= mmmmm_x) && ((mmmmm_x+50) >= (xx)))
	{


		exit(0);
	}

	else if((((yy)>= mmmmmm_y) && ((yy) <= (mmmmmm_y))) && ((xx) >= mmmmmm_x) && ((mmmmmm_x+50) >= (xx)))
	{
		exit(0);
	}*/

	
}

void iDraw()
{
	//place your drawing codes here
	iClear();
	

	if(gameState == 0)
	{
		int home = iLoadImage("picture//Home.png");
		iShowImage(0,0,1300, 650, home);
		if(music == 1)
		{
			PlaySound("music\\MusicOne.wav",NULL,SND_LOOP | SND_ASYNC);
		}

		iSetColor(0,0,0);
		iText(580, 10, "Press N to Sound On");
		if(gameState == 0)
		{
			for(int i = 0; i < 10; i++)
				str_time[i] = 0;
		}

		xx = 200;
	    yy = 200;
		m_x = 1700, m_y = 500; // monkey coordinate
	    mm_x = 1300, mm_y = 300;
	    mmm_x = 2000, mmm_y = 100;
	}
	if(gameState == 1)
	{
		int menu = iLoadImage("picture//Menu.png");
		iShowImage(0,0,1300, 650, menu);
		iSetColor(0,0,0);
		iText(430, 10, "Press H to back Home, Press E to Exit, Press N to Sound On");
	}
	if(gameState == 2)
	{
		gameSateTwo(); 
		iSetColor(0,0,0);
		iText(400, 10, "Press H to back Home, Press E to Exit, Press N to Sound On, Press S to Start Game");
	}
	if(gameState == 3)
	{
		int credit = iLoadImage("picture//Credit.png");
		iShowImage(0,0,1300, 650, credit);
		iSetColor(0,0,0);
		iText(400, 10, "Press H to back Home, Press E to Exit, Press N to Sound On");
	}
	if(gameState == 4)
	{
		int procedure = iLoadImage("picture//Procedure.png");
		iShowImage(0,0,1300, 650, procedure);
		iSetColor(0,0,0);
		iText(400, 10, "Press H to back Home, Press E to Exit, Press N to Sound On");
	}
	if(gameState == 5)
	{
		int gameOver = iLoadImage("picture//GameOver.png");
		iShowImage(0,0,1300, 650, gameOver);
		iSetColor(225,225,0);
		printf("%d\n", Score);
		iText(630, 130, str_time, GLUT_BITMAP_HELVETICA_18);
		iSetColor(0,0,0);
		iText(580, 10, "Press N to Sound On");
	}

	/*iSetColor(rr+150, gg+150, bb+150);
	iFilledCircle(xx+625, yy+480, 50, 10000);
	iFilledRectangle(xx+525, yy+250, 200, 200);*/
}


void iPassiveMouse(int x, int y)
{
	;
}


/*
 function iMouseMove() is called when the user presses and drags the mouse.
 (mx, my) is the position where the mouse pointer is.
 */
void iMouseMove(int mx, int my)
{
	printf("x = %d, y= %d\n", mx, my);
	//place your codes here
}

/*
 function iMouse() is called when the user presses/releases the mouse.
 (mx, my) is the position where the mouse pointer is.
 */
void iMouse(int button, int state, int mx, int my)
{
	clickX = mx;
	clickY = my;
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here
		//	printf("x = %d, y= %d\n",mx,my);

		if((mx >=674) && (mx<=961) && (my >=350) && (my <= 515))
		{
			gameState = 2;
		}
		if((mx >=674) && (mx<=961) && (my >=134) && (my <= 280))
		{
			gameState = 4;
		}
	}
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here
		rr = 255;
		gg = 0;
		bb = 0;
	}
}

/*
 function iKeyboard() is called whenever the user hits a key in keyboard.
 key- holds the ASCII value of the key pressed.
 */
void iKeyboard(unsigned char key)
{
	if (key == 'e')
	{
		exit(0);
	}
	else if((key == 'm') && (gameState == 0))
	{
		gameState = 1;
	}
	else if((key == 'c') && (gameState == 0))
	{
		gameState = 3;
	}
	else if(key == 's')
	{
		gameStart = 1;
	}
	else if((key == 'h') && ((gameState == 5) || (gameState == 1) || (gameState == 3) || (gameState == 4)))
	{
		gameState = 0;
	}
	else if (key == 'q')
	{
		music = 0;
	}
	else if (key == 'n')
	{
		music = 1;
	}


	else if (key == 'a' && speed < 5)
		speed += 1;
	else if (key == 's' && speed > 0)
		speed -= 1;
	//place your codes for other keys here
}

/*
 function iSpecialKeyboard() is called whenver user hits special keys like-
 function keys, home, end, pg up, pg down, arraows etc. you have to use
 appropriate constants to detect them. A list is:
 GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
 GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
 GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
 GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
 */
void iSpecialKeyboard(unsigned char key)
{

	if (key == GLUT_KEY_END)
	{
		exit(0);
	}
	if (key == GLUT_KEY_UP)
	{
		yy += 10;
		collisionCheck();
	}
	if (key == GLUT_KEY_DOWN)
	{
		yy -= 10;
		collisionCheck();
	}
	if (key == GLUT_KEY_RIGHT)
	{
		xx += 10;
		collisionCheck();
		genieCheck = 1;
		/*if(xx == 1300)
		{
			xx = 0;
		}*/
	}
	if (key == GLUT_KEY_LEFT)
	{
		xx -= 10;
		collisionCheck();
	}

	//place your codes for other keys here
}

void enemyMotion()
{
	m_x--;

	if(m_x == 0)
	{
		m_x = 1700;
	}
	mm_x--;
	if(mm_x == 0)
	{
		mm_x = 1300;
	}
	mmm_x--;
	if(mmm_x == 0)
	{
		mmm_x = 2000;
	}
}

/*void enemyMotionTwo()
{
	mm_x --;

	if(mm_x == 0)
	{
		mm_x = 1305;
	}

}
void enemyMotionThree()
{
	mmm_x --;

	if(mmm_x == 0)
	{
		mmm_x = 1315;
	}
}

/*void enemyMotionFour()
{
	mmmm_x --;

	if(mmmm_x == 0)
	{
		mmmm_x = 1315;
	}
}
void enemyMotionFive()
{
	mmmmmm_x --;

	if(mmmmm_x == 0)
	{
		mmmmm_x = 1320;
	}
}

void enemyMotionSix()
{
	mmmmmm_x --;

	if(mmmmmm_x == 0)
	{
		mmmmmm_x = 1320;
	}
}*/


int main()
{
	//place your own initialization codes here.


	iInitialize(1300, 650, "2nd assignment on iGraphics!");
	iSetTimer(50, showTime);
	iSetTimer(100, change_background);
	iSetTimer(200, changeFisrtBackground);
	//iSetTimer(50, geineWorking);
	//iSetTimer(250, changeObstacles);

	iSetTimer(01, enemyMotion);
	/*iSetTimer(15, enemyMotionTwo);
	iSetTimer(25, enemyMotionThree);
	/*iSetTimer(05, enemyMotionFour);
	iSetTimer(10, enemyMotionFive);
	iSetTimer(15, enemyMotionSix);*/



	genieInitial = iLoadImage("picture\\GFfour.png");
	
	image1 = iLoadImage("picture\\bomb.png");
	image2 = iLoadImage("picture\\bomb.png");
	image3 = iLoadImage("picture\\bomb.png");
	
	for(int i = 0; i < 2; i++)
	{
		genie[i] = iLoadImage("picture//GF1.png");
	}
	for(int i = 2; i < 4; i++)
	{
		genie[i] = iLoadImage("picture//GF2.png");
	}
	for(int i = 4; i < 6; i++)
	{
		genie[i] = iLoadImage("picture//GF3.png");
	}


	background[0] = iLoadImage("picture\\BG1.png");
	background[1] = iLoadImage("picture\\BG2.png");
	background[2] = iLoadImage("picture\\BG3.png");
	background[3] = iLoadImage("picture\\BG4.png");
	background[4] = iLoadImage("picture\\BG5.png");
	background[5] = iLoadImage("picture\\BG6.png");
	

	iStart(); // it will start drawing

	return 0;
}