/*JUEGO REALIZADO EN LENGUAJE C*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include <ctype.h>


void MostrarMenu();
void categorias();
void InstruccionesA();
void Instrucciones3();
void ingresoCategoria (int op);
void empezarJuego (char palabras[][15], char nombre[]);
void dibujo (int intentos);
void introPrimer(char c[3][3]);
void loop (char c[3][3]);
void tablero(char c[3][3]);
void introValores(char c[3][3]);
void introIa (char c[3][3]);
int ganador(char c[3][3]);
int rachaVictorias;
int rachaDerrotas;
int opcion;
int salir();
int z;

int main(){
	rachaVictorias = 0;
	rachaDerrotas = 0;
	opcion = 0;
	MostrarMenu();
	
return 0;
}

void MostrarMenu(){

	do{
		system ("COLOR 2");
		printf("                                           \n\n     \n\n");
		printf("                                                 ***CABRA JUEGOS***\n\n");
		printf("                                                   ***MENU***     \n\n");
		printf("                                                 1. JUGAR AHORCADO\n\n");
		printf("                                                 2. COMO JUGAR AHORCADO?\n\n");
		printf("                                                 3. JUGAR 3 EN RAYAS \n\n");
		printf("                                                 4. COMO JUGAR 3 EN RAYAS?\n\n");
		printf("                                                 5. SALIR\n\n");
		printf("                                                    ");
		scanf("%d", &opcion);
		
		switch(opcion){
			case 1:{
				categorias();
				system("cls");
				break;
			}
				case 2:{
				InstruccionesA();
				system("cls");
				break;
			}
				case 3:{
				char c[3][3];
				loop (c);
				system("cls");
				break;
			}
				case 4:{
				Instrucciones3();
				system("cls");
						break;
			}
				case 5:{
				int salir();
				system("cls");
				break;
			}
		}
	}while(opcion != 5);
}
	int salir(){
	return 0;
}
void InstruccionesA(){
	system("cls");
	printf("\n\n");
	printf("                                         GUIA DE COMO JUGAR     \n\n");
	printf("                                    A. El juego del ahorcado se trata de adivinar una palabra con un numero de intentos limitados\n\n");
	printf("                                    B. Una vez dentro del juego se debe seleccionar una categoria\n\n");
	printf("                                    C. Cuando seleccionemos la categoria se generara una palabra aleatoria correspondiente a la categoria\n\n");
	printf("                                    D. Una vez generada la palabra tendremos que digitar una letra y si dicha letra se encuentra dentro de la palabra se cambia el guion bajo por la letra\n\n");
	printf("                                    E. El juego termina cuando encontramos todas las letras de la palabra o cuando se nos acaben los intentos disponibles\n\n ");
	system("pause");
	}

	
void Instrucciones3(){
	system("cls");
	printf("\n\n");
	printf("                                         GUIA DE COMO JUGAR     \n\n");
	printf("                                    A. El juego de 3 en rayas se trata de colocar 3 X de formar que se cree una raya\n\n");
	printf("                                    B. Una vez dentro del juego se compite contra un bot y comienza el jugador\n\n");
	printf("                                    C. Cuando es su turno coloca una X , luego el bot colocara un O en un casillero\n\n");
	printf("                                    D. El que logre colocar 3 (X o O) en una fila lineal de 3 ganara\n\n");
	system("pause");
	}

/*FUNCION CATEGORIAS, IMPRIME EN PANTALLA LAS CATEGORIAS Y PERMITE ELEGIR UNA*/
void categorias(){
	int op;
	do{
		system("cls"); /*esta sentencia sirve para que el usuario no vea los datos le dimos previamente*/
		printf("\n\t\t\t\t                         JUEGO AHORCADO\n\n");
		printf("                                     SELECCIONE UNA CATEGORIA\n\n");
		printf("                                     1. Frutas\n");
		printf("                                     2. Animales\n");
		printf("                                     3. Paises\n");
		printf("                                     4. Objetos\n");
		printf("                                     5. Provincias\n");
		printf("                                     6. Deportes\n");
		printf("                                     7. Colores\n");
		printf("                                     0 PARA VOLVER AL MENU\n\n");
		
		printf("                                     DIGITE EL NUMERO DE LA CATEGORIA ELEGIDA:    ");
		
		scanf("%d",&op);
		
		
	}while(op<0 || op>7);
	
	if (op==0) ingresoCategoria(op);
	if (op==1) ingresoCategoria(op);
	if (op==2) ingresoCategoria(op);
	if (op==3) ingresoCategoria(op);
	if (op==4) ingresoCategoria(op);
	if (op==5) ingresoCategoria(op);
	if (op==6) ingresoCategoria(op);
	if (op==7) ingresoCategoria(op);
	
}


/*/ESTA FUNCION RECIBE UN VALOR, Y DEPENDIENDO DEL VALOR RECIBIDO LLAMA A OTRA FUNCION PARA EMPEZAR EL JUEGO*/
void ingresoCategoria (int op){
	char nombrecat[7][15] = {"Frutas","Animales","Paises","Objetos", "Provincias", "Deportes", "Colores" };
	char frutas [10][15] = {"MELON","BANANA","SANDIA","MANZANA","PERA","NARANJA","UVA","CEREZA","CIRUELA","KIWI"};
	char animales [10][15] = {"PERRO","GATO","CABALLO","GALLINA","JIRAFA","MONO","VACA","CONEJO","TORTUGA","LOBO"};
	char paises [10][15] = {"PERU","COLOMBIA","ARGENTINA","NICARAGUA","ITALIA","MEXICO","CANADA","VENEZUELA","ECUADOR","BRASIL"};
	char objetos [10][15] = {"MOCHILA","RELOJ","ZAPATILLA","MUEBLE","CUADERNO","SILLA","MESA","CELULAR","PUERTA","AURICULARES"};
	char provincias[10][15]={"CHACO", "TUCUMAN", "NEUQUEN", "MENDOZA", "JUJUY","SALTA", "FORMOSA","CORRIENTES", "CORDOBA", "MISIONES"};
	char deportes [10][15]={"FUTBOL", "TENNIS", "RUGBY", "BASQUET", "NATACION", "VOLEY", "HOCKEY", "BOXEO", "TAEKWONDO", "JUDO"};
	char colores[10][15]={"ROJO", "AZUL", "VERDE", "AMARILLO", "NARANJA", "BLANCO", "NEGRO", "ROSA", "CELESTE", "VIOLETA"};
	switch(op){
		case 1:
			empezarJuego(frutas,nombrecat[op-1]);
			break;
		case 2:
			empezarJuego(animales,nombrecat[op-1]);
			break;
		case 3:
			empezarJuego(paises,nombrecat[op-1]);
			break;
		case 4:
			empezarJuego(objetos,nombrecat[op-1]);
			break;	
		case 5:
			empezarJuego(provincias,nombrecat[op-1]);
			break;
		case 6:
			empezarJuego(deportes, nombrecat[op-1]);
			break;
		case 7:
			empezarJuego(colores, nombrecat[op-1]);
			break;
		case 0:{
			system("cls");
			MostrarMenu(); 
			break;
		}	
	}	
}


/*VOID QUE CONTIENE EL ALGORITMO DEL JUEGO*/
void empezarJuego (char palabras[][15], char nombre[]){
	int opcion,i,j,k,longitud,espacios,puntos=1200;
	char letra;
	int aciertos = 0;
	int intentos = 0;
	int ganar = 0;
	srand(time(NULL));
	
	opcion = rand() % 5; 
	longitud = strlen(palabras[opcion]); 
	char frase[longitud];
	

	for(i=0; i < longitud; i++){
		frase[i] = '_';
	}
	
	
	do{
		aciertos = 0;
		system("cls");
		printf("\n\t\t\t\tJUEGO EL AHORCADO\n\n");
		printf(" CATEGORIA: %s\n\n",nombre);
		printf(" Intentos Disponibles: %d\t\t\t\tPuntuacion: %i\n\n Racha de aciertos: %d\n\n Racha de derrotas: %d\n\n",6-intentos,puntos, rachaVictorias, rachaDerrotas);
		printf(" 0 PARA VOLVER AL MENU\n\n");
		dibujo(intentos);
		

		printf("\n\n\n");
		for(i=0; i < longitud; i++){
			printf(" %c ",frase[i]);
		}

		
		if (intentos == 6){
			rachaDerrotas = rachaDerrotas +1;		
			printf("\n\n PERDISTE!!\n");
			printf(" LA SOLUCION ERA: %s\n\n",palabras[opcion]);
			printf(" SE HA PERDIDO LA RACHA DE VICTORIAS! %d",rachaDerrotas);
			printf(" Si desea volver a jugar presione cualquier tecla ");
			getch();
			categorias();	
		}
		
		
	/*ESTE ES EL PROCESO QUE COMPRUEBA SI SE HA ADIVINADO LA PALABRA*/
		espacios=0;
		
		for (i = 0; i < longitud; i++){
			if (frase[i] == '_')
				espacios++;
		}
		
		
		if (espacios == 0){
			rachaVictorias = rachaVictorias + 1;
			printf("\n\n FELICIDADES.. GANASTE!!\n\n");
			printf("\n\n COMENZASTE UNA RACHA DE VICTORIAS!");
			printf(" Si desea volver a jugar presione cualquier tecla ");
			getch();
			categorias();		
		}
		
		
		printf("\n\n ELIJA UNA LETRA: ");
		scanf(" %c",&letra);
		letra = toupper(letra);
		
		
	/*PROCESO QUE VERIFICA SI LA LETRA INGRESADA EXISTE EN LA PALABRA, SI ESTO ES VERDADERO, SE REEMPLAZA EL CARACTER GUION BAJO POR LA LETRA INGRESADA*/
		for (j = 0; j < longitud; j++){
			if (toupper(palabras[opcion][j]) == letra) {  // Convertir la palabra a mayúscula
				frase[j] = letra;
				aciertos++;
			}	
		}
		
		if (aciertos == 0){
			intentos++;	
			puntos -= 200;
		}
		if(letra == '0'){
			system("cls");
			return (MostrarMenu());
			intentos == 6;
		}
		
			
	}while(intentos != 7);
	
	printf("\n\n");		
}


void dibujo (int intentos){
	switch(intentos){
		case 0:
			printf("\n     _______\n    |       |\n    |\n    |\n    |\n    |\n    |\n ----------");
			break;
		case 1:
			printf("\n     _______\n    |       |\n    |       0\n    |\n    |\n    |\n    |\n ----------");
			break;
		case 2:
			printf("\n     _______\n    |       |\n    |       0\n    |       |\n    |\n    |\n    |\n ----------");
			break;
		case 3:
			printf("\n     _______\n    |       |\n    |       0\n    |      /|\n    |\n    |\n    |\n ----------");
			break;
		case 4:
			printf("\n     _______\n    |       |\n    |       0\n    |      /|");
			printf("\\");
			printf("\n");
			printf("    |\n    |\n    |\n ----------");
			break;
		case 5:
			printf("\n     _______\n    |       |\n    |       0\n    |      /|");
			printf("\\");
			printf("\n");
			printf("    |      /\n    |\n    |\n ----------");
			break;
		case 6:
			printf("\n     _______\n    |       |\n    |       0\n    |      /|");
			printf("\\");
			printf("\n");
			printf("    |      / ");
			printf("\\");
			printf("\n");
			printf("    |\n    |\n ----------");
			break;
	}
	
}

void loop (char c[3][3]){
	int i,j;
	
	i = 0;
	
	introPrimer(c);
	
	do{
		system ("cls");
		tablero(c);
		
		if(i % 2 == 0){
			introValores(c);	
		}
		else {
			introIa(c);
		}
		j = ganador(c);
		i++;
		
	}while ( i<9 && j==2);
		system ("cls");
		tablero(c);
	if(j==0){
		printf(" GANASTE FELICITACIONES!!! \n\n");
				system ("pause");
				system ("cls");
				MostrarMenu();	
		
	}
	if(j==1){
		printf(" PERDISTE INTENTALO DE NUEVO!!! \n\n");
			system ("pause");
			system ("cls");	
			MostrarMenu();
		
	}
	if(j==2){
		printf(" EMPATASTE SUERTE EN EL PROXIMO INTENTO \n\n");
			system ("pause");
			system ("cls");
			MostrarMenu();
		
		}
 

	}
void introPrimer (char c[3][3]){
	int i,j;
	char aux;
	
	aux='1';

	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			c  [i][j] = aux++;
		}
	}
	
}


void tablero(char c[3][3]){
		int i,j;
		
		
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			if(j<2){
			printf(" %c |", c[i] [j]);	
			}
			else {
				printf(" %c ", c[i] [j]);
			}
		}
		if(i<2){	
			printf("\n-----------\n");	
			}
			
	}printf("\n\n");
	
}
void introValores(char c[3][3]){
	char aux;
	int i,j,k,p;
	
	do {
		do{	printf("\n\n       PRECIONE 0 PARA VOLVER \n\n ");
			printf("\n\n       COLOCAR UNA FICHA:   \n\n ");
			printf("                    ");
			fflush (stdin);
			scanf("%c", &aux);
			}while (aux < '0' || aux> '9');
			k = 0;
			
			switch (aux){
				case '1': {
					i = 0;
					j = 0;
					if(c[i] [j] == 'x' || c[i] [j] == 'O'){
						k = 1;
						printf("la casilla seleccionada esta ocupada, intente con otro numero \n\n");
					}
					break;
				}
				case '2': {
					i = 0;
					j = 1;
					if(c[i] [j] == 'x' || c[i] [j] == 'O'){
						k = 1;
						printf("la casilla seleccionada esta ocupada, intente con otro numero \n\n");
					}
					break;
				}case '3': {
					i = 0;
					j = 2;
					if(c[i] [j] == 'x' || c[i] [j] == 'O'){
						k = 1;
						printf("la casilla seleccionada esta ocupada, intente con otro numero \n\n");
					}
					break;
				}case '4': {
					i = 1;
					j = 0;
					if(c[i] [j] == 'x' || c[i] [j] == 'O'){
						k = 1;
						printf("la casilla seleccionada esta ocupada, intente con otro numero \n\n");
					}
					break;
				}case '5': {
					i = 1;
					j = 1;
					if(c[i] [j] == 'x' || c[i] [j] == 'O'){
						k = 1;
						printf("la casilla seleccionada esta ocupada, intente con otro numero \n\n");
					}
					break;
				}case '6': {
					i = 1;
					j = 2;
					if(c[i] [j] == 'x' || c[i] [j] == 'O'){
						k = 1;
						printf("la casilla seleccionada esta ocupada, intente con otro numero \n\n");
					}
					break;
				}case '7': {
					i = 2;
					j = 0;
					if(c[i] [j] == 'x' || c[i] [j] == 'O'){
						k = 1;
						printf("la casilla seleccionada esta ocupada, intente con otro numero \n\n");
					}
					break;
				}case '8': {
					i = 2;
					j = 1;
					if(c[i] [j] == 'x' || c[i] [j] == 'O'){
						k = 1;
						printf("la casilla seleccionada esta ocupada, intente con otro numero \n\n");
					}
					break;
				}case '9': {
					i = 2;
					j = 2;
					if(c[i] [j] == 'x' || c[i] [j] == 'O'){
						k = 1;
						printf("la casilla seleccionada esta ocupada, intente con otro numero \n\n");
					}
					break;
				}case '0':{
					k=0;
					p=1;
				}
			}
		}while (k==1);
		if(p==1){
			system ("cls");
			MostrarMenu();
		
		}
		else{c[i] [j] = 'x';
		}
		
		
	}
	void introIa (char c[3][3]){
		int i,j,k;
		srand (time(NULL));
		do{
		i=rand() % 3;
		j=rand() % 3;
		k=0;
			if(c[i] [j] == 'x' || c[i] [j] == 'O'){
				k=1;
			}
		}while(k==1);
		c[i] [j] = 'O';
	}
	int ganador (char c[3][3]){
		if( c[0][0]=='x' || c[0] [0] == 'O'){
			if(c[0][0]==c[0][1] && c[0][0]==c[0][2]){
				if(c[0][0]=='x'){
					return 0; /*he ganado*/
				}
				else {
					return 1; /*he perdido*/
				}
			}
			if(c[0][0]==c[1][0] && c[0][0]==c[2][0]){
					if(c[0][0]=='x'){
						return 0; /*he ganado*/
					}
					else {
						return 1; /*he perdido*/
				}
			}
		}
		if(c[1][1]=='x' || c[1] [1] == 'O'){
			if(c[1][1]==c[0][0] && c[1][1]==c[2][2]){
				if(c[1][1]=='x'){
					return 0; /*he ganado*/
				}
				else {
					return 1; /*he perdido*/
					}
			}
			if(c[1][1]==c[1][0] && c[1][1]==c[1][2]){
				if(c[1][1]=='x'){
					return 0; /*he ganado*/
				}
				else {
					return 1; /*he perdido*/
					}
			}
			if(c[1][1]==c[2][0] && c[1][1]==c[0][2]){
				if(c[1][1]=='x'){
					return 0; /*he ganado*/
				}
				else {
					return 1; /*he perdido*/
					}
			}
			if(c[1][1]==c[0][1] && c[1][1]==c[2][1]){
				if(c[1][1]=='x'){
					return 0; /*he ganado*/
				}
				else {
					return 1; /*he perdido*/
					}
			}
		}
		if(c[2][2]=='x' || c[2] [2] == 'O'){
			if(c[2][2]==c[2][0] && c[2][2]==c[2][1]){
				if(c[2][2]=='x'){
					return 0; /*he ganado*/
				}
				else {
					return 1; /*he perdido*/
					}
				}
			if(c[2][2]==c[0][2] && c[2][2]==c[1][2]){
				if(c[2][2]=='x'){
					return 0; /*he ganado*/
				}
				else {
					return 1; /*he perdido*/
					}
				}	
		}
return 2;
}
