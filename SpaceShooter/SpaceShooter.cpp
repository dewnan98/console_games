#include "SpaceShooter.h"



bool gameovers;
char key;
Ship ship;
Bullet bullets[100];
Alien aliens[100];

void Menu::start()
{

}

void setup()
{
    gameovers=true;
    ship.x=lebar/2;
    ship.y=panjang+5;


}

void play()
{

    while(gameovers)
    {
        input();
        logic();
        update();

    }

}


void update()
{

    gotoxy(ship.x , ship.y);
    cout<<"^";
    gotoxy(ship.x , ship.y+1);
    cout<<"=";

}

void logic()
{

      if (key==75 || key=='a')
            {gotoxy(ship.x,ship.y);
            cout<<" ";
            gotoxy(ship.x,ship.y+1);
            cout<<" ";

                ship.x--;

            }

            else if (key==77 || key=='d')
            {gotoxy(ship.x,ship.y);
            cout<<" ";

               ship.x++;
            }

            else if(key== ' ')
            {

            }





}

void input ()
{
    key='\0';

    if (kbhit())
    {
        key=getch();

        if (key==27)
            gameovers=false;


    }

    Sleep(50);

}

void gotoxy(int x, int y)
{
  COORD coord;
  coord.X = x;
  coord.Y = y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

