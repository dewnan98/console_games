#include <iostream>
#include "include/Pacman.h"
#include "include/Enemy.h"
#include "include/Variabel Global.h"


int time;

int main()
{
  setup();

  play();
}

void setup()
{
       gameover =false;
    drawMap();
    savageMode=false;
}

void play ()
{
    while (!gameover)
    {
        draw();
        input ();
        logic ();
    }
}

void draw()
{
pacman.draw();
ghost1.draw();
ghost2.draw();
ghost3.draw();
ghost4.draw();
}

void logic ()
{
Sleep(120);
    pacman.eat();
    pacman.moves();
    ghost1.AI1();

    ghost1.attack();

        ghost2.AI2();
    ghost2.attack();
       ghost3.AI1();
ghost3.attack();
        ghost4.AI2();
    ghost4.attack();


   if (savageMode)
   {
       time++;

           if (time==60)
           {
               time=0;
               savageMode=false;

           }
   }

}



void input ()
{





        if (kbhit())
        {
            key=getch();

            if (key>='A' && key <='Z')
                key+=32;






        }


}

void drawMap()
{
    gotoxy(0,0);

    for (int a =0 ; a< tinggi; a++)
    {
            for (int b = 0 ; b< lebar; b++)
    {
        if (maps[a][b]=='0')
        {
            setColor(0);
            cout<<" ";

        }
        if (maps[a][b]=='1')
        {
            setColor(7);
            cout<<char(250);

        }
             if (maps[a][b]=='o')
        {
            setColor(7);
            cout<<char(254);

        }
        if (maps[a][b]=='V')
        {
               setColor(1);
            cout<<char(186);

        }
        if (maps[a][b]=='B')
        {
               setColor(1);
            cout<<char(188);

        }
        if (maps[a][b]=='C')
        {
               setColor(1);
            cout<<char(201);

        }
        if (maps[a][b]=='H')
        {
               setColor(1);
            cout<<char(205);

        }
        if (maps[a][b]=='A')
        {
               setColor(1);
            cout<<char(200);

        }

        if (maps[a][b]=='D')
        {
               setColor(1);
            cout<<char(187);

        }
                if (maps[a][b]=='=')
        {
               setColor(1);
            cout<<char(3);

        }


        if (maps[a][b]=='v')
        {
               setColor(1);
            cout<<char(179);

        }
        if (maps[a][b]=='b')
        {
               setColor(1);
            cout<<char(217);

        }
        if (maps[a][b]=='c')
        {
               setColor(1);
            cout<<char(218);

        }
        if (maps[a][b]=='h')
        {
               setColor(1);
            cout<<char(196);

        }
        if (maps[a][b]=='a')
        {
               setColor(1);
            cout<<char(192);

        }

        if (maps[a][b]=='d')
        {
               setColor(1);
            cout<<char(191);

        }

        if (maps[a][b]=='-')
        {
               setColor(7);
            cout<<char(196);

        }

    }cout<<endl;

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

