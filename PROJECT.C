#include<stdio.h>
#include<graphics.h>
int dcol[]={BLUE,MAGENTA,RED,GREEN};
int lcol[]={CYAN,LIGHTMAGENTA,LIGHTRED,LIGHTGREEN};
int n,ch[4],i,j;
void sort()
{
	int t;
	for (i=0;i<n-1;i++)
		for (j=0;j<n-i-1;j++)
			if (ch[j]>ch[j+1])
			{
				t=ch[j];
				ch[j]=ch[j+1];
				ch[j+1]=t;
			}
}
void back()
{

	line(-7,480,43,400);
	line(583,400,633,480);
	line(633,480,-7,480);
	rectangle(43,90,583,400);
	rectangle(25-7,60,615-7,90);
	setfillstyle(LINE_FILL,DARKGRAY);
	floodfill(100,470,WHITE);
	setfillstyle(SOLID_FILL,LIGHTGRAY);
	floodfill(30,80,WHITE);
	setfillstyle(SOLID_FILL,DARKGRAY);
	floodfill(50,300,WHITE);
}
void main()
{
	int gd=DETECT,gm,o=50,x,y=65,t;
	initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
	setlinestyle(SOLID_LINE,1,3);
	back();
	for (i=0;i<4;i++)
	{
		rectangle(25+o,100+y,125+o,200+y);
		rectangle(40+o,115+y,110+o,185+y);
		rectangle(60+o,200+y,90+o,225+y);
		line(40+o,40+y,65+o,83+y);
		arc(75+o,100+y,0,180,20);
		rectangle(50+o,70,100+o,80);
		setfillstyle(SOLID_FILL,LIGHTGRAY);
		floodfill(30+o,105+y,WHITE);
		setfillstyle(SOLID_FILL,lcol[i]);
		floodfill(75+o,95+y,WHITE);
		setfillstyle(SOLID_FILL,dcol[i]);
		floodfill(75+o,150+y,WHITE);
		setfillstyle(SOLID_FILL,BROWN);
		floodfill(75+o,205+y,WHITE);
		setfillstyle(SOLID_FILL,RED);
		floodfill(55+o,75,WHITE);
		o+=125;
	}
	o=50;
	do
	{
		printf("Enter the number of drinks you want (1-4) ");
		scanf("%d",&n);
		if(n<=0||n>4)
			printf("Incorrect Option Please choose again\n");
	}while(n<=0||n>4);
	printf("Press 1 for Blue 2 for Magneta 3 for Red 4 for Green ");
	for (i=0;i<n;i++)
	{
		do
		{
			scanf("%d",&ch[i]);
			if(ch[i]<=0||ch[i]>4)
				printf("Incorrect Option Please choose again\n");
		}while(ch[i]<=0||ch[i]>4);
	}
	sort();
	t=0;
	for(i=0;i<4;i++)
	{
		if (ch[t]==i+1)
		{
			delay(400);
			setfillstyle(SOLID_FILL,GREEN);
			floodfill(55+o,75,WHITE);
			ellipse(75+o,275+y,0,360,51,15);
			ellipse(75+o,400+y,0,360,25,10);
			line(23+o,275+y,48+o,400+y);
			line(126+o,275+y,101+o,400+y);
			delay(400);
			setcolor(DARKGRAY);
			line(40+o,40+y,65+o,83+y);
			setcolor(WHITE);
			line(110+o,40+y,85+o,83+y);
			setcolor(dcol[i]);
			setfillstyle(SOLID_FILL,lcol[i]);
			for (j=-3;j<=3;j++)
			{
				line(75+o+j,227+y,75+o+j,395+y);
			}
			x=24;
			for(j=398;j>=305;j--)
			{
				delay(20);
				if (j%5==0)
					x++;
				fillellipse(75+o,j+y,x,8);
			}
			setcolor(DARKGRAY);
			for (j=-3;j<=3;j++)
			{
				line(75+o+j,227+y,75+o+j,296+y);
			}
			line(110+o,40+y,85+o,83+y);
			setcolor(WHITE);
			ellipse(75+o,275+y,0,360,51,15);
			line(40+o,40+y,65+o,83+y);
			arc(75+o,100+y,0,180,20);
			t++;
		}
		o+=125;
	}
	printf("Enjoy your drink");
	getch();
	closegraph();
}