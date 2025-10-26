/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haqajjef <haqajjef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 16:19:32 by haqajjef          #+#    #+#             */
/*   Updated: 2025/10/25 20:37:51 by haqajjef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	initialisation(t_tocount *occ, t_parse *parse)
{
	occ->n_c = 0;
	occ->n_f = 0;
	occ->n_no = 0;
	occ->n_so = 0;
	occ->n_we = 0;
	occ->n_ea = 0;
	parse->start_map = 0;
	parse->end_map = 0;
	parse->color_c = NULL;
	parse->color_f = NULL;
}

int	is_empty_line(char *s)
{
	int	i;

	i = 0;
	while (s && s[i])
	{
		if (s[i] != ' ' && s[i] != '\t' && s[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

size_t	ft_len(const char *s)
{
	size_t	i;
	size_t	count;

	count = 0;
	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] != '\n')
			count++;
		i++;
	}
	return (count);
}

int	find_end_map(char **map)
{
	int	i;
	int	start;

	if (!map || !(*map))
		return (-1);
	start = find_start_map(map);
	if (start < 0)
		return (-1);
	i = start;
	while (map[i])
		i++;
	i--;
	while (i >= start)
	{
		if (!is_empty_line(map[i]))
			return (i);
		i--;
	}
	return (-1);
}
