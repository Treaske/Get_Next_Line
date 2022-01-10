/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-blas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 18:32:58 by ade-blas          #+#    #+#             */
/*   Updated: 2022/01/10 17:07:17 by ade-blas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int length(char *str)
{
    int x;

    x = 0;
    if (!str)
        return (0);
    while (str[x] != 0)
        x++;
    return (x);
}

int check_jump(char *save)
{
    int x;

    x = 0;
    if (!save)
        return (0);
    while (save[x] != 0)
    {
        if (save[x] == '\n')
            return (x + 1);
        x++;
    }
    return (0);
}

char    *ft_join(char *save, char *str)
{
    int     x;
    int     y;
    char    *aux;

    x = 0;
    y = 0;
    x = (length(save) + length(str));
    aux = (char *) malloc(sizeof (char) * x + 1);
    if (!aux)
        return (0);
    aux[x] = 0;
    x = 0;
    while (save[x] != 0)
    {
        aux[x] = save[x];
        x++;
    }
    while (str[y] != 0)
    {
        aux[x] = str[y];
        x++;
        y++;
    }
    free(save);
    return (aux);
}
