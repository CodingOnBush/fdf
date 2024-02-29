/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 09:47:20 by momrane           #+#    #+#             */
/*   Updated: 2024/02/29 15:55:31 by momrane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

static int	ft_gradient(int c1, int c2, float factor)
{
	int	r;
	int	g;
	int	b;

	r = (int)(((c1 >> 16) & 0xFF) + factor * (((c2 >> 16) & 0xFF)
				- ((c1 >> 16) & 0xFF)));
	g = (int)(((c1 >> 8) & 0xFF) + factor * (((c2 >> 8) & 0xFF)
				- ((c1 >> 8) & 0xFF)));
	b = (int)((c1 & 0xFF) + factor * ((c2 & 0xFF) - (c1 & 0xFF)));
	return ((r | g | b));
	// return (1);
}

static float	ft_get_steps(float dx, float dy)
{
	int	steps;

	steps = abs((int)dy);
	if (abs((int)dx) > abs((int)dy))
		steps = abs((int)dx);
	return (steps);
}

static void	ft_draw_line(t_env *env, t_pt pt1, t_pt pt2)
{
	float	factor;
	float	steps;
	float	x;
	float	y;
	float	i;

	x = pt1.x;
	y = pt1.y;
	i = 0;
	steps = ft_get_steps(pt2.x - pt1.x, pt2.y - pt1.y);
	while (i++ <= steps)
	{
		factor = i / steps;
		ft_put_pixel(env, (int)x, (int)y, ft_gradient(pt1.color, pt2.color,
				factor));
		x += (pt2.x - pt1.x) / steps;
		y += (pt2.y - pt1.y) / steps;
	}
}

void	ft_draw_dda(t_env *env, int r, int c)
{
	if (c < env->cols - 1)
		ft_draw_line(env, env->mat[r][c], env->mat[r][c + 1]);
	if (r < env->rows - 1)
		ft_draw_line(env, env->mat[r][c], env->mat[r + 1][c]);
}
