#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>

typedef struct linked_list_1
{
    char *nombre;
    int edad;
}Persona;

void ft_imprimir_datos(Persona p1, Persona *p2)
{
    printf("El nombre es: %s y la edad es: %d\n", p1.nombre, p1.edad);
    printf("El nombre es: %s y la edad es: %d\n", p2->nombre, p2->edad);
}

void ft_imprimir_datos_reverso(Persona *p1, Persona p2)
{
    printf("-----------------------------\n");
    printf("v2: El nombre es: %s y la edad es: %d\n", p1->nombre, p1->edad);
    printf("v2: El nombre es: %s y la edad es: %d\n", p2.nombre, p2.edad);

}

int main(int argc, char const *argv[])
{
    Persona persona1;
    Persona *persona2;

    persona1.nombre = "Persona1";
    persona1.edad = 20;

    persona2 = malloc(sizeof(Persona));
    if (!persona2)
    {
        return 1;
    }
    persona2->nombre = "Persona2";
    persona2->edad = 42;

    ft_imprimir_datos(persona1, persona2);
    ft_imprimir_datos_reverso(&persona1, *persona2);


    return 0;
}
