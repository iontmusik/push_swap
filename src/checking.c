/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtorre-s <jtorre-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 12:07:27 by jtorre-s          #+#    #+#             */
/*   Updated: 2023/05/03 10:53:18 by jtorre-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/push_swap.h"


int duplicate_nums(char **split)
{
    int     i;
    int     j;
    char    *rep;

    i = 0;
    while (split[i])
    {
        rep = ft_strdup(split[i]);
        j = 0;
        while (split[j])
        {
            if (i == j)
                j++;
            else if (strcmp(rep, split[j]) == 0)
            {
                free(rep);
                exit_ps("dup");
            }
            else
                j++;
        }
        free(rep);
        i++;
    }
    return (0);
}

long long   atoi_ps(char *num_char)
{
    int                 i;
    int                 neg;
    unsigned long long  num;

    i = 0;
    neg = 1;
    num = 0;
    while (num_char[i] == '\n' || num_char[i] == '\t' || num_char[i] == '\v'
            || num_char[i] == '\r' || num_char[i] =='f' || num_char[i] == ' ')
            i++;
    if (num_char[i] == '-')
        neg = -1;
    if (num_char[i] == '-' || num_char[i] == '+')
        i++;
    while (num_char[i] >= '0' && num_char[i] <= '9')
    {
        num = 10 * num + num_char[i] - '0';
        i++;
    }
    num = num * neg;
    return (num);     
}

int    is_nums(char **av)
{
    int i;
    int j;

    i = 0;
    while (av[i])
    {
        j = 0;
        if (int_limits(av[i]) == 0)
            exit_ps("max-min");
        while (av[i][j])
        {
            if (ft_isalpha(av[i][j]) == 1 || av[i][j] == '.' || ((av[i][j]) == '-' 
                && (av[i][j + 1]) == '\0') || (av[i][j] == '+' && (av[i][j + 1]) == '\0'))
                    exit_ps("inv-arg");
            j++;
        }
    }
    return (1);
}

int    int_limits(char *av)
{
    long long num;

    num = atoi_ps(av);
    if (num >= INT_MIN && num <= INT_MAX && ft_strlen(av) < 12)
        return (1);
    return (0);
}
