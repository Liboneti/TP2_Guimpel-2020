#include <stdio.h>
#include <stdlib.h>
#include "Jugadores.h"
#include "IngresosJugador.h"
#include "tecnomate.h"

int main(int argc, char *argv[]){
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
		
		case 2:
		 	inicio = ingresaJugadorPorTeclado(inicio, nombreArchivo);
		 	break;

		//case 3:
		// 	recuperaJugadoresPorEdad(inicio, ingresaRangoDeEdad(1), ingresaRangoDeEdad(2));
		// 	break;

		case 4:
			salida=1;
			break;
		default:
			printf("Ingreso invalido. Pruebe de vuelta...\n\n");
			freeBuffer();
			break;
		}
	}

    return 0;
}