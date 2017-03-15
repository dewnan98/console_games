#ifndef PACMAN_H
#define PACMAN_H


class Pacman
{

    private:
    int x;
    int y;
    float x2;
    float y2;
    const float speed =0.25;
    bool collided=false;
    friend class Enemy;

    public:
        Pacman();

        void draw();
        void moves();
        void collision ();
        void logic();

        void eat();
        bool collisionCheck();
        void clearFrame();





} extern pacman;

#endif // PACMAN_H
