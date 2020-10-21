#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Jugadores.h"
#include "IngresosJugador.h"
#include "tecnomate.h"

void mostrarLista(Nodo* inicio){
	Nodo* aux = inicio;

	for(; aux != NULL; aux = aux->sig){
		printf("%s, %s, %d, %d\n", aux->jug->nombre, aux->jug->club, aux->jug->posicion, aux->jug->edad);
	}
	printf("\nPresione enter para continuar...\n\n");
	freeBuffer();
}

Jugador creaJugador(){
	Jugador j = malloc(sizeof(_Jugador));
	j->nombre = malloc(sizeof(char)*100);
	j->club = malloc(sizeof(char)*100);
	return j;
}

Nodo* agregaJugador(Nodo* inicio, Jugador j){
	Nodo* nuevoNodo = malloc(sizeof(Nodo));
	nuevoNodo->jug = malloc(sizeof(_Jugador));
	nuevoNodo->jug->nombre = malloc(sizeof(char)*strlen(j->nombre)+1);
	nuevoNodo->jug->club = malloc(sizeof(char)*strlen(j->club)+1);
	strcpy(nuevoNodo->jug->nombre, j->nombre);
	strcpy(nuevoNodo->jug->club, j->club);
	nuevoNodo->jug->posicion = j->posicion;
	nuevoNodo->jug->edad = j->edad;
	nuevoNodo->sig = NULL;

	if(inicio==NULL){
		return nuevoNodo;
	}

	Nodo* aux = inicio;
	for(; aux->sig != NULL; aux = aux->sig);
	aux->sig = nuevoNodo;

	return inicio;
}

int  leeJugadorDelArchivo(Jugador j, FILE* file){
	return fscanf(file, "%[^,],%[^,],%d,%d\n", j->nombre, j->club, &j->posicion, &j->edad);
	//char nombre[100];
	//char club[100];
	//int posicion;
	//int edad;
	//int r = fscanf(file, "%[^,],%[^,],%d,%d\n", nombre, club, &posicion, &edad);
	//strcpy(j->nombre, nombre);
	//strcpy(j->club, club);
	//j->posicion = posicion;
	//j->edad = edad;
}

Nodo* leeNodoDelArchivo(Nodo* inicio, char *nombreArchivo) {
	FILE* file = fopen(nombreArchivo, "r");
	Jugador j = creaJugador();
	while(leeJugadorDelArchivo(j, file) != EOF){
		inicio = agregaJugador(inicio, j);
	}
	free(j->nombre);
	free(j->club);
	free(j);
	fclose(file);
	return inicio;
}

Nodo* recuperaJugadoresPorEdad(Nodo* inicio, int edadMax, int edadMin){

}

void escribeJugadorEnArchivo(Jugador j, FILE* file){
	 fprintf(file, "%s,%s,%d,%d\n", j->nombre, j->club, j->posicion, j->edad);
}

void liberaNodos(Nodo* temp){
	free(temp->jug->nombre);
	free(temp->jug->club);
	free(temp->jug);
	free(temp);
}
