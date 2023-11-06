#pragma once

#include "..\Gerenciadores\GerenciadorGrafico.hpp"
#include "..\Gerenciadores\GerenciadorDeColisao.hpp"
#include "..\Gerenciadores\GerenciadorFisico.hpp"
#include "..\Lista\ListaDeEntidades.hpp"
#include "..\Entidades\Personagens\Jogador\Jogador.hpp"
#include "..\Entidades\Personagens\Inimigo\Inimigo.hpp"
#include "..\Entidades\Obstaculos\Caixa.hpp"

namespace Fases{
    class Fase: public Ente{
        protected:
            Gerenciadores::GerenciadorFisico gerenciadorFisico;
            Gerenciadores::GerenciadorDeColisao gerenciadorDeColisao;
            Entidades::Personagens::Jogador* pJogador;
            Lista::ListaDeEntidades LE;
        public:
            Fase();
            ~Fase();
            void newJogador(sf::Vector2f pos, sf::Vector2f size);
            void newInimigo(sf::Vector2f pos, sf::Vector2f size);
            void newObstaculo(sf::Vector2f pos, sf::Vector2f size);
            //void newCaixa(sf::Vector2f pos, sf::Vector2f size);
            //void newEntidade(char letter, sf::Vector2i pos);
            void draw();
            void executar();
            void update();
            virtual void loadMap() = 0;
    };
}