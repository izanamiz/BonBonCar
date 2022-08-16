#ifndef BONBONCAR_MENU_HPP
#define BONBONCAR_MENU_HPP

#include "Header.hpp"
#include "Game.hpp"
#include "Load.hpp"

class Menu
{
public:
    Menu();
    void run();
private:
    void processEvents();
    void updateOptionText();
    void render();
    void exitMenu();
    void instructions();

private:
    string Option[3] = { "PLAY","INSTRUCTIONS","EXIT"};
    RenderWindow window;
    Texture startTxt;
    Sprite startSpr;
    Font titleFont, selectFont;
    Text titleText;
    vector<Text> options;
    int optionIndex;
    Game game;
    Load load;

    string Instruction;
    Text instructionTxt;
    Sprite background;

};


Menu ::Menu() : window(VideoMode(1920,1080), "Bon Bon Car"),
                startTxt(),startSpr(),optionIndex(-1),background(), Instruction(),instructionTxt()
{
    window.setFramerateLimit(60);
    window.setPosition(Vector2i(0,0));
    if(!startTxt.loadFromFile("images/start.jpg"))
    {
        cout<<"No File!!"<<endl;
    }
    startSpr.setTexture(startTxt);
    startSpr.setPosition(0,0);

    if(!titleFont.loadFromFile("fonts/PaladinsCondensed-rB77.otf"))
        cout << "Error Loading menu font"<<endl;
    titleText.setFont(titleFont);
    titleText.setString("Bon Bon Car");
    titleText.setCharacterSize(200);
    titleText.setStyle(Text::Bold);
    titleText.setColor(Color::Black);
    titleText.setPosition(Vector2f(100, 20));

    if(!selectFont.loadFromFile("fonts/leafy.otf"))
        cout<<"Error Loading menu font"<<endl;

    Instruction = "\t\t\t\t\t\t Instructions \n\n\t\t\t\t\t Keys \n\t\t\t\t Right : Drift Right \n\t\t\t\t Left  : Drift Left \n\t\t\t\t Up    : Drift Up \n\t\t\t\t Down  : Drift Down \n\t\t\t\t Space : Shoot";
    instructionTxt.setFont(selectFont);
    instructionTxt.setColor(Color::Yellow);
    instructionTxt.setString(Instruction);
    instructionTxt.setCharacterSize(100);

    background.setTexture(startTxt);
    background.setColor(sf::Color(255,255,255,150));

    for(int i = 0; i<3 ; i++)
    {
        Text tempOption;
        tempOption.setFont(selectFont);
        tempOption.setString(Option[i]);
        tempOption.setColor(Color::Black);
        tempOption.setCharacterSize(100);
        tempOption.setPosition(Vector2f(window.getSize().x/3+50,window.getSize().y/3+(i*150)));
        options.push_back(tempOption);
    }
}

void Menu::run()
{
    while (window.isOpen())
    {
        processEvents();
        render();
    }
}

void Menu::processEvents()
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        if(event.type == sf::Event::Closed)
            exitMenu();
        if (event.type==sf::Event::KeyPressed)
        {
            if (event.key.code == sf::Keyboard::Up)
            {
                if (optionIndex > 0)
                    optionIndex--;
                else
                    optionIndex = options.size() - 1;
                updateOptionText();
            }
            else if (event.key.code == sf::Keyboard::Down)
            {
                if (optionIndex < options.size() - 1)
                    optionIndex++;
                else
                    optionIndex = 0;
                updateOptionText();
            }

            if (event.key.code == sf::Keyboard::Return)
            {
                switch(optionIndex)
                {
                    case 0 :
                        window.close();
                        load.run();
                        game.run();
                        break;
                    case 1 :
                        instructions();
                        break;
                    case 2 :
                        exitMenu();
                }
            }
        }
    }
}

void Menu::updateOptionText()
{
    if (options.empty())
        return;
    for(int i = 0 ; i < 4 ; i++)
    {
        options[i].setColor(Color::Black);
        options[i].setCharacterSize(100);
    }
    options[optionIndex].setColor(Color::Red);
    options[optionIndex].setStyle(Text::Bold | Text::Underlined);
    options[optionIndex].setCharacterSize(120);
}

void Menu::render()
{
    window.clear();
    window.draw(startSpr);
    window.draw(titleText);
    for(int i = 0; i<options.size(); i++)
        window.draw(options[i]);
    window.display();
}

void Menu :: exitMenu(void)
{
    int msgboxID = MessageBox(NULL, "Are you sure you want to Exit?", "EXIT", MB_ICONWARNING | MB_YESNO | MB_DEFBUTTON2);
    switch (msgboxID)
    {
        case IDYES:
            window.close();
            exit(1);
        case IDNO:
            break;
    }
}
void Menu::instructions()
{
    window.clear();
    window.draw(background);
    window.draw(instructionTxt);
    window.display();
    Sleep(2000);
    Menu();
}



#endif //BONBONCAR_MENU_HPP
