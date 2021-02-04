#include <iostream>
#include <malloc.h>
#include <string.h>
#define ALFABETO_CONT 26
using namespace std;

typedef struct Nodo {
	char *palabra;
	struct Nodo *ptrSiguiente;	
}Palabra;

typedef struct ListaPalabras{
	int size;
	Palabra *ptrInicio;
}Lista;

void mostrarMenu();
void inicializarLista(Lista *ptrLista);
void AgregarAlFinal(Lista *ptrLista);
void Jugar(Lista *ptrLista,char *palabraBuscada);
void LiberaMemoria(Lista *ptrLista);
int caracteresComunes(char *s1, char *s2);

int main(){
    Lista *ptrLista;
	char *palabraBuscada;
	int fin=0, opcion, nuevaEdad;
	/*Vamos a crear (darle memoria) la estructura que va a manejar la lista de Palabras*/
	ptrLista = (ListaPalabras *)malloc(sizeof(ListaPalabras));
	inicializarLista(ptrLista);

    while (1){
        system("CLS");
		mostrarMenu();
		cin >> opcion;
		switch (opcion){
			case 1: {
                system("CLS");
				AgregarAlFinal(ptrLista);
                system("PAUSE");
				break;
			}
			case 2:{
                system("CLS");
				cout << "Palabra: ";
				palabraBuscada = (char *)malloc(sizeof(char)*20);
				cin >> palabraBuscada;
				Jugar(ptrLista,palabraBuscada);
				free(palabraBuscada); /*Hay que liberar la memoria de este puntero, porque ya no lo necesito*/
                system("PAUSE");
				break;
			}
			case 3: {
				LiberaMemoria(ptrLista);
				fin = 1;
                cout << "Gracias por jugar" << endl;
				break;
			}
		}
		if (fin==1){
			/*Terminamos la ejecución del programa*/
			break;
		}	
	}

    return 0;
}


void mostrarMenu(){
    cout << "Bienvenidos al juego de cifras y letras" << endl;
    cout << "1.- Agregar palabras al final al diccionario." << endl;
    cout << "2.- Jugar"<< endl;
    cout << "3.- Salir"<< endl;
    cout << "Ingrese su opcion: ";
}

void inicializarLista(Lista *ptrLista){
	//(*ptrLista).size = 0;
	ptrLista->size = 0;
	ptrLista->ptrInicio = NULL;
}

void AgregarAlFinal(Lista *ptrLista){
    
    Palabra *ptrNodo;
    ptrNodo = NULL;
    ptrNodo = (Palabra *)malloc(sizeof(Palabra));
    ptrNodo->palabra = (char *)malloc(sizeof(char)*9);
    cout << "Ingresa la palabra: ";
	cin >> ptrNodo->palabra;
    ptrNodo->ptrSiguiente = NULL;
    
    Palabra *ptrRecorrido;
	ptrRecorrido = ptrLista->ptrInicio;
    bool seEncontro = false;
    for (int i=0; i<ptrLista->size; i++){
		if (strcmp(ptrRecorrido->palabra,ptrNodo->palabra)==0){
            seEncontro = true;
		}
		ptrRecorrido = ptrRecorrido->ptrSiguiente; /*Con esta instruccion estamos pasando a la siguiente Palabra*/
	}
    if(seEncontro == false){
	    /*Voy a agregar la Palabra que acabo de crear y colocar datos*/
        if (ptrLista->size==0){
            ptrLista->ptrInicio = ptrNodo;
            ptrLista->size++;
        }
        else {
            Palabra *ptrRecorrido = ptrLista->ptrInicio;
            for (int i=0; i<(ptrLista->size - 1); i++){
                ptrRecorrido = ptrRecorrido->ptrSiguiente;
            }
            ptrRecorrido->ptrSiguiente = ptrNodo;
            ptrLista->size++;
        }
        cout << "Palabra agregada" << endl;
    }else{
        cout << "La palabra ya se encuentra en el diccionario" << endl;
    }

        
}

void Jugar(Lista *ptrLista,char *palabraBuscada){
	Palabra *ptrRecorrido;
	ptrRecorrido = ptrLista->ptrInicio;

    char *palabraEncontrada = (char *)malloc(sizeof(char)*9);
    bool seEncontro = false;
    int comunesMax = -1;
	for (int i=0; i<ptrLista->size; i++){
        
		if (caracteresComunes(ptrRecorrido->palabra,palabraBuscada)>comunesMax){
            comunesMax = caracteresComunes(ptrRecorrido->palabra,palabraBuscada);
            palabraEncontrada = ptrRecorrido->palabra;
            seEncontro = true;
		}
		ptrRecorrido = ptrRecorrido->ptrSiguiente; /*Con esta instruccion estamos pasando a la siguiente Palabra*/
	}
    if(seEncontro == true){
	    cout << "Palabra encontrada: " << palabraEncontrada << endl;
    }else{
        cout << "No se encontro la palabra" << endl;
    }
}

void LiberaMemoria(Lista *ptrLista){
	Palabra *ptrRecorrido;
	ptrRecorrido = ptrLista->ptrInicio;
	for (int i=0; i<ptrLista->size; i++){
		free(ptrRecorrido->palabra);
		Palabra *ptrAux;
		ptrAux = ptrRecorrido->ptrSiguiente;
		free(ptrRecorrido);
		ptrRecorrido = ptrAux;
	}
	free(ptrLista);
}

int caracteresComunes(char *s1, char *s2){
    int c_count = 0, i; 
    int arr1[ALFABETO_CONT] = {0}, arr2[ALFABETO_CONT] = {0};

    while (*s1)
        arr1[*s1++ -'a'] += 1;
    while (*s2)
        arr2[*s2++ -'a'] += 1;       

    for(i=0; i<ALFABETO_CONT; i++) {
        if(arr1[i] == arr2[i]) c_count += arr1[i];
        else if(arr1[i]>arr2[i] && arr2[i] != 0) c_count += arr2[i];
        else if(arr2[i]>arr1[i] && arr1[i] != 0) c_count += arr1[i];
    }

    return c_count;
}