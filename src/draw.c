/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 13:24:05 by momrane           #+#    #+#             */
/*   Updated: 2024/01/20 18:40:04 by momrane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int	lerp_color(int color1, int color2, float factor)
{
	int	r1;
	int	g1;
	int	b1;
	int	r2;
	int	g2;
	int	b2;
	int	r;
	int	g;
	int	b;

	r1 = (color1 >> 16) & 0xFF;
	g1 = (color1 >> 8) & 0xFF;
	b1 = color1 & 0xFF;
	r2 = (color2 >> 16) & 0xFF;
	g2 = (color2 >> 8) & 0xFF;
	b2 = color2 & 0xFF;
	r = (int)(r1 + factor * (r2 - r1));
	g = (int)(g1 + factor * (g2 - g1));
	b = (int)(b1 + factor * (b2 - b1));
	return ((r << 16) | (g << 8) | b);
}

static void	my_pixel_put(t_env *env, int x, int y, int color)
{
	char	*dst;

	dst = env->img.img_data + (y * env->img.size_line + x * (env->img.bpp / 8));
	*(unsigned int *)dst = color;
}

void	draw_line_dda(t_env *env, t_pt pt1, t_pt pt2)
{
	int		steps;
	float	x;
	float	y;
	float	dx;
	float	dy;
	int		i;
	float	factor;
	int		color;
	float	xIncrement;
	float	yIncrement;

	x = pt1.x;
	dx = pt2.x - pt1.x;
	x = pt1.x, y = pt1.y;
	dx = pt2.x - pt1.x;
	dy = pt2.y - pt1.y;
	steps = (abs((int)dx) > abs((int)dy)) ? abs((int)dx) : abs((int)dy);
	xIncrement = dx / (float)steps;
	yIncrement = dy / (float)steps;
	i = 0;
	while (i <= steps)
	{
		factor = i / (float)steps;
		color = lerp_color(pt1.color, pt2.color, factor);
		if (x >= 0 && x < env->width && y >= 0 && y < env->height)
			my_pixel_put(env, (int)x, (int)y, color);
		x += xIncrement;
		y += yIncrement;
		i++;
	}
}

static void	ft_draw_dda(t_env *env, int r, int c)
{
	if (c < env->cols - 1)
		draw_line_dda(env, env->mat[r][c], env->mat[r][c + 1]);
	if (r < env->rows - 1)
		draw_line_dda(env, env->mat[r][c], env->mat[r + 1][c]);
}

static void	ft_convert_points(t_env *env, int r, int c)
{
	t_pt converted_point;

	converted_point = ft_get_converted_point(env, r, c);
	env->mat[r][c] = converted_point;
}

void	ft_draw(t_env *env)
{
	ft_parse_matrix(env, ft_convert_points);
	ft_clear_img(env);
	ft_parse_matrix(env, ft_draw_dda);
	// my_pixel_put(env, env->origin.x, env->origin.y, 0xFFFFFF);
	// my_pixel_put(env, env->width - 100, 100, 0xFFFFFF);
	
	mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->img.img_ptr, 0, 0);
}
