/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haqajjef <haqajjef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 16:24:12 by haqajjef          #+#    #+#             */
/*   Updated: 2025/10/14 18:57:31 by haqajjef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

static void	ft_free1(char **t, size_t j)
{
	size_t	i;

	i = 0;
	while (i < j)
	{
		free(t[i]);
		i++;
	}
	free(t);
}

int	ft_count(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
		{
			i++;
		}
		if (s[i] != '\0')
		{
			count++;
			while (s[i] != c && s[i])
				i++;
		}
	}
	return (count);
}

static char	*ft_ndup(const char *s1, int n)
{
	char	*str;
	int		i;

	i = 0;
	str = ft_malloc((n + 1) * sizeof(char), "MALLOC");
	if (str == NULL)
		return (NULL);
	while (i < n)
	{
		str[i] = s1[i];
		i++;
	}
	str[n] = '\0';
	return (str);
}

static char	**cr_word(char const *s, char c, char **result)
{
	int	i;
	int	d;
	int	k;

	i = 0;
	k = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] == '\0')
			break ;
		d = i;
		while (s[i] != c && s[i] != '\0')
			i++;
		result[k] = ft_ndup(s + d, i - d);
		if (result[k] == NULL)
		{
			ft_free1(result, k);
			return (NULL);
		}
		k++;
	}
	result[k] = NULL;
	return (result);
}

char	**ft_split(char const *s, char c)
{
	char	**result;

	if (s == NULL)
		return (NULL);
	result = ft_malloc((ft_count(s, c) + 1) * sizeof(char *), "MALLOC");
	if (result == NULL)
		return (NULL);
	result = cr_word(s, c, result);
	return (result);
}
