/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmesum <mmesum@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 16:40:01 by mmesum            #+#    #+#             */
/*   Updated: 2022/10/31 13:26:43 by mmesum           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strchr(const char *str, int c)
{
	int		i;
	char	value;
	int		len;

	len = 0;
	if (str == NULL)
		return (0);
	while (*(str + len))
		len++;
	if (!str)
		return (0);
	value = c;
	i = 0;
	while (i <= len)
	{
		if (str[i] == value)
			return ((char *)&str[i]);
		i++;
	}
	return (0);
}

static int	findlen(const char *str)
{
	int	scount;

	scount = 0;
	if (str == NULL)
		return (0);
	while (*(str + scount))
		scount++;
	return (scount);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		index;

	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	i = 0;
	index = 0;
	str = malloc((findlen(s1) + findlen(s2) + 1) * sizeof(char));
	if (!str)
		return (0);
	while (s1[index] != '\0')
		str[i++] = s1[index++];
	index = 0;
	while (s2[index] != '\0')
		str[i++] = s2[index++];
	str[i] = '\0';
	free(s1);
	return (str);
}

char	*get_new_arr(char *arr)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (arr[i] && arr[i] != '\n')
		i++;
	if (!arr[i])
	{
		free(arr);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (findlen(arr) - i + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (arr[i])
		str[j++] = arr[i++];
	str[j] = '\0';
	free(arr);
	return (str);
}
