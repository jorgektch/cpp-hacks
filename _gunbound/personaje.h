class Personaje: public ELemento{
private:
	string nombre;
public:
	Personaje(string nombre){
		this->nombre = nombre;
	};
	~Personaje();
	
	void setNombre(string nombre){ this->nombre = nombre; }

	string getNombre(){ this->nombre = nombre; }
};