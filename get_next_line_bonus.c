/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmesum <mmesum@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 16:39:57 by mmesum            #+#    #+#             */
/*   Updated: 2022/10/31 13:11:42 by mmesum           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static char	*read_line(int fd, char *arr)
{
	char	*buff;
	int		read_bytes;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	read_bytes = 1;
	while (!ft_strchr(arr, '\n') && read_bytes != 0)
	{
		read_bytes = read(fd, buff, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[read_bytes] = '\0';
		arr = ft_strjoin(arr, buff);
	}
	free(buff);
	return (arr);
}

static char	*get_new_line(char *arr)
{
	int		i;
	char	*str;

	i = 0;
	if (!arr[i])
		return (NULL);
	while (arr[i] && arr[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (arr[i] && arr[i] != '\n')
	{
		str[i] = arr[i];
		i++;
	}
	if (arr[i] == '\n')
	{
		str[i] = arr[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*arr[2048];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	arr[fd] = read_line(fd, arr[fd]);
	if (!arr[fd])
		return (NULL);
	line = get_new_line(arr[fd]);
	arr[fd] = get_new_arr(arr[fd]);
	return (line);
}
