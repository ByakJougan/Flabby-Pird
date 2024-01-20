#pragma once
#ifndef ENTRY_HPP
#define ENTRY_HPP

#include "state.hpp"
#include <stack>
#include <SFML/Graphics.hpp>

class Game;

class Entry : public State {
    public :
        Entry(sf::RenderWindow* window, std::stack <State*>* states);
        void initShape();
        void handleEvent();
        void update();
        void render();
        
    private :
        sf::RenderWindow* window;
        std::stack <State*>* states;

        sf::Event event;
        sf::Vector2i mousePosition;

        sf::Texture backgroundTexture;
        sf::Sprite backgroundImage;
};

#endif
