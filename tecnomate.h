/*Esto pregunta si está definida la librería, en caso de no
estarlo la define*/

/*Una aclaración sobre este header. Nosotros tenemos un grupo desde el año pasado
para programación, y tenemos algunas funciones que solemos usar en los programas
que tienen que ver con el manejo visual de la consola, o de ciertos problemas como
liberar los \n que siguen en stdin. Esto lo armamos juntos así que puede que encuentres
las mismas funciones en otras tareas*/
#ifndef __TECNOMATE_H__
#define __TECNOMATE_H__

//Limpia el buffer de \n que quedaron, y permite esperar a que se ingrese un enter.
void freeBuffer();

//Limpia la consola.
void limpiarPantalla();

//Probablemente sigamos añadiendo más funciones en el futuro.

#endif /*  __TECNOMATE_H__  */