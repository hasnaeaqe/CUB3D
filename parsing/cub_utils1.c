/* ************************************************************************** */
/*	                                                                       */
/*                                                        :::      ::::::::   */
/*   cub_utils1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haqajjef <haqajjef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 16:01:47 by haqajjef          #+#    #+#             */
/*   Updated: 2025/09/17 20:14:50 by haqajjef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int	check_extension(char *file)
{
	int	len;

	if (!file)
		return (1);
	len = ft_strlen(file);
	if (len >= 4 && file[len] == '\0' && file[len - 1] == 'b'
		&& file[len - 2] == 'u'
		&& file[len - 3] == 'c' && file[len - 4] == '.')
		return (0);
	return (1);
}

int	open_file(char *file)
{
	int	fd;

	if (check_extension(file) == 1)
		return (ft_putstr_fd("Error: Invalid Extension!\n", 2), -1);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (ft_putstr_fd("Error: file Doesn't exist\n", 2), -1);
	return (fd);
}

int	count_line(int fd)
{
	int		size;
	char	*line;

	size = 0;
	line = get_next_line(fd);
	if (!line)
		return (close(fd), size);
	while (line)
	{
		size++;
		line = get_next_line(fd);
	}
	close (fd);
	return (size);
}

char	**copy_map(int fd, char *file)
{
	int		i;
	char	*line;
	char	**map;

	i = count_line(fd);
	if (i == 0)
		return (ft_putstr_fd("Error: empty map!\n", 2), NULL);
	map = ft_malloc(sizeof (char *) * (i + 1), "MALLOC");
	fd = open_file(file);
	if (fd < 0)
		return (NULL);
	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		map[i++] = ft_strdup(line);
		line = get_next_line(fd);
	}
	map[i] = NULL;
	return (close(fd), map);
}

int	check_occurence(t_parse *parse, t_tocount *count_oc)
{
	int		i;
	char	*trim;

	i = 0;
	while (parse->map_cub && parse->map_cub[i])
	{
		trim = ft_strtrim(parse->map_cub[i], " ");
		if (!ft_strncmp(trim, "NO ", 3) || !ft_strncmp(trim, "NO", 2))
			count_oc->n_no++;
		if (!ft_strncmp(trim, "SO ", 3) || !ft_strncmp(trim, "SO", 2))
			count_oc->n_so++;
		if (!ft_strncmp(trim, "WE ", 3) || !ft_strncmp(trim, "WE", 2))
			count_oc->n_we++;
		if (!ft_strncmp(trim, "EA ", 3) || !ft_strncmp(trim, "EA", 2))
			count_oc->n_ea++;
		if (!ft_strncmp(trim, "F ", 2) || !ft_strncmp(trim, "F", 1))
			count_oc->n_f++;
		if (!ft_strncmp(trim, "C ", 2) || !ft_strncmp(trim, "C", 1))
			count_oc->n_c++;
		i++;
	}
	if (count_oc->n_c != 1 || count_oc->n_f != 1 || count_oc->n_ea != 1
		|| count_oc->n_we != 1 || count_oc->n_so != 1 || count_oc->n_no != 1)
		return (ft_putstr_fd("Error: invalid nb of texture or color\n", 2), 1);
	return (0);
}
