#include "../include/Pacman.h"
#include "../include/Enemy.h"
#include "../include/Variabel Global.h"
Pacman pacman;
Pacman::Pacman()
{
   x=lebar/2;
   y=tinggi/2+8;
}

void Pacman::draw()
{
   gotoxy(x ,y);
   setColor(14);
   cout<<char(254);

}

void Pacman::moves()
{
char arah;
    int tempx=this->x;
    int tempy=this->y;
clearFrame();

if (key=='w')
{

y--;

}
if (key=='a')
{
x--;

}
if (key=='s')
{
y++;

}
if (key=='d')
{
x++;
}


if (x<0)x=lebar-1;
if (x>=lebar)x=0;

if (collisionCheck())
{
    this->x=tempx;
    this->y=tempy;
}
draw();

}

void Pacman::clearFrame()
{
    gotoxy(x ,y);
   setColor(0);
   cout<<' ';
}
void Pacman::collision()
{


}
bool Pacman::collisionCheck()
{
        if (maps [y][x]!= '1' &&  maps [y][x]!='0' &&  maps [y][x]!='o')
        return true;

        else return false;

}

void Pacman::eat()
{
    if (maps [y][x]== '1' )
     {

       maps[y][x]='0';
    score+10;
    setColor(0);
     gotoxy(x,y);
     cout<<" ";
     }

     if (maps [y][x]== 'o' )
     {
          maps[y][x]='0';
          savageMode=true;

     }


}
