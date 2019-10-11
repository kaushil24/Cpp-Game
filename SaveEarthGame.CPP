#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>
#include<dos.h>
#include<stdlib.h>
int xShip, yShip;
int xBul, yBul;
int xObj = 100;
int yObj = 100;
int objH;
int radObj = 10;
int radShip=15;
int xMax;
int yMax;
int xStars[75], yStars[75];
float ip;
int kIp;
void news();
void spaceX();
void dispShipComp();
void moveShip();
void shootBul();
void objPlace(int r=radObj);
int objKill(int, int, int, int);
void objNew();
void destObj();
void showAll(int cho=1);
void litStars();
double scr = -1;
//void litStarsNew();
void news()
{

   int x = getmaxx();
   int y = getmaxy();
   rectangle(0,0,x,y);
   rectangle(25,25,x-25,y-25);
   setfillstyle(SOLID_FILL, BROWN);
   floodfill(1,1,15);
   setfillstyle(SOLID_FILL, CYAN);
   floodfill(26,26,15);
   settextstyle(0, 0, 4);
   outtextxy(150,100,"N");
   delay(550);
   outtextxy(250,100,"E");
   delay(550);
   outtextxy(350,100,"W");
   delay(550);
   outtextxy(450,100,"S");
   settextstyle(0,0,3);
   //settextjustify("CENTER_TEXT", "CENTER_TEXT");
   setcolor(RED);
   delay(1000);
   //circle(100,100,50);
   outtextxy(165,200,"ATTENTION!!!");
   delay(1000);
   settextstyle(0,0,2);
   setcolor(YELLOW);
   outtextxy(60, 250, "MAJOR ASTROID SHOWER TO HIT EARTH");
   delay(1000);
   outtextxy(125, 300, "HUMANITY MAY EXTINT :)");
   delay(500);
   setcolor(BLUE);
   circle(getmaxx()/2-10,390,50);
   delay(1000);
   setcolor(BLUE);
   setfillstyle(1, BLUE);
   floodfill(getmaxx()/2-9, 388, BLUE);
   setcolor(GREEN);
   circle(getmaxx()/2-5,410,25);
   setfillstyle(1, GREEN);
   floodfill(getmaxx()/2-4, 411, GREEN);
   delay(1000);
}
void spaceX()
{  int ssx, ssy;
   ssx = getmaxx();
   ssy = getmaxy() - 90;
   rectangle(0,0,ssx,ssy);
   //setcolor(CYAN);
   setfillstyle(1,CYAN);
   floodfill(10,10, getmaxcolor());
   setcolor(BROWN);
   line(0,215+50,55,95+50);
   line(55,95+50,ssx-55,95+50);
   line(ssx,215+50,ssx-55,95+50);
   setcolor(LIGHTBLUE);
   line(55,95+50,55,0);
   line(ssx-55,95+50,ssx-55,0);
   setfillstyle(1,BROWN);
   floodfill(getmaxx()/2,getmaxy()/2,BROWN);
   setcolor(15);
   rectangle(0,ssy-30,getmaxx(),getmaxy());
   setfillstyle(1,BLACK);
   floodfill(ssx-20,getmaxy()-20,getmaxcolor());
   rectangle((getmaxx()/2)-95 ,110,95 + getmaxx()/2,230);
   setfillstyle(1,BLACK);
   floodfill(85+getmaxx()/2, 210, getmaxcolor());
   rectangle((getmaxx()/2)-110, 95, 110+getmaxx()/2, 245);
   setfillstyle(1, LIGHTGRAY);
   floodfill((getmaxx()/2)-109, 96, getmaxcolor());
   setfillstyle(1,MAGENTA);
   bar((getmaxx()/2)-10, 247, 10+getmaxx()/2, 275);
   fillellipse(getmaxx()/2, 275,50,10);
   delay(1000);
   settextstyle(0,0,2);
   outtextxy(10,ssy+10,"ELON MUSK: Hmm..I'll design SpaceShip & ...");
   delay(1000);
   settextstyle(0,0,3);
   outtextxy(10,ssy+40,"SAVE HUMANITY AGAIN!!!");
   dispShipComp();
   settextstyle(0,0,2);
   setcolor(BLUE);
   outtextxy(getmaxx()/2 - 40, getmaxy()/2 - 105, "SpaceX");
   delay(3500);
}
void dispShipComp()
{
   int sang, rang;
   sang=0;
   rang=180;
   setcolor(15);
   int x,y,rad;
   x = getmaxx()/2;
   y=(getmaxy()/2)-50;
   rad = 20;
   arc(x,y,sang,rang, rad);
   line(x-rad,y,x+rad,y);
   setfillstyle(SOLID_FILL, 3);
   floodfill(x+1,y-1,15);
   line(x-rad,y,x-rad-12,y+8);
   line(x+rad,y,x+rad+12,y+8);
   line(x-rad-12,y+8,x+rad+12,y+8);
   setfillstyle(SOLID_FILL, 7);
   floodfill(x,y+3,15);
}
void main()
{
   int gdriver = DETECT, gmode, errorcode;
   initgraph(&gdriver, &gmode, "");
   xShip=50;
   yShip=50;
   xMax = getmaxx();
   yMax = getmaxy();
   news();
   delay(1000);
   cleardevice();
   spaceX();
   delay(1000);
   cleardevice();
   int i=0;
 /*   cout<<"--------------------------------------------------------------------------------------------------------------------------\n";
     cout<<"The Lit A.F. Ultimate Battle SpaceShip Game... \n";
     cout<<"--------------------------------------------------------------------------------------------------------------------------\n";
     cout<<"Enter any key to start:\n";
     getch();  */
     settextstyle(0,0,1);
    outtextxy(10,10,"Instructions:(Press Any key to go to next instruction)");
    getch();
    outtextxy(20, 30,"* Kill as many astroids as you can, before time runs out.");
    getch();
    outtextxy(20, 50, "* Musk has used special concentrated laser beams to destroy asteroids.");
    getch();
    outtextxy(20, 70,"* The farther the lasers are shot, the more damage they'll make");
    getch();
    outtextxy(20, 90,"* Press 'Esc' anytime to exit.");
    getch();
    outtextxy(20, 90, "Press any key to SAVE HUMAN-SPECIES");
    objNew();
  //litStarsNew();
    struct  time t;
   struct time t2;
   gettime(&t);
   int chcnt = t.ti_sec;
   chcnt+=30;
   if(chcnt>60)
	chcnt=chcnt-60;
   int tcnt = t.ti_sec;
   while(tcnt!=chcnt)
   {
      showAll();
      gettime(&t2);
	tcnt = t2.ti_sec;
      //objH = 1000;
      //objPlace();
     //circle(xShip, yShip, radShip);
    if(kbhit)
    {
      ip=getch();
      kIp = int(ip);
      if(kIp==27)
      {
	  break;
      }
      else
      {
	   if(kIp>=72 && kIp<=81)
	   {
	      moveShip();
	   }

	   else if(kIp>=97 && kIp<=119)
	   {
	       shootBul();
	   }
	   else
	   {
		continue;
	   }
      }
    }
     else
     {
	 showAll();//circle(xShip, yShip, radShip);
     }

     delay(15);
     cleardevice();
   }
   outtextxy(350,250, "GAME OVER !!!!!");
   getch();
   cleardevice();
   settextstyle(0,0,4);
   cout<<"Your score is; "<<scr;
   delay(3500);
   getch();
   closegraph();

}
void moveShip()
{
	if(kIp==75)
	{  xShip=xShip-10;
	   if(xShip<=radShip)
	   {  xShip=radShip;
	   }
	 }
	else if(kIp==72)
	 {  yShip=yShip-10;
	    if(yShip<=radShip)
	    {
	       yShip=radShip;
	    }
	 }
	else if(kIp==77)
	 {   xShip=xShip+10;
	     if(xShip>=xMax-radShip)
	     {
		xShip=xMax-radShip;
	     }
	 }
	else if(kIp==80)
	  {   yShip=yShip+10;
	      if(yShip>=yMax-radShip)
	      {
		 yShip=yMax-radShip;
	      }
	  }
	 showAll(); //circle(xShip,yShip, radShip);

}

void dispShip()
{
   int sang, rang;
   sang=0;
   rang=180;
   setcolor(15);
   int x,y,rad;
   x = xShip;
   y=yShip;
   rad = radShip;
   arc(x,y,sang,rang, rad);
   line(x-rad,y,x+rad,y);
   setfillstyle(SOLID_FILL, 3);
   floodfill(x+1,y-1,15);
   line(x-rad,y,x-rad-8,y+5);
   line(x+rad,y,x+rad+8,y+5);
   line(x-rad-8,y+5,x+rad+8,y+5);
   setfillstyle(SOLID_FILL, 7);
   floodfill(x,y+3,15);
}
void shootBul()
{
   int xn,yn;
   xBul = xShip;
   yBul = yShip;
   xn = xBul;
   yn = yBul;
   int op, xLim, yLim;
   op=0;
      if(kIp==100)
      {
	  if(yBul==yObj)
	  {
	      xLim = xObj;
	  }
	  else
	       xLim = xMax;

	  for(xn=xShip+50;xn<=xLim;xn+=25)
	  {
	      xBul+=25;
	      line(xBul, yBul, xn, yBul);
	     showAll(); //circle(xShip, yShip, radShip);
	      delay(15);
	      cleardevice();
	      op = objKill(xBul, yBul, xn, yn);
	      if(op==1)
	      {
		 cout<<"Villan Died!\n";
		 objNew();
		 break;
	      }
	  }

      }

      else if(kIp==115)
      {
	  if(xBul==xObj)
		yLim = yObj;
	  else
		yLim = yMax;
	  for(yn=yShip+50;yn<=yLim;yn+=25)
	  {
	      yBul+=25;
	      line(xBul, yBul, xBul, yn);
	     showAll(); //circle(xShip, yShip, radShip);
	      delay(15);
	      cleardevice();
	       op = objKill(xBul, yBul, xn, yn);
	      if(op==1)
	      {
		 cout<<"Villan Died!\n";
		 objNew();
		 break;
	      }
	  }

      }

      else if(kIp==119)
      {
	  if(xBul==xObj)
		yLim = yObj;
	  else
		yLim = 0;

	  for(yn=yShip-50;yn>=yLim;yn-=25)
	  {
	      yBul-=25;
	      line(xBul, yBul, xBul, yn);
	     showAll(); //circle(xShip, yShip, radShip);
	      delay(15);
	      cleardevice();
	      op = objKill(xBul, yBul, xn, yn);
	      if(op==1)
	      {
		 cout<<"Villan Died!\n";
		 objNew();
		 break;
	      }
	  }

      }

      else if(kIp==97)
      {
	 if(yBul==yObj)
		xLim = xObj;
	  else
		xLim = 0;

	  for(xn=xShip-50;xn>=xLim;xn=xn-25)
	  {
	      xBul-=25;
	      line(xBul, yBul, xn, yBul);
	     // circle(xShip, yShip, radShip);
	      showAll();
	      delay(15);
	      cleardevice();
	       op = objKill(xBul, yBul, xn, yBul);
	      if(op==1)
	      {
		 cout<<"Villan Died!\n";
		 objNew();
		 break;
	      }
	  }

      }
}
void destObj()
{
   int i;
   int r = radObj;
   int r2 = r*2;
   int xcor, ycor,x1,x2,x3,x4,y1,y2,y3,y4;
   xcor = xObj;
   ycor = yObj;
   x1 = xcor;
   x2 = xcor;
   y1 = ycor;
   y2 = ycor;
   for(i=0;i<9;i++)
   {   x1 = x1-1;
       x2 = x2+1;
       y1 = y1 - 1;
       y2 = y2 + 1;
       r=r-1;
       //objPlace(r);
       pieslice(x1,y1,90,270,r);
       pieslice(x2,y1,0,90,r);
       pieslice(x1,y2,180,270,r);
       pieslice(x2,y2,-270,0,r);
       delay(100);
       cleardevice();
       showAll(0);
   }

}
void objNew()
{
   destObj();
   int pm;
   scr++;
   pm = rand();
   int opr1, opr2;
   opr1 = rand()%xMax;
   opr2 = rand()%yMax;
   opr1 = opr1 - (opr1%10);
   opr2 = opr2 - (opr2%10);
   xObj = opr1;
   yObj = opr2;
  /* if(pm%2==0)
   {*/
      if(opr1==0 && opr2==0)
      {
	 //xObj = xObj - opr1*10;
	 //yObj = yObj - opr2*10;
	 xObj = 300;
	 yObj = 240;
      }
     /* else
      {
	  xObj=xObj - 10;
	  yObj = yObj - 10;
      }
   }
   else
   {
      if(opr1!=0 && opr2!=0)
      {
	  xObj=xObj + opr1*10;
	  yObj=yObj + opr2*10;
      }
      else
      {
	 xObj = xObj - 10;
      }
   }   */
   if( (xObj>=xMax || xObj<=0) || (yObj<=0 || yObj>=yMax) )
   {
       xObj = 290;
       yObj = 310;
   }
   objH = 1000;
   settextjustify(10,10);
  // cout<<xObj<<" "<<yObj;
  // getch();
   objPlace();
   //litStarsNew();
}
void objPlace(int r)
{
   //arc(xObj, yObj,0,180,10);
   pieslice(xObj, yObj, 0, 360,r);
   putpixel(xObj, yObj,15);

}
int objKill(int bulCorX1,int bulCorY1, int bulCorX2, int bulCorY2)
{
  if((bulCorY1==bulCorY2) && (bulCorY1==yObj))
  {
    if(bulCorX1< bulCorX2)
    {
      if(bulCorX1<=xObj || xObj<=bulCorX2)// && (yShip>=yObj+5 || yShip<=yObj-5))
      {
	  objH = objH-100;
	  cout<<"Obj Health: "<<objH;
	  if(objH<=0)
	  {
	    return 1;
	    cout<<"Killed !\n";
	    getch();
	   }
      }
      else
      {
	 cout<<"No Hit :(\n";
	 return 0;
      }
    }
    else if(bulCorX2< bulCorX1)
    {
	 if(bulCorX2<=xObj || xObj<=bulCorX1)// && (yShip>=yObj+5 || yShip<=yObj-5))
	 {
	  objH = objH-100;
	  cout<<"obj Health: "<<objH;
	  if(objH<=0)
	  {
	    return 1;
	    cout<<"Killed !\n";
	    getch();
	   }
	 }
	else
	{
	 cout<<"No Hit :(\n";
	 return 0;
	}

    }
  }
  else if((bulCorX1==bulCorX2) && (bulCorX1==xObj))
  {
    if(bulCorY1<=yObj || yObj<=bulCorY2)
    {
       objH = objH-100;
       cout<<"obj Health: "<<objH;

	  if(objH<=0)
	  {
	    return 1;
	    cout<<"Killed !\n";
	    getch();
	  }
     }
    else
    {
       cout<<"No Hit :(\n";
       return 0;
    }
  }

}
void litStars()
{   int rndx, rndy;
    int i;
    for(i=0;i<75;i++)
    {
	rndx = rand() % getmaxx();
	rndy = rand() % getmaxy();
	putpixel(rndx, rndy, 15);
    }
}
void litStarsNew()
{
	int i;
      for(i=0;i<75;i++)
    {
       xStars[i] = rand() % getmaxx();
       yStars[i] = rand() % getmaxy();
	//putpixel(xStars[i], yStars[i], 15);
    }
    litStars();
}

void showAll(int cho)
{
   dispShip();
   litStars();
   if(cho==1)
   {
     //setfillstyle("SOLID_FILL", 11);
     //floodfill(xObj+1, yObj, 15);
     objPlace();
   }
}