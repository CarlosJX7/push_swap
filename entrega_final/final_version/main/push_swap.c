/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cinaquiz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 21:11:56 by cinaquiz          #+#    #+#             */
/*   Updated: 2025/09/08 21:11:58 by cinaquiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibft.h"
#include "main_utils.h"
#include "utils.h"
#include "../node_stack/node_stack.h"
#include "../parsing/parsing.h"
#include "../parsing/get_string.h"
#include "../node_stack/stack_management.h"
#include "../node_stack/node_managment.h"
#include "../algoritmos/algoritmos.h"
//#include "../algoritmos/radix.h"
#include "../algoritmos/chunks.h"

#include <stdio.h> // para printf

#include <stdio.h>
#include <stdlib.h>

/* Convierte un entero a cadena con su representación binaria */
/* Devuelve un puntero a una cadena estática que debe ser usada o copiada antes de otra llamada */
const char *int_to_binary(int n)
{
    static char bin[33];  // 32 bits + terminador
    int i;

    bin[32] = '\0';
    for (i = 31; i >= 0; i--)
    {
        bin[i] = (n & 1) ? '1' : '0';
        n >>= 1;
    }
    // Omitir ceros a la izquierda para mostrar solo los bits necesarios
    // Encontrar primer 1 desde la izquierda
    for (i = 0; i < 31; i++)
    {
        if (bin[i] == '1')
            break;
    }
    // Retornar puntero a la posición del primer 1 o al último bit (0) si era 0
    return &bin[i];
}

void ft_imprimir_pila(t_stack *pila)
{
    t_node *nodo;

    if (!pila || pila->cantidad_elementos == 0)
    {
        printf("Pila vacía.\n");
        return;
    }

    nodo = pila->primer_elemento;
    printf("Elementos de la pila (valor, índice decimal, índice binario) (total: %d):\n", pila->cantidad_elementos);
    while (nodo)
    {
        printf("(%d, %d, %s)\n", nodo->valor, nodo->index, int_to_binary(nodo->index));
        nodo = nodo->siguiente_nodo;
    }
}



int	*ft_contruir_array(char **tokens, int *array)
{
	int	i;

	i = 0;
	while (tokens[i])
	{
		array[i] = ft_atoi(tokens[i]);
		if (ft_is_duplicate(array, i, array[i]))
		{
			free(array);
			ft_free_tokens(tokens);
			ft_print_error();
		}
		i++;
	}
	ft_free_tokens(tokens);
	return (array);
}

static int	*ft_parse_single_arg(char *arg, int *size)
{
	char	**tokens;
	int		*array;

	if (!arg)
		ft_print_error();
	tokens = ft_split(arg, ' ');
	if (!tokens)
		ft_print_error();
	*size = ft_count_tokens(tokens);
	array = malloc(*size * sizeof(int));
	if (!array)
	{
		ft_free_tokens(tokens);
		ft_print_error();
	}
	return (ft_contruir_array(tokens, array));
}

static int	*ft_parse_args(int argc, char **argv, int *size)
{
	int	*array;
	int	i;

	*size = argc - 1;
	array = malloc(*size * sizeof(int));
	if (!array)
		ft_print_error();
	i = 0;
	while (i < *size)
	{
		array[i] = ft_atoi(argv[i + 1]);
		if (ft_is_duplicate(array, i, array[i]))
		{
			free(array);
			ft_print_error();
		}
		i++;
	}
	return (array);
}

static void	ft_process(int *array, int size)
{
	t_stack	*pila_a;
	t_stack	*pila_b;
	int		*aux;

	pila_a = ft_pila_ini();
	pila_b = ft_pila_ini();
	if (!pila_a || !pila_b)
	{
		free(array);
		ft_print_error();
	}
	ft_fill_stack(pila_a, array, size);
	free(array);
	if (ft_pila_to_array(pila_a) == NULL)
	{
		ft_pilas_free(pila_a, pila_b);
		return ;
	}
	aux = ft_pila_to_array(pila_a);
	aux = ft_ordenar_array(aux, pila_a->cantidad_elementos);
	ft_index_ordenado(pila_a, aux);
	free(aux);
	if (!ft_algoritmos(size + 1, pila_a, pila_b))
		ft_chunks(pila_a, pila_b);
		//ft_radix(pila_a, pila_b);
	//ft_imprimir_pila(pila_a);
	//ft_imprimir_pila(pila_b);
	ft_pilas_free(pila_a, pila_b);
}

int	main(int argc, char **argv)
{
	int	*array;
	int	size;
	int	k;

	k = 0;
	if (argc < 2)
		return (0);
	if (argc == 2)
	{
		while (argv[1][k] && ft_isspace(argv[1][k]))
			k++;
		if (argv[1][k] == '\0')
			ft_print_error();
		array = ft_parse_single_arg(argv[1], &size);
	}
	else
		array = ft_parse_args(argc, argv, &size);
	ft_process(array, size);
	return (0);
}


/////////////////////////////parsing fixed




















/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cinaquiz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 21:11:56 by cinaquiz          #+#    #+#             */
/*   Updated: 2025/09/12 13:15:00 by cinaquiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibft.h"
#include "main_utils.h"
#include "utils.h"
#include "../node_stack/node_stack.h"
#include "../parsing/parsing.h"
#include "../parsing/get_string.h"
#include "../node_stack/stack_management.h"
#include "../node_stack/node_managment.h"
#include "../algoritmos/algoritmos.h"
//#include "../algoritmos/radix.h"
#include "../algoritmos/chunks.h"

#include <stdio.h>
#include <stdlib.h>

/* Convierte un entero a cadena con su representación binaria
   Devuelve un puntero a una cadena estática que debe ser usada o copiada antes de otra llamada */
const char *int_to_binary(int n)
{
    static char bin[5];  // 32 bits + terminador
    int i;

    bin[6] = '\0';
    for (i = 31; i >= 0; i--)
    {
        bin[i] = (n & 1) ? '1' : '0';
        n >>= 1;
    }
    // Omitir ceros a la izquierda para mostrar solo los bits necesarios
    // Encontrar primer 1 desde la izquierda
    for (i = 0; i < 31; i++)
    {
        if (bin[i] == '1')
            break;
    }
    // Retornar puntero a la posición del primer 1 o al último bit (0) si era 0
    return &bin[i];
}

void ft_imprimir_pila(t_stack *pila)
{
    t_node *nodo;

    if (!pila || pila->cantidad_elementos == 0)
    {
        printf("Pila vacía.\n");
        return;
    }
    nodo = pila->primer_elemento;
    printf("Elementos de la pila (valor, índice decimal, índice binario) (total: %d):\n", pila->cantidad_elementos);
    while (nodo)
    {
        printf("(%d, %d, %s)\n", nodo->valor, nodo->index, int_to_binary(nodo->index));
        nodo = nodo->siguiente_nodo;
    }
}

/* (Opcional) Construye un array a partir de tokens ya divididos */
int *ft_contruir_array(char **tokens, int *array)
{
    int i;

    i = 0;
    while (tokens[i])
    {
        array[i] = ft_atoi(tokens[i]);
        if (ft_is_duplicate(array, i, array[i]))
        {
            free(array);
            ft_free_tokens(tokens);
            ft_print_error();
        }
        i++;
    }
    ft_free_tokens(tokens);
    return (array);
}

/* ============================== PARSING ============================== */

/* Contar todos los tokens resultantes de dividir por espacios cada argv[i] */
static int count_all_tokens(int argc, char **argv)
{
    int     total;      /* total de tokens encontrados en todos los argumentos */
    int     i;          /* índice para recorrer argv */
    char  **tokens;     /* array temporal con los tokens de un argv[i] */

    total = 0;          /* inicializamos el contador total en 0 */
    i = 1;              /* empezamos en 1 porque argv[0] es el nombre del programa */
    while (i < argc)    /* recorremos todos los argumentos pasados al programa */
    {
        tokens = ft_split(argv[i], ' '); /* dividimos el argumento actual por espacios */
        if (!tokens)                     /* si ft_split falla y devuelve NULL */
            ft_print_error();            /* abortamos mostrando "Error" según la norma del proyecto */
        total += ft_count_tokens(tokens);/* acumulamos cuántos tokens no vacíos produjo este argumento */
        ft_free_tokens(tokens);          /* liberamos la matriz de tokens de este argumento */
        i++;                             /* avanzamos al siguiente argumento */
    }
    return total;        /* devolvemos el total de tokens encontrados */
}

/* Parseo unificado: divide cada argv[i] por espacios, valida y acumula */
static int *ft_parse_mixed_args(int argc, char **argv, int *size)
{
    int     total;     /* total de tokens (números) previstos para reservar memoria */
    int     i;         /* índice para recorrer argv */
    int     k;         /* índice de escritura en el array resultante */
    char  **tokens;    /* tokens del argumento actual tras hacer split */
    int    *array;     /* array final con todos los enteros parseados */

    total = count_all_tokens(argc, argv); /* contamos primero para saber cuánta memoria reservar */
    if (total == 0)                       /* si no hay ningún token válido (todo eran espacios, p. ej.) */
        ft_print_error();                 /* se considera entrada inválida según la norma */
    array = malloc(total * sizeof(int));  /* reservamos memoria para todos los enteros */
    if (!array)                           /* si malloc falla */
        ft_print_error();                 /* abortamos con "Error" */
    k = 0;                                /* inicializamos el índice de escritura en el array final */
    i = 1;                                /* empezamos en argv[1] (primer argumento de usuario) */
    while (i < argc)                      /* procesamos cada argumento recibido */
    {
        int j = 0;                        /* índice para recorrer los tokens del argumento actual */
        tokens = ft_split(argv[i], ' ');  /* dividimos argv[i] por espacios para extraer números */
        if (!tokens)                      /* comprobamos fallo del split por seguridad */
        {
            free(array);                  /* liberamos el array ya reservado para evitar fuga */
            ft_print_error();             /* abortamos */
        }
        while (tokens[j])                 /* recorremos cada token no NULL del array de tokens */
        {
            /* ft_split no debe producir tokens vacíos; aun así, se puede filtrar si se desea */
            if (tokens[j][0] != '\0')     /* ignoramos explícitamente posibles cadenas vacías por robustez */
            {
                array[k] = ft_atoi(tokens[j]);        /* convertimos el token a entero (asume validación en ft_atoi) */
                if (ft_is_duplicate(array, k, array[k])) /* comprobamos si el nuevo número duplica a alguno previo */
                {
                    free(array);                        /* liberamos el array para no filtrar memoria */
                    ft_free_tokens(tokens);             /* liberamos los tokens del argumento actual */
                    ft_print_error();                   /* abortamos si hay duplicado */
                }
                k++;                                    /* avanzamos el índice de escritura en el array final */
            }
            j++;                                        /* pasamos al siguiente token del mismo argumento */
        }
        ft_free_tokens(tokens);           /* liberamos el array de tokens del argumento actual */
        i++;                              /* pasamos al siguiente argumento argv */
    }
    *size = k;                            /* devolvemos por salida el número total de enteros parseados */
    return array;                         /* devolvemos el array completamente construido y validado */
}

/* ============================ FIN PARSING ============================ */

/* Procesamiento: rellenar pilas, indexar y ejecutar algoritmo */
static void ft_process(int *array, int size)
{
    t_stack *pila_a;
    t_stack *pila_b;
    int     *aux;

    pila_a = ft_pila_ini();
    pila_b = ft_pila_ini();
    if (!pila_a || !pila_b)
    {
        free(array);
        ft_print_error();
    }
    ft_fill_stack(pila_a, array, size);
    free(array);
    if (ft_pila_to_array(pila_a) == NULL)
    {
        ft_pilas_free(pila_a, pila_b);
        return ;
    }
    aux = ft_pila_to_array(pila_a);
    aux = ft_ordenar_array(aux, pila_a->cantidad_elementos);
    ft_index_ordenado(pila_a, aux);
    free(aux);
    if (!ft_algoritmos(size + 1, pila_a, pila_b))
        ft_chunks(pila_a, pila_b);
        //ft_radix(pila_a, pila_b);
    //ft_imprimir_pila(pila_a);
    //ft_imprimir_pila(pila_b);
    ft_pilas_free(pila_a, pila_b);
}

int main(int argc, char **argv)
{
    int *array;
    int size;

    if (argc < 2)
        return (0);
    array = ft_parse_mixed_args(argc, argv, &size);
    ft_process(array, size);
    return (0);
}
