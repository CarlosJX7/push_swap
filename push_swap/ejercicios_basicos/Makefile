all: programa

programa: lista_enlazada.c
	gcc -o programa lista_enlazada.c

main: main.c ps_utils.c gestion_nodos.c movimientos.c 
	gcc -o main.out main.c ps_utils.c gestion_nodos.c movimientos.c

menu: main.c ps_utils.c gestion_nodos.c movimientos.c menu.c 
	gcc -o menu main.c ps_utils.c gestion_nodos.c movimientos.c menu.c


run:
	./programa

runmain:
	./main.out  0 1 2 3 4 5 6 7 8 9

runmenu:
	./menu 0 1 2 3 4 5 6 7 8 9 
clean:
	rm -rf programa *.o *.out