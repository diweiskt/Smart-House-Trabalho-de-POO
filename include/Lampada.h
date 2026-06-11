#ifndef LAMPADA_H
#define LAMPADA_H

#include "Dispositivo.h"
#include <string>

class Lampada : public Dispositivo{
private:
    std::string cor;
    int brilho;

public:
    Lampada(int id, std::string nome, float consumoWatts, std::string cor, int brilho);

    virtual ~Lampada();

    void mudarCor(std::string novaCor);

    void mudarBrilho(int novoBrilho);

};

#endif