/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haqajjef <haqajjef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 12:34:37 by haqajjef          #+#    #+#             */
/*   Updated: 2025/10/25 20:40:11 by haqajjef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

static int	max_len(char **map, int start, int end)
{
	int	max;
	int	i;
	int	len;

	max = 0;
	i = start;
	while (i <= end)
	{
		if (!is_empty_line(map[i]))
		{
			len = ft_len(map[i]);
			if (len > max)
				max = len;
		}
		i++;
	}
	return (max);
}

static void	remplir_case(char **map, int max, int j)
{
	map[j] = ft_malloc(sizeof(char) * (max + 1), "MALLOC");
	ft_memset(map[j], ' ', max);
	map[j][max] = '\0';
}

char	**get_map(t_parse *parse, int i, int end)
{
	char	**map;
	int		j;
	int		k;
	int		max;

	k = end - i + 1;
	map = ft_malloc(sizeof(char *) * (k + 1), "MALLOC");
	max = max_len(parse->map_cub, i, end);
	j = 0;
	while (i <= end)
	{
		if (is_empty_line(parse->map_cub[i]))
			return (ft_putstr_fd("Error: empty line in map!\n", 2), NULL);
		remplir_case(map, max, j);
		k = -1;
		while (parse->map_cub[i][++k])
		{
			if (parse->map_cub[i][k] != ' ' && parse->map_cub[i][k] != '\n')
				map[j][k] = parse->map_cub[i][k];
		}
		j++;
		i++;
	}
	return (map[j] = NULL, map);
}

static int	is_validmap(char **map, int i, int j, int len)
{
	char	c;

	c = map[i][j];
	if (c != '1' && c != '0' && c != 'S' && c != 'N' && c != 'W' && c != 'E'
		&& c != ' ' && c != '\n')
		return (ft_putstr_fd("Error: Invalid character in map.\n", 2), 1);
	if ((i == 0 || map[i + 1] == NULL) && c != '1' && c != '\n' && c != ' ')
		return (ft_putstr_fd("Error: map is open (horizontale)!\n", 2), 1);
	if ((j == 0 || j == len - 1) && c != '1' && c != '\n' && c != ' ')
		return (ft_putstr_fd("Error: map is open (Verticale)!\n", 2), 1);
	if (c == '0' || c == 'N' || c == 'S' || c == 'E' || c == 'W')
	{
		if (i == 0 || map[i + 1] == NULL || j == 0 || j == len - 1)
			return (ft_putstr_fd("Error: open map at border!\n", 2), 1);
		if (map[i - 1][j] == ' ' || map[i + 1][j] == ' '
			|| map[i][j - 1] == ' ' || map[i][j + 1] == ' ')
			return (ft_putstr_fd("Error: open map is not allowed!\n", 2), 1);
	}
	return (0);
}

int	parse_map(t_parse *parse)
{
	int		i;
	int		j;
	int		count;
	int		len;

	1 && (i = -1, count = 0);
	len = parse->end_map - parse->start_map + 1;
	if (len == 0)
		return (ft_putstr_fd("Error: empty map!\n", 2), 1);
	while (parse->map && parse->map[++i])
	{
		len = ft_strlen(parse->map[i]);
		j = -1;
		while (parse->map[i][++j])
		{
			if (is_validmap(parse->map, i, j, len) == 1)
				return (1);
			if (parse->map[i][j] == 'N' || parse->map[i][j] == 'S'
				|| parse->map[i][j] == 'W' || parse->map[i][j] == 'E' )
				count++;
		}
	}
	if (count != 1)
		return (ft_putstr_fd("Error: num of players not valid\n", 2), 1);
	return (0);
}
