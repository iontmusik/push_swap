/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtorre-s <jtorre-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 12:11:17 by jtorre-s          #+#    #+#             */
/*   Updated: 2023/05/03 10:53:22 by jtorre-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"


int exit_ps(char *text)
{
    if (strcmp(text, "dup") == 0)
        printf("%s\n", "Error\n Números duplicados.\n");
    else if (strcmp(text, "max-min") == 0)
        printf("%s\n", "Error\n No son numeros enteros.\n");
    else if (strcmp(text, "inv-arg") == 0)
        printf("%s\n", "Error\n Argumentos inválidos.\n");
    else if (strcmp(text, "need_arg") == 0)
        printf("%s\n", "Error\n Necesita más de 2 argumentos.\n");
    exit (1);
}