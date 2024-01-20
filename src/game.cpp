#include "header/game.hpp"

Game::Game() : widthWindow(1500), heightWindow(1300) {
    window = new sf::RenderWindow(sf::VideoMode(widthWindow, heightWindow), "Game");
    window->setFramerateLimit(60);

    states.push(new Entry(window, &states));
}

Game::~Game() {
    while (!states.empty()) 
    {
        State* tmp =  states.top();
        states.pop();
        delete tmp;
    }
    delete window;
    window = nullptr;
    std::cout << "Deallocated ok!\n";
}

void Game::run() {
    while (window->isOpen()) 
    {
        handleEvent();
        update();
        render();
    }
}

void Game::handleEvent() {
    if (!states.empty()) 
        states.top()->handleEvent();
    else 
        window->close();
}

void Game::update() 
{
    if (!states.empty()) 
        states.top()->update();
    else 
        window->close();
}

void Game::render() 
{
    window->clear(sf::Color::White);
    if (!states.empty()) 
        states.top()->render();
    window->display();
}