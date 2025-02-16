/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haaghaja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 13:46:37 by haaghaja          #+#    #+#             */
/*   Updated: 2025/02/17 12:11:58 by haaghaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	char		*str;
	ssize_t		bytes_read;
	static char	*buffer[4864];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = NULL;
	printf("BUFF: %p %d\n%s\n", buffer[fd], fd, buffer[fd]);
	if (buffer[fd] == NULL)
		buffer[fd] = malloc((BUFFER_SIZE + 1) * sizeof(char));
	printf("BUFF: %p %d\n%s\n", buffer[fd], fd, buffer[fd]);
	if (!buffer[fd])
		return (NULL);
	while (!ft_get_line(&str, buffer[fd]))
	{
		bytes_read = read(fd, buffer[fd], BUFFER_SIZE);
		printf("-- BR: %zd\nBUFSTR:%s\nSTR: %s\n", bytes_read, buffer[fd], str);
		if (bytes_read == -1)
			return (exit_gnl(str, &buffer[fd]));
		buffer[fd][bytes_read] = '\0';
		if (bytes_read == 0)
			break ;
	}
	if (*str == '\0')
		return (exit_gnl(str, &buffer[fd]));
	//shift_buffer(buffer[fd]);
	return (str);
}
