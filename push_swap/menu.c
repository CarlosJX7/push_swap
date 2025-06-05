/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cinaquiz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 14:16:46 by cinaquiz          #+#    #+#             */
/*   Updated: 2025/05/26 14:16:48 by cinaquiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
            printf("   %6d, indice = %d", a->valor, a->index);
            a = a->siguiente_nodo;
        }
        else
            printf("         ");

        printf("   ");

        if (b)
        {
            printf("%6d, indice = %d", b->valor, b->index);
            b = b->siguiente_nodo;
        }
        printf("\n");
    }
    printf("-------------------------------\n");
}

void imprimir_pila(t_pila *pila)
{
    t_nodo *node;

    node = pila->primer_elemento;
    printf("INICIO PILA\n");
    while (node != NULL)
    {
        printf("Valor >%d<, indice >%d<\n", node->valor, node->index);
        node = node->siguiente_nodo;
    }
    printf("FIN PILA\n");
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
    printf("Imprimimos el array sin ordenar\n");
    int *pila_array = ft_pila_to_array(pila_A);
    ft_imprimir_arry(pila_array, pila_A->cantidad_elementos);

    printf("Procedemos a ordenar el array\n");
    int *array_ordenado = ft_ordenar_array(pila_array, pila_A->cantidad_elementos);
    ft_imprimir_arry(array_ordenado, pila_A->cantidad_elementos);
    ft_pila_indices(pila_A, array_ordenado);

    ft_radix(pila_A, pila_B);
    menu_interactivo_flechas(pila_A, pila_B);
    imprimir_pila(pila_A);
    imprimir_pila(pila_B);

   ft_vaciar_pila(pila_A);
   ft_vaciar_pila(pila_B);
   printf("FIN DEL PROGRAMA\n");
    return 0;
}
