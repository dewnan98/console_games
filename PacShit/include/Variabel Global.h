#include <stdio.h>

#include <tchar.h>
#define _WIN32_WINNT 0x0500
#include <windows.h>
#include <iostream>
#include <stdlib.h>
#include <conio.h>
using namespace std;

extern const int lebar;
extern const int tinggi;

extern char maps [31][28];
extern int score;
extern bool gameover;
extern char key;
extern bool savageMode;
void gotoxy (int x , int y);
void play();
void input ();
void logic ();
void setup ();
void draw();
void drawMap();
void setColor(int );
void updateMap();

