#include<stdio.h>
//stdlib is used to perform rand(random) function as rand is stored in stdlib
#include<stdlib.h>
//console input output is used to use getch
#include<conio.h>
//global variables
// x and y are the coordinates of the  snakes head 
//fruitX and fruitY are the coordinates of fruit
int height=20,width=20.,x,y,fruitX,fruitY,flag,game,score;
//t=tail
int tx[100],ty[100];
int piece=0;
//this function will be used for the movement of snake.This is the main logic function
void logic()
{ 
// this is performed to increase the length of snake
    int i;
    int prevx,prevy,prev2x,prev2y;
    prevx=tx[0];
    prevy=ty[0];
    tx[0]=x;
    ty[0]=y;
    for(i=1;i<=piece;i++)
    {
    	prev2x=tx[i];
    	prev2y=ty[i];
    	tx[i]=prevx;
    	ty[i]=prevy;
    	prevx=prev2x;
    	prevy=prev2y;
	}
//upto here for length of snake	
	switch(flag)
	{
		case 1:
			{
			  x--;
			  break;
			}
	    case 2:
	    	{
	    		x++;
	    		break;
			}
		case 3:
		{
			y--;
			break;
		}
		case 4:
		{
			y++;
			break;
		}	
	}
	if(x==0 || x==height || y==0 || y==width)
	{
		game=1;
	}
	if(x==fruitX && y==fruitY)
	{
label3:
	fruitX=rand()%20;
	if(fruitX==0)
	goto label3;
	
	label4:
	fruitY=rand()%20;
	if(fruitY==0)
	goto label4;
	score+=10;
	piece++;
	}
}
//to use kbhit function and make snake moving
void input()
{
//kbhit is used to run the code until any key is presses from the keboard..kbhit=keyboard hit	
	if(kbhit)
	{
//getch is used to know which key is been pressed		
		switch(getch())
		{
			case 'w':
			{
				flag=1;
				break;
			}
			case 's':
			{
				flag=2;
				break;
}
			case 'a':
			{
				flag=3;
				break;
			}
		    case 'd':
			{
				flag=4;
				break;
			}	
		}
	}
}
void setup()
{
	x=height/2;
	y=width/2;
	label1:
//we used mod as we want the fruit to stay inside the block only as mod will not give the answer more than 20
	fruitX=rand()%20;
	if(fruitX==0)
//goto is used to perform the label 1 again	
	goto label1;
	
label2:
	fruitY=rand()%20;
	if(fruitY==0)
	goto label2;
	game=0;
	score=0;
	piece++;
}
//this void draw is used to draw the outer boundary
void  draw()
{
//system("cls) is stored in stdlib and is used to clear the screen as the boundaries keeps on drawing again aand again
	system("cls");
	int i,j,k,ch;
	// i is used for height
	for(i=0;i<=height;i++)
	{
		//here j is used for width
	    for(j=0;j<=width;j++)
	    {
	       if(i==0 || i==height || j==0 || j==width)
	       {
	       	printf("*");
		   }
		  else
		  {
		  	if(i==x && j==y)
			  {
			  	printf("0");
}
			else if(i==fruitX && j==fruitY)
			{
				printf("@");
			}  
			else 
			{   ch=0;
			    for(k=0;k<piece;k++)
				{
					if(i==tx[k] && j==ty[k])
					{
						printf("o");
						ch=1;
					}
				}
				if(ch==0)	
				printf(" ");
			}
		  	
		  }
		  
	    }
	     printf("\n");
	}
printf("Your score is\t %d",score);	
}
int main()
{
	printf("Enter any key to start :)");
//setup function is called  
    setup();
    while(game!=1)
    {
    	//input function is called    
    input();
//draw function is called
	draw();
//logic function is called	
	logic();
	}
}