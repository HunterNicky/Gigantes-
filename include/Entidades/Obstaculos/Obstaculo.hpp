#pragma once
#include "Entidades/Entidade.hpp"
#include "Gerenciadores/GerenciadorFisico.hpp"
#include "Animacao/AnimacaoBloco.hpp"
#include "Animacao/AnimacaoContext.hpp"
namespace Entidades{
    namespace Obstaculos{
        class Obstaculo : public Entidade{
        protected:
            static Gerenciadores::GerenciadorFisico* gFisico;
            bool danoso;
        public:
            Obstaculo(const sf::Vector2f pos,  const sf::Vector2f size, const Entidades::ID id);
            ~Obstaculo();
            virtual void verificaSolo(sf::Vector2f mtv);
            virtual void animacao() = 0; 
            virtual void tratarColisao(Entidade* entidade) = 0;
            virtual void executar() = 0;
            virtual void update() = 0;
            virtual void salvar(std::ostringstream* entrada) = 0;
        };
    }
}
