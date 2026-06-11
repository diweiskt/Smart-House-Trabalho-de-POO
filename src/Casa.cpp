#include "Casa.h"
#include <iostream>

Casa::Casa(std::string endereco) {
    this->endereco = endereco;
}

Casa::Casa(std::string endereco, std::vector<Comodo*> comodosIniciais) {
    this->endereco = endereco;
    this->comodos = comodosIniciais;
}

Casa::~Casa() {
    for (Comodo* c : comodos) {
        delete c;
    }
    std::cout << "[INFO] A casa foi destruída e todos os cômodos foram limpos da memória.\n";
}

void Casa::adicionarComodo(Comodo* comodo) {
    comodos.push_back(comodo);
}

float Casa::calcularConsumoTotal() const {
    float totalConsumo = 0.0f;

    for(Comodo* c : comodos){
        for(Dispositivo* d : c->getDispositivos()){
            totalConsumo += d->getConsumoAtual();
        }
    }

    return totalConsumo;
}