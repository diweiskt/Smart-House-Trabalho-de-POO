#ifndef ARCONDICIONADO_H
#define ARCONDICIONADO_H

#include "Dispositivo.h"
#include <string>

class ArCondicionado : public Dispositivo {
private:
    float temperaturaAlvo;
    std::string modo;

public:

    ArCondicionado(int id, std::string nome, float consumoWatts, float temperaturaAlvo, std::string modo);
    

    virtual ~ArCondicionado();


    void ajustarTemperatura(float novaTemperatura);

    void mudarModo(std::string novoModo);

    float getConsumoAtual() const override;
};

#endif