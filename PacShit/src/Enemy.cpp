#include "../include/Pacman.h"
#include "../include/Enemy.h"
#include "../include/Variabel Global.h"
Enemy ghost1(lebar/2, tinggi/2-4, 12,1);
Enemy ghost2(lebar/2-1, tinggi/2-4, 13,3);
Enemy ghost3(lebar/2+1, tinggi/2-4, 6,1);
Enemy ghost4(lebar/2-2, tinggi/2-4, 11,4);
Enemy::Enemy(int x, int y, int value,int dir)
{
    this->x=x;
    this->y=y;
    this->color=value;
    this->dir=dir;
}

void Enemy::draw()
{
    gotoxy(x,y);
    if (savageMode)
        setColor(9);

    else setColor(color);
    cout<<char(178);

}
void Enemy::moves()
{
    int tempx=this->x;
    int tempy=this->y;

    clearFrame();

    if(dir==1)
    {
        x--;
    }

    if(dir==2)
    {
        y++;

    }


    if(dir==3)
    {
        x++;
    }


    if(dir==4)
    {
        y--;

    }








    gotoxy(tempx,tempy);

    if (maps[tempy][tempx]=='1')
    {
        setColor(7);
        cout<<char(250);

    }

    if (maps[tempy][tempx]=='o')
    {
        setColor(7);
        cout<<char(254);

    }


}

void Enemy::chase()
{
    clearFrame();

    if (x<pacman.x )x++;
    if (collisionCheck())
    {
        x--;
    }
    if (y<pacman.y)y++;
    if (collisionCheck())
    {
        y--;
    }
    if (x>pacman.x )x--;
    if (collisionCheck())
    {
        x++;
    }
    if (y>pacman.y)y--;
    if (collisionCheck())
    {
        y++;
    }

}

void Enemy::run()
{
    clearFrame();

    if (x<pacman.x )x--;
    if (collisionCheck())
    {
        x++;
    }
    if (y<pacman.y)y--;
    if (collisionCheck())
    {
        y++;
    }
    if (x>pacman.x )x++;
    if (collisionCheck())
    {
        x--;
    }
    if (y>pacman.y)y++;
    if (collisionCheck())
    {
        y--;
    }
}
bool Enemy::collisionCheck()
{
    if (maps [y][x]!= '1' &&  maps [y][x]!='0' &&  maps [y][x]!='o')
        return true;

    else return false;

}

void Enemy::clearFrame()
{
    gotoxy(x,y);
    setColor(0);
    cout<<' ';
}

void Enemy::attack()
{
    if( this->x ==pacman.x && this->y==pacman.y)
    {
        if (savageMode)
        {
            dead();

        }

        else gameover=true;
    }

}


void Enemy::AI1()
{

    int tempx=this->x;
    int tempy=this->y;
    int jarakx;
    int jaraky;
    moves();
    if (savageMode)
    {
        if (maps [y][x]!= '1' &&  maps [y][x]!='0' &&  maps [y][x]!='o')
        {
            this->x=tempx;
            this->y=tempy;
            draw();


            if (pacman.x>x)
            {
                jarakx=pacman.x-x;
                dir=1;

                if (maps [y][x-1]!= '1' &&  maps [y][x-1]!='0' &&  maps [y][x-1]!='o')
                {


                    dir=4;
                    if (maps [y-1][x]!= '1' &&  maps [y-1][x]!='0' &&  maps [y-1][x]!='o')
                        dir=3;


                }


            }
            else
            {
                jarakx= x-pacman.x;
                dir=3;

                if (maps [y][x+1]!= '1' &&  maps [y][x+1]!='0' &&  maps [y][x+1]!='o')
                {
                    dir=2;
                    if (maps [y+1][x]!= '1' &&  maps [y+1][x]!='0' &&  maps [y+1][x]!='o')
                        dir=1;
                }
            }


            if (pacman.y>y)
            {


                jaraky= pacman.y-y;

                if (jaraky>jarakx)
                {
                    dir=4;
                    if (maps [y-1][x]!= '1' &&  maps [y-1][x]!='0' &&  maps [y-1][x]!='o')
                    {
                        dir=1;
                        if (maps [y][x-1]!= '1' &&  maps [y][x-1]!='0' &&  maps [y][x-1]!='o')
                            dir=2;
                    }
                }

            }


            else

            {
                jaraky=y-pacman.y;

                if (jaraky>jarakx)
                {
                    dir=2;
                    if (maps [y+1][x]!= '1' &&  maps [y+1][x]!='0' &&  maps [y+1][x]!='o')

                    {
                        dir=1;
                        if (maps [y][x-1]!= '1' &&  maps [y][x-1]!='0' &&  maps [y][x-1]!='o')
                            dir=4;
                    }
                }

            }

        }


    }





    else
    {


        if (maps [y][x]!= '1' &&  maps [y][x]!='0' &&  maps [y][x]!='o')
        {
            this->x=tempx;
            this->y=tempy;
            draw();


            if (pacman.x>x)
            {
                jarakx=pacman.x-x;
                dir=3;

                if (maps [y][x+1]!= '1' &&  maps [y][x+1]!='0' &&  maps [y][x+1]!='o')
                {


                    dir=2;
                    if (maps [y+1][x]!= '1' &&  maps [y+1][x]!='0' &&  maps [y+1][x]!='o')
                        dir=1;


                }


            }
            else
            {
                jarakx= x-pacman.x;
                dir=1;

                if (maps [y][x-1]!= '1' &&  maps [y][x-1]!='0' &&  maps [y][x-1]!='o')
                {
                    dir=4;
                    if (maps [y-1][x]!= '1' &&  maps [y-1][x]!='0' &&  maps [y-1][x]!='o')
                        dir=3;
                }
            }


            if (pacman.y>y)
            {


                jaraky= pacman.y-y;

                if (jaraky>jarakx)
                {
                    dir=2;
                    if (maps [y+1][x]!= '1' &&  maps [y+1][x]!='0' &&  maps [y+1][x]!='o')
                    {
                        dir=3;
                        if (maps [y][x+1]!= '1' &&  maps [y][x+1]!='0' &&  maps [y][x+1]!='o')
                            dir=4;
                    }
                }

            }


            else

            {
                jaraky=y-pacman.y;

                if (jaraky>jarakx)
                {
                    dir=4;
                    if (maps [y-1][x]!= '1' &&  maps [y-1][x]!='0' &&  maps [y-1][x]!='o')

                    {
                        dir=1;
                        if (maps [y][x-1]!= '1' &&  maps [y][x-1]!='0' &&  maps [y][x-1]!='o')
                            dir=2;
                    }
                }

            }

        }

    }


}


void Enemy::AI2()
{
    int tempx=this->x;
    int tempy=this->y;
    int jarakx;
    int jaraky;
    moves();



if (savageMode)
    {



            if (pacman.x>x)
            {
                jarakx=pacman.x-x;
                dir=1;

                if (maps [y][x-1]!= '1' &&  maps [y][x-1]!='0' &&  maps [y][x-1]!='o')
                {


                    dir=4;
                    if (maps [y-1][x]!= '1' &&  maps [y-1][x]!='0' &&  maps [y-1][x]!='o')
                        dir=3;


                }


            }
            else
            {
                jarakx= x-pacman.x;
                dir=3;

                if (maps [y][x+1]!= '1' &&  maps [y][x+1]!='0' &&  maps [y][x+1]!='o')
                {
                    dir=2;
                    if (maps [y+1][x]!= '1' &&  maps [y+1][x]!='0' &&  maps [y+1][x]!='o')
                        dir=1;
                }
            }


            if (pacman.y>y)
            {


                jaraky= pacman.y-y;

                if (jaraky>jarakx)
                {
                    dir=4;
                    if (maps [y-1][x]!= '1' &&  maps [y-1][x]!='0' &&  maps [y-1][x]!='o')
                    {
                        dir=1;
                        if (maps [y][x-1]!= '1' &&  maps [y][x-1]!='0' &&  maps [y][x-1]!='o')
                            dir=2;
                    }
                }

            }


            else

            {
                jaraky=y-pacman.y;

                if (jaraky>jarakx)
                {
                    dir=2;
                    if (maps [y+1][x]!= '1' &&  maps [y+1][x]!='0' &&  maps [y+1][x]!='o')

                    {
                        dir=1;
                        if (maps [y][x-1]!= '1' &&  maps [y][x-1]!='0' &&  maps [y][x-1]!='o')
                            dir=4;
                    }
                }

            }

        }







    else
    {





            if (pacman.x>x)
            {
                jarakx=pacman.x-x;
                dir=3;

                if (maps [y][x+1]!= '1' &&  maps [y][x+1]!='0' &&  maps [y][x+1]!='o')
                {


                    dir=2;
                    if (maps [y+1][x]!= '1' &&  maps [y+1][x]!='0' &&  maps [y+1][x]!='o')
                        dir=1;


                }


            }
            else
            {
                jarakx= x-pacman.x;
                dir=1;

                if (maps [y][x-1]!= '1' &&  maps [y][x-1]!='0' &&  maps [y][x-1]!='o')
                {
                    dir=4;
                    if (maps [y-1][x]!= '1' &&  maps [y-1][x]!='0' &&  maps [y-1][x]!='o')
                        dir=3;
                }
            }


            if (pacman.y>y)
            {


                jaraky= pacman.y-y;

                if (jaraky>jarakx)
                {
                    dir=2;
                    if (maps [y+1][x]!= '1' &&  maps [y+1][x]!='0' &&  maps [y+1][x]!='o')
                    {
                        dir=3;
                        if (maps [y][x+1]!= '1' &&  maps [y][x+1]!='0' &&  maps [y][x+1]!='o')
                            dir=4;
                    }
                }

            }


            else

            {
                jaraky=y-pacman.y;

                if (jaraky>jarakx)
                {
                    dir=4;
                    if (maps [y-1][x]!= '1' &&  maps [y-1][x]!='0' &&  maps [y-1][x]!='o')

                    {
                        dir=1;
                        if (maps [y][x-1]!= '1' &&  maps [y][x-1]!='0' &&  maps [y][x-1]!='o')
                            dir=2;
                    }
                }

            }

        }






}

void Enemy::dead()
{
    x=lebar/2;
    y=tinggi/2;
}
