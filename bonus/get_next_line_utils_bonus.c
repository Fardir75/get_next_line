/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavilov <eavilov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 18:15:00 by eavilov           #+#    #+#             */
/*   Updated: 2022/02/13 14:07:18 by eavilov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_substr(char const *src, unsigned int start, size_t len)
{
	size_t			h;
	size_t			o;
	char			*dest;

	o = 0;
	h = 0;
	if (ft_strlen(src) == 0)
		return (NULL);
	if (!src)
		return (NULL);
	while (src[o])
		o++;
	if (len > o)
		len = o;
	dest = malloc(sizeof (char) * (len + 1));
	if (!dest)
		return (NULL);
	while (h < len && start < o)
	{
		dest[h] = src[start + h];
		h++;
	}
	dest[h] = '\0';
	return (dest);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*result;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(s1) + ft_strlen(s2);
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	while (*s1)
		result[i++] = *s1++;
	while (*s2)
		result[i++] = *s2++;
	result[i] = '\0';
	return (result);
}

char	*ft_strdiffjoin(char *str1, char *str2)
{
	char	*result;

	if (!str1)
		return (result = ft_substr(str2, 0, ft_strlen(str2)));
	else if (!str2)
		return (result = ft_substr(str1, 0, ft_strlen(str1)));
	else
	{
		result = ft_strjoin(str1, str2);
		free(str1);
	}
	return (result);
}

char	*ft_subjoin(char *s1, char *s2, int size)
{
	char	*result;
	int		i;
	int		y;

	i = 0;
	y = 0;
	if (!s1)
		return (result = ft_substr(s2, 0, size + 1));
	else
		result = (char *)malloc(sizeof(char) * (ft_strlen(s1) + (size + 2)));
	while (s1[i])
		result[y++] = s1[i++];
	i = 0;
	while (s2[i] && i <= size)
		result[y++] = s2[i++];
	result[y] = '\0';
	free(s1);
	return (result);
}
