#pragma once

#include "Observer.hpp"
#include "..\Entidades\Personagens\Jogador\Jogador.hpp"
#include "..\Estados\MaquinaDeEstado.hpp"

namespace Entidades{
    namespace Personagens{
        class Jogador;
    }
}

namespace Observadores{
    class ControleJogador : public Observer{
        private:
            static Estados::MaquinaDeEstado* pMaquinaDeEstado;
            Entidades::Personagens::Jogador* pJogador;
            std::string pular, esquerda, direita;
            std::string fechar;
        public:
            ControleJogador(Entidades::Personagens::Jogador* pJogador);
            ~ControleJogador();
            void setJogador(Entidades::Personagens::Jogador* pJogador);
            void notifyPressed(std::string key);
            void notifyReleased(std::string key);
    };
}