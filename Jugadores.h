/*Esto pregunta si está definida la librería, en caso de no
estarlo la define*/
#ifndef __JUGADORES_H__
#define __JUGADORES_H__

#include <stdio.h>

//Estructura para los jugadores
typedef struct _Jugador{
    char* nombre, *club;
    int posicion, edad;
} _Jugador ;

//Jugador es un puntero _Jugador. Ahorra escribir _Jugador*
typedef _Jugador* Jugador; 

//Estructura de los nodos. Esta va a ser la lista de jugadores.
typedef struct nodo{
    Jugador jug;
    struct nodo* sig;
} Nodo;

//Libera el stdin, también sirve para esperar el ingreso de un enter.
void freeBuffer();

//El menu del programa
void menu();

//Muestra la lista de jugadores
void mostrarLista(Nodo* inicio);

//Crea una variable de jugador genérica, con espacio genérico asignado a nombre y club
Jugador creaJugador();

//Como dice el nombre, agrega un jugador a la lista
Nodo* agregaJugador(Nodo* inicio, Jugador j);

//Cambia el tamaño de nombre y club para que no se desperdicie memoria.
void redimensionaJugador(Jugador j);

//Toma los jugadores anotados en el archivo
int leeJugadorDelArchivo(Jugador j, FILE* file);

//Lee un segmento del archivo con el formato de jugador para ponerlo en un nodo
Nodo* leeNodoDelArchivo(Nodo* inicio, char* nombreArchivo);

//Filtra jugadores por la edad y los muestra
Nodo* recuperaJugadoresPorEdad(Nodo* inicio, int edadMax, int edadMin);

//Anota los jugadores de la lista en el archivo
void escribeJugadorEnArchivo(Jugador j, FILE* file);

//Libera todos los nodos del programa.
void liberaNodos(Nodo* temp);

#endif /* __JUGADORES_H__ */