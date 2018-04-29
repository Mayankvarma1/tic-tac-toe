#include <stdio.h>
#include <conio.h>
#include<graphics.h>
#include<dos.h>

char square[10] = { 'o', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };

int checkwin();
void board();

void main()
{
    int player = 1, i, choice;
    char mark;

    int x,y,j,k,a,e,c=150;
    int g=DETECT, gd=DETECT, d, gm;
    initgraph(&g, &d,"C:\\TURBOC3\\BGI");
    cleardevice();
    x=getmaxx()/2;
    y=getmaxy()/2;
    settextstyle(TRIPLEX_FONT,HORIZ_DIR,3);
    setbkcolor(rand());
    setcolor(4);

    for(e=0;e<15;e++)
    {
  	for(k=50;k<100;k++)
	{
   	 	setcolor(3);
		settextstyle(SMALL_FONT, HORIZ_DIR, 10);
		outtextxy(x,y,"Loading...");
		settextstyle(SMALL_FONT, HORIZ_DIR, 5);
		outtextxy(x-5,y-5,"Please Wait... ");
		circle(x,y,k);
		circle(x,y,c);
		c--;
		cleardevice();
        }
     }

    setcolor(6);
    settextstyle(SMALL_FONT, HORIZ_DIR, 10);
    settextjustify(x,y);
    outtextxy(x-70,y-60,"WELCOME");
    delay(1000);
    outtextxy(x-70,y-20,"TO THE");
    delay(1000);
    outtextxy(x-70,y+20,"GAME OF");
    delay(1000);
    outtextxy(x-70,y+60,"TIC-TAC-TOE");
    delay(1000);

    do
    {
	board();
	player = (player % 2) ? 1 : 2;

	printf("\t\tPlayer %d, enter a number:  ", player);
	scanf("%d", &choice);

	mark = (player == 1) ? 'X' : 'O';

	if (choice == 1 && square[1] == ' ')
	    square[1] = mark;

	else if (choice == 2 && square[2] == ' ')
	    square[2] = mark;

	else if (choice == 3 && square[3] == ' ')
	    square[3] = mark;

	else if (choice == 4 && square[4] == ' ')
	    square[4] = mark;

	else if (choice == 5 && square[5] == ' ')
	    square[5] = mark;

	else if (choice == 6 && square[6] == ' ')
	    square[6] = mark;

	else if (choice == 7 && square[7] == ' ')
	    square[7] = mark;

	else if (choice == 8 && square[8] == ' ')
	    square[8] = mark;

	else if (choice == 9 && square[9] == ' ')
	    square[9] = mark;

	else
	{
	    printf("Invalid move ");

	    player--;
	    getch();
	}
	i = checkwin();

	player++;
    }while (i ==  - 1);

    board();

    if (i == 1)
    {	
	printf("==>\aPlayer %d win ", --player);
	for ( a = 200 ; a <= 1000 ; a = a + 20 )
   	{
  	    sound(a);
  	    delay(25);
  	}
  	 nosound();
    }
    else
    {
	printf("==>\aGame draw");
        for ( a = 1000 ; a >= 200 ; a = a - 20 )
        {
     	   sound(a);
     	   delay(25);
        }
        nosound();
    }
	clrscr();
	initgraph(&gd, &gm,"C:\\TURBOC3\\BGI");
	j=getmaxx();
	j=j-50;
	setcolor(15);
	for(x=0;x<=j;x++)
	{
		cleardevice();
		fflush(stdin);
		outtextxy(x,150,"THANK YOU FOR PLAYING!!!");
		outtextxy(x,180,"Created by- Mayank Varma");
		x=x+1;
		delay(20);
	}
	closegraph();
}
int checkwin()
{
    if (square[1] == square[2] && square[2] == square[3] && square[1]!=' ' && square[2]!=' ' && square[3]!=' ')
	return 1;

    else if (square[4] == square[5] && square[5] == square[6] && square[4]!=' ' && square[5]!=' ' && square[6]!=' ')
	return 1;

    else if (square[7] == square[8] && square[8] == square[9] && square[7]!=' ' && square[8]!=' ' && square[9]!=' ')
	return 1;

    else if (square[1] == square[4] && square[4] == square[7] && square[4]!=' ' && square[1]!=' ' && square[7]!=' ')
	return 1;

    else if (square[2] == square[5] && square[5] == square[8] && square[5]!=' ' && square[2]!=' ' && square[8]!=' ')
	return 1;

    else if (square[3] == square[6] && square[6] == square[9] && square[6]!=' ' && square[3]!=' ' && square[9]!=' ')
	return 1;

    else if (square[1] == square[5] && square[5] == square[9] && square[5]!=' ' && square[1]!=' ' && square[9]!=' ')
	return 1;

    else if (square[3] == square[5] && square[5] == square[7] && square[5]!=' ' && square[3]!=' ' && square[7]!=' ')
	return 1;

    else if (square[1] != ' ' && square[2] != ' ' && square[3] != ' ' &&
	square[4] != ' ' && square[5] != ' ' && square[6] != ' ' && square[7]
	!= ' ' && square[8] != ' ' && square[9] != ' ')

	return 0;
    else
	return  - 1;
}
void board()
{
    system("cls");
    printf("\n\n\t\t\tTic Tac Toe\n\n");

    printf("\t\t\tPlayer 1 (X)  -  Player 2 (O)\n\n\n");

    printf("\t\t\t     |     |     \n");
    printf("\t\t\t  %c  |  %c  |  %c \n", square[1], square[2], square[3]);

    printf("\t\t\t_____|_____|_____\n");
    printf("\t\t\t     |     |     \n");

    printf("\t\t\t  %c  |  %c  |  %c \n", square[4], square[5], square[6]);
    printf("\t\t\t_____|_____|_____\n");
    printf("\t\t\t     |     |     \n");

    printf("\t\t\t  %c  |  %c  |  %c \n", square[7], square[8], square[9]);
    printf("\t\t\t     |     |     \n\n");
	delay(10);
}
