/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 09:27:43 by momrane           #+#    #+#             */
/*   Updated: 2024/01/16 14:57:50 by momrane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int	main(int ac, char **av)
{
	t_parsing	data;
	t_env		env;

	if (ac != 2)
		ft_exit_error("Usage: ./fdf <filename>");
	data = ft_start_parsing(av[1]);
	env = ft_init_env(data);
	ft_init_hooks(&env);
	
	// env->img.img_ptr = mlx_new_image(env->mlx, env->width, env->height);
	// env->img.img_pixels_ptr = mlx_get_data_addr(env->img.img_ptr, &env->img.bits_per_pixel, &env->img.line_len, &env->img.endian);
	// ft_draw(env);
	// mlx_put_image_to_window(env->mlx, env->win, env->img.img_ptr, 0, 0);
	
	mlx_loop(env.mlx_ptr);
	return (0);
}
