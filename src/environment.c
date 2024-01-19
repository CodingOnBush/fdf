/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:28:38 by momrane           #+#    #+#             */
/*   Updated: 2024/01/19 04:54:54 by momrane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

t_env	ft_init_env(t_parsing data)
{
	t_env	env;
	int		width;
	int		height;

	width = 1200;
	height = 800;
	env.data = data;
	env.width = width;
	env.height = height;
	env.x_offset = width / 2;
	env.y_offset = height / 2;
	env.z_offset = 0;
	env.angle = 365;
	env.zoom = 20;
	env.altitude = 2;
	env.scale = 0.7;
	env.space = 20;//width / data.col / 1.5;
	env.origin.x = width / 2;
	env.origin.y = height / 2;
	env.mlx_ptr = mlx_init();
	if (!(env.mlx_ptr))
		ft_exit_error("mlx_init failed");
	env.win_ptr = mlx_new_window(env.mlx_ptr, width, height, "FDF");
	if (!(env.win_ptr))
		ft_exit_error("mlx_new_window failed");
	return (env);
}
