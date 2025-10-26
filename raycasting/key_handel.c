/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbayousf <cbayousf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 10:25:36 by cbayousf          #+#    #+#             */
/*   Updated: 2025/10/25 16:47:01 by cbayousf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int	check_collision(t_data *data, double x, double y, double radius)
{
	int	left;
	int	right;
	int	top;
	int	bottom;

	left = x - radius / COF;
	right = x + radius / COF;
	top = y - radius / COF;
	bottom = y + radius / COF;
	if (left < 0 || right < 0 || top < 0 || bottom < 0)
		return (1);
	if (left >= data->map_width || right >= data->map_width
		|| top >= data->map_height || bottom >= data->map_height)
		return (1);
	if (fabs(x - data->player.posx) > 1 || fabs(y - data->player.posy) > 1)
		return (1);
	if (data->parse->map[top][left] == '1' ||
		data->parse->map[top][right] == '1' ||
		data->parse->map[bottom][left] == '1' ||
		data->parse->map[bottom][right] == '1')
	{
		return (1);
	}
	return (0);
}

void	key_up_down(t_data *data, double movespeed)
{
	double	px;
	double	py;

	if (mlx_is_key_down(data->mlx_ptr, MLX_KEY_W))
	{
		px = data->player.posx + data->player.dirx * movespeed;
		py = data->player.posy + data->player.diry * movespeed;
		if (!check_collision(data, px, py, 10))
		{
			data->player.posx = px;
			data->player.posy = py;
		}
	}
	if (mlx_is_key_down(data->mlx_ptr, MLX_KEY_S))
	{
		px = data->player.posx - data->player.dirx * movespeed;
		py = data->player.posy - data->player.diry * movespeed;
		if (!check_collision(data, px, py, 10))
		{
			data->player.posx = px;
			data->player.posy = py;
		}
	}
}

void	key_a_d(t_data *data, double moveSpeed)
{
	double	px;
	double	py;

	if (mlx_is_key_down(data->mlx_ptr, MLX_KEY_A))
	{
		px = data->player.posx + data->player.diry * moveSpeed;
		py = data->player.posy - data->player.dirx * moveSpeed;
		if (!check_collision(data, px, py, 10))
		{
			data->player.posx = px;
			data->player.posy = py;
		}
	}
	if (mlx_is_key_down(data->mlx_ptr, MLX_KEY_D))
	{
		px = data->player.posx - data->player.diry * moveSpeed;
		py = data->player.posy + data->player.dirx * moveSpeed;
		if (!check_collision(data, px, py, 10))
		{
			data->player.posx = px;
			data->player.posy = py;
		}
	}
}

void	key_left_right(t_data *data, double rS)
{
	double	dirx;
	double	planx;

	if (mlx_is_key_down(data->mlx_ptr, MLX_KEY_LEFT))
	{
		dirx = data->player.dirx;
		data->player.dirx = data->player.dirx * cos(-rS)
			- data->player.diry * sin(-rS);
		data->player.diry = dirx * sin(-rS) + data->player.diry * cos(-rS);
		planx = data->player.planex;
		data->player.planex = data->player.planex * cos(-rS)
			- data->player.planey * sin(-rS);
		data->player.planey = planx * sin(-rS) + data->player.planey * cos(-rS);
	}
	if (mlx_is_key_down(data->mlx_ptr, MLX_KEY_RIGHT))
	{
		dirx = data->player.dirx;
		data->player.dirx = data->player.dirx * cos(rS)
			- data->player.diry * sin(rS);
		data->player.diry = dirx * sin(rS) + data->player.diry * cos(rS);
		planx = data->player.planex;
		data->player.planex = data->player.planex * cos(rS)
			- data->player.planey * sin(rS);
		data->player.planey = planx * sin(rS) + data->player.planey * cos(rS);
	}
}

void	key_handler(void *ptr)
{
	t_data	*data;
	double	rotspeed;
	double	movespeed;

	movespeed = 0.1;
	rotspeed = 0.05;
	data = (t_data *)ptr;
	if (mlx_is_key_down(data->mlx_ptr, MLX_KEY_ESCAPE))
		close_win(data);
	key_up_down(data, movespeed);
	key_a_d(data, movespeed);
	key_left_right(data, rotspeed);
}
