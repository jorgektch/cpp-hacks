#include <string>
#include "heroe.h"
#include "enemigo.h"
#include "proyectil.h"

using namespace std;

class Partida{
private:
	int codigo;
	int nivel;
	int puntaje;
	Personaje* heroe;
	Personaje* enemigo;
	vector<Proyectil*> proyectiles;
public:
	Partida(int codigo, int nivel, int puntaje, Personaje* heroe, Personaje* enemigo){
		this->codigo = codigo;
		this->nivel = nivel;
		this->puntaje = puntaje;
		this->heroe = heroe;
		this->enemigo = enemigo;
		this->proyectiles = vector<Proyectil*>();
	};
	~Partida();

	//
};