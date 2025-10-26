/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haqajjef <haqajjef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 10:53:59 by haqajjef          #+#    #+#             */
/*   Updated: 2025/10/14 18:57:14 by haqajjef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*s;
	unsigned char	*l;

	if (!s1 || !s2)
		return (0);
	s = (unsigned char *)s1;
	l = (unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (s[i] == l[i] && i < n)
	{
		if (s[i] == '\0' || l[i] == '\0')
			return (0);
		i++;
	}
	if (i < n)
		return (s[i] - l[i]);
	return (0);
}

void	ft_putstr_fd(char *s, int fd)
{
	size_t	i;

	i = 0;
	if (!s || fd < 0)
		return ;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
	ft_malloc(0, "FREE");
}
