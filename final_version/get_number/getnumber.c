#include <stdio.h>

void ft_imprimir(char *cadena, int start, int end)
{
    printf("Recibimos start %d, end %d\n", start, end);
    printf(">>>");
    while (start < end)
    {
        printf(" %c", cadena[start]);
        start++;
    }
    printf("<<<\n");
}

int ft_spaces(char c)
{
    return (c == ' ' || c == '\t' || c == '\n');
}

// Función corregida: calcula longitud desde 'start'
int ft_longitud_desde(char *cadena, int start)
{
    int longitud = 0;
    
    while (cadena[start + longitud] && !ft_spaces(cadena[start + longitud]))
    {
        longitud++;
    }
    return longitud;
}

void ft_get_number(char *cadena)
{
    int posicion = 0;
    int start, longitud;
    
    while (cadena[posicion])
    {
        // Saltamos espacios
        while (cadena[posicion] && ft_spaces(cadena[posicion]))
            posicion++;
        
        // Si llegamos al final, salimos
        if (!cadena[posicion])
            break;
            
        // Encontramos inicio de número
        start = posicion;
        longitud = ft_longitud_desde(cadena, start);
        
        printf("Número encontrado en posición %d:\n", start);
        ft_imprimir(cadena, start, start + longitud);
        
        // Avanzamos al siguiente número
        posicion = start + longitud;
    }
}

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Uso: %s \"1 2 3 4\"\n", argv[0]);
        return 1;
    }
    
    char *cadena = argv[1];
    ft_get_number(cadena);
    return 0;
}
