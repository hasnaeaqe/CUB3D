/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haqajjef <haqajjef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 11:14:07 by cbayousf          #+#    #+#             */
/*   Updated: 2025/10/26 10:00:43 by haqajjef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	initialise_derection(t_player *player, char p)
{
	if (p == 'N')
	{
		player->dirx = 0;
		player->diry = -1;
	}
	else if (p == 'S')
	{
		player->dirx = 0;
		player->diry = 1;
	}
	else if (p == 'E')
	{
		player->dirx = 1;
		player->diry = 0;
	}
	else
	{
		player->dirx = -1;
		player->diry = 0;
	}
	player->planex = -player->diry * 0.66;
	player->planey = player->dirx * 0.66;
}

void	find_position(t_player *player, t_parse *parse)
{
	int	i;
	int	j;

	i = 0;
	while (parse->map[i])
	{
		j = 0;
		while (parse->map[i][j])
		{
			if (parse->map[i][j] == 'N' || parse->map[i][j] == 'S' ||
				parse->map[i][j] == 'E' || parse->map[i][j] == 'W')
			{
				player->posx = j + 0.5;
				player->posy = i + 0.5;
				initialise_derection(player, parse->map[i][j]);
				return ;
			}
			j++;
		}
		i++;
	}
}

int	ft_strlen_wh(t_parse *parse, int k)
{
	int	i;

	i = 0;
	if (k == 1)
	{
		while (parse->map[i])
			i++;
		return (i);
	}
	else
	{
		while (parse->map[0][i])
			i++;
		return (i);
	}
}

void	tracer(void *ptr)
{
	t_data	*data;

	data = (t_data *)ptr;
	raycasting(data);
}

void	start_raycasting(t_parse *parse)
{
	t_data	*data;

	data = ft_malloc(sizeof(t_data), "MALLOC");
	data->parse = parse;
	find_position(&data->player, data->parse);
	data->map_width = ft_strlen_wh(parse, 0);
	data->map_height = ft_strlen_wh(parse, 1);
	data->screenwidth = 1920;
	data->screenheight = 1080;
	if (load_texture(parse))
		exit(1);
	initialisation_mlx(data);
	mlx_loop_hook(data->mlx_ptr, tracer, data);
	mlx_loop_hook(data->mlx_ptr, key_handler, data);
	mlx_close_hook(data->mlx_ptr, close_win, data);
	mlx_loop(data->mlx_ptr);
}
