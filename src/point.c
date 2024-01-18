/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 12:17:47 by momrane           #+#    #+#             */
/*   Updated: 2024/01/18 22:05:39 by momrane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int	ft_get_new_x(t_env *env, int r, int c)
{
	int	new_x;
	int	x;

	if (env->data.matrix == NULL)
		return (0);
	x = env->data.matrix[r][c].x;
	new_x = x;
	if (c < env->data.c)
		new_x -= env->space * (env->data.c - c);
	else if (c > env->data.c)
		new_x += (env->space) * (env->data.col - c);
	return (new_x);
}

int	ft_get_new_y(t_env *env, int r, int c)
{
	int	new_y;
	int	y;

	y = env->data.matrix[r][c].y;

	new_y = y;
	if (r < env->data.r)
		new_y -= env->space * (env->data.r - r);
	else if (r > env->data.r)
		new_y += (env->space) * (env->data.row - r);
	return (new_y);
}

int	ft_get_new_z(t_env *env, int r, int c)
{
	int	new_z;
	int	z;

	z = env->data.matrix[r][c].z;
	new_z = z;// + env->altitude;
	return (new_z);
}
