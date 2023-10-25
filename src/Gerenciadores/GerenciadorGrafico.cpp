#include "..\..\include\Gerenciadores\GerenciadorGrafico.hpp"

Gerenciadores::GerenciadorGrafico* Gerenciadores::GerenciadorGrafico::instance = nullptr;

Gerenciadores::GerenciadorGrafico* Gerenciadores::GerenciadorGrafico::getInstance(){
    if(instance == nullptr){
        instance = new GerenciadorGrafico();
    }
    return instance;
}

Gerenciadores::GerenciadorGrafico::GerenciadorGrafico():
window(new sf::RenderWindow(sf::VideoMode(1280,720),"Minion++")),
view(sf::Vector2f(1280/2,720/2), sf::Vector2f(1280,720)){}

Gerenciadores::GerenciadorGrafico::~GerenciadorGrafico(){}

void Gerenciadores::GerenciadorGrafico::display(){
    if(isWindowOpen()){
        window->display();
    }
}

void Gerenciadores::GerenciadorGrafico::clear(){
    if(isWindowOpen()){
        window->clear();
    }
}

void Gerenciadores::GerenciadorGrafico::close(){
    if(isWindowOpen()){
        window->close();
    }
}

void Gerenciadores::GerenciadorGrafico::draw(const sf::Drawable &drawable){
    if(isWindowOpen()){
        window->draw(drawable);
    }
}

const bool Gerenciadores::GerenciadorGrafico::isWindowOpen(){
    return window->isOpen();
}

const bool Gerenciadores::GerenciadorGrafico::pollEvent(sf::Event &event){
    return window->pollEvent(event);
}
