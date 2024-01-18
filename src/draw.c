/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 13:24:05 by momrane           #+#    #+#             */
/*   Updated: 2024/01/18 20:49:40 by momrane          ###   ########.fr       */
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

void	ft_draw(t_env *env)
{
	int	r;
	int	c;
	int x;
	int y;
	int z;

	ft_bzero(env->img.img_pixels_ptr, env->img.line_len * env->height);
	r = 0;
	while (r < env->data.row)
	{
		c = 0;
		while (c < env->data.col)
		{
			x = ft_get_new_x(env, r, c);
			y = ft_get_new_y(env, r, c);
			z = ft_get_new_z(env, r, c);
			x = (x * cos(env->angle)) + (y * cos(env->angle + 2)) + (z * cos(env->angle - 2));
			y = (x * sin(env->angle)) + (y * sin(env->angle + 2)) + (z * sin(env->angle - 2));
			x += env->origin.x;
			y += env->origin.y;
			if (x >= 0 && x <= env->width && y >=0 && y <= env->height)
				my_pixel_put(&env->img, x, y, 0xFFFFFF);
			c++;
		}
		r++;
	}
	my_pixel_put(&env->img, env->origin.x, env->origin.y, 0xFF0000);
	mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->img.img_ptr, 0, 0);
}
