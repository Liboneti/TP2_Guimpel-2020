#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "Jugadores.h"
#include "IngresosJugador.h"
#include "tecnomate.h"

char* ingresoArchivo(){
	char buffer[150];
	char* nombre;
	printf("Ingrese el nombre del archivo para almacenar la lista:\n");
    printf("(Si el archivo no existe, se crea automaticamente)\n");
	scanf("%[^\n]", buffer);
	nombre = malloc(sizeof(char)*(strlen(buffer)+1));
	strcpy(nombre, buffer);

	return nombre;
}

Nodo* ingresaJugadorPorTeclado(Nodo* inicio){
	Jugador jugador = malloc(sizeof(_Jugador));
	char buffer[150];

	printf("Ingrese el nombre: ");
	scanf("%[^\n]", buffer);
	freeBuffer();
	jugador->nombre = malloc(sizeof(char)*strlen(buffer)+1);
	strcpy(jugador->nombre, buffer);

	printf("Ingrese el club: ");
	scanf("%[^\n]", buffer);
	freeBuffer();
	jugador->club = malloc(sizeof(char)*strlen(buffer)+1);
	strcpy(jugador->club, buffer);

	printf("Ingrese la posicion: ");
	scanf("%d", &jugador->posicion);

	printf("Ingrese la edad: ");
	scanf("%d", &jugador->edad);

    inicio = agregaJugador(inicio, jugador);

	free(jugador->nombre);
	free(jugador->club);
	free(jugador);

	return inicio;
}

int ingresaRangoDeEdad(int modo){
	int rango;
	if(modo==1){
		printf("Ingrese la edad maxima para la busqueda: ");
		scanf("%d", &rango);
	}
	else if(modo==2){
		printf("Ingrese la edad minima para la busqueda: ");
		scanf("%d", &rango);
	}
	return rango;
}