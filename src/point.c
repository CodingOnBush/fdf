/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 12:17:47 by momrane           #+#    #+#             */
/*   Updated: 2024/01/18 20:50:21 by momrane          ###   ########.fr       */
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
	new_x = x + 1;
	if (c < env->data.c)
		new_x -= env->space * (env->data.c - c);
	else if (c > env->data.c)
		new_x += (env->space) * (env->data.col - c);
	// ft_printf("new_x = %d\n", new_x);
	return (new_x);
}

int	ft_get_new_y(t_env *env, int r, int c)
{
	int	new_y;
	int	y;

	y = env->data.matrix[r][c].y;

	new_y = y + 1;
	if (r < env->data.r)
		new_y -= env->space * (env->data.r - r);
	else if (r > env->data.r)
		new_y += (env->space) * (env->data.row - r);
	// ft_printf("new_y = %d\n", new_y);
	return (new_y);
}

int	ft_get_new_z(t_env *env, int r, int c)
{
	int	new_z;
	int	z;

	z = env->data.matrix[r][c].z;
	new_z = z * env->space / 2;
	return (new_z);
}
