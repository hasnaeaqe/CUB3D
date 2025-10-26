/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haqajjef <haqajjef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 18:27:57 by haqajjef          #+#    #+#             */
/*   Updated: 2025/10/26 10:25:38 by haqajjef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

static int	stock_all(t_parse *parse, int fd, char *argv, t_tocount *count_occ)
{
	initialisation(count_occ, parse);
	parse->map_cub = copy_map(fd, argv);
	if (!parse->map_cub)
		return (close(fd), 1);
	if (check_occurence(parse, count_occ) == 1)
		return (close(fd), 1);
	stock_lignes(parse);
	if (parse_colors(parse) == 1)
		return (1);
	parse->start_map = find_start_map(parse->map_cub);
	if (parse->start_map == -1)
		return (ft_putstr_fd("Error: invalid map!\n", 2), 1);
	parse->end_map = find_end_map(parse->map_cub);
	if (parse->start_map == -1)
		return (ft_putstr_fd("Error: invalid end!\n", 2), 1);
	if (parse_first(parse, parse->start_map) == 1)
		return (1);
	parse->map = get_map(parse, parse->start_map, parse->end_map);
	if (!parse->map)
		return (1);
	if (parse_map(parse))
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_parse		parse;
	t_tocount	count_occ;
	int			fd;

	if (argc != 2)
	{
		ft_putstr_fd("Error: Invalid arguments. Expected: ./cub file.cub\n", 2);
		return (1);
	}
	fd = open_file(argv[1]);
	if (fd == -1)
		return (1);
	if (stock_all(&parse, fd, argv[1], &count_occ) == 1)
		return (1);
	start_raycasting(&parse);
	return (ft_malloc(0, "FREE"), 0);
}
