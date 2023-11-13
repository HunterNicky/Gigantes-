#pragma once

#include <SFML/Graphics.hpp>

namespace Gerenciadores{
    class GerenciadorGrafico{
        private:
            sf::RenderWindow* window;
            sf::View view;
            static GerenciadorGrafico* instance;
            GerenciadorGrafico();
        public:
            ~GerenciadorGrafico();
            static GerenciadorGrafico* getInstance();
            void display();
            void clear();
            void close();
            const bool isWindowOpen() const;
            const bool pollEvent(sf::Event &event);
            void draw(const sf::Drawable *drawable);
            void drawText(const sf::Text *text);
            void setViewCenter(sf::Vector2f center);
            const sf::Vector2f getViewCenter() const;
    };
}