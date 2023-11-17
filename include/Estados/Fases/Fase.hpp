#pragma once

#include "..\..\Gerenciadores\GerenciadorGrafico.hpp"
#include "..\..\Gerenciadores\GerenciadorDeColisao.hpp"
#include "..\..\Lista\ListaDeEntidades.hpp"
#include "..\..\Entidades\Personagens\Jogador\Jogador.hpp"
#include "..\..\Entidades\Personagens\Inimigo\InimigoFacil.hpp"
#include "..\..\Entidades\Personagens\Inimigo\InimigoMedio.hpp"
#include "..\..\Entidades\Personagens\Inimigo\InimigoDificil.hpp"
#include "..\..\Entidades\Projetil\Projetil.hpp"
#include "..\..\Entidades\Obstaculos\Caixa.hpp"
#include "..\..\Entidades\Obstaculos\Lava.hpp"
#include "..\..\Observadores\ControleJogador.hpp"
#include "..\..\Gerenciadores\GerenciadorDeEvento.hpp"
#include "..\Estado.hpp"
#include "..\MaquinaDeEstado.hpp"
#include "Entidades/Entidade.hpp"
#include "Gerenciadores/GerenciadorFisico.hpp"

#include <iostream>
#include <fstream>
#include <sstream>
#include "json.hpp"

namespace Estados{
    namespace Fases{
        class Fase : public Estados::Estado{
            protected:
                static Gerenciadores::GerenciadorGrafico* pGrafico;
                static Gerenciadores::GerenciadorDeEvento* pEvento;
                static Gerenciadores::GerenciadorFisico* pFisico;
                static Gerenciadores::GerenciadorDeColisao* pColisao;
                static MaquinaDeEstado* pMaquinaDeEstado;
                Observadores::ControleJogador* controle;
                Entidades::Personagens::Jogador* pJogador;
                Lista::ListaDeEntidades LE;
                std::ostringstream buffer;
                double dt, alpha;
            public:
                Fase();
                ~Fase();
                void salvar();
                void newJogador(sf::Vector2f pos, sf::Vector2f size);
                void newInimigo(sf::Vector2f pos, sf::Vector2f size);
                void newInimigoMedio(sf::Vector2f pos, sf::Vector2f size);
                void newChefao(sf::Vector2f pos, sf::Vector2f size);
                void newProjetil(sf::Vector2f pos, const bool direita);
                void deleteProjetil();
                //void newPlataforma(sf::Vector2f pos, sf::Vector2f size);
                //void newGosma(sf::Vector2f pos, sf::Vector2f size);
                void newObstaculo(sf::Vector2f pos, sf::Vector2f size);
                void updateVida();
                virtual void recuperarJogada() = 0;
                void update(double dt);
                void executar();
                void draw();
                //virtual void resetEstate() = 0;
                virtual void loadMap() = 0;
        };
    }
}