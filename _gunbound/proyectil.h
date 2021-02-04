class Proyectil: public ELemento{
private:
	int velX;
	int velY;
public:
	Proyectil(
		int posX, int posY, int lenX, int lenY, vector<string> figuraASCII, int lenY, int velX, int velY
	): Elemento(
		posX, posY, lenX, lenY, figuraASCII){
		this->velX = velX;
		this->velY = velY;
	};
	~Proyectil();

	void setVelX(int velX){ this->velX = velX; }
	void setVelY(int velY){ this->velY = velY; }

	void getVelX(){ return this->velX; }
	void getVelY(){ return this->velY; }

	void movX(int deltaT){
		int deltaX = this->getVelX()*deltaT;
		this->setPosX(this->getPosX()+deltaX);
	}
	void movY(int deltaT){
		int deltaY = this->getVelY()*deltaT;
		this->setPosY(this->getPosY()+deltaY);
	}
	void movProyectil(int deltaT){
		this->movX(deltaT);
		this->movY(deltaT);
	}
};
