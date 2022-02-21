/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavilov <eavilov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 11:03:34 by eavilov           #+#    #+#             */
/*   Updated: 2022/02/17 17:07:17 by eavilov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_charfinder(char *str, char character)
{
	int	i;

	i = 0;
	if (ft_strlen(str) == 0)
		return (-1);
	while (str[i])
	{
		if (str[i] == character)
			return (i);
		else
			i++;
	}
	return (-1);
}

char	*ft_parser(int fd, char *content, int end, char *mix)
{
	char	*line;
	int		i;

	i = 0;
	line = NULL;
	if (mix)
		line = ft_strdiffjoin(line, mix);
	free(mix);
	while (i <= BUFFER_SIZE)
	{
		if (i == BUFFER_SIZE)
		{
			line = ft_strdiffjoin(line, content);
			end = read(fd, content, BUFFER_SIZE);
			content[end] = '\0';
			i = -1;
		}
		if (content[i] == '\n' || end == 0)
			return (line = ft_subjoin(line, content, i));
		i++;
	}
	return (NULL);
}

char	*ft_statcheck(char **stat)
{
	char	*line;
	char	*sub;
	int		i;

	i = 0;
	line = NULL;
	if (ft_strlen(*stat) > 0)
	{
		sub = *stat;
		while (sub[i])
		{
			if (sub[i] == '\n')
			{
				line = ft_substr(sub, 0, i + 1);
				*stat = ft_substr(&sub[i + 1], 0, ft_strlen(&sub[i]));
				free(sub);
				return (line);
			}
			i++;
		}
		line = ft_strdiffjoin(line, sub);
		*stat = NULL;
		free(sub);
	}
	return (line);
}

char	*ft_ending(char *content, char *line, char **stat, int end)
{
	int	i;

	i = 0;
	if (end <= 0)
		return (line);
	content[end] = '\0';
	while (i <= BUFFER_SIZE)
	{
		if (content[i] == '\n')
		{
			line = ft_subjoin(line, content, i);
			*stat = ft_substr(&content[i + 1], 0, ft_strlen(&content[i + 1]));
			return (line);
		}
		i++;
	}
	line = ft_strdiffjoin(line, content);
	return (line);
}

char	*get_next_line(int fd)
{
	static t_sc	sc;
	char		*line;
	int			end;

	line = ft_statcheck(&sc.stat);
	if (ft_charfinder(line, '\n') >= 0)
		return (line);
	end = read(fd, sc.content, BUFFER_SIZE);
	if (end < BUFFER_SIZE)
		return (line = ft_ending(sc.content, line, &sc.stat, end));
	sc.content[end] = '\0';
	line = ft_parser(fd, sc.content, end, line);
	sc.stat = ft_substr(&sc.content[ft_charfinder(sc.content, '\n')] + 1,
			0, ft_strlen(&sc.content[ft_charfinder(sc.content, '\n')] + 1));
	return (line);
}

int	main(int ac, char **av)
{
	int		i;
	int		count;
	char	*str;

	count = 1;
	i = open (av[1], O_RDONLY);
	(void) ac;
	str = (char *)1;
	while (str)
	{
		str = get_next_line(i);
		printf (" L%d = %s", count, str);
		count++;
		free(str);
	}
	close (i);
	return (0);
}