#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define MAX 9

/*Prototipos de funciones*/
void MPresentacion(); /*HECHO*/
void MSeleccion(); /*HECHO*/
void FEstablecerMatrices(); 
	int FDificultad(); /*HECHO*/
	void FCopiarSudoku(int plantilla[][MAX], int sudoku[][MAX]); /*HECHO*/
void MJuego(); /*HECHO*/
	int FPedirPosicion(char posicion[10], int a); /*HECHO*/
	void FImprimirSudoku(int sudoku[][MAX]); /*HECHO*/
	int FVerificarCoordenadas(); /*HECHO*/
	int FPedirNuevoNumero(); /*HECHO*/
	void FColocarNumero(int nuevoNumero); /*HECHO*/
	void FVerificarTablero(int matrz[MAX][MAX]); /*HECHO*/
	int FVerificarVictoria(int matriz[MAX][MAX]); /*HECHO*/
		int FVerificarArea(int fila, int columna);/*HECHO*/
	void FPantallaTriunfo(); /*HECHO*/

	void FPantallaFinal(); /*HECHO*/
/*Matrices*/
int sudoku[MAX][MAX];
int sudokuBase[MAX][MAX];


/*Variables*/
int posX, posY, nuevoJuego, tableroCorrecto, xError, yError;

int main(){
	MPresentacion();
	do{
		MSeleccion();
		MJuego();
	} while(nuevoJuego == 0);
	
	FPantallaFinal();
	return 0;
	
}
void MPresentacion() {
	
	int c, h, c2, count = 4000000;
	for(c = 15;c>0;c--){
		for(c2 = 0; c2<c;c2++) printf("\n");
		puts("                   °°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°     ");
		puts("                   °                                    °     ");
		puts("                   °  °°°° °  ° °°°°  °°°°° °  ° °   °  °     ");
		puts("                   °  °    °  ° °  °° °   ° °  ° °   °  °     ");
		puts("                   °  °°°° °  ° °   ° °   ° °°°  °   °  °     ");
		puts("                   °     ° °  ° °  °° °   ° °  ° °   °  °     ");
		puts("                   °  °°°° °°°° °°°°  °°°°° °  ° °°°°°  °     ");
		puts("                   °                                    °     ");
		puts("                   °°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°     ");
		
		system("cls");
		if(c%2==0) system("COLOR 70"); else system("COLOR 07");
		for(h=0; h<count;h++);
	}
	
	puts("                   °°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°     ");
	puts("                   °                                     °     ");
	puts("                   °  °°°° °  ° °°°°  °°°°° °  ° °   °   °     ");
	puts("                   °  °    °  ° °  °° °   ° °  ° °   °   °     ");
	puts("                   °  °°°° °  ° °   ° °   ° °°°  °   °   °     ");
	puts("                   °     ° °  ° °  °° °   ° °  ° °   °   °     ");
	puts("                   °  °°°° °°°° °°°°  °°°°° °  ° °°°°°   °     ");
	puts("                   °                                     °     ");
	puts("                   °°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°     ");
	puts("                   °°                                   °°     ");
	puts("                   °°  PULSE ENTER PARA EMPEZAR JUEGO   °°     ");
	puts("                   °°                                   °°     ");
	puts("                   °°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°     ");
	puts("                                      °° Se recomienda  °°     ");
	puts("                                      °° poner pantalla °°     ");
	puts("                                      °° completa       °°     ");
	puts("                                      °°°°°°°°°°°°°°°°°°°°     ");
	
	do{
		
	}while(getch() != 13);
	
	
}



void MSeleccion(){
	int sudokuPrincipiante1[MAX][MAX] =
			{{0,7,4,6,0,9,0,8,2},
			{0,6,1,2,0,0,0,0,0},
			{0,0,0,0,5,8,0,0,0},
			{0,8,5,0,0,6,0,3,0},
			{6,0,9,0,4,7,0,5,8},
			{0,3,0,5,8,0,0,0,4},
			{7,5,0,4,0,3,6,0,0},
			{0,4,3,0,6,2,0,0,0},
			{0,2,0,8,0,0,3,4,0}};
	
	int sudokuPrincipiante2[MAX][MAX] = {
			{0,8,0,0,7,2,0,0,0},
			{4,7,3,0,0,0,0,5,9},
			{6,0,2,0,0,5,0,0,0},
			{0,4,0,8,3,0,6,0,5},
			{5,3,0,6,2,7,0,4,0},
			{0,0,8,0,5,0,3,0,0},
			{0,0,0,0,0,8,0,0,6},
			{0,0,4,0,0,3,0,0,2},
			{0,2,6,5,0,4,7,3,0}
	};
	
	int sudokuIntermedio1[MAX][MAX] = {
			{0,5,0,0,0,3,9,2,7},
			{0,0,4,0,7,0,3,0,0},
			{0,3,0,0,0,2,5,0,0},
			{0,0,0,2,0,0,0,0,5},
			{7,0,6,0,0,0,0,0,2},
			{5,2,3,7,0,0,0,0,0},
			{8,0,0,0,3,0,0,0,0},
			{6,0,0,0,0,0,0,5,0},
			{3,7,2,0,4,5,0,8,6}
	};
	
	int sudokuIntermedio2[MAX][MAX]= {
			{0,2,0,0,7,0,0,8,5},
			{0,0,7,0,5,0,0,0,0},
			{0,8,5,0,0,4,0,0,0},
			{0,6,3,5,8,7,0,0,4},
			{0,5,0,0,0,0,0,3,0},
			{8,0,0,0,6,2,0,0,0},
			{0,0,6,4,0,3,0,0,2},
			{0,4,0,8,9,0,3,5,0},
			{0,0,0,7,0,0,0,0,6}
	};
	
	int sudokuAvanzado1[MAX][MAX] = {{0,2,8,0,5,0,3,0,0},
		{0,0,0,0,0,0,5,2,4},
		{0,0,0,0,0,6,0,0,7},
		{0,0,0,5,4,0,0,0,0},
		{6,0,2,0,0,8,0,5,3},
		{0,0,0,0,0,0,0,9,0},
		{0,0,3,0,0,0,6,0,5},
		{0,0,0,7,0,0,0,8,0},
		{0,4,0,0,2,0,0,0,0}};
	
	int sudokuAvanzado2[MAX][MAX] ={
		{0,0,4,8,0,7,0,0,0},
			{0,0,0,0,6,0,4,8,3},
			{0,5,0,0,0,0,0,0,0},
			{0,0,0,2,0,0,0,4,0},
			{0,0,0,0,8,0,5,6,0},
			{0,0,0,0,0,0,9,0,7},
			{0,0,8,3,7,0,6,2,0},
			{0,3,5,0,0,0,0,0,0},
			{0,0,2,0,0,5,0,0,9}
	};
	
	switch(FDificultad()){ /*Segun la dificultad que devuelva la funcion se estable la matriz en juego*/
	case 1: /*Sencillo Juego 1*/
		FCopiarSudoku(sudokuPrincipiante1, sudoku);
		FCopiarSudoku(sudokuPrincipiante1, sudokuBase);
		break;
	case 2: /* Sencillo Juego 2*/
		FCopiarSudoku(sudokuPrincipiante2, sudoku);
		FCopiarSudoku(sudokuPrincipiante2, sudokuBase);
		break;
	case 3: /*Intemedio Juego 1*/
		FCopiarSudoku(sudokuIntermedio1, sudoku);
		FCopiarSudoku(sudokuIntermedio1, sudokuBase);
		break;
	case 4: /*Intermedio Juego 2*/
		FCopiarSudoku(sudokuIntermedio2, sudoku);
		FCopiarSudoku(sudokuIntermedio2, sudokuBase);
		break;
	case 5: /* Avanzado Juego 1*/
		FCopiarSudoku(sudokuAvanzado1, sudoku);
		FCopiarSudoku(sudokuAvanzado1, sudokuBase);
		break;
	case 6: /*Avanzado Juego 2*/
		FCopiarSudoku(sudokuAvanzado2, sudoku);
		FCopiarSudoku(sudokuAvanzado2, sudokuBase);
		break;
	}
}
void MJuego(){
	int numero, verificarCoordenadas, victoria;
	do{ /*Iteraciones que se hacen hasta que se gane el juego*/
		do{ /*Este do es para la verificacion de que no se sobreponga un dato*/
			posX = FPedirPosicion("FILA", 0); /*Se introduce la posicion x del nuevo número, el otro parametro es para saber si es fila o columna*/
			posY = FPedirPosicion("COLUMNA", 1); /*Se introduce la posicion y del nuevo número, el otro parametro es para saber si es fila o columna*/
			verificarCoordenadas = FVerificarCoordenadas();
		}while(verificarCoordenadas == 1); /*La funcion verifica si las coordenadas estan vacias para poner el nuevo numero*/
		numero = FPedirNuevoNumero();
		FColocarNumero(numero); /*Pone el numero en la matriz en juego, el nuevo numero se obtiene de la funcion FPedirNuevoNumero*/
		system("cls");
		victoria = FVerificarVictoria(sudoku);
		FVerificarTablero(sudoku);
	}while(victoria == 1);
	FPantallaTriunfo();
}
int FPedirPosicion(char posicion[10], int fila){
	int correcto, numeroValido, copia;
	float pos;
	do{
		
		
		correcto =0;
		system("cls");
		FImprimirSudoku(sudoku);
		if(fila==1){ /*Verificacion que se hace para saber si ya se introdujo la fila*/
			printf("\n\nSelecciono su linea = %d\n", posX);
		}
		printf("\n\nIntroduzca el valor de la %s donde pondra el numero\nDebe ser mayor o igual a 0 y menor que 9: ", posicion);
		numeroValido = scanf("%f", &pos);
		if(numeroValido ==0){ /*detecta si no se introdujo un entero*/
			fflush(stdin);
			correcto = 1;
			system("color 47");
			printf("\n\n\aTipo de dato no valido. ENTER para continuar");
			do{
				fflush(stdin);
			}while(getch() != 13);
		}else{
			copia = pos;
			if((pos<0 || pos>8) || copia-pos != 0){ /*Verifica que el numero este en el rango y que no sea decimal*/
				system("color 47");
				printf("\n\n\t\t\aEl valor que introdujo no es valido\n\n Pulse ENTER para continuar");
				correcto = 1;
				do{
					fflush(stdin);
				}while(getch() != 13);
			}
		}
	}while(correcto == 1); 
	return pos;
}
int FPedirNuevoNumero(){
	int correcto=0, copia;
	float nuevo;
	do{
		correcto = 0;
		system("cls");
		FImprimirSudoku(sudoku);
		printf("\n\nSelecciono su linea = %d\nSelecciono su columna = %d", posX, posY);
		printf("\n\nIntroduzca el numero a colocar del 1 al 9, cero borra el valor actual: ");
		if(scanf("%f", &nuevo) ==0){ /*detecta si no se introdujo un entero*/
			fflush(stdin);
			correcto = 1;
			system("color 47");
			printf("\n\n\aTipo de dato no valido. ENTER para continuar");
			do{
				fflush(stdin);
			}while(getch() != 13);
		}else{
			copia = nuevo;
			if((nuevo<0 || nuevo>9) || copia-nuevo != 0){ /*Verifica que el numero este en el rango y que no sea decimal*/
				system("color 47");
				printf("\n\n\t\t\aEl valor que introdujo no es valido\n\n Pulse ENTER para continuar");
				correcto = 1;
				do{
					fflush(stdin);
				}while(getch() != 13);
			}
		}
	}while(correcto == 1); 
	return nuevo;
}

void FCopiarSudoku(int plantilla[][MAX], int sudoku[][MAX]){
	int fila;
	int columna;
	for(fila=0; fila<MAX; fila++){
		for(columna=0; columna<MAX; columna++){
			sudoku[fila][columna] = plantilla[fila][columna];
		}
	}	
}

int FVerificarCoordenadas(){
	int verificacion;
	if(sudokuBase[posX][posY]!=0){
		
		system("color 47");
		printf("\n\n\aLa posicion [%d, %d] no puede ser modificada. Pulse ENTER para continuar.", posX, posY);
		do{
			fflush(stdin);
		}while(getch() != 13);
	
		verificacion = 1;
	}
	else{
		verificacion = 0;
	}
	return verificacion;
}
void FImprimirSudoku(int sudoku[][MAX]){
	int i, j;
	if(tableroCorrecto == 1) system("color 47");
	if(tableroCorrecto == 0) system("color 07");
	
	printf("\n");
	printf("\t\t             °°°°°°°°°°°°°°°°°°°°°\n");
	printf("\t\t             °°°°°° SUDOKU °°°°°°°\n");
	printf("\t\t             °°°°°°°°°°°°°°°°°°°°°\n");
	printf("\n\n");
	printf("\t\t       0   1   2   3   4   5   6   7   8\n");
	for(i =0; i<MAX; i++){
		if(i == 0 || i == 3 || i==6){
			printf("\t\t     °°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°\n");
			printf("\t\t     °           °           °           °\n");
		}
		printf("\t\t    %d", i); /*Aqui se imprime el número de columna*/
		for(j = 0; j<MAX; j++){
			if(j == 0 || j == 3 || j==6)
				printf("°");
			else printf(" ");
			
			
			if(sudokuBase[i][j]!=0){ /*Verifica si hay algo en los valores estaticos para ponerlos especiales*/
				printf("|%d|", sudoku[i][j]);
			}
			else if(sudoku[i][j] == 0){  /* Hace que no se impriman los ceros*/
				printf("   ");
			}
			else{
				printf(" %d ", sudoku[i][j]);
			}
			
			
		}
		printf("°");
		printf("\n");
		printf("\t\t     °           °           °           °");
		printf("\n");
		
	}
	printf("\t\t     °°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°\n");
	if(tableroCorrecto == 1) printf("\t\t     HAY UN NUMERO REPETIDO EN [%d][%d]", xError, yError);
}
int FVerificarVictoria(int matriz[][MAX]){
	int c, c2, c3, repeticionesFila, repeticionesColumna;
	
	
	for(c=0;c<MAX;c++){ 
		for(c2=0;c2<MAX;c2++){
			repeticionesFila = 0;
			repeticionesColumna = 0;
			if(matriz[c][c2] == 0) return 1; /*Si encuentra un cero, devuelve que no esta resuelto*/
			for(c3=0;c3<MAX;c3++){ /*Verifica que cada valor sea único en su fila y en su columna*/
				
				if(matriz[c][c2] == matriz[c][c3]) repeticionesFila++;
				if(repeticionesFila>=2) return 1;
				if(matriz[c][c2] == matriz[c3][c2]) repeticionesColumna++;
				if(repeticionesColumna>=2) return 1;
			}
			/* lo siguiente verifica que el numero sea unico en su area
			solo entra a verificar area cuando detecta que esta en la esquina de una*/
			
			if((c==0 || c==3 || c==6) && (c2==0 || c2==3 || c2==6 ))
			if(FVerificarArea(c, c2) == 1) return 1;
				
			}
			
		}
		
	return 0;
	}

	
	


void FColocarNumero(int numero){
	sudoku[posX][posY] = numero;
}
int FDificultad(){
	
	char tecla, tecla2;
	int dificultad, juego;
	
	do{
		fflush(stdin);
		system("cls");
		puts("\t\t°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°");
		puts("\t\t°°°°°°°°°°° SELECCION DE DIFICULTAD °°°°°°°°°°°°");
		puts("\t\t°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°\n");
		printf("\t\tOprima la tecla 1 para nivel PRINCIPIANTE\n");
		printf("\t\tOprima la tecla 2 para nivel INTERMEDIO\n");
		printf("\t\tOprima la tecla 3 para nivel AVANZADO");
		
		tecla = getch();
		
	}while(tecla != '1' && tecla != '2' && tecla != '3');
	dificultad = (int)(tecla-48);
	
	do{
		fflush(stdin);
		system("cls");
		puts("\t\t°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°");
		puts("\t\t°°°°°°°°°°° SELECCION DE JUEGO °°°°°°°°°°°");
		puts("\t\t°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°\n");
		printf("\t\tOprima la tecla 1 para JUEGO 1\n");
		printf("\t\tOprima la tecla 2 para JUEGO 2");
		
		tecla2 = getch();
		
	}while(tecla2 != '1' && tecla2 != '2');
	juego = (int)(tecla2-48);
	
	switch(dificultad){
	case 1:
		if(juego == 1) return 1;
		else return 2;
		break;
	case 2:
		if(juego == 1) return 3;
		else return 4;
		break;
	case 3:
		if(juego == 1) return 5;
		else return 6;
		break;
		
	}
	return 0;
}
void FPantallaTriunfo() {
	int tecla;
	
	int j, x, y;
	for(x = 15;x>0;x--){
		for(y = 0; y<x;y++) printf("\n");
		puts("    °°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°");
		puts("    °                                                                     °");
		puts("    ° °°°° °°°° °    °°°°°    °°°° °°°°°°° °°°°°    °°°  °°°°   °°°° °°°° °");
		puts("    ° °    °    °      °     °°       °    °   °°  °   ° °  °°  °    °    °");
		puts("    ° °°°  °°°  °      °    °°        °    °    °° °°°°° °   °° °°°  °°°° °");
		puts("    ° °    °    °      °    °°        °    °    °° °   ° °   °° °       ° °");
		puts("    ° °    °    °      °     °°       °    °   °°  °   ° °  °°  °       ° °");
		puts("    ° °    °°°° °°°° °°°°°    °°°° °°°°°°° °°°°°   °   ° °°°°   °°°° °°°° °");
		puts("    °                                                                     °");
		puts("    °°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°");
		
		system("COLOR 01");
		system("COLOR 02");
		system("COLOR 06");
		system("COLOR 07");
		system("COLOR 05");
		system("COLOR 0F");
		system("COLOR 0B");
		system("COLOR 0C");system("cls");
	}
	for(j=0;j<5;j++){
		
		puts("     °°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°");
		puts("     °                                                                   °");
		puts("     ° °°°°°       °°   °       °°°°°       °°°°    °°°°          °      °");
		puts("     ° °           ° °  °       °           °      °    °          °     °");
		puts("     ° ° °°°  °°°  °  ° °  °°°  °°°°° °°°°° °°°    °    °           °    °");
		puts("     ° °   ° °   ° °   °° °   °     °   °   °       °°°°             °   °");
		puts("     ° °°°°° °°°°° °    ° °°°°° °°°°°   °   °°°°           °°°°°°     °  °");
		puts("     °       °   °        °   °         °           °°°°             °   °");
		puts("     °       °   °        °   °         °          °    °           °    °");
		puts("     °                                             °    °          °     °");
		puts("     °                                              °°°°          °      °");
		puts("     °                                                                   °");
		puts("     °°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°");
		puts("     °                                                                   °");
		puts("     °                     GRACIAS POR JUGAR :)                          °");
		puts("     °              TE ESPERAMOS EN UNA NUEVA PARTIDA                    °");
		puts("     °                                                                   °");
		puts("     °°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°");
		system("COLOR 01");
		system("COLOR 02");
		system("COLOR 06");
		system("COLOR 07");
		system("COLOR 05");
		system("COLOR 0F");
		system("COLOR 0B");
		system("COLOR 0C");
		system("COLOR 06");
		system("cls");
		
	}
	
	puts("\t°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°");
	puts("\t°                                                                   °");
	puts("\t° °°°°°       °°   °       °°°°°       °°°°    °°°°          °      °");
	puts("\t° °           ° °  °       °           °      °    °          °     °");
	puts("\t° ° °°°  °°°  °  ° °  °°°  °°°°° °°°°° °°°    °    °           °    °");
	puts("\t° °   ° °   ° °   °° °   °     °   °   °       °°°°             °   °");
	puts("\t° °°°°° °°°°° °    ° °°°°° °°°°°   °   °°°°           °°°°°°     °  °");
	puts("\t°       °   °        °   °         °           °°°°             °   °");
	puts("\t°       °   °        °   °         °          °    °           °    °");
	puts("\t°                                             °    °          °     °");
	puts("\t°                                              °°°°          °      °");
	puts("\t°                                                                   °");
	puts("\t°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°");
	puts("\t°                                                                   °");
	puts("\t°                     GRACIAS POR JUGAR :)                          °");
	puts("\t°              TE ESPERAMOS EN UNA NUEVA PARTIDA                    °");
	puts("\t°                                                                   °");
	puts("\t°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°");
	system("COLOR 0E");
	puts("\nPresione ENTER para nuevo juego o ESC para terminar juego");
	
	do{
		fflush(stdin);
		tecla = getch();
		
	}while(tecla != 13 && tecla != 27);
	if(tecla == 13) nuevoJuego = 0;
	if(tecla == 27) nuevoJuego = 1;
}



void FPantallaFinal(){
	int x, h, y, count = 4000000;
	system("cls");
	for(x = 15;x>0;x--){
		for(y = 0; y<x;y++) printf("\n");
		puts(" °°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°");
		puts(" °                                                                            °");
		puts(" °    °°°°°°    °°°   °°      °°  °°°°°       °°°     °     °  °°°°° °°°°°    °");
		puts(" °   °°        °   °  ° °    ° °  °          °   °    °     °  °     °    °   °");
		puts(" °  °°         °   °  °  °  °  °  °         °     °   °     °  °     °    °   °");
		puts(" °  °°   °°°°  °°°°°  °   °°   °  °°°°     °       °  °     °  °°°°  °°°°°    °");
		puts(" °  °°      °  °   °  °        °  °         °     °   °     °  °     °    °   °");
		puts(" °   °°     °  °   °  °        °  °          °   °     °   °   °     °    °   °");
		puts(" °    °°°°°°°  °   °  °        °  °°°°°       °°°       °°°    °°°°° °    °   °");
		puts(" °                                                                            °");
		puts(" °°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°");
		
		system("cls");
		if(x%2==0) system("COLOR 07"); else system("COLOR F5");
		for(h=0; h<count;h++);
	}
	
	puts(" °°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°");
	puts(" °                                                                            °");
	puts(" °    °°°°°°    °°°   °°      °°  °°°°°       °°°     °     °  °°°°° °°°°°    °");
	puts(" °   °°        °   °  ° °    ° °  °          °   °    °     °  °     °    °   °");
	puts(" °  °°         °   °  °  °  °  °  °         °     °   °     °  °     °    °   °");
	puts(" °  °°   °°°°  °°°°°  °   °°   °  °°°°     °       °  °     °  °°°°  °°°°°    °");
	puts(" °  °°      °  °   °  °        °  °         °     °   °     °  °     °    °   °");
	puts(" °   °°     °  °   °  °        °  °          °   °     °   °   °     °    °   °");
	puts(" °    °°°°°°°  °   °  °        °  °°°°°       °°°       °°°    °°°°° °    °   °");
	puts(" °                                                                            °");
	puts(" °°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°");
	puts(" °                                                                            °");
	puts(" °                            GRACIAS POR JUGAR :)                            °");
	puts(" °                                                                            °");
	puts(" °°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°");
}
int FVerificarArea(int fila, int columna){
	int area[3][3], c, c2, repeticiones, c3, c4;
	/*se crea una matriz de 3x3 que sería un area del sudoku*/
	for(c=0;c<3;c++){
		for(c2=0;c2<3;c2++){
			area[c][c2] = sudoku[fila+c][columna+c2];
		}
	}
	/*se evalua que los valores sean unicos en su area*/
	for(c=0;c<3;c++){
		for(c2=0;c2<3;c2++){ /*Los primero dos for toman el numero a evaluar*/
			if(area[c][c2] != 0){
				repeticiones =0;
				for(c3=0;c3<3;c3++){ /*Los siguientes dos for evaluan en cada termino de la matriz*/
					for(c4=0;c4<3;c4++){
						if(area[c][c2] == area[c3][c4]) repeticiones++;
						if(repeticiones >=2){ xError = c3+fila; yError = c4+columna; return 1;} /*Toma los valores de la matriz area y los suma a los valores de entrada para sacar el error*/
					}
				}
			}
		}
	}
	return 0;
	
}
void FVerificarTablero(int matriz[MAX][MAX]){
	int c, c2, c3, repeticionesFila, repeticionesColumna, areaCorrecta;
	
	
	for(c=0;c<MAX;c++){ 
		for(c2=0;c2<MAX;c2++){
			repeticionesFila = 0;
			repeticionesColumna = 0;
			
				for(c3=0;c3<MAX;c3++){ /*Verifica que cada valor sea único en su fila y en su columna*/
					if(matriz[c][c2] == 0) break;
					if(matriz[c][c2] == matriz[c][c3]) repeticionesFila++;
					if(repeticionesFila>=2){ tableroCorrecto=1; xError = c; yError = c2; return;}
					if(matriz[c][c2] == matriz[c3][c2]) repeticionesColumna++;
					if(repeticionesColumna>=2){ xError = c; yError = c2; tableroCorrecto =1; return;}
				}
				/* lo siguiente verifica que el numero sea unico en su area
				solo entra a verificar area cuando detecta que esta en la esquina de una*/
				
				if((c==0 || c==3 || c==6) && (c2==0 || c2==3 || c2==6 )){
					areaCorrecta = FVerificarArea(c, c2);
					if(areaCorrecta == 1){ tableroCorrecto=1; return;}
				}
			
		}
	}
	
	tableroCorrecto= 0;
}
