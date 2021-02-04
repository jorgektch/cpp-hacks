#include <iostream>
#include <stdlib.h>
#include <time.h>
#define maxJugadores 4
#define maxCuadrados 79
#define maxCartas 400
using namespace std;

void generarCuadrados(char cuadrados[], int numCuadrados);
void mostrarCuadrados(char cuadrados[], int numCuadrados);
void generarCartas(char cartas[], int numCartas);
void mostrarCartas(char cartas[], int numCartas);
void simularJuego(int posJugadores[], int numJugadores, char cuadrados[], int numCuadrados, char cartas[], int numCartas);

int main(){
    int numJugadores;
    int posJugadores[maxJugadores];
    
    int numCuadrados;
    char cuadrados[maxCuadrados];
    
    int numCartas;
    char cartas[maxCartas];
    
    cout << "Ingresa el numero de jugadores: ";
    cin >> numJugadores;
    cout << "Ingresa el numero de cuadrados en el tablero: ";
    cin >> numCuadrados;
    cout << "Ingresa el numero de cartas en el deck: ";
    cin >> numCartas;

    // Generar Cuadrados
    srand (time(NULL));
    generarCuadrados(cuadrados, numCuadrados);
    mostrarCuadrados(cuadrados, numCuadrados);

    // Generar Cartas
    generarCartas(cartas, numCartas);
    mostrarCartas(cartas, numCartas);

    simularJuego(posJugadores, numJugadores, cuadrados, numCuadrados, cartas, numCartas);

    return 0;
}

void generarCuadrados(char cuadrados[], int numCuadrados){
    /*
    cuadrados[0] = 'R';
    cuadrados[1] = 'Y';
    cuadrados[2] = 'G';
    cuadrados[3] = 'P';
    cuadrados[4] = 'B';
    cuadrados[5] = 'R';
    cuadrados[6] = 'Y';
    cuadrados[7] = 'G';
    cuadrados[8] = 'B';
    cuadrados[9] = 'R';
    cuadrados[10] = 'P';
    cuadrados[11] = 'O';
    cuadrados[12] = 'P';
    */
    for(int i=0; i<numCuadrados; i++){
        cuadrados[i] = (int)(65 + rand() % 26); //65->A,  90->Z
    }
}
void mostrarCuadrados(char cuadrados[], int numCuadrados){
    for(int i=0; i<numCuadrados; i++){
        cout << cuadrados[i];
    }
    cout << endl;
}
void generarCartas(char cartas[], int numCartas){
    /*
    cartas[0] = 'R';
    cartas[1] = 'B';
    cartas[2] = 'G';
    cartas[3] = 'Y';
    cartas[4] = 'P';
    cartas[5] = 'B';
    cartas[6] = 'P';
    cartas[7] = 'R';
    */
    for(int i=0; i<numCartas; i++){
        cartas[i] = (char)(65 + rand() % 26); //65->A,  90->Z
    }
    
}
void mostrarCartas(char cartas[], int numCartas){
    for(int i=0; i<numCartas; i++){
        cout << cartas[i];
    }
    cout << endl;
}
void simularJuego(int posJugadores[], int numJugadores, char cuadrados[], int numCuadrados, char cartas[], int numCartas){
    /* Inicializar posiciones de jugadores */
    for(int i=0; i<numCartas; i++){
        posJugadores[i] = -1;
    }

    bool hayGanador = false;
    int i=0; /* Iterador de cartas */
    while(hayGanador == false && i<numCartas){

        int jugador = i%numJugadores;
        char cartaSacada = cartas[i];
        bool haySiguiente = false;
        int posSiguiente;
        
        cout << "Jugador " << jugador+1;
        cout << " saca " << cartaSacada;

        /* Simulacion de movimiento bajo las reglas del juego */
        for(int j=posJugadores[jugador]+1; j<numCuadrados; j++){
            if(haySiguiente == false && cartaSacada == cuadrados[j]){
                haySiguiente = true;
                posJugadores[jugador] = j;
            }
        }
        if(haySiguiente == false){
            posJugadores[jugador] = numCuadrados-1;
        }
        
        if(posJugadores[jugador]<numCuadrados-1){
            cout << ", se mueve a la posicion " << posJugadores[jugador]+1 << " del cuadrado" << endl;
        }else{
            cout << ", Gano! (no hay " << cartaSacada <<"'s al frente de esta pieza asi que va hasta el ultimo cuadrado)" << endl;
            hayGanador = true;
        }
        /* Aumento de iterador de cartas */
        i++;
    }
    /* Verificacion de existencia de ganador */
    if(hayGanador == false){
        cout << "No hubo ganador en este juego" << endl;
    }
    
}