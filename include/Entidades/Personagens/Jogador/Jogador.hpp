#pragma once

#include "..\Personagem.hpp"

namespace Entidades{
    namespace Personagens{
        class Jogador: public Personagem {
        private:
            void inicializa();
        public:
            Jogador(const sf::Vector2f pos, const sf::Vector2f size, const Entidades::ID id);
            ~Jogador();
            void operator--(const int dano);
            void move();
            void neutralizarInimigo(Entidade* pInimigo);
            void tratarColisao(Entidade* entidade);
            void parar();
            void executar();
            void update();
        };
    }
}
