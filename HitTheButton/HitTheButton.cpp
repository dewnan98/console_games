#include <iostream>
#include <conio.h>
#include <ctime>
#include <stdio.h>
#include <cstdlib>
#include <stdlib.h>
#include <windows.h>
using namespace std;

const int  panjang= 24;
const int lebar = 40;

class O {
public :

    int x;
    int y;
};

class Button {

public :
    int ax;
    int ay;

    int bx;
    int by;



};


Button button[4];
O o[100];
void setup();
void logic();
void input ();
void draw ();
void ogenerate();
void play ();
void sorting(int a);
void hit(int a , int x);
bool hits;
void miss();
void gotoxy (int x, int y);
char key;
int jumlah;
int tombol;
int randomarray[100];
int score;
int colour[4];
int combos;
bool gameover;
bool kena;
void maps();
void combo();

HANDLE hConsole =GetStdHandle(STD_OUTPUT_HANDLE);



int main () {

    setup();
    play();




}



void setup () {
    for (int a=0; a<4; a++) {
        colour[a]=7;

    }
    combos=0;
    jumlah=0;
    score =0;
    kena =true;
    gameover= false;
    button[0].ax = 1;
    button[0].bx = 7 ;
    button[0].by = panjang;
    button[0].ay = panjang-3;

    for ( int a=1; a<4; a++) {
        button[a].ax = button[a-1].ax +10;
        button[a].bx = button [a-1].bx +10;
        button[a].by = panjang;
        button[a].ay = panjang-3;
    }


}

void play () {
    maps();
    while(!gameover) {


        draw();
        input();
        logic();


    }

}

void draw () {

    for (int a =0 ; a<jumlah ; a++) {
        gotoxy(o[a].x, o[a].y);
        cout<<"o";

    }


    gotoxy(lebar +1 , 1);
    cout<<"SCORE : "<<score;

    gotoxy (lebar/2, panjang /2);
    cout<<"COMBO "<<combos;


    SetConsoleTextAttribute(hConsole, colour[0]);

    gotoxy(button[0].ax,button[0].ay  );
    cout<<"_______\n";
    gotoxy(button[0].ax,button[0].ay+1  );
    cout<<"|  H  |\n";
    gotoxy(button[0].ax,button[0].ay+2  );
    cout<<"|_____|";
    SetConsoleTextAttribute(hConsole, colour[1]);
    gotoxy(button[1].ax,button[1].ay  );
    cout<<"_______\n";
    gotoxy(button[1].ax,button[1].ay+1 );
    cout<<"|  J  |\n";
    gotoxy(button[1].ax,button[1].ay +2 );
    cout<<"|_____|";
    SetConsoleTextAttribute(hConsole, colour[2]);
    gotoxy(button[2].ax,button[3].ay  );
    cout<<"_______\n";
    gotoxy(button[2].ax,button[3].ay+1  );
    cout<<"|  K  |\n";
    gotoxy(button[2].ax,button[3].ay +2 );
    cout<<"|_____|";
    SetConsoleTextAttribute(hConsole, colour[3]);
    gotoxy(button[3].ax,button[3].ay );
    cout<<"_______\n";
    gotoxy(button[3].ax,button[3].ay +1 );
    cout<<"|  L  |\n";
    gotoxy(button[3].ax,button[3].ay +2 );
    cout<<"|_____|";



}

void logic() {
    ogenerate();
    hits = false;

    for(int a=0; a<jumlah; a++) {
        gotoxy(o[a].x, o[a].y);
        cout<<" ";
        o[a].y+=1;
    }
    for (int a=0; a<4; a++) {
        colour[a]=7;

    }

    for(int a=0; a<jumlah; a++) {

        if(o[a].y > panjang) {

            sorting(a);

        }

    }




    if (key=='h') {
        colour[0]=23;

        hits=true;
        tombol=0;

    } else if (key=='j') {
        colour[1]=23;
        hits=true;
        tombol=1;
    } else if (key=='k') {
        colour[2]=23;
        hits=true;
        tombol=2;

    } else if (key=='l') {
        colour[3]=23;
        hits=true;
        tombol=3;
    }
    if (hits)
{
  int  a=0;
    while (kena)
    {

            hit(a , tombol);



        a++;
        if (a==jumlah-1)
        {
            kena = false;
        }

    }




}



    key=' ';

}





void input () {
    bool ketik=true;

    while (ketik) {




        if (kbhit()) {
            key=getch();
            ketik=false;

        }

        Sleep(50);
        ketik=false;

    }

}




void ogenerate() {
    if (rand()%100==26) {
        o[jumlah].x= 4;
        o[jumlah].y=0 ;
        jumlah++;
    }
    if (rand()%100==32) {
        o[jumlah].x= 14;
        o[jumlah].y=0;
        jumlah++;
    }
    if(rand()%100==24) {
        o[jumlah].x= 24;
        o[jumlah].y=0;
        jumlah++;
    }
    if(rand()%100==56) {
        o[jumlah].x= 34;
        o[jumlah].y=0;
        jumlah++;
    }

}

void sorting (int a) {
    o[a].x = o[jumlah-1].x;
    o[a].y = o[jumlah-1].y;

    jumlah--;

}

void hit (int a ,int x)
{
    if (o[a].y >= button[x].ay && o[a].x <= button[x].by )
        {combo();
        kena = false;
        }

    else kena = true ;


}

void combo ()
{
combos++;
score+=10;


}

void maps ()

{
   for (int a=0;a<panjang;a++){
    for (int b=0;b<lebar;b++){
        if (b==1 || b==7 || b==11 ||b==17 ||
            b==21 || b==31 || b==27 || b==37 || b==41||b==47)
                cout<<"|";
        else cout<<" ";
    }cout<<endl;
   }



}



void gotoxy (int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

}
