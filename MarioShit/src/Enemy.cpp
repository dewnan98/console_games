#include "Mario.h"
#include "Enemy.h"
#include "GLOBALVARIABEL.h"

 Enemy mushroom[2];

Enemy::Enemy()
{

mushroom[0].x2=15;
mushroom[0].y=tinggi-4;
mushroom[1].x2=40;
mushroom[1].y=tinggi-4;


mushroom[0].respawn=false;
mushroom[1].respawn=false;
}

void Enemy::draw()
{


if( !despawn && respawn  )
{

 if ( Map[y][x]=='g')
{
    setColor(166);

}
else
      setColor(182);

    gotoxy(x-mapFrame,y);

    cout<<char(220);
}

}


void Enemy::collision()
{


if( !despawn && respawn  )
{



    if (Map[y+1][x]!='0')
    {

        onGround=true;

    }

    else
        onGround=false;

if (x>=mario.x+mapFrame-1  && y-1 == mario.y && x<=mario.x+mapFrame+1 && y-1 == mario.y )
    despawn=true;

else if (x==mario.x+mapFrame && y==mario.y )
    gameover=true;



}

}
void Enemy::velocity()
{


if( !despawn && respawn  )
{



        if(onGround==false )
    {


cleanFrame();
        y+=gravity;
        draw();
    }
}

}
void Enemy::range()
{
   // if (x2-mapFrame <=lebar-1)
   // {
      //  enemySpawn++;

    //}


    if (x2 <=mapFrame || y>=tinggi-1)
    {


        despawn=true;

    }

 //  else despawn = false;

    if (x2>=mapFrame -1 && x2<=lebar+mapFrame-1)
    {
      respawn=true;
    }
    else respawn = false;



}

void Enemy::moves()
{


if( !despawn && respawn  )
{




    if (dir)
    {
        cleanFrame();
        x2-=speedMove;

        x=x2;
        draw();
                 if (Map[y][x-1]!='0' && Map[y][x-1]!='g')
    {
draw();
        dir= false;


    }

    }

    if (dir==false)
    {



cleanFrame();
            x2+=speedMove;

        x=x2;


draw();

            if (Map[y][x+1]!='0'&& Map[y][x+1]!='g')
    {

        dir =true;


    }


    }
}

}
void Enemy::cleanFrame()

{

if(!despawn && respawn)
{
 if ( Map[y][x]=='g')
{
    setColor(166);

}
else
setColor(187);




        gotoxy(x-mapFrame,y);

        cout<<" ";
}

}

void Enemy::nextFrame()
{
       //


 x++;

}
