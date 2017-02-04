#ifndef MARIO_H
#define MARIO_H





class Mario
{
private :
    int x;
    int y;
    float y2;
    float x2;
    const int gravity=1;
    bool jump;
    bool collided;
    bool onGround;
    int jumpHigh;
    bool right;
    bool left;
    const float speedMove=0.25;
    float moveRange=2;
    friend class Enemy;


public :


    void range();

    void velocity();

    void setup();



    void input();


    void draw();

    void collision ();
    void cleanFrame();

}extern mario;


#endif // MARIO_H
