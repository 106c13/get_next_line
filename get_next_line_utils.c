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

void	str_join(char *str1, char *str2)
{
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
		*str1 = *str2;
		str1++;
	}
	*str1 = '\0';
}

ssize_t	end_of_line(char *buffer, size_t bytes_read)
{
	size_t	i;

	i = 0;
	while (i < bytes_read && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		buffer[i + 1] = '\0';
	else
		buffer[i] = '\0';
	return (i);
}

char	*read_buffer(char *buffer, char **str, ssize_t *total, ssize_t i)
{
	char	*temp;


	temp = str;
	i = end_of_line(buffer, i);
	if (buffer[i] == '\n')
		str = malloc((*total + i + 2) * sizeof(char));
	else
		str = malloc((*total + i + 1) * sizeof(char));
	if (!str)
		return (NULL);
	*total = *total + i;
	str_join(str, temp);
	str_join(str, buffer);
	free(temp);
	return (str);
}

char	*exit_gnl(char *str)
{
	free(str);
	return (NULL);
}
