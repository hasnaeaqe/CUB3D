/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haqajjef <haqajjef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 13:17:41 by cbayousf          #+#    #+#             */
/*   Updated: 2025/10/25 17:29:08 by haqajjef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	initialisation_mlx(t_data *data)
{
	data->mlx_ptr = mlx_init(data->screenwidth, data->screenheight,
			"cub3D", false);
	if (!data->mlx_ptr)
		exit(1);
	data->img = mlx_new_image(data->mlx_ptr, data->screenwidth,
			data->screenheight);
	if (!data->img)
	{
		mlx_terminate(data->mlx_ptr);
		exit(1);
	}
	if (mlx_image_to_window(data->mlx_ptr, data->img, 0, 0) == -1)
	{
		mlx_terminate(data->mlx_ptr);
		exit(1);
	}
}

void	close_win(void	*ptr)
{
	t_data	*data;

	data = (t_data *)ptr;
	mlx_terminate(data->mlx_ptr);
	ft_malloc(0, "FREE");
	exit(0);
}

int	key_release(t_data *data)
{
	if (mlx_is_key_down(data->mlx_ptr, MLX_KEY_W))
		data->keys.up = 0;
	if (mlx_is_key_down(data->mlx_ptr, MLX_KEY_S))
		data->keys.down = 0;
	if (mlx_is_key_down(data->mlx_ptr, MLX_KEY_A))
		data->keys.a = 0;
	if (mlx_is_key_down(data->mlx_ptr, MLX_KEY_D))
		data->keys.d = 0;
	if (mlx_is_key_down(data->mlx_ptr, MLX_KEY_LEFT))
		data->keys.left = 0;
	if (mlx_is_key_down(data->mlx_ptr, MLX_KEY_RIGHT))
		data->keys.right = 0;
	return (0);
}

int	key_press(t_data *data)
{
	if (mlx_is_key_down(data->mlx_ptr, MLX_KEY_ESCAPE))
		close_win(data);
	if (mlx_is_key_down(data->mlx_ptr, MLX_KEY_W))
		data->keys.up = 1;
	if (mlx_is_key_down(data->mlx_ptr, MLX_KEY_S))
		data->keys.down = 1;
	if (mlx_is_key_down(data->mlx_ptr, MLX_KEY_A))
		data->keys.a = 1;
	if (mlx_is_key_down(data->mlx_ptr, MLX_KEY_D))
		data->keys.d = 1;
	if (mlx_is_key_down(data->mlx_ptr, MLX_KEY_LEFT))
		data->keys.left = 1;
	if (mlx_is_key_down(data->mlx_ptr, MLX_KEY_RIGHT))
		data->keys.right = 1;
	return (0);
}
