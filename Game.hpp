#ifndef BONBONCAR_GAME_HPP
#define BONBONCAR_GAME_HPP


#include "Header.hpp"
#include "Animation.hpp"
#include "Player.hpp"
#include "Enemy.hpp"
#include "Explosion.hpp"
#include "Bullet.hpp"
#include "Coin.hpp"
#include "Obstacle.hpp"
#include "PowerUP.hpp"

class Game {
private:
    void processEvent();
    void render();
    void respawn();
    void checkCollision();
    void endGame();
    RenderWindow window;

    Player racer;
    PowerUP power;

    float maxSpeed = 5.0f;
    float speed = 0;
    float bgAcc = 0.01f;
    float BackgroundY1 = 0;
    float BackgroundY2 = -1080.0f;
    float BackgroundY3 = -2160.0f;
    float BackgroundY4 = -3240.0f;
    float BackgroundY5 = -4320.0f;
    float score = 0;
    float bulletCount = 10;

    float oppMaxSpeed = 5;
    bool collided =false;
    bool fire = false;
    bool bulletCollide = false;

    vector<Explosion> explode;
    vector<Bullet> bullet;
    vector<Explosion> enemyExplode;
    vector<Coin> coinVect;
    vector<Obstacle> obsVect;
    vector<Enemy> enemyVect;

    Font normalFont;
    Text scoreText, lifeText, bulletText;
    Texture bg1, bg2, bg3, bg4, bg5, bgCover, bombTxt, bulletTxt, scoreBoardTxt, coinTexture, obs1Txt, obs2Txt, powerUP, playerTexture, enemyTxt;
    Sprite mainBG, mainBG2, mainBG3, mainBG4, mainBG5, mainCover, scoreBoard;

public:
    Game();
    void run();
    float getRandomNumber(float a, float b, char ch);

    string getRandomImage();

    void setEnemNewPosition(Enemy& enem, int num, float speed);
    void setCoinNewPosition(Coin& , int );

    float getDistance(float, float, float, float);
    float getCPdistance(Coin& , Player& );
    float getOPDistance(Obstacle&, Player&);
    float getPPdistance(PowerUP& pp, Player& p);
};

#endif //BONBONCAR_GAME_HPP
