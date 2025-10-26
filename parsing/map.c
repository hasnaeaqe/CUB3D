/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haqajjef <haqajjef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 10:43:19 by haqajjef          #+#    #+#             */
/*   Updated: 2025/10/25 20:43:27 by haqajjef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

static char	*skip_spaces(char *s)
{
	int	i;

	i = 0;
	while (s[i] && (s[i] == ' ' || s[i] == '\t'))
		i++;
	return (&s[i]);
}

static int	to_compare(char *s, char *tok)
{
	char	*line;

	line = skip_spaces(s);
	if (ft_strncmp(line, tok, ft_strlen(tok)))
		return (1);
	return (0);
}

int	is_texture(char *s)
{
	if (!s)
		return (-1);
	if (to_compare(s, "NO") == 0)
		return (1);
	if (to_compare(s, "SO") == 0)
		return (1);
	if (to_compare(s, "WE") == 0)
		return (1);
	if (to_compare(s, "EA") == 0)
		return (1);
	if (to_compare(s, "F") == 0)
		return (1);
	if (to_compare(s, "C") == 0)
		return (1);
	return (0);
}

static int	is_map(char *s)
{
	int	i;

	if (!s)
		return (1);
	i = 0;
	while (s[i])
	{
		if (s[i] != '0' && s[i] != '1'
			&& s[i] != ' ' && s[i] != '\t'
			&& s[i] != 'N' && s[i] != 'S'
			&& s[i] != 'E' && s[i] != 'W' && s[i] != '\n')
			return (1);
		i++;
	}
	return (0);
}

int	find_start_map(char **map)
{
	int	i;

	if (!map)
		return (-1);
	i = 0;
	while (map[i])
	{
		if (!is_empty_line(map[i]) && is_map(map[i]) == 0)
			return (i);
		i++;
	}
	return (-1);
}
