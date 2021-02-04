#include "pragma"
#include "partida.h"
#include <vector>
using namespace std;
class Juego{
private:
    vector<Partida*> partidas;
public:
    Juego(){
        this->partidas = new vector<Partida*>();
    }
    ~Juego(){}

    void addPartida(Partida* p){ this->partidas.push_back(p); }

    vector<Partida*> getPartidas(){ return this->partidas; }
};