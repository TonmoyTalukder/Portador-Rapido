#ifndef GAME_FUNCTIONS_H
#define GAME_FUNCTIONS_H


#include "challenge.h"
#include "playerLoadFile.h"


void resetValues();
void resetWCdata();
void victoryPicture();
void playerRunning();
void ballRunning();
void glovesRunning();
void ballTimer();
void gkDive();
void powerRun1Timer();
void powerRun2Timer();
void blinkPower();
void goalCount(int value);
void circleDraw(int checkGoal);
void circleFillup();
void storeDefaultData();
void playingSound();


int gk_dive = 0;

int gkMoveX = 645;
int gkMoveY = 335;
int pauseBall = 0;

int ballGo = 0;
int ballMoveX =673;
int ballMoveY =168;
int ballSizeX = 35;
int ballSizeY = 35;
int ballShadowX = 668;
int ballShadowY = 165;
int ballShadowSizeX = 40;
int ballShadowSizeY = 15;
int calculateBallMoveX = 0;
int calculateBallMoveY = 0;

int gkMoveRender = 0;
int victoryRender = 0;
int clockRender1 = 6;
int clockRender2 = 0;
int glovesRender = 0;


int powerRectangle1 = 0;
int powerRectangle2 = 30;
int power2length = 20;

int glovesPositionX [7] = {412 , 412 , 412 , 638 , 865 , 865 , 865};
int glovesPositionY [7] = { 365 , 425 , 475 , 425 , 475 , 425 , 365};



//mainGame() function works to move ball,player and gk.........
//Called from GamePicturePage() function......return type void

void mainGame()
{
	if(!challenge_mode)
	{

		circleFillup();
		iSetColor(204,0,0);
		iFilledRectangle(80,575,60,40);
		iFilledRectangle(200,575,60,40);
		iSetColor(51,51,255);
		iFilledRectangle(140,575,60,40);
		iSetColor(255,255,255);
		char showGoalString[100];
		sprintf(showGoalString,"%d - %d",ownGoalCount,opponentGoalCount);
		iText(145,590,showGoalString,GLUT_BITMAP_TIMES_ROMAN_24);
		iSetColor(255,255,255);

		if(worldCup_mode)
		{
			iShowImage(10,575,70,40,flag[worldCupOwnTeam]);
			iShowImage(260,575,70,40,flag[worldCupOpponentTeam]);
			iText(90,590,player[worldCupOwnTeam].shortName,GLUT_BITMAP_HELVETICA_18);
			iText(210,590,player[worldCupOpponentTeam].shortName,GLUT_BITMAP_HELVETICA_18);
		}
		else
		{
			iShowImage(10,575,70,40,flag[yourTeamNumber]);
			iShowImage(260,575,70,40,flag[opponentTeamNumber]);
			iText(90,590,player[yourTeamNumber].shortName,GLUT_BITMAP_HELVETICA_18);
			iText(210,590,player[opponentTeamNumber].shortName,GLUT_BITMAP_HELVETICA_18);
		}
	}

	else
	{
		iSetColor(32,32,32);
		iFilledRectangle(40,535,280,80);
		iSetColor(255,255,255);
		iText(110,585,"Your Score",GLUT_BITMAP_TIMES_ROMAN_24);
		char tempString[100];
		sprintf(tempString,"%d",userDataChallenge.userScore);
		iText(160,550,tempString,GLUT_BITMAP_TIMES_ROMAN_24);


	}


	iSetColor(51,51,255);
	iFilledRectangle(100,100,160,40);
	iFilledRectangle(1135,300,160,40);

	iSetColor(255,255,255);
	if(worldCup_mode)
	{
		if(teamType)
		{
			iShowImage(30,100,70,40,flag[worldCupOpponentTeam]);
			iShowImage(1065,300,70,40,flag[worldCupOwnTeam]);
			iText(1150,315,player[worldCupOwnTeam].PName[10],GLUT_BITMAP_HELVETICA_18);
			iText(115,115,player[worldCupOpponentTeam].PName[playerNameRender],GLUT_BITMAP_HELVETICA_18);
		}
		else if(!teamType)
		{
			iShowImage(30,100,70,40,flag[worldCupOwnTeam]);
			iShowImage(1065,300,70,40,flag[worldCupOpponentTeam]);
			iText(1150,315,player[worldCupOpponentTeam].PName[10],GLUT_BITMAP_HELVETICA_18);
			iText(115,115,player[worldCupOwnTeam].PName[playerNameRender],GLUT_BITMAP_HELVETICA_18);
		}
	}
	else
	{
		if(teamType)
		{
			iShowImage(30,100,70,40,flag[opponentTeamNumber]);
			iShowImage(1065,300,70,40,flag[yourTeamNumber]);
			iText(1150,315,player[yourTeamNumber].PName[10],GLUT_BITMAP_HELVETICA_18);
			iText(115,115,player[opponentTeamNumber].PName[playerNameRender],GLUT_BITMAP_HELVETICA_18);
		}

		else if(!teamType)
		{
			iShowImage(30,100,70,40,flag[yourTeamNumber]);
			iShowImage(1065,300,70,40,flag[opponentTeamNumber]);
			iText(1150,315,player[opponentTeamNumber].PName[10],GLUT_BITMAP_HELVETICA_18);
			iText(115,115,player[yourTeamNumber].PName[playerNameRender],GLUT_BITMAP_HELVETICA_18);
		}
	}


	if(teamType)
	{
		if(gkRun)
			iShowImage(-200,-150,screen_length+450,screen_width+290,opponentGk[gkRender]);
	}
	else if(!teamType)
	{
		if(gkRun)
			iShowImage(10,-10,screen_length,screen_width,ownGk[gkRender]);
	}

	gkDive();

	iShowImage(ballShadowX,ballShadowY,ballShadowSizeX,ballShadowSizeY,ballShadow);
	iShowImage(ballMoveX,ballMoveY,ballSizeX,ballSizeY,ballPicture);

	playerRunning();
	victoryPicture();

	if(!glovesRun)
	{
		blinkPower();
		iSetColor(255,0,0);
		iFilledRectangle(1170,130,50,powerRectangle1);
	}



	if(redPower  && !glovesRun)
	{
		iSetColor(255,0,0);
		iFilledRectangle(powerRectangle2,346,15,10);

	}

	ballRunning();

	if(challenge_mode)
	{
		iShowImage(500,30,100,100,digitPicture[clockRender1]);
		iShowImage(650,30,100,100,digitPicture[clockRender2]);

	}

	if((worldCup_mode || single_mode)  && teamType  && glovesShow)
	{
		iShowImage(glovesPositionX[glovesRender],glovesPositionY[glovesRender],70,60,gloves_picture);
	}
}



//gkDive() function works to dive gk.........
//Called from mainGame() function......return type void

void gkDive()
{

	if(gk_dive == 1 && gkRun==false)
	{
		if(teamType)
		{
			iShowImage(-30,0,screen_length,screen_width,opponentGkRight[gkMoveRender]);
		}
		else if(!teamType)
		{
			iShowImage(0,0,screen_length,screen_width,ownGkRight[gkMoveRender]);
		}
	}

	else if(gk_dive == 2 && gkRun==false)
	{
		if(teamType)
		{
			iShowImage(30,0,screen_length,screen_width,opponentGkLeft[gkMoveRender]);
		}
		else if(!teamType)
		{
			iShowImage(0,0,screen_length,screen_width,ownGkLeft[gkMoveRender]);
		}
	}

	else if((gk_dive == 3 ||  gk_dive == 5) && gkRun==false)
	{

		if(teamType)
		{
			iShowImage(0,0,screen_length,screen_width,opponentMidLeft[gkMoveRender]);
		}
		else if(!teamType)
		{
			iShowImage(0,0,screen_length,screen_width,ownMidLeft[gkMoveRender]);
		}
	}

	else if((gk_dive == 4 ||  gk_dive == 6) && gkRun==false)
	{

		if(teamType)
		{
			iShowImage(0,0,screen_length,screen_width,opponentMidRight[gkMoveRender]);
		}
		else if(!teamType)
		{
			iShowImage(0,0,screen_length,screen_width,ownMidRight[gkMoveRender]);
		}
	}

	else if((gk_dive == 0 || gk_dive == 7)  && gkRun==false)
	{

		if(teamType)
		{
			iShowImage(624+gkSaveMiddleX,345,85,175,opponentSaveMid);
		}
		else if(!teamType)
		{
			iShowImage(630+gkSaveMiddleX,343,75,162,ownSaveMid);
		}
	}

}



//gkTimer() function works to change the gk picture while standing.........
//Called again and again from main() function......return type void


void gkTimer()
{
	if(coverImage==16 && gkRun==true && teamType)
	{
		if(gkRender==5)
			gkRender = 0;
		else gkRender++;
	}

	else if(coverImage==16 && gkRun==true && teamType==false)
	{
		if(gkRender==3)
			gkRender = 0;
		else gkRender++;
	}
}


//gkRunning() function works to change the gk picture while diving.........
//Called again and again from main() function......return type void

void gkRunning()
{
	if((gk_dive == 1 || gk_dive == 2) &&  !gkRun  && teamType)
	{
		if(gkMoveRender == 6)
		{
			iPauseTimer(gk_dive_timer);

		}
		else gkMoveRender++;
	}

	else if((gk_dive == 3 || gk_dive == 4 || gk_dive == 5 || gk_dive == 6) && !gkRun  && teamType)
	{
		if(gkMoveRender == 7)
		{
			iPauseTimer(gk_dive_timer);

		}

		else if(gkMoveRender == 2 && (gk_dive == 3 || gk_dive == 4))
			gkMoveRender = 4;

		else if(gkMoveRender == 3 && (gk_dive == 5 || gk_dive == 6))
			gkMoveRender = 5;

		else gkMoveRender++;
	}

	else if((gk_dive == 0 || gk_dive == 7 ) && !gkRun  && teamType)
	{

		if(powerRectangle2 > 560 && powerRectangle2 < 790)
			gkSaveMiddleX = (powerRectangle2 - 673) - 32;

		iPauseTimer(gk_dive_timer);
	}

	else if(gk_dive == 1  &&  !gkRun  && !teamType)
	{
		if(gkMoveRender == 4)
		{
			iPauseTimer(gk_dive_timer);

		}
		else gkMoveRender++;
	}

	else if(gk_dive == 2  &&  !gkRun  && !teamType)
	{
		if(gkMoveRender == 5)
		{
			iPauseTimer(gk_dive_timer);

		}
		else gkMoveRender++;
	}

	else if((gk_dive == 3 || gk_dive == 4  || gk_dive == 5 || gk_dive == 6) && !gkRun  && !teamType)
	{
		if(gkMoveRender == 6)
		{
			iPauseTimer(gk_dive_timer);

		}

		else if(gkMoveRender == 2 && (gk_dive == 3 || gk_dive == 4))
			gkMoveRender = 4;

		else if(gkMoveRender == 3 && (gk_dive == 5 || gk_dive == 6))
			gkMoveRender = 5;

		else gkMoveRender++;
	}

	else if((gk_dive == 0 || gk_dive == 7 ) && !gkRun  && !teamType)
	{

		if(powerRectangle2 > 560 && powerRectangle2 < 790)
			gkSaveMiddleX = (powerRectangle2 - 664) - 27;

		iPauseTimer(gk_dive_timer);
	}
}



//ballTimer() function works to change the co-ordinates of ball.........
//Called again and again from main() function......return type void

void ballTimer()
{
	if(ballMoveY > pauseBall  && ballRun)
	{
		if((gk_dive == 1 || gk_dive == 4) && powerRectangle1==22 && ballMoveX>=780 && ballMoveX<=980)
		{
			ballGo = 1;
			ballRun = false;
			goalCount(2);
		}

		else if((gk_dive == 2 || gk_dive == 3) && powerRectangle1==22 && ballMoveX>=347 && ballMoveX<=547)
		{
			ballGo = 2;
			ballRun = false;
			goalCount(2);

		}

		else if((gk_dive == 2 || gk_dive == 3  || gk_dive == 5)  && powerRectangle1==44 && ballMoveX>=347 && ballMoveX<=547)
		{
			ballGo = 2;
			ballRun = false;
			goalCount(2);
		}

		else if((gk_dive == 4 || gk_dive == 1  || gk_dive == 6) && powerRectangle1==44 && ballMoveX>=780 && ballMoveX<=980)
		{
			ballGo = 1;
			ballRun = false;
			goalCount(2);
		}

		else if((gk_dive == 5 || gk_dive == 3) && powerRectangle1==66 && ballMoveX>=347 && ballMoveX<=547)
		{
			ballGo = 2;
			ballRun = false;
			goalCount(2);
		}

		else if((gk_dive == 4 || gk_dive == 6)  &&  powerRectangle1==66 && ballMoveX>=780 && ballMoveX<=980)
		{
			ballGo = 1;
			ballRun = false;
			goalCount(2);
		}

		else if((gk_dive == 0 || gk_dive == 7 ) && (ballMoveX>547 && ballMoveX<780) && (powerRectangle1==22 || powerRectangle1==44 || powerRectangle1==66))
		{
			ballGo = 1;
			ballRun = false;
			goalCount(2);
		}

		else if(powerRectangle1==88  && ballMoveX>=315  &&  ballMoveX<=992)
		{
			ballGo = 4;
			ballRun = false;
			goalCount(2);
		}

		else if(powerRectangle1==110)
		{
			ballGo = 3;
			ballRun = false;
			goalCount(3);
		}

		else if(powerRectangle1!=0  && powerRectangle1!=110 && ballMoveX<315)
		{
			ballGo = 2;
			ballRun = false;
			goalCount(3);
		}
		else if(powerRectangle1!=0  && powerRectangle1!=110 &&  ballMoveX>992)
		{
			ballGo = 1;
			ballRun = false;
			goalCount(3);
		}

		else if(powerRectangle1!=0 && powerRectangle1!=110 && ballMoveX>=315  && ballMoveX<=325)
		{
			ballGo = 2;
			ballRun = false;
			goalCount(2);
		}

		else if(powerRectangle1!=0 && powerRectangle1!=110 && ballMoveX>=981  && ballMoveX<=992)
		{
			ballGo = 1;
			ballRun = false;
			goalCount(2);
		}

		else if(powerRectangle1==0)
		{
			ballRun = false;
			ballGo = 6;
			if(ballMoveX>=315  && ballMoveX<=992)
				goalCount(2);
			else goalCount(3);
		}

		else
		{
			//iText(700,50,"G O A L",GLUT_BITMAP_TIMES_ROMAN_24);
			ballGo = 5;
			ballRun = false;
			goalCount(1);
		}
	}

	else if(ballRun)
	{

		ballMoveX+= calculateBallMoveX;
		ballMoveY+= calculateBallMoveY;

		ballSizeX--;
		ballSizeY--;

		ballShadowX+= (powerRectangle2-668)/10;

		if(powerRectangle1== 0)
			ballShadowY+= (290-165)/10;
		else
			ballShadowY+= (346-165)/10;

		ballShadowSizeX--;
		ballShadowSizeY--;
	}

	else if(ballGo==1)
	{
		ballMoveX+= 35;
		ballShadowX+= 35;
		if(ballMoveX > 3000)
			resetValues();
	}

	else if(ballGo==2)
	{
		ballMoveX-= 35;
		ballShadowX-= 35;

		if(ballMoveX < -2000)
			resetValues();
	}

	else if(ballGo==3)
	{
		ballMoveX+= calculateBallMoveX;
		ballMoveY+= 35;
		ballShadowX+= calculateBallMoveX;
		ballShadowY+= 35;

		if(ballMoveX > 2000 || ballMoveY>2000)
			resetValues();
	}

	else if(ballGo==4)
	{
		ballMoveY+= 35;

		if(ballMoveY > 2000)
			resetValues();
	}

	else if(ballGo==5)
	{
		if(ballMoveY<=370)
		{
			playerVictory = true;
			iPauseTimer(ball_timer);
		}
		else
		{
			ballMoveY-= 15;
		}
	}

	else if(ballGo ==6)
	{
		if(spendingTimebetweenShot>1000)
		{
			resetValues();
		}
		else
			spendingTimebetweenShot+=35;
	}
}



//ballRunning() function works to start ball moving.........
//Called mainGame() function......return type void

void ballRunning()
{
	if((playerRender == 13  && teamType) ||(playerRender == 14  && !teamType))
	{
		ballRun = true;
		gkRun = false;
		redPower = false;
		glovesShow = false;
	}
}



//playerTimer() function works to change the Player Picture.........
//Called again and again from main() function......return type void

void playerTimer()
{
	if(playerRun  && teamType)
	{
		if(playerRender==17)
			playerRun = false;
		else playerRender++;
	}

	else if(playerRun  && !teamType)
	{
		if(playerRender == 20)
			playerRun = false;
		else playerRender++;
	}
}



//playerRunning() function works to show the Player Picture.........
//Called mainGame() function......return type void

void playerRunning()
{
	if(teamType  && !playerVictory)
	{
		iShowImage(60,0,screen_length,screen_width+60,opponentTeamPlayer[playerRender]);
	}
	else if(!teamType  &&  !playerVictory)
	{
		iShowImage(0,0,screen_length,screen_width,ownTeamPlayer[playerRender]);
	}
}



//powerRun1Timer function works to change the value of power(x-axis) while shooting.....return type void

void powerRun1Timer()
{
	if(coverImage==16 && powerRun1==false)
	{
		powerRectangle1 += 22;

		if(powerRectangle1>110)
			powerRectangle1 = 0;
	}
}


//powerRun1Timer function works to change the value of power(y-axis) while shooting.....return type void

void powerRun2Timer()
{
	if(coverImage==16 && powerRun2==true)
		{
			powerRectangle2 += power2length;

			if(powerRectangle2<=20 || powerRectangle2>=1260)
				power2length =  -power2length;
		}
}



//ballMove function is used to set the value how far ball will go....
//(setBallY,setBallX) take the value of desired position's x-axis and y-axis value

void ballMove(int setBallY,int setBallX)
{
	if(setBallY==0)
	{
		pauseBall = 290;
		calculateBallMoveY = (290-168)/10;
	}
	else if(setBallY==22)
	{
		pauseBall = 345;
		calculateBallMoveY = (345-168)/10;
	}
	else if(setBallY==44)
	{
		pauseBall = 415;
		calculateBallMoveY = (415-168)/10;
	}
	else if(setBallY==66)
	{
		pauseBall = 465;
		calculateBallMoveY = (465-168)/10;
	}
	else if(setBallY==88)
	{
		pauseBall = 495;
		calculateBallMoveY = (495-168)/10;
	}
	else if(setBallY==110)
	{
		pauseBall = 600;
		calculateBallMoveY = (600-168)/10;
	}

	calculateBallMoveX = (setBallX-673)/10;
}



//victoryPicture is used to show player picture after scoring a goal...return type void

void victoryPicture()
{
	if(teamType && playerVictory)
	{
		iShowImage(60,0,screen_length,screen_width+60,opponentVictory[victoryRender]);
	}
	else if(!teamType  &&  playerVictory)
	{
		iShowImage(0,0,screen_length,screen_width,ownVictory[victoryRender]);
	}
}



//victoryRunning is used to change the player picture after scoring a goal...return type void

void victoryRunning()
{
	if(teamType && playerVictory)
	{
		if(victoryRender==8)
		{
			ballGo = 6;
			iResumeTimer(ball_timer);
			iPauseTimer(victory_timer);
		}
		else
			victoryRender++;
	}
	else if(!teamType  && playerVictory)
	{

		if(victoryRender==10)
		{
			ballGo = 6;
			iResumeTimer(ball_timer);
			iPauseTimer(victory_timer);
		}
		else
			victoryRender++;
	}

}


//resetValues function is called after every shoot...return type void
//makes all characters value into default value

void resetValues()
{

	if(keyType)
	{
		gkRun = true;
		ballMoveX =673;
		ballMoveY =168;
		playerRender = 0;
		ballRun = false;
		gkMoveRender = 0;
		powerRun1 = false;
		powerRun2 = false;
		iResumeTimer(gk_dive_timer);
		iResumeTimer(ball_timer);
		iResumeTimer(victory_timer);
		powerRectangle2 = 30;
		ballShadowX = 668;
		ballShadowY = 165;
		ballSizeX = 35;
		ballSizeY = 35;
		gkRender = 0;
		ballGo = 0;
		gkSaveMiddleX = 0;
		playerRun = false;
		playerVictory = false;

		if(teamType && !challenge_mode)
		{
			teamType = false;
			opponentTotalShootNo++;
		}
		else if(!teamType && !challenge_mode)
		{
			teamType = true;
			ownTotalShootNo++;
		}

		if(!teamType)
		{
			if(playerNameRender==10)
				playerNameRender = 0;
			else
				playerNameRender++;
		}
		else if((teamType ) && (single_mode || worldCup_mode))
		{
			glovesRun = true;
			glovesRender = 0;
			glovesShow = true;
		}



		ballShadowSizeX = 40;
		ballShadowSizeY = 15;

		victoryRender = 0;
		spendingTimebetweenShot = 0;

		if((single_mode || multiPlayer_mode  || round16orHigher) && ownTotalShootNo+opponentTotalShootNo==10  &&  ownGoalCount==opponentGoalCount)
			doOrDie = true;

		else if(!challenge_mode && !doOrDie &&  ownTotalShootNo+opponentTotalShootNo==10)
		{
			coverImage = 17;
			playSound = true;
			playingSound();
		}

		else if(doOrDie && ownTotalShootNo==opponentTotalShootNo)
		{
			if(opponentGoalCount!=ownGoalCount)
			{
				coverImage = 17;
				doOrDie = false;
				playSound = true;
				playingSound();
			}
		}

		else if((((5-ownTotalShootNo) < (opponentGoalCount-ownGoalCount)) || ((5-opponentTotalShootNo) < (ownGoalCount-opponentGoalCount)))  && (single_mode || multiPlayer_mode || worldCup_mode) && !doOrDie )
		{
			coverImage = 17;
			playSound = true;
			playingSound();
		}

		keyType = false;
	}
}



//wtachRunning function is used to run the stop watch in challenge mode
//return type void

void watchRunning()
{
	if(coverImage==16  && challenge_mode)
	{
		if(clockRender2==0)
		{
			if(clockRender1==0)
			{
				coverImage = 17;
				resetValues();
			}
			else
			{
				clockRender2 = 9;
				clockRender1--;
			}
		}
		else clockRender2--;
	}
}



//goalCount function is used to count the goal after every shoot
//return type void

void goalCount(int value)
{
	if(value==1 && checkSound)
	{
		//PlaySound(NULL,0,0);
		PlaySound("music/music4.wav",NULL, SND_ASYNC);
	}
	else if(checkSound && (value==2 || value==3))
	{
		//PlaySound(NULL,0,0);
		PlaySound("music/music5.wav",NULL, SND_ASYNC);
	}


	if(challenge_mode)
	{
		if(value==1)
			userDataChallenge.userScore +=50;
		else if(value==2)
			userDataChallenge.userScore -=10;
		else if(value==3)
			userDataChallenge.userScore -=20;
	}
	else
	{
		if(value==1)
		{
			if(teamType)
			{
				opponentGoalCount++;
				if(ownTotalShootNo+opponentTotalShootNo<11)
				{
					circleDraw(value);
				}
			}
			else if(!teamType)
			{
				ownGoalCount++;
				if(ownTotalShootNo+opponentTotalShootNo<11)
				{
					circleDraw(value);
				}
			}
		}

		else if(value==2 || value==3)
		{
			if(teamType)
			{
				if(ownTotalShootNo+opponentTotalShootNo<11)
				{
					circleDraw(value);
				}
			}
			else if(!teamType)
			{
				if(ownTotalShootNo+opponentTotalShootNo<11)
				{
					circleDraw(value);
				}
			}
		}
	}
}



//circleFillup is used to draw red/green/white circle for every shoot in gamePicture page
//return type void

void circleFillup()
{
	if(coverImage==16 && !challenge_mode)
	{
		iSetColor(32,32,32);
		iFilledRectangle(10,535,320,40);
		iSetColor(255,255,255);
		int point1 = 22;
		int point2 = 300;
		for(int i = 0 ; i != 10 ; i++)
		{

			if(i%2==0)
			{
				iShowImage(point1,547,16,16,circleArray[i][circleIndex[i]]);
				point1 += 30;
			}
			else
			{
				iShowImage(point2,547,16,16,circleArray[i][circleIndex[i]]);
				point2 -= 30;
			}
		}
	}
}



//glovesRunning function is used to change the value of gloves at the time of saving a shoot

void glovesRunning()
{
	if((worldCup_mode || single_mode ) && teamType && glovesRun)
	{
		if(glovesRender == 6)
		{
			glovesRender = 0;
		}
		else
		{
			glovesRender++;
		}
	}
}



//check goal and change the color of a circle...if player scores then it will show green else red
//checkGoal takes the value to check if the shoot is successful or not

void circleDraw(int checkGoal)
{
	if(checkGoal==1)
		circleIndex[ownTotalShootNo+opponentTotalShootNo] = 2;
	else
		circleIndex[ownTotalShootNo+opponentTotalShootNo] = 1;

	circleFillup();

}



//storeDefaultData function is called after every match and makes all value into default value
//return type void

void storeDefaultData()
{
	coverImage = 2;

	if(challenge_mode)
	{
		writeChallengeFile(userDataChallenge.userName,userDataChallenge.userScore);
	}
	else if(worldCup_mode)
	{
		resetWCdata();
	}

	ownGoalCount = 0;
	opponentGoalCount = 0;
	clockRender1 = 6;
	clockRender2 = 0;
	userDataChallenge.userScore = 0;
	userDataChallenge.userName[0]  = '\0';
	opponentTotalShootNo = 0;
	ownTotalShootNo = 0;
	yourTeamNumber = 0;
	opponentTeamNumber = 0;
	playerNameRender = 0;
	teamType = false;
	glovesRun = false;


	for(int i = 0;i<11;i++)
		circleIndex[i] = 0;

	if(single_mode)
		single_mode = false;
	else if(multiPlayer_mode)
		multiPlayer_mode = false;
	else if(challenge_mode)
		challenge_mode  = false;
	else if(worldCup_mode)
		worldCup_mode = false;

}

#endif


