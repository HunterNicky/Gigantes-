#include "..\..\..\include\Entidades\Personagens\Personagem.hpp"

namespace Entidades{
    namespace Personagens{
        Personagem::Personagem(const sf::Vector2f pos, const sf::Vector2f size, const Entidades::ID id):
            Entidade(pos, size, id),
            massa(20)    
        {
            
        }
        Personagem::~Personagem()
        {
        }

        void Personagem::setVel(sf::Vector2f vel){this->vel = vel;}

        void Personagem::setAcc(sf::Vector2f acc){this->acc = acc;}

        void Personagem::setMassa(float massa){this->massa = massa;}

        const sf::Vector2f Personagem::getVel() const{return vel;}

        const sf::Vector2f Personagem::getAcc() const{return acc;}

        const sf::Vector2f Personagem::getForca() const{return forca;}

        const float Personagem::getMass() const{return massa;}

        const int Personagem::getNum_vidas() const{return num_vidas;}

        void Personagem::move(){
            Entidade::body->move(vel);
            gColisao->checkCollision(static_cast<Entidades::Entidade*>(this));
        }

    }
}

