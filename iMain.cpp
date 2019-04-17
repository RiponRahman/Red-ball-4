#include "iGraphics.h"
#include "bitmap_loader.h"
#define screenHeight 1209
#define screenWidth 680



void showable(void);  //For showing score
void read(void);   //For reading score from file


int playing=0,scoreTimer;
char strng[10];char hScr[10];
int stop = 0;
int scr;
char home[20] = {"homepage.bmp"};
char credit[20] = {"credit.bmp"};
char ins[20] = {"instruction.bmp"};
char ball[4][20] = {"ball0.bmp", "ball1.bmp", "ball2.bmp", "ball3.bmp"};
char ballStand[20] = {"ball.bmp"};
char score[20] = {"score.bmp"};
char level[20] = {"level.bmp"};
int flag = 0;
int ballX = 130, ballY = 115, ballIndex = 0, StandCounter = 0 ;
int i = 0,flag1=1;
int bgx = 130, bgy = 0, image1, spy=10, image2, image3, gov;
int bgxx = bgx - 130;
int enemyX1 = 1200, enemyY1=115;
int enemyXX1 = 1900;
int enemyXXX1 = 2300;
int enemyXXXX1 = 2900;
int scoreX = 1160, scoreY1 = 595, scoreY2 = 75;
int bgX = 0, bgY = 0;
int medium; 
int enimage; 
int background[2];
int background_x[] = {0,screenHeight}, background_y[]={0,0};
int mediumbackground[2];
int medium_background_x[] = {0,screenHeight}, medium_background_y[]={0,0};
int len=0;
int point;
char nameShow[10];
char pname[100];
char str[20],str2[20];


//function iDraw() is called again and again by the system.

void HomePage()
{
	// For homepage image
	iShowBMP(0,0,home);
}

void ilevel()
{
	//level selection
	iShowBMP(0, 0, level);
}

void icredit()
{
	//Showing credit
	iShowBMP(0,0, credit);
}

void instruction()
{
	//instruction about the game
	iShowBMP(0, 0, ins);
}

void iscore()
{
	//score reading from file and showing in screen
	iShowBMP(0, 0, score);
	read();
	showable();
}

void change_background()
{ for(int i=0;i<2;i++)
	{
		background_x[i] -= 10; //left slide
		if(background_x[i]+screenHeight<0) //left slide out of frame
			background_x[i] = background_x[(i+1)%2]+screenHeight; 

	}
}

void change_medium()
{
	for(int i=0;i<2;i++)
	{
		medium_background_x[i] -= 10; //left slide
		if(medium_background_x[i]+screenHeight<0) //left slide out of frame
			medium_background_x[i] = medium_background_x[(i+1)%2]+screenHeight; 

	}
}


void scoreIncrement(){

	if(playing)
		scr++;
}




void startinglevel()
{
	for(int i=0;i<2;i++)
		iShowImage(background_x[i],0,screenHeight + 10,screenWidth,background[i]);
	iShowBMP2(ballX, ballY, ball[ballIndex], 0);
	iShowImage(enemyX1,enemyY1,100/2+20,100/2,image2);  //obstacle 1
	iShowImage(enemyXX1,270,100/2+20,70,image1);
	//iShowImage(enemyXXX1,enemyY1,100/2+20,100/2,image3);
	//iShowImage(enemyXXXX1,enemyY1,100/2+20,100/2,image2);
		
		
	if((ballX >= enemyX1 && ballX <= enemyX1 +70 && ballY <= enemyY1+50)   || ( ballX>= enemyXX1 && ballX <= enemyXX1 +90 && ballY <= 340)){    //COLLISION
		scoreY2 = scoreY2 - 15;
		//ballX=enemyX1;
	}
	iSetColor(255, 0, 0);
	iText(45, 630, "Score : ",  GLUT_BITMAP_TIMES_ROMAN_24);
	//iText(45, 595, "High Score : ",  GLUT_BITMAP_TIMES_ROMAN_24);
		
	iSetColor(255, 255, 255);  //life level
	iFilledRectangle(1160, 595, 20, 76);

	iSetColor(255, 0, 0);
	iFilledRectangle(1160, 595, 20, scoreY2);  //LIFE LEVEL

		if(scoreY2 <= 0){
			flag=6;
			iPauseTimer(scoreTimer);
		}
		
		//if(ballX>enemyX1+44  && stop == 0)
			//scr=20;


		sprintf(strng,"%d",scr);
		/*if(scr>highestScore){
			highestScore=scr;
		}*/
		//sprintf(hScr,"%d",highestScore);


		iSetColor(255,0,0);


		iText(150,630,strng,GLUT_BITMAP_TIMES_ROMAN_24);
		//iText(190,595,hScr,GLUT_BITMAP_TIMES_ROMAN_24);

		if(ballX>=enemyX1 && ballY<=enemyY1+50 )
			stop = 1;
		if(ballX<=enemyX1 )
			stop = 0;


		//sprintf(strng,"%d",scr);


		//iSetColor(255,0,0);


		//iText(150,630,strng,GLUT_BITMAP_TIMES_ROMAN_24);

}

void mediumlevel()
{
	for(int i=0;i<2;i++){
		iShowImage(medium_background_x[i],0,screenHeight + 10,screenWidth,mediumbackground[i]);}
	iShowBMP2(ballX, ballY, ball[ballIndex], 0);
	iShowImage(enemyX1,enemyY1,100/2+20,100/2,image2);  //obstacle 1
	iShowImage(enemyXX1, 270, 90, 70, image3); // enemy2
	iShowImage(enemyXXX1, 350, 90, 70, image1); 

	
		
	if((ballX >= enemyX1 && ballX <= enemyX1 +70 && ballY <= enemyY1+50)   || ( ballX>= enemyXX1 && ballX <= enemyXX1 +90 && ballY <= 340  && ballY>= 270) || ( ballX>= enemyXXX1 && ballX <= enemyXXX1 +90 && ballY <= 420 && ballY >= 35))   //COLLISION
		scoreY2 = scoreY2 - 15;
	iSetColor(255, 0, 0);
	iText(45, 630, "Score : ",  GLUT_BITMAP_TIMES_ROMAN_24);
	//iText(45, 595, "High Score : ",  GLUT_BITMAP_TIMES_ROMAN_24);
		
	iSetColor(255, 255, 255);  //life level
	iFilledRectangle(1160, 595, 20, 76);

	iSetColor(255, 0, 0);
	iFilledRectangle(1160, 595, 20, scoreY2);  //LIFE LEVEL

		if(scoreY2 <= 0)
			flag=6;
		//iPauseTimer(scoreTimer);

		
		//if(ballX>enemyX1+70  && stop == 0)
			//scr=20;


		sprintf(strng,"%d",scr);


		iSetColor(255,0,0);


		iText(150,630,strng,GLUT_BITMAP_TIMES_ROMAN_24);


		if(ballX>=enemyX1 && ballY<=enemyY1+50 )
			stop = 1;
		if(ballX<=enemyX1 )
			stop = 0;


		//sprintf(strng,"%d",scr);


		//iSetColor(255,0,0);


		//iText(150,630,strng,GLUT_BITMAP_TIMES_ROMAN_24); 
}


void moveEnemy()
{
	enemyX1 = enemyX1 - 10; 
	enemyXX1 = enemyXX1 - 10; 
	enemyXXX1 = enemyXXX1 - 10;

	if(enemyX1 < 0)
		enemyX1 = 1200;
	if(enemyXX1 < 0)
		enemyXX1 = 1200;
	if(enemyXXX1 < 0)
		enemyXXX1 = 1200;
}


void GameOver(){



	iShowImage(0,0,1209,680,gov);

	iSetColor(255, 0, 0);
	iText(45, 630, "Score : ",  GLUT_BITMAP_TIMES_ROMAN_24);
	//iText(45, 595, "High Score : ",  GLUT_BITMAP_TIMES_ROMAN_24);

	
	

		iSetColor(255,0,0);


		iText(150,630,strng,GLUT_BITMAP_TIMES_ROMAN_24);

		//iText(190,595,hScr,GLUT_BITMAP_TIMES_ROMAN_24);
		read();
		iPauseTimer(scoreTimer);

}



  void gravity()
{
	if(flag1==0)
	{
	ballY=ballY-10;
	if(ballY<115)
	{
		ballY=115;

	}

	}
}


void iDraw()
{
	//place your drawing codes here
	iClear();
	
	HomePage();
	iSetColor(0, 0, 0);
	//iRectangle(530,230,150,150);   //play 1
	//iRectangle(375, 258, 95, 95);  //instruction 3
	//iRectangle(740, 258, 95, 95);  //score 4
	//iRectangle(383, 13, 200, 80);  //quit
	//iRectangle(628, 13, 200, 80);  //credit 2
	if(flag == 5)
		ilevel();
	else if(flag == 1)
		startinglevel();
	else if(flag == 2)
		icredit();
	else if(flag == 3)
		instruction();
	else if(flag == 4)
		iscore();
	else if(flag == 0)
		HomePage();
	else if(flag == 7)
		mediumlevel();

	if(flag==6)
		GameOver();
	
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
//	printf("x = %d, y= %d\n", mx, my);
	//place your codes here
}

/*
 function iMouse() is called when the user presses/releases the mouse.
 (mx, my) is the position where the mouse pointer is.
 */
void iMouse(int button, int state, int mx, int my)
{   printf("%d %d \n",mx,my);
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		if(mx>=530 && my>=230 && mx<=680 && my<=380)
			flag = 5;
		if(mx>=628 && my>=13 && mx<=828 && my<=93)
			flag = 2;
		if(mx>=375 && my>=258 && mx<=470 && my<=353)
			flag = 3;
		if(mx>=740 && my>=258 && mx<=835 && my<=353)
			flag = 4;
		if(mx>=383 && my>=13 && mx<=583 && my<=93)
			exit(0);
		
		
	}
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here
		
	}
}

/*
 function iKeyboard() is called whenever the user hits a key in keyboard.
 key- holds the ASCII value of the key pressed.
 */
void iKeyboard(unsigned char key)
{
	if (key == '1')
	{
		flag = 1;
		playing=1;
	}

	if (key == '2')
	{
		flag = 7;
		playing=1;
	}
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
	
	if (key == GLUT_KEY_F5)
	{
		flag = 0;
	}

	if (key == GLUT_KEY_LEFT)
	{
		ballX -= 35;
		ballIndex--;
		bgx=bgx+23;
		printf("%d-----> \n",bgx);
	    if(ballIndex <0)
			ballIndex = 3;
		//standPos = false;
	}
	if (key == GLUT_KEY_RIGHT)
	{


		if(ballX+44<enemyX1 || ballX>enemyX1+70 || ballY>enemyY1+50){
		ballX += 35;
		ballIndex++;
		bgx=bgx-25;
		enemyX1=enemyX1-5;}
		if(ballX>1209)
		{
			bgxx=0;
			ballX=130;

		}
	    if(ballIndex >= 4)
			ballIndex = 0;
		//standPos = false;


		//if(ballX>obgx+58)
			//scr=20;


		

	}

		if (key == GLUT_KEY_UP)
	{
		flag1=0;
		ballY = ballY + 25;
		//ballX = ballX + 10;
		



	}





	//place your codes for other keys here
}


struct Player {
	
	int score;

    

};

Player winner[10];

void read()
{
	//reading name and scores from the text file
	FILE *fp = fopen("score.txt", "r");
	for(int i=0; i<5; i++){
		int sc;
		fscanf(fp, "%d", &sc);
		
		winner[i].score = sc;////putiing score in structure type array
	}

		winner[5].score = scr;

	fclose(fp);
	int temp;
	
	//bubble sorting the score in higher order
	for(int i=0; i<6; i++){
		for(int j=0; j<5; j++){
			if(winner[j].score <winner[j+1].score){
				


				temp = winner[j].score;
				winner[j].score = winner[j+1].score ;
				winner[j+1].score = temp;

		

			}
		}
	}
	
 


}
//showing name and score in the games score page


void showable(){


	


		sprintf(nameShow, "%d", winner[0].score);
		iText(500, 350,nameShow, GLUT_BITMAP_TIMES_ROMAN_24);


		sprintf(nameShow, "%d", winner[1].score);
		iText(500, 310,nameShow, GLUT_BITMAP_TIMES_ROMAN_24);

	

		sprintf(nameShow, "%d", winner[2].score);
		iText(500, 270,nameShow, GLUT_BITMAP_TIMES_ROMAN_24);


		sprintf(nameShow, "%d", winner[3].score);
		iText(500, 230,nameShow, GLUT_BITMAP_TIMES_ROMAN_24);



		sprintf(nameShow, "%d", winner[4].score);
		iText(500, 190,nameShow, GLUT_BITMAP_TIMES_ROMAN_24);




	   

}

int main()
{
	//place your own initialization codes here.

	read();
	iInitialize(screenHeight, screenWidth, "Demo");
	image1=iLoadImage("image (2).png");
	image2=iLoadImage("image2.png");
	image3=iLoadImage("image (3).png");
	gov=iLoadImage("gameover.png");
	//image4 = iLoadImage("image (3).png");
	iSetTimer(50,gravity);
	iSetTimer(40, moveEnemy);
	iSetTimer(40,change_background);
	iSetTimer(20, change_medium);
	scoreTimer=iSetTimer(125,scoreIncrement);

	background[0] = iLoadImage("riponGadha.png");	
	background[1] = iLoadImage("riponGadhaa.png");
	mediumbackground[0] = iLoadImage("maxresdefault - Copy.jpg");
	mediumbackground[1] = iLoadImage("maxresdefault.jpg");

	iStart(); // it will start drawing

	return 0;
}

