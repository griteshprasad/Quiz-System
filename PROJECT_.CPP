#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<fstream.h>
#include<dos.h>
#include<ctype.h>

union REGS in,out;

class mouse               //class definition
{
	public:
		void show_mouse()
	{
		in.x.ax=1;
		int86(0X33,&in,&out);
	}
};

class quiz:public mouse          //class definition
{
	char option[10];
	char que1[52];
	char que2[50];
	char ans[21];
	int  back;
	int  i;
	int  total;
	int  midx,midy;


      public:

	ifstream fin;
	void welcome();
	void instructions();
	void start();
	void choice(int,int);
	void score();
	void thanks();
	void logo();

	void show_ques1();
	void show_ques2();
	void show_ques3();
	void show_ques4();
	void show_ques5();
	void show_ques6();
	void show_ques7();
	void show_ques8();
	void show_ques9();
	void show_ques10();
};

void quiz::logo()
{
	midx=getmaxx()/2;
	midy=getmaxy()/2;

	circle(midx,midy-50,155);
	circle(midx,midy-50,125);
	line(midx-100,midy+25,midx-85,midy-140);
	line(midx-95,midy+31,midx-50,midy-165);
	line(midx-85,midy+40,midx+25,midy-173);
	line(midx-83,midy+42,midx+60,midy-160);
	line(midx-78,midy+48,midx+113,midy-107);
	line(midx-75,midy+50,midx+123,midy-70);
	line(midx-65,midy+55,midx+103,midy+20);
	line(midx-63,midy+58,midx+67,midy+55);

	settextstyle(10,0,2);
	setcolor(getmaxcolor());
	outtextxy(midx-240,midy+110,"Lovely Professional University");

	settextstyle(7,0,1);
	setcolor(getmaxcolor());
	outtextxy(midx-242,midy+150,"Transforming  Education  Transforming India");

	delay(10000);
	welcome();
}

void quiz::welcome()                       //welcome page
{
		cleardevice();
		rectangle(0,20,getmaxx(),getmaxy()-20);
		setcolor(GREEN);
		rectangle(20,40,getmaxx()-20,getmaxy()-40);
		rectangle(140,100,490,160);
		rectangle(130,90,500,170);
		setfillstyle(1,YELLOW);
		floodfill(150,110,GREEN);
		setfillstyle(1,YELLOW);
		floodfill(200,200,GREEN);
		setfillstyle(4,GREEN);
		floodfill(10,30,GREEN);
		setcolor(RED);
		settextstyle(10,0,3);
		outtextxy(150,100,"WELCOME TO THE ");
		settextstyle(7,0,5);
		outtextxy(100,340,"Programming Quiz");
		settextstyle(7,0,1);
		outtextxy(430,410,"Hosted by GRITESH");
	//LOGO
	{
		setcolor(WHITE);
		circle(330,265,70);
		setfillstyle(10,RED);
		floodfill(340,270,WHITE);
		circle(330,265,80);
		setfillstyle(1,WHITE);
		floodfill(280,205,WHITE);

		settextstyle(4,0,10);
		setcolor(BLUE);
		outtextxy(270,160,"P");
		setcolor(GREEN);
		outtextxy(310,190,"Q");
	 }
		delay(10000);
		back=0;
		instructions();
}


void quiz::instructions()              //instruction page
{
		cleardevice();
		rectangle(0,20,getmaxx(),getmaxy()-20);
		setcolor(GREEN);
		rectangle(20,40,getmaxx()-20,getmaxy()-40);
		line(80,40,80,getmaxy()-40);
		setcolor(BLUE);
		settextstyle(1,1,6);
		outtextxy(20,60,"INSTRUCTIONS");
		setcolor(WHITE);
		settextstyle(1,0,2);
		outtextxy(100,60,"* This is just a GAME for fun.");
		outtextxy(100,90,"* Use mouse pointer to select your answer.");
		outtextxy(100,120,"* Click on the arrow to go to the next question.");
		outtextxy(100,150,"* Note that once you enter the next question");
		outtextxy(100,170,"  you are not allowed to come back on the");
		outtextxy(100,190,"  previous question.");
		outtextxy(100,220,"Marking Criterion:");
		outtextxy(100,250,"* Each correct answer will be awarded with 5");
		outtextxy(100,270,"  Marks.");
		outtextxy(100,300,"* We are not going to cut your marks for wrong");
		outtextxy(100,320,"  answers.");
		outtextxy(100,350,"* So Enjoy The GAME");
		outtextxy(200,400,"Press Enter if you are done...");

		getch();

		switch(back)
		{
			case 0:	 start();
				 break;
			case 1:	 show_ques1();
				 break;
			case 2:	 show_ques2();
				 break;
			case 3:	 show_ques3();
				 break;
			case 4:	 show_ques4();
				 break;
			case 5:	 show_ques5();
				 break;
			case 6:	 show_ques6();
				 break;
			case 7:	 show_ques7();
				 break;
			case 8:	 show_ques8();
				 break;
			case 9:	 show_ques9();
				 break;
			case 10: show_ques10();
				 break;
		}
}


void quiz::start()            //starting page
{
		cleardevice();
		rectangle(0,20,getmaxx(),getmaxy()-20);
		setcolor(GREEN);
		rectangle(20,40,getmaxx()-20,getmaxy()-40);
		settextstyle(1,0,3);
		setcolor(BLUE);
		outtextxy(265,100,"Excited ???");
		outtextxy(220,130,"Hit Enter to start");
		setcolor(GREEN);
		outtextxy(250,370,"!!!GOOD LUCK!!!");



	//LOGO
	{
		setcolor(WHITE);
		circle(330,265,70);
		setfillstyle(10,RED);
		floodfill(340,270,WHITE);
		circle(330,265,80);
		setfillstyle(1,WHITE);
		floodfill(280,205,WHITE);

		settextstyle(4,0,10);
		setcolor(BLUE);
		outtextxy(270,160,"P");
		setcolor(GREEN);
		outtextxy(310,190,"Q");
	 }
		getch();

		show_ques1();

}



void quiz::show_ques1()                      //question 1
{
		cleardevice();
		show_mouse();
		setcolor(WHITE);
		rectangle(0,20,getmaxx(),getmaxy()-20);
		setcolor(GREEN);
		rectangle(20,40,getmaxx()-20,getmaxy()-40);


	 //option
	 {
		setcolor(BLUE);
		settextstyle(1,0,1);
		outtextxy(40,50,"Instructions");
		line(40,70,148,70);
		outtextxy(560,50,"Quit");
		line(560,70,598,70);
		setcolor(7);
		line(getmaxx()-30,150,getmaxx()-40,130); //next
		line(getmaxx()-30,150,getmaxx()-40,170);
	 }


	//LOGO
	{
		setcolor(WHITE);
		circle(330,145,70);
		setfillstyle(10,RED);
		floodfill(340,150,WHITE);
		circle(330,145,80);
		setfillstyle(1,WHITE);
		floodfill(280,85,WHITE);

		settextstyle(4,0,10);
		setcolor(BLUE);
		outtextxy(270,40,"P");
		setcolor(GREEN);
		outtextxy(310,70,"Q");
	}


	//Question boxes
	{
		setcolor(BLUE);
		rectangle(60,250,580,300);  //ques
		setcolor(WHITE);
		line(60,245,580,245);       //line1
		line(60,305,580,305); 	    //line2
		setcolor(GREEN);
		rectangle(60,330,300,360);  //ans1
		rectangle(340,330,580,360); //ans2
		rectangle(60,380,300,410);  //ans3
		rectangle(340,380,580,410); //ans4
	}
	setcolor(WHITE);
	settextstyle(7,0,1);

	//questions

	{
		fin.open("1.txt");
		fin.getline(que1,52);      //question1
		outtextxy(70,250,que1);
		fin.getline(que2,50);      //question2
		outtextxy(85,270,que2);
		fin.close();

		fin.open("1a.txt");
		fin.getline(ans,21);
		outtextxy(70,332,ans);
		fin.close();

		fin.open("1b.txt");
		fin.getline(ans,21);
		outtextxy(350,332,ans);
		fin.close();

		fin.open("1c.txt");
		fin.getline(ans,21);
		outtextxy(70,383,ans);
		fin.close();

		fin.open("1d.txt");
		fin.getline(ans,21);
		outtextxy(350,383,ans);
		fin.close();
	}

	i=0;

	while(!kbhit())
	{
		int x,y,button;

		in.x.ax=3;
		int86(0X33,&in,&out);

		button=out.x.bx&7;

		switch(button)
		{
			case 1:
			case 3: x=out.x.cx;
				y=out.x.dx;
				break;
		}

		if((x>=getmaxx()-40)&&(x<=getmaxx()-30)&&(y>=130)&&(y<=170))
		{
			cleardevice();
			setcolor(WHITE);
			outtextxy(150,200,"Wanna go to the next question !!!");
			outtextxy(250,250,"...Hit Enter...");
			getch();
			show_ques2();
		}

		back=1;
		choice(x,y);
	}
}



void quiz::show_ques2()               //question 2
{
		cleardevice();
		show_mouse();
		setcolor(WHITE);
		rectangle(0,20,getmaxx(),getmaxy()-20);
		setcolor(GREEN);
		rectangle(20,40,getmaxx()-20,getmaxy()-40);


	 //option
	 {
		setcolor(BLUE);
		settextstyle(1,0,1);
		outtextxy(40,50,"Instructions");
		line(40,70,148,70);
		outtextxy(560,50,"Quit");
		line(560,70,598,70);
		setcolor(7);
		line(getmaxx()-30,150,getmaxx()-40,130); //next
		line(getmaxx()-30,150,getmaxx()-40,170);
	 }


	//LOGO
	{
		setcolor(WHITE);
		circle(330,145,70);
		setfillstyle(10,RED);
		floodfill(340,150,WHITE);
		circle(330,145,80);
		setfillstyle(1,WHITE);
		floodfill(280,85,WHITE);

		settextstyle(4,0,10);
		setcolor(BLUE);
		outtextxy(270,40,"P");
		setcolor(GREEN);
		outtextxy(310,70,"Q");
	}


	//Question boxes
	{
		setcolor(BLUE);
		rectangle(60,250,580,300);  //ques
		setcolor(WHITE);
		line(60,245,580,245);       //line1
		line(60,305,580,305); 	    //line2
		setcolor(GREEN);
		rectangle(60,330,300,360);  //ans1
		rectangle(340,330,580,360); //ans2
		rectangle(60,380,300,410);  //ans3
		rectangle(340,380,580,410); //ans4
	}
	setcolor(WHITE);
	settextstyle(7,0,1);

	//questions

	{
		fin.open("2.txt");
		fin.getline(que1,52);      //question1
		outtextxy(70,250,que1);
		fin.getline(que2,50);      //question2
		outtextxy(85,270,que2);
		fin.close();

		fin.open("2a.txt");
		fin.getline(ans,21);
		outtextxy(70,332,ans);
		fin.close();

		fin.open("2b.txt");
		fin.getline(ans,21);
		outtextxy(350,332,ans);
		fin.close();

		fin.open("2c.txt");
		fin.getline(ans,21);
		outtextxy(70,383,ans);
		fin.close();

		fin.open("2d.txt");
		fin.getline(ans,21);
		outtextxy(350,383,ans);
		fin.close();
	}

	i=1;

	while(!kbhit())
	{
		int x,y,button;

		in.x.ax=3;
		int86(0X33,&in,&out);

		button=out.x.bx&7;

		switch(button)
		{
			case 1:
			case 3: x=out.x.cx;
				y=out.x.dx;
				break;
		}

		if((x>=getmaxx()-40)&&(x<=getmaxx()-30)&&(y>=130)&&(y<=170))
		{
			cleardevice();
			setcolor(WHITE);
			outtextxy(220,200,"Proceed further ???");
			outtextxy(250,250,"...Continue...");
			getch();
			show_ques3();
		}

		back=2;
		choice(x,y);
	}

}


void quiz::show_ques3()                 //question 3
{
		cleardevice();
		show_mouse();
		setcolor(WHITE);
		rectangle(0,20,getmaxx(),getmaxy()-20);
		setcolor(GREEN);
		rectangle(20,40,getmaxx()-20,getmaxy()-40);


	 //option
	 {
		setcolor(BLUE);
		settextstyle(1,0,1);
		outtextxy(40,50,"Instructions");
		line(40,70,148,70);
		outtextxy(560,50,"Quit");
		line(560,70,598,70);
		setcolor(7);
		line(getmaxx()-30,150,getmaxx()-40,130); //next
		line(getmaxx()-30,150,getmaxx()-40,170);
	 }


	//LOGO
	{
		setcolor(WHITE);
		circle(330,145,70);
		setfillstyle(10,RED);
		floodfill(340,150,WHITE);
		circle(330,145,80);
		setfillstyle(1,WHITE);
		floodfill(280,85,WHITE);

		settextstyle(4,0,10);
		setcolor(BLUE);
		outtextxy(270,40,"P");
		setcolor(GREEN);
		outtextxy(310,70,"Q");
	}


	//Question boxes
	{
		setcolor(BLUE);
		rectangle(60,250,580,300);  //ques
		setcolor(WHITE);
		line(60,245,580,245);       //line1
		line(60,305,580,305); 	    //line2
		setcolor(GREEN);
		rectangle(60,330,300,360);  //ans1
		rectangle(340,330,580,360); //ans2
		rectangle(60,380,300,410);  //ans3
		rectangle(340,380,580,410); //ans4
	}
	setcolor(WHITE);
	settextstyle(7,0,1);

	//questions

	{
		fin.open("3.txt");
		fin.getline(que1,52);      //question1
		outtextxy(70,250,que1);
		fin.getline(que2,50);      //question2
		outtextxy(85,270,que2);
		fin.close();

		fin.open("3a.txt");
		fin.getline(ans,21);
		outtextxy(70,332,ans);
		fin.close();

		fin.open("3b.txt");
		fin.getline(ans,21);
		outtextxy(350,332,ans);
		fin.close();

		fin.open("3c.txt");
		fin.getline(ans,21);
		outtextxy(70,383,ans);
		fin.close();

		fin.open("3d.txt");
		fin.getline(ans,21);
		outtextxy(350,383,ans);
		fin.close();
	}

	i=2;

	while(!kbhit())
	{
		int x,y,button;

		in.x.ax=3;
		int86(0X33,&in,&out);

		button=out.x.bx&7;

		switch(button)
		{
			case 1:
			case 3: x=out.x.cx;
				y=out.x.dx;
				break;
		}

		if((x>=getmaxx()-40)&&(x<=getmaxx()-30)&&(y>=130)&&(y<=170))
		{
			cleardevice();
			setcolor(WHITE);
			outtextxy(200,200,"You are doing good !!!");
			outtextxy(250,250,"...Carry on...");
			getch();
			show_ques4();
		}

		back=3;
		choice(x,y);
	}

}


void quiz::show_ques4()                //question 4
{
		cleardevice();
		show_mouse();
		setcolor(WHITE);
		rectangle(0,20,getmaxx(),getmaxy()-20);
		setcolor(GREEN);
		rectangle(20,40,getmaxx()-20,getmaxy()-40);


	 //option
	 {
		setcolor(BLUE);
		settextstyle(1,0,1);
		outtextxy(40,50,"Instructions");
		line(40,70,148,70);
		outtextxy(560,50,"Quit");
		line(560,70,598,70);
		setcolor(7);
		line(getmaxx()-30,150,getmaxx()-40,130); //next
		line(getmaxx()-30,150,getmaxx()-40,170);
	 }


	//LOGO
	{
		setcolor(WHITE);
		circle(330,145,70);
		setfillstyle(10,RED);
		floodfill(340,150,WHITE);
		circle(330,145,80);
		setfillstyle(1,WHITE);
		floodfill(280,85,WHITE);

		settextstyle(4,0,10);
		setcolor(BLUE);
		outtextxy(270,40,"P");
		setcolor(GREEN);
		outtextxy(310,70,"Q");
	}


	//Question boxes
	{
		setcolor(BLUE);
		rectangle(60,250,580,300);  //ques
		setcolor(WHITE);
		line(60,245,580,245);       //line1
		line(60,305,580,305); 	    //line2
		setcolor(GREEN);
		rectangle(60,330,300,360);  //ans1
		rectangle(340,330,580,360); //ans2
		rectangle(60,380,300,410);  //ans3
		rectangle(340,380,580,410); //ans4
	}
	setcolor(WHITE);
	settextstyle(7,0,1);

	//questions
	{
		fin.open("4.txt");
		fin.getline(que1,52);      //question1
		outtextxy(70,250,que1);
		fin.getline(que2,50);      //question2
		outtextxy(85,270,que2);
		fin.close();

		fin.open("4a.txt");
		fin.getline(ans,21);
		outtextxy(70,332,ans);
		fin.close();

		fin.open("4b.txt");
		fin.getline(ans,21);
		outtextxy(350,332,ans);
		fin.close();

		fin.open("4c.txt");
		fin.getline(ans,21);
		outtextxy(70,383,ans);
		fin.close();

		fin.open("4d.txt");
		fin.getline(ans,21);
		outtextxy(350,383,ans);
		fin.close();
	}

	i=3;


	while(!kbhit())
	{
		int x,y,button;

		in.x.ax=3;
		int86(0X33,&in,&out);

		button=out.x.bx&7;

		switch(button)
		{
			case 1:
			case 3: x=out.x.cx;
				y=out.x.dx;
				break;
		}

		if((x>=getmaxx()-40)&&(x<=getmaxx()-30)&&(y>=130)&&(y<=170))
		{
			cleardevice();
			setcolor(WHITE);
			outtextxy(150,200,"You are born for programming!!!");
			outtextxy(270,250,"...Go On...");
			getch();
			show_ques5();
		}

		back=4;
		choice(x,y);
	}

}



void quiz::show_ques5()                  //question 5
{
		cleardevice();
		show_mouse();
		setcolor(WHITE);
		rectangle(0,20,getmaxx(),getmaxy()-20);
		setcolor(GREEN);
		rectangle(20,40,getmaxx()-20,getmaxy()-40);


	 //option
	 {
		setcolor(BLUE);
		settextstyle(1,0,1);
		outtextxy(40,50,"Instructions");
		line(40,70,148,70);
		outtextxy(560,50,"Quit");
		line(560,70,598,70);
		setcolor(7);
		line(getmaxx()-30,150,getmaxx()-40,130); //next
		line(getmaxx()-30,150,getmaxx()-40,170);
	 }


	//LOGO
	{
		setcolor(WHITE);
		circle(330,145,70);
		setfillstyle(10,RED);
		floodfill(340,150,WHITE);
		circle(330,145,80);
		setfillstyle(1,WHITE);
		floodfill(280,85,WHITE);

		settextstyle(4,0,10);
		setcolor(BLUE);
		outtextxy(270,40,"P");
		setcolor(GREEN);
		outtextxy(310,70,"Q");
	}


	//Question boxes
	{
		setcolor(BLUE);
		rectangle(60,250,580,300);  //ques
		setcolor(WHITE);
		line(60,245,580,245);       //line1
		line(60,305,580,305); 	    //line2
		setcolor(GREEN);
		rectangle(60,330,300,360);  //ans1
		rectangle(340,330,580,360); //ans2
		rectangle(60,380,300,410);  //ans3
		rectangle(340,380,580,410); //ans4
	}
	setcolor(WHITE);
	settextstyle(7,0,1);

	//questions

	{
		fin.open("5.txt");
		fin.getline(que1,52);      //question1
		outtextxy(70,250,que1);
		fin.getline(que2,50);      //question2
		outtextxy(85,270,que2);
		fin.close();

		fin.open("5a.txt");
		fin.getline(ans,21);
		outtextxy(70,332,ans);
		fin.close();

		fin.open("5b.txt");
		fin.getline(ans,21);
		outtextxy(350,332,ans);
		fin.close();

		fin.open("5c.txt");
		fin.getline(ans,21);
		outtextxy(70,383,ans);
		fin.close();

		fin.open("5d.txt");
		fin.getline(ans,21);
		outtextxy(350,383,ans);
		fin.close();
	}

	i=4;

	while(!kbhit())
	{
		int x,y,button;

		in.x.ax=3;
		int86(0X33,&in,&out);

		button=out.x.bx&7;

		switch(button)
		{
			case 1:
			case 3: x=out.x.cx;
				y=out.x.dx;
				break;
		}

		if((x>=getmaxx()-40)&&(x<=getmaxx()-30)&&(y>=130)&&(y<=170))
		{
			cleardevice();
			setcolor(WHITE);
			outtextxy(140,200,"Looking like you are getting interested !!!");
			outtextxy(230,250,"...So...to the next question...");
			getch();
			show_ques6();
		}

		back=5;
		choice(x,y);
	}

}



void quiz::show_ques6()                //question 6
{
		cleardevice();
		show_mouse();
		setcolor(WHITE);
		rectangle(0,20,getmaxx(),getmaxy()-20);
		setcolor(GREEN);
		rectangle(20,40,getmaxx()-20,getmaxy()-40);


	 //option
	 {
		setcolor(BLUE);
		settextstyle(1,0,1);
		outtextxy(40,50,"Instructions");
		line(40,70,148,70);
		outtextxy(560,50,"Quit");
		line(560,70,598,70);
		setcolor(7);
		line(getmaxx()-30,150,getmaxx()-40,130); //next
		line(getmaxx()-30,150,getmaxx()-40,170);
	 }


	//LOGO
	{
		setcolor(WHITE);
		circle(330,145,70);
		setfillstyle(10,RED);
		floodfill(340,150,WHITE);
		circle(330,145,80);
		setfillstyle(1,WHITE);
		floodfill(280,85,WHITE);

		settextstyle(4,0,10);
		setcolor(BLUE);
		outtextxy(270,40,"P");
		setcolor(GREEN);
		outtextxy(310,70,"Q");
	}


	//Question boxes
	{
		setcolor(BLUE);
		rectangle(60,250,580,300);  //ques
		setcolor(WHITE);
		line(60,245,580,245);       //line1
		line(60,305,580,305); 	    //line2
		setcolor(GREEN);
		rectangle(60,330,300,360);  //ans1
		rectangle(340,330,580,360); //ans2
		rectangle(60,380,300,410);  //ans3
		rectangle(340,380,580,410); //ans4
	}
	setcolor(WHITE);
	settextstyle(7,0,1);

	//questions

	{
		fin.open("6.txt");
		fin.getline(que1,52);      //question1
		outtextxy(70,250,que1);
		fin.getline(que2,50);      //question2
		outtextxy(85,270,que2);
		fin.close();

		fin.open("6a.txt");
		fin.getline(ans,21);
		outtextxy(70,332,ans);
		fin.close();

		fin.open("6b.txt");
		fin.getline(ans,21);
		outtextxy(350,332,ans);
		fin.close();

		fin.open("6c.txt");
		fin.getline(ans,21);
		outtextxy(70,383,ans);
		fin.close();

		fin.open("6d.txt");
		fin.getline(ans,21);
		outtextxy(350,383,ans);
		fin.close();
	}

	i=5;

	while(!kbhit())
	{
		int x,y,button;

		in.x.ax=3;
		int86(0X33,&in,&out);

		button=out.x.bx&7;

		switch(button)
		{
			case 1:
			case 3: x=out.x.cx;
				y=out.x.dx;
				break;
		}

		if((x>=getmaxx()-40)&&(x<=getmaxx()-30)&&(y>=130)&&(y<=170))
		{
			cleardevice();
			setcolor(WHITE);
			outtextxy(170,200,"Its not that tough...huh ???");
			outtextxy(250,250,"...Go make it...");
			getch();
			show_ques7();
		}

		back=6;
		choice(x,y);
	}

}



void quiz::show_ques7()               //question 7
{
		cleardevice();
		show_mouse();
		setcolor(WHITE);
		rectangle(0,20,getmaxx(),getmaxy()-20);
		setcolor(GREEN);
		rectangle(20,40,getmaxx()-20,getmaxy()-40);


	 //option
	 {
		setcolor(BLUE);
		settextstyle(1,0,1);
		outtextxy(40,50,"Instructions");
		line(40,70,148,70);
		outtextxy(560,50,"Quit");
		line(560,70,598,70);
		setcolor(7);
		line(getmaxx()-30,150,getmaxx()-40,130); //next
		line(getmaxx()-30,150,getmaxx()-40,170);
	 }


	//LOGO
	{
		setcolor(WHITE);
		circle(330,145,70);
		setfillstyle(10,RED);
		floodfill(340,150,WHITE);
		circle(330,145,80);
		setfillstyle(1,WHITE);
		floodfill(280,85,WHITE);

		settextstyle(4,0,10);
		setcolor(BLUE);
		outtextxy(270,40,"P");
		setcolor(GREEN);
		outtextxy(310,70,"Q");
	}


	//Question boxes
	{
		setcolor(BLUE);
		rectangle(60,250,580,300);  //ques
		setcolor(WHITE);
		line(60,245,580,245);       //line1
		line(60,305,580,305); 	    //line2
		setcolor(GREEN);
		rectangle(60,330,300,360);  //ans1
		rectangle(340,330,580,360); //ans2
		rectangle(60,380,300,410);  //ans3
		rectangle(340,380,580,410); //ans4
	}
	setcolor(WHITE);
	settextstyle(7,0,1);

	//questions

	{
		fin.open("7.txt");
		fin.getline(que1,52);      //question1
		outtextxy(70,250,que1);
		fin.getline(que2,50);      //question2
		outtextxy(85,270,que2);
		fin.close();

		fin.open("7a.txt");
		fin.getline(ans,21);
		outtextxy(70,332,ans);
		fin.close();

		fin.open("7b.txt");
		fin.getline(ans,21);
		outtextxy(350,332,ans);
		fin.close();

		fin.open("7c.txt");
		fin.getline(ans,21);
		outtextxy(70,383,ans);
		fin.close();

		fin.open("7d.txt");
		fin.getline(ans,21);
		outtextxy(350,383,ans);
		fin.close();
	}

	i=6;

	while(!kbhit())
	{
		int x,y,button;

		in.x.ax=3;
		int86(0X33,&in,&out);

		button=out.x.bx&7;

		switch(button)
		{
			case 1:
			case 3: x=out.x.cx;
				y=out.x.dx;
				break;
		}

		if((x>=getmaxx()-40)&&(x<=getmaxx()-30)&&(y>=130)&&(y<=170))
		{
			cleardevice();
			setcolor(WHITE);
			outtextxy(150,200,"It was a good question...Wasn't it ???");
			outtextxy(250,250,"...See the next one...");
			getch();
			show_ques8();
		}

		back=7;
		choice(x,y);
	}

}



void quiz::show_ques8()                //question 8
{
		cleardevice();
		show_mouse();
		setcolor(WHITE);
		rectangle(0,20,getmaxx(),getmaxy()-20);
		setcolor(GREEN);
		rectangle(20,40,getmaxx()-20,getmaxy()-40);


	 //option
	 {
		setcolor(BLUE);
		settextstyle(1,0,1);
		outtextxy(40,50,"Instructions");
		line(40,70,148,70);
		outtextxy(560,50,"Quit");
		line(560,70,598,70);
		setcolor(7);
		line(getmaxx()-30,150,getmaxx()-40,130); //next
		line(getmaxx()-30,150,getmaxx()-40,170);
	 }


	//LOGO
	{
		setcolor(WHITE);
		circle(330,145,70);
		setfillstyle(10,RED);
		floodfill(340,150,WHITE);
		circle(330,145,80);
		setfillstyle(1,WHITE);
		floodfill(280,85,WHITE);

		settextstyle(4,0,10);
		setcolor(BLUE);
		outtextxy(270,40,"P");
		setcolor(GREEN);
		outtextxy(310,70,"Q");
	}


	//Question boxes
	{
		setcolor(BLUE);
		rectangle(60,250,580,300);  //ques
		setcolor(WHITE);
		line(60,245,580,245);       //line1
		line(60,305,580,305); 	    //line2
		setcolor(GREEN);
		rectangle(60,330,300,360);  //ans1
		rectangle(340,330,580,360); //ans2
		rectangle(60,380,300,410);  //ans3
		rectangle(340,380,580,410); //ans4
	}
	setcolor(WHITE);
	settextstyle(7,0,1);

	//questions

	{
		fin.open("8.txt");
		fin.getline(que1,52);      //question1
		outtextxy(70,250,que1);
		fin.getline(que2,50);      //question2
		outtextxy(85,270,que2);
		fin.close();

		fin.open("8a.txt");
		fin.getline(ans,21);
		outtextxy(70,332,ans);
		fin.close();

		fin.open("8b.txt");
		fin.getline(ans,21);
		outtextxy(350,332,ans);
		fin.close();

		fin.open("8c.txt");
		fin.getline(ans,21);
		outtextxy(70,383,ans);
		fin.close();

		fin.open("8d.txt");
		fin.getline(ans,21);
		outtextxy(350,383,ans);
		fin.close();
	}

	i=7;

	while(!kbhit())
	{
		int x,y,button;

		in.x.ax=3;
		int86(0X33,&in,&out);

		button=out.x.bx&7;

		switch(button)
		{
			case 1:
			case 3: x=out.x.cx;
				y=out.x.dx;
				break;
		}

		if((x>=getmaxx()-40)&&(x<=getmaxx()-30)&&(y>=130)&&(y<=170))
		{
			cleardevice();
			setcolor(WHITE);
			outtextxy(180,200,"Very near to the end !!!");
			outtextxy(260,250,"...Hit it...");
			getch();
			show_ques9();
		}

		back=8;
		choice(x,y);
	}

}



void quiz::show_ques9()            //question 9
{
		cleardevice();
		show_mouse();
		setcolor(WHITE);
		rectangle(0,20,getmaxx(),getmaxy()-20);
		setcolor(GREEN);
		rectangle(20,40,getmaxx()-20,getmaxy()-40);


	 //option
	 {
		setcolor(BLUE);
		settextstyle(1,0,1);
		outtextxy(40,50,"Instructions");
		line(40,70,148,70);
		outtextxy(560,50,"Quit");
		line(560,70,598,70);
		setcolor(7);
		line(getmaxx()-30,150,getmaxx()-40,130); //next
		line(getmaxx()-30,150,getmaxx()-40,170);
	 }


	//LOGO
	{
		setcolor(WHITE);
		circle(330,145,70);
		setfillstyle(10,RED);
		floodfill(340,150,WHITE);
		circle(330,145,80);
		setfillstyle(1,WHITE);
		floodfill(280,85,WHITE);

		settextstyle(4,0,10);
		setcolor(BLUE);
		outtextxy(270,40,"P");
		setcolor(GREEN);
		outtextxy(310,70,"Q");
	}


	//Question boxes
	{
		setcolor(BLUE);
		rectangle(60,250,580,300);  //ques
		setcolor(WHITE);
		line(60,245,580,245);       //line1
		line(60,305,580,305); 	    //line2
		setcolor(GREEN);
		rectangle(60,330,300,360);  //ans1
		rectangle(340,330,580,360); //ans2
		rectangle(60,380,300,410);  //ans3
		rectangle(340,380,580,410); //ans4
	}
	setcolor(WHITE);
	settextstyle(7,0,1);

	//questions

	{
		fin.open("9.txt");
		fin.getline(que1,52);      //question1
		outtextxy(70,250,que1);
		fin.getline(que2,50);      //question2
		outtextxy(85,270,que2);
		fin.close();

		fin.open("9a.txt");
		fin.getline(ans,21);
		outtextxy(70,332,ans);
		fin.close();

		fin.open("9b.txt");
		fin.getline(ans,21);
		outtextxy(350,332,ans);
		fin.close();

		fin.open("9c.txt");
		fin.getline(ans,21);
		outtextxy(70,383,ans);
		fin.close();

		fin.open("9d.txt");
		fin.getline(ans,21);
		outtextxy(350,383,ans);
		fin.close();
	}

	i=8;

	while(!kbhit())
	{
		int x,y,button;

		in.x.ax=3;
		int86(0X33,&in,&out);

		button=out.x.bx&7;

		switch(button)
		{
			case 1:
			case 3: x=out.x.cx;
				y=out.x.dx;
				break;
		}

		if((x>=getmaxx()-40)&&(x<=getmaxx()-30)&&(y>=130)&&(y<=170))
		{
			cleardevice();
			setcolor(WHITE);
			outtextxy(160,200,"Now the final question .....");
			outtextxy(260,250,"...Grab it...");
			getch();
			show_ques10();
		}

		back=9;
		choice(x,y);
	}

}



void quiz::show_ques10()                      //question 10
{
		cleardevice();
		show_mouse();
		setcolor(WHITE);
		rectangle(0,20,getmaxx(),getmaxy()-20);
		setcolor(GREEN);
		rectangle(20,40,getmaxx()-20,getmaxy()-40);


	 //option
	 {
		setcolor(BLUE);
		settextstyle(1,0,1);
		outtextxy(40,50,"Instructions");
		line(40,70,148,70);
		outtextxy(560,50,"Quit");
		line(560,70,598,70);
		setcolor(7);
		line(getmaxx()-30,150,getmaxx()-40,130); //next
		line(getmaxx()-30,150,getmaxx()-40,170);
		outtextxy(getmaxx()-105,137,"RESULT");
	 }


	//LOGO
	{
		setcolor(WHITE);
		circle(330,145,70);
		setfillstyle(10,RED);
		floodfill(340,150,WHITE);
		circle(330,145,80);
		setfillstyle(1,WHITE);
		floodfill(280,85,WHITE);

		settextstyle(4,0,10);
		setcolor(BLUE);
		outtextxy(270,40,"P");
		setcolor(GREEN);
		outtextxy(310,70,"Q");
	}


	//Question boxes
	{
		setcolor(BLUE);
		rectangle(60,250,580,300);  //ques
		setcolor(WHITE);
		line(60,245,580,245);       //line1
		line(60,305,580,305); 	    //line2
		setcolor(GREEN);
		rectangle(60,330,300,360);  //ans1
		rectangle(340,330,580,360); //ans2
		rectangle(60,380,300,410);  //ans3
		rectangle(340,380,580,410); //ans4
	}
	setcolor(WHITE);
	settextstyle(7,0,1);

	//questions

	{
		fin.open("10.txt");
		fin.getline(que1,52);      //question1
		outtextxy(70,250,que1);
		fin.getline(que2,50);      //question2
		outtextxy(85,270,que2);
		fin.close();

		fin.open("10a.txt");
		fin.getline(ans,21);
		outtextxy(70,332,ans);
		fin.close();

		fin.open("10b.txt");
		fin.getline(ans,21);
		outtextxy(350,332,ans);
		fin.close();

		fin.open("10c.txt");
		fin.getline(ans,21);
		outtextxy(70,383,ans);
		fin.close();

		fin.open("10d.txt");
		fin.getline(ans,21);
		outtextxy(350,383,ans);
		fin.close();
	}

	i=9;

	while(!kbhit())
	{
		int x,y,button;

		in.x.ax=3;
		int86(0X33,&in,&out);

		button=out.x.bx&7;

		switch(button)
		{
			case 1:
			case 3: x=out.x.cx;
				y=out.x.dx;
				break;
		}

		if((x>=getmaxx()-150)&&(x<=getmaxx()-30)&&(y>=130)&&(y<=170))
		score();

		back=10;
		choice(x,y);
	}


}



void quiz::choice(int x,int y)       //taking input
{


		if((x>=60)&&(x<=300)&&(y>=330)&&(y<=360))
		{
			option[i]='a';
			setcolor(WHITE);
			rectangle(60,330,300,360);

			setcolor(GREEN);
			rectangle(340,330,580,360);
			rectangle(60,380,300,410);
			rectangle(340,380,580,410);

		}
		else if((x>=340)&&(x<=580)&&(y>=330)&&(y<=360))
		{
			option[i]='b';
			setcolor(WHITE);
			rectangle(340,330,580,360);

			setcolor(GREEN);
			rectangle(60,330,300,360);
			rectangle(60,380,300,410);
			rectangle(340,380,580,410);

		}
		else if((x>=60)&&(x<=300)&&(y>=380)&&(y<=410))
		{
			option[i]='c';
			setcolor(WHITE);
			rectangle(60,380,300,410);

			setcolor(GREEN);
			rectangle(60,330,300,360);
			rectangle(340,330,580,360);
			rectangle(340,380,580,410);

		}
		else if((x>=340)&&(x<=580)&&(y>=380)&&(y<=410))
		{
			option[i]='d';
			setcolor(WHITE);
			rectangle(340,380,580,410);

			setcolor(GREEN);
			rectangle(60,330,300,360);
			rectangle(340,330,580,360);
			rectangle(60,380,300,410);

		}

		else if((x>=40)&&(x<=148)&&(y>=50)&&(y<=70))
		{
			instructions();
		}

		else if((x>=560)&&(x<=598)&&(y>=50)&&(y<=70))
		{
			thanks();
		}


}


void quiz::score()           //checking result
{
		cleardevice();
		setcolor(WHITE);
		outtextxy(160,200,"READY TO SEE THE SCORE ???");
		outtextxy(260,250,"GO FOR IT");
		getch();

		cleardevice();
		show_mouse();
		setcolor(WHITE);
		rectangle(0,20,getmaxx(),getmaxy()-20);
		setcolor(GREEN);
		rectangle(20,40,getmaxx()-20,getmaxy()-40);
		line(140,40,140,getmaxy()-40);
		setcolor(BLUE);
		settextstyle(1,1,9);
		outtextxy(20,70,"RESULT");
		setcolor(WHITE);
		settextstyle(1,0,4);
		outtextxy(250,340,"OUT OF 50");
		settextstyle(1,0,2);
		outtextxy(231,400,"Press Enter to EXIT");

		total=0;
		char answer[10]={'a','b','a','b','c','b','d','a','b','a'};


		for(int j=0;j<10;j++)
		{
			tolower(option[j]);

			if(option[j]==answer[j])
			{
				total+=1;
			}
		}

	if(total<=4)
	{
		setcolor(WHITE);
		circle(330,265,70);
		setfillstyle(10,RED);
		floodfill(340,270,WHITE);
		circle(330,265,80);
		setfillstyle(1,WHITE);
		floodfill(280,205,WHITE);
		setcolor(RED);
		settextstyle(1,0,5);
		outtextxy(200,100,"YOU SCORED:");
		setcolor(WHITE);
		settextstyle(10,0,6);

		switch(total)
		{
			case 0:	outtextxy(310,195,"0");
				break;
			case 1: outtextxy(310,195,"5");
				break;
			case 2: outtextxy(285,195,"10");
				break;
			case 3: outtextxy(285,195,"15");
				break;
			case 4:	outtextxy(285,195,"20");
				break;
		}

	}
	else
	{
		setcolor(WHITE);
		circle(330,265,70);
		setfillstyle(10,GREEN);
		floodfill(340,270,WHITE);
		circle(330,265,80);
		setfillstyle(1,WHITE);
		floodfill(280,205,WHITE);
		setcolor(GREEN);
		settextstyle(1,0,5);
		outtextxy(200,100,"YOU SCORED:");
		setcolor(WHITE);
		settextstyle(10,0,6);

		switch(total)
		{
			case 5: outtextxy(285,195,"25");
				break;
			case 6: outtextxy(285,195,"30");
				break;
			case 7: outtextxy(285,195,"35");
				break;
			case 8: outtextxy(285,195,"40");
				break;
			case 9: outtextxy(285,195,"45");
				break;
			case 10: outtextxy(285,195,"50");
				break;
		}

	}

	getch();

	thanks();
}

void quiz::thanks()                 //last page
{
	cleardevice();

	rectangle(0,20,getmaxx(),getmaxy()-20);
	rectangle(20,40,getmaxx()-20,getmaxy()-40);

	settextstyle(7,0,3);
	outtextxy(50,250,"THANK YOU");
	settextstyle(6,0,1);
	outtextxy(50,270,"PRESS ENTER...");
	getch();

	circle(400,250,150);
	getch();

	circle(267,100,50);
	circle(532,100,50);
	getch();

	circle(320,200,20);
	circle(480,200,20);
	circle(400,250,10);
	getch();

	arc(400,100,199,341,100);
	arc(400,250,230,310,80);
	settextstyle(6,0,1);
	outtextxy(50,400,"PRESS END ...");
	getch();
	closegraph();
}



void main()
{
	clrscr();
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"C:\\TC\\BGI");

	class quiz user;

	user.logo();

	getch();
	closegraph();

}