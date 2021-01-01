#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include<dos.h>
#include<process.h>
union REGS in,out;

char Aa[9][9]={'','2','1','2','','','','1','-'
	      , '1','2','','2','2','3','2','1','-'
	      , '1','2','2','1','-','-','-','-','-'
	      , '1','','1','-','-','-','-','-', '-'
	      , '1','1','1','-','1','1','1','-', '-'
	      , '-','-', '-','1','2','','2','1','-'
	      , '-','-','-','1','','3','','2', '1'
	      , '-','-','-','1','1','2','1','2', ''
	      , '-','-','-','-','-','-','-','1', '1'};
char ABC[9][9];
char AB[9][9];
void checking ();
int minedisplay();
void detect()
{
	int x,y,z,o;
	in.x.ax=3;
	int86(0X33,&in,&out);
	if(out.x.bx==1)
	{
		x=out.x.cx;
		y=out.x.dx;
	}
}

int play_mine ()
{
	//int d=DETECT,m;
	int poly[8];
	int k,l;
	int i,j;
	int x,y;
	//initgraph(&gd,&gm,"c:\\tc\\bgi");
	setbkcolor(4);

	detect();

	for(i=0;i<9;i++)
		for(j=0;j<9;j++)
			AB[i][j]=' ';

	minedisplay();

	while(1)
	{
		in.x.ax=3;
		int86(0X33,&in,&out);

		if(out.x.bx==1)
		{

				x=out.x.cx;
				y=out.x.dx;
				for(j=45,k=0;j<444;j=j+50,k++)
				{
					for(i=60,l=0;i<507;i=i+50,l++)
					{
						if ((x>=i) && (x<=(i+45)) && (y>=j) && (y<=(j+45)))
						{

							if(Aa[k][l]=='')
							{
								AB[k][l]=Aa[k][l];
								minedisplay();
								outtextxy(200,200,"Game Over");
								delay(100);
								getch();
								//exit(0);
								in.x.ax=2;
								int86(0x33,&in,&out);
								cleardevice();
								//in.x.ax=1;int86(0x33,&in,&out);
								return;
							}
							AB[k][l]=Aa[k][l];
							ABC[k][l]=Aa[k][l];
							checking();
							in.x.ax=2;int86(0x33,&in,&out);
							minedisplay ();

						}
					}
				}

		}

	}







 //	getch ();
  //	closegraph();
}



int minedisplay ()
{
	int poly[8];
	int i,j,k,l;
	//in.x.ax=2;
	//int86(0x33,&in,&out);
	poly[0] = 60;
	poly[1] = 45;
	poly[2] = 507;
	poly[3] = 45;
	poly[4] = 507;
	poly[5] = 444;
	poly[6] = 60;
	poly[7] = 444;
	setcolor(8);
	setfillstyle(1,1);
	fillpoly(4,poly);
	rectangle(58,43,509,446);

	for(i=45;i<=395;i=i+50)
		for(j=60;j<=507;j=j+50)
			rectangle(j,i,j+45,i+45);
	setcolor(15);
	settextstyle(10,0,3);
	outtextxy(523,20,"M");
	outtextxy(530,60,"I");
	outtextxy(525,100,"N");
	outtextxy(525,140,"E");
	outtextxy(525,180,"S");
	outtextxy(517,220,"W");
	outtextxy(525,260,"E");
	outtextxy(525,300,"E");
	outtextxy(525,340,"P");
	outtextxy(525,380,"E");
	outtextxy(525,420,"R");



	 setcolor(2);
	settextstyle(0,0,3);
	for(i=0,k=57;i<9;i++,k=k+50)
	{
		for(j=0,l=70;j<9;j++,l=l+50)
		{
			switch(AB[i][j])
			{
				case '1':
					 outtextxy(l,k,"1 ");
					 break;

				case '2':
					outtextxy(l,k,"2 ");
					 break;

				case '3':
					 outtextxy(l,k,"3 ");
					 break;

				case '4':
					 outtextxy(l,k,"4 ");
					 break;

				case '':
					 outtextxy(l,k," ");
					 break;

				case '-':
					 outtextxy(l,k,"- ");
					 break;

				default :
					 outtextxy(l,k," ");
					 break;
			}


		}
	}
	in.x.ax=1;
	int86(0x33,&in,&out);
	//showmouse();
}

void checking ()
{
	int i,j,k,l;
	for(i=0;i<=8;i++)
	{
		for(j=0;j<=9;j++)
		{
			if(Aa[i][j]=='')
			{
				ABC[i][j]=Aa[i][j];
			}
		}
	}
	for(i=0;i<=8;i++)
	{
		for(j=0;j<=9;j++)
		{
			if(Aa[i][j]!=ABC[i][j])
			{
				return;
			}
		}
	}

	setcolor(2);
	settextstyle(0,0,3);
	for(i=0,k=57;i<9;i++,k=k+50)
	{
		for(j=0,l=70;j<9;j++,l=l+50)
		{
			switch(ABC[i][j])
			{
				case '1':
					 outtextxy(l,k,"1 ");
					 break;

				case '2':
					outtextxy(l,k,"2 ");
					 break;

				case '3':
					 outtextxy(l,k,"3 ");
					 break;

				case '4':
					 outtextxy(l,k,"4 ");
					 break;

				case '':
					 outtextxy(l,k," ");
					 break;

				case '-':
					 outtextxy(l,k,"- ");
					 break;

				default :
					 outtextxy(l,k," ");
					 break;
			}


		}
	}
	settextstyle(5,0,6);
	outtextxy(100,100,"YOU WIN..!");
	delay(100);
	exit(0);
}
int castle_state_p1=1;
void showmouse ();
void detect ();
void inidisplay ();
int castle_state_p2=1;
int CastleDone_p1=0;
int CastleDone_p2=0;
int poly[150];

int *pawnimage;int pawnsize;

char arr[8][8]= {'r','n','b','q','k','b','n','r',
		'p','p','p','p','p','p','p','p',
		'-','-','-','-','-','-','-','-',
		'-','-','-','-','-','-','-','-',
		'-','-','-','-','-','-','-','-',
		'-','-','-','-','-','-','-','-',
		'P','P','P','P','P','P','P','P',
		'R','N','B','Q','K','B','N','R'};

int reinitialize()
{
	arr[0][0]='r';arr[0][1]='n';arr[0][2]='b';arr[0][3]='q';arr[0][4]='k';arr[0][5]='b';arr[0][6]='n';arr[0][7]='r';
	arr[1][0]='p';arr[1][1]='p';arr[1][2]='p';arr[1][3]='p';arr[1][4]='p';arr[1][5]='p';arr[1][6]='p';arr[1][7]='p';
	arr[2][0]='-';arr[2][1]='-';arr[2][2]='-';arr[2][3]='-';arr[2][4]='-';arr[2][5]='-';arr[2][6]='-';arr[2][7]='-';
	arr[3][0]='-';arr[3][1]='-';arr[3][2]='-';arr[3][3]='-';arr[3][4]='-';arr[3][5]='-';arr[3][6]='-';arr[3][7]='-';
	arr[4][0]='-';arr[4][1]='-';arr[4][2]='-';arr[4][3]='-';arr[4][4]='-';arr[4][5]='-';arr[4][6]='-';arr[4][7]='-';
	arr[5][0]='-';arr[5][1]='-';arr[5][2]='-';arr[5][3]='-';arr[5][4]='-';arr[5][5]='-';arr[5][6]='-';arr[5][7]='-';
	arr[6][0]='P';arr[6][1]='P';arr[6][2]='P';arr[6][3]='P';arr[6][4]='P';arr[6][5]='P';arr[6][6]='P';arr[6][7]='P';
	arr[7][0]='R';arr[7][1]='N';arr[7][2]='B';arr[7][3]='Q';arr[7][4]='K';arr[7][5]='B';arr[7][6]='N';arr[7][7]='R';
}
char temp[2][2];
char P1[10],P2[10];
int game_over();
int P1_chance=1,P2_chance=0;
int move(int,int,int,int);
int knightin(int,int);
int icheck(int,int,int,int,int,int);
int check(int,int,int,int);
int valid_position(int,int,int,int);
void display();
void _king(int i,int j,int color);
void _minister(int i,int j,int color);
void _pawn(int,int,int);
void _rook(int,int,int);
void _knight(int,int,int);
int castle(int,int,int,int,int,int);
int king_incheck(int,int,int ,int);
void player_details();
int is_your_own(int,int);
int resolved(int,int,int,int,int,int);
int open_check(int,int,int,int);
//void pawn();


//union REGS in,out;
void draw_frame2_ladder();
void draw_frame2_chessboard();
void draw_frame2_IQboard();
void draw_frame2_snakeboard();
void play_snake_display(char name[10][12],int,int);
//static int snakeboard[65];
int pos[6];
void draw_frame1();
int draw_frame2();
void IQ_LVL1();
int input_manipultion_from_frame2();
void background();
void play_chess();
void draw_background();
void * ladder1img;int ladder1size;
void * ladder2img;int ladder2size;
void * ladder3img;int ladder3size;
void * ladder4img;int ladder3size;
void * bgimg;int bgsize;
void pawn()//drawing the pawn image
{
	cleardevice();
	setbkcolor(15);
	setcolor(5);
	setlinestyle(0,1,1);
	setfillstyle(1,5);
	poly[0]=52;poly[1]=66;poly[2]=17;poly[3]=66;poly[4]=17;poly[5]=60;poly[6]=28;poly[7]=50;poly[8]=28;poly[9]=41;poly[10]=23;poly[11]=41;poly[12]=23;poly[13]=37;poly[14]=43;poly[15]=37;poly[16]=43;poly[17]=41;poly[18]=39;poly[19]=41;poly[20]=39;poly[21]=50;poly[22]=52;poly[23]=60;
	fillpoly(12,poly);
	fillellipse(33,29,7,7);
	pawnsize= imagesize(10,20,60,70);
   // allocate memory to hold the image
   pawnimage = malloc(pawnsize);
   //grab the image
   getimage(10,20,60,70, pawnimage);     //getch();
   cleardevice();
}

void draw_background()
{
	int z,i,j;
	cleardevice();
	for( z=1;z<600;z++)
		putpixel((random(40)+1),(random(40)+1),2);

	bgsize=imagesize(0,0,40,40);
	bgimg=(void *)malloc(bgsize);
	getimage(0,0,40,40,bgimg);
	cleardevice();
}
void draw_frame2_chessboard()
{
	int i,j,k,a,b=13,c,d=13;
	int poly[6]={215,215,225,220,215,225};
	setcolor(0);
	for(i=1;i<=8;i++)
		if(i%2)
			for(j=0;j<23;j++,a=13,b++,c=46,d++)
				for(k=0;k<4;k++,a+=66,c+=66)
					line(a,b,c,d);
		else
			for(j=0;j<23;j++,a=46,b++,c=79,d++)
				for(k=0;k<4;k++,a+=66,c+=66)
					line(a,b,c,d);

	a=46;b=13;c=79;d=13;
	setcolor(WHITE);
	for(i=1;i<=8;i++)
		if(i%2)
			for(j=0;j<23;j++,a=46,b++,c=79,d++)
				for(k=0;k<4;k++,a+=66,c+=66)
					line(a,b,c,d);
		else
			for(j=0;j<23;j++,a=13,b++,c=46,d++)
				for(k=0;k<4;k++,a+=66,c+=66)
					line(a,b,c,d);

	setcolor(WHITE);
	setlinestyle(0,0,3);
	arc(240,200,180,360,3);
	arc(200,200,180,360,3);
	setlinestyle(0,0,3);
	ellipse(200,211,0,360,1,7);
	ellipse(240,211,0,360,1,7);
	setcolor(15);
	setfillstyle(1,15);
	bar3d(190,211,250,230,0,1);
	setcolor(2);
	setfillstyle(1,2);
	fillpoly(3,poly);
	setlinestyle(0,0,1);
}
void draw_frame2_IQboard()
{
	int poly[10]={410,16,580,16,580,194,410,194};
	setfillstyle(1,7);
	setcolor(8);
	bar3d(410,16,580,194,5,1);
	//fillpoly(4,poly);

	setfillstyle(1,8);

	arc(430,193,0,180,10);
	circle(448,180,12);

	circle(448,178,1);
	circle(455,178,1);
	line(442,187,451,187);

	line(425,194,452,180);
	line(452,180,440,194);
	poly[0]=500;poly[1]=130;poly[2]=580;poly[3]=110;poly[4]=580;poly[5]=194;poly[6]=530;poly[7]=194;
	fillpoly(4,poly);
	poly[0]=580;poly[1]=100;poly[2]=580;poly[3]=194;poly[4]=520;poly[5]=194;poly[6]=527;poly[7]=192;poly[8]=577;poly[9]=112;
	setfillstyle(1,7);
	fillpoly(5,poly);

	/*protracter*/
	setfillstyle(1,6);
	poly[0]=510;poly[1]=16;poly[2]=580;poly[3]=55;poly[4]=580;poly[5]=60;poly[6]=510;poly[7]=60;
	fillpoly(4,poly);
	poly[0]=520;poly[1]=30;poly[2]=560;poly[3]=50;poly[4]=520;poly[5]=50;
	setfillstyle(1,7);
	fillpoly(3,poly);

	settextstyle(0,1,0);
	outtextxy(520,53,"-");
	outtextxy(525,53,"-");
	outtextxy(530,53,"-");
	outtextxy(535,53,"-");
	outtextxy(540,53,"-");
	outtextxy(545,53,"-");
	outtextxy(550,53,"-");
	outtextxy(555,53,"-");
	outtextxy(560,53,"-");
	outtextxy(565,53,"-");
	outtextxy(570,53,"-");
	outtextxy(575,53,"-");
	outtextxy(480,65,"CODE x");
	outtextxy(430,80,"C");
	outtextxy(440,80,"H");
	outtextxy(450,80,"A");
	outtextxy(460,80,"L");
	outtextxy(470,80,"L");
	outtextxy(490,80,"N");
	outtextxy(500,80,"G");
	outtextxy(510,80,"E");
	settextstyle(0,0,0);
	outtextxy(510,20,"-");
	outtextxy(510,25,"-");
	outtextxy(510,30,"-");
	outtextxy(510,35,"-");
	outtextxy(510,40,"-");
	outtextxy(510,45,"-");
	outtextxy(510,50,"-");

	outtextxy(570,185,"2");

	/* chemistry*/
	setcolor(8);
	outtextxy(413,23,"H");
	outtextxy(420,27,"2");
	outtextxy(427,23,"O");
	line(413,50,415,43);
	line(417,41,424,38);
	line(426,39,433,43);
	line(433,45,433,54);
	line(431,54,422,54);
	line(420,53,415,51);
	line(418,44,418,48);
	line(425,41,430,45);
	line(429,52,424,52);

	line(434,43,445,41);
	line(445,41,444,35);
	line(448,35,447,41);
	outtextxy(443,27,"o");
	line(447,41,456,43);
	outtextxy(459,40,"o");
	line(468,42,475,38);
	outtextxy(480,38,"CH");
	outtextxy(495,42,"3");

	/*arithmatic*/
	settextstyle(1,0,0);
	outtextxy(440,110,"+");
	settextstyle(0,0,0);
	outtextxy(438,123,"-");
	outtextxy(452,122,"%");
	outtextxy(439,135,"/");
	outtextxy(453,135,"*");

	/*play button*/
	setcolor(WHITE);
	setlinestyle(0,0,3);
	setfillstyle(1,8);
	arc(550,200,180,360,3);
	arc(590,200,180,360,3);
	fillellipse(550,211,1,7);
	fillellipse(590,211,1,7);
	setcolor(15);

	setfillstyle(1,15);
	bar3d(540,211,600,230,0,1);
	setcolor(2);
	poly[0]=565;poly[1]=215;poly[2]=575;poly[3]=220;poly[4]=565;poly[5]=225;
	setfillstyle(1,2);
	fillpoly(3,poly);
	setlinestyle(0,0,0);





}/*
int game_over()
{
	int i,j;
	if(P1_chance)
	{

		for(i=0;i<=7;i++)
		{
			for(j=0;j<=7;j++)
			{
				if(P1_chance)
				{
					if(arr[i][j]=='K')
					{
						goto Q;
					}
				}
				else
				{
					if(arr[i][j]=='k')
					{
						goto Q;
					}
				}
			}
		}
	}
	Q:
	if(P1_chance)
		if((!check(i,j,i,j)))
			if(!escape(i,j))
				if(!check(i,j,i,j))

				return(0);
			else
				return(1);
		else
			return(1);


}
int escape(int i, int j)
{     int no=0;
	if(!check(i,j,i-1,j)
		no++;
	if(!check(i,j,i-1,j+1)
		no++;
	if(!check(i,j,i,j+1)
		no++;
	if(!check(i,j,i+1,j+1)
		no++;
	if(!check(i,j,i+1,j)
		no++;
	if(!check(i,j,i+1,j-1)
		no++;
	if(!check(i,j,i,j-1)
		no++;
	if(!check(i,j,i-1,j-1)
		no++;
	if(no>=8)
		return(0);
	else
		return(1);
}
   */
void play_chess()
{

	char ch='y';
	int a=-1,b=-1,c=-1,d=-1,i,j,x,y,z,o,l,k,q;



	cleardevice();
	pawn();

	//inidisplay();
	display();

	while(ch=='y')
	{
		//game_over();
		q=1;
		showmouse();
		while(q)
		{
			C:
			in.x.ax=3;
			int86(0X33,&in,&out);
			if(out.x.bx==1)
			{
				x=out.x.cx;
				y=out.x.dx;
				/*exit condition*/
				if((x>=600&&x<=625))
				{
					if(y>=30&&y<=60)
					{
						reinitialize();
						in.x.ax=2;
						int86(0x33,&in,&out);
						cleardevice();
						return;

					}
				}
				for(j=20,k=0;j<426;j=j+50,k++)
				{
					for(i=10,l=0;i<397;i=i+50,l++)
					{
						if ((x>=i) && (x<=(i+50)) && (y>=j) && (y<=(j+50)))
						{
							a=k;
							b=l;
							q=0;
						     //	printf("%ld",m);
						}
					}
				}
			}
		}
		while(!q)
		{

			in.x.ax=3;
			int86(0X33,&in,&out);
		   if(out.x.bx==1)
				goto C;
			if(out.x.bx==2)
			{
				z=out.x.cx;
				o=out.x.dx;


				for(j=20,k=0;j<426;j=j+50,k++)
				{
					for(i=10,l=0;i<397;i=i+50,l++)
					{
						if ((z>=i) && (z<=(i+50)) && (o>=j) && (o<=(j+50)))
						{
							c=k;
							d=l;
							q=1;

						}

					}
				}
			}
		}

		if(!is_your_own(a,b))
			continue;
		if(!move(a,b,c,d))
			continue;
		if(P1_chance)
		{
			P2_chance=1;
			P1_chance=0;
		}
		else
		{
			P1_chance=1;
			P2_chance=0;
		}


	}
	//closegraph();
}
int move(int a,int b,int c,int d)
{
	if(!king_incheck(a,b,c,d))
	{
		poly[0]=10;poly[1]=429;poly[2]=100;poly[3]=429;poly[4]=100;poly[5]=469;poly[6]=10;poly[7]=469;
		setfillstyle(1,0);
		setcolor(0);
		fillpoly(4,poly);
		setcolor(4);
		settextstyle(0,0,0);
		//setviewport(450,100,500,150,1);
		outtextxy(10,439,"KING under CHECK");
		return(0);
	}
	if(!(valid_move(a,b,c,d)))
	{
		poly[0]=10;poly[1]=429;poly[2]=100;poly[3]=429;poly[4]=100;poly[5]=469;poly[6]=10;poly[7]=469;
		setfillstyle(1,0);
		setcolor(0);
		fillpoly(4,poly);
		setcolor(4);
		settextstyle(0,0,0);
		//setviewport(450,100,500,150,1);
		outtextxy(10,439,"! a VALID MOVE");
		return 0;
	}
	if(CastleDone_p1 || CastleDone_p2)
	{
		CastleDone_p1=0;
		CastleDone_p2=0;
		goto Z;
	}
	if(!(valid_path(a,b,c,d)))
	{
		poly[0]=10;poly[1]=429;poly[2]=100;poly[3]=429;poly[4]=100;poly[5]=469;poly[6]=10;poly[7]=469;
		setfillstyle(1,0);
		setcolor(0);
		fillpoly(4,poly);
		setcolor(4);
		settextstyle(0,0,0);
		//setviewport(450,100,500,150,1);
		outtextxy(10,439,"no OVER CROSSING");
		return 0;
	}
	if(!(valid_position(a,b,c,d)))
	{
		poly[0]=10;poly[1]=429;poly[2]=100;poly[3]=429;poly[4]=100;poly[5]=469;poly[6]=10;poly[7]=469;
		setfillstyle(1,0);
		setcolor(0);
		fillpoly(4,poly);
		setcolor(4);
		settextstyle(0,0,0);
		//setviewport(450,100,500,150,1);
		outtextxy(10,439,"DON't KILL YOURSELF");
		return 0;
	}
	if(!open_check(a,b,c,d))
	{
		poly[0]=10;poly[1]=429;poly[2]=100;poly[3]=429;poly[4]=100;poly[5]=469;poly[6]=10;poly[7]=469;
		setfillstyle(1,0);
		setcolor(0);
		fillpoly(4,poly);
		setcolor(4);
		settextstyle(0,0,0);
		//setviewport(450,100,500,150,1);
		outtextxy(10,439,"AN open CHECK!...");
		return(0);
	}

     Z:	arr[c][d]=arr[a][b];
	arr[a][b]='-';
	cleardevice();
	display();
	return 1;
}
int is_your_own(int a,int b)
{
	if(P1_chance)
		if(arr[a][b]>=65 && arr[a][b]<=90)
			return(1);
		else
		{
			poly[0]=10;poly[1]=429;poly[2]=100;poly[3]=429;poly[4]=100;poly[5]=469;poly[6]=10;poly[7]=469;
			setfillstyle(1,0);
			setcolor(0);
			fillpoly(4,poly);
			setcolor(4);
			settextstyle(0,0,0);
			//setviewport(450,100,500,150,1);
			outtextxy(10,439,"Move ur piece");
			return(0);
		}

	else
		if(arr[a][b]>=97 && arr[a][b]<=122)
			return(1);
		else
		{

			poly[0]=10;poly[1]=429;poly[2]=100;poly[3]=429;poly[4]=100;poly[5]=469;poly[6]=10;poly[7]=469;
			setfillstyle(1,0);
			setcolor(0);
			fillpoly(4,poly);
			setcolor(4);
			settextstyle(0,0,0);
			//setviewport(450,100,500,150,1);
			outtextxy(10,439,"Move ur piece");
			return(0);
		}
}
int open_check(int a,int b,int c,int d)
{
	int i,j;
	for(i=0;i<=7;i++)
	{
		for(j=0;j<=7;j++)
		{
			if(P1_chance)
			{
				if(arr[i][j]=='K')
				{
					goto Q;
				}
			}
			else
			{
				if(arr[i][j]=='k')
				{
					goto Q;
				}
			}
		}
	}
	Q:
	if(!resolved(i,j,a,b,c,d))
		return(0);
	else
		return(1);

}
int king_incheck(int a,int b,int c,int d)
{
	int i,j;
	for(i=0;i<=7;i++)
	{
		for(j=0;j<=7;j++)
		{
			if(P1_chance)
			{
				if(arr[i][j]=='K')
				{
					goto L;
				}
			}
			else
			{
				if(arr[i][j]=='k')
				{
					goto L;
				}
			}
		}
	}
	L:
	if(P1_chance)
		if(arr[a][b]!='K' && (!check(i,j,i,j)))
			if(!resolved(i,j,a,b,c,d))
				return(0);
			else
				return(1);
		else
			return(1);
	else
		if(arr[a][b]!='k' && (!check(i,j,i,j)))
			if(!resolved(i,j,a,b,c,d))
				return(0);
			else
				return(1);
		else
			return(1);
}

int resolved(int i,int j,int a,int b,int c,int d)
{
	int p,q;
	char temp1[2][2];
	temp1[0][0]=arr[a][b];
	temp1[0][1]=arr[c][d];
	arr[c][d]=arr[a][b];
	arr[a][b]='-';
	for(p=0;p<=7;p++)
	{
		for(q=0;q<=7;q++)
		{
			if(P1_chance)
			{
				if(arr[p][q]=='K')
				{
					goto X;
				}
			}
			else
			{
				if(arr[p][q]=='k')
				{
					goto X;
				}
			}
		}
	}


	     X:	if(!check(p,q,p,q))
		{
			arr[a][b]=temp1[0][0];
			arr[c][d]=temp1[0][1];
			return(0);
		}
		else
		{
			arr[a][b]=temp1[0][0];
			arr[c][d]=temp1[0][1];
			return(1);
		}

}


int castle(int i,int j,int a,int b,int c,int d) //actually c ,d variables are not nececcary!...
{
	if(b>d)
	{
		if(arr[a][b]=='K')
		{
			if(arr[i][j]=='R')
			{
				if(!castle_state_p1)
					return(0);
				//arr[c][d]=arr[a][b];
				if(!check(a,b,c,b-1))
					return(0);
				if(!check(a,b,c,b-2))
					return(0);
				arr[c][d+1]=arr[i][j];
				arr[i][j]='-';
				castle_state_p1=0;
				return(1);
			}
			return(0);
		}
		else
		{
			if(arr[i][j]=='r')
			{

				if(!castle_state_p2)
					return(0);
				if(!check(a,b,c,b-1))
					return(0);
				if(!check(a,b,c,b-2))
					return(0);
				arr[c][d+1]=arr[i][j];
				arr[i][j]='-';
				castle_state_p2=0;
				return(1);
			}
			return(0);
		}
	}
	else
	{
		if(arr[a][b]=='K')
		{
			if(arr[i][j]=='R')
			{

				if(!castle_state_p1)
					return(0);
				if(!check(a,b,c,b+1))
					return(0);
				if(!check(a,b,c,b+2))
					return(0);
				arr[c][d-1]=arr[i][j];
				arr[i][j]='-';
				castle_state_p1=0;
				return(1);
			}
			return(0);
		}
		else
		{
			if(arr[i][j]=='r')
			{

				if(!castle_state_p2)
					return(0);
				if(!check(a,b,c,b+1))
					return(0);
				if(!check(a,b,c,b+2))
					return(0);
				arr[c][d-1]=arr[i][j];
				arr[i][j]='-';
				castle_state_p2=0;
				return(1);
			}
			return(0);
		}
	}
}
void display()
{
	int a=10,b=20,c=60,d=20,i,j,k,w=10,x=20,y=410,z=420;
	int p=10,q=20;
	cleardevice();

	setbkcolor(0);
	setcolor(6);
	in.x.ax=2;  /*hides the mouse pointer*/
	int86(0x33,&in,&out);
	//for(i=0,w=0,x=3,y=640,z=3;i<500;i++,x+=1,z+=1)
	//line(w,x,y,z);

	//getch();

	//setcolor(8);
	//for(i=0,w=0,x=3,y=640,z=3;i<170;i++,x+=3,z+=3)
	//line(w,x,y,z);

	//getch();

	//setcolor(6);
	//for(i=0,w=437,x=17,y=627,z=420;i<150;i++,w++,x++,y--,z--)
	//rectangle(w,x,y,z);

	//getch();

	//setcolor(5);
	//for(i=0,w=437,x=17,y=437,z=420;i<64;i++,w+=3,y+=3)
	//line(w,x,y,z);
	setcolor(BLUE);
	settextstyle(7,0,4);
	for(i=0,w=10,x=19,y=411,z=421;i<5;i++,w--,x--,y++,z++)
	rectangle(w,x,y,z);

	//getch();

	//setcolor(RED);
	//for(i=0,w=4,x=429,y=633,z=475;i<46;i++,w++,x++,y--,z--)
	//	rectangle(w,x,y,z);

	//getch();

	//for(i=0,w=430,x=10,y=627,z=420;i<7;i++,w++,x++,y++,z++)
	//rectangle(w,x,y,z);

	//getch();

	/*draw save button*/

	/*draw the close button*/
	setcolor(15);
	setfillstyle(1,15);
	poly[0]=600;poly[1]=30;poly[2]=625;poly[3]=30;poly[4]=625;poly[5]=60;poly[6]=600;poly[7]=60;
	fillpoly(4,poly);
	setlinestyle(0,0,3);
	setcolor(4);
	line(600,30,625,60);
	line(625,30,600,60);
	settextstyle(2,0,0);
	setcolor(8);
	outtextxy(603,37,"e");
	outtextxy(610,29,"x");
	outtextxy(619,39,"i");
	outtextxy(610,48,"t");
	setcolor(4);
	rectangle(600,30,625,60);

	//getch();exit(0);
	/*drawing chess board*/
	setcolor(0);
	for(i=1;i<=8;i++)
		if(i%2)
			for(j=0;j<50;j++,a=10,b++,c=60,d++)
				for(k=0;k<4;k++,a+=100,c+=100)
					line(a,b,c,d);
		else
			for(j=0;j<50;j++,a=60,b++,c=110,d++)
				for(k=0;k<4;k++,a+=100,c+=100)
					line(a,b,c,d);
	a=60;b=20;c=110;d=20;
	setcolor(15);
	for(i=1;i<=8;i++)
		if(i%2)
			for(j=0;j<50;j++,a=60,b++,c=110,d++)
				for(k=0;k<4;k++,a+=100,c+=100)
					line(a,b,c,d);
		else
			for(j=0;j<50;j++,a=10,b++,c=60,d++)
				for(k=0;k<4;k++,a+=100,c+=100)
					line(a,b,c,d);

	/* p,q are the positions where the pawn,rook etc..should place*/



	for(i=0;i<8;i++,q+=50)
	{
		for(j=0,p=10;j<8;j++,p+=50)
		{
		      switch(arr[i][j])
		      {
				case 'r':
					_rook(p,q,6);
					//setcolor(5);
					//settextstyle(1,0,4);
					//outtextxy(p,q,"R");
					break;
				case 'R':
					_rook(p,q,8);
					//setcolor(RED);
					//settextstyle(1,0,4);
					//outtextxy(p,q,"R");
					break;
				case 'n':
					_knight(p,q,6);
					//setcolor(5);
					//settextstyle(1,0,4);
					//outtextxy(p,q,"N");
					break;
				case 'N':
					_knight(p,q,8);
					//setcolor(RED);
					//settextstyle(1,0,4);
					//outtextxy(p,q,"N");
					break;
				case 'b':
					_bishop(p,q,6);
					//setcolor(5);
					//settextstyle(1,0,1);
					//outtextxy(p,q,"B");
					break;
				case 'B':
					_bishop(p,q,8);
					//setcolor(RED);
					//settextstyle(1,0,4);
					//outtextxy(p,q,"B");
					break;
				case 'k':
					//setcolor(5);
					//settextstyle(1,0,4);
					_king(p,q,6);
					//outtextxy(p,q,"K");
					//outtextxy(p,q-7,"+");
					break;
				case 'K':
					//setcolor(RED);
					//settextstyle(1,0,4);
					_king(p,q,8);
					//outtextxy(p,q,"K");
					//outtextxy(p,q-7,"+");
					break;
				case 'p': _pawn(p,q,6);
					//putimage(p-15,q+5,pawnimage,4);
					break;
				case 'P': _pawn(p,q,8);
					//putimage(p-15,q+5,pawnimage,4);
					//setcolor(5);line(13,300,640,300);
					break;
				case '-':
					outtextxy(p,q,"");
					break;
				case 'q':
					_minister(p,q,6);
					//setcolor(5);
					//settextstyle(1,0,4);
					//outtextxy(p,q,"Q");
					break;
				case 'Q':
					_minister(p,q,8);
					//setcolor(RED);
					//settextstyle(1,0,4);
					//outtextxy(p,q,"Q");
					break;
		      }
		}
	}
	display_gone_items();
	//setcolor(4);
	//settextstyle(1,0,2);
	//outtextxy(440,50,"Click here to Quit.!");
	in.x.ax=1; /*shows mouse pointer*/
	int86(0x33,&in,&out);
	//getch();exit(0);
}
int display_gone_items()
{
	int i,j,R=0,r=0,N=0,n=0,B=0,b=0,Q=0,q=0,P=0,p=0,w,x;
	for(i=0;i<8;i++)
	{
		for(j=0;j<8;j++)
		{
			if(arr[i][j]=='R')
			{
				R++;
			}
			if(arr[i][j]=='N')
			{
				N++;
			}
			if(arr[i][j]=='B')
			{
				B++;
			}
			if(arr[i][j]=='Q')
			{
				Q++;
			}
			if(arr[i][j]=='P')
			{
				P++;
			}
			if(arr[i][j]=='r')
			{
				r++;
			}
			if(arr[i][j]=='n')
			{
				n++;
			}
			if(arr[i][j]=='b')
			{
				b++;
			}
			if(arr[i][j]=='q')
			{
				q++;
			}
			if(arr[i][j]=='p')
			{
				p++;
			}
		}
	}
	for(i=2,w=410,x=369;i>R;i--,x+=50)
		_rook(w,x,8);
	for(i=2,w=410,x=69;i>r;i--,x+=50)
		_rook(w,x,6);
	for(i=2,w=440,x=369;i>N;i--,x+=50)
		_knight(w,x,8);
	for(i=2,w=440,x=69;i>n;i--,x+=50)
		_knight(w,x,6);
	for(i=2,w=470,x=369;i>B;i--,x+=50)
		_bishop(w,x,8);
	for(i=2,w=470,x=69;i>b;i--,x+=50)
		_rook(w,x,6);
	for(i=1,w=500,x=369;i>Q;i--,x+=50)
		_minister(w,x,8);
	for(i=1,w=500,x=69;i>q;i--,x+=50)
		_minister(w,x,6);
	for(i=8,w=410,x=269;i>P;i--,w+=40){
		if(i==4){
			x+=50;w=410;
		}
		_pawn(w,x,8);
	}
	for(i=8,w=410,x=169;i>p;i--,w+=40){
		if(i==4){
			x+=50;w=410;
		}
		_pawn(w,x,6);
	}
}
void _pawn(int i,int j,int color)
{
	setcolor(color);
	setlinestyle(0,0,1);
	setfillstyle(1,color);
	poly[0]=i+42;poly[1]=j+46;poly[2]=i+7;poly[3]=j+46;poly[4]=i+7;poly[5]=j+40;poly[6]=i+18;poly[7]=j+30;poly[8]=i+18;poly[9]=j+21;poly[10]=i+13;poly[11]=j+21;poly[12]=i+13;poly[13]=j+17;poly[14]=i+33;poly[15]=j+17;poly[16]=i+33;poly[17]=j+21;poly[18]=i+29;poly[19]=j+21;poly[20]=i+29;poly[21]=j+30;poly[22]=i+42;poly[23]=j+40;
	fillpoly(12,poly);
	fillellipse(i+23,j+9,7,7);
}
void _king(int i,int j,int color)
{
	i=i-10;j=j-20;
	setcolor(color);
	setlinestyle(0,0,1);
	setfillstyle(1,color);
	poly[0]=i+23;poly[1]=j+67;poly[2]=i+46;poly[3]=j+67;poly[4]=i+46;poly[5]=j+65;poly[6]=i+44;poly[7]=j+64;poly[8]=i+43;poly[9]=j+63;poly[10]=i+42;poly[11]=j+62;poly[12]=i+42;poly[13]=j+60;poly[14]=i+41;poly[15]=j+60;poly[16]=i+41;poly[17]=j+58;poly[18]=i+40;poly[19]=j+58;poly[20]=i+40;poly[21]=j+57;poly[22]=i+39;poly[23]=j+56;poly[24]=i+38;poly[25]=j+54;poly[26]=i+38;poly[27]=j+52;poly[28]=i+37;poly[29]=j+49;poly[30]=i+37;poly[31]=j+47;poly[32]=i+37;poly[33]=j+45;poly[34]=i+37;poly[35]=j+42;poly[36]=i+39;poly[37]=j+42;poly[38]=i+40;poly[39]=j+42;poly[40]=i+41;poly[41]=j+42;poly[42]=i+42;poly[43]=j+41;poly[44]=i+41;poly[45]=j+41;poly[46]=i+39;poly[47]=j+41;poly[48]=i+39;poly[49]=j+40;poly[50]=i+38;poly[51]=j+40;poly[52]=i+38;poly[53]=j+39;poly[54]=i+39;poly[55]=j+38;poly[56]=i+38;poly[57]=j+38;poly[58]=i+39;poly[59]=j+37;poly[60]=i+40;poly[61]=j+36;poly[62]=i+42;poly[63]=j+34;poly[64]=i+42;poly[65]=j+32;poly[66]=i+40;poly[67]=j+32;poly[68]=i+38;poly[69]=j+41;poly[70]=i+37;poly[71]=j+31;poly[72]=i+38;
	poly[73]=j+30;poly[74]=i+37;poly[75]=j+30;poly[76]=i+38;poly[77]=j+30;poly[78]=i+37;poly[79]=j+29;poly[80]=i+37;poly[81]=j+38;poly[82]=i+36;poly[83]=j+28;poly[84]=i+36;poly[85]=j+27;poly[86]=i+38;poly[87]=j+27;poly[88]=i+38;poly[89]=j+25;poly[90]=i+36;poly[91]=j+25;poly[92]=i+36;poly[93]=j+24;poly[94]=i+35;poly[95]=j+23;poly[96]=i+34;poly[97]=j+23;poly[98]=i+33;poly[99]=j+23;poly[100]=i+33;poly[101]=j+24;poly[102]=i+33;poly[103]=j+25;poly[104]=i+30;poly[105]=j+25;poly[106]=i+30;poly[107]=j+27;poly[108]=i+33;poly[109]=j+27;poly[110]=i+33;poly[111]=j+28;poly[112]=i+32;poly[113]=j+28;poly[114]=i+32;poly[115]=j+29;poly[116]=i+31;poly[117]=j+29;poly[118]=i+31;poly[119]=j+30;poly[120]=i+32;poly[121]=j+30;poly[122]=i+32;poly[123]=j+31;poly[124]=i+31;poly[125]=j+31;poly[126]=i+29;poly[127]=j+32;poly[128]=i+27;poly[129]=j+32;poly[130]=i+27;poly[131]=j+33;poly[132]=i+28;poly[133]=j+34;poly[134]=i+29;poly[135]=j+36;poly[136]=i+30;poly[137]=j+37;poly[138]=i+33;poly[139]=j+38;poly[140]=i+29;poly[141]=j+38;
	poly[142]=i+30;poly[143]=j+39;poly[144]=i+30;poly[145]=j+40;poly[146]=i+29;poly[147]=j+41;poly[148]=i+27;poly[149]=j+41;poly[150]=i+37;poly[151]=j+42;poly[152]=i+39;poly[153]=j+42;poly[154]=i+32;poly[155]=j+42;poly[156]=i+32;poly[157]=j+47;poly[158]=i+31;poly[159]=j+50;poly[160]=i+31;poly[161]=j+53;poly[162]=i+30;poly[163]=j+55;poly[164]=i+29;poly[165]=j+57;poly[166]=i+29;poly[167]=j+58;poly[168]=i+28;poly[169]=j+58;poly[170]=i+28;poly[171]=j+60;poly[172]=i+27;poly[173]=j+60;poly[174]=i+27;poly[175]=j+61;poly[176]=i+26;poly[177]=j+62;poly[178]=i+25;poly[179]=j+63;poly[180]=i+25;poly[181]=j+64;poly[182]=i+24;poly[183]=j+64;poly[184]=i+23;poly[185]=j+65;poly[186]=i+23;poly[187]=j+67;
	fillpoly(94,poly);
}

void _minister(int i,int j,int color)
{       i=i-10;j=j-20;
	setcolor(color);
	setlinestyle(0,0,1);
	setfillstyle(1,color);
	poly[0]=i+21;poly[1]=j+66;poly[2]=i+48;poly[3]=j+66;poly[4]=i+48;poly[5]=j+64;poly[6]=i+46;poly[7]=j+63;poly[8]=i+45;poly[9]=j+62;poly[10]=i+44;poly[11]=j+61;poly[12]=i+43;poly[13]=j+61;poly[14]=i+43;poly[15]=j+60;poly[16]=i+42;poly[17]=j+60;poly[18]=i+42;poly[19]=j+57;poly[20]=i+41;poly[21]=j+57;poly[22]=i+41;poly[23]=j+56;poly[24]=i+40;poly[25]=j+56;poly[26]=i+39;poly[27]=j+55;poly[28]=i+39;poly[29]=j+53;poly[30]=i+38;poly[31]=j+52;poly[32]=i+38;poly[33]=j+50;poly[34]=i+38;poly[35]=j+48;poly[36]=i+38;poly[37]=j+45;poly[38]=i+38;poly[39]=j+42;poly[40]=i+39;poly[41]=j+42;poly[42]=i+42;poly[43]=j+41;poly[44]=i+43;poly[45]=j+41;poly[46]=i+42;poly[47]=j+41;poly[48]=i+41;poly[49]=j+40;poly[50]=i+40;poly[51]=j+40;poly[52]=i+39;poly[53]=j+39;poly[54]=i+39;poly[55]=j+38;poly[56]=i+40;poly[57]=j+38;poly[58]=i+39;poly[59]=j+37;poly[60]=i+40;poly[61]=j+37;poly[62]=i+41;poly[63]=j+36;poly[64]=i+40;poly[65]=j+35;poly[66]=i+40;poly[67]=j+34;poly[68]=i+39;poly[69]=j+34;poly[70]=i+40;poly[71]=j+32;poly[72]=i+41;
	poly[73]=j+30;poly[74]=i+43;poly[75]=j+27;poly[76]=i+44;poly[77]=j+26;poly[78]=i+43;poly[79]=j+25;poly[80]=i+42;poly[81]=j+25;poly[82]=i+41;poly[83]=j+26;poly[84]=i+40;poly[85]=j+25;poly[86]=i+39;poly[87]=j+25;poly[88]=i+38;poly[89]=j+26;poly[90]=i+37;poly[91]=j+25;poly[92]=i+36;poly[93]=j+25;poly[94]=i+36;poly[95]=j+24;poly[96]=i+35;poly[97]=j+23;poly[98]=i+34;poly[99]=j+23;poly[100]=i+33;poly[101]=j+24;poly[102]=i+33;poly[103]=j+25;poly[104]=i+32;poly[105]=j+25;poly[106]=i+31;poly[107]=j+25;poly[108]=i+30;poly[109]=j+25;poly[110]=i+29;poly[111]=j+25;poly[112]=i+28;poly[113]=j+25;poly[114]=i+27;poly[115]=j+26;poly[116]=i+26;poly[117]=j+25;poly[118]=i+25;poly[119]=j+25;poly[120]=i+25;poly[121]=j+26;poly[122]=i+26;poly[123]=j+27;poly[124]=i+27;poly[125]=j+29;poly[126]=i+28;poly[127]=j+30;poly[128]=i+29;poly[129]=j+31;poly[130]=i+29;poly[131]=j+32;poly[132]=i+29;poly[133]=j+33;poly[134]=i+29;poly[135]=j+34;poly[136]=i+29;poly[137]=j+35;poly[138]=i+30;poly[139]=j+35;poly[140]=i+29;poly[141]=j+35;
	poly[142]=i+28;poly[143]=j+36;poly[144]=i+29;poly[145]=j+37;poly[146]=i+30;poly[147]=j+37;poly[148]=i+29;poly[149]=j+38;poly[150]=i+30;poly[151]=j+38;poly[152]=i+30;poly[153]=j+39;poly[154]=i+28;poly[155]=j+40;poly[156]=i+27;poly[157]=j+40;poly[158]=i+26;poly[159]=j+41;poly[160]=i+26;poly[161]=j+42;poly[162]=i+31;poly[163]=j+42;poly[164]=i+31;poly[165]=j+45;poly[166]=i+31;poly[167]=j+49;poly[168]=i+30;poly[169]=j+53;poly[170]=i+29;poly[171]=j+55;poly[172]=i+29;poly[173]=j+56;poly[174]=i+28;poly[175]=j+56;poly[176]=i+28;poly[177]=j+57;poly[178]=i+27;poly[179]=j+57;poly[180]=i+27;poly[181]=j+59;poly[182]=i+26;poly[183]=j+60;poly[184]=i+25;poly[185]=j+61;poly[186]=i+24;poly[187]=j+62;poly[188]=i+23;poly[189]=j+63;poly[190]=i+22;poly[191]=j+64;poly[192]=i+21;poly[193]=j+64;poly[194]=i+21;poly[195]=j+66;
	fillpoly(98,poly);
}
void _rook(int i,int j,int color)
{
	setcolor(color);
	setlinestyle(0,0,1);
	setfillstyle(1,color);
	poly[0]=i+12;poly[1]=j+4;poly[2]=i+14;poly[3]=j+13;poly[4]=i+16;poly[5]=j+14;poly[6]=i+17;poly[7]=j+14;poly[8]=i+18;poly[9]=j+15;poly[10]=i+18;poly[11]=j+25;poly[12]=i+17;poly[13]=j+31;poly[14]=i+16;poly[15]=j+33;poly[16]=i+16;poly[17]=j+34;poly[18]=i+15;poly[19]=j+34;poly[20]=i+14;poly[21]=j+37;poly[22]=i+13;poly[23]=j+38;poly[24]=i+13;poly[25]=j+40;poly[26]=i+12;poly[27]=j+42;poly[28]=i+10;poly[29]=j+44;poly[30]=i+10;poly[31]=j+47;poly[32]=i+39;poly[33]=j+47;poly[34]=i+39;poly[35]=j+44;poly[36]=i+37;poly[37]=j+43;poly[38]=i+36;poly[39]=j+41;poly[40]=i+36;poly[41]=j+38;poly[42]=i+35;poly[43]=j+38;poly[44]=i+34;poly[45]=j+37;poly[46]=i+34;poly[47]=j+34;poly[48]=i+33;poly[49]=j+34;poly[50]=i+33;poly[51]=j+33;poly[52]=i+32;poly[53]=j+31;poly[54]=i+31;poly[55]=j+27;poly[56]=i+30;poly[57]=j+18;poly[58]=i+30;poly[59]=j+15;poly[60]=i+32;poly[61]=j+14;poly[62]=i+32;poly[63]=j+13;poly[64]=i+35;poly[65]=j+13;poly[66]=i+36;poly[67]=j+4;poly[68]=i+34;poly[69]=j+4;poly[70]=i+33;poly[71]=j+5;poly[72]=i+32;
	poly[73]=j+6;poly[74]=i+30;poly[75]=j+6;poly[76]=i+29;poly[77]=j+4;poly[78]=i+27;poly[79]=j+4;poly[80]=i+27;poly[81]=j+5;poly[82]=i+26;poly[83]=j+6;poly[84]=i+22;poly[85]=j+6;poly[86]=i+21;poly[87]=j+4;poly[88]=i+19;poly[89]=j+4;poly[90]=i+19;poly[91]=j+6;poly[92]=i+17;poly[93]=j+6;poly[94]=i+16;poly[95]=j+5;poly[96]=i+15;poly[97]=j+4;poly[98]=i+12;poly[99]=j+4;
	fillpoly(50,poly);
}
int _bishop(int i,int j,int color)
{
	i=i-10;j=j-20;
	setcolor(color);
	setlinestyle(0,0,1);
	setfillstyle(1,color);
	poly[0]=i+21;poly[1]=j+67;poly[2]=i+46;poly[3]=j+67;poly[4]=i+46;poly[5]=j+65;poly[6]=i+45;poly[7]=j+64;poly[8]=i+44;poly[9]=j+63;poly[10]=i+43;poly[11]=j+62;poly[12]=i+43;poly[13]=j+62;poly[14]=i+42;poly[15]=j+62;poly[16]=i+41;poly[17]=j+60;poly[18]=i+40;poly[19]=j+59;poly[20]=i+40;poly[21]=j+57;poly[22]=i+39;poly[23]=j+57;poly[24]=i+39;poly[25]=j+56;poly[26]=i+38;poly[27]=j+55;poly[28]=i+37;poly[29]=j+53;poly[30]=i+37;poly[31]=j+52;poly[32]=i+37;poly[33]=j+50;poly[34]=i+37;poly[35]=j+49;poly[36]=i+37;poly[37]=j+48;poly[38]=i+36;poly[39]=j+47;poly[40]=i+36;poly[41]=j+46;poly[42]=i+36;poly[43]=j+44;poly[44]=i+36;poly[45]=j+43;poly[46]=i+38;poly[47]=j+43;poly[48]=i+39;poly[49]=j+43;poly[50]=i+40;poly[51]=j+43;poly[52]=i+40;poly[53]=j+42;poly[54]=i+41;poly[55]=j+42;poly[56]=i+40;poly[57]=j+42;poly[58]=i+39;poly[59]=j+41;poly[60]=i+38;poly[61]=j+41;poly[62]=i+37;poly[63]=j+40;poly[64]=i+38;poly[65]=j+38;poly[66]=i+39;poly[67]=j+38;poly[68]=i+39;poly[69]=j+37;poly[70]=i+40;poly[71]=j+36;
	poly[72]=i+41;poly[73]=j+35;poly[74]=i+41;poly[75]=j+34;poly[76]=i+41;poly[77]=j+33;poly[78]=i+41;poly[79]=j+32;poly[80]=i+40;poly[81]=j+30;poly[82]=i+39;poly[83]=j+29;poly[84]=i+39;poly[85]=j+28;poly[86]=i+38;poly[87]=j+28;poly[88]=i+37;poly[89]=j+28;poly[90]=i+37;poly[91]=j+29;poly[92]=i+37;poly[93]=j+30;poly[94]=i+36;poly[95]=j+31;poly[96]=i+36;poly[97]=j+32;poly[98]=i+36;poly[99]=j+33;poly[100]=i+36;poly[101]=j+34;poly[102]=i+35;poly[103]=j+33;poly[104]=i+35;poly[105]=j+31;poly[106]=i+35;poly[107]=j+26;poly[108]=i+34;poly[109]=j+25;poly[110]=i+35;poly[111]=j+24;poly[112]=i+35;poly[113]=j+23;poly[114]=i+33;poly[115]=j+23;poly[116]=i+32;poly[117]=j+23;poly[118]=i+31;poly[119]=j+24;poly[120]=i+31;poly[121]=j+25;poly[122]=i+32;poly[123]=j+25;poly[124]=i+30;poly[125]=j+26;poly[126]=i+29;poly[127]=j+28;poly[128]=i+27;poly[129]=j+29;poly[130]=i+26;poly[131]=j+31;poly[132]=i+25;poly[133]=j+32;poly[134]=i+25;poly[135]=j+34;poly[136]=i+25;poly[137]=j+35;poly[138]=i+26;poly[139]=j+36;
	poly[140]=i+27;poly[141]=j+37;poly[142]=i+28;poly[143]=j+37;poly[144]=i+28;poly[145]=j+38;poly[146]=i+29;poly[147]=j+38;poly[148]=i+29;poly[149]=j+40;poly[150]=i+28;poly[151]=j+41;poly[152]=i+27;poly[153]=j+41;poly[154]=i+26;poly[155]=j+41;poly[156]=i+26;poly[157]=j+42;poly[158]=i+25;poly[159]=j+42;poly[160]=i+26;poly[161]=j+42;poly[162]=i+27;poly[163]=j+43;poly[164]=i+28;poly[165]=j+43;poly[166]=i+29;poly[167]=j+43;poly[168]=i+30;poly[169]=j+43;poly[170]=i+30;poly[171]=j+47;poly[172]=i+30;poly[173]=j+49;poly[174]=i+30;poly[175]=j+51;poly[176]=i+29;poly[177]=j+53;poly[178]=i+29;poly[179]=j+54;poly[180]=i+28;poly[181]=j+55;poly[182]=i+27;poly[183]=j+56;poly[184]=i+27;poly[185]=j+57;poly[186]=i+26;poly[187]=j+57;poly[188]=i+26;poly[189]=j+60;poly[190]=i+25;poly[191]=j+60;poly[192]=i+25;poly[193]=j+61;poly[194]=i+24;poly[195]=j+62;poly[196]=i+23;poly[197]=j+63;poly[198]=i+22;poly[199]=j+64;poly[200]=i+21;poly[201]=j+64;poly[202]=i+21;poly[203]=j+65;poly[204]=i+21;poly[205]=j+67;
	fillpoly(103,poly);
}
void _knight(int i,int j,int color)
{
	setcolor(color);
	setlinestyle(0,0,1);
	setfillstyle(1,color);
	poly[0]=i+13;poly[1]=j+3;poly[2]=i+13;poly[3]=j+5;poly[4]=i+13;poly[5]=j+6;poly[6]=i+14;poly[7]=j+7;poly[8]=i+15;poly[9]=j+7;poly[10]=i+16;poly[11]=j+8;poly[12]=i+14;poly[13]=j+9;poly[14]=i+13;poly[15]=j+9;poly[16]=i+13;poly[17]=j+10;poly[18]=i+14;poly[19]=j+11;poly[20]=i+12;poly[21]=j+16;poly[22]=i+12;poly[23]=j+19;poly[24]=i+11;poly[25]=j+21;poly[26]=i+13;poly[27]=j+22;poly[28]=i+15;poly[29]=j+21;poly[30]=i+16;poly[31]=j+23;poly[32]=i+17;poly[33]=j+23;poly[34]=i+18;poly[35]=j+22;poly[36]=i+19;poly[37]=j+19;poly[38]=i+20;poly[39]=j+17;poly[40]=i+22;poly[41]=j+16;poly[42]=i+21;poly[43]=j+18;poly[44]=i+19;poly[45]=j+20;poly[46]=i+18;poly[47]=j+23;poly[48]=i+19;poly[49]=j+24;poly[50]=i+16;poly[51]=j+28;poly[52]=i+15;poly[53]=j+32;poly[54]=i+15;poly[55]=j+36;poly[56]=i+16;poly[57]=j+37;poly[58]=i+15;poly[59]=j+38;poly[60]=i+15;poly[61]=j+40;poly[62]=i+14;poly[63]=j+42;poly[64]=i+13;poly[65]=j+43;poly[66]=i+13;poly[67]=j+45;poly[68]=i+36;poly[69]=j+45;poly[70]=i+36;poly[71]=j+43;poly[72]=i+34;
	poly[73]=j+41;poly[74]=i+33;poly[75]=j+40;poly[76]=i+34;poly[77]=j+38;poly[78]=i+33;poly[79]=j+37;poly[80]=i+35;poly[81]=j+36;poly[82]=i+35;poly[83]=j+35;poly[84]=i+31;poly[85]=j+28;poly[86]=i+32;poly[87]=j+24;poly[88]=i+33;poly[89]=j+21;poly[90]=i+34;poly[91]=j+19;poly[92]=i+35;poly[93]=j+16;poly[94]=i+36;poly[95]=j+14;poly[96]=i+36;poly[97]=j+12;poly[98]=i+35;poly[99]=j+10;poly[100]=i+34;poly[101]=j+10;poly[102]=i+20;poly[103]=j+5;poly[104]=i+19;poly[105]=j+6;poly[106]=i+18;poly[107]=j+5;poly[108]=i+13;poly[109]=j+3;
	fillpoly(55,poly);
}
int valid_move(int a,int b,int c,int d)
{
	int i,j;
	/* the switch case checks movement of each item whether valid or not*/
	switch(arr[a][b])
	{
		case 'r':
		case 'R':
			if(a!=c && b!=d)
				return(0);
			return(1);
		case 'b':
		case 'B':
			if(abs(a-c)!=abs(b-d))
				return(0);
			return(1);
		case 'n':
		case 'N':
			if(a==c)
				return(0);
			if(b==d)
				return(0);
			if(abs(a-c)+abs(b-d)!=3)
				return(0);
			return(1);
		case 'q':
		case 'Q':
			if((abs(a-c)!=abs(b-d)) && (a!=c && b!=d))
				return(0);
			return(1);

		case 'k':
		case 'K':
		    if(d==2 && b==4)
		    {
			for(i=a,j=3;arr[i][j]=='-';j--)
			{
				if(j==-1)
				{
					break;
				}
			}
			if(j)
				return(0);
			if(!castle(i,j,a,b,c,d))
				return(0);
			{
				CastleDone_p1=1;
				return(1);
			}
		    }
		     if(d==6 && b==4)
		    {
			for(i=a,j=5;arr[i][j]=='-';j++)
			{
				if(j==8)
				{
					break;
				}
			}
			if(j!=7)
				return(0);
			if(!castle(i,j,a,b,c,d))
				return(0);
			{
				CastleDone_p2=1;
				return(1);
			}
		    }

		     if(abs(a-c)>=2)
			return(0);
		     if(abs(b-d)>=2)
			return(0);
		     if(!check(a,b,c,d))
			return(0);
		    else
			return(1);



		case 'P':
			if(a==6)
			{
				if((a-c)>=3 ||a-c<=0)
					return(0);
				if((abs(b-d)>=2))
					return(0);
				if(a-c==2 && b-d!=0)
					return(0);
				if((b-d!=0) && arr[c][d]=='-')
					return(0);
				return(1);
			}
			else
			{
				if(a-c>=2 ||a-c<=0 )
					return(0);
				if((abs(b-d)>=2))
					return(0);
				if((b-d!=0)&&arr[c][d]=='-')
					return(0);
				return(1);
			}

		case 'p':
			if(a==1)
			{
				if(c-a>=3 || c-a<=0 )
					return(0);
				if((abs(b-d)>=2))
					return(0);
				if(c-a==2 && b-d!=0)
					return(0);
				if((b-d!=0) && arr[c][d]=='-')
					return(0);
				return(1);
			}
			else
			{
				if(c-a>=2 || c-a<=0 )
					return(0);
				if(abs(b-d)>=2)
					return(0);
				if((b-d!=0) && arr[c][d]=='-')
					return(0);
				return(1);
			}

		default:
			return(0);
	}
	//return(0);
}
int valid_path(int a,int b,int c,int d)
{
	int i,j;
	switch(arr[a][b])
	{
		case 'n':
		case 'N':
			return(1);

		case 'r':
		case 'R':
			if(a==c)
			{
				if(b<d)
				{
					for(i=b+1;i<d;i++)
					{
						if(arr[a][i]!='-')
							return(0);
					}
					return(1);
				}
				else
				{
					for(i=b-1;i>d;i--)
					{
						if(arr[a][i]!='-')
							return(0);
					}
					return(1);
				}
			      //return(0);
			}
			else
			{
				if(a<c)
				{
					for(i=a+1;i<c;i++)
					{
						if(arr[i][b]!='-')
							return(0);

					}
					return(1);
				}
				else
				{
					for(i=a-1;i>c;i--)
					{
						if(arr[i][b]!='-')
							return(0);

					}
					return(1);
				}
				//return(0);
			}
			//return(0);

		case 'b':
		case 'B':
			if(((a<c) && (b<d)))
			{
				for(i=a+1,j=b+1;i<c;i++,j++)
				{
					if(arr[i][j]!='-')
						return(0);

				}
				return(1);
			}
			else if((a<c) && (d<b))
			{
				for(i=a+1,j=b-1;i<c;i++,j--)
				{
					if(arr[i][j]!='-')
						return(0);

				}
				return(1);
			}
			else if((a>c) && (b>d))
			{
				for(i=a-1,j=b-1;i>c;i--,j--)
				{
					if(arr[i][j]!='-')
						return(0);

				}
				return(1);
			}
			else if((a>c) && (d>b))
			{
				for(i=a-1,j=b+1;j<d;i--,j++)
				{
					if(arr[i][j]!='-')
						return(0);

				}
				return(1);
			}
			else
				return(0);

		case 'p':
			if(b==d)
				if(arr[c][d]!='-')
					return(0);
			return(1);
		case 'P':
			if(b==d)
				if(arr[c][d]!='-')
					return(0);
			return(1);
		case 'q':
		case 'Q':
			if(a==c)
			{
				if(b<d)
				{
					for(i=b+1;i<d;i++)
					{
						if(arr[a][i]!='-')
							return(0);
					}
					return(1);
				}
				else
				{
					for(i=b-1;i>d;i--)
					{
						if(arr[a][i]!='-')
							return(0);

					}
					return(1);
				}
			}
			else if(b==d)
			{
				if(a<c)
				{
					for(i=a+1,j=b;i<c;i++,j)
					{
						if(arr[i][j]!='-')
							return(0);

					}
					return(1);
				}
				else
				{
					for(i=a-1,j=b;i>c;i--)
					{
						if(arr[i][j]!='-')
							return(0);

					}
					return(1);
				}

			}
			if(((a<c) && (b<d)))
			{
				for(i=a+1,j=b+1;i<c;i++,j++)
				{
					if(arr[i][j]!='-')
						return(0);

				}
				return(1);
			}
			else if((a<c) && (d<b))
			{
				for(i=a+1,j=b-1;i<c;i++,j--)
				{
					if(arr[i][j]!='-')
						return(0);

				}
				return(1);
			}
			else if((a>c) && (b>d))
			{
				for(i=a-1,j=b-1;i>c;i--,j--)
				{
					if(arr[i][j]!='-')
						return(0);

				}
				return(1);
			}
			else if((a>c) && (d>b))
			{
				for(i=a-1,j=b+1;j<d;i--,j++)
				{
					if(arr[i][j]!='-')
						return(0);

				}
				return(1);
			}
			else
				return(0);

		case 'k':
		case 'K':
			return(1);

	}
	 return(0);
}
int valid_position(int a,int b,int c,int d)
{
	if(arr[a][b]>=65 && arr[a][b]<=90)
	{
		if(arr[c][d]>=65 && arr[c][d]<=90)
			return(0);

	}
	else if(arr[a][b]>=97 && arr[a][b]<=122)
	{
		if(arr[c][d]>=97 && arr[c][d]<=122)
			return(0);

	}
	return(1);
}
int check(int a,int b,int c,int d)
{
	int i,j;
	temp[0][1]=arr[c][d];
	arr[c][d]=arr[a][b];
	temp[0][0]=arr[a][b];
	arr[a][b]='-';
	/* at some exceptions */
	arr[c][d]=temp[0][0];
	/* in kings checking 1st one*/
	for(i=c-1,j=d;arr[i][j]=='-';i--)
		if(i==0)
			break;
		if(!icheck(i,j,c,d,a,b))
			return(0);
	for(i=c-1,j=d+1;arr[i][j]=='-';i--,j++)
		if(j==7||i==0)
			break;
		if(!icheck(i,j,c,d,a,b))
			return(0);
	for(i=c,j=d+1;arr[i][j]=='-';j++)
		if(j==7)
			break;
		if(!icheck(i,j,c,d,a,b))
			return(0);
	for(i=c+1,j=d+1;arr[i][j]=='-';i++,j++)
		if(i==7||j==7)
			break;
		if(!icheck(i,j,c,d,a,b))
			return(0);
	for(i=c+1,j=d;arr[i][j]=='-';i++)
		if(i==7)
			break;
		if(!icheck(i,j,c,d,a,b))
			return(0);
	for(i=c+1,j=d-1;arr[i][j]=='-';i++,j--)
		if(i==7||j==0)
			break;
		if(!icheck(i,j,c,d,a,b))
			return(0);
	for(i=c,j=d-1;arr[i][j]=='-';j--)
		if(j==0)
			break;
		if(!icheck(i,j,c,d,a,b))
			return(0);

	for(i=c-1,j=d-1;arr[i][j]=='-';i--,j--)
		if(i==0||j==0)
			break;
		if(!icheck(i,j,c,d,a,b))
			return(0);
	if(!knightin(c,d))
	{
		arr[a][b]=temp[0][0];
		arr[c][d]=temp[0][1];
		return(0);
	}
	arr[a][b]=temp[0][0];
	arr[c][d]=temp[0][1];
	return(1);
}
int icheck(int i,int j,int c,int d,int a,int b)
{
	if(arr[i][j]!='-')
	{
		if(!valid_position(i,j,c,d))
			return(1);
		if((valid_move(i,j,c,d))&&(valid_path(i,j,c,d)))
		{
			arr[c][d]=temp[0][1];
			arr[a][b]=temp[0][0];
			return(0);
		}
		return(1);
	}
	return(1);
}
int knightin(int c,int d)
{
	if(temp[0][0]>=65 && temp[0][0]<=90)
	{
		if(arr[c+1][d+2]=='n')
			return(0);
		if(arr[c+2][d+1]=='n')
			return(0);
		if(arr[c+2][d-1]=='n')
			return(0);
		if(arr[c+1][d-2]=='n')
			return(0);
		if(arr[c-1][d-2]=='n')
			return(0);
		if(arr[c-2][d-1]=='n')
			return(0);
		if(arr[c-2][d+1]=='n')
			return(0);
		if(arr[c-1][d+2]=='n')
			return(0);
		return(1);
	}
	else
	{
		if(arr[c+1][d+2]=='N')
			return(0);
		if(arr[c+2][d+1]=='N')
			return(0);
		if(arr[c+2][d-1]=='N')
			return(0);
		if(arr[c+1][d-2]=='N')
			return(0);
		if(arr[c-1][d-2]=='N')
			return(0);
		if(arr[c-2][d-1]=='N')
			return(0);
		if(arr[c-2][d+1]=='N')
			return(0);
		if(arr[c-1][d+2]=='N')
			return(0);
		return(1);
	}

}
void showmouse()
{
	in.x.ax=1;
	int86(0X33,&in,&out);


}



void play_IQ()
{
	/*there are so many levels
	  so we want actually to draw the each
	  level and get user's answer and check */
	IQ_START();
	  //IQ_OPTIONS();
	  //IQ_STASTICS();
	  //IQ_LAST();

	  IQ_LVL1();

	  //IQ_LVL2();
	  //IQ_LVL3();
	  //IQ_LVL4();
	  //IQ_LVL5();



}
IQ_START()
{
	int i,w,z,poly[10]={310,16,580,16,580,394,310,394};
	cleardevice();
	//in.x.ax=2;
	//int86(0x33,&in,&out);
	setbkcolor(15);
	setfillstyle(1,7);
	setcolor(8);
	setlinestyle(0,0,1);
	bar3d(170,10,470,430,5,1);
	//for
	//fillpoly(4,poly);

	setfillstyle(1,8);
		setlinestyle(0,1,3);
	arc(230,428,0,180,40);
	circle(308,373,55);

	circle(308,373,3);
	circle(345,375,3);
	//setlinestyle(0,1,1);
	line(320,392,330,392);
	line(330,392,325,382);
	line(325,382,320,392);
	//line(302,415,342,415);
	arc(324,402,180,360,10);
	arc(274,370,70,240,5);

	//poly[0]=500;poly[1]=130;poly[2]=580;poly[3]=110;poly[4]=580;poly[5]=194;poly[6]=530;poly[7]=194;
	//fillpoly(4,poly);
	//setlinestyle(0,0,1);
	//poly[0]=580;poly[1]=100;poly[2]=580;poly[3]=194;poly[4]=520;poly[5]=194;poly[6]=527;poly[7]=192;poly[8]=577;poly[9]=112;
	//setfillstyle(1,7);
	//fillpoly(5,poly);

	/*protracter*/
	setlinestyle(0,0,1);
	setfillstyle(1,6);
	poly[0]=310;poly[1]=16;poly[2]=470;poly[3]=52;poly[4]=470;poly[5]=60;poly[6]=310;poly[7]=60;
	fillpoly(4,poly);
	poly[0]=320;poly[1]=30;poly[2]=450;poly[3]=51;poly[4]=320;poly[5]=51;
	setfillstyle(1,7);
	fillpoly(3,poly);

	settextstyle(0,1,0);
	for(i=320;i<470;i+=5)
	outtextxy(i,53,"-");
	setcolor(4);
	outtextxy(280,65,"CODE x");
	outtextxy(230,80,"C");
	outtextxy(240,80,"H");
	outtextxy(250,80,"A");
	outtextxy(260,80,"L");
	outtextxy(270,80,"L");
	outtextxy(290,80,"N");
	outtextxy(300,80,"G");
	outtextxy(310,80,"E");
	settextstyle(0,0,0);
	setcolor(8);
	outtextxy(310,20,"-");
	outtextxy(310,25,"-");
	outtextxy(310,30,"-");
	outtextxy(310,35,"-");
	outtextxy(310,40,"-");
	outtextxy(310,45,"-");
	outtextxy(310,50,"-");

	//outtextxy(270,185,"2");

	/* chemistry*/
	setcolor(8);
	outtextxy(213,23,"H");
	outtextxy(220,27,"2");
	outtextxy(227,23,"O");
	line(213,50,215,43);
	line(217,41,224,38);
	line(226,39,233,43);
	line(233,45,233,54);
	line(231,54,222,54);
	line(220,53,215,51);
	line(218,44,218,48);
	line(225,41,230,45);
	line(229,52,224,52);

	line(234,43,245,41);
	line(245,41,244,35);
	line(248,35,247,41);
	outtextxy(243,27,"o");
	line(247,41,256,43);
	outtextxy(259,40,"o");
	line(268,42,275,38);
	outtextxy(280,38,"CH");
	outtextxy(295,42,"3");

	/*arithmatic*/
	settextstyle(1,0,0);
	outtextxy(240,110,"+");
	settextstyle(0,0,0);
	outtextxy(238,123,"-");
	outtextxy(252,122,"%");
	outtextxy(239,135,"/");
	outtextxy(253,135,"*");

	/*play button*/
	setcolor(WHITE);
	setlinestyle(2,0,1);
	setfillstyle(1,8);
	setcolor(8);
	line(250,180,330,175);
	line(250,200,330,195);
	line(255,173,252,207);
	line(325,168,322,200);
	settextstyle(0,0,1);
	outtextxy(270,185,"PLAY");
	setcolor(8);
	settextstyle(2,0,5);
	outtextxy(265,350,"$WUDUC&@&GC77gw");
	outtextxy(260,304,"tan30/a+b:65");
	outtextxy(260,400,"x=b^2-4ac/2a");
	settextstyle(2,1,3);
	outtextxy(380,300,"cos(x)-sec(u)");
	settextstyle(2,1,3);
	for(i=170,w=305;i<470;i+=10)
	outtextxy(i,w,"(d-h/7)*(a+b)(a-b)=a^2 -b^2");
	setlinestyle(0,1,1);
	circle(320,390,10);
	circle(270,400,5);
	line(270,395,310,185);
	setlinestyle(1,1,1);
	line(320,390,270,200);

	for( z=1;z<800;z++)
			putpixel((random(434)+53),(random(438)+3),15);

	in.x.ax=1;
	int86(0x33,&in,&out);

	//getch();exit(0);
	while(1)
	{
		in.x.ax=3;
		int86(0x33,&in,&out);
		if(out.x.bx==1)
		{
			//in.x.ax=3;
			//int86(0x33,&in,&out);
			if(out.x.cx>=250&&out.x.cx<=330&&out.x.dx>180&&out.x.dx<=200)
				break;
		}
	}
	in.x.ax=2;
	  int86(0x33,&in,&out);
	  cleardevice();
       setcolor(BLACK);
       setlinestyle(0,0,1);

}
//IQ_OPTIONS(){}
int IQ_STASTICS(int lvlans,int no)
{
	       int L1=4,L2=13,L3=2,L4=9,L5=7,L6=42,L7=8,L8,L9,L10,L11,L12,L13,L14,L15,L16,j,answer;

		for(j=1;j<16;j++)
		{
			setcolor(j);
			switch(no)
			{
				case 1 :
					if(lvlans!=4){answer=0;
						outtextxy(230,400,"WRONG");}
					else{   answer=1;
						outtextxy(230,400,"CONGRATS");}
					break;

				case 2 :
					if(lvlans!=13){answer=0;
						outtextxy(230,400,"WRONG");}
					else{answer=1;
						outtextxy(230,400,"CONGRATS");}
					break;
				case 3 :
					if(lvlans!=2){answer=0;
						outtextxy(230,400,"WRONG");}
					else{answer=1;
						outtextxy(230,400,"CONGRATS");}
					break;
				case 4 :
					if(lvlans!=9){answer=0;
						outtextxy(230,400,"WRONG");}
					else{answer=1;
						outtextxy(230,400,"CONGRATS");}
					break;
				case 5 :
					if(lvlans!=7){answer=0;
						outtextxy(230,400,"WRONG");}
					else{answer=1;
						outtextxy(230,400,"CONGRATS");}
					break;
				case 6 :
					if(lvlans!=42){answer=0;
						outtextxy(230,400,"WRONG");}
					else{answer=1;
						outtextxy(230,400,"CONGRATS");}
					break;
				case 7 :
					if(lvlans!=8){answer=0;
						outtextxy(230,400,"WRONG");}
					else{answer=1;
						outtextxy(230,400,"CONGRATS");}
					break;
				case 8 :
					if(lvlans!=2){answer=0;
						outtextxy(230,400,"WRONG");}
					else{answer=1;
						outtextxy(230,400,"CONGRATS");}
					break;
				case 9 :
					if(lvlans!=44){answer=0;
						outtextxy(230,400,"WRONG");}
					else{answer=1;
						outtextxy(230,400,"CONGRATS");}
					break;
				case 10 :
					if(lvlans!=3){answer=0;
						outtextxy(230,400,"WRONG");}
					else{answer=1;
						outtextxy(230,400,"CONGRATS");}
					break;
				case 11 :
					if(lvlans!=82){answer=0;
						outtextxy(230,400,"WRONG");}
					else{answer=1;
						outtextxy(230,400,"CONGRATS");}
					break;
				case 12 :
					if(lvlans!=7){answer=0;
						outtextxy(230,400,"WRONG");}
					else{answer=1;
						outtextxy(230,400,"CONGRATS");}
					break;
				case 13 :
					if(lvlans!=27){answer=0;
						outtextxy(230,400,"WRONG");}
					else{answer=1;
						outtextxy(230,400,"CONGRATS");}
					break;
				case 14 :
					if(lvlans!=50){answer=0;
						outtextxy(230,400,"WRONG");}
					else{answer=1;
						outtextxy(230,400,"CONGRATS");}
					break;
				case 15 :
					if(lvlans!=2){answer=0;
						outtextxy(230,400,"WRONG");}
					else{answer=1;
						outtextxy(230,400,"CONGRATS");}
					break;
				case 16 :
					if(lvlans!=74){answer=0;
						outtextxy(230,400,"WRONG");}
					else{answer=1;
						outtextxy(230,400,"CONGRATS");}
					break;

			}
			delay(100);

		}
      in.x.ax=2;
      int86(0x33,&in,&out);
      setcolor(16);
      setlinestyle(0,0,1);
      setfillstyle(1,8);
      poly[0]=400;poly[1]=330;poly[2]=440;poly[3]=330;poly[4]=440;poly[5]=360;poly[6]=400;poly[7]=360;
      fillpoly(4,poly);
      setcolor(15);
      settextstyle(2,0,5);
      if(answer)
	outtextxy(410,340,"GO");
      else
	outtextxy(410,340,"XIT");
      in.x.ax=1;
      int86(0x33,&in,&out);
      while(1)
      {
		in.x.ax=3;
		int86(0x33,&in,&out);
		if(out.x.bx==1)
		{
			//in.x.ax=3;
			//int86(0x33,&in,&out);
			if(out.x.cx>=400&&out.x.cx<=440&&out.x.dx>330&&out.x.dx<=360)
				break;
		}
      }
      in.x.ax=2;
      int86(0x33,&in,&out);

      if(answer)
	return(1);
      else
	return(0);

}
//IQ_LAST(){}

void IQ_LVL1()
{
	int i,j,w,x,y,z,answer;
	char a,b;
	int poly[20]={266,120,259,114,259,112,272,119,272,121,259,128,257,126,266,121};
	/*quiz no.1*/
	setbkcolor(0);
	setcolor(7);

	for(i=0,w=170,x=3,y=470,z=3;i<440;i++,x++,z++)
	line(w,x,y,z);
	/*drawing the board*/
	setcolor(8);
	setlinestyle(0,0,3);
	rectangle(250,100,390,230);
	rectangle(253,103,387,227);
	setfillstyle(1,2);
	setcolor(10);
	bar3d(253,103,387,227,0,0);
	setcolor(WHITE);
	settextstyle(0,0,0);
	outtextxy(240,85,"this is a Riddle");
	/*drawing the arrow*/
	arc(260,103,168,290,17);
	arc(260,103,168,280,16);
	setfillstyle(1,15);
	setcolor(15);
	fillpoly(8,poly);

	/*2 + 2 = ?*/
	settextstyle(2,0,6);
	outtextxy(280,110,"2 + 2 = ?");    /* to increse the thickness of 2*/
	outtextxy(281,109,"2 + 2 = ?");
	outtextxy(282,108,"2 + 2 = ?");
	/* txt solution*/
	settextstyle(5,0,1);
	outtextxy(290,130,"Solution");
	settextstyle(2,0,0);
	outtextxy(257,155,"1.Put       on cryptex");
	outtextxy(286,155,"answer");
	outtextxy(287,155,"answer");

	outtextxy(257,210,"2.Next");
	outtextxy(293,210,"click");
	outtextxy(294,210,"click");
	in.x.ax=1;
	int86(0x33,&in,&out);
	setcolor(16);
	setfillstyle(1,16);
	poly[0]=260;poly[1]=360;poly[2]=360;poly[3]=360;poly[4]=360;poly[5]=390;poly[6]=260;poly[7]=390;
	fillpoly(4,poly);
	gotoxy(35,24);
		scanf("%d",&answer);
	if(!IQ_STASTICS(answer,1))
		return(0);
		//exit(0);
	/* quiz no.2*/

	setcolor(7);
	for(i=0,w=170,x=3,y=470,z=3;i<440;i++,x++,z++)
	line(w,x,y,z);
	/*rectangular boxes*/
	setcolor(6);
	setlinestyle(0,0,3);
	rectangle(248,148,302,202);line(248,175,302,175);line(275,148,275,202);
	rectangle(318,148,372,202);line(318,175,372,175);line(345,148,345,202);
	rectangle(278,218,332,272);line(278,245,332,245);line(305,218,305,272);
	/*no inside*/
	setcolor(16);
	settextstyle(7,0,0);

	outtextxy(253,141,"2");
	outtextxy(280,141,"4");
	outtextxy(253,168,"6");
	outtextxy(280,168,"8");

	outtextxy(323,141,"1");
	outtextxy(350,141,"3");
	outtextxy(323,168,"5");
	outtextxy(350,168,"7");

	outtextxy(283,211,"7");
	outtextxy(310,211,"9");
	outtextxy(278,238,"1");
	outtextxy(288,238,"1");
	setcolor(4);
	outtextxy(310,238,"?");
	in.x.ax=1;
	int86(0x33,&in,&out);
	setcolor(16);
	setfillstyle(1,16);
	poly[0]=260;poly[1]=360;poly[2]=360;poly[3]=360;poly[4]=360;poly[5]=390;poly[6]=260;poly[7]=390;
	fillpoly(4,poly);
	gotoxy(35,24);
		scanf("%d",&answer);
	if(!IQ_STASTICS(answer,2))
		return(0);



	/* quiz no.3*/

	setcolor(7);
	for(i=0,w=170,x=3,y=470,z=3;i<440;i++,x++,z++)
	line(w,x,y,z);


	setcolor(15);
	setlinestyle(0,0,3);
	rectangle(250,100,390,230);
	rectangle(253,103,387,227);
	setfillstyle(1,8);
	setcolor(10);
	bar3d(253,103,387,227,0,0);
	setcolor(WHITE);

	settextstyle(5,0,4);
	outtextxy(285,135,"H O");
	outtextxy(286,135,"H O");
	outtextxy(287,135,"H O");
	settextstyle(8,0,4);
	outtextxy(311,155,"?");
	outtextxy(312,155,"?");
	outtextxy(313,155,"?");
	in.x.ax=1;
	int86(0x33,&in,&out);
	setcolor(16);
	setfillstyle(1,16);
	poly[0]=260;poly[1]=360;poly[2]=360;poly[3]=360;poly[4]=360;poly[5]=390;poly[6]=260;poly[7]=390;
	fillpoly(4,poly);
	gotoxy(35,24);
		scanf("%d",&answer);
	if(!IQ_STASTICS(answer,3))
		return(0);

	/*quiz no.4*/

	setcolor(7);
	for(i=0,w=170,x=3,y=470,z=3;i<440;i++,x++,z++)
	line(w,x,y,z);

	/*lines in that*/
	setcolor(8);
	setlinestyle(0,0,1);
	line(250,130,250,230);
	line(271,158,271,242);
	line(288,176,288,250);
	line(308,150,308,235);
	line(322,196,322,245);
	line(340,175,340,235);
	line(358,198,358,240);
	line(376,158,376,235);
	line(360,160,384,160);
	line(360,146,360,135);
	line(362,136,293,136);
	line(247,232,273,232);
	line(285,232,310,232);
	line(320,232,344,232);
	line(356,232,379,232);
	line(247,214,273,214);
	line(285,214,310,214);
	line(320,214,344,214);
	line(356,214,379,214);
	line(247,196,273,196);
	line(285,196,310,196);
	line(322,196,347,196);
	line(247,178,273,178);
	line(285,178,328,178);
	line(247,160,298,160);
	//writing no
	settextstyle(0,0,0);
	setcolor(16);
	outtextxy(257,165,"1");
	outtextxy(257,183,"2");
	outtextxy(257,201,"2");
	outtextxy(257,219,"1");
	outtextxy(295,183,"2");
	outtextxy(295,201,"4");
	outtextxy(295,219,"1");
	outtextxy(329,201,"3");
	outtextxy(329,219,"5");
	outtextxy(366,219,"?");
	in.x.ax=1;
	int86(0x33,&in,&out);

	setcolor(16);
	setfillstyle(1,16);
	poly[0]=260;poly[1]=360;poly[2]=360;poly[3]=360;poly[4]=360;poly[5]=390;poly[6]=260;poly[7]=390;
	fillpoly(4,poly);
	gotoxy(35,24);
		scanf("%d",&answer);
	if(!IQ_STASTICS(answer,4))
		return(0);

	/*iq no5*/
	setcolor(7);
	for(i=0,w=170,x=3,y=470,z=3;i<440;i++,x++,z++)
	line(w,x,y,z);
	setfillstyle(12,15);
	//bar3d(253,103,387,227,0,0);
	setcolor(6);
	for( z=1;z<800;z++)
			putpixel((random(151)+253),(random(141)+103),z);
	settextstyle(2,0,0);
	poly[0]=258;poly[1]=111;poly[2]=323;poly[3]=105;poly[4]=290;poly[5]=168;poly[6]=258;poly[7]=111;
	drawpoly(4,poly);
	arc(258,111,300,5,10);arc(323,105,190,245,10);arc(290,168,55,115,10);

	setcolor(8);
	outtextxy(268,111,"4");outtextxy(308,107,"7");outtextxy(285,145,"28");

	setcolor(6);
	poly[0]=270;poly[1]=180;poly[2]=335;poly[3]=174;poly[4]=310;poly[5]=237;poly[6]=270;poly[7]=180;
	drawpoly(4,poly);
	arc(270,180,300,5,10);arc(335,174,190,245,10);arc(310,237,55,115,10);

	setcolor(4);settextstyle(0,0,0);
	outtextxy(283,185,"?");
	setcolor(8);settextstyle(2,0,0);
	outtextxy(320,176,"8");outtextxy(302,215,"56");

	setcolor(6);
	poly[0]=328;poly[1]=115;poly[2]=393;poly[3]=120;poly[4]=360;poly[5]=180;poly[6]=328;poly[7]=115;
	drawpoly(4,poly);
	arc(328,115,300,0,10);arc(393,120,180,235,10);arc(360,180,55,115,10);

	setcolor(8);
	outtextxy(337,117,"9");outtextxy(377,121,"6");outtextxy(355,156,"54");
	in.x.ax=1;
	int86(0x33,&in,&out);
	setcolor(16);
	setfillstyle(1,16);
	poly[0]=260;poly[1]=360;poly[2]=360;poly[3]=360;poly[4]=360;poly[5]=390;poly[6]=260;poly[7]=390;
	fillpoly(4,poly);
	gotoxy(35,24);
		scanf("%d",&answer);
	if(!IQ_STASTICS(answer,5))
		return(0);
	//getch();

	/*iq no6*/

	setcolor(7);
	for(i=0,w=170,x=3,y=470,z=3;i<440;i++,x++,z++)
	line(w,x,y,z);

	setcolor(8);
	setlinestyle(0,0,3);
	rectangle(250,100,390,230);
	rectangle(253,103,387,227);
	setfillstyle(1,2);
	setcolor(2);
	bar3d(253,103,387,227,0,0);
	setcolor(WHITE);
	setlinestyle(0,0,1);
	line(320,110,320,220);
	line(260,165,380,165);

	setcolor(4);
	rectangle(265,115,305,150);
	rectangle(335,115,375,150);
	rectangle(265,180,305,215);
	rectangle(335,180,375,215);

	setcolor(15);
	settextstyle(2,0,0);
	outtextxy(254,104,"12");
	outtextxy(306,105,"4");
	outtextxy(254,150,"15");
	outtextxy(306,151,"5");
	settextstyle(4,0,0);
	outtextxy(266,110,"60");

	settextstyle(2,0,0);
	outtextxy(258,171,"4");
	outtextxy(309,171,"7");
	outtextxy(258,214,"8");
	outtextxy(306,214,"14");
	settextstyle(4,0,0);
	outtextxy(266,176,"56");

	settextstyle(2,0,0);
	outtextxy(325,169,"14");
	outtextxy(378,169,"7");
	outtextxy(327,214,"6");
	outtextxy(378,214,"3");
	settextstyle(4,0,0);
	outtextxy(350,176,"?");

	settextstyle(2,0,0);
	outtextxy(329,104,"7");
	outtextxy(377,105,"14");
	outtextxy(329,150,"2");
	outtextxy(377,151,"4");
	settextstyle(4,0,0);
	outtextxy(337,110,"28");
	in.x.ax=1;
	int86(0x33,&in,&out);
	setcolor(16);
	setfillstyle(1,16);
	poly[0]=260;poly[1]=360;poly[2]=360;poly[3]=360;poly[4]=360;poly[5]=390;poly[6]=260;poly[7]=390;
	fillpoly(4,poly);
	gotoxy(35,24);
		scanf("%d",&answer);
	if(!IQ_STASTICS(answer,6))
		return(0);
	//getch();

	/*no 7*/

	setcolor(7);
	for(i=0,w=170,x=3,y=470,z=3;i<440;i++,x++,z++)
	line(w,x,y,z);

	setcolor(6);
	setlinestyle(0,0,3);
	rectangle(250,100,390,230);
	rectangle(253,103,387,227);
	setfillstyle(1,8);
	setcolor(8);
	bar3d(253,103,387,227,0,0);

	setcolor(7);
	settextstyle(2,0,5);
	outtextxy(265,150,"$WUDUC&@&GC77gw");
	outtextxy(260,104,"tan30/a+b:65");
	outtextxy(260,200,"x=b^2-4ac/2a");
	settextstyle(2,1,3);
	outtextxy(380,100,"cos(x)-sec(u)");
	settextstyle(2,1,3);
	for(i=250,w=105;i<390;i+=10)
	outtextxy(i,w,"(d-h/7)*(a+b)(a-b)=a^2 -b^2");
	setlinestyle(0,1,1);
	circle(320,190,10);
	circle(270,200,5);
	line(270,195,310,185);
	setlinestyle(1,1,1);
	line(320,190,270,200);

	for( z=1;z<800;z++)
			putpixel((random(134)+253),(random(128)+103),15);

	setcolor(1);
	settextstyle(5,0,1);
	for(i=252;i<=255;i++)
		outtextxy(i,150,"2+2+2+2*2/2");


	settextstyle(0,0,2);
	outtextxy(330,190,"= ?");
	in.x.ax=1;
	int86(0x33,&in,&out);
	setcolor(16);
	setfillstyle(1,16);
	poly[0]=260;poly[1]=360;poly[2]=360;poly[3]=360;poly[4]=360;poly[5]=390;poly[6]=260;poly[7]=390;
	fillpoly(4,poly);
	gotoxy(35,24);
		scanf("%d",&answer);
	if(!IQ_STASTICS(answer,7))
		return(0);
	//getch();
	/*IQ_no 8*/
	poly[0]= 170;
	poly[1]= 3  ;
	poly[2]= 470;
	poly[3]= 3  ;
	poly[4]= 470;
	poly[5]= 439;
	poly[6]= 170;
	poly[7]= 439;

	setfillstyle(9,6);
	setcolor(BLUE);
	fillpoly(4,poly);

	setcolor(BLUE);
	for(i=1;i<=5;i++)
	rectangle(230-i,120-i,400+i,260+i);

	poly[0]= 230;
	poly[1]= 120;
	poly[2]= 400;
	poly[3]= 120;
	poly[4]= 400;
	poly[5]= 260;
	poly[6]= 230;
	poly[7]= 260;
	setfillstyle(10,3);
	fillpoly(4,poly);
	setcolor(15);
	settextstyle(1,0,3);
	outtextxy(250,120,"P+P+O=14");
	outtextxy(250,145,"N+N+M=20");
	outtextxy(250,175,"O+M+P=12");
	outtextxy(250,205,"P+M+N=18");
	outtextxy(250,230,"  O=? ");
	in.x.ax=1;
	int86(0x33,&in,&out);
	setcolor(16);
	setfillstyle(1,16);
	poly[0]=260;poly[1]=360;poly[2]=360;poly[3]=360;poly[4]=360;poly[5]=390;poly[6]=260;poly[7]=390;
	fillpoly(4,poly);
	gotoxy(35,24);
		scanf("%d",&answer);
	if(!IQ_STASTICS(answer,8))
		return(0);
	/*IQNO 9*/
	poly[0]= 170;
	poly[1]= 3  ;
	poly[2]= 470;
	poly[3]= 3  ;
	poly[4]= 470;
	poly[5]= 439;
	poly[6]= 170;
	poly[7]= 439;

	setfillstyle(9,6);
	setcolor(6);
	fillpoly(4,poly);

	poly[0]= 215;
	poly[1]= 120;
	poly[2]= 420;
	poly[3]= 120;
	poly[4]= 420;
	poly[5]= 270;
	poly[6]= 215;
	poly[7]= 270;

	setfillstyle(11,9);
	fillpoly(4,poly);

	setcolor(15);
	settextstyle(7,0,1);
	outtextxy(225,180,"1,1,2,4,7,13,24,?");

	in.x.ax=1;
	int86(0x33,&in,&out);
	setcolor(16);
	setfillstyle(1,16);
	poly[0]=260;poly[1]=360;poly[2]=360;poly[3]=360;poly[4]=360;poly[5]=390;poly[6]=260;poly[7]=390;
	fillpoly(4,poly);
	gotoxy(35,24);
		scanf("%d",&answer);
	if(!IQ_STASTICS(answer,9))
		return(0);
	/*IQ 10*/
	poly[0]= 170;
	poly[1]= 3  ;
	poly[2]= 470;
	poly[3]= 3  ;
	poly[4]= 470;
	poly[5]= 439;
	poly[6]= 170;
	poly[7]= 439;

	setfillstyle(9,6);
	setcolor(6);
	fillpoly(4,poly);

	setcolor(4);
	for(i=1;i<=5;i++)
	rectangle(230-i,120-i,400+i,260+i);

	poly[0]= 230;
	poly[1]= 120;
	poly[2]= 400;
	poly[3]= 120;
	poly[4]= 400;
	poly[5]= 260;
	poly[6]= 230;
	poly[7]= 260;
	setfillstyle(10,9);
	fillpoly(4,poly);
	setcolor(15);
	settextstyle(1,0,3);
	outtextxy(250,125,"OKAY=8");
	outtextxy(300,155,"ALSO=?");
	outtextxy(250,185,"BORN=2");
	outtextxy(300,220,"FIVE=10");
	in.x.ax=1;
	int86(0x33,&in,&out);
	setcolor(16);
	setfillstyle(1,16);
	poly[0]=260;poly[1]=360;poly[2]=360;poly[3]=360;poly[4]=360;poly[5]=390;poly[6]=260;poly[7]=390;
	fillpoly(4,poly);
	gotoxy(35,24);
		scanf("%d",&answer);
	if(!IQ_STASTICS(answer,10))
		return(0);
	/*IQ 11*/
	poly[0]= 170;
	poly[1]= 3  ;
	poly[2]= 470;
	poly[3]= 3  ;
	poly[4]= 470;
	poly[5]= 439;
	poly[6]= 170;
	poly[7]= 439;

	setfillstyle(9,6);
	setcolor(6);
	fillpoly(4,poly);

	setcolor(4);
	for(i=1;i<=5;i++)
	rectangle(230-i,120-i,400+i,260+i);

	poly[0]= 230;
	poly[1]= 120;
	poly[2]= 400;
	poly[3]= 120;
	poly[4]= 400;
	poly[5]= 260;
	poly[6]= 230;
	poly[7]= 260;
	setfillstyle(10,0);
	fillpoly(4,poly);
	setcolor(15);
	settextstyle(1,0,3);

	outtextxy(300,120,"AF");
	outtextxy(300,143,"BE");
	outtextxy(300,165,"CF");
	outtextxy(300,185,"DI");
	outtextxy(300,206,"FD");
	outtextxy(300,230,"??");
       in.x.ax=1;
	int86(0x33,&in,&out);
	setcolor(16);
	setfillstyle(1,16);
	poly[0]=260;poly[1]=360;poly[2]=360;poly[3]=360;poly[4]=360;poly[5]=390;poly[6]=260;poly[7]=390;
	fillpoly(4,poly);
	gotoxy(35,24);
		scanf("%c%c",&a,&b);
	answer=a+b;
	if(!IQ_STASTICS(answer,11))
		return(0);
	/*IQ 12*/
	poly[0]= 170;
	poly[1]= 3  ;
	poly[2]= 470;
	poly[3]= 3  ;
	poly[4]= 470;
	poly[5]= 439;
	poly[6]= 170;
	poly[7]= 439;

	setfillstyle(9,6);
	setcolor(6);
	fillpoly(4,poly);

	setcolor(15);
	circle(330,180,85);
	line(230,120,330,300);
	line(230,120,430,120);
	line(430,120,330,300);

	settextstyle(1,0,3);
	outtextxy(310,170,"271");
	outtextxy(325,93,"9");
	outtextxy(260,200,"8");
	outtextxy(325,265,"?");
	outtextxy(240,115,"4");
	outtextxy(385,200,"4");
	outtextxy(405,115,"6");
	in.x.ax=1;
	int86(0x33,&in,&out);
	setcolor(16);
	setfillstyle(1,16);
	poly[0]=260;poly[1]=360;poly[2]=360;poly[3]=360;poly[4]=360;poly[5]=390;poly[6]=260;poly[7]=390;
	fillpoly(4,poly);
	gotoxy(35,24);
		flushall();
		scanf("%d",&answer);
	//answer=a+b;
	if(!IQ_STASTICS(answer,12))
		return(0);
	/*IQ 13*/
	poly[0]= 170;
	poly[1]= 3  ;
	poly[2]= 470;
	poly[3]= 3  ;
	poly[4]= 470;
	poly[5]= 439;
	poly[6]= 170;
	poly[7]= 439;
	setfillstyle(9,6);
	setcolor(6);
	fillpoly(4,poly);
	setfillstyle(1,6);
	setcolor(6);

	poly[0]= 210;
	poly[1]= 150;
	poly[2]= 310;
	poly[3]= 150;
	poly[4]= 310;
	poly[5]= 200;
	poly[6]= 210;
	poly[7]= 200;
	fillpoly(4,poly);
	poly[0]= 330;
	poly[1]= 150;
	poly[2]= 430;
	poly[3]= 150;
	poly[4]= 430;
	poly[5]= 200;
	poly[6]= 330;
	poly[7]= 200;
	fillpoly(4,poly);
	poly[0]= 330 ;
	poly[1]= 220;
	poly[2]= 430;
	poly[3]= 220;
	poly[4]= 430;
	poly[5]= 270;
	poly[6]= 330;
	poly[7]= 270;
	fillpoly(4,poly);
	poly[0]= 210;
	poly[1]= 220;
	poly[2]= 310;
	poly[3]= 220;
	poly[4]= 310;
	poly[5]= 270;
	poly[6]= 210;
	poly[7]= 270;
	fillpoly(4,poly);
	poly[0]= 270;
	poly[1]= 175;
	poly[2]= 370;
	poly[3]= 175;
	poly[4]= 370;
	poly[5]= 245;
	poly[6]= 270;
	poly[7]= 245;
	setfillstyle(1,8);
	setcolor(6);
	fillpoly(4,poly);
	for(i=1;i<1000;i++)
	putpixel((random(100)+210),(random(50)+150),8);

	for(i=1;i<1000;i++)
	putpixel((random(100)+330),(random(50)+150),8);

	for(i=1;i<1000;i++)
	putpixel((random(100)+210),(random(50)+220),8);

	for(i=1;i<1000;i++)
	putpixel((random(100)+330),(random(50)+220),8);

	for(i=1;i<1000;i++)
	putpixel((random(100)+270),(random(70)+180),8);


	rectangle(210,150,310,200);
	rectangle(330,150,430,200);
	rectangle(330,220,430,270);
	rectangle(210,220,310,270);


	line(210,203,270,203);
	line(210,148,313,148);

	line(370,203,430,203);
	line(330,148,430,148);

	line(370,218,430,218);
	line(330,272,430,272);

	line(210,218,270,218);
	line(210,272,313,272);


	setcolor(2);
	outtextxy(215,155,"13");
	outtextxy(285,155,"11");
	outtextxy(335,155,"21");
	outtextxy(415,155,"6");
	outtextxy(215,190,"9");
	outtextxy(285,190,"15");
	outtextxy(335,190,"18");
	outtextxy(415,190,"18");
	outtextxy(215,225,"15");
	outtextxy(285,225,"20");
	outtextxy(335,225,"?");
	outtextxy(415,225,"17");
	outtextxy(215,260,"4");
	outtextxy(285,260,"19");
	outtextxy(335,260,"29");
	outtextxy(415,260,"8");
	in.x.ax=1;
	int86(0x33,&in,&out);
	setcolor(16);
	setfillstyle(1,16);
	poly[0]=260;poly[1]=360;poly[2]=360;poly[3]=360;poly[4]=360;poly[5]=390;poly[6]=260;poly[7]=390;
	fillpoly(4,poly);
	gotoxy(35,24);
		flushall();
		scanf("%d",&answer);
	//answer=a+b;
	if(!IQ_STASTICS(answer,13))
		return(0);

	//getch();
	/*IQno 14*/
	poly[0]= 170;
	poly[1]= 3  ;
	poly[2]= 470;
	poly[3]= 3  ;
	poly[4]= 470;
	poly[5]= 439;
	poly[6]= 170;
	poly[7]= 439;

	setfillstyle(9,6);
	setcolor(6);
	fillpoly(4,poly);

	setcolor(1);

	line(260,250,390,250);
	line(270,250,240,180);
	line(242,182,320,130);
	line(320,130,420,185);
	line (405,180,380,250);
	line(300,250,255,140);
	line(250,205,360,130);
	line(400,200,280,135);
	line(390,140,355,250);
	line(260,225,390,225);

	setcolor (2);
	settextstyle(1,0,1);
	outtextxy(275,225,"A");
	outtextxy(315,130,"T");
	outtextxy(250,175,"K");
	outtextxy(385,170,"G");
	outtextxy(367,225,"Z");
	outtextxy(320,225,"?");
	settextstyle(2,0,5);
	outtextxy(260,200,"20");
	outtextxy(285,155,"18");
	outtextxy(345,155,"26");
	outtextxy(375,200,"32");
	in.x.ax=1;
	int86(0x33,&in,&out);
	setcolor(16);
	setfillstyle(1,16);
	poly[0]=260;poly[1]=360;poly[2]=360;poly[3]=360;poly[4]=360;poly[5]=390;poly[6]=260;poly[7]=390;
	fillpoly(4,poly);
	gotoxy(35,24);
		flushall();
		scanf("%d",&answer);
	//answer=a+b;
	if(!IQ_STASTICS(answer,14))
		return(0);

		/*IQ NO 15*/
		poly[0]= 170;
	poly[1]= 3  ;
	poly[2]= 470;
	poly[3]= 3  ;
	poly[4]= 470;
	poly[5]= 439;
	poly[6]= 170;
	poly[7]= 439;

	setfillstyle(9,6);
	setcolor(6);
	fillpoly(4,poly);

	poly[0]= 225;
	poly[1]= 120;
	poly[2]= 375;
	poly[3]= 120;
	poly[4]= 375;
	poly[5]= 270;
	poly[6]= 225;
	poly[7]= 270;

	setfillstyle(1,0);
	fillpoly(4,poly);


	setcolor(15);


	line(225,120,375,120);
	line(225,150,375,150);
	line(225,180,375,180);
	line(225,210,375,210);
	line(225,240,375,240);
	line(225,270,375,270);

	line(225,120,225,270);
	line(255,120,255,270);
	line(285,120,285,270);
	line(315,120,315,270);
	line(345,120,345,270);
	line(375,120,375,270);

	outtextxy(235,130,"5");
	outtextxy(265,130,"4");
	outtextxy(295,130,"1");
	outtextxy(325,130,"2");
	outtextxy(355,130,"5");

	outtextxy(235,160,"2");
	outtextxy(265,160,"4");
	outtextxy(295,160,"6");
	outtextxy(325,160,"6");
	outtextxy(355,160,"2");

	outtextxy(235,190,"6");
	outtextxy(265,190,"3");
	setcolor(4);
	settextstyle(0,0,3);
	outtextxy(290,185,"?");
	settextstyle(0,0,0);
	setcolor(15);
	outtextxy(325,190,"1");
	outtextxy(355,190,"6");

	outtextxy(235,220,"5");
	outtextxy(265,220,"1");
	outtextxy(295,220,"9");
	outtextxy(325,220,"3");
	outtextxy(355,220,"5");

	outtextxy(235,250,"6");
	outtextxy(265,250,"3");
	outtextxy(295,250,"2");
	outtextxy(325,250,"1");
	outtextxy(355,250,"6");
	in.x.ax=1;
	int86(0x33,&in,&out);
	setcolor(16);
	setfillstyle(1,16);
	poly[0]=260;poly[1]=360;poly[2]=360;poly[3]=360;poly[4]=360;poly[5]=390;poly[6]=260;poly[7]=390;
	fillpoly(4,poly);
	gotoxy(35,24);
		flushall();
		scanf("%d",&answer);
	//answer=a+b;
	if(!IQ_STASTICS(answer,15))
		return(0);

	/*IQ no 16*/
	poly[0]= 170;
	poly[1]= 3  ;
	poly[2]= 470;
	poly[3]= 3  ;
	poly[4]= 470;
	poly[5]= 439;
	poly[6]= 170;
	poly[7]= 439;

	setfillstyle(9,6);
	setcolor(6);
	fillpoly(4,poly);

	setcolor(15);

	circle(240,150,50);
	circle(400,150,50);
	circle(320,250,50);

	setcolor(15);

	line(190,120,240,150);
	line(240,150,295,125);
	line(240,150,240,210);

	line(400,150,450,120);
	line(400,150,350,120);
	line(400,150,400,210);

	line(320,250,370,220);
	line(320,250,270,220);
	line(320,250,320,310);

	settextstyle(1,0,2);
	outtextxy(230,110,"36");
	outtextxy(200,150,"50");
	outtextxy(255,150,"58");

	outtextxy(365,150,"34");
	outtextxy(415,150,"47");
	outtextxy(390,110,"36");

	outtextxy(285,250,"49");
	outtextxy(335,250,"?");
	outtextxy(305,205,"48");
	in.x.ax=1;
	int86(0x33,&in,&out);
	setcolor(16);
	setfillstyle(1,16);
	poly[0]=260;poly[1]=360;poly[2]=360;poly[3]=360;poly[4]=360;poly[5]=390;poly[6]=260;poly[7]=390;
	fillpoly(4,poly);
	gotoxy(35,24);
		flushall();
		scanf("%d",&answer);
	//answer=a+b;
	if(!IQ_STASTICS(answer,16))
		return(0);

	/*END*/
	in.x.ax=2;
	int86(0x33,&in,&out);
	for(w=1;w<250;w++)
		for(x=1;x<3000;x++)
			putpixel(random(640),random(480),8);
	settextstyle(4,0,4);
	setcolor(4);
	outtextxy(200,200,"YOU WINS");
	delay(2000);

	cleardevice();
	in.x.ax=1;
	int86(0x33,&in,&out);

	return(1);


}
//IQ_LVL2(){}
//IQ_LVL3(){}
//IQ_LVL4(){}
//IQ_LVL5(){}

void play_snake()
{



	int i,j,w,x,y,z,n=5,posi,sum,START1=1,START2=1,START3=1,START4=1,START5=1;
	char name[6][12],winner[5][20];
	cleardevice();
	setbkcolor(15);
	//setcolor(8);
	//for(i=0,w=0,x=3,y=640,z=3;i<480;i++,x++,z++)
	//line(w,x,y,z);

	settextstyle(0,0,0);
	setcolor(8);
	outtextxy(200,200," Player   Details");
	outtextxy(150,227,"Enter no of players:");
	//setcolor(3);
	gotoxy(40,15);
	scanf("%d",&n);
	if(n>=5)
		n=5;
	//exit(0);
	cleardevice();
	setbkcolor(15);
	//setcolor(15);
	//for(i=0,w=0,x=3,y=640,z=3;i<480;i++,x++,z++)
	//line(w,x,y,z);
	setcolor(8);
	for(i=1,j=195,w=30,x=13;i<=n;i++,j+=16,x++)
	{
		sprintf(name[i],"Player %d :",i);
		outtextxy(150,j,name[i]);
		gotoxy(w,x);
		scanf("%s",name[i]);  //printf("%s",name[i]);
	}
	pos[1]=0;pos[2]=0;pos[3]=0;pos[4]=0;pos[5]=0;
	//exit(0);
	//play_snake_display();
	randomize();
	while(1)
	{

		for(i=1;i<=n;i++)
		{

			play_snake_display(name,n,i);
			//getch();
			poly[0]=50;poly[1]=250;poly[2]=105;poly[3]=250;poly[4]=105;poly[5]=295;poly[6]=50;poly[7]=295;
			setcolor(16);
			setfillstyle(1,16);
			fillpoly(4,poly);
			poly[0]=55;poly[1]=245;poly[2]=100;poly[3]=245;poly[4]=100;poly[5]=300;poly[6]=55;poly[7]=300;
			setcolor(16);
			setfillstyle(1,16);
			fillpoly(4,poly);

			pieslice(55,250,90,180,5);
			pieslice(100,250,0,90,5);
			pieslice(100,295,270,360,5);
			pieslice(55,295,180,270,5);

			in.x.ax=1;
			int86(0x33,&in,&out);
			//getch();
			while(1)
			{
				in.x.ax=3;
				int86(0x33,&in,&out);
				if(out.x.bx==1)
				{
					in.x.ax=3;
					int86(0x33,&in,&out);

					if(out.x.cx>=60&&out.x.cx<=100&&out.x.dx>330&&out.x.dx<=360)
						break;

					if(out.x.cx>=600&&out.x.cx<=625&&out.x.dx>=30&&out.x.dx<=60){
						in.x.ax=2;
						int86(0x33,&in,&out);
						cleardevice();
						return;
					}
				}
			}

			for(w=0;w<12;w++){//delay(10);
			dice((random(6)+1));}

			posi=(random(6)+1);
			dice(posi);
			 setcolor(8);
			if(i==1)
			if(START1)
			if(posi!=1){
				for(j=1;j<16;j++)
				{       setcolor(j);
					outtextxy(50,440,"roll 1 to start");
					delay(100);

				}
				continue;
				}
				else START1=0;
			if(i==2)
			if(START2)
			if(posi!=1){
				for(j=1;j<16;j++)
				{       setcolor(j);
					outtextxy(50,440,"roll 1 to start");
					delay(100);
					continue;
				}
				continue;}
				else START2=0;
			if(i==3)
			if(START3)
			if(posi!=1){
				for(j=1;j<16;j++)
				{       setcolor(j);
					outtextxy(50,440,"roll 1 to start");
					delay(100);
					continue;
				}
				continue;}
			else START3=0;
			if(i==4)
			if(START4)
			if(posi!=1){
				for(j=1;j<16;j++)
				{       setcolor(j);
					outtextxy(50,440,"roll 1 to start");
					delay(100);
					continue;
				}
				continue;}
			else START4=0;
			if(i==5)
			if(START5)
			if(posi!=1){
				for(j=1;j<16;j++)
				{       setcolor(j);
					outtextxy(50,440,"roll 1 to start");
					delay(100);
					continue;
				}
				continue;}
				else START5=0;

			/*draw go button*/
			in.x.ax=2;
			int86(0x33,&in,&out);
			setcolor(16);
			setlinestyle(0,0,1);
			setfillstyle(1,8);
			poly[0]=60;poly[1]=330;poly[2]=100;poly[3]=330;poly[4]=100;poly[5]=360;poly[6]=60;poly[7]=360;
			fillpoly(4,poly);
			setcolor(15);
			settextstyle(2,0,5);
			outtextxy(70,340,"GO");
			in.x.ax=1;
			int86(0x33,&in,&out);
			while(1)
			{
				in.x.ax=3;
				int86(0x33,&in,&out);
				if(out.x.bx==1)
				{
					//in.x.ax=3;
					//int86(0x33,&in,&out);

					if(out.x.cx>=60&&out.x.cx<=100&&out.x.dx>330&&out.x.dx<=360)
						break;
				}
			}

			sum=pos[i]+posi;
			//getch();
			if(sum<=64)
			{
				pos[i]=sum;
				if(pos[i]==20)
				{       setcolor(4);
					play_snake_display(name,n,i);
					climb(1);
					//outtextxy(0,10,"ladder");
					pos[i]=59;    //getch();
				}
				else if(pos[i]==23)
				{       setcolor(4);
				play_snake_display(name,n,i);
				climb(1);
					//outtextxy(0,10,"ladder");
					pos[i]=42;    //getch();
				}
				else if(pos[i]==1)
				{        setcolor(4);
				play_snake_display(name,n,i);
				climb(1);
					//outtextxy(0,10,"ladder");
					pos[i]=32;    //getch();
				}
				else if(pos[i]==46)
				{        setcolor(4);
					play_snake_display(name,n,i);
					climb(1);
					//outtextxy(0,10,"ladder");
					pos[i]=63;    //getch();
				}


				if(pos[i]==14)
				{        setcolor(4);
				play_snake_display(name,n,i);
				climb(0);
					//outtextxy(0,10,"snake");
					pos[i]=5;     //getch();
				}

				else if(pos[i]==25)
				{        setcolor(4);
				play_snake_display(name,n,i);
				climb(0);
					//outtextxy(0,10,"snake");
					pos[i]=10;    //getch();
				}
				else if(pos[i]==60)
				{        setcolor(4);
				play_snake_display(name,n,i);
				climb(0);
					//outtextxy(0,10,"snake");
					pos[i]=41;    //getch();
				}
				else if(pos[i]==52)
				{        setcolor(4);
				play_snake_display(name,n,i);
				climb(0);
					//outtextxy(0,10,"snake");
					pos[i]=18;    //getch();
				}


				if(pos[i]==64)
				{        setcolor(4);
					sprintf(winner[0],"%s wins",name[i]);
					//play_snake_display(name,n);
					goto c;
				}
			}
		}
	}
	c:
	//printf("\nEND of GAME ");
	in.x.ax=2;
	int86(0x33,&in,&out);
	for(w=1;w<50;w++)
		for(x=1;x<3000;x++)
			putpixel(random(640),random(480),8);
	settextstyle(2,0,10);
	setcolor(4);
	outtextxy(200,200,winner[0]);
	delay(2000);
	cleardevice();
	//getch();
	return(0);
}

int climb(int flag)
{
	in.x.ax=2;
	int86(0x33,&in,&out);
	setcolor(16);
	setlinestyle(0,0,1);
	setfillstyle(1,8);
	poly[0]=60;poly[1]=330;poly[2]=100;poly[3]=330;poly[4]=100;poly[5]=360;poly[6]=60;poly[7]=360;
	fillpoly(4,poly);
	setcolor(15);
	settextstyle(2,0,4);
	if(flag)
		outtextxy(65,340,"CLIMB");
	else
		outtextxy(65,340,"SNAKE!");
	in.x.ax=1;
	int86(0x33,&in,&out);
	while(1)
	{
		in.x.ax=3;
		int86(0x33,&in,&out);
		if(out.x.bx==1)
		{
			//in.x.ax=3;
			//int86(0x33,&in,&out);
			if(out.x.cx>=60&&out.x.cx<=100&&out.x.dx>330&&out.x.dx<=360)
				break;
		}
	}

}
int dice(int n)
{
	delay(100);
	poly[0]=50;poly[1]=250;poly[2]=105;poly[3]=250;poly[4]=105;poly[5]=295;poly[6]=50;poly[7]=295;
	setcolor(16);
	setfillstyle(1,16);
	fillpoly(4,poly);
	poly[0]=55;poly[1]=245;poly[2]=100;poly[3]=245;poly[4]=100;poly[5]=300;poly[6]=55;poly[7]=300;
	setcolor(16);
	setfillstyle(1,16);
	fillpoly(4,poly);

	pieslice(55,250,90,180,5);
	pieslice(100,250,0,90,5);
	pieslice(100,295,270,360,5);
	pieslice(55,295,180,270,5);

	setcolor(15);
	setfillstyle(1,15);

	switch(n)
	{
		case 1 :
			fillellipse(78,273,5,5);
			break;
		case 2 :
			fillellipse(68,265,5,5);
			fillellipse(88,285,5,5);
			break;
		case 3 :
			fillellipse(77,259,5,5);
			fillellipse(77,273,5,5);
			fillellipse(77,287,5,5);
			break;
		case 4 :
			fillellipse(68,263,5,5);
			fillellipse(88,283,5,5);
			fillellipse(68,283,5,5);
			fillellipse(88,263,5,5);
			break;
		case 5 :
			fillellipse(68,263,5,5);
			fillellipse(88,283,5,5);
			fillellipse(68,283,5,5);
			fillellipse(88,263,5,5);
			fillellipse(78,273,5,5);
			break;
		case 6 :
			fillellipse(65,260,5,5);
			fillellipse(88,260,5,5);
			fillellipse(65,274,5,5);
			fillellipse(88,274,5,5);
			fillellipse(65,288,5,5);
			fillellipse(88,288,5,5);
			break;
	}
}
void play_snake_display(char name[10][12],int no,int player)
{
	int j,i,l,p,q,k,n=64,variable[2];
	int w,x,y,z;
	int poly[12]={175,50,587,50,587,460,175,460,175,50};
	cleardevice();
	setbkcolor(0);
	setcolor(15);
	for(i=0,w=0,x=3,y=640,z=3;i<=480;i++,x++,z++)
	line(w,x,y,z);
	setcolor(6);
	setlinestyle(0,1,3);
	drawpoly(5,poly);
	rectangle(178,53,584,457);
	poly[0]=181;poly[1]=56;poly[2]=581;poly[3]=56;poly[4]=581;poly[5]=454;poly[6]=181;poly[7]=454;poly[8]=181;poly[9]=56;
	setfillstyle(1,3);
	fillpoly(4,poly);
	setcolor(2);
	settextstyle(4,0,4);
	outtextxy(5,20,"SNAKE &");
	setcolor(12);
	outtextxy(20,60,"LADDERS");
	settextstyle(0,0,0);
	setlinestyle(0,0,1);
	for(i=1,w=50,x=150,y=60,z=147;i<=no;i++,x+=15,z+=15)
	{
		setcolor(i);
		setfillstyle(1,i+8);
		fillellipse(w,x,5,5);
		outtextxy(y,z,name[i]);

	}
	setcolor(6);
	if(player==1){outtextxy(20,146,"--");outtextxy(20,146,">");}
	if(player==2){outtextxy(20,161,"--");outtextxy(20,161,">");}
	if(player==3){outtextxy(20,176,"--");outtextxy(20,176,">");}
	if(player==4){outtextxy(20,191,"--");outtextxy(20,191,">");}
	if(player==5){outtextxy(20,206,"--");outtextxy(20,206,">");}

/*	poly[0]=50;poly[1]=250;poly[2]=105;poly[3]=250;poly[4]=105;poly[5]=295;poly[6]=50;poly[7]=295;
	setcolor(16);
	setfillstyle(1,16);
	fillpoly(4,poly);
	poly[0]=55;poly[1]=245;poly[2]=100;poly[3]=245;poly[4]=100;poly[5]=300;poly[6]=55;poly[7]=300;
	setcolor(16);
	setfillstyle(1,16);
	fillpoly(4,poly);

	pieslice(55,250,90,180,5);
	pieslice(100,250,0,90,5);
	pieslice(100,295,270,360,5);
	pieslice(55,295,180,270,5);
*/
	//getch();exit(0);
	/*exit button*/

	setcolor(15);
	setfillstyle(1,15);
	poly[0]=600;poly[1]=30;poly[2]=625;poly[3]=30;poly[4]=625;poly[5]=60;poly[6]=600;poly[7]=60;
	fillpoly(4,poly);
	setlinestyle(0,0,3);
	setcolor(4);
	line(600,30,625,60);
	line(625,30,600,60);
	settextstyle(2,0,0);
	setcolor(8);
	outtextxy(603,37,"e");
	outtextxy(610,29,"x");
	outtextxy(619,39,"i");
	outtextxy(610,48,"t");
	setcolor(4);
	rectangle(600,30,625,60);

	/*draw roll dice */
	in.x.ax=2;
	int86(0x33,&in,&out);
	setcolor(8);
	setlinestyle(0,0,1);
	setfillstyle(1,7);
	poly[0]=60;poly[1]=330;poly[2]=100;poly[3]=330;poly[4]=100;poly[5]=360;poly[6]=60;poly[7]=360;
	fillpoly(4,poly);
	setcolor(16);
	settextstyle(2,0,0);
	outtextxy(70,340,"ROLL");
	in.x.ax=1;
	int86(0x33,&in,&out);
	for(j=63,l=1;j<427;j=j+47,l++)
	{
		for(i=188;i<555;i=i+47,l++)
		{

			poly[0] = i+5;
			poly[1] = j+5;
			poly[2] = i+47;
			poly[3] = j+5;
			poly[4] = i+47;
			poly[5] = j+47;
			poly[6] = i+5;
			poly[7] = j+47;
			setcolor(8);
			setlinestyle(0,1,1);
			if(l%2)
				setfillstyle(1,7);
			else
				setfillstyle(1,3);

			fillpoly(4,poly);

		}
	}
	ladders();
	snake1();
	/*write the variablesand players on board*/
	setlinestyle(0,1,1);
	for(z=1;z<=5;z++)
	{
		for(p=1,j=75,l=75,n=64;p<=8;j+=47,l+=47,p++)
		{
			for(q=1,i=197,k=527;q<=8;i+=47,k-=47,q++)
			{
				setcolor(8);
				if(p%2)
				{
					if(pos[z]==n)
					{
						setcolor(8);
						setfillstyle(1,z+8);
						fillellipse(i,j,5,5);
					}
					sprintf(variable,"%d",n);
					outtextxy(i,j,variable);
					n--;
				}
				else
				{
					if(pos[z]==n)
					{
						setcolor(8);
						setfillstyle(1,z+8);
						fillellipse(k,l,5,5);
					}
					sprintf(variable,"%d",n);
					outtextxy(k,l,variable);
					n--;
				}


			}
		}
	}
}
int ladders()
{
	setlinestyle(0,1,3);
	setcolor(14);
	line(205,280,205,419);line(220,280,220,419);
	//setlinestyle(0,0,1);
	line(203,290,222,290);line(203,320,222,320);line(203,340,222,340);line(203,360,222,360);line(203,380,222,380);line(203,400,222,400);

	//ladder1size=imagesize(8,20,27,89);
	//ladder1img=(void *)malloc(ladder1size);
	//getimage(8,20,27,89,ladder1img);
	/*no 2*/
	setlinestyle(0,1,3);
	setcolor(14);
	line(443,100,347,313);line(455,100,362,313);
	setlinestyle(0,1,1);
	//setcolor(14);
	line(434,115,451,115);line(431,120,449,120);line(429,125,447,125);line(427,130,444,130);line(425,135,442,135);line(422,140,440,140);line(420,145,438,145);line(418,150,436,150);line(416,155,434,155);line(414,160,431,160);line(411,165,429,165);line(409,170,427,170);line(407,175,425,175);line(404,180,423,180);line(402,185,420,185);line(400,190,418,190);line(398,195,416,195);line(395,200,414,200);line(393,205,412,205);line(391,210,410,210);line(389,215,408,215);line(386,220,405,220);line(384,225,403,225);line(382,230,401,230);line(380,235,399,235);line(377,240,396,240);line(375,245,394,245);line(373,250,392,250);line(371,255,390,255);line(368,260,388,260);line(366,265,386,265);line(364,270,383,270);line(362,275,381,275);line(359,280,379,280);line(357,285,377,285);line(355,290,375,290);line(353,295,372,295);line(350,300,370,300);
	//ladder2size=imagesize(430,300,520,430);
	//ladder2img=(void *)malloc(ladder2size);
	//getimage(430,300,520,430,ladder2img);

	/*no 3*/
	setlinestyle(0,1,3);
	setcolor(14);
	line(490,200,490,313);line(505,200,505,313);
	setlinestyle(0,1,1);
	line(488,210,507,210);line(488,215,507,215);line(488,220,507,220);line(488,225,507,225);line(488,230,507,230);line(488,235,507,235);line(488,240,507,240);line(488,245,507,245);line(488,250,507,250);line(488,255,507,255);line(488,260,507,260);  line(488,265,507,265); line(488,270,507,270);line(488,275,507,275);line(488,280,507,280);line(488,285,507,285);line(488,290,507,290);line(488,295,507,295);line(488,300,507,300);line(488,305,507,305);line(488,310,507,310);
	//getch();exit(0);
	//ladder3size=imagesize(563,345,577,400);
	//ladder3img=(void *)malloc(ladder3size);
	//getimage(563,345,577,400,ladder3img);
	//getch();
	/*no 4*/
	setlinestyle(0,1,3);
	setcolor(14);
	line(250,103,300,183);line(265,103,315,183);
	setlinestyle(0,1,1);
	line(251,108,271,108);line(254,113,274,113);line(257,118,277,118);line(260,123,280,123);line(263,128,283,128);line(266,133,286,133);line(270,138,289,138);line(273,143,293,143);line(276,148,296,148);line(279,153,299,153);line(282,158,302,158);line(285,163,305,163);line(288,168,308,168);line(291,173,311,173);


	//getch();
	setcolor(WHITE);
}
int snake1()
{       int z,i=345,j=155;
	setcolor(RED);
	setlinestyle(0,1,3);
	for(z=0;z<13;z++)
		arc(i,j,20,125,z);
	setlinestyle(0,1,3);
	arc(i-28,j,270,360,28);
	arc(i-28,j+56,90,180,28);
	arc(i-28,j+56,90,178,27);
	arc(i-83,j+56,280,0,28);
	arc(i-83,j+56,280,0,27);
	arc(i-75,j+110,95,230,26);
	arc(i-75,j+110,95,230,25);
	arc(i-118,j+140,310,20,28);
	fillellipse(i-3,j-9,0,0);
	fillellipse(i+5,j-7,0,0);

//}
//void snake3()
//{
//	int i;
	setcolor(4);
	//setfillstyle(1,8);
	setlinestyle(0,1,3);
	for(i=0;i<13;i++)
		arc(416,105,83,185,i);
	arc(416+28,95,180,270,28);
	arc(416+28,95+28+28,0,90,28);
	arc(416+28+28+28,95+28+28,180,270,28);
	arc(416+28+28+28,95+28+28,270,300,28);
	arc(416+28+28+28+17,95+27+28+28+25,35,95,28);
	fillellipse(416-3,105-9,0,0);
	fillellipse(416-9,105-4,0,0);

//}


//void snake4()
//{
	//int i;
	setlinestyle(0,1,3);
	setcolor(4);
	for(i=0;i<10;i++)
		arc(325,375,90,180,i);
	arc(320,375+13,0,80,15);
	arc(320+30,375+13,180,270,15);
	arc(320+30,375+13+13+15,0,90,15);
	arc(320+30+30,375+13+13+15,180,310,15);
	fillellipse(325-6,375-2,0,0);
	fillellipse(325-3,375-7,0,0);

//void snake5()
//{

//	int i;
	setcolor(RED);
	setlinestyle(0,1,3);
	for(i=0;i<13;i++)
		arc(553,290,65,145,i);
	arc(538,290,270,0,15);
	arc(538,290+15+15,90,180,15);
	arc(538-15-15,290+15+15,270,0,15);
	setlinestyle(2,2,7);
	arc(538-15-15,290+15+15+15+15,90,230,15);
	fillellipse(553-5,290-6,0,0);
	fillellipse(553+1,290-8,0,0);
//}


}
//int play_mine(){}
int draw_frame2_mine()
{
	int i,j,k,l,p,q,n=64;
	int poly[8],variable[3];
	setcolor(0);
	/*draw outline of board*/
	poly[0]=10;poly[1]=260;poly[2]=277;poly[3]=260;poly[4]=277;poly[5]=447;poly[6]=10;poly[7]=447;
	setfillstyle(1,1);
	fillpoly(4,poly);
	for(i=13;i<267;i+=20)
	{
		for(j=263;j<437;j+=20)
		{
			rectangle(i,j,i+15,j+15);
		}
	}/*
	for(j=263;j<447;j=j+23)
	{
		for(i=13;i<277;i=i+33)
		{

			poly[0] = i;
			poly[1] = j;
			poly[2] = i+32;
			poly[3] = j;
			poly[4] = i+32;
			poly[5] = j+22;
			poly[6] = i;
			poly[7] = j+22;
			setlinestyle(0,1,1);
			setfillstyle(9,1);
			fillpoly(4, poly);
		}
	}  */
	/*make the play button*/
	setcolor(WHITE);
	setlinestyle(0,0,3);
	setfillstyle(1,8);
	arc(200,450,180,360,3);
	arc(240,450,180,360,3);
	fillellipse(200,461,1,7);
	fillellipse(240,461,1,7);
	setcolor(15);

	setfillstyle(1,15);
	bar3d(190,461,250,476,0,1);
	setcolor(2);
	poly[0]=215;poly[1]=463;poly[2]=225;poly[3]=468;poly[4]=215;poly[5]=473;
	setfillstyle(1,2);
	fillpoly(3,poly);
	setlinestyle(0,0,0);



}
int input_manipultion_from_frame2()
{


/*	while(1)
	{
		in.x.ax=3;
		int86(0x33,&in,&out);
		if(out.x.bx==2)
			break;
	}
*/
	while(1)
	{

		in.x.ax=3;
		int86(0x33,&in,&out);
		if(out.x.bx==1)
		{

			if((out.x.cx>=190)&&(out.x.cx<=250)&&(out.x.dx>=211)&&(out.x.dx<=230))
			{

				in.x.ax=2;
				int86(0x33,&in,&out);
				cleardevice();

				return(1);

			}
		   else if((out.x.cx>=540)&&(out.x.cx<=600)&&(out.x.dx>=211)&&(out.x.dx<=230))
			{
				in.x.ax=2;
				int86(0x33,&in,&out);
				cleardevice();

				return(2);
			}
		   else if((out.x.cx>=540)&&(out.x.cx<=600)&&(out.x.dx>=461)&&(out.x.dx<=476))
			{
				in.x.ax=2;
				int86(0x33,&in,&out);
				cleardevice();

				return(3);

			}
		   else if((out.x.cx>=190)&&(out.x.cx<=250)&&(out.x.dx>=461)&&(out.x.dx<=476))
			{
			       in.x.ax=2;
				int86(0x33,&in,&out);
				cleardevice();

			       return(4);
			 }
		   else if((out.x.cx>=600)&&(out.x.cx<=625)&&(out.x.dx>=30)&&(out.x.dx<=60))
			{
				in.x.ax=2;
				int86(0x33,&in,&out);
				cleardevice();

				return(0);
			}


		}
	}
}

int draw_frame2()
{
/*	int poly1[10]={10,10,280,10,280,200,10,200};
	int poly2[10]={360,10,630,10,630,200,360,200};
	int poly3[10]={10,280,280,280,280,470,10,470};
	int poly4[10]={360,280,630,280,630,470,360,470};
*/
	setbkcolor(0);
	background();
	setcolor(WHITE);

	setfillstyle(1,8);
	setlinestyle(0,0,1);
	bar3d(10,10,280,200,4,1); /*chess frame*/
	draw_frame2_chessboard();

	setfillstyle(1,WHITE);
	setcolor(WHITE);
	bar3d(360,10,630,200,4,1); /*IQ challenge frame*/
	draw_frame2_IQboard();

	setfillstyle(1,8);
	setcolor(WHITE);
	bar3d(10,260,280,450,4,1);  /*4th gasme*/
	draw_frame2_mine();
	bar3d(360,260,630,450,4,1); /*snake board frame*/
	draw_frame2_snakeboard();
	/*END BUTTON*/
	END();
	in.x.ax=1;
	int86(0x33,&in,&out);

	in.x.ax=4;
	in.x.cx=500;
	in.x.dx=30;
	int86(0x33,&in,&out);

	//int86(0x33,&in,&out);

	return(input_manipultion_from_frame2());

}

void draw_frame1()
{
	int i,w,x,y,z;
	setbkcolor(0);
	setcolor(WHITE);

	for(i=0,w=0,x=3,y=640,z=3;i<500;i++,x++,z++)
	line(w,x,y,z);


	settextstyle(11,0,0);

	setcolor(BLACK);
	outtextxy(300,200,"C pearls");
	settextstyle(2,0,0);
	outtextxy(10,468,"copyright c  Cpearls 2014");
	circle(70,475,5); //copy right symbol

	setcolor(WHITE);
	setlinestyle(0,0,1);
	//.1
	delay(100);
	setfillstyle(1,2);
	fillellipse(200,200,3,3);
	//.2
	delay(100);
	setfillstyle(1,6);
	fillellipse(210,200,3,3);
	//.3
	delay(100);
	setfillstyle(1,1);
	fillellipse(220,200,3,3);
	//.4
	delay(100);
	setfillstyle(1,3);
	fillellipse(230,193,3,3);
	//.5
	delay(100);
	setfillstyle(1,3);
	fillellipse(240,185,3,3);
	//.6
	delay(100);
	setfillstyle(1,13);
	fillellipse(250,180,4,4);
	//.7
	delay(100);
	setfillstyle(1,11);
	fillellipse(263,183,3,3);
	//.8
	delay(100);
	setfillstyle(1,10);
	fillellipse(272,188,3,3);
	//.9
	delay(100);
	setfillstyle(1,3);
	fillellipse(280,197,3,3);
	//.10
	delay(100);
	setfillstyle(1,3);
	fillellipse(272,205,3,3);
	//.11
	delay(100);
	setfillstyle(1,3);
	fillellipse(263,213,3,3);
	//.12
	delay(100);
	setfillstyle(1,13);
	fillellipse(250,217,4,4);

	//.13
	delay(100);
	setfillstyle(1,3);
	fillellipse(243,213,3,3);
	//.14
	delay(100);
	setfillstyle(1,3);
	fillellipse(235,207,3,3);
	//.15
	delay(100);
	setfillstyle(1,14);
	fillellipse(230,200,2,2);
	//.16
	delay(100);
	setfillstyle(1,11);
	fillellipse(240,197,3,3);
	//.17
	delay(100);
	setfillstyle(1,10);
	fillellipse(247,205,3,3);
	//.18
	delay(100);
	setfillstyle(1,14);
	fillellipse(255,206,3,3);
	//.19
	delay(100);
	setfillstyle(1,4);
	fillellipse(260,200,3,3);

	//.20
	delay(100);
	setfillstyle(1,12);
	fillellipse(250,197,3,3);

	//.21
	delay(100);
	setfillstyle(1,9);
	fillellipse(246,190,3,3);
	//.22
	delay(100);
	setfillstyle(1,9);
	fillellipse(257,192,3,3);
	//.23
	delay(100);
	setfillstyle(1,0);
	fillellipse(268,197,2,2);

}

void draw_frame2_ladder()
{
	cleardevice();
	/*no  1*/
	setlinestyle(0,1,3);
	setcolor(14);
	line(10,20,10,89);line(25,20,25,89);
	setlinestyle(0,0,1);
	line(8,30,27,30);line(8,40,27,40);line(8,50,27,50);line(8,60,27,60);line(8,70,27,70);line(8,80,27,80);
	ladder1size=imagesize(8,20,27,89);
	ladder1img=(void *)malloc(ladder1size);
	getimage(8,20,27,89,ladder1img);
	/*no 2*/
	setlinestyle(0,1,3);
	setcolor(14);
	line(510,305,437,413);line(520,305,447,413);
	setlinestyle(0,1,1);
	line(504,310,519,310);line(500,315,516,315);line(497,320,513,320);line(494,325,509,325);line(491,330,506,330);line(487,335,502,335);line(484,340,499,340);line(480,345,495,345);line(477,350,492,350);line(474,355,489,355);line(470,360,485,360);line(467,365,482,365);line(463,370,479,370);line(460,375,475,375);line(457,380,472,380);line(453,385,469,385);line(450,390,465,390);line(446,395,462,395);line(443,400,458,400);line(440,405,455,405);line(437,410,452,410);
	ladder2size=imagesize(430,300,520,430);
	ladder2img=(void *)malloc(ladder2size);
	getimage(430,300,520,430,ladder2img);

	/*no 3*/
	setlinestyle(0,1,3);
	setcolor(14);
	line(565,345,565,400);line(575,345,575,400);setlinestyle(0,1,1);line(563,350,577,350);line(563,360,577,360);line(563,370,577,370);line(563,380,577,380);line(563,390,577,390);
	ladder3size=imagesize(563,345,577,400);
	ladder3img=(void *)malloc(ladder3size);
	getimage(563,345,577,400,ladder3img);
	//getch();
	/*no 4*/
	setlinestyle(0,1,3);
	setcolor(14);
	//getch();
	setcolor(WHITE);
	cleardevice();
}

void draw_frame2_snakeboard()
{
	int i,j,k,l,p,q,n=64;
	int poly[8],variable[3];
	setcolor(6);
	/*draw outline of board*/
	for(j=263;j<447;j=j+23)
	{
		for(i=363;i<627;i=i+33)
		{

			poly[0] = i;
			poly[1] = j;
			poly[2] = i+32;
			poly[3] = j;
			poly[4] = i+32;
			poly[5] = j+22;
			poly[6] = i;
			poly[7] = j+22;
			setlinestyle(0,1,1);
			setfillstyle(1,4);
			fillpoly(4, poly);
		}
	}
	/*place ladders*/
	putimage(403,370,ladder1img,OR_PUT);
	putimage(460,270,ladder2img,OR_PUT);
	putimage(564,325,ladder3img,OR_PUT);
	setcolor(2);
	setlinestyle(0,1,3);

	for(i=0;i<11;i++)
		arc(467,373,90,180,i);
	arc(465,373+8,340,80,8);
	arc(466,373+8+1,270,0,8);
	arc(466,373+8+1+5+8+2,90,180,8);
	arc(466,373+8+1+5+8+2,180,250,8);
	arc(466+5-9,373+8+1+5+8+2+8+5+2,230,90,8);
	fillellipse(467-3,373-7,0,0);
	fillellipse(467-8,373-2,0,0);

	//snake2
	for(i=0;i<11;i++)
		arc(550,310,30,120,i);
	arc(550+8,310,180,270,8);
	arc(550+8,310+8+8,270,90,8);
	arc(550+8,310+8+8+16,90,230,8);
	arc(550-3,310+8+8+16+8+3,230,45,8);
	arc(550-8,310+13+8+16+8+3+11,80,180,8);
	fillellipse(550-2,310-8,0,0);
	fillellipse(550+5,310-6,0,0);

	//snake3
	for(i=0;i<11;i++)
		arc(455,280,55,150,i);
	arc(455-5,280+6,280,45,8);
	arc(455-4,280+6+8+8+3,85,250,12);
	arc(455-4-15+5,280+15+8+8+3+8,230,75,8);
	arc(455-21,280+14+8+8+3+8+16,85,280,8);
	fillellipse(455,273,0,0);
	fillellipse(455-5,275,0,0);
	/*write the variables on board*/
	for(p=1,j=265,l=265;p<=8;j+=23,l+=23,p++)
	{
		for(q=1,i=365,k=610;q<=8;i+=33,k-=33,q++)
		{
			setcolor(8);
			if(p%2){
			sprintf(variable,"%d",n);
			outtextxy(i,j,variable);
			n--;  }
			else  {
			sprintf(variable,"%d",n);
			outtextxy(k,l,variable);
			n--;  }


		}
	}
	/*make the play button*/
	setcolor(WHITE);
	setlinestyle(0,0,3);
	setfillstyle(1,8);
	arc(550,450,180,360,3);
	arc(590,450,180,360,3);
	fillellipse(550,461,1,7);
	fillellipse(590,461,1,7);
	setcolor(15);

	setfillstyle(1,15);
	bar3d(540,461,600,476,0,1);
	setcolor(2);
	poly[0]=565;poly[1]=463;poly[2]=575;poly[3]=468;poly[4]=565;poly[5]=473;
	setfillstyle(1,2);
	fillpoly(3,poly);
	setlinestyle(0,0,0);


}
void background()
{
	int i,j;
	//int *k;
	for(i=0;i<=600;i+=40)
	{
		for(j=0;j<=440;j+=40)
		{
			putimage(i,j,bgimg,XOR_PUT);
		}
	}

	for(i=0;i<=440;i+=40)
		putimage(599,i,bgimg,XOR_PUT);
}
int END()
{
	/*draw end button*/
	setcolor(15);
	setfillstyle(1,15);
	poly[0]=600;poly[1]=30;poly[2]=625;poly[3]=30;poly[4]=625;poly[5]=60;poly[6]=600;poly[7]=60;
	fillpoly(4,poly);
	setlinestyle(0,0,3);
	setcolor(4);
	line(600,30,625,60);
	line(625,30,600,60);
	settextstyle(2,0,0);
	setcolor(8);
	outtextxy(603,37,"e");
	outtextxy(610,29,"x");
	outtextxy(619,39,"i");
	outtextxy(610,48,"t");
	setcolor(4);
	rectangle(600,30,625,60);

}
void main ()
{
	int gd = DETECT, gm;
	int i=1,j;

	initgraph(&gd, &gm, "c:\\tc\\bgi");


/*	draw_frame1();
	delay(5000);
	draw_frame2_ladder();/*draws ladder images and saves*/
/*	draw_background();    /*draws a background image for the game*/
/*	while(i)
	{

		switch(draw_frame2())/*draws frame2 */
/*		{
			case 1:
				play_chess();
				settextstyle(0,0,0);
				cleardevice();
				break;
			case 2:
				play_IQ();
				settextstyle(0,0,0);
				cleardevice();
				break;
			case 3:
				//exit(0);
				play_snake();
				settextstyle(0,0,0);
				cleardevice();   //exit(0);
				break;
			case 4:    */
				play_mine();
				settextstyle(0,0,0);
				cleardevice();   //exit(0);

//			       	break;
		     /*	case 0:
				in.x.ax=2;
				int86(0x33,&in,&out);
				cleardevice();
				//closegraph();
				//exit(1);
				i=0;
			default:
				;
				break;
		}
	}              */
	getch();
	closegraph();

}
