#include "..\..\..\include\Entidades\Obstaculos\Lava.hpp"
#include "Animacao/AnimacaoBloco.hpp"
#include "Animacao/AnimacaoContext.hpp"
#include "Entidades/Entidade.hpp"
#include "Entidades/Obstaculos/Lava.hpp"
#include "Entidades/Personagens/Personagem.hpp"
#include <cstdlib>
#include <iostream>

namespace Entidades {
namespace Obstaculos {
unsigned int Lava::queimadura = 50;

Lava::Lava(const sf::Vector2f pos, const sf::Vector2f size,
           const Entidades::ID id)
    : Obstaculo(pos, size, id),
      bloco(static_cast<Entidades::Entidade *>(this), CAMINHO_BLOCO_LAVA, 10,
            sf::Vector2f(1, 1)),
      contexto() {
  this->body->setFillColor(sf::Color::Red);
  contexto.setStrategy(&bloco, 0.1);
}

Lava::Lava(nlohmann::json atributos, const int pos, const Entidades::ID id)
    : Obstaculo(sf::Vector2f(atributos[pos]["Posicao"][0],
                             atributos[pos]["Posicao"][1]),
                sf::Vector2f(atributos[pos]["Tamanho"][0],
                             atributos[pos]["Tamanho"][1]),
                id),
      bloco(static_cast<Entidades::Entidade *>(this), CAMINHO_BLOCO_LAVA, 10,
            sf::Vector2f(1, 1)),
      contexto() {
  this->body->setFillColor(sf::Color::Red);
  contexto.setStrategy(&bloco, 0.1);
}
Lava::~Lava() {}

void Lava::animacao() { contexto.updateStrategy(gFisico->getDeltaTime()); }

void Lava::queimar(Entidade *entidade) {
  Entidades::Personagens::Personagem *pPers =
      static_cast<Entidades::Personagens::Personagem *>(entidade);

  pPers->operator--(queimadura);
}

void Lava::tratarColisao(Entidade *entidade, const sf::Vector2f mtv) {
  if (entidade) {
    if (entidade->getId() == Entidades::ID::jogador) {
      queimar(entidade);
    }
  }
}

void Lava::executar() { animacao(); }

void Lava::update() { executar(); }

void Lava::salvar(std::ostringstream *entrada) {
  (*entrada) << "{ \"ID\": [" << 8 << "], \"Posicao\": [" << pos.x << " , "
             << pos.y << "],  \"Tamanho\": [" << this->getSize().x << " , "
             << this->getSize().y << "] }" << std::endl;
}
} // namespace Obstaculos
} // namespace Entidades