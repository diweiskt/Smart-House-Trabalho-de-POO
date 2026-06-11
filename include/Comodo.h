#ifndef COMODO_H
#define COMODO_H

#include <string>
#include <vector>
#include "Dispositivo.h"

class Comodo {
private:
    std::string nome;
    std::vector<Dispositivo*> dispositivos;

public:

    Comodo(std::string nome);
    virtual ~Comodo();

    void adicionarDispositivo(Dispositivo* dispositivo);

    void desligarTudo();

    const std::vector<Dispositivo*>& getDispositivos() const;
    std::string getNome() const;
};

#endif