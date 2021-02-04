class Elemento{
private:
	int posX;
	int posY;
	int lenX;
	int lenY;
	vector<string> figuraASCII;
public:
	Elemento(int posX, int posY, int lenX, int lenY, vector<string> figuraASCII){
		this->posX = posX;
		this->posY = posY;

		this->lenX = lenX;
		this->lenY = lenY;

		this->figuraASCII = figuraASCII;
	};
	~Elemento();
	
	void setPosX(int posX){ this->posX = posX; }
	void setPosY(int posY){ this->posY = posY; }
	void setLenX(int lenX){ this->lenX = lenX; }
	void setLenY(int lenY){ this->lenY = lenY; }
	void setFiguraASCII(vector<string> figuraASCII){ this->figuraASCII = figuraASCII; }

	int getPosX(){ return this->posX; }
	int getPosY(){ return this->posY; }
	int getLenX(){ return this->lenX; }
	int getLenY(){ return this->lenY; }
	vector<string> getFiguraASCII(){ return this->figuraASCII; }
};