/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oumondad <oumondad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 15:02:32 by oumondad          #+#    #+#             */
/*   Updated: 2023/12/19 20:13:50 by oumondad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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

int	ft_strchr(char *stack, char c)
{
	int	i;

	i = 0;
	if (!stack)
		return (0);
	while (stack[i])
	{
		if (stack[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *stack, char *buffer)
{
	size_t	i;
	size_t	j;
	size_t	sl;
	size_t	bl;
	char	*str;

	sl = ft_strlen(stack);
	bl = ft_strlen(buffer);
	str = malloc (sl + bl + 1);
	if (!str)
		return (free(stack), free(buffer), NULL);
	if (!stack)
		stack = malloc (1);
	if (!stack)
		return (free(str), free(buffer), NULL);
	i = -1;
	while (++i < sl)
		str[i] = stack[i];
	str[i] = '\0';
	j = -1;
	while (++j < bl)
		str[i + j] = buffer[j];
	str[i + j] = '\0';
	return (free(buffer), free(stack), str);
}

void	ft_help(char *stack, char *tmp, int i)
{
	size_t	j;

	j = 0;
	while (stack[i + j])
	{
		tmp[j] = stack[i + j];
		j++;
	}
	tmp[j] = '\0';
}

char	*ft_check(char *stack, char *buffer, int byte_read)
{
	if (byte_read == 0)
	{
		free(buffer);
		return (stack);
	}
	free (buffer);
	free (stack);
	return (NULL);
}
