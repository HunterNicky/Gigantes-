#pragma once

#include "Inimigo.hpp"
#include <math.h>
namespace Estados{
    namespace Fases{
            class Fase;
    }
}

#define RANGE 200.0f
namespace Entidades{
    namespace Personagens{
        class InimigoMedio: public Inimigo{
        private:
            Estados::Fases::Fase* pFase;
            int dano;
            int moveAleatorio;
            void inicializa();
        public:
            InimigoMedio(const sf::Vector2f pos, const sf::Vector2f size, const Entidades::ID id, Entidades::Personagens::Jogador* pJog, Estados::Fases::Fase* pFase);
            ~InimigoMedio();
            void operator--(const int dano);
            void movimentoAleatorio();
            void atirarProjetil(sf::Vector2f pos, const bool direita);
            void move();
            void danificar(Entidade* entidade);
            void tratarColisao(Entidade* entidade);
            void executar();
            void update() ;
        };
    }
}