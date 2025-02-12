#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdlib.h>



// get_next_line.c
char	*get_next_line(int fd);
char	*str_malloc(size_t size);
void	str_join(char *str1, char *str2);
void	str_ncp(char *src, char *dest);


// get_next_line_utils.c
#define BUFFER_SIZE 4
int	get_line_lenght(int fd);
#endif
