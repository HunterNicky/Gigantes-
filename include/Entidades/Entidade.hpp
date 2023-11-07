#pragma once
#include "..\Ente.hpp"
#include "..\Gerenciadores\GerenciadorDeColisao.hpp"
namespace Gerenciadores{
    class GerenciadorDeColisao; 
}
namespace Entidades{
    enum class ID{
        empty = 0,
        jogador,
        Inimigo,
        Plataforma,
        Caixa, 
        Gosma,
        Lava
    };

    class Entidade : public Ente{
        protected:
            int id;
            sf::RectangleShape* body;
            Gerenciadores::GerenciadorDeColisao* gColisao;
            const Entidades::ID ID;
        public:
            Entidade(const sf::Vector2f pos, const sf::Vector2f size, const Entidades::ID id);
            virtual ~Entidade();
            const Entidades::ID getId() const;
            void setBody(sf::RectangleShape* body);
            void setGerenciadorDeColisao(Gerenciadores::GerenciadorDeColisao* gColisao);
            sf::RectangleShape* getBody();
            virtual void executar() = 0;
            virtual void update() = 0;
            virtual void tratarColisao(Entidades::Entidade* entidade) = 0;
            virtual void draw();
    };
}