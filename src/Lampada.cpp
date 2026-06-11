#include "Lampada.h"
#include <iostream>


Lampada::Lampada(int id, std::string nome, float consumoWatts, std::string cor, int brilho)
    : Dispositivo(id, nome, consumoWatts){
        this->cor = cor;
        this->brilho = brilho;
    }

Lampada::~Lampada(){}

void Lampada::mudarCor(std::string novaCor){
    this->cor = novaCor;
    std::cout << "[INFO] A cor da lâmpada " << nome << " mudou para " << cor << ".\n";
}

void Lampada::mudarBrilho(int novoBrilho){
    this->brilho = novoBrilho;
    std::cout << "[INFO] O brilho da lâmpada " << nome << " mudou para " << brilho << ".\n";
}