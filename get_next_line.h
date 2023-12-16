/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oumondad <oumondad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 15:40:12 by oumondad          #+#    #+#             */
/*   Updated: 2023/12/16 20:42:27 by oumondad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 101010100
# endif

# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

int		ft_strchr(char *str, char c);
char	*ft_strjoin(char *stack, char *buffer);
size_t	ft_strlen(char *str);
char	*ft_check(int i, char *buffer, char *stack);
char	*get_next_line(int fd);
char	*after_new_line(char *stack);
char	*ft_get_line(char *stack);
char	*get_new_line(char *stack, int fd);
void	ft_mossa3ada(char *stack, char *tmp, int i);

#endif