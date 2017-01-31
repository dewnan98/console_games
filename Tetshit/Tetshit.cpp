//masih newbie kakak.
//still have few bugs.
//the code is bad written
//bad algorithm implemantion.
//masil belum bisa ngerotate, algoritma nya ga ngerti.- fix later.
//new features coming soon :D


#include <iostream>
#include <windows.h>
#include <stdlib.h>
#include <conio.h>
#include <cstdlib>
#include <time.h>

using namespace std;
const int tinggi = 20 ;
const int lebar = 20;
int speed = 100 ;
//void Rotate();
void createTetris();
time_t currentTime;
struct tm *localTime;
void play ();
void logic ();
void input ();
void add();
void draw ();
void collided();
void setup ();
void playArea();
void gotoxy(int x , int y);
void cleanBlocks(int );
void isComplete();
bool gameover;
int next;
int now;



int Map [tinggi][lebar];

    int tet [4][4][4]=
{
{
    0,1,1,0,
    0,1,0,0,
    0,1,0,0,
    0,0,0,0

},
{
    0,1,0,0,
    0,1,0,0,
    0,1,0,0,
    0,1,0,0

},
{
    1,1,1,0,
    0,1,0,0,
    0,0,0,0,
    0,0,0,0

},
{
    0,0,0,0,
    0,1,1,0,
    0,1,1,0,
    0,0,0,0

},

} ;


void drawMap();

class Tetris
{
public: //why the hell this is public , terpaksa haaha ,, goona fix later.
    int x;
    int y;
    int x2;
    float y2;
    const float gravity = 0.15;
public :
    void setups ()
    {
        int x = rand()%lebar;
        int y = 0;
    }

    void Move (char key)
    {
        cleanUp();
        y2 +=gravity;
        y=y2;
        x2=x;

        switch (key)
        {

            case 'a' :cleanUp(); x -=1;    break;
            case 'd' : cleanUp();x+=1 ;    break;
            case 's' : speed=10;     break;
      //      case ' ' : Rotate();
                                    // break;

        }
    }

    void draw ()
    {


        for (int a = 0 ;  a<4 ; a++ )
        {
            for (int b = 0 ;  b<4 ; b++ )
            {
                if (tet[now][a][b]==1){
                gotoxy(x+b, y+a);
                cout<<"O";


                }



            }
        }

    }

    void cleanUp()
    {
                for (int a = 0 ;  a<4 ; a++ )
        {
            for (int b = 0 ;  b<4 ; b++ )
            {
                if (tet[now][a][b]==1){
                gotoxy(x+b, y+a);
                cout<<" ";
                }



            }
        }




    }
    void collision ()
    {
            for (int a = 0 ;  a<4 ; a++ )
        {
            for (int b = 0 ;  b<4 ; b++ )
            {
                if (tet[now][a][b]==1){

                    if (x+b<0 || Map[y+a][b+x]!=0 ||x+b>=lebar)
                    x=x2;


                    if (Map[y+a][b+x] !=0  || y+a+1>tinggi)
                    {
                        collided();

                    }



                }


            }
        }

    }



}tetris;





 char key;
int main()
{

    setup();
    play();

}

void setup ()
{
gameover=false;
now = rand()%4;

    for (int a=0;a<tinggi;a++)
    {
        for (int b=0;b<lebar;b++)
        {

            Map[a][b]=0;


        }
    }playArea();
    drawMap();



}

void play ()
{
    while (!gameover)
    {
        draw();
        input();
        logic();
    }
}

void logic ()
{
    speed=40;


tetris.Move(key);
tetris.collision();

key='/0';


}

void input ()
{






        if (kbhit())
        {
            key=getch();




        }

        Sleep(speed);





}

void draw ()

{

tetris.draw();

}


void drawMap()
{
    gotoxy(0,0);
    for (int a=0;a<tinggi;a++)
    {
        for (int b=0;b<lebar;b++)
        {
            if (Map[a][b]==1) cout<<"0";
            else cout<<" ";
        }cout<<endl;
    }
}


void collided()
{

    add();
    isComplete();
    drawMap();
    tetris.setups();
    createTetris();
}
void createTetris()
{

    srand(time(0));
tetris.setups();
tetris.y2= 0;
tetris.y=0;
tetris.x=lebar/2;
now = rand()%4;


}
void add()
{
     for (int a = 0 ;  a<4 ; a++ )
        {
            for (int b = 0 ;  b<4 ; b++ )
            {
    if(tet[now][a][b]!=0)
   Map[tetris.y+a-1][tetris.x+b] = tet[now][a][b];

            }
        }
}
void isComplete()
{
int complete;
    for (int a = 0 ; a< tinggi ; a++)
    { complete=0;
        for (int b= 0 ; b<lebar; b++)
        {
            if (Map[a][b]!=0)
                complete++;

            if (complete ==lebar)
            cleanBlocks(a);


        }
    }
}
void cleanBlocks(int a)
{

        for (int b= 0 ; b<lebar; b++)
        {
            Map[a][b]=0;
        }



}
void playArea()
{
    for (int a = 0 ; a<=tinggi ; a++)
    {
        for (int b=0 ; b<=lebar;b++)
        {
            if (a==0 || b==0 || a== tinggi || b== lebar)
                cout<<"X";
            else cout<<" ";
        }cout<<endl;
    }
}

void gotoxy(int x, int y)
{
  COORD coord;
  coord.X = x;
  coord.Y = y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
