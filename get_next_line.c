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

char    *take_line(char *save, int x)
{
    char    *line;
    int     y;

    y = 0;
    line = malloc(sizeof(char) * x + 1);
    if (!line)
        return (0);
    line[x] = 0;
    while (y < x)
    {
        line[y] = save[y];
        y++;
    }
    return (line);
}

char    *get_new_save(char *save, int x)
{
    char    *nsave;
    int     y;
    int     j;

    y = length(save);
    j = 0;
    nsave = malloc(sizeof(char) * (y - x) + 1);
    if (!nsave)
        return (0);
    nsave[y - x] = 0;
    while (x <= y)
    {
        nsave[j] = save[x];
        j++;
        x++;
    }
    free(save);
    return (nsave);
}

char    *get_no_jump(char *save)
{
    char    *str;
    int     x;

    if (save[0] == 0)
        return (0);
    x = 0;
    x = length(save);
    str = malloc(sizeof (char) * x + 1);
    if (!str)
        return (0);
    str[x] = 0;
    x = 0;
    while (save[x] != 0)
    {
        str[x] = save[x];
        x++;
    }
    return (str);
}

char    *comp_save(char *save)
{
    int     x;

    if (check_jump(save) != 0)
    {
        x = check_jump(save);
        save = get_new_save(save, x);
        return (save);
    }
    free(save);
    return (0);
}

char    *comp_str(char *save)
{
    int     x;
    char    *line;

    if (check_jump(save) != 0)
    {
        x = check_jump(save);
        line = take_line(save, x);
        return (line);
    }
    line = get_no_jump(save);
    return (line);
}

char    *get_next_line(int fd)
{
    static char *save;
    char        *str;
    char        *line;
    int         buf;

    if (BUFFER_SIZE <= 0)
        return (0);
    str = malloc(sizeof (char) * BUFFER_SIZE + 1);
    if (!save)
        save = malloc(sizeof (char) * BUFFER_SIZE + 1);
    if (!str || !save)
        return (0);
    while (check_jump(save) == 0)
    {
        buf = read(fd, str, BUFFER_SIZE);
        if (buf <= 0)
            break;
        str[buf] = 0;
        save = ft_join(save, str);
    }
    free(str);
    line = comp_str(save);
    save = comp_save(save);
    return (line);
}
/*
int main(void)
{
    int     fd;
    int     cont;
    char    *str;
    cont = 0;
    fd = open("21_no_line.txt", O_RDONLY);
    str = get_next_line(fd);
    while (str)
    {
        printf("%s\n", str);
        free(str);
        str = get_next_line(fd);
    }
    //printf("%s", str);
    free(str);
    close(fd);
    return (0);
}*/
