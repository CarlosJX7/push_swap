#include "ps_utils.h"
#include "movements.h"
#include "nodes.h"
#include <stdio.h>
#include <termios.h>
#include <unistd.h>

static void ft_imprimir_pilas(t_pila *pilaA, t_pila *pilaB)
{
    t_nodo *a = pilaA->primer_elemento;
    t_nodo *b = pilaB->primer_elemento;

    printf("\n   Pila A      Pila B\n");
    printf("  -------     -------\n");
    while (a || b)
    {
        if (a)
        {
            printf("   %6d", a->valor);
            a = a->siguiente_nodo;
        }
        else
            printf("         ");

        printf("   ");

        if (b)
        {
            printf("%6d", b->valor);
            b = b->siguiente_nodo;
        }
        printf("\n");
    }
    printf("-------------------------------\n");
}
void ft_imprimir_array(int *array_enteros, int cantidad)
{
    int j;
    j = 0;
    printf("-------------LISTA-------------\n");
    //while (array_enteros[j]) no imprime el 0
    while (j < cantidad)
    {
            printf("              [%d]\n", array_enteros[j]);
            j++;
        }
    printf("-------------------------------\n");
}
void set_raw_mode(int enable)
{
    static struct termios oldt, newt;
    if (enable)
    {
        tcgetattr(STDIN_FILENO, &oldt);
        newt = oldt;
        newt.c_lflag &= ~(ICANON | ECHO);
        tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    }
    else
    {
        tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    }
}

void menu_interactivo_flechas(t_pila *pilaA, t_pila *pilaB)
{
    int c;
    set_raw_mode(1);
    while (1)
    {
        c = getchar();
        if (c == 'q')
            break;
        printf("\033[H\033[J"); // Limpiar pantalla

        if (c == 27)
        {
            if (getchar() == 91)
            {
                c = getchar();
                switch (c)
                {
                    case 'A':
                        ft_rotate(pilaA);
                        ft_imprimir_pilas(pilaA, pilaB);
                        break;
                    case 'B':
                        ft_rotate_inverso(pilaA);
                        ft_imprimir_pilas(pilaA, pilaB);
                        break;
                    case 'C':
                        ft_push(pilaA, pilaB);
                        ft_imprimir_pilas(pilaA, pilaB);
                        break;
                    case 'D':
                        ft_push(pilaB, pilaA);
                        ft_imprimir_pilas(pilaA, pilaB);
                        break;
                    default:
                        break;
                }
            }
        }
        else
        {
            switch (c)
            {
                case 's':
                case 'S':
                    ft_swap(pilaA);
					ft_imprimir_pilas(pilaA, pilaB);
                    break;
                case 'r':
                case 'R':
                    printf("reverse\n");
                    break;
                // Puedes añadir más teclas aquí
                default:
                    break;
            }
        }
    }
    set_raw_mode(0);
}


void ft_imprimir_arry(int *array_enteros, int cantidad)
{
    int j;
    j = 0;
    printf("-------------LISTA-------------\n");
    //while (array_enteros[j]) no imprime el 0
    while (j < cantidad)
    {
            printf("              [%d]\n", array_enteros[j]);
            j++;
        }
    printf("-------------------------------\n");
}



void ft_iniciar_pila(t_pila *pila)
{
    pila->primer_elemento = NULL;
    pila->ultimo_elemento = NULL;
    pila->cantidad_elementos = 0;
}

int main(int argc, char const *argv[])
{
    int i = 1;
    t_pila *pila_A;
    t_pila *pila_B;

    pila_A = malloc(sizeof(t_pila));
    pila_B = malloc(sizeof(t_pila));
    ft_iniciar_pila(pila_A);
    ft_iniciar_pila(pila_B);

    if (argc < 2)
    {
        return 0;
    }
    
    while (argv[i])
    {
        ft_agregar_nodo(pila_A, ft_atoi(argv[i]));
        i++;
    }


    //ft_imprimir_pilas(pila_A, pila_B);
    //ft_push(pila_A, pila_B);
    //printf("SWAP\n");
    //ft_swap(pila_A);
    //ft_imprimir_pilas(pila_A, pila_B);
    //ft_imprimir_arry(ft_pila_to_array(pila_A), pila_A->cantidad_elementos);
    //ft_push(pila_A, pila_B);
    //ft_imprimir_arry(ft_pila_to_array(pila_B), pila_B->cantidad_elementos);
    menu_interactivo_flechas(pila_A, pila_B);
    /*
    array_enteros = ft_pila_to_array(pila_A);
    printf("Imprimiendo array sin modificar\n");
    ft_imprimir_arary(array_enteros, pila_A->cantidad_elementos);
    ft_rotate(pila_A);
    printf("Imprimiendo array ft_rotate\n");
    ft_imprimir_arary(ft_pila_to_array(pila_A), pila_A->cantidad_elementos);
    printf("Imprimiendo array ft_rotate_inverso\n");
    ft_rotate_inverso(pila_A);
    ft_imprimir_arary(ft_pila_to_array(pila_A), pila_A->cantidad_elementos);
    */
   
   ft_vaciar_pila(pila_A);
   ft_vaciar_pila(pila_B);
    return 0;
}
