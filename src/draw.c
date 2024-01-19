/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 13:24:05 by momrane           #+#    #+#             */
/*   Updated: 2024/01/19 16:25:02 by momrane          ###   ########.fr       */
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

	// int	offset;
	//🚨 Line len is in bytes. WIDTH 800 len_line ~3200 (can differ for alignment)
	// offset = (img->size_line * y) + (x * (img->bpp / 8));
	// *((unsigned int *)(offset + img->img_data)) = color;
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
	steps = (abs(dx) > abs(dy)) ? abs(dx) : abs(dy);
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
	if (c < env->data.col - 1)
		draw_line_dda(env, env->mat[r][c], env->mat[r][c + 1]);
	if (r < env->data.row - 1)
		draw_line_dda(env, env->mat[r][c], env->mat[r + 1][c]);
}


static void	ft_apply_transformation(t_env *env, int r, int c)
{
	int x;
	int y;
	int z;

	x = env->data.matrix[r][c].x * env->space;
	y = env->data.matrix[r][c].y * env->space;
	z = env->data.matrix[r][c].z * env->space;
	env->mat[r][c].x = x * cos(env->angle) - y * sin(env->angle);
	env->mat[r][c].y = (x * sin(env->angle) + y * cos(env->angle)) / 2 - z * env->altitude;
	
	env->mat[r][c].x += env->origin.x - env->data.col;
	env->mat[r][c].y += env->origin.y - env->data.row;
	
	env->mat[r][c].z = env->data.matrix[r][c].z;

	env->mat[r][c].color = env->data.matrix[r][c].color + env->mat[r][c].z * 100;
}

// static void	ft_fill_new_matrix(t_env *env, t_pt **new)
// {
// 	int	r;
// 	int	c;

// 	if (!new)
// 		ft_exit_error("malloc failed");
// 	r = 0;
// 	while (r < env->data.row)
// 	{
// 		c = 0;
// 		while (c < env->data.col)
// 		{
// 			new[r][c].x = env->data.matrix[r][c].x * env->space;
// 			new[r][c].y = env->data.matrix[r][c].y * env->space;
// 			new[r][c].z = env->data.matrix[r][c].z;
// 			ft_make_transformation(env, &new[r][c].x, &new[r][c].y,
// 				&new[r][c].z);
// 			new[r][c].color = env->data.matrix[r][c].color + new[r][c].z * 100;
// 			c++;
// 		}
// 		r++;
// 	}
// }

void	ft_draw(t_env *env)
{
	ft_parse_matrix(env, ft_apply_transformation);
	ft_bzero(env->img.img_data, env->img.size_line * env->height);
	ft_parse_matrix(env, ft_draw_dda);
	mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->img.img_ptr, 0, 0);
}
