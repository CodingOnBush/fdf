/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 13:24:05 by momrane           #+#    #+#             */
/*   Updated: 2024/01/18 22:12:00 by momrane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

static void	my_pixel_put(t_img *img, int x, int y, int color)
{
	int				offset;
	unsigned int	*px;

	offset = (img->line_len * y) + (x * (img->bits_per_pixel / 8));
	px = (unsigned int *)(img->img_pixels_ptr + offset);
	*px = color;
}

t_pt	**ft_new_matrix(int r, int c)
{
	t_pt	**new;
	int		i;

	i = 0;
	new = (t_pt **)malloc(sizeof(t_pt *) * r);
	while (i < r)
	{
		new[i] = (t_pt *)malloc(sizeof(t_pt) * c);
		i++;
	}
	return (new);
}

void	ft_draw_line(t_env *env, t_pt a, t_pt b)
{
	int		x;
	int		y;
	int		dx;
	int		dy;
	int		sx;
	int		sy;
	int		err;
	int		e2;
	int		color;

	color = 0xFFFFFF;
	x = a.x;
	y = a.y;
	dx = abs(b.x - a.x);
	dy = abs(b.y - a.y);
	sx = (a.x < b.x) ? 1 : -1;
	sy = (a.y < b.y) ? 1 : -1;
	err = ((dx > dy) ? dx : -dy) / 2;
	while (1)
	{
		if (x > 0 && x < env->width && y > 0 && y < env->height)
			my_pixel_put(&env->img, x, y, color);
		if (x == b.x && y == b.y)
			break ;
		e2 = err;
		if (e2 > -dx)
		{
			err -= dy;
			x += sx;
		}
		if (e2 < dy)
		{
			err += dx;
			y += sy;
		}
	}
}

void	ft_draw_lines(t_env *env, t_pt **mat, int row, int col)
{
	int	r;
	int	c;

	r = 0;
	while (r < row)
	{
		c = 0;
		while (c < col)
		{
			if (c < col - 1)
				ft_draw_line(env, mat[r][c], mat[r][c + 1]);
			// if (r < row - 1)
			// 	ft_draw_line(env, mat[r][c], mat[r + 1][c]);
			c++;
		}
		r++;
	}
}

void	ft_draw(t_env *env)
{
	int	r;
	int	c;
	int x;
	int y;
	int z;
	t_pt **new;

	new = ft_new_matrix(env->data.row, env->data.col);
	if (!new)
		ft_exit_error("malloc failed");
	ft_bzero(env->img.img_pixels_ptr, env->img.line_len * env->height);
	r = 0;
	while (r < env->data.row)
	{
		c = 0;
		while (c < env->data.col)
		{
			x = ft_get_new_x(env, r, c);
			y = ft_get_new_y(env, r, c);
			z = ft_get_new_z(env, r, c);
			x = (x * cos(env->angle)) + (y * cos(env->angle + 2)) + (z * cos(env->angle - 2));
			y = (x * sin(env->angle)) + (y * sin(env->angle + 2)) + (z * sin(env->angle - 2));
			x += env->origin.x;
			y += env->origin.y;
			new[r][c].x = x;
			new[r][c].y = y;
			new[r][c].z = z;
			// if (x >= 0 && x <= env->width && y >=0 && y <= env->height)
			// 	my_pixel_put(&env->img, x, y, 0xFFFFFF);
			c++;
		}
		r++;
	}
	ft_draw_lines(env, new, env->data.row, env->data.col);
	my_pixel_put(&env->img, env->origin.x, env->origin.y, 0xFF0000);
	mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->img.img_ptr, 0, 0);
}
