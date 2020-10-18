#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void freeBuffer(){
    int c;
    while((c = getchar()) != '\n' && c != EOF){}
}

void limpiarPantalla(){
  #if defined(linux) || defined(unix) || defined(APPLE)
    system("clear");
  #endif

  #if defined(_WIN32) || defined(_WIN64)
    system("cls");
  #endif
}