#include "Mario.h"
#include "Enemy.h"
#include "GLOBALVARIABEL.h"


Mario mario;
void Mario::setup()
{
    jump=false;

    x=2;
    y=tinggi-5;

}


void Mario::range()
{
    if(x>=lebar/2)
    {

        nextMap();
        x--;
    }
}


void Mario:: velocity()
{

    if(!onGround &&!jump)
    {

    cleanFrame();

        y+=gravity;
        draw();
        if (y>=tinggi-1)
        {
            Sleep(100);
            gameover=true;
        }

    }

    if (jump)
    {
 cleanFrame();

        y--;
        draw();
        jumpHigh++;

    }

    if (jumpHigh>=5)
    {
        jump=false;
        jumpHigh=0;
    }


}


void Mario::input()
{
    if (GetAsyncKeyState(VK_RIGHT))
    {
  cleanFrame();
        x++;

            if (Map[y][x+mapFrame]!='0' &&Map[y][x+mapFrame]!='g')
                x--;
        draw();
    }
    if (GetAsyncKeyState(VK_LEFT))
    {
cleanFrame();

        x--;

            if (Map[y][x+mapFrame]!='0' &&Map[y][x+mapFrame]!='g'|| x<0)x++;
        draw();
    }

    if (GetAsyncKeyState(VK_DOWN))
    {
        ;
    }


    if (GetAsyncKeyState(VK_UP))
    {
        if(onGround)
            jump=true;
    }






}

void Mario::draw()
{

    if ( Map[y][x+mapFrame]=='g')
{
    setColor(172);

}


   else
   {
       setColor(188);
   }
   gotoxy(x,y);

    cout<<char(219);


}
void Mario::collision ()
{
    if (Map[y+1][x+mapFrame]!='0' &&Map[y+1][x+mapFrame]!='g')
    {

        onGround=true;

    }

    else
        onGround=false;

    if (Map[y-1][x+mapFrame]!='0' )
    {
        if (Map[y-1][x+mapFrame]=='2')
        {
            gotoxy(x,y-2);
            setColor(190);
            cout<<char(157);
            Map[y-1][x+mapFrame]='y';
            drawMap();

        }



        jump=false;

    }

}


void Mario::cleanFrame()
{

    if ( Map[y][x+mapFrame]=='g')
{
    setColor(172);

}


    else
    setColor(187);



        gotoxy(x,y);

        cout<<" ";


}


