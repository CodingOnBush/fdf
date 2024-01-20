/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 12:17:47 by momrane           #+#    #+#             */
/*   Updated: 2024/01/20 17:49:50 by momrane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

t_pt	ft_get_converted_point(t_env *env, int r, int c)
{
	t_pt	out;
	int		x;
	int		y;
	int		z;

	x = env->map[r][c].x;
	y = env->map[r][c].y;
	z = env->map[r][c].z;
	if (c < env->c)
		x += (env->c - c) * env->space;
	else if (c > env->c)
		x -= (c - env->c) * env->space;
	if (r < env->r)
		y += (env->r - r) * env->space;
	else if (r > env->r)
		y -= (r - env->r) * env->space;
	out.x = x * cos(env->angle) - y * sin(env->angle);
	out.y = (x * sin(env->angle) + y * cos(env->angle)) / 2 - z * env->altitude;
	out.x += env->origin.x;
	out.y += env->origin.y;
	out.z = z * env->altitude;
	out.color = env->map[r][c].color;
	return (out);
}
