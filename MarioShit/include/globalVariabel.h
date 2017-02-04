#ifndef GLOBALVARIABEL_H
#define GLOBALVARIABEL_H



#include <stdio.h>

#include <tchar.h>
#define _WIN32_WINNT 0x0500
#include <windows.h>
#include <iostream>
#include <stdlib.h>



using namespace std;
extern HANDLE hConsole;

extern const int tinggi;
extern const int lebar;

extern char Map[15][220];

void play ();
void gameSetup();
void logic();
void input();
extern bool gameover;
void draw();
void drawMap();
void nextMap();
void gotoxy(int x , int y);
void setColor(int value);
extern int  mapFrame;

#endif
