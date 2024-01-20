#include "header/entry.hpp"
#include <iostream>

Entry::Entry(sf::RenderWindow* window, std::stack <State*>* states) : window(window), states(states)
{
    initShape();
}

void Entry::initShape() 
{
    backgroundTexture.loadFromFile("../resources/res/background.png");
    backgroundImage.setTexture(backgroundTexture);
    backgroundImage.setPosition(0, 0);
}

void Entry::handleEvent() 
{
    while (window->pollEvent(event)) 
    {
        switch (event.type) {
            case sf::Event::Closed :
                window->close();
                break ;
                
            case sf::Event::MouseButtonPressed :
                if (event.mouseButton.button == sf::Mouse::Left) 
                {
                    mousePosition = sf::Mouse::getPosition(*window);
                }
                break ;
            case sf::Event::KeyPressed :
                if (event.key.code == sf::Keyboard::Escape) {
                    window->close();
                }
                break ;
            default :
                break ;
        }
    }
}

void Entry::update() 
{

}

void Entry::render() 
{
    window->draw(backgroundImage);
}