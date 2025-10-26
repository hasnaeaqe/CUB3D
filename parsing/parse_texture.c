/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haqajjef <haqajjef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 11:50:12 by haqajjef          #+#    #+#             */
/*   Updated: 2025/10/25 20:39:06 by haqajjef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int	parse_texture(char *line, t_parse *parse, int id)
{
	char	*trimmed;

	if (!line)
		return (1);
	trimmed = ft_strtrim(line + 2, " \t\n");
	if (trimmed && trimmed[0] == '.' && trimmed[1] == '/')
		trimmed = ft_strtrim(trimmed, "./");
	if (trimmed && is_empty_line(trimmed))
		return (1);
	if (id == NO)
		parse->textures[NO].path = ft_strdup(trimmed);
	else if (id == SO)
		parse->textures[SO].path = ft_strdup(trimmed);
	else if (id == WE)
		parse->textures[WE].path = ft_strdup(trimmed);
	else if (id == EA)
	{
		parse->textures[EA].path = ft_strdup(trimmed);
	}
	return (0);
}

void	stock_lignes(t_parse *parse)
{
	int		i;
	char	*line;

	i = -1;
	while (parse->map_cub && parse->map_cub[++i])
	{
		line = ft_strtrim(parse->map_cub[i], " ");
		if (is_empty_line(line))
			continue ;
		if (ft_strncmp(line, "NO ", 3) == 0)
			parse_texture(line, parse, NO);
		else if (ft_strncmp(line, "SO ", 3) == 0)
			parse_texture(line, parse, SO);
		else if (ft_strncmp(line, "WE ", 3) == 0)
			parse_texture(line, parse, WE);
		else if (ft_strncmp(line, "EA ", 3) == 0)
			parse_texture(line, parse, EA);
		else if (ft_strncmp(line, "F ", 2) == 0)
			parse->color_f = ft_strdup(line);
		else if (ft_strncmp(line, "C ", 2) == 0)
			parse->color_c = ft_strdup(line);
	}
}
