/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haqajjef <haqajjef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 10:42:26 by haqajjef          #+#    #+#             */
/*   Updated: 2025/10/14 18:57:07 by haqajjef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*ptr;
	size_t			i;
	unsigned char	d;

	d = (unsigned char) c;
	ptr = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		ptr[i] = d;
		i++;
	}
	return (b);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	lensrc;
	size_t	j;

	lensrc = ft_strlen(src);
	if (dstsize == 0)
		return (lensrc);
	j = 0;
	while (j < dstsize - 1 && j < lensrc)
	{
		dst[j] = src[j];
		j++;
	}
	dst[j] = '\0';
	return (lensrc);
}

static int	check(const char *set, char c)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	i;
	size_t	j;

	if (s1 == NULL)
		return (NULL);
	if (set == NULL)
		return (ft_strdup(s1));
	i = 0;
	j = ft_strlen(s1);
	while (s1[i] && check(set, s1[i]))
		i++;
	while (j > i && check(set, s1[j - 1]))
		j--;
	str = ft_malloc((j - i + 1) * sizeof(char), "MALLOC");
	if (str == NULL)
		return (NULL);
	ft_strlcpy(str, &s1[i], j - i + 1);
	return (str);
}
