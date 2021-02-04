#include "pragma"
#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Elemento{
private:
    int posX;
    int posY;
    int velocX;
    int velocY;
    int acelerX;
    int acelerY;
    vector<string> asciiArt;
public:
    Elemento(int posX, int posY, int velocX, int velocY, int acelerX, int acelerY){
        this->posX = posX;
        this->posY = posY;
        this->velocX = velocX;
        this->velocY = velocY;
        this->acelerX = acelerX;
        this->acelerY = acelerY;
    }
    ~Elemento(){}

    void setPosX(int posX){ this->posX = posX; }
    void setPosY(int posY){ this->posY = posY; }
    void setVelocX(int velocX){ this->velocX = velocX; }
    void setVelocY(int velocY){ this->velocY = velocY; }
    void setAcelerX(int acelerX){ this->acelerX = acelerX; }
    void setAcelerY(int acelerY){ this->acelerY = acelerY; }
    void setAsciiArt(vector<string> asciiArt){ this->asciiArt = asciiArt; }

    int getPosX(){ return this->posX; }
    int getPosY(){ return this->posY; }
    int getVelocX(){ return this->velocX; }
    int getVelocY(){ return this->velocY; }
    int getAcelerX(){ return this->acelerX; }
    int getAcelerY(){ return this->acelerY; }
    vector<string> getAsciiArt(){ return this->asciiArt; }

    void mover(int deltaTiempo){
        this->moverX(deltaTiempo);
        this->moverY(deltaTiempo);
    }
    void moverX(int deltaTiempo){ this->setPosX(this->getPosX()+this->getVelocX()*deltaTiempo); }
    void moverY(int deltaTiempo){ this->setPosY(this->getPosY()+this->getVelocY()*deltaTiempo); }

    void acelerar(int deltaTiempo){
        this->acelerarX(deltaTiempo);
        this->acelerarY(deltaTiempo);
    }
    void acelerarX(int deltaTiempo){ this->setVelocX(this->getVelocX()+this->getAcelerX()*deltaTiempo); }
    void acelerarY(int deltaTiempo){ this->setVelocY(this->getVelocY()+this->getAcelerY()*deltaTiempo); }

    void detectarColision(Elemento* e){
        /* Pendiente */
    }
};