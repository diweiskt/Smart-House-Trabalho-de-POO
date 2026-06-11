#include "Comodo.h"
#include <iostream>

Comodo::Comodo(std::string nome) {
    this->nome = nome;
}

Comodo::~Comodo() {}

void Comodo::adicionarDispositivo(Dispositivo* dispositivo) {
    dispositivos.push_back(dispositivo);
}

void Comodo::desligarTudo() {
    std::cout << "[INFO] Desligando todos os aparelhos do cômodo: " << nome << "\n";
    
    for(Dispositivo* d : dispositivos){
        d->desligar();
    }
}

const std::vector<Dispositivo*>& Comodo::getDispositivos() const {
    return dispositivos;
}

std::string Comodo::getNome() const {
    return nome;
}