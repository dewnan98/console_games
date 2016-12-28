//Flikering Screen Is Fix....

//gotoxy its really helpfull..


#include <iostream>
#include <conio.h>
#include <ctime>
#include <stdio.h>
#include <cstdlib>
#include <stdlib.h>
#include <windows.h>
using namespace std;


const int panjang =20;
const int lebar =20;




class Tails
{
public :
    char tail='-';
    int tailx;
    int taily;
};

class Snake {


public :
    char snake ;
    int x;
    int y;


};
class Food
{

public :


  char food='o';

  int x;
  int y;


};

class Bigfood
{
    public :

      char bigfood='O';


  int x;
  int y;
};


bool gameover;
char key;
double speed;
int score;
int jumlahtails;
Snake snake;
Food food;
Bigfood bigfood;
Tails tails[100];

bool chance();
bool chances;
void draw ();
void setup();
void input();
void logic ();
void gotoxy(int x, int y);
void menu ();
void maps ();
void play();
bool snakepos(int a,int b);
void logo ();
void option();
void menu();
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

int main () {
    srand(time(0));



    setup();
    menu();


if (gameover)
play();



}

void setup() {

chances=false;
speed=100;
jumlahtails=0;
score=0;
    snake.snake='^';
    bigfood.x=-1;
    bigfood.y=-1;

    snake.y=panjang/2;
    snake.x=lebar/2;
    food.x = rand()%panjang-1;
    food.y = rand()%lebar-1;

    if (food.x<2 )food.x+=2;
    if (food.y<2)food.y+=2;

}

void menu()
{
bool pilih;
bool done;
int colour [3];
char keys;
int point=0;;


do {
 done=true;
while (done)
{
    pilih=true;
    for (int a=0;a<3;a++){
            if (a==point)colour[a]=112;
    else
        colour [a]=128;
    }

    //system("cls");
    logo();


    SetConsoleTextAttribute(hConsole , colour[0]);
cout<<"  __  ___         _   ___       \n";
cout<<" (_    |    /\\   |_)   |        \n";
cout<<" __)   |   /--\\  | \\   |        \n";


    SetConsoleTextAttribute(hConsole,colour[1]);
cout<<"  _    _   ___  ___   _         \n";
cout<<" / \\  |_)   |    |   / \\  |\\ |  \n";
cout<<" \\_/  |     |   _|_  \\_/  | \\|  \n";
    SetConsoleTextAttribute(hConsole,colour[2]);
cout<<"  _      ___  ___               \n";
cout<<" |_  \\/   |    |                \n";
cout<<" |_  /\\  _|_   |                \n";


    while(pilih)
    {
        if (kbhit) {
                key=getch();

        if (key==72 || key=='w'){
            --point;
            if(point<0)point=2;
            break;

        }
            else if (key==80 || key=='s'){
                ++point;
            if (point>2)point=0;
            break;
            }

            else if (key==13){
                pilih=false;
                done=false;
            }


        }

}
}

SetConsoleTextAttribute(hConsole,7);
if (point==0) gameover=true;
else if (point==1)option();
if (point==2)gameover=false;
}while(point==1);

}
void play()
{
    system("cls");
SetConsoleTextAttribute(hConsole,7);
    maps();
    while (gameover)
    {

        input();
        logic();
        draw();

    }


}

void draw () {






             gotoxy(snake.x,snake.y);

                cout<<snake.snake;


            gotoxy(food.x,food.y);

             cout<<food.food;





    for (int a=0;a<jumlahtails;a++)
{
    gotoxy(tails[a].tailx , tails[a].taily);
       if(a%2==0)cout<<"O";
       else cout<<"o";
}




gotoxy(lebar+2 , 0);
cout<<"SCORE : "<<score;
gotoxy(lebar+5 , 8);
cout<<"  W ";
gotoxy(lebar+5 , 9);
cout<<"A S D " ;


if (chances)
{
gotoxy(bigfood.x , bigfood.y);
cout<<bigfood.bigfood;

}









chance ();


}


void logic()
{

            gotoxy(tails[jumlahtails-1].tailx , tails[jumlahtails-1].taily);
cout<<" ";





    tails[0].tailx=snake.x;
        tails[0].taily=snake.y;

int tempx=tails[0].tailx;
int tempy=tails[0].taily;

int  temp2x,temp2y;

{


for (int a=0;a<100;a++)
{
    temp2x=tails[a].tailx;
    temp2y=tails[a].taily;
    tails[a].tailx=tempx;
    tails[a].taily=tempy;
    tempx=temp2x;
    tempy=temp2y;
}

}



    if (key==72 || key=='w'){
            gotoxy(snake.x,snake.y);
            cout<<" ";
            snake.y--;
            snake.snake='^';

        }
            else if (key==80 || key=='s'){
 gotoxy(snake.x,snake.y);
            cout<<" ";
                snake.y++;
                snake.snake ='v';


            }

            else if (key==75 || key=='a')
            {gotoxy(snake.x,snake.y);
            cout<<" ";

                snake.x--;
                snake.snake='<';
            }

            else if (key==77 || key=='d')
            {gotoxy(snake.x,snake.y);
            cout<<" ";
                snake.x++;
                snake.snake='>';
            }

            else if (key==27)
            {
                gameover=false;
            }


    if (snake.x == food.x && snake.y == food.y)
    {
        jumlahtails++;
        food.x=rand()%lebar-1;;
        food.y=rand()%panjang-1;;

        if (food.y<2 )food.y+=2;
    if (food.x<2)food.x+=2;
        score+=10;

        speed-=1;
    }



    if (snake.x == bigfood.x && snake.y==bigfood.y)
    {
        score+=30;
        jumlahtails+=3;
        bigfood.x=-1;
        bigfood.y=-1;
        chances = false;
        speed-=2;

    }

if (snake.x==lebar-1)
snake.x=1;

if (snake.y==panjang-1)
snake.y=1;
if (snake.x==0)
snake.x=lebar-2;

if(snake.y==0)
snake.y=panjang-2;





}

void input()
{
    bool input=true;

    while (input)
    {

        if (kbhit())
        {
            key=getch();
            input=false;




        }

        Sleep(speed);
        input=false;



    }

for (int a=0;a<jumlahtails;a++)
{
    if (snake.x ==tails[a].tailx && snake.y ==tails[a].taily)
    {
        gameover=false;
    }

}

}


void maps () {

for (int a=0;a<panjang;a++){

    for (int b=0;b<lebar;b++)
    {



    if (a==0|| b==0 || a==panjang-1 || b==lebar-1)
        cout<<"#";
        else cout<<" ";

}cout<<endl;
}
cout<<endl<<endl;

}
bool snakepos (int a, int b) {



    if (a==snake.y &&  b ==snake.x)
        return true;

    else return false;
}




bool chance()
{
    if (rand()%200==3)
    {
        gotoxy(bigfood.x , bigfood.y);
        cout<<" ";



        bigfood.x=rand()%lebar;
        bigfood.y=rand()%panjang;



        if (bigfood.y<2 )bigfood.y+=3;
    if (bigfood.x<2)bigfood.x+=2;
        chances=true;
    }

}

void logo ()
{
    SetConsoleTextAttribute(hConsole,78);
gotoxy(0,4);
cout<<"   _________                 __              ________                           ";
gotoxy(0,5);
cout<<"  /   _____/  ____  _____   |  | __  ____   /  _____/ _____     _____    ____   ";
gotoxy(0,6);
cout<<"  \\_____  \\  /    \\ \\__  \\  |  |/ /_/ __ \\ /   \\  ___ \\__  \\   /     \\ _/ __ \\  ";
gotoxy(0,7);
cout<<"  /        \\|   |  \\ / __ \\_|    < \\  ___/ \\    \\_\\  \\ / __ \\_|  Y Y  \\\\  ___/  ";
gotoxy(0,8);
cout<<" /_______  /|___|  /(____  /|__|_ \\ \\___  > \\______  /(____  /|__|_|  / \\___  > ";
gotoxy(0,9);
cout<<"         \\/      \\/      \\/      \\/     \\/         \\/      \\/       \\/      \\/  ";
gotoxy(0,10);
cout<<"         _                                  _          _                        \n";
gotoxy(0,11);
cout<<"        /   ._   _    _.  _|_   _    _|    |_)   \\/    | \\   _          _.      \n";
gotoxy(0,12);
cout<<"        \\_  |   (/_  (_|   |_  (/_  (_|    |_)   /     |_/  (/_  \\/\\/  (_|      \n";



}

void option()
{system("cls");




}

void gotoxy(int x, int y)
{
  COORD coord;
  coord.X = x;
  coord.Y = y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
