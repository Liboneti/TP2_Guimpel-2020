all: main.o Jugadores.o IngresosJugador.o tecnomate.o
	gcc main.o Jugadores.o IngresosJugador.o tecnomate.o

main.o: main.c Jugadores.h IngresosJugador.h tecnomate.h
	gcc -c main.c -g

IngresosJugador.o: IngresosJugador.c IngresosJugador.h Jugadores.h tecnomate.h
	gcc -c IngresosJugador.c -g

Jugadores.o: Jugadores.c Jugadores.h IngresosJugador.h tecnomate.h
	gcc -c Jugadores.c -g

tecnomate.o: tecnomate.c tecnomate.h
	gcc -c tecnomate.c -g

clean:
	rd *.o

cleanall:
	rd *.o a.exe