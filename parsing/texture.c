/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbayousf <cbayousf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 15:41:42 by haqajjef          #+#    #+#             */
/*   Updated: 2025/10/26 10:43:10 by cbayousf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

static mlx_texture_t	*get_texture(t_variables *var, t_parse *parse)
{
	if (!var || !parse)
		return (NULL);
	if (var->side == 0)
	{
		if (var->raydirx > 0)
			return (parse->textures[EA].tex);
		else
			return (parse->textures[WE].tex);
	}
	else
	{
		if (var->raydiry > 0)
			return (parse->textures[SO].tex);
		else
			return (parse->textures[NO].tex);
	}
}

static uint32_t	get_col(mlx_texture_t *tex, int texx, int texy)
{
	size_t	index ;
	uint8_t	r;
	uint8_t	g;
	uint8_t	b;
	uint8_t	a;

	if (!tex || !tex->pixels)
		return (0);
	index = ((size_t)texy * tex->width + (size_t)texx) * 4;
	r = tex->pixels[index];
	g = tex->pixels[index + 1];
	b = tex->pixels[index + 2];
	a = tex->pixels[index + 3];
	return (((uint32_t)r << 24) | ((uint32_t)g << 16) | ((uint32_t)b << 8) | a);
}

static void	help_text(t_data *data, t_variables *var,
		t_parse *parse, mlx_texture_t *tex)
{
	if ((var->side == 0 && var->raydirx < 0)
		|| (var->side == 1 && var->raydiry > 0))
		parse->offset_x = tex->width - parse->offset_x - 1;
	if (parse->offset_x < 0)
		parse->offset_x = 0;
	if (parse->offset_x >= (int)tex->width)
		parse->offset_x = (int)tex->width - 1;
	parse->texPos = (var->drawstart - data->screenheight / 2
			+ var->lineheight / 2) * parse->step;
}

static void	draw_texture_column(t_data *data, t_variables *var, t_parse *parse,
		mlx_texture_t *tex)
{
	int	i;

	i = var->drawstart;
	while (i <= var->drawend)
	{
		parse->offset_y = (int)parse->texPos % tex->height;
		if (parse->offset_y < 0)
			parse->offset_y += tex->height;
		parse->color = get_col(tex, parse->offset_x, parse->offset_y);
		mlx_put_pixel(data->img, var->x, i, parse->color);
		parse->texPos += parse->step;
		i++;
	}
}

void	texture(t_data *data, t_variables *var, t_parse *parse)
{
	mlx_texture_t	*tex;
	double			wall_x;

	if (!data || !var || !parse || !data->img || var->lineheight <= 0)
		return ;
	tex = get_texture(var, parse);
	if (!tex)
		return ;
	puts("here");
	if (var->side == 0)
		wall_x = data->player.posy + var->perpwalldist * var->raydiry;
	else
		wall_x = data->player.posx + var->perpwalldist * var->raydirx;
	wall_x -= floor(wall_x);
	parse->offset_x = (int)(wall_x * tex->width);
	help_text(data, var, parse, tex);
	draw_texture_column(data, var, parse, tex);
}
