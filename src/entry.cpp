#include "header/entry.hpp"
#include <iostream>

Entry::Entry(sf::RenderWindow* window, std::stack <State*>* states) : window(window), states(states)
{
    initShape();
}

void Entry::initShape() 
{
    shape.setSize(sf::Vector2f(100, 100));
    shape.setFillColor(sf::Color::Green);
    shape.setPosition(sf::Vector2f(100, 100));
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
                    if (shape.getGlobalBounds().contains(mousePosition.x, mousePosition.y)) 
                    {
                        std::cout << "Clicked!\n";
                    }
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
    if(shape.getGlobalBounds().contains(mousePosition.x, mousePosition.y)) 
        shape.setFillColor(sf::Color(255, 255, 255, 255));
    else
        shape.setFillColor(sf::Color(255, 255, 255, 200));
}

void Entry::render() {
    window->draw(shape);
}