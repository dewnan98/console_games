#include <iostream>
#include <windows.h>
#include <conio.h>
#include <ctime>
#include <cstdlib>

using namespace std;


const int lebar=50;
const int tinggi =20;
class Up_Pipe
{
    public :
    int x;
    int y;
};

class B_Pipe
{
public :
    int x;
    int y;
};
class Space
{
    public :
    int x;
    int y;
};

class Bird
{

public :
    int x;
    int y;
     int jump=5;

};
Bird bird;
Up_Pipe u_pipe;
B_Pipe b_pipe;
Space space;

void start();
void pipe_generate();
void play();
void input();
void logic();
void setup();
void maps();
void draw();
void draw_pipe();
void delete_pipe();

char key;
void gotoxy(int x , int y);
bool gameover;
int main ()

{
srand(time(0));

    setup();
    play();
}

void setup ()
{
    gotoxy(0 , 0);
maps();
    gameover=false;

bird.x=4;
bird.y=tinggi/2;


}

void play ()
{

    pipe_generate();

    while (!gameover)
    {


   draw ();
   input();
   logic();
    }

}

void draw()
{
    draw_pipe();

gotoxy(bird.x , bird . y);
cout<<"O";


}

void logic ()
{

     delete_pipe();

    u_pipe.x-=1;
    b_pipe.x-=1;

    gotoxy(bird.x , bird . y);
    cout<<" ";
    bird.y+=1;

            if (key==' ')
        {
            gotoxy(bird.x , bird . y);
            cout<<" ";
            bird.y-=bird.jump;
        }


    if (bird.y >= tinggi-2 || bird.y  <=0)
        gameover=true;

    if (u_pipe. x < 0 && b_pipe.x <0)
        pipe_generate();

if (bird . x >= b_pipe.x && bird . x <= b_pipe.x+1   &&  ( bird . y <=u_pipe.y
    ||  bird . y >=b_pipe.y))
    gameover=true;




}

void input ()
{
 key='\0';

    if(kbhit())
    {
        key=getch();



    }

    Sleep(60);


}



void pipe_generate ()
{


    space.x=lebar-5;
    space.y=rand()%tinggi;
    if(space.y>tinggi-5)space.y-=6;
    if (space.y < 5)space.y+=6;
    u_pipe.x= lebar;
    u_pipe.y=space.y-3;
    b_pipe.x= lebar;
    b_pipe.y=space.y+3;



}


void maps()
{
   for (int a=1;a<=tinggi;a++)
   {
       for(int b=1;b<=lebar;b++)
       {
           if (a==1 || a==tinggi )
           cout<<"_";

            else cout<<" ";
       }cout<<endl;
   }

}
void draw_pipe()
{

    for (int a=0;a<u_pipe.y;a++)
    {
     gotoxy(u_pipe.x , u_pipe.y-a);
     cout<<"[]";
    }
    for (int a=b_pipe.y; a<tinggi-1  ;a++)
    {
     gotoxy(b_pipe.x , a);
     cout<<"[]";
    }


}

void delete_pipe()
{
    for (int a=0;a<u_pipe.y;a++)
    {
     gotoxy(u_pipe.x+1 , u_pipe.y-a);
     cout<<"  ";
    }

    for (int a=b_pipe.y; a<tinggi-1  ;a++)
    {
     gotoxy(b_pipe.x , a);
     cout<<"  ";
    }


}

void gotoxy(int x , int y)
{
    COORD coord;
    coord.X =x;
    coord.Y =y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);

}


