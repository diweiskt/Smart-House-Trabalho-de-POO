#include "Dispositivo.h"
#include <iostream>

Dispositivo::Dispositivo(int id, std::string nome, float consumoWatts){
    this->id = id;
    this->nome = nome;
    this->consumoWatts = consumoWatts;
    this->ligado = false;
}

Dispositivo::~Dispositivo(){
}

void Dispositivo::ligar(){
    ligado = true;
    std::cout << "[INFO] " << nome << " foi ligado.\n";
}

void Dispositivo::desligar(){
    ligado = false;
    std::cout << "[INFO] " << nome << " foi desligado.\n";
}

bool Dispositivo::isLigado() const{
    return ligado;
}

std::string Dispositivo::getNome() const{
    return nome;
}

float Dispositivo::getConsumoAtual() const{
    if(ligado){
        return consumoWatts;
    }
    return 0.0f;
};