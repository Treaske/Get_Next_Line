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

int	length(char *str)
{
	int x;

	x = 0;
	while (str[x] != 0)
		x++;
	return (x);
}

int	check_jump(char *save)
{
	int x;

	x = 0;
	if (!save)
		return (0);
	while (save[x] != 0)
	{
		if (save[x] == '\n')
			return (x);
		x++;
	}
	return (0);
}

char	*ft_join(char *save, char *str)
{
	int 	x;
	int		y;
	int		len;
	char	*aux;

	x = 0;
	y = 0;
	len = 0;
	printf("save: %s\n", save);
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
	printf("aux: %s\n", aux);
	return (aux);
}

char	*get_new_save(char *save)
{
	char	*nsave;
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (save[x] != '\n')
		x++;
	nsave = malloc(sizeof (char) * y + 1);
	while (save[x] != 0)
	{
		nsave[y] = save[x];
		y++;
		x++;
	}
	nsave[y] = 0;
	return (nsave);
}

char	*take_line(char *save)
{
	char	*line;
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (save[y] != '\n')
		y++;
	y++;
	line = malloc(sizeof (char) * y + 1);
	while  (x != y)
	{
		line[x] = save[x];
		x++;
	}
	return (line);
}

char	*get_next_line2(int fd)
{
	static char	*save;
	char		*str;
	int			buf;
	int			i;

	buf = 1;
	i = 1;
	str = malloc(sizeof (char) * BUFFER_SIZE + 1);
	if (!save)
		save = malloc(sizeof (char) * BUFFER_SIZE + 1);
	while (check_jump(save) == 0 && buf > 0)
	{
		printf("bucle: %i\n", i);
		i++;
		buf = read(fd, str, BUFFER_SIZE);
		save = ft_join(save, str);
	}
	free(str);
	str = take_line(save);
	save = get_new_save(save);
	return (str);
}

int	main(void)
{
	int 	fd;
	int 	cont;
	char	*str;

	cont = 0;
	fd = open("lines.txt", O_RDONLY);
	str = get_next_line2(fd);
	/*while (str)
	{
		printf("%s", str);
		free(str);
		str = get_next_line2(fd);
	}*/
	printf("%s", strla);
	free(str);
	close(fd);
	return (0);
}
