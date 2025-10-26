/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haqajjef <haqajjef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 11:34:03 by haqajjef          #+#    #+#             */
/*   Updated: 2025/09/16 16:42:04 by haqajjef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

static int	check_overflow(long long prev, long long current, int *overflow)
{
	if (current / 10 != prev)
	{
		*overflow = 1;
		return (1);
	}
	return (0);
}

long	ft_atoi(char *str, int *overflow)
{
	int			i;
	long long	c;
	long long	prev;
	int			signe;

	i = 0;
	c = 0;
	signe = 1;
	while (str && (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13)))
		i++;
	if (str && (str[i] == '+'))
		i++;
	while (str && str[i] >= '0' && str[i] <= '9')
	{
		prev = c;
		c = c * 10 + (str[i] - '0');
		if (check_overflow(prev, c, overflow))
			return (-1);
		i++;
	}
	return (signe * c);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*ptr;
	unsigned char		*s;
	size_t				i;

	if (src == dst)
		return (dst);
	ptr = (unsigned char *)dst;
	s = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		ptr[i] = s[i];
		i++;
	}
	return (dst);
}
