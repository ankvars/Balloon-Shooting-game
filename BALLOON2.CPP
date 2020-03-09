#include<iostream.h>
#include<dos.h>
#include<stdlib.h>
#include<graphics.h>
#include<time.h>
#include<conio.h>
#include<stdio.h>
union REGS in,out;
void notmove();
void move()
{
	char hits[10],miss[10],scr[5],blt[10],sr[10];
	int i,j,k,x,mis=0,hit=0,blts=5,scrs=0,cnth=0,cntm=0;
	float srs=0;
	setfillstyle(HATCH_FILL,RED);
	randomize();
	i=5;
	rec:
	while(i)
	{
		mis=mis+cntm;
		hit=hit+cnth;
		blts=i;
		scrs=scrs+(cnth*1000)-(cntm*500);
		if(hit==0)
			srs=0;
		else if(i<5)
			srs=(float)(hit)/(5-(blts))*100.0;
		x=random(450-100+1)+100;
		for(j=430;j>70;j--)
		{
			sprintf(hits,"%d",hit);
			sprintf(miss,"%d",mis);
			sprintf(scr,"%d",scrs);
			sprintf(blt,"%d",blts);
			sprintf(sr,"%0.3f",srs);
			outtextxy(530,250,hits);
			outtextxy(530,330,miss);
			outtextxy(530,170,scr);
			outtextxy(530,90,blt);
			outtextxy(530,410,sr);
			int button;
			in.x.ax =3;
			int86 (0X33,&in,&out);
			button=out.x.bx&7;
			if(button==1)
			{
				sound(50);
				delay(100);
				nosound();
				for(k=65;j>70&&k<495;j--)
				{
					fillellipse(x,j,10,20);
					circle(k,240,5);
					notmove();
					delay(20);
					cleardevice();
					k+=3;
					if(j>=215 && j<=255 && k+5<=x+10 && k+5>=x-10)
					{
						i--;
						notmove();
						cnth=1;
						cntm=0;
						settextstyle(0,0,3);
						setcolor(CYAN);
						outtextxy(300,100,"BOOM!");
						setcolor(15);
						sound(50);
						delay(1000);
						nosound();
						cleardevice();
						goto rec;
					}
					else
					{
						cntm=1;
						cnth=0;

					}
					blts--;
				}
				i--;
				goto rec;
			}
			cntm=0;
			cnth=0;
			notmove();
			fillellipse(x,j,10,20);
			delay(20);
			cleardevice();

		}
	}
	//getch();
	mis=mis+cntm;
	hit=hit+cnth;
	blts=0;
	scrs=scrs+(cnth*1000)-(cntm*500);
	notmove();
	sprintf(hits,"%d",hit);
	sprintf(miss,"%d",mis);
	sprintf(scr,"%d",scrs);
	sprintf(blt,"%d",blts);
	sprintf(sr,"%0.3f",srs);
	outtextxy(530,250,hits);
	outtextxy(530,330,miss);
	outtextxy(530,170,scr);
	outtextxy(530,90,blt);
	outtextxy(530,410,sr);
	getch();
	cleardevice();
	settextstyle(0,0,3);
	setcolor(BLUE);
	outtextxy(200,100,"Score : ");
	outtextxy(200,200,"Hits : ");
	outtextxy(200,300,"Miss : ");
	outtextxy(200,400,"S. Rate : ");
	setcolor(RED);
	outtextxy(380,100,scr);
	outtextxy(380,200,hits);
	outtextxy(380,300,miss);
	outtextxy(450,400,sr);
	getch();
	cleardevice();
}
void initial()
{
	settextstyle(0,0,2);
	rectangle(10,10,600,440);
	setcolor(RED);
	outtextxy(100,200,"WELCOME TO BALLOON SHOOTING!");
	settextstyle(0,0,1);
	setcolor(15);
	outtextxy(350,300,"PRESS ANY KEY TO CONTINUE");
	getch();
	cleardevice();
	settextstyle(0,0,3);
	setcolor(RED);
	outtextxy(200,100,"RULES");
	settextstyle(0,0,2);
	setcolor(15);
	outtextxy(100,200,"1. Get 1000 points on 1 hit");
	outtextxy(100,250,"2. Lose 500 points on 1 miss");
	outtextxy(100,300,"3. You have total 5 bullets");
	setcolor(BLUE);
	outtextxy(200,400,"PRESS ANY KEY TO CONTINUE");
	getch();
	cleardevice();
	settextstyle(0,0,5);
	setcolor(CYAN);
	outtextxy(300,220,"3");
	sound(200);
	delay(1000);
	nosound();
	delay(500);
	cleardevice();
	outtextxy(300,220,"2");
	sound(200);
	delay(1000);
	nosound();
	delay(500);
	cleardevice();
	outtextxy(300,220,"1");
	sound(200);
	delay(1000);
	nosound();
	delay(500);
	cleardevice();
	outtextxy(250,220,"GO!!");
	sound(300);
	delay(1000);
	nosound();
	cleardevice();
	closegraph();
}
void notmove()
{
	int arr[]={40,230,50,230,60,240,50,250,40,250,40,230};
	settextstyle(0,0,1);
	rectangle(40,40,600,440);
	line(500,40,500,440);
	outtextxy(510,60,"BULLETS");
	line(500,120,600,120);
	outtextxy(510,140,"SCORE");
	line(500,200,600,200);
	outtextxy(510,220,"HITS");
	line(500,280,600,280);
	outtextxy(510,300,"MISS");
	line(500,360,600,360);
	outtextxy(510,380,"S.RATE");
	drawpoly(5,arr);
	//getch();
	//cleardevice();
	//closegraph();
}
void last()
{
	settextstyle(0,0,4);
	setcolor(BLUE);
	outtextxy(200,220,"GAME OVER!");
	sound(100);
	delay(2000);
	nosound();
}

void main()
{
	int gd=0,gm;
	initgraph(&gd,&gm,"");
	initial();
	initgraph(&gd,&gm,"");
	notmove();
	move();
	last();
	getch();
	closegraph();

}
