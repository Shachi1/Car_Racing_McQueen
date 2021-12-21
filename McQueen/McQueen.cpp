#include "iGraphics.h"
#include "bitmap_loader.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include<algorithm>
//#include <bits/stdc++.h>
using namespace std;
int screenlength = 1080, screenWidth = 675;
int x = 425, y = 10, dx = 100, dy = 207, y2 = 10, x2 = 425, x3 = 250, y3 = 450, xa = 425, b = 603, c = 250, test = 3,rndTrack;
int pic1, pic2, pic3, indexOponent, indexTime,indextest,indexOfScore,indexOfOver, roadId1,a = 3;
int covereddistance = 0, finalscore,gameover=false, life=3;
  
char opponent[3][80] = { "pic//bg//menu//oponent1.bmp", "pic//bg//menu//oponent2.bmp", "pic//bg//menu//oponent3.bmp" };
int i = 0,j=0;
int roadY = 0, roadY2 = 675;
bool enter = true, menu, newgame, level, resume, credits, highscore, quit, about, instructions, mode, easy, medium, hard, single, _double, load;
bool randCar = false, collision, singlePlayer, doublePlayer;
void page1(){
	iPauseTimer(indexOponent);
	iPauseTimer(indexTime);
	iPauseTimer(indextest);
	iShowBMP(0, 0, "pic//bg//bg.bmp");
	
}

void Menu(){
	iShowBMP(0, 0, "pic//bg//menu//menuBg.bmp");
	iShowBMPAlternativeSkipWhite(50, 510, "pic//bg//menu//Buttons//newgame.bmp");
	iShowBMPAlternativeSkipWhite(50, 390, "pic//bg//menu//Buttons//resume.bmp");
	iShowBMPAlternativeSkipWhite(50, 270, "pic//bg//menu//Buttons//highscore.bmp");
	iShowBMPAlternativeSkipWhite(50, 150, "pic//bg//menu//Buttons//instructions.bmp");
	iShowBMPAlternativeSkipWhite(50, 30, "pic//bg//menu//Buttons//quit.bmp");
	iShowBMP2(900, 110, "pic//bg//menu//Buttons//about.bmp", 0xffffff);
	iShowBMP2(900, 50, "pic//bg//menu//Buttons//credit.bmp", 0xffffff);
}

void Newgame(){
	iShowBMP(0, 0, "pic//bg//menu//level.bmp");
	iShowBMP2(750, 495, "pic//bg//menu//Buttons//easy.bmp", 0xffffff);
	iShowBMP2(750, 395, "pic//bg//menu//Buttons//medium.bmp", 0xffffff);
	iShowBMP2(750, 295, "pic//bg//menu//Buttons//hard.bmp", 0xffffff);
	iShowBMP2(50, 620, "pic//bg//menu//Buttons//back.bmp", 0xffffff);
}
void Easy(){
	iShowBMP(0, 0, "pic//bg//menu//mode.bmp");
	iShowBMP2(140, 340, "pic//bg//menu//Buttons//single.bmp", 0xffffff);
	iShowBMP2(560, 340, "pic//bg//menu//Buttons//double.bmp", 0xffffff);
	iShowBMP2(50, 620, "pic//bg//menu//Buttons//back.bmp", 0xffffff);
}
void Medium(){
	iShowBMP(0, 0, "pic//bg//menu//mode.bmp");
	iShowBMP2(140, 340, "pic//bg//menu//Buttons//single.bmp", 0xffffff);
	iShowBMP2(560, 340, "pic//bg//menu//Buttons//double.bmp", 0xffffff);
	iShowBMP2(50, 620, "pic//bg//menu//Buttons//back.bmp", 0xffffff);
}
void Hard(){
	iShowBMP(0, 0, "pic//bg//menu//mode.bmp");
	iShowBMP2(140, 340, "pic//bg//menu//Buttons//single.bmp", 0xffffff);
	iShowBMP2(560, 340, "pic//bg//menu//Buttons//double.bmp", 0xffffff);
	iShowBMP2(50, 620, "pic//bg//menu//Buttons//back.bmp", 0xffffff);
}
void Resume(){
	iShowBMP(0, 0, "pic//bg//menu//menuBg.bmp");
}


void Instructions(){
	iShowBMP(0, 0, "pic//bg//menu//instructions.bmp");
	iShowBMP2(50, 620, "pic//bg//menu//Buttons//back.bmp", 0xffffff);
}
void About(){
	iShowBMP(0, 0, "pic//bg//menu//about.bmp");
	iShowBMP2(50, 620, "pic//bg//menu//Buttons//back.bmp", 0xffffff);
}
void Highscore(){
	iShowBMP(0, 0, "pic//bg//menu//menuBg.bmp");
	iShowBMP2(50, 620, "pic//bg//menu//Buttons//back.bmp", 0xffffff);
	//show_score();

}
void Credits(){
	iShowBMP(0, 0, "pic//bg//menu//credits.bmp");
	iShowBMP2(50, 620, "pic//bg//menu//Buttons//back.bmp", 0xffffff);
}
void Mode(){
	easy = false;
	medium = false;
	hard = false;
}
void save_score(int my_score){
    int score = my_score;
    FILE *f = fopen("player_score.txt", "r");
    //for(int i = 0; i < 10; i++){
        fscanf(f, "%d", &score);
    //}
    fclose(f);
    //sort(score, score + 11);
    //reverse(score, score + 11);
    f = fopen("player_score.txt", "w");
    //for(int i = 0; i < 10; i++){
        fprintf(f, "%4d\n", score);
    //}
    fclose(f);
}
void roadMove(){
	roadY -= a;
	roadY2 -= a;

	if (roadY <= -675 && roadY2 <= 0){
		roadY = 0;
		roadY2 = 675;
	}
	covereddistance += a;
}
void Collision(){
	//y3 += 50;
	//if (y + dy >= y3 && y + dy <= y3 + 2 * dy){
		if (y + dy > y3+20 && y < y3 + dy){
			if (x + dx > x3 && x  < x3 ){
				xa += 100;
				b += 100;
				c += 100;
				life--;
			}

			else if (x > x3 && x < x3 + dx ){
				xa -= 100;
				b -= 100;
				c  -= 100;
				life--;
			}
		}
		if (y + dy >= y3 && y + dy <= y3+20){
			if (x + dx > x3 && x < x3 + dx){
				y3 += 150;
				life--;
			}
		}
		 
}

void show_score(){
    char str[100];
    int score;
    FILE *f = fopen("player_score.txt", "r");
    //for(int i = 0; i < 10; i++){
        fscanf(f, "%d", &score);
   // }
    //for(int i = 0; i < 9; i++){
        sprintf(str, "McQueen\t-\t%4d\n", score);
        iText(123, 564, str);
        //printf("McQueen\t-\t%3d\n", score[i]);
    //}
    fclose(f);
}


void RandCar(){
	switch (j){
	case 0: x3 = xa;
		break;
	case 1: x3 = b;
		break;
	case 2: x3 = c;
		break;
	}

	iShowBMPAlternativeSkipWhite(x3, y3, opponent[i]);

	y3 -= 20;
	
	if (y3 < -300){
		y3 = 700;
		xa = 425;
		b = 603;
		c = 250;
		j = rndTrack;
		if (i == 2){
			i = -1;
		}

		i++;
		iResumeTimer(indexOponent);

	}
}
void oponent(){
	randCar = true;
	iPauseTimer(indexOponent);
}
void GameOver(){
	randCar = false;
	load = false;

	//iPauseTimer(index);
	iShowBMP(0, 0, "pic//bg//menu//gameOver2.bmp");
	//save_score(finalscore);
	//show_score();
	//exit(0);
	finalscore = covereddistance;

}
void DoublePlayer(){
	iShowBMPAlternativeSkipWhite(x2, y2, "pic//bg//menu//player2.bmp");
	if (x + dx >= x2 && x <= x2 + dx){
		x2 = x + dx + 10;
		x = x2 - dx - 20;
	}
	else if (x2 + dx >= x && x2 <= x + dx){
		x = x2 + dx + 10;
		x2 = x - dx - 10;
	}
}
void Loadgame(){
	iShowBMPAlternative(0, roadY, "pic//bg//menu//road1.bmp");
	iShowBMPAlternative(0, roadY2, "pic//bg//menu//road1.bmp");
	iResumeTimer(indexOfScore);
	iPauseTimer(indexTime);
	iShowBMPAlternativeSkipWhite(x, y, "pic//bg//menu//player1.bmp");

	collision = true;
	iResumeTimer(indexOponent);
	//iResumeTimer(indexOfOver);
	iResumeTimer(indextest);
	if (doublePlayer == true){
		DoublePlayer();
	}
	if (life <= 0){
		gameover = true;
	}
}
void Test(){
	test--;
	if (test <= 0){
		gameover = true;
	}
	
}
void Time(){
	if (a <= 12){
		a += 20;
	}
	
}
void iDraw()
{

	iClear();

	if (enter){
		page1();
	}
	if (menu){
		Menu();
	}
	if (newgame){
		Newgame();
	}
	if (easy){
		Easy();
	}
	if (medium){
		Medium();
	}
	if (hard){
		Hard();
	}
	if (resume){
		Resume();
	}
	if (highscore){
		Highscore();
	}
	if (instructions){
		Instructions();
	}
	if (load){
		Loadgame();
	}
	if (quit){
		exit(0);
	}
	if (about){
		About();
	}
	if (credits){
		Credits();
	}
	if (!mode){
		Mode();
	}
	if (randCar){
		RandCar();
	}
	if(collision)
	    Collision();

	if (gameover)
		GameOver();
	

}


void iMouseMove(int mx, int my)
{
	x2 = mx;

}

void iMouse(int button, int state, int mx, int my)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{

		if (mx > 50 && mx < 450)
		{
			if (my > 510 && my < 595 && menu == true)
			{
				menu = false;
				newgame = true;

			}
			if (mx > 50 && mx < 150 && my > 620 && my < 653 && newgame)
			{
				newgame = false;
				menu = true;
			}


			if (my > 390 && my < 475 && menu == true)
			{
				menu = false;
				resume = true;
			}


			if (my > 270 && my < 355 && menu == true)
			{
				menu = false;
				highscore = true;
			}

			if (mx > 50 && mx < 150 && my > 620 && my < 653 && highscore)
			{
				highscore = false;
				menu = true;
			}

			if (my > 150 && my < 253 && menu == true)
			{
				menu = false;
				instructions = true;
			}

			if (mx > 50 && mx < 150 && my > 620 && my < 653 && instructions)
			{
				instructions = false;
				menu = true;
			}

			if (my > 30 && my < 115 && menu == true)
			{
				menu = false;
				quit = true;
			}

		}
		//if (mx > 900 && mx < 1050){
		if (mx > 900 && mx < 1050 && my >110 && my < 160 && menu == true){
			menu = false;
			about = true;
		}

		if (mx > 50 && mx < 150 && my > 620 && my < 653 && about)
		{
			about = false;
			menu = true;
		}

		if (mx > 900 && mx < 1050 && my > 50 && my < 100 && menu == true){
			menu = false;
			credits = true;
		}

		if (mx > 50 && mx < 150 && my > 620 && my < 653 && credits)
		{
			credits = false;
			menu = true;
		}
		//}


		//if (mx > 750 && mx < 1030){
		if (mx > 750 && mx < 1030 && my >495 && my < 555 && newgame == true){
			newgame = false;
			easy = true;
			mode = true;
		}

		if (mx > 50 && mx < 150 && my > 620 && my < 653 && mode && easy)
		{
			easy = false;
			mode = false;
			newgame = true;
		}

		if (mx > 750 && mx < 1030 && my > 395 && my < 455 && newgame){
			newgame = false;
			medium = true;
			mode = true;
		}

		if (mx > 50 && mx < 150 && my > 620 && my < 653 && mode && medium)
		{
			medium = false;
			mode = false;
			newgame = true;
		}

		if (mx > 750 && mx < 1030 && my > 295 && my < 355 && newgame){
			newgame = false;
			hard = true;
			mode = true;
		}

		if (mx > 50 && mx < 150 && my > 620 && my < 653 && mode && hard)
		{
			hard = false;
			mode = false;
			newgame = true;
		}
		//}


		if (my >340 && my < 425 && mode){
			if (mx > 140 && mx < 540){
				mode = false;
				load = true;
				singlePlayer = true;
			}


			if (mx > 560 && mx < 960){
				mode = false;
				load = true;
				doublePlayer = true;
			}

		}


	}


}

void iKeyboard(unsigned char key)
{
	if (key == ' ' &&  enter == true){
		enter = false;
		menu = true;
	}

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
	
	if (key == GLUT_KEY_UP && load == true){
		roadMove();
		iResumeTimer(indexTime);
	}
	
	if (key == GLUT_KEY_LEFT){
		x -= 20;
		roadMove();
	}
	if (key == GLUT_KEY_RIGHT){
		x += 20;
		roadMove();
	}
	if (key == GLUT_KEY_END){
		iShowBMP(0, 0, "pic//bg//bg.bmp");
		page1();
		newgame == false;
		easy == false;
		medium == false;
		hard == false;
		load == false;
		mode == false;

	}
}




int main()
{
	srand((unsigned int)time(NULL));
	int rnd = 1000 + rand() % 3000;
	indexOponent = iSetTimer(rnd, oponent);
	rndTrack = 0 + rand() % 2;
	indexTime = iSetTimer(2000, Time);
	indextest = iSetTimer(100000,Test);
	iPauseTimer(indexOfScore);
	iInitialize(screenlength, screenWidth, "McQueen");

	roadId1 = iLoadImage("pic//bg//menu//road.png");
	iStart();

	return 0;
}

