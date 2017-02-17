#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <conio.h>

using namespace std;

const int lebar = 55;
const int tinggi =30;
void gotoxy(int x, int y);
void input ();
void play ();
void draw();
void logic ();
void setup();
void setColor(int);
void drawMap();
void backgrund();
bool gameover;
void drawScore();
int speed=30;
int hit;
int score1;
int score2;

class Pad
{
private :
    int x;
    int y;
    const int length =6;
    friend class Ball;

public :
    Pad (int x, int y)
    {
       this->x=x;
        this->y=y;


    }

public :
    void moves (int x, int y)
    {
        this->x+=x;
        this->y+=y;

        if (this->y<=0 )this->y++;
        if (this->y+length>=tinggi)this->y--;

        draw();

    }

    void draw()
    {
        for (int a=0 ; a<length ; a++)
        {
            gotoxy(x,y+a);
                    setColor (79);
        cout<<char(219);

        }
    }
    void clearFrame()
    {
               for (int a=0 ; a<length ; a++)
        {
            gotoxy(x,y+a);
            cout<<" ";

        }


    }

};

Pad player1(3,tinggi/2);
Pad player2(lebar-3,tinggi/2);




class Ball
{

private :
    int x;
    int y;
    int x2;
    int y2;
    int speed;

    public :
    Ball()
    {
        x=lebar/2;
        y=tinggi/2;
        x2=-1;
        y2=-1;


    }
public :
    void moves (int x, int y)
    {


        this->x+=x;
        this->y+=y;

    }

    void draw ()
    {

        gotoxy(x,y);
        setColor (79);
        cout<<char(254);
    }
    void collision ()
    {
        clearFrame();

        if (x == player1.x && y>= player1.y && y<= player1.y+player1.length )
        {
            x2=1;
            hit++;



                }
        else  if (x == player2.x && y>= player2.y && y<= player2.y+player2.length)
        {
            x2=-1;
            hit++;



                }
        else  if ( y<=1  )
        {
            y2=1;
        }

        else  if ( y>=tinggi-2  )
        {

            y2=-1;
        }

        else  if ( x<=0  )
        {
            score2++;
            x=lebar/2;
        y=tinggi/2;
        x2=1;
        hit=0;
        }

        else  if ( x>=lebar-1  )
        {score1++;
             x=lebar/2;
        y=tinggi/2;
        x2=-1;
        hit=0;


        }

        moves (x2,y2);




    }

    void clearFrame()
    {
        gotoxy(x,y);
        cout<<" ";

    }


}ball;




int main ()
{
    setup();
    play();


}

void setup()
{
    gameover=false;

    drawMap();


}

void play ()
{
    while (!gameover)
    {
        draw();
        input();
        logic ();

    }
}

void draw()
{
    player1.draw();
    player2.draw();
    ball.draw();
    drawScore();

}

void logic()
{
    Sleep(speed);

    ball.collision();

}
void input()
{
    if (GetAsyncKeyState('W'))
    {
        player1.clearFrame();

        player1.moves(0,-1);




    }

    if (GetAsyncKeyState('S'))
    {
         player1.clearFrame();

        player1.moves(0,1);

    }

    if (GetAsyncKeyState(VK_UP))
    {
         player2.clearFrame();

        player2.moves(0,-1);



    }
    if (GetAsyncKeyState(VK_DOWN))
    {
         player2.clearFrame();

        player2.moves(0,1);


    }




}

void drawMap()
{
    for (int a = 0 ;a<tinggi ; a++)
    {
            for (int b = 0 ;b<lebar ; b++)
    {
        if (a==0 || a==tinggi-1)
        {


           setColor(79); cout<<char(220);
        }

        else
        {


        setColor(68);
            cout<<" ";
        }

    }
    cout<<endl;

    }
}
void drawScore ()
{

gotoxy(lebar/2-2 , 2);
setColor(79);
cout<<"SCORE";

gotoxy(lebar/2-7 , 2);
setColor(79);
cout<<score1;
gotoxy(lebar/2+6 , 2);
setColor(79);
cout<<score2;


if (score1>=5)
{
gotoxy(lebar/2-6 , tinggi/2);
setColor(79);
cout<<"PLAYER 1 WIN";
Sleep(1800);
gameover=true;
}
if (score2>=5)
{
gotoxy(lebar/2-6 , tinggi/2);
setColor(79);
cout<<"PLAYER 2 WIN";
Sleep(1800);
gameover=true;

}
}

void setColor(int value)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),  value);
}



void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

