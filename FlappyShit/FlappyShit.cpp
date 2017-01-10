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
    float x;
    float y;
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
Up_Pipe u_pipe[3];
B_Pipe b_pipe[3];
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
void reset_pipe(int a);
void death_animation();
const int gravity = 1;
int jumlah=0;
int jarak=0;
char key;
int score=0;
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
    gotoxy(0 , 1);
maps();
    gameover=false;

bird.x=4;
bird.y=tinggi/2;




}

void play ()
{
    draw ();
gotoxy(0,tinggi+2);
cout<<"Enter Space to Jump ....";

key=getch();
gotoxy(0,tinggi+2);
cout<<"                           ";



    while (!gameover)
    {


    logic();
   draw ();

   input();

    }


}

void draw()
{


gotoxy(bird.x , bird . y);
cout<<"O";
draw_pipe();
gotoxy(0,0);
cout<<"SCORE : "<<score;


}

void logic ()
{

     delete_pipe();

for (int a=0;a<jumlah;a++){
    u_pipe[a].x-=1;
    b_pipe[a].x-=1;
}

    gotoxy(bird.x , bird . y);
    cout<<" ";
    bird.y+=gravity;

            if (key==' ')
        {
            gotoxy(bird.x , bird . y);
            cout<<" ";
            bird.y-=bird.jump;
        }


    if (bird.y >= tinggi || bird.y  <=0)
        gameover=true;


for (int a=0;a<jumlah;a++)
{

    if (bird.x == u_pipe[a].x+1 )
    score++;


    if (u_pipe[a].x < 0 && b_pipe[a].x <0)
        reset_pipe(a);
        if (bird. x >= b_pipe[a].x && bird. x <= b_pipe[a].x+1   &&  ( bird . y <=u_pipe[a].y
    ||  bird . y >=b_pipe[a].y))
    gameover=true;

}

        if (jarak%25==0)
        pipe_generate();

}

void input ()
{
 key='\0';

    if(kbhit())
    {
        key=getch();



    }

    Sleep(60);
    jarak++;


}



void pipe_generate ()
{


    space.x=lebar-5;
    space.y=rand()%tinggi;
    if(space.y>tinggi-5)space.y-=6;
    if (space.y < 5)space.y+=6;
    u_pipe[jumlah].x= lebar;
    u_pipe[jumlah].y=space.y-3;
    b_pipe[jumlah].x= lebar;
    b_pipe[jumlah].y=space.y+3;

    jumlah++;



}

void reset_pipe(int a)
{

u_pipe[a].x=u_pipe[jumlah-1].x;
b_pipe[a].x=b_pipe[jumlah-1].x;
u_pipe[a].y=u_pipe[jumlah-1].y;
b_pipe[a].y=b_pipe[jumlah-1].y ;
jumlah--;
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
    for (int b=0;b<jumlah;b++)
{

    for (int a=0;a<u_pipe[b].y-1;a++)
    {
     gotoxy(u_pipe[b].x , u_pipe[b].y-a);
     cout<<"[]";
    }
}
    for (int b=0;b<jumlah;b++)
{

    for (int a=b_pipe[b].y; a<tinggi  ;a++)
    {
     gotoxy(b_pipe[b].x , a);
     cout<<"[]";
    }
}


}

void delete_pipe()
{
for (int b=0;b<jumlah;b++)
{


    for (int a=0;a<u_pipe[b].y-1;a++)
    {
     gotoxy(u_pipe[b].x , u_pipe[b].y-a);
     cout<<"  ";
    }
}
for (int b=0;b<jumlah;b++)
{

    for (int a=b_pipe[b].y; a<tinggi  ;a++)
    {
     gotoxy(b_pipe[b].x , a);
     cout<<"  ";


    }

}
}


void gotoxy(int x , int y)
{
    COORD coord;
    coord.X =x;
    coord.Y =y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);

}


