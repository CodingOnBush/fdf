/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 12:17:47 by momrane           #+#    #+#             */
/*   Updated: 2024/01/21 12:30:08 by momrane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	ft_move_map_points(t_env *env, int r, int c)
{
	int	x;
	int	y;
	
	x = env->map[r][c].x;
	y = env->map[r][c].y;
	if (c < env->c)
		x += (env->c - c) * env->space;
	else if (c > env->c)
		x -= (c - env->c) * env->space;
	if (r < env->r)
		y += (env->r - r) * env->space;
	else if (r > env->r)
		y -= (r - env->r) * env->space;
}
