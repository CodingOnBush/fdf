/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 12:17:47 by momrane           #+#    #+#             */
/*   Updated: 2024/01/18 11:35:09 by momrane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"


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
	new_y -= (env->data.col / 2) * env->scale;
	return (new_y);
}

static int	ft_get_new_z(t_env *env, int i, int j)
{
	int	new_z;
	int	x;
	int	y;
	int	z;

	(void)x;
	(void)y;
	(void)z;
	x = env->data.matrix[i][j].x;
	y = env->data.matrix[i][j].y;
	z = env->data.matrix[i][j].z;
	new_z = ((z + 1) * env->scale) + (env->origin.z) - env->scale;
	new_z -= (env->data.row / 2) * env->scale;
	return (new_z);
}

void	ft_transformation_points(t_env *env)
{
	int	i;
	int	j;
	int x;
	int y;
	int z;

	i = 0;
	while (i < env->data.row)
	{
		j = 0;
		while (j < env->data.col)
		{
			x = ft_get_new_x(env, i, j);
			y = ft_get_new_y(env, i, j);
			z = ft_get_new_z(env, i, j);
			x = (x * cos(env->angle)) + (y * cos(env->angle + 2)) + (z * cos(env->angle - 2));
			y = (x * sin(env->angle)) + (y * sin(env->angle + 2)) + (z * sin(env->angle - 2));
			env->data.matrix[i][j].x = x;
			env->data.matrix[i][j].y = y;
			env->data.matrix[i][j].z = z;
			j++;
		}
		i++;
	}
}
