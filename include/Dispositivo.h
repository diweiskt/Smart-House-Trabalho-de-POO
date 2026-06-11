#ifndef DISPOSITIVO_H
#define DISPOSITIVO_H

#include <string>

class Dispositivo {
protected:
    int id;
    std::string nome;
    bool ligado;
    float consumoWatts;

public:

    Dispositivo(int id, std::string nome, float consumoWatts);

    virtual ~Dispositivo();

    virtual void ligar();
    virtual void desligar();
    
    bool isLigado() const;
    std::string getNome() const;

    virtual float getConsumoAtual() const;

};

#endif