#include "get_next_line.h"
#include <stdio.h>


// Joins str2 to str1 without \0
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
		*str1++;
	}
	*str1 = '\0';
}

// Copies string without \0
void	str_ncp(char *src, char *dest)
{
	while (*src)
	{
		*dest = *src;
		src++;
		dest++;
	}
}

char	*get_next_line(int fd)
{
	char	*str;
	char	*temp;
	char	buffer[BUFFER_SIZE];
	size_t bytes_read;
	size_t total;
	int i;

	total = 0;
	str = malloc(1);
	str[0] = '\0';
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE - 1);
		i = 0;
		while (i < bytes_read && buffer[i] != '\n')
			i++;
		buffer[i + 1] = '\0';
		temp = str;
		if (buffer[i] == '\n')
			str = malloc((total + i + 2) * sizeof(char));
		else
			str = malloc((total + i + 1) * sizeof(char));
		if (!str)
			return (NULL);
		str_ncp(temp, str);
		free(temp);
		str_join(str, buffer);
		total += i;
		printf("%d\n", total);
		if (str[total] == '\n')
			break;
	}
	return (str);
}