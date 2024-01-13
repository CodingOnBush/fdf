/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 09:27:43 by momrane           #+#    #+#             */
/*   Updated: 2024/01/13 15:34:48 by momrane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

// static void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
// 	*(unsigned int *)dst = color;
// }


int	main(int ac, char **av)
{
	t_env	*env;
	// t_data	*img;

	if (ft_init_env(&env, ac, av) == 0)
		ft_error("Error: init failed");
	env->mlx = mlx_init();
	if (!(env->mlx))
	{
		ft_free_env(&env);
		ft_error("Error: mlx_init failed");
	}
	env->win = mlx_new_window(env->mlx, 500, 500, "Hello world!");
	if (!(env->win))
	{
		ft_free_env(&env);
		ft_error("Error: mlx_new_window failed");
	}
	mlx_loop(env->mlx);
	
	// env->win = mlx_new_window(env->mlx, 500, 500, "Hello world!");
	// img = (t_data *)malloc(sizeof(t_data));
	// if (!img)
	// {
	// 	ft_free_env(&env);
	// 	ft_error("Error: malloc failed");
	// }
	// img->img = mlx_new_image(env->mlx, 500, 500);
	// img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
	// 		&img->line_length, &img->endian);
	// my_mlx_pixel_put(img, 5, 5, 0x00FF0000);
	// mlx_put_image_to_window(env->mlx, env->win, img->img, 0, 0);
	// mlx_loop(env->mlx);
	
	mlx_destroy_display(env->mlx);
	// free(img);
	ft_free_env(&env);
	return (0);
}
