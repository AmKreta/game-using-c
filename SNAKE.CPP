#include<graphics.h>
#include<conio.h>
#include<dos.h>
#include<stdlib.h>
#include<math.h>
int size=1;
class snake
{
 public:
       int x,y;
       char dir;

       void set_initials(int i)
	      {
	      x=60-i*10;y=10;
	       dir='d';
	      }
       void move_head()
		 {
		   if(dir=='d')
		       x+=10;
		   if(dir=='a')
		       x-=10;
		   if(dir=='s')
		       y+=10;
		   if(dir=='w')
		       y-=10;
		 }
       void draw()
		 {
		  setcolor(3);
		  circle(x,y,5);
		 }
       void get_dir(char dir)
		 {
		  this->dir=dir;
		 }

};

class food
{
   private:
	int X,Y;


   public:
	food()
	    {
	     X=50+random(getmaxx());
	     Y=100+random(getmaxy());
	    }
	void draw_food()
	    {
	      setcolor(WHITE);
	      circle(X,Y,5);
	    }
	void collide(snake p)
	    {
	     int dist;
	       dist=sqrt(pow((X-p.x),2)+pow((Y-p.y),2));
	       if(dist<=10)
		 change_food_pos();
	   }
	 void change_food_pos()
		   {
		    size++;
		    X=random(getmaxx());
		    Y=random(getmaxy());
		   }

};

void main()
{
  int gd=DETECT,gm;

  initgraph(&gd,&gm,"c:\\Turboc3\\BGI");

   snake player[30];
   food f;

   for(int i=0;i<size;i++)
      {
       player[i].set_initials(i);
      }

   char  ch;

	 while(player[0].dir!='e')
	      {
		 cleardevice();
		 f.draw_food();
		  for(int i=size-1;i>=1;i--)
		   {
		     player[i].x=player[i-1].x;
		     player[i].y=player[i-1].y;
		   }
		  if(kbhit())
		    {
		     player[0].get_dir(getch());
		    }
		  player[0].move_head();

		 for( i=0;i<size;i++)
		     player[i].draw();

	      f.collide(player[0]);

		 delay(40);
	      }

  getch();
 closegraph();
}