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
	printf("So long... ");
	Nodo* nuevoNodo = malloc(sizeof(Nodo));
	printf("... ");
	nuevoNodo->jug = malloc(sizeof(_Jugador));
	printf("Gay bowser...");
	nuevoNodo->jug->nombre = malloc(sizeof(char)*strlen(j->nombre)+1);
	nuevoNodo->jug->club = malloc(sizeof(char)*strlen(j->club)+1);
	strcpy(nuevoNodo->jug->nombre, j->nombre);
	strcpy(nuevoNodo->jug->club, j->club);
	nuevoNodo->jug->posicion = j->posicion;
	nuevoNodo->jug->edad = j->edad;
	nuevoNodo->sig = inicio;

	return nuevoNodo;
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
		printf("Me estoy volviendo pelotudo en loop\n");
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

void escribeNodoEnArchivo(Nodo* inicio, char* nombreArchivo){
	FILE* file = fopen(nombreArchivo, "w");
	Nodo* temp = inicio;

	for(; temp!=NULL; temp = temp->sig){
		escribeJugadorEnArchivo(temp->jug, file);
		liberaNodos(temp);
	}
	fclose(file);
}

void menu(){
	Nodo* inicio = NULL;
	int salida=0, ingreso;

	char* nombreArchivo = ingresoArchivo();
	FILE* file = fopen(nombreArchivo, "a");
	fclose(file);

	inicio = leeNodoDelArchivo(inicio, nombreArchivo);


	while(salida==0){
		limpiarPantalla();
		printf("\n\tMENU\n"
		"1- Mostrar lista\n"
		"2- Agregar jugadores a la lista\n"
		"3- Recuperar jugadores por edad\n"
		"4- Guardar y Cerrar programa\n");

		scanf("%d", &ingreso);
		freeBuffer();
		switch(ingreso)
		{
		case 1:
			mostrarLista(inicio);
			break;
		
		//case 2:
			inicio = ingresaJugadorPorTeclado(inicio);
			break;

		//case 3:
			recuperaJugadoresPorEdad(inicio, ingresaRangoDeEdad(1), ingresaRangoDeEdad(2));
			break;

		//case 4:
			escribeNodoEnArchivo(inicio, nombreArchivo);
			salida=1;
			break;
		default:
			printf("Ingreso invalido. Pruebe de vuelta...\n\n");
			freeBuffer();
			break;
		}
	}
}