/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haaghaja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 13:47:22 by haaghaja          #+#    #+#             */
/*   Updated: 2025/02/17 12:15:17 by haaghaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdio.h>
int	ft_get_line(char **str, char *buffer)
{
	ssize_t	size;
	int		flag;

	flag = 0;
	size = 0;
	printf("GET_line str: %s\n", *str);
	if (buffer == NULL)
		return (0);
	while (buffer[size] && buffer[size] != '\n')
		size++;
	if (buffer[size] == '\n')
		size++;
	*str = new_str(*str, size);
	printf("GET_line str: %s\n", buffer);
	if (!(*str))
		return (0);
	flag = ft_strnjoin(*str, buffer);
	printf("GET_line str: %s\n", *str);
	return (flag);
}

int	ft_strnjoin(char *str1, char *str2)
{
	int	flag;

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
		str1++;
		flag = 1;
	}
	*str1 = '\0';
	return (flag);
}

char	*new_str(char *str, ssize_t bytes_read)
{
	ssize_t	len;
	char	*temp;

	len = 0;
	temp = str;
	if (str)
	{
		while (*str)
		{
			len++;
			str++;
		}
	}
	str = malloc((bytes_read + len + 1) * sizeof(char));
	if (!str)
		return (exit_gnl(temp, NULL));
	str[0] = 0;
	if (temp)
		ft_strnjoin(str, temp);
	free(temp);
	return (str);
}
#include <stdio.h>
char	*exit_gnl(char *str, char **buffer)
{
	free(str);
	//printf("HERE %p %p\n", buffer, *buffer);
	if (buffer != NULL)
		free(*buffer);
	*buffer = NULL;
	return (NULL);
}

void	shift_buffer(char *buffer)
{
	ssize_t	i;
	ssize_t	j;

	i = 0;
	j = 0;
	if (!buffer)
		return ;
	while (buffer[i] != '\0' && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
	{
		i++;
		while (buffer[i] != '\0')
			buffer[j++] = buffer[i++];
		buffer[j] = '\0';
	}
}
