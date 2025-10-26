/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haqajjef <haqajjef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 14:19:21 by haqajjef          #+#    #+#             */
/*   Updated: 2025/10/25 20:34:23 by haqajjef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int	check_virgule(char *s)
{
	int	i;
	int	count;

	if (!s)
		return (-1);
	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == ',')
			count++;
		i++;
	}
	return (count);
}

uint32_t	shifting(char **s)
{
	int	colors[3];
	int	overflow;
	int	i;

	if (!s || !(*s))
		return (COLOR_ERROR);
	colors[0] = 0;
	colors[1] = 0;
	colors[2] = 0;
	overflow = 0;
	i = 0;
	while (i < 3)
	{
		if (!s[i])
			return (COLOR_ERROR);
		colors[i] = ft_atoi(s[i], &overflow);
		if (overflow || colors[i] < 0 || colors[i] > 255)
			return (COLOR_ERROR);
		i++;
	}
	return ((colors[0] << 24) | (colors[1] << 16) | (colors[2] << 8) | 255);
}

int	parse_first(t_parse *parse, int start)
{
	int		i;
	int		j;
	char	c;

	if (!parse || start == -1)
		return (ft_putstr_fd("Error: invalid map!\n", 2), 1);
	i = 0;
	while (i < start)
	{
		if (!is_texture(parse->map_cub[i]) && !is_empty_line(parse->map_cub[i]))
			return (ft_putstr_fd("Error: Invalid line before map!\n", 2), 1);
		i++;
	}
	j = 0;
	while (parse->map_cub[start][j])
	{
		c = parse->map_cub[start][j];
		if (c != '1' && c != ' ' && c != '\n')
		{
			ft_putstr_fd("Error: First map line must contain only(1)!\n", 2);
			return (1);
		}
		j++;
	}
	return (0);
}
