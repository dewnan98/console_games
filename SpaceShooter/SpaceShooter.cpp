#include "SpaceShooter.h"



bool gameovers;
char key;
int bulletshot=0;
Ship ship;
Bullet bullets[100];
Alien aliens[100];

void Menu::start() {

}

void setup() {
    gameovers=true;
    ship.x=lebar/2;
    ship.y=panjang/2;


}

void play() {

    while(gameovers) {
        input();
        logic();
        update();

    }

}


void update() {

    gotoxy(ship.x, ship.y);
    cout<<"^";
    gotoxy(ship.x, ship.y+1);
    cout<<"=";


    for (int a=0; a<bulletshot;a++)
    {
        gotoxy (bullets[a].x , bullets[a].y);
        cout<<"|";
    }
    }


void logic() {

    if (key==75 || key=='a') {
        gotoxy(ship.x,ship.y);
        cout<<" ";
        gotoxy(ship.x,ship.y+1);
        cout<<" ";

        ship.x--;

    }

    else if (key==77 || key=='d') {
        gotoxy(ship.x,ship.y);
        cout<<" ";
        gotoxy(ship.x,ship.y+1);
        cout<<" ";
        ship.x++;
    }

    else if(key== ' ') {

        shoot();

    }

   if (ship.x <0)ship.x++;

   else if (ship.x>lebar) ship.x--;



        for (int a=0;a<bulletshot;a++)
        {
            gotoxy (bullets[a].x , bullets[a].y);
            cout<<" ";
            if (bullets[a].y>=-2)
            bullets[a].y-=1;

            if(bullets[a].y==0){
                bulletshot--;

        }
        }






}

void input () {
    key='\0';

    if (kbhit()) {
        key=getch();

        if (key==27)
            gameovers=false;


    }

    Sleep(25);

}

void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}


void shoot()
{
   bullets[bulletshot].x=ship.x;
   bullets[bulletshot].y=ship.y+1;
   bulletshot++;
}
