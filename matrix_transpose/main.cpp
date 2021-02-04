#include <iostream>
#define maxFilas 100
#define maxColumnas 100
using namespace std;

void leerMatriz(int matriz[][maxColumnas], int ordenMatriz);
void transponerMatriz(int matriz[][maxColumnas], int ordenMatriz);
void imprimirMatriz(int matriz[][maxColumnas], int ordenMatriz);

int main(){
    int matriz[maxFilas][maxColumnas];
    int ordenMatriz;

    cout << "Ingresa el orden la matriz: ";
    cin >> ordenMatriz;
    
    /* Validacion del orden de la matriz */
    if(ordenMatriz<=100){
        leerMatriz(matriz, ordenMatriz);
        imprimirMatriz(matriz, ordenMatriz);
        transponerMatriz(matriz, ordenMatriz);
        imprimirMatriz(matriz, ordenMatriz);
    }else{
        cout << "El tamanho maximo de la matriz es de 100x100" << endl;
    }

    return 0;
}

void leerMatriz(int matriz[][maxColumnas], int ordenMatriz){
    int numero;
    cout << "Registro de elementos de la matriz de " << ordenMatriz << "x" << ordenMatriz << endl;
    for (int i=0; i<ordenMatriz; i++){
		for (int j=0; j<ordenMatriz; j++){
			cout << "A[" << i+1 << "][" << j+1 << "] = ";
            cin >> numero;
            matriz[i][j] = numero;
		}		
	}
}
void transponerMatriz(int matriz[][maxColumnas], int ordenMatriz){
    /* Copia de la matriz original */
    int matrizCopia[maxFilas][maxColumnas];
    for(int i=0; i<ordenMatriz; i++){
        for(int j=0; j<ordenMatriz; j++){
            matrizCopia[i][j] = matriz[i][j];
        }
    }
    /* Transposicion utilizando la matriz copia */
	for (int i=0; i<ordenMatriz; i++){
		for (int j=0; j<ordenMatriz; j++){
			matriz[i][j] = matrizCopia[j][i];
		}
	}
    cout << "Se transpuso la matriz exitosamente" << endl;
}
void imprimirMatriz(int matriz[][maxColumnas], int ordenMatriz){
    cout << "Elementos de la matriz de " << ordenMatriz << "x" << ordenMatriz << endl;
	for (int i=0; i<ordenMatriz; i++){
		for (int j=0; j<ordenMatriz; j++){
			cout << matriz[i][j] << " ";
		}
		cout << endl;
	}
}
