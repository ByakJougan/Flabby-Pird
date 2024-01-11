#include "header/calculator.hpp"

Calculator::Calculator() : widthWindow(1300), heightWindow(900) {
    window = new sf::RenderWindow(sf::VideoMode(widthWindow, heightWindow), "Calculator");
    window->setFramerateLimit(60);

    states.push(new Entry(window, &states));
}

Calculator::~Calculator() {
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

void Calculator::run() {
    while (window->isOpen()) 
    {
        handleEvent();
        update();
        render();
    }
}

void Calculator::handleEvent() {
    if (!states.empty()) 
        states.top()->handleEvent();
    else 
        window->close();
}

void Calculator::update() 
{
    if (!states.empty()) 
        states.top()->update();
    else 
        window->close();
}

void Calculator::render() 
{
    window->clear(sf::Color::White);
    if (!states.empty()) 
        states.top()->render();
    window->display();
}