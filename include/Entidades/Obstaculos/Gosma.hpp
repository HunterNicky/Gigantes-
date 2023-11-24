#pragma once

#include "..\Personagens\Personagem.hpp"
#include "Obstaculo.hpp"

namespace Entidades {
namespace Obstaculos {
class Gosma : public Obstaculo {
private:
  int slow;

public:
  Gosma(const sf::Vector2f pos, const sf::Vector2f size,
        const Entidades::ID id);
  ~Gosma();
  void atrasar(Entidade *entidade);
  void tratarColisao(Entidade *entidade, const sf::Vector2f mtv);
  void executar();
  void update();
  void salvar(std::ostringstream *entrada);
};
} // namespace Obstaculos
} // namespace Entidades