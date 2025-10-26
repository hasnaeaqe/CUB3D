/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haqajjef <haqajjef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 12:11:00 by haqajjef          #+#    #+#             */
/*   Updated: 2025/10/26 10:28:21 by haqajjef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

static int	check_empty(char *s)
{
	int	i;

	i = 0;
	while (s[i] && (s[i] == ' ' || s[i] == '\t'))
		i++;
	if (s[i] == '\0')
		return (1);
	return (0);
}

static int	is_valid_col(char *s)
{
	int		i;

	if (check_empty(s))
		return (1);
	i = 0;
	if (s[i] && s[i] == '+')
		i++;
	if (!s[i])
		return (1);
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			return (1);
		i++;
	}
	return (0);
}

static int	valid_range(long nb)
{
	if (nb >= 0 && nb <= 255)
		return (0);
	return (1);
}

static int	check_color(char **color)
{
	int		i;
	char	*trim;
	int		overflow;

	if (!color || !(*color))
		return (1);
	overflow = 0;
	i = 0;
	while (color[i])
		i++;
	if (i != 3)
		return (ft_putstr_fd("Error: A color must have 3 values.\n", 2), 1);
	i = 0;
	while (i < 3)
	{
		trim = ft_strtrim(color[i], " \n");
		if (is_valid_col(trim))
			return (ft_putstr_fd("Error:value not valid.\n", 2), 1);
		if (valid_range(ft_atoi(trim, &overflow)) || overflow == 1)
			return (ft_putstr_fd("Error: range not valid.\n", 2), 1);
		i++;
	}
	return (0);
}

int	parse_colors(t_parse *parse)
{
	char	**f;
	char	**c;

	if (!parse->color_c || !parse->color_f)
		return (ft_putstr_fd("Error: Invalid color!\n", 2), 1);
	if (check_virgule(parse->color_c) != 2
		|| check_virgule(parse->color_f) != 2)
	{
		ft_putstr_fd("Error: Invalid color format\n", 2);
		return (1);
	}
	f = ft_split(parse->color_f + 1, ',');
	c = ft_split(parse->color_c + 1, ',');
	if (check_color(c) || check_color(f))
		return (1);
	parse->ceiling_color = shifting(c);
	parse->floor_color = shifting(f);
	return (0);
}
