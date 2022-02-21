/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavilov <eavilov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 19:18:21 by eavilov           #+#    #+#             */
/*   Updated: 2022/02/16 15:53:45 by eavilov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>	
# include <string.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 0
# endif

typedef struct s_sc {
	char	*stat;
	char	content[BUFFER_SIZE + 1];
}				t_sc;

char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char const *src, unsigned int start, size_t len);
char	*ft_subjoin(char *s1, char *s2, int size);
char	*ft_strdiffjoin(char *str1, char *str2);
int		ft_strlen(const char *s);

#endif