/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_tex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haqajjef <haqajjef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 17:32:17 by haqajjef          #+#    #+#             */
/*   Updated: 2025/10/18 17:36:02 by haqajjef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	destroy_textures(t_parse *parse)
{
	if (parse->textures[NO].tex)
	{
		mlx_delete_texture(parse->textures[NO].tex);
		parse->textures[NO].tex = NULL;
	}
	if (parse->textures[SO].tex)
	{
		mlx_delete_texture(parse->textures[SO].tex);
		parse->textures[SO].tex = NULL;
	}
	if (parse->textures[WE].tex)
	{
		mlx_delete_texture(parse->textures[WE].tex);
		parse->textures[WE].tex = NULL;
	}
	if (parse->textures[EA].tex)
	{
		mlx_delete_texture(parse->textures[EA].tex);
		parse->textures[EA].tex = NULL;
	}
}

void	close_game(void *ptr)
{
	t_data	*data;

	data = (t_data *)ptr;
	if (data && data->parse)
		destroy_textures(data->parse);
	if (data && data->img && data->mlx_ptr)
		mlx_delete_image(data->mlx_ptr, data->img);
	if (data && data->mlx_ptr)
		mlx_terminate(data->mlx_ptr);
	exit(0);
}

int	load_texture(t_parse *parse)
{
	if (!parse)
		return (1);
	parse->textures[NO].tex = mlx_load_png(parse->textures[NO].path);
	if (!parse->textures[NO].tex)
		return (ft_putstr_fd("Error: Invalid NO texture\n", 2), 1);
	parse->textures[SO].tex = mlx_load_png(parse->textures[SO].path);
	if (!parse->textures[SO].tex)
	{
		destroy_textures(parse);
		return (ft_putstr_fd("Error: Invalid SO texture\n", 2), 1);
	}
	parse->textures[WE].tex = mlx_load_png(parse->textures[WE].path);
	if (!parse->textures[WE].tex)
	{
		destroy_textures(parse);
		return (ft_putstr_fd("Error: Invalid WE texture\n", 2), 1);
	}
	parse->textures[EA].tex = mlx_load_png(parse->textures[EA].path);
	if (!parse->textures[EA].tex)
	{
		destroy_textures(parse);
		return (ft_putstr_fd("Error: Invalid EA texture\n", 2), 1);
	}
	return (0);
}
