/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allblue <allblue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:28:38 by momrane           #+#    #+#             */
/*   Updated: 2024/01/20 10:35:18 by allblue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

static void	ft_init_values(t_env *env, t_parsing data)
{
	env->data = data;
	env->width = 1200;
	env->height = 800;
	env->angle = 5;
	env->zoom = 20;
	env->altitude = 1.3;
	env->scale = 0.7;
	env->space = 20;
	env->origin.x = env->width / 2;
	env->origin.y = env->height / 2;
}

int	ft_init_env(t_env *env, t_parsing data)
{
	ft_init_values(env, data);
	env->mlx_ptr = mlx_init();
	if (!env->mlx_ptr)
		return (-1);
	env->win_ptr = mlx_new_window(env->mlx_ptr, env->width, env->height, "FDF");
	if (!env->win_ptr)
		return (-1);
	env->mat = ft_new_matrix(env->data.row, env->data.col);
	if (!env->mat)
		return (-1);
	return (1);
}
