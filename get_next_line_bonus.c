/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oumondad <oumondad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 15:02:11 by oumondad          #+#    #+#             */
/*   Updated: 2023/12/19 20:26:01 by oumondad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_get_new_line(char *stack, int fd)
{
	char	*buffer;
	int		byte_read;

	while (ft_strchr(stack, '\n') != 1)
	{
		buffer = malloc (BUFFER_SIZE + 1);
		if (!buffer)
			return (free(stack), NULL);
		byte_read = read (fd, buffer, BUFFER_SIZE);
		if (byte_read <= 0)
		{
			stack = ft_check(stack, buffer, byte_read);
			break ;
		}
		buffer[byte_read] = '\0';
		stack = ft_strjoin(stack, buffer);
		if (!stack)
			return (NULL);
	}
	return (stack);
}

char	*ft_get_line(char *stack)
{
	int		i;
	int		j;
	int		x;
	char	*line;

	x = 1;
	i = 0;
	j = 0;
	while (stack[i] != '\n' && stack[i] != '\0')
		i++;
	if (stack[i] == '\n')
		i++;
	line = malloc (i + x);
	if (!line)
		return (NULL);
	while (j < i)
	{
		line[j] = stack[j];
		j++;
	}
	line[j] = '\0';
	return (line);
}

char	*ft_get_after_line(char *stack)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	j = 0;
	if (!stack)
		return (NULL);
	while (stack[i] != '\0' && stack[i] != '\n')
		i++;
	if (stack[i] == '\0')
		return (free(stack), NULL);
	if (stack[i + 1] != '\0')
	{
		i++;
		while (stack[i + j] != '\0')
			j++;
		tmp = malloc (j + 1);
		if (!tmp)
			return (free(stack), NULL);
		ft_help(stack, tmp, i);
		return (free (stack), tmp);
	}
	return (free (stack), NULL);
}

char	*get_next_line(int fd)
{
	static char	*stack[OPEN_MAX];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE >= INT_MAX)
		return (NULL);
	stack[fd] = ft_get_new_line (stack[fd], fd);
	if (!stack[fd])
		return (free(stack[fd]), NULL);
	line = ft_get_line (stack[fd]);
	stack[fd] = ft_get_after_line (stack[fd]);
	return (line);
}
