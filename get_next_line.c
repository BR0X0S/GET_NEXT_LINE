/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oumondad <oumondad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 15:39:49 by oumondad          #+#    #+#             */
/*   Updated: 2023/12/16 20:41:47 by oumondad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_new_line(char *stack, int fd)
{
	int		i;
	char	*buffer;

	while (ft_strchr(stack, '\n') != 1)
	{
		buffer = malloc ((size_t)BUFFER_SIZE + 1);
		if (!buffer)
			return (free(stack), NULL);
		i = read (fd, buffer, BUFFER_SIZE);
		if (i <= 0)
		{
			stack = ft_check(i, buffer, stack);
			break ;
		}
		buffer[i] = '\0';
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
	char	*line;

	i = 0;
	j = 0;
	while (stack[i] != '\n' && stack[i] != '\0')
		i++;
	line = malloc (i + 2);
	if (!line)
		return (NULL);
	while (j <= i)
	{
		line[j] = stack[j];
		j++;
	}
	line[j] = '\0';
	return (line);
}

char	*after_new_line(char *stack)
{
	size_t	i;
	size_t	j;
	char	*tmp;

	i = 0;
	j = 0;
	if (!stack)
		return (NULL);
	while (stack[i] != '\n' && stack[i] != '\0')
		i++;
	if (stack[i] == '\0')
		return (free (stack), (NULL));
	if (stack[i + 1] != '\0')
	{
		i++;
		while (stack[i + j])
			j++;
		tmp = malloc(j + 1);
		if (!tmp)
			return (free(stack), (NULL));
		j = -1;
		ft_mossa3ada(stack, tmp, i);
		return (free(stack), tmp);
	}
	return (free(stack), (NULL));
}

char	*get_next_line(int fd)
{
	static char	*stack;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stack = get_new_line(stack, fd);
	if (!stack)
		return (free(stack), NULL);
	line = ft_get_line(stack);
	stack = after_new_line(stack);
	return (line);
}
