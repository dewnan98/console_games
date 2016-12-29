#ifndef SPACESHOOTER_H
#define SPACESHOOTER_H

#include <iostream>
#include <conio.h>
#include <ctime>
#include <stdio.h>
#include <cstdlib>
#include <stdlib.h>
#include <windows.h>

using namespace std;

const int panjang=40;
const int lebar=40;


class Ship
{public :

    char ship ='^';
    int x;
    int y;
    int health;
    bool death;
    int life;
    int ammunition;

};


class Bullet
{
public :

    char bullet ='|';
    int x;
    int y;
    bool shoot;





};

class Alien
{
    public :
    int health;
    int x;
    int y;

};

class Menu
{
public :
    void pause();
    void  start();
    void gameover();
};

void play();
void input();
void logic();
void update();
void maps();
void setup();
void shoot();
bool shot();
void draw();




void gotoxy(int x, int y);

#endif // SPACESHOOTER_H
