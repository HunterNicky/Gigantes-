#include "..\..\include\Estados\MaquinaDeEstado.hpp"

namespace Estados{
    MaquinaDeEstado* MaquinaDeEstado::instance = nullptr;

    MaquinaDeEstado* MaquinaDeEstado::getInstance(){
        if(instance == nullptr){
            instance = new MaquinaDeEstado();
        }
        return instance;
    }

    MaquinaDeEstado::MaquinaDeEstado(){
    }

    MaquinaDeEstado::~MaquinaDeEstado(){
    }

    void MaquinaDeEstado::pushEstado(Estado* estado){
        estadoStack.push(estado);
    }

    void MaquinaDeEstado::popEstado(){
        if (!estadoStack.empty()){
            delete estadoStack.top();
            estadoStack.pop();
        }
    }

    void MaquinaDeEstado::trocarEstado(Estado* estado){
        popEstado();
        pushEstado(estado);
    }

    void MaquinaDeEstado::atualizarEstadoAtual(){
        if(!estadoStack.empty()){
            estadoStack.top()->update();
        }
    }

    Estado* MaquinaDeEstado::getEstadoAtual()const{
        return !estadoStack.empty() ? estadoStack.top():nullptr;
    }
}