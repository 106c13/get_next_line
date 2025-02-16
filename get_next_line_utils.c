/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haaghaja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 13:47:22 by haaghaja          #+#    #+#             */
/*   Updated: 2025/02/16 16:24:24 by haaghaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int get_line(char **str, char *buffer, ssize_t *buffer_offset)
{
	ssize_t size;
	int flag;

	flag = 0;
	size = *buffer_offset;
	//printf("STR: %s\nBUFFER %s\n", *str, buffer);
	//printf("OFFSET %zd\n", *buffer_offset);
	while (buffer[size] && buffer[size] != '\n')
		size++;
	if(buffer[size] == '\n')
		size++;
	//printf("SIZE: %zd\n", size - *buffer_offset);
	*str = new_str(*str, size - *buffer_offset);
	if (!(*str))
		return (0);
	flag = ft_strnjoin(*str, &buffer[*buffer_offset]);
	*buffer_offset = size;
	return (flag);
}

int	ft_strnjoin(char *str1, char *str2)
{
	int flag;

	flag = 0;
	while (*str1)
		str1++;
	while (*str2 && *str2 != '\n')
	{
		*str1 = *str2;
		str1++;
		str2++;
	}
	if (*str2 == '\n')
	{
		*str1 = '\n';
		*str1++;
		flag = 1;
	}
	*str1 = '\0';
	return (flag);
}

char	*ft_calloc(ssize_t size)
{
	char	*str;

	str = malloc(size * sizeof(char));
	while (size > 0)
	{
		str[size - 1] = 0;
		size--;
	}
}

char	*new_str(char *str, ssize_t bytes_read)
{
	ssize_t len;
	char	*temp;

	len = 0;
	temp = str;
	while (*str)
	{
		len++;
		str++;
	}
	str = malloc((bytes_read + len + 1) * sizeof(char));
	if (!str)
		return (exit_gnl(temp));
	str[0] = 0;
	ft_strnjoin(str, temp);
	return (str);
}

char	*exit_gnl(char *str)
{
	free(str);
	return (NULL);
}
