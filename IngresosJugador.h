/*Esto pregunta si está definida la librería, en caso de no
estarlo la define*/
#ifndef __INGRESOSJUGADOR_H__
#define __INGRESOSJUGADOR_H__

#include "Jugadores.h"

//ingresa el nombre del archivo
char* ingresoArchivo();

//Ingreso por teclado de los datos de jugadores
Nodo* ingresaJugadorPorTeclado(Nodo* inicio, char* nombreArchivo);

//Ingreso de la edad maxima en modo 1 y la minima en modo 2 de la edad
int ingresaRangoDeEdad(int modo);


#endif /* __INGRESOSJUGADOR_H__ */