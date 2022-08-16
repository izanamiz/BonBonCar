#include "Header.hpp"

class Load
{
public:
    Load();
    void run();

private:
    RenderWindow lWindow;
    Font lFont;
    Text lText, load;
    Texture loadTxt;
    Sprite loadSpr;
};

Load ::Load() : lWindow(sf::VideoMode(1920,1080), "BON BON CAR"),lFont(),lText()
{
    lWindow.setPosition(sf::Vector2i(0,0));
    lWindow.setFramerateLimit(60);
    if(!lFont.loadFromFile("fonts/PaladinsCondensed-rB77.otf"))
        cout<<"Error Loading menu font"<<endl;
    lText.setFont(lFont);
    lText.setString("BON BON CAR");
    lText.setCharacterSize(200);
    lText.setColor(sf::Color(0,0,0));
    lText.setPosition(100,50);

    if(!loadTxt.loadFromFile("images/car.png")) {
        cout << "Error loading load texture";
    }
    loadSpr.setTexture(loadTxt);
    loadSpr.setPosition(300,400);
}

void Load::run()
{
    lWindow.clear();
    sf::Event event;

    for (int i = 0; i < 50 ; i++)
    {
        while (lWindow.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
                lWindow.close();
            break;
        }
        lWindow.draw(loadSpr);
        lText.setColor(sf::Color(rand()%255,rand()%255,rand()%255));

        Sleep(50);
        lWindow.draw(lText);
        lWindow.display();
    }
    lWindow.close();
}