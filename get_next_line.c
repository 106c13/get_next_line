/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haaghaja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 13:46:37 by haaghaja          #+#    #+#             */
/*   Updated: 2025/02/16 16:24:22 by haaghaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	char			*str;
	static char		buffer[BUFFER_SIZE];
	static ssize_t	bytes_read;
	static ssize_t	bytes_offset;
	static ssize_t	total;


	




	bytes_offset = read_buffer(buffer, NULL, 0, bytes_read);
	//str = malloc(1);
	//*str = '\0';
	total = 0;
	bytes_read = 1;
	printf("R: %s\n", str);
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (exit_gnl(str));
		str = read_buffer(buffer, str, &total, bytes_read);
		if (!str)
			return (exit_gnl(str));
		if (str[total] == '\n')
			break ;
		if (!*str)
			return (exit_gnl(str));
	}
	return (str);
}
