/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavilov <eavilov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 10:29:43 by eavilov           #+#    #+#             */
/*   Updated: 2022/08/07 10:32:27 by eavilov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// to compile -> cc -D BUFFER_SIZE=10 *.c

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
		if (!str)
			break ;
		printf (" Ligne %d = %s", count, str);
		count++;
		free(str);
	}
	close (i);
	return (0);
}