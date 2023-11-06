#include "..\..\include\Gerenciadores\GerenciadorDeColisao.hpp"
#include <iostream>
#include "GerenciadorDeColisao.hpp"

namespace Gerenciadores{
    GerenciadorDeColisao::GerenciadorDeColisao(Lista::ListaDeEntidades *LE):
    LE(LE){}

    GerenciadorDeColisao::~GerenciadorDeColisao(){}

    void GerenciadorDeColisao::Notify(Entidades::Entidade* entidade, const sf::Vector2f mtv) const override{
        entidade->getBody()->move(mtv);
    }

    bool GerenciadorDeColisao::collisionDetection void GerenciadorDeColisao::Notify(Entidades::Entidade *entidade, const sf::Vector2f mtv) const {}(const sf::Drawable *drawable1, const sf::Drawable *drawable2, sf::Vector2f *mtv)
    {
        const sf::FloatRect &rs1 = static_cast<const sf::RectangleShape&>(*drawable1).getGlobalBounds();
        const sf::FloatRect &rs2 = static_cast<const sf::RectangleShape&>(*drawable2).getGlobalBounds();
        sf::Vector2f projection;
        sf::Vector2f overlap;

        projection.x = std::max(rs1.left + rs1.width, rs2.left + rs2.width) - std::min(rs1.left, rs2.left);
        if (projection.x < (rs1.width + rs2.width)) {
            overlap.x = (rs1.width + rs2.width) - projection.x;
            projection.y = std::max(rs1.top + rs1.height, rs2.top + rs2.height) - std::min(rs1.top, rs2.top);

            if (projection.y < (rs1.height + rs2.height)) {
                overlap.y = rs1.height + rs2.height - projection.y;
                mtv->x = mtv->y = 0;
                if (overlap.x < overlap.y) {
                    mtv->x = overlap.x * (rs1.left < rs2.left ? -1 : 1);
                } else {
                    mtv->y = overlap.y * (rs1.top < rs2.top ? -1 : 1);
                }
                return true;
            }
        }
        return false;
    }

    void GerenciadorDeColisao::checkCollision() {
        Lista::ListaDeEntidades* listaEntidades = LE;

        for (unsigned int i = 0; i < listaEntidades->getSize(); i++) {
            for (unsigned int j = i + 1; j < listaEntidades->getSize(); j++) {
                Entidades::Entidade* entidade1 = (*listaEntidades)[i];
                Entidades::Entidade* entidade2 = (*listaEntidades)[j];

                if (entidade1 != entidade2) {
                    sf::Vector2f mtv;
                    if (collisionDetection(entidade1->getBody(), entidade2->getBody(), &mtv)) {
                        if((entidade1->getId() == 2 || entidade1->getId() == 1) && (entidade2->getId() == 2 || entidade2->getId() == 1))
                            entidade1->getBody()->move(mtv);
                        else if((entidade1->getId() == 2 || (entidade1->getId() == 1)) && entidade2->getId() == 3)
                            entidade1->getBody()->move(mtv);
                        else if(entidade1->getId() == 3 && (entidade2->getId() == 2 || entidade2->getId() == 1))
                            entidade2->getBody()->move(-mtv);
                    }

                }
            }
        }
    }
}