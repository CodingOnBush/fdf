/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 13:24:05 by momrane           #+#    #+#             */
/*   Updated: 2024/01/16 16:27:21 by momrane          ###   ########.fr       */
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
	env->img.img_ptr = mlx_new_image(env->mlx_ptr, env->width, env->height);
	if (!env->img.img_ptr)
		ft_exit_error("Error: mlx_new_image failed");
	env->img.img_pixels_ptr = mlx_get_data_addr(env->img.img_ptr,
			&env->img.bits_per_pixel, &env->img.line_len, &env->img.endian);
	if (!env->img.img_pixels_ptr)
		ft_exit_error("Error: mlx_get_data_addr failed");
}

int	ft_draw(t_env *env)
{
	int	sx;
	int	sy;
	int	i;
	int	j;

	i = 0;
	ft_prep_img(env);
	while (i < env->data.row)
	{
		j = 0;
		while (j < env->data.col)
		{
			sx = j + 10;
			sy = i;
			my_pixel_put(&env->img, (sx + 1) * 200, (sy + 1) * 200, rand()
				% 0xFFFFFF);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->img.img_ptr, 0, 0);
	sleep(1);
	return (0);
}
