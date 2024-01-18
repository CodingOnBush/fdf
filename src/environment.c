/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:28:38 by momrane           #+#    #+#             */
/*   Updated: 2024/01/18 18:03:54 by momrane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

t_env	ft_init_env(t_parsing data)
{
	t_env	env;
	int		width;
	int		height;

	width = 1000;
	height = 1000;
	env.data = data;
	env.width = width;
	env.height = height;
	env.x_offset = width / 2;
	env.y_offset = height / 2;
	env.z_offset = 0;
	env.angle = 0.45;
	env.zoom = 20;
	env.scale = 5;
	env.space = 10;
	env.origin.x = width / 2;
	env.origin.y = height / 2;
	env.mlx_ptr = mlx_init();
	if (!(env.mlx_ptr))
		ft_exit_error("mlx_init failed");
	env.win_ptr = mlx_new_window(env.mlx_ptr, width, height, "FDF");
	if (!(env.win_ptr))
		ft_exit_error("mlx_new_window failed");
	ft_printf("width: %d\n", env.width);
	ft_printf("height: %d\n", env.height);
	return (env);
}
