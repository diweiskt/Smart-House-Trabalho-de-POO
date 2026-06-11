#include "ArCondicionado.h"
#include <iostream>

ArCondicionado::ArCondicionado(int id, std::string nome, float consumoWatts, float temperaturaAlvo, std::string modo)
    : Dispositivo(id, nome, consumoWatts){
        this->temperaturaAlvo = temperaturaAlvo;
        this->modo = modo;
    }

ArCondicionado::~ArCondicionado(){}

void ArCondicionado::ajustarTemperatura(float novaTemperatura){
    this->temperaturaAlvo = novaTemperatura;
    std::cout << "[INFO] A temperatura do Ar Condicionado " << nome << " foi alterada para " << temperaturaAlvo << ".\n";
}

void ArCondicionado::mudarModo(std::string novoModo){
    this->modo = novoModo;
    std::cout << "[INFO] O modo do Ar Condicionado " << nome << " foi alterado para " << modo << ".\n";
}

float ArCondicionado::getConsumoAtual() const{
    if (ligado){
        if(modo == "Turbo"){
            return consumoWatts * 1.2f; // Consome 20% a mais se for Turbo
        }
        return consumoWatts;
    }
    return 0.0f;
}