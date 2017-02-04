#ifndef ENEMY_H
#define ENEMY_H


class Enemy
{

      private:

          int y;
          float x2;
          const float speedMove=0.25;

          int enemySpawn=0;
          bool dir=true;
          const int gravity=1;
          bool onGround=false;
          bool despawn;
          bool respawn;



    public:
        Enemy();
int x;

        void draw();
        void range();
        void moves();
        void getStomp();
        void collision();
        void velocity();
        void nextFrame();
        void cleanFrame();








}extern mushroom[2];

#endif // ENEMY_H
