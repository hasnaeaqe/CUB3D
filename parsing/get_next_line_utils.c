/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haqajjef <haqajjef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 15:22:27 by haqajjef          #+#    #+#             */
/*   Updated: 2025/10/14 18:58:03 by haqajjef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

char	*ft_strdup(const char *s1)
{
	size_t	lens1;
	size_t	i;
	char	*tab;

	lens1 = ft_strlen(s1);
	tab = ft_malloc ((lens1 + 1) * sizeof(char), "MALLOC");
	if (tab == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		tab[i] = s1[i];
		i++;
	}
	tab[i] = '\0';
	return (tab);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if ((char)c == '\0')
		return ((char *)&s[i]);
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*newstr;
	char	*head;
	int		l1;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	l1 = ft_strlen(s1);
	newstr = ft_malloc(l1 + ft_strlen(s2) +1 * sizeof(char), "MALLOC");
	if (!newstr)
		return (NULL);
	head = newstr;
	while (*s1)
		*newstr++ = *s1++;
	while (*s2)
		*newstr++ = *s2++;
	*newstr = '\0';
	return (head);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t		i;
	char		*news;
	size_t		len_s;

	if (!s)
		return (NULL);
	len_s = ft_strlen(s);
	if (start >= len_s)
		return (ft_strdup(""));
	if (len > len_s - start)
		len = len_s - start;
	news = ft_malloc ((len + 1) * sizeof(char), "MALLOC");
	if (news == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		news[i] = s[start + i];
		i++;
	}
	news[i] = '\0';
	return (news);
}
