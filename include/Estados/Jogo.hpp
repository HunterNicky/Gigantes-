#pragma once

#include "..\Entidades\Personagens\Jogador\Jogador.hpp"
#include "..\Gerenciadores\GerenciadorDeEvento.hpp"
#include "..\Gerenciadores\GerenciadorGrafico.hpp"
#include "..\Menu\MenuPrincipal.hpp"
#include "..\Observadores\ControleMenu.hpp"
#include "MaquinaDeEstado.hpp"

namespace Estados{

    class Jogo{
    private:
        static Gerenciadores::GerenciadorGrafico* pGrafico;
        static Gerenciadores::GerenciadorDeEvento* pEvento;
        static Estados::MaquinaDeEstado* pMaquinaDeEstado;
        sf::Time tick, dt;
        sf::Clock clock;
    public:
        Jogo();
        ~Jogo();
        void executar();
        void atualizarJogo();
    };

}