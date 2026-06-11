#include <iostream>
#include <vector>
#include "Casa.h"
#include "Comodo.h"
#include "Lampada.h"
#include "ArCondicionado.h"

int main() {
    std::cout << "MANSÃO INTELIGENTE: SIMULAÇÃO DE CARGA MÁXIMA\n\n";

    // Vetor global para limpar a memória de todos os dispositivos no final
    std::vector<Dispositivo*> centralDispositivos;

    // 1. INSTANCIAÇÃO EM MASSA (Cenário de Alta Carga)
    // DISPOSITIVOS DA SALA DE CINEMA
    Dispositivo* luzCinema1 = new Lampada(101, "Luz dicroica Led 1", 7.0f, "Vermelho", 20);
    Dispositivo* luzCinema2 = new Lampada(102, "Luz dicroica Led 2", 7.0f, "Vermelho", 20);
    Dispositivo* acCinema = new ArCondicionado(103, "Central de Ar Cinema", 2500.0f, 18.0f, "Turbo"); // Override +20%

    // DISPOSITIVOS DA COZINHA INDUSTRIAL
    Dispositivo* luzCozinha = new Lampada(201, "Calha de Led Industrial", 45.0f, "Branco Frio", 100);
    Dispositivo* acCozinha = new ArCondicionado(202, "Ar LG Cozinha", 1800.0f, 21.0f, "Frio");

    // DISPOSITIVOS DA SUÍTE MASTER
    Dispositivo* luzSuite = new Lampada(301, "Plafon Central Quarto", 32.0f, "Branco Neutro", 90);
    Dispositivo* acSuite = new ArCondicionado(302, "Ar Split Suíte", 1200.0f, 23.0f, "Frio");

    // DISPOSITIVOS DO ESCRITÓRIO DE TRADING
    Dispositivo* luzEscritorio = new Lampada(401, "Fita Led Gamer", 15.0f, "Azul", 100);
    Dispositivo* acEscritorio = new ArCondicionado(402, "Ar Escritório", 1200.0f, 22.0f, "Turbo"); // Override +20%

    // DISPOSITIVOS DA ÁREA GOURMET / LAZER
    Dispositivo* luzLazer1 = new Lampada(501, "Refletor Piscina 1", 100.0f, "Verde", 100);
    Dispositivo* luzLazer2 = new Lampada(502, "Refletor Piscina 2", 100.0f, "Verde", 100);
    Dispositivo* acLazer = new ArCondicionado(503, "Ar Central Espaço Gourmet", 3500.0f, 17.0f, "Turbo"); // Override +20%

    // Povoando a central de rastreamento para o delete final
    centralDispositivos = {
        luzCinema1, luzCinema2, acCinema,
        luzCozinha, acCozinha,
        luzSuite, acSuite,
        luzEscritorio, acEscritorio,
        luzLazer1, luzLazer2, acLazer
    };

    // 2. ESTRUTURAÇÃO DOS CÔMODOS
    Comodo* cinema = new Comodo("Home Cinema");
    cinema->adicionarDispositivo(luzCinema1); cinema->adicionarDispositivo(luzCinema2); cinema->adicionarDispositivo(acCinema);

    Comodo* cozinha = new Comodo("Cozinha Industrial");
    cozinha->adicionarDispositivo(luzCozinha); cozinha->adicionarDispositivo(acCozinha);

    Comodo* suite = new Comodo("Suíte Master");
    suite->adicionarDispositivo(luzSuite); suite->adicionarDispositivo(acSuite);

    Comodo* escritorio = new Comodo("Escritório de TI");
    escritorio->adicionarDispositivo(luzEscritorio); escritorio->adicionarDispositivo(acEscritorio);

    Comodo* lazer = new Comodo("Área Gourmet & Piscina");
    lazer->adicionarDispositivo(luzLazer1); lazer->adicionarDispositivo(luzLazer2); lazer->adicionarDispositivo(acLazer);

    // Guardando os cômodos em um vetor para testar o construtor sobrecarregado
    std::vector<Comodo*> todosComodos = { cinema, cozinha, suite, escritorio, lazer };


    // 3. INSTANCIAÇÃO DA CASA USANDO A SOBRECARGA DE CONSTRUTOR
    std::cout << "[POO] Instanciando a Casa utilizando o Construtor Sobrecarregado...\n";
    // Enviamos o vetor inteiro direto no construtor!
    Casa mansao("Condomínio Alphaville, Lote 45", todosComodos);

    // 4. SIMULAÇÃO DE SOBRECARGA ELÉTRICA (Ligar TUDO na casa)
    std::cout << "\nSIMULANDO ATIVAÇÃO DE CARGA MÁXIMA NA REDE\n";
    for (Dispositivo* d : centralDispositivos) {
        d->ligar(); // Liga todos os 12 aparelhos da mansão ao mesmo tempo
    }


    // 5. MEDIÇÃO DO CONSUMO CRÍTICO (Polimorfismo + Substituição de Método)
    std::cout << "\nMEDIÇÃO DE CONSUMO EM TEMPO REAL\n";
    // Os Ares do Cinema (2500W), Escritório (1200W) e Lazer (3500W) estão no modo "Turbo".
    // O algoritmo vai calcular o consumo deles com +20% de gasto devido ao Override.
    float consumoPico = mansao.calcularConsumoTotal();
    std::cout << ">>> CONSUMO DE PICO DA MANSÃO: " << consumoPico << " Watts.\n";


    // 6. ALÍVIO DE CARGA DA REDE (Regra de Negócio 2 em Múltiplos Cômodos)
    std::cout << "\nEXECUTANDO PROTOCOLO DE ECONOMIA DE ENERGIA\n";
    std::cout << "[AUTOMAÇÃO] Desligando setores de alto consumo desocupados...\n";
    cinema->desligarTudo();
    lazer->desligarTudo();
    escritorio->desligarTudo();


    // 7. NOVA MEDIÇÃO PÓS PROTOCOLO
    std::cout << "\nNOVA MEDIÇÃO DE CONSUMO\n";
    float consumoEstabilizado = mansao.calcularConsumoTotal();
    std::cout << ">>> CONSUMO ATUAL REDUZIDO: " << consumoEstabilizado << " Watts.\n";


    // 8. DESALOCAÇÃO COMPLETA DA MEMÓRIA
    std::cout << "\nLIMPANDO RASTROS DE MEMÓRIA\n";
    // Deleta os 12 dispositivos alocados com 'new'
    for (Dispositivo* d : centralDispositivos) {
        delete d;
    }
    std::cout << "[MEMÓRIA] Todos os dispositivos foram destruídos da Memória.\n";

    /* O objeto 'mansao' sai de escopo aqui. O destruidor de 'Casa' vai varrer
    o vetor interno e deletar os 5 cômodos automaticamente (Composição).*/
    return 0;
}
//g++ main.cpp src/*.cpp -I include -o main ; if ($?) { .\main }