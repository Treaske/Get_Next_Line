/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-blas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 17:04:14 by ade-blas          #+#    #+#             */
/*   Updated: 2021/11/26 17:22:47 by ade-blas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

int length(char *str)
{
    int x;

    x = 0;
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
    int     len;
    char    *aux;

    x = 0;
    y = 0;
    len = 0;
    if (save[0] != 0)
        len = length(save);
    len += length(str);
    aux = malloc(sizeof (char) * len + 1);
    if (!aux)
        return (0);
    while (x != length(save))
    {
        aux[x] = save[x];
        x++;
    }
    while (x != len)
    {
        aux[x] = str[y];
        x++;
        y++;
    }
    aux[x] = 0;
    return (aux);
}

char    *get_new_save(char *save)
{
    char    *nsave;
    int     x;
    int     y;

    x = 0;
    y = 0;
    while (save[x] != '\n')
        x++;
    x++;
    y = length(save) - x;
    nsave = malloc(sizeof (char) * y + 1);
    if (!nsave)
        return (0);
    y = 0;
    while (save[x] != 0)
    {
        nsave[y] = save[x];
        y++;
        x++;
    }
    nsave[y] = 0;
    return (nsave);
}

char    *take_line(char *save)
{
    char    *line;
    int     x;
    int     y;

    x = 0;
    y = 0;
    while (save[y] != '\n')
        y++;
    y++;
    line = malloc(sizeof (char) * y + 1);
    if (!line)
        return (0);
    while (x != y)
    {
        line[x] = save[x];
        x++;
    }
    line[x] = 0;
    return (line);
}

char    *get_next_line(int fd)
{
    static char *save;
    char        *str;
    int         buf;

    buf = 1;
    str = malloc(sizeof (char) * BUFFER_SIZE + 1);
    if (!save)
        save = malloc(sizeof (char) * BUFFER_SIZE + 1);
    while (check_jump(save) == 0 && buf > 0)
    {
        buf = read(fd, str, BUFFER_SIZE);
        str[buf] = 0;
        save = ft_join(save, str);
    }
    free(str);
    if (check_jump(save) != 0)
    {
        str = take_line(save);
        save = get_new_save(save);
        return (str);
    }
    return (0);
}
/*
int main(void)
{
    int     fd;
    int     cont;
    char    *str;

    cont = 0;
    fd = open("lines.txt", O_RDONLY);
    str = get_next_line(fd);
    while (str)
    {
        printf("%s", str);
        free(str);
        str = get_next_line(fd);
    }
    //printf("%s", str);
    free(str);
    close(fd);
    return (0);
}*/
