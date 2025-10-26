/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haqajjef <haqajjef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 10:52:38 by cbayousf          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2025/10/26 11:09:19 by haqajjef         ###   ########.fr       */
=======
/*   Updated: 2025/10/26 10:33:04 by cbayousf         ###   ########.fr       */
>>>>>>> cdfe64d7e226904db2b233105a0a082c2c5a2a6d
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	draw_3d(t_data *data, double perpwalldist, t_variables *var)
{
	int	y;

	var->lineheight = (int)(data->screenheight / perpwalldist);
	var->drawstart = -var->lineheight / 2 + data->screenheight / 2;
	if (var->drawstart < 0)
		var->drawstart = 0;
	var->drawend = var->lineheight / 2 + data->screenheight / 2;
	if (var->drawend >= data->screenheight)
		var->drawend = data->screenheight - 1;
	y = 0;
	while (y < var->drawstart)
	{
		mlx_put_pixel(data->img, var->x, y, data->parse->ceiling_color);
		y++;
	}
	y = var->drawend;
	while (y < data->screenheight)
	{
		mlx_put_pixel(data->img, var->x, y, data->parse->floor_color);
		y++;
	}
}

void	init(t_variables *var, t_data *data, int x)
{
	var->camerax = 2 * x / (double)data->screenwidth - 1;
	var->raydirx = data->player.dirx + data->player.planex * var->camerax;
	var->raydiry = data->player.diry + data->player.planey * var->camerax;
	var->mapx = (int)data->player.posx;
	var->mapy = (int)data->player.posy;
	var->deltadistx = fabs(1.0 / var->raydirx);
	var->deltadisty = fabs(1.0 / var->raydiry);
	if (var->raydirx < 0)
	{
		var->stepx = -1;
		var->sidedistx = (data->player.posx - var->mapx) * var->deltadistx;
	}
	else
	{
		var->stepx = 1;
		var->sidedistx = (var->mapx + 1.0 - data->player.posx)
			* var->deltadistx;
	}
}

void	dda_algo(t_variables *var, t_data *data)
{
	var->hit = 0;
	var->side = 0;
	while (var->hit == 0)
	{
		if (var->sidedistx < var->sidedisty)
		{
			var->sidedistx += var->deltadistx;
			var->mapx += var->stepx;
			var->side = 0;
		}
		else
		{
			var->sidedisty += var->deltadisty;
			var->mapy += var->stepy;
			var->side = 1;
		}
		if (data->parse->map[var->mapy][var->mapx] == '1')
			var->hit = 1;
	}
	if (var->side == 0)
		var->perpwalldist = var->sidedistx - var->deltadistx;
	else
		var->perpwalldist = var->sidedisty - var->deltadisty;
}

void	clear_screen(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->screenheight)
	{
		x = 0;
		while (x < data->screenwidth)
		{
			mlx_put_pixel(data->img, x, y, 0x000000FF);
			x++;
		}
		y++;
	}
}

int	raycasting(t_data *data)
{
	t_variables	*var;

	var = ft_malloc(sizeof(t_variables), "MALLOC");
	var->x = 0;
	while (var->x < data->screenwidth)
	{
		init(var, data, var->x);
		if (var->raydiry < 0)
		{
			var->stepy = -1;
			var->sidedisty = (data->player.posy - var->mapy) * var->deltadisty;
		}
		else
		{
			var->stepy = 1;
			var->sidedisty = (var->mapy + 1.0 - data->player.posy)
				* var->deltadisty;
		}
		dda_algo(var, data);
		draw_3d(data, var->perpwalldist, var);
		texture(data, var, data->parse);
		var->x++;
	}
	return (0);
}
