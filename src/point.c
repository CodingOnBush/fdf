/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 12:17:47 by momrane           #+#    #+#             */
/*   Updated: 2024/01/21 13:46:57 by momrane          ###   ########.fr       */
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
		x += (env->c - c) * env->zoom;
	else if (c > env->c)
		x -= (c - env->c) * env->zoom;
	if (r < env->r)
		y += (env->r - r) * env->zoom;
	else if (r > env->r)
		y -= (r - env->r) * env->zoom;
	env->map[r][c].x = x;
	env->map[r][c].y = y;
}
