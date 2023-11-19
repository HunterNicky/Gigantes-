#include "..\..\include\Observadores\ControleJogador.hpp"
#include "Estados/Estado.hpp"
#include "Menu/MenuPausa.hpp"
#include "Observadores/ControleMenu.hpp"

namespace Observadores{
    Estados::MaquinaDeEstado* ControleJogador::pMaquinaDeEstado = Estados::MaquinaDeEstado::getInstance();

    ControleJogador::ControleJogador(Entidades::Personagens::Jogador *pJogador):
    Observer(),
    pJogador(pJogador),
    pular("W"), esquerda("A"), direita("D"), correr("LShift"), fechar("Escape"){
    }

    ControleJogador::~ControleJogador(){
    }

    void ControleJogador::setJogador(Entidades::Personagens::Jogador *pJogador){
        this->pJogador = pJogador;
    }
    void ControleJogador::notifyPressed(const std::string key){
        if(pJogador && pMaquinaDeEstado->getEstadoAtual()->getAtivo()){
            if(key == direita){
                pJogador->direcionar(true);
            }else if(key == esquerda){
                pJogador->direcionar(false);
            }
            if(key == pular){
                pJogador->pular();
            }else if(key == correr){
                pJogador->correr();
            }
            if(key == fechar){
                Menu::MenuPausa* pPausa = new Menu::MenuPausa();
                pMaquinaDeEstado->pushEstado(static_cast<Estados::Estado*>(pPausa));
            }
        }
    }

    void ControleJogador::notifyReleased(const std::string key){
        if(pJogador){
            if(key == direita){
                pJogador->parar();
            }else if(key == esquerda){
                pJogador->parar();
            }else if(key == correr){
                pJogador->parar();
            }else if(key == pular){
                pJogador->setOnFloor(false);
                pJogador->pular();
            }
        }
    }
}
