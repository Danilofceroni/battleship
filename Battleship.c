#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void barcoscom(char barco, int tamano, int ctd, char map[10][10]){
	int ctdships = 0;
	srand(time(NULL));
	while (ctd > ctdships){
		int VorH = rand()%2;
		if (VorH == 0){
			int x = rand()%10;
			int y = rand()%10;
			if (y + tamano <= 10){
				int verify = 1;
				for (int i = y; i < y + tamano; i++){
					if (map[x][i] != '-'){
						verify = 0;
					}
				}
				if (verify == 1){
					for (int i = y; i < y + tamano; i++){
						map[x][i] = barco;
					}
					ctdships++;
				}
			}
		}else{
			int x = rand()%10;
			int y = rand()%10;
			if (x + tamano <= 10){
				int verify = 1;
				for (int i = x; i < x + tamano; i++){
					if (map[i][y] != '-'){
						verify = 0;
					}
				}
				if (verify == 1){
					for (int i = x; i < x + tamano; i++){
						map[i][y] = barco;
					}
					ctdships++;
				}
			}
		}
	}
}
void llenadobarcos(char barco, int tamano, int ctd, char map[10][10]){
	int ctdships = 0;
	srand(time(NULL));
	while (ctd > ctdships){
		int VorH = rand()%2;
		if (VorH == 1){
			int x = rand()%10;
			int y = rand()%10;
			if (y + tamano <= 10){
				int verify = 1;
				for (int i = y; i < y + tamano; i++){
					if (map[x][i] != '-'){
						verify = 0;
					}
				}
				if (verify == 1){
					for (int i = y; i < y + tamano; i++){
						map[x][i] = barco;
					}
					ctdships++;
				}
			}
		}else{
			int x = rand()%10;
			int y = rand()%10;
			if (x + tamano <= 10){
				int verify = 1;
				for (int i = x; i < x + tamano; i++){
					if (map[i][y] != '-'){
						verify = 0;
					}
				}
				if (verify == 1){
					for (int i = x; i < x + tamano; i++){
						map[i][y] = barco;
					}
					ctdships++;
				}
			}
		}
	}
}
void llenadomira(char mira[10][10]){
	for (int i = 0; i < 10; i++){
		for (int j = 0; j < 10; j++){
			mira[i][j] = '-';
		}
	}
}
void mira(char mira[10][10]){
	printf("  ");
	for (int t = 0; t < 10; t++)
		printf("%d ", t);
	printf("\n");
	for (int i = 0; i < 10; i++){
		printf("%d ", i);
		for (int j = 0; j < 10; j++){
			printf("%c ", mira[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
int game(char player[10][10], char playerscope[10][10], char com[10][10], char comscope[10][10]){
	int i, j, tirosacertados = 0, tirosfallados = 0, comlife=0, plslife=0, win=0;
	srand(time(NULL));
	while (plslife < 33 || comlife < 33){
		system("cls");
		mira(playerscope);		printf("Tiros acertados: %d\n", tirosacertados);
		mira(player);			printf("Tiros fallados: %d\n", tirosfallados);
		do{
			do{
				printf("\n Ingrese la coordenada de la fila(horizontal): ");
				scanf("%d", &i);
			} while (i < 0 || i > 9);
			do{
				printf("\n Ingrese la coordenada de la columna(vertical): ");
				scanf("%d", &j);
			} while (j < 0 || j > 9);
		}while(playerscope[i][j] == 'A' || playerscope[i][j] == 'F');	
		if (com[i][j] == '-'){
			playerscope[i][j] = 'F';
			tirosfallados++;
		}else{
			playerscope[i][j] = 'A';
			tirosacertados++;
			comlife++;
			
		}
		do{
			i = rand()%10;
			j = rand()%10;
		}while(comscope[i][j] == 'A' || comscope[i][j] == 'F');	
		if (player[i][j] != '-'){
			comscope[i][j] = 'A';
			player[i][j] = 'A';
			plslife++;
			
		}else{
			comscope[i][j] = 'F';
			player[i][j] = 'F';
		}
		printf("\nLa maquina esta haciendo su movimiento...\n");
		system("pause");
	}
	if (comlife==33){
		win=1;
		return win;
	}if (plslife==33){
		return win;
	}
}
int main(){
	int iniciodejuego;
	char mirapla[10][10], miracom[10][10], tablapl[10][10], tablacom[10][10];
	do{
		printf("Bienvenido a Batalla Naval.\n");
		printf("Presione 1 para Jugar.\n");
		printf("Presione 2 para salir.\n");
		printf("Ingrese su opcion: ");
		scanf("%d", &iniciodejuego);
		if (iniciodejuego == 2){
			break;
		}
		while (iniciodejuego == 1){
			system("cls");
			llenadomira(tablapl);
			llenadomira(tablacom);
			llenadomira(mirapla);
			llenadomira(miracom);
			barcoscom('a', 2, 3, tablacom);
			llenadobarcos('a', 2, 3, tablapl);
			barcoscom('b', 3, 3, tablacom);
			llenadobarcos('b', 3, 3, tablapl);
			barcoscom('c', 4, 2, tablacom);
			llenadobarcos('c', 4, 2, tablapl);
			barcoscom('d', 5, 2, tablacom);
			llenadobarcos('d', 5, 2, tablapl);
			game(tablapl, mirapla, tablacom, miracom);
			if (game(tablapl, mirapla, tablacom, miracom) == 1){
				printf("La flota enemiga ha sido destruida!\n");
				printf("Felicidades Ganaste! Bien hecho!\n");
				system("pause");
				iniciodejuego=0;
				system("cls");
			}else{
				printf("La flota aliada ha sido destruida!\n");
				printf("Gano la computadora! Suerte para la proxima.\n");
				system("pause");
				iniciodejuego=0;
				system("cls");
			}
		}
	} while (iniciodejuego != 2 && iniciodejuego != 1);
	printf("Gracias por jugar.\n");
	printf("Creado por Reynaldo Rivas & Martin Quinones.\n");
	system("pause");
	system ("cls");
	return 0;
}