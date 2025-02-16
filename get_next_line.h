/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haaghaja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 13:47:35 by haaghaja          #+#    #+#             */
/*   Updated: 2025/02/16 15:51:21 by haaghaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

// get_next_line.c
char	*get_next_line(int fd);

// get_next_line_utils.c
char	*read_buffer(char *buffer, char *str, ssize_t *total, ssize_t i);
ssize_t	end_of_line(char *buffer, size_t bytes_read);
void	str_cp(char *src, char *dest);
void	str_join(char *str1, char *str2);
char	*exit_gnl(char *str);
#endif
