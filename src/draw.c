/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 13:24:05 by momrane           #+#    #+#             */
/*   Updated: 2024/01/17 13:14:45 by momrane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

static void	my_pixel_put(t_img *img, int x, int y, int color)
{
	int				offset;
	unsigned int	*px;

	offset = (img->line_len * y) + (x * (img->bits_per_pixel / 8));
	px = (unsigned int *)(img->img_pixels_ptr + offset);
	*px = color;
}

static void	ft_prep_img(t_env *env)
{
	env->img.bits_per_pixel = 32;
	env->img.endian = 0;
	env->img.line_len = env->width * 4;
	if (env->img.img_ptr != NULL)
		mlx_destroy_image(env->mlx_ptr, env->img.img_ptr);
	env->img.img_ptr = mlx_new_image(env->mlx_ptr, env->width, env->height);
	if (!env->img.img_ptr)
		ft_exit_error("Error: mlx_new_image failed");
	env->img.img_pixels_ptr = mlx_get_data_addr(env->img.img_ptr,
			&env->img.bits_per_pixel, &env->img.line_len, &env->img.endian);
	if (!env->img.img_pixels_ptr)
		ft_exit_error("Error: mlx_get_data_addr failed");
}

// static void ft_draw_rectangle(t_env *env, int x, int y, int size, int color)
// {
// 	int i;
// 	int j;

// 	i = 0;
// 	while (i < size)
// 	{
// 		j = 0;
// 		while (j < size)
// 		{
// 			my_pixel_put(&env->img, (x - size / 2) + i, (y - size / 2) + j, color);
// 			j++;
// 		}
// 		i++;
// 	}
// }

static int	ft_get_new_x(t_env *env, int i, int j)
{
	int	new_x;
	int	x;
	int	y;
	int	z;

	(void)x;
	(void)y;
	(void)z;
	x = env->data.matrix[i][j].x;
	y = env->data.matrix[i][j].y;
	z = env->data.matrix[i][j].z;
	new_x = ((x + 1) * env->scale) + (env->origin.x) - env->scale;
	new_x -= (env->data.col / 2) * env->scale;
	return (new_x);
}

static int	ft_get_new_y(t_env *env, int i, int j)
{
	int	new_y;
	int	x;
	int	y;
	int	z;

	(void)x;
	(void)y;
	(void)z;
	x = env->data.matrix[i][j].x;
	y = env->data.matrix[i][j].y;
	z = env->data.matrix[i][j].z;
	new_y = ((y + 1) * env->scale) + (env->origin.y) - env->scale;
	new_y -= (env->data.row / 2) * env->scale;
	return (new_y);
}

int	ft_draw(t_env *env)
{
	int	i;
	int	j;
	int x;
	int y;

	i = 0;
	ft_prep_img(env);
	while (i < env->data.row)
	{
		j = 0;
		while (j < env->data.col)
		{
			x = ft_get_new_x(env, i, j);
			y = ft_get_new_y(env, i, j);
			if (x >= 0 && x <= env->width && y >=0 && y <= env->height)
				my_pixel_put(&env->img, x, y, 0xFFFFFF);
			j++;
		}
		i++;
	}
	// ft_draw_rectangle(env, env->origin.x, env->origin.y, 8, 0xFF0000);
	my_pixel_put(&env->img, env->origin.x, env->origin.y, 0xFF0000);
	mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->img.img_ptr, 0, 0);
	return (0);
}
