/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 13:24:05 by momrane           #+#    #+#             */
/*   Updated: 2024/01/21 13:53:38 by momrane          ###   ########.fr       */
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

	if (x < 0 || x >= env->width || y < 0 || y >= env->height)
		return ;
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
	t_pt	out;
	int		x;
	int		y;
	int		z;

	x = env->map[r][c].x - env->map[env->rows / 2][env->cols / 2].x;
	y = env->map[r][c].y - env->map[env->rows / 2][env->cols / 2].y;
	z = env->map[r][c].z;
	if (c < env->c)
		x += (env->c - c) * env->zoom;
	else if (c > env->c)
		x -= (c - env->c) * env->zoom;
	if (r < env->r)
		y += (env->r - r) * env->zoom;
	else if (r > env->r)
		y -= (r - env->r) * env->zoom;
	out.x = x * cosf(env->angle) - y * sinf(env->angle);
	out.y = (x * sinf(env->angle) + y * cosf(env->angle)) / 2 - z * env->altitude;
	out.x += env->origin.x;
	out.y += env->origin.y;
	out.z = z * env->altitude;
	out.color = env->map[r][c].color * (z + 42);
	env->mat[r][c] = out;
}

static void	ft_draw_square(t_env *env, int x, int y, int color)
{
	int		i;
	int		j;

	i = 0;
	x -= 10;
	y -= 10;
	while (i < 20)
	{
		j = 0;
		while (j < 20)
		{
			my_pixel_put(env, x + i, y + j, color);
			j++;
		}
		i++;
	}
}

void	ft_draw(t_env *env)
{
	// ft_set_zoom(env);
	// ft_parse_matrix(env, ft_move_map_points);
	ft_parse_matrix(env, ft_convert_points);
	ft_clear_img(env);
	ft_parse_matrix(env, ft_draw_dda);
	// my_pixel_put(env, env->origin.x, env->origin.y, 0xFFFFFF);
	// my_pixel_put(env, env->mat[env->rows/2][env->cols/2].x, env->mat[env->rows/2][env->cols/2].y, 0xFF0000);
	printf("ORIGIN : (%d, %d)\n", env->origin.x, env->origin.y);
	ft_draw_square(env, env->origin.x, env->origin.y, 0xFF0000);
	ft_draw_square(env, env->mat[0][0].x, env->mat[0][0].y, 0x00FF00);
	ft_draw_square(env, env->mat[env->rows - 1][env->cols - 1].x, env->mat[env->rows - 1][env->cols - 1].y, 0x00FF00);
	ft_draw_square(env, env->mat[env->rows / 2][env->cols / 2].x, env->mat[env->rows / 2][env->cols / 2].y, 0x00FF00);
	mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->img.img_ptr, 0, 0);
}
