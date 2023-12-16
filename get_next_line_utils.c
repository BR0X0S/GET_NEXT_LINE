/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oumondad <oumondad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 15:40:01 by oumondad          #+#    #+#             */
/*   Updated: 2023/12/16 19:56:55 by oumondad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strchr(char *str, char c)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *stack, char *buffer)
{
	char	*str;
	size_t	j;
	size_t	i;
	size_t	len1;
	size_t	len2;

	len1 = ft_strlen(stack);
	len2 = ft_strlen(buffer);
	i = -1;
	str = malloc(len1 + len2 + 1);
	if (!str)
		return (NULL);
	if (!stack)
		stack = malloc(1);
	while (++i < len1)
		str[i] = stack[i];
	str[i] = '\0';
	j = -1;
	while (++j < len2)
		str[i + j] = buffer[j];
	str[i + j] = '\0';
	return (free(stack), free(buffer), str);
}

void ft_mossa3ada(char *stack, char *tmp, int i)
{
	size_t	j;
	
	j = -1;
	while (stack[i + (++j)])
		tmp[j] = stack[i + j];
	tmp[j] = '\0';
}

char	*ft_check(int i, char *buffer, char *stack)
{
	if (i == 0)
		return (free (buffer), stack);
	return (free (buffer), free (stack), NULL);
}
