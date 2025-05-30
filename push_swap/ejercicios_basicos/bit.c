#include <stdio.h>
int rotaciones(int n)
{
	int i;

	i = 0;
	while (n > 0)
	{
		n = n >> 1;
		i++;
	}
	return i;
	
}

int main(int argc, char const *argv[])
{
	int bit;
	int contador;
	int acumulador;

	acumulador = 0;
	bit = 1;
	contador = 0;

	while (contador < 32)
	{
		printf("%d, acumulado: %d, sizeof: %ld\n", bit, acumulador, sizeof(bit));
		printf("Vamos a necesitar como mucho %d rotaciones\n", rotaciones(acumulador));
		acumulador = bit + acumulador;
		bit = bit<<1;
		contador++;
	}

	
	return 0;
}
