#ifndef CASA_H
#define CASA_H

#include <string>
#include <vector>
#include "Comodo.h"

class Casa {
private:
    std::string endereco;
    std::vector<Comodo*> comodos;

public:
    Casa(std::string endereco);
    Casa(std::string endereco, std::vector<Comodo*> comodosIniciais);
    
    virtual ~Casa();

    void adicionarComodo(Comodo* comodo);

    float calcularConsumoTotal() const;
};

#endif