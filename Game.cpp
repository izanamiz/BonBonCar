#include "Game.hpp"

Game::Game(): window(VideoMode(1920, 1080), "Bon Bon Car", sf::Style::Close | sf::Style::Titlebar)
{
    if (!normalFont.loadFromFile("fonts/PaladinsCondensed-rB77.otf")) {
        cout << "Error loading Score Font";
    }
    scoreText.setFont(normalFont);
    scoreText.setPosition(Vector2f(1138.0f, 28.0f));
    scoreText.setCharacterSize(100);
    scoreText.setFillColor(Color::Red);

    lifeText.setFont(normalFont);
    lifeText.setPosition(Vector2f(750.0f, 40.0f));
    lifeText.setFillColor(Color::White);
    lifeText.setCharacterSize(40);

    bulletText.setFont(normalFont);
    bulletText.setPosition(Vector2f(750.0f, 90.0f));
    bulletText.setCharacterSize(40);
    bulletText.setFillColor(Color::White);

    if (!bg1.loadFromFile("images/new1.png")){
        cout << "Error Loading File 1" << endl;
    }
    bg1.setSmooth(true);

    if (!bg2.loadFromFile("images/new2.png")){
        cout << "Error Loading File 2" << endl;
    }
    bg2.setSmooth(true);

    if (!bg3.loadFromFile("images/new3.png")){
        cout << "Error Loading File 3" << endl;
    }
    bg3.setSmooth(true);

    if (!bg4.loadFromFile("images/new4.png")){
        cout << "Error Loading File 4" << endl;
    }
    bg4.setSmooth(true);

    if (!bgCover.loadFromFile("images/backupBG.png")){
        cout << "Error loading Cover" << endl;
    }
    bgCover.setSmooth(true);

    if (!bombTxt.loadFromFile("images/type_C.png")){
        cout << "Error loading Bomb" << endl;
    }
    bombTxt.setSmooth(true);

    if (!bulletTxt.loadFromFile("images/fire_red.png")){
        cout << "Error loading Bullet" << endl;
    }
    bulletTxt.setSmooth(true);

    if (!scoreBoardTxt.loadFromFile("images/scoreBoard.png")){
        cout << "Error loading scoreBoard" << endl;
    }
    scoreBoardTxt.setSmooth(true);

    if (!coinTexture.loadFromFile("images/coins.png")){
        cout << "Error loading Coin" << endl;
    }
    coinTexture.setSmooth(true);

    if (!obs1Txt.loadFromFile("images/barrel.png")){
        cout << "Error loading Barrel" << endl;
    }
    obs1Txt.setSmooth(true);

    if (!obs2Txt.loadFromFile("images/block.png")){
        cout << "Error loading Block" << endl;
    }
    obs2Txt.setSmooth(true);

    if (!powerUP.loadFromFile("images/HP_Bonus.png")){
        cout << "Error loading Bonus" << endl;
    }
    powerUP.setSmooth(true);

    if(!playerTexture.loadFromFile("images/audi.png")){
        cout << "Error loading player";
    }
    playerTexture.setSmooth(true);
    racer = Player(playerTexture, 925.0f, 900.0f);

    mainBG.setTexture(bg1);
    mainBG2.setTexture(bg2);
    mainBG3.setTexture(bg3);
    mainBG4.setTexture(bg4);
    mainCover.setTexture(bgCover);

    //// ScoreBoard
    scoreBoard.setTexture(scoreBoardTxt);
    scoreBoard.setPosition(Vector2f(580.0f,0));

    //// Coin Objects
    coinVect.push_back(Coin(coinTexture, getRandomNumber(705, 805, 'c'), getRandomNumber(-1000, -1500, 'c'), 60, 60, 10, 0.1));
    coinVect.push_back(Coin(coinTexture, getRandomNumber(855, 955, 'c'), getRandomNumber(-2000, -2500, 'c'), 60, 60, 10, 0.1));
    coinVect.push_back(Coin(coinTexture, getRandomNumber(1005, 1055, 'c'), getRandomNumber(-3000, -3500, 'c'), 60, 60, 10, 0.1));
    coinVect.push_back(Coin(coinTexture, getRandomNumber(1105, 1155, 'c'), getRandomNumber(-4000, -4500, 'c'), 60, 60, 10, 0.1));
    coinVect.push_back(Coin(coinTexture, getRandomNumber(1205, 1255, 'c'), getRandomNumber(-5000, -5500, 'c'), 60, 60, 10, 0.1));

    //// Obstacles
    obsVect.push_back(Obstacle(obs1Txt, getRandomNumber(650, 750, 'e'), getRandomNumber(-1000, -2000, 'e')));
    obsVect.push_back(Obstacle(obs2Txt, getRandomNumber(950, 1050, 'e'), getRandomNumber(-2500, -3500, 'e')));
    obsVect.push_back(Obstacle(obs1Txt, getRandomNumber(850, 950, 'e'), getRandomNumber(-4000, -5000, 'e')));
    obsVect.push_back(Obstacle(obs2Txt, getRandomNumber(1100, 1150, 'e'), getRandomNumber(-5500, -6500, 'e')));

    float a1,a2,b1,b2;
    for(int i=0; i<4; i++)
    {
        enemyTxt.loadFromFile(getRandomImage());
        switch(i){
            case 0:
                a1 = 705, b1 = 805, a2 = -1000, b2 = -1500;
                break;
            case 1:
                a1 = 855, b1 = 955, a2 = -2000, b2 = -2500;
                break;
            case 2:
                a1 = 1005, b1 = 1105, a2 = -2200, b2 = -2400;
                break;
            case 3:
                a1 = 1155, b1 = 1200, a2 = -2500, b2 = -2700;
                break;
        }
        enemyVect.push_back(Enemy(enemyTxt, getRandomNumber(a1,b1,'e'), getRandomNumber(a2,b2,'e'), getRandomNumber(3,8,'s')));
    }

    power = PowerUP(powerUP, getRandomNumber(600, 1150, 'e'), getRandomNumber(-10000, -20000, 'e'));
    power.setScale();

}

void Game::run(){
    while (window.isOpen()) {
        processEvent();

        //// Showing life
        scoreText.setString(to_string((int)score));
        lifeText.setString(to_string(racer.getLife()));
        bulletText.setString(to_string((int)bulletCount));

        if (!collided) {
            if (Keyboard::isKeyPressed(Keyboard::Up)) {
                racer.movePlayer('u');
            }
            if (Keyboard::isKeyPressed(Keyboard::Down)) {
                racer.movePlayer('d');
            }

            if (Keyboard::isKeyPressed(Keyboard::Right)) {
                racer.movePlayer('r');
            }
            if (Keyboard::isKeyPressed(Keyboard::Left)) {
                racer.movePlayer('l');
            }
        }
        //// Create scrolling background
        mainBG.setPosition(Vector2f(0, BackgroundY1));
        mainBG2.setPosition(Vector2f(0, BackgroundY2));
        mainBG3.setPosition(Vector2f(0, BackgroundY3));
        mainBG4.setPosition(Vector2f(0, BackgroundY4));
        mainCover.setPosition(Vector2f(0, 0));

        if (mainBG.getPosition().y >= 1080){
            BackgroundY1 = -4315.0f;
        }
        if (mainBG2.getPosition().y >= 1080) {
            BackgroundY2 = -4315.0f;
        }
        if (mainBG3.getPosition().y >= 1080) {
            BackgroundY3 = -4315.0f;
        }
        if (mainBG4.getPosition().y >= 1080) {
            BackgroundY4 = -4315.0f;
        }
        //// Player Collision
        if (!collided) {
            if (speed <= maxSpeed) {
                speed += bgAcc;
            }
        }
        else{
            if (maxSpeed <= 5) {
                if (speed > 0) {
                    speed -= 0.05f;
                }
            }
            else if (maxSpeed > 5 && maxSpeed <= 7) {
                if (speed > 0) {
                    speed -= 0.05f;
                }
            }
            else if (maxSpeed > 7 && maxSpeed <= 9) {
                if (speed > 0) {
                    speed -= 0.07f;
                }
            }
            else if (maxSpeed > 9 && maxSpeed <= 11) {
                if (speed > 0) {
                    speed -= 0.09f;
                }
            }
            else if (maxSpeed > 11 && maxSpeed <= 15) {
                if (speed > 0) {
                    speed -= 0.1f;
                }
            }
        }
        BackgroundY1 += speed;
        BackgroundY2 += speed;
        BackgroundY3 += speed;
        BackgroundY4 += speed;

        //// Regeneration of Enemy
        for(int i=0; i<enemyVect.size(); i++)
        {
            if (enemyVect[i].getPosY() > 1200) {
                setEnemNewPosition(enemyVect[i], i, oppMaxSpeed);
            }
        }

        //// Speed
        if (score > 25 && score < 75) { maxSpeed = 7; oppMaxSpeed = 7; };
        if (score > 75 && score < 150) { maxSpeed = 9; oppMaxSpeed = 9; };
        if (score > 150 && score < 200) { maxSpeed = 11; oppMaxSpeed = 11; };
        if (score > 200 && score < 250) { maxSpeed = 15; oppMaxSpeed = 15; };

        //// Check Collision
        checkCollision();

        //// Respawn Objects
        respawn();

        //// Draw
        render();

        //// Checking Player LifeSpan
        if (racer.getLife() <= 0) {
            endGame();
            window.close();
        }

    }
}

void Game::checkCollision() {

    //// Check collision of player and enemy
    if (!collided) {
        for (int i = 0; i < enemyVect.size(); i++) {
            if (getDistance(racer.getPosX(), racer.getPosY(), enemyVect[i].getPosX(), enemyVect[i].getPosY()) <50) {
                collided = true;
                explode.push_back(Explosion(bombTxt, racer.getPosX() - 170, racer.getPosY() - 150, 256, 256, 48,0.25));
                racer.setLife(racer.getLife() - 1);
                if (bulletCount > 0) {
                    bulletCount--;
                }
            }
        }
    }

    //// Bullet Collision
    if (fire){
        for (int i = 0; i < bullet.size(); i++){
            for(int i=0; i<enemyVect.size(); i++){
                if (getDistance( bullet[i].getPosX(),  bullet[i].getPosY(), enemyVect[i].getPosX(), enemyVect[i].getPosY()) < 60){
                    bulletCollide = true;
                    enemyExplode.push_back(Explosion(bombTxt, enemyVect[i].getPosX() - 170, enemyVect[i].getPosY() - 150, 256, 256, 48,0.25));
                    setEnemNewPosition(enemyVect[i], i, oppMaxSpeed);
                    score += 1;
                }
            }
        }
    }

    //// Coin Collision
    for (int i = 0; i < coinVect.size(); i++){
        if (getCPdistance(coinVect[i], racer) < 50) {
            setCoinNewPosition(coinVect[i], i);
            score += 2;
        }
    }

    //// Obstacles Collision
    for (int i = 0; i < obsVect.size(); i++) {
        if (getOPDistance(obsVect[i], racer) < 50) {
            collided = true;
            explode.push_back(Explosion(bombTxt, racer.getPosX() - 170, racer.getPosY() - 150, 256, 256, 48, 0.25));
            obsVect[i].setPosY(getRandomNumber(-1000, -5500, 'e'));
            racer.setLife(racer.getLife() - 1);
            if (bulletCount > 0) {
                bulletCount--;
            }
        }
    }

}
void Game::respawn(){

    //// Power ups
    if (getPPdistance(power, racer) < 40) {
        power.setPosY(getRandomNumber(-10000, -20000, 'e'));
        power.setPosX(getRandomNumber(600, 1150, 'e'));

        racer.setLife(racer.getLife() + 1);

        if (bulletCount < 10) {
            bulletCount += 5;
        }
    }
    if (power.getPosY() > 1080) {
        power.setPosY(getRandomNumber(-5000, -8000, 'e'));
        power.setPosX(getRandomNumber(600, 1150, 'e'));
    }

    ////Respawn Obstacles
    for (int i = 0; i < obsVect.size(); i++) {
        if (obsVect[i].getPosY() > 1200) {
            if (i == 0) {
                obsVect[i].setPosY(getRandomNumber(-1500, -2000, 'e'));
            }
            else if (i == 1) {
                obsVect[i].setPosY(getRandomNumber(-2500, -3500, 'e'));
            }
            else if (i == 2) {
                obsVect[i].setPosY(getRandomNumber(-4000, -5000, 'e'));
            }
            else if (i == 3) {
                obsVect[i].setPosY(getRandomNumber(-5500, -6500, 'e'));
            }
        }
    }
}
void Game::render() {
    window.clear();

    //// Background
    window.draw(mainCover);
    window.draw(mainBG);
    window.draw(mainBG2);
    window.draw(mainBG3);
    window.draw(mainBG4);

    //// Render Player
    racer.drawPlayer(window);

    //// Render Enemies
    for (int i = 0; i < enemyVect.size(); i++) {
        enemyVect[i].drawEnemy(window);
    };

    ///// Render Obstacles
    for (int i = 0; i < obsVect.size(); i++) {
        obsVect[i].drawObs(window);
    }

    //// Render PowerUP
    power.drawObs(window);

    ////Render Coin
    for (int i = 0; i < coinVect.size(); i++) {
        coinVect[i].update();
        window.draw(coinVect[i].sprite);
        coinVect[i].updateCoin();
    }

    //// Explosion
    if (collided) {
        for (int i = 0; i < explode.size(); i++) {
            explode[i].update();
            window.draw(explode[i].sprite);
            if (explode[i].isEnd()) {
                explode.pop_back();
                collided = false;
            };
        }

        if (explode.empty()) {
            fire = false;
        }
    }

    if (fire) {
        for (int i = 0; i < bullet.size(); i++) {
            bullet[i].update();
            window.draw(bullet[i].sprite);
            bullet[i].updateBullet();

            if (bullet[i].getPosY() < 300) {
                bullet.erase(bullet.begin());
            }
        }

        if (bullet.empty()) {
            fire = false;
        }
    }

    if (bulletCollide) {
        for (int i = 0; i < enemyExplode.size(); i++) {
            enemyExplode[i].update();
            window.draw(enemyExplode[i].sprite);

            if (enemyExplode[i].isEnd()) {
                enemyExplode.erase(enemyExplode.begin() + 0);
            }
        }
        if (enemyExplode.empty()) {
            bulletCollide = false;
        }
    }

    //// Render ScoreBoard
    window.draw(scoreBoard);

    //// Render Score
    window.draw(scoreText);
    window.draw(lifeText);
    window.draw(bulletText);

    window.display();
}
void Game::processEvent() {
    Event event;
    while (window.pollEvent(event)) {
        switch (event.type) {
            case Event::Closed:
                window.close();
                break;
            case Event::KeyPressed:
                if (event.key.code == Keyboard::Space){
                    if (bulletCount > 0) {
                        fire = true;
                        bullet.push_back(Bullet(bulletTxt, racer.getPosX(), racer.getPosY(), 32, 64, 16, 0.25));
                        bulletCount--;
                    }
                }
                break;
        }
    }
}
//// e = enemy, i = image, s = speed, c = coin
float Game::getRandomNumber(float a, float b, char ch)
{
    static bool first = true;
    if (first) {
        srand(time(NULL));
        first = false;
    }
    float result = a +  rand() % (int) ((b + 1) - a);

    if (ch == 'e') {
        result = (result / 10) * 10;
        return result;
    }
    else if (ch == 'i' || ch == 's' || ch == 'c') {
        return result;
    }
    return result;
}
string Game::getRandomImage() {
    stringstream ss;
    ss << getRandomNumber(1, 7, 'i');
    string imgTag = ss.str();
    string imgDir = "images/obs" + imgTag + ".png";
    return imgDir;
}

float Game::getDistance(float x1, float y1, float x2, float y2) {
    return sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
}

void Game::setEnemNewPosition(Enemy &enem, int num, float speed) {
    switch(num)
    {
        case 0:
            enem.setPosY(getRandomNumber(-1000, -2000, 'e'));
            break;
        case 1:
            enem.setPosY(getRandomNumber(-1500, -2500, 'e'));
            break;
        case 2:
            enem.setPosY(getRandomNumber(-2000, -3000, 'e'));
            break;
        case 3:
            enem.setPosY(getRandomNumber(-2500, -3500, 'e'));
            break;
        case 4:
            enem.setPosY(getRandomNumber(-3000, -4000, 'e'));
            break;
    }
    enem.setNewTexture(getRandomImage());
    enem.setSpeed(getRandomNumber(3, speed, 's'));

}

float Game::getCPdistance(Coin& c, Player& p) {
    return sqrt(pow((p.getPosX() - c.getPosX()),2) + pow((p.getPosY() - c.getPosY()),2));
}

float Game::getPPdistance(PowerUP& pp, Player& p) {
    return sqrt(pow((p.getPosX() - pp.getPosX()), 2) + pow((p.getPosY() - pp.getPosY()), 2));
}

void Game::setCoinNewPosition(Coin& coin, int num) {
    switch(num)
    {
        case 0:
            coin.setNewPos(getRandomNumber(705, 805, 'c'), getRandomNumber(-1500, -1700, 'c'));
            break;
        case 1:
            coin.setNewPos(getRandomNumber(855, 955, 'c'), getRandomNumber(-2700, -2900, 'c'));
            break;
        case 2:
            coin.setNewPos(getRandomNumber(1005, 1055, 'c'), getRandomNumber(-3900, -4100, 'c'));
            break;
        case 3:
            coin.setNewPos(getRandomNumber(1105, 1155, 'c'), getRandomNumber(-5100, -5300, 'c'));
            break;
        case 4:
            coin.setNewPos(getRandomNumber(1205, 1255, 'c'), getRandomNumber(-6300, -6500, 'c'));
            break;
    }
}

float Game::getOPDistance(Obstacle& obj1, Player& obj2) {
    return sqrt(pow((obj2.getPosX() - obj1.getPosX()), 2) + pow((obj2.getPosY() - obj1.getPosY()), 2));;
}

void Game::endGame() {
    Text gameOver, scoreDisplay;
    gameOver.setFont(normalFont);
    gameOver.setCharacterSize(127);
    string s = "Game Over";
    string sub;
    gameOver.setPosition(Vector2f(window.getSize().x/5+50, window.getSize().y/3));

    RectangleShape rect;
    rect.setFillColor(Color(0,0,0,77));
    rect.setSize(Vector2f(window.getSize()));

    for(int i = 0 ; i != s.length()+1; i++){
        sub.append(s,i,1);
        gameOver.setString(sub);
        window.draw(rect);
        window.draw(gameOver);
        window.display();
        Sleep(200);
    }

    scoreDisplay.setFont(normalFont);
    string Score = "Your Score: " + to_string((int)score);
    scoreDisplay.setCharacterSize(77);
    scoreDisplay.setPosition(sf::Vector2f(window.getSize().x/5+50,window.getSize().y/2));
    scoreDisplay.setString(Score);
    window.draw(scoreDisplay);

    window.display();
    Sleep(1500);
}
