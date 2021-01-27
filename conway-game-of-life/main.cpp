#include<iostream>
#include<stdio.h>
#include<windows.h>
#include<conio.h>

int main(){
	int generacionMax = 90;
	int pausa = 30;
	
	int generacion = 0;
	int numFil = 25;
	int numCol = 56;
	int vecinos;
	
	// Espacio
	int matriz[numFil][numCol];
	for(int i=0; i<numFil; i++){
		for(int j=0; j<numCol; j++){
			matriz[i][j] = 0;
		}
	}
	
	// Elementos
	matriz[1][2] = 1;
	matriz[1][5] = 1;
	matriz[2][6] = 1;
	matriz[3][6] = 1;
	matriz[3][2] = 1;
	matriz[4][3] = 1;
	matriz[4][4] = 1;
	matriz[4][5] = 1;
	matriz[4][6] = 1;
	
	matriz[7][4] = 1;
	matriz[8][2] = 1;
	matriz[8][6] = 1;
	matriz[9][7] = 1;
	matriz[10][2] = 1;
	matriz[10][7] = 1;
	matriz[11][3] = 1;
	matriz[11][4] = 1;
	matriz[11][5] = 1;
	matriz[11][6] = 1;
	matriz[11][7] = 1;
	
	matriz[16][6] = 1;
	matriz[16][7] = 1;
	matriz[17][5] = 1;
	matriz[17][8] = 1;
	matriz[18][4] = 1;
	matriz[18][9] = 1;
	matriz[19][3] = 1;
	matriz[19][10] = 1;
	matriz[20][3] = 1;
	matriz[20][10] = 1;
	matriz[21][4] = 1;
	matriz[21][9] = 1;
	matriz[22][5] = 1;
	matriz[22][8] = 1;
	matriz[23][6] = 1;
	matriz[23][7] = 1;
	
	matriz[17][16] = 1;
	matriz[17][17] = 1;
	matriz[18][16] = 1;
	matriz[18][17] = 1;
	matriz[18][19] = 1;
	matriz[19][20] = 1;
	matriz[20][17] = 1;
	matriz[21][18] = 1;
	matriz[21][20] = 1;
	matriz[21][21] = 1;
	matriz[22][20] = 1;
	matriz[22][21] = 1;
	
	matriz[18][30] = 1;
	matriz[18][31] = 1;
	matriz[19][30] = 1;
	matriz[19][31] = 1;
	matriz[20][28] = 1;
	matriz[20][29] = 1;
	matriz[21][28] = 1;
	matriz[21][29] = 1;
	
	matriz[19][37] = 1;
	matriz[19][38] = 1;
	matriz[20][37] = 1;
	matriz[20][39] = 1;
	matriz[22][39] = 1;
	matriz[22][41] = 1;
	matriz[23][40] = 1;
	matriz[23][41] = 1;
	
	matriz[18][47] = 1;
	matriz[18][48] = 1;
	matriz[19][47] = 1;
	matriz[19][49] = 1;
	matriz[21][49] = 1;
	matriz[21][51] = 1;
	matriz[22][52] = 1;
	matriz[23][51] = 1;
	matriz[23][52] = 1;
	
	// Iteración (Evolucion por generaciones
	do{
		// Limpieza del espacio de trabajo
		system("CLS");
		
		printf("Generacion %d\n", generacion);
		// Pintado de la matriz de elementos
		for(int i=0; i<numFil; i++){
			for(int j=0; j<numCol; j++){
				if(matriz[i][j]==0){
					printf("%c", char(176));
				}else{
					printf("%c", char(219));
				}
			}
			printf("\n");
		}
		
		// Copia de la matriz de elementos
		int matrizCopia[numFil][numCol];
		for(int i=0; i<numFil; i++){
			for(int j=0; j<numCol; j++){
				matrizCopia[i][j] = matriz[i][j];
			}
		}
		
		// Evolucion #1
		for(int i=0; i<numFil; i++){
			for(int j=0; j<numCol; j++){
				vecinos = 0;
				if(0<=i-1 && i-1<numFil && 0<=j && j<numCol)
					vecinos = vecinos+matrizCopia[i-1][j];
				if(0<=i-1 && i-1<numFil && 0<=j+1 && j+1<numCol)
					vecinos = vecinos+matrizCopia[i-1][j+1];
				if(0<=i && i<numFil && 0<=j+1 && j+1<numCol)
					vecinos = vecinos+matrizCopia[i][j+1];
				if(0<=i+1 && i+1<numFil && 0<=j+1 && j+1<numCol)
					vecinos = vecinos+matrizCopia[i+1][j+1];
				if(0<=i+1 && i+1<numFil && 0<=j && j<numCol)
					vecinos = vecinos+matrizCopia[i+1][j];
				if(0<=i+1 && i+1<numFil && 0<=j-1 && j-1<numCol)
					vecinos = vecinos+matrizCopia[i+1][j-1];
				if(0<=i && i<numFil && 0<=j-1 && j-1<numCol)
					vecinos = vecinos+matrizCopia[i][j-1];
				if(0<=i-1 && i-1<numFil && 0<=j-1 && j-1<numCol)
					vecinos = vecinos+matrizCopia[i-1][j-1];
				
				if(matrizCopia[i][j]==0 && vecinos==3)
					matriz[i][j]=1;
				if(matrizCopia[i][j]==1 && (vecinos<2 || 3<vecinos))
					matriz[i][j]=0;
			}
		}
		
		generacion = generacion+1;
		Sleep(pausa);
		
	}while(generacion<=generacionMax);
}
