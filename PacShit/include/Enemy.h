#ifndef ENEMY_H
#define ENEMY_H


class Enemy
{


    private:
    int x;
    int y;
    int color;
    float x2;
    float y2;
    const float speed =0.25;
    bool collided=false;
    int dir;
    //1 = left
    //2 = down
    //3 = right
    //4 = up


    public:
       Enemy(int ,int , int ,int);

        void moves();
        void collision ();
        void logic();
        void eat();
        void chase();
        void dead();
        void run();
        void draw();
                bool collisionCheck();
        void clearFrame();
        void attack();
        void AI1();
        void AI2();
        void AI3();
        void AI4();



} extern ghost1 ;
extern Enemy ghost2;
extern Enemy ghost3;
extern Enemy ghost4;
#endif // ENEMY_H
