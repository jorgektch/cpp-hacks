#include <string>
#include "partida.h"

using namespace std;

class Juego{
private:
	vector<Partidas*> partidas;
public:
	Partida(){
		this->partidas = vector<Partida*>();
	};
	~Partida();

	//
};