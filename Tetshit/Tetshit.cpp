
#define _WIN32_WINNT 0x0500
#include <iostream>
#include <windows.h>
#include <stdlib.h>
#include <conio.h>
#include <cstdlib>
#include <time.h>
#include <stdio.h>
#include <cwchar>

using namespace std;
const int tinggi = 22 ;
const int lebar = 10;
int speed = 100 ;
int combo;
//void Rotate();
void createTetris();
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
time_t currentTime;
struct tm *localTime;
void play ();
void logic ();
void input ();
void add();
void draw ();
void collided();
void blocksFall(int );
void setup ();
void drawPlayArea();
void gotoxy(int x , int y);
void cleanBlocks(int );
void isComplete();
void cleanNextTet();
bool combos;
bool gameover;
bool fastforward=false;
int next;
int now;
int pos=0;
int getTetris();
int tet[4][4][4];
int nextTet[4][4][4];
int score;

int Map [tinggi][lebar];
void drawMap();
void setColor(int);
void copyArrays(int [][4][4] , int [][4][4]);

void fontSize(int ,int);

char blocks=254;
char vline = 179;
char hline = 196;
char vLine=186;
char hLine=205;
int colour[7]= {12,10,11,13,14,15,9};

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
            case 's' : fastforward=true;    break;
           case ' ' : cleanUp(); pos++; if (pos>3)pos=0; break;
                                    // break;

        }
    }

    void draw ()
    {


        for (int a = 0 ;  a<4 ; a++ )
        {
            for (int b = 0 ;  b<4 ; b++ )
            {
                if (tet[pos][a][b]!=0){
                gotoxy(x+b, y+a);
                setColor(colour[tet[pos][a][b]-1]);
                cout<<blocks;


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
                if (tet[pos][a][b]!=0){
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
                if (tet[pos][a][b]!=0){

                    if (x+b<0 || Map[y+a][b+x]!=0 ||x+b>=lebar)
                    x=x2;

                    while(x+b>=lebar)
                        x--;

                        while(x+b<0)
                        x++;




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

CONSOLE_FONT_INFO font;



// -----------main-------------
int main()
{


//MessageBox(NULL, "Dont share this code unless you get permission with the owner.", "Dewa Says :", MB_OK);

    srand(time(0));

    setup();
    play();

}
//----------main--------------


void setup ()
{
gameover=false;
combos=false;
score=0;
combo=1;

    for (int a=0;a<tinggi;a++)
    {
        for (int b=0;b<lebar;b++)
        {

            Map[a][b]=0;


        }
    }drawPlayArea();
    drawMap();
    getTetris();
    copyArrays(nextTet , tet);

        getTetris();
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

            if (key>='A' && key <='Z')
                key+=32;




        }


if(!fastforward)
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
            if (Map[a][b]!=0)
            {   setColor(colour[Map[a][b]-1]);
                cout<<blocks;

            }
            else cout<<" ";
        }cout<<endl;
    }

    int length =0 ;
    int score2=score;

    while (score2>=10)
    {
        score2/=10;
        length++;

    }

    setColor(7);
    gotoxy(lebar+4 ,4);
    cout<<"SCORE";
     gotoxy(lebar+9-length ,5);
     cout<<score;
     gotoxy(lebar+3 , 7);
     cout<<"       ";
     if(combo-1>1)
     {
         gotoxy(lebar+3 , 7);
         cout<<combo-1<<" COMBO";
     }

            for (int a = 0 ;  a<4 ; a++ )
        {
            for (int b = 0 ;  b<4 ; b++ )
            {
                if (nextTet[0][a][b]!=0){
                gotoxy(lebar+5+b, a+tinggi-6);
                setColor(colour[nextTet[0][a][b]-1]);
                cout<<blocks;


                }



            }
        }
}


void collided()
{
combos=false;

    add();
    isComplete();
    tetris.setups();

    cleanNextTet();
    createTetris();

    getTetris();

if (combos)
    combo++;
else combo=1;


    drawMap();

    fastforward = false;

}
void createTetris()
{


tetris.setups();
tetris.y2= 0;
tetris.y=0;
tetris.x=lebar/2-lebar/4;
now = rand()%4;
copyArrays(nextTet,tet);


}
void add()
{
     for (int a = 0 ;  a<4 ; a++ )
        {
            for (int b = 0 ;  b<4 ; b++ )
            {

    if(tet[pos][a][b]!=0)
   Map[tetris.y+a-1][tetris.x+b] = tet[pos][a][b];




            }
        }
}
void isComplete()
{
int line=0;
int complete;
    for (int a = 0 ; a< tinggi ; a++)
    { complete=0;
        for (int b= 0 ; b<lebar; b++)
        {
            if (Map[a][b]!=0)
                complete++;

            if (complete ==lebar)
            {
                line++;

                score+=100*line*combo;
            cleanBlocks(a);


            }


              if (Map[0][b]!=0)gameover=true;


        }
    }
}
void cleanBlocks(int a)
{

        for (int b= 0 ; b<lebar; b++)
        {
            Map[a][b]=0;

        }


        blocksFall(a);
        combos=true;



}

void blocksFall(int a)
{
    for (int i = 0 ; i <a; i++)
    for (int j= 0 ; j<lebar; j++)
        {
            Map[a-i][j]=Map[a-i-1][j];
        }


}

void drawPlayArea()
{
    for (int a = 0 ; a<=tinggi ; a++)
    {
        for (int b=0 ; b<=lebar;b++)
        {
            if (a==0 || b==0 || a== tinggi || b== lebar)
                cout<<blocks;
            else cout<<" ";
        }cout<<endl;
    }



     gotoxy(lebar+3 ,5);
     cout<<"0000000";

        for (int a = 0 ; a<=tinggi ; a++)
    {
        for (int b=0 ; b<=lebar;b++)
        {
            if (a==0 &&b==0)
            {


            gotoxy(lebar+b+1 , a);
                cout<<char (201);
            }

            else if (a==0 &&b==lebar)
            {


            gotoxy(lebar+b+1 , a);
                cout<<char (187);
            }
           else if (a==tinggi &&b==0)
            {


            gotoxy(lebar+b+1 , a);
                cout<<char (200);
            }
           else if (a==tinggi &&b==lebar)
            {


            gotoxy(lebar+b+1 , a);
                cout<<char (188);
            }

            else  if
            (b==0 || b==lebar)
            {


             gotoxy(lebar+b+1 , a);
                cout<<vLine;
            }
            else if (a==0 ||a== tinggi)
            {
                gotoxy(lebar+b+1 , a);

                cout<<hLine;
            }

        }cout<<endl;
    }

}


void cleanNextTet()
{

            for (int a = 0 ;  a<4 ; a++ )
        {
            for (int b = 0 ;  b<4 ; b++ )
            {
                if (nextTet[0][a][b]!=0){
                gotoxy(lebar+5+b, tinggi-6+a);

                cout<<" ";


                }



            }
        }

}

int getTetris ()
{
        int tet1 [4][4][4]=
{
{
    1,0,0,0,
    1,1,1,0,
    0,0,0,0,
    0,0,0,0

},
{
    0,1,1,0,
    0,1,0,0,
    0,1,0,0,
    0,0,0,0

},
{
    0,0,0,0,
    1,1,1,0,
    0,0,1,0,
    0,0,0,0

},
{
    0,1,0,0,
    0,1,0,0,
    1,1,0,0,
    0,0,0,0

}

} ;

        int tet2 [4][4][4]=
{
{
    0,2,0,0,
    0,2,0,0,
    0,2,0,0,
    0,2,0,0

},
{
    0,0,0,0,
    2,2,2,2,
    0,0,0,0,
    0,0,0,0

},
{
    0,2,0,0,
    0,2,0,0,
    0,2,0,0,
    0,2,0,0

},
{
    0,0,0,0,
    2,2,2,2,
    0,0,0,0,
    0,0,0,0

}

} ;

        int tet3 [4][4][4]=
{
{
    0,0,3,0,
    3,3,3,0,
    0,0,0,0,
    0,0,0,0

},
{
    0,3,0,0,
    0,3,0,0,
    0,3,3,0,
    0,0,0,0

},
{
    0,0,0,0,
    3,3,3,0,
    3,0,0,0,
    0,0,0,0

},
{
    3,3,0,0,
    0,3,0,0,
    0,3,0,0,
    0,0,0,0

},

} ;

        int tet4 [4][4][4]=
{
{
    4,4,0,0,
    0,4,4,0,
    0,0,0,0,
    0,0,0,0

},
{
    0,4,0,0,
    4,4,0,0,
    4,0,0,0,
    0,0,0,0

},
{
    4,4,0,0,
    0,4,4,0,
    0,0,0,0,
    0,0,0,0

},
{
    0,4,0,0,
    4,4,0,0,
    4,0,0,0,
    0,0,0,0

},

} ;

        int tet5 [4][4][4]=
{
{
    0,5,0,0,
    5,5,5,0,
    0,0,0,0,
    0,0,0,0

},
{
    0,5,0,0,
    0,5,5,0,
    0,5,0,0,
    0,0,0,0

},
{
    0,0,0,0,
    5,5,5,0,
    0,5,0,0,
    0,0,0,0

},
{
    0,5,0,0,
    5,5,0,0,
    0,5,0,0,
    0,0,0,0

},

} ;

        int tet6 [4][4][4]=
{
{
    0,6,6,0,
    6,6,0,0,
    0,0,0,0,
    0,0,0,0

},
{
    6,0,0,0,
    6,6,0,0,
    0,6,0,0,
    0,0,0,0

},
{
    0,6,6,0,
    6,6,0,0,
    0,0,0,0,
    0,0,0,0

},
{
    6,0,0,0,
    6,6,0,0,
    0,6,0,0,
    0,0,0,0

},

} ;

        int tet7 [4][4][4]=
{
{
    0,7,7,0,
    0,7,7,0,
    0,0,0,0,
    0,0,0,0

},
{
    0,7,7,0,
    0,7,7,0,
    0,0,0,0,
    0,0,0,0

},
{
    0,7,7,0,
    0,7,7,0,
    0,0,0,0,
    0,0,0,0

},
{
    0,7,7,0,
    0,7,7,0,
    0,0,0,0,
    0,0,0,0

},

} ;

int rands=rand()%7;
while(rands>=7)
rands=rand()%7;


if (rands==0)
copyArrays(tet1,nextTet);
if (rands==1)
copyArrays(tet2,nextTet);
if (rands==2)
copyArrays(tet3,nextTet);
if (rands==3)
copyArrays(tet4,nextTet);
if (rands==4)
copyArrays(tet5,nextTet);
if (rands==5)
copyArrays(tet6,nextTet);
if (rands==6)
copyArrays(tet7,nextTet);


}
void copyArrays(int from [][4][4] , int to [][4][4] )
{
    for (int a=0; a<4; a++){
    for (int b=0;b<4;b++){
        for (int c=0;c<4;c++)
        {
            to[a][b][c]=from [a][b][c];
        }
    }
}


}
void setColor(int value){
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

