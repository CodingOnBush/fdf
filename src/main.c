/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 09:27:43 by momrane           #+#    #+#             */
/*   Updated: 2024/01/16 11:44:26 by momrane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

static void	my_pixel_put(t_img *img, int x, int y, int color)
{
	int	offset;

	//🚨 Line len is in bytes. WIDTH 800 len_line ~3200 (can differ for alignment)
	offset = (img->line_len * y) + (x * (img->bits_per_pixel / 8));
	*((unsigned int *)(offset + img->img_pixels_ptr)) = color;
}

static void	color_screen(t_env *env, int color)
{
	for (int y = 0; y < env->height; ++y)
	{
		for (int x = 0; x < env->width; ++x)
		{
			/*
				* This function is much faster than the library one🏻
				* 	~Buffer in the image and push only when ready-> No flickering effect
				*/
			my_pixel_put(&env->img, x, y, color);
		}
	}
}

static void	ft_draw(t_env *env)
{
	t_point	*pt;
	int		sx;
	int		sy;

	pt = env->lst;
	if (!pt)
		return ;
	while (pt)
	{
		sx = pt->x + 10;
		sy = pt->y;
		my_pixel_put(&env->img, (sx + 1) * 200, (sy + 1) * 200, 0x00FF00);
		pt = pt->next;
	}
}

int	main(int ac, char **av)
{
	ft_start_parsing(ac, av);
	// t_env	*env;

	// ft_init_env(&env, ac, av);
	// ft_init_hooks(env);
	
	// env->img.img_ptr = mlx_new_image(env->mlx, env->width, env->height);
	// env->img.img_pixels_ptr = mlx_get_data_addr(env->img.img_ptr, &env->img.bits_per_pixel, &env->img.line_len, &env->img.endian);
	// ft_draw(env);
	// mlx_put_image_to_window(env->mlx, env->win, env->img.img_ptr, 0, 0);
	
	// mlx_loop(env->mlx);
	return (0);
}
