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
int 	get_line(char **str, char *buffer, ssize_t *buffer_offset);
int		ft_strnjoin(char *str1, char *str2);
char	*new_str(char *str, ssize_t bytes_read);
char	*ft_calloc(ssize_t size);
char	*exit_gnl(char *str);
#endif
