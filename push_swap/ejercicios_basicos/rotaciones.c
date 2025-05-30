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
	int n;
	int i;

	n = 15;
	printf("rotaciones = %d\n", rotaciones(n));

	return 0;
}
