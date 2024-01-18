/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 13:24:05 by momrane           #+#    #+#             */
/*   Updated: 2024/01/18 17:57:59 by momrane          ###   ########.fr       */
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
	// ft_printf("pixel put\n");
}

// static void ft_draw_rectangle(t_env *env, int x, int y, int size, int color)
// {
// 	int i;
// 	int j;

// 	i = 0;
// 	while (i < size)
// 	{
// 		j = 0;
// 		while (j < size)
// 		{
// 			my_pixel_put(&env->img, (x - size / 2) + i, (y - size / 2) + j, color);
// 			j++;
// 		}
// 		i++;
// 	}
// }

// destination.x = source.x + cos(angle) * source.z
// destination.y = source.y + sin(angle) * source.z


static void	ft_draw_line(t_env *env, t_pt a, t_pt b)
{
	float step;
	float xin;
	float yin;

	if (((float)b.x - (float)a.x) >= ((float)b.y - (float)a.y))
		step = fabs((float)b.x - (float)a.x);
	else
		step = fabs((float)b.y - (float)a.y);
	xin = (b.x - a.x) / step;
	yin = (b.y - a.y) / step;
	a.x = a.x + 0.5;
	a.y = a.y + 0.5;
	while (step--)
	{
		if (a.x >= 0 && a.x <= env->width && a.y >= 0 && a.y <= env->height)
			my_pixel_put(&env->img, a.x, a.y, 0xFFFFFF);
		a.x = a.x + xin;
		a.y = a.y + yin;
	}
}

/*

void	draw_line(t_env *env, t_fpoint point0, t_fpoint point1)
{
	float	step;
	float	x;
	float	y;
	int		i;
	t_delta	delta;

	i = 0;
	delta.dx = point1.x - point0.x;
	delta.dy = point1.y - point0.y;
	if (fabsf(delta.dx) >= fabsf(delta.dy))
		step = fabsf(delta.dx);
	else
		step = fabsf(delta.dy);
	delta.dx = delta.dx / step;
	delta.dy = delta.dy / step;
	x = point0.x;
	y = point0.y;
	while (i < step)
	{
		put_pixel(env, -x + WINDOW_WIDTH / 2 + env->translation, \
		-y + WINDOW_HEIGHT / 2 + env->translation, RED);
		x = x + delta.dx;
		y = y + delta.dy;
		i++;
	}
}

*/

static void	ft_draw_all_lines(t_env *env)
{
	int	i;
	int	j;

	i = 0;
	while (i < env->data.row)
	{
		j = 0;
		while (j < env->data.col)
		{
			if (j + 1 < env->data.col && i < env->data.row)
				ft_draw_line(env, env->data.matrix[i][j], env->data.matrix[i][j + 1]);
			if (i + 1 < env->data.row && j < env->data.col)
				ft_draw_line(env, env->data.matrix[i][j], env->data.matrix[i + 1][j]);
			j++;
		}
		i++;
	}
}

static void	ft_print_matrix(t_env *env)
{
	int	i;
	int	j;

	i = 0;
	while (i < env->data.row)
	{
		j = 0;
		while (j < env->data.col)
		{
			ft_printf("[x: %d, y: %d]", env->data.matrix[i][j].x, env->data.matrix[i][j].y);
			j++;
		}
		ft_printf("\n");
		i++;
	}
}

void	ft_draw(t_env *env)
{
	int	i;
	int	j;
	int x;
	int y;
	int z;

	i = 0;
	ft_bzero(env->img.img_pixels_ptr, env->img.line_len * env->height);
	while (i < env->data.row)
	{
		j = 0;
		while (j < env->data.col)
		{
			x = ft_get_new_x(env, i, j);
			y = ft_get_new_y(env, i, j);
			z = ft_get_new_z(env, i, j);
			x = (x * cos(env->angle)) + (y * cos(env->angle + 2)) + (z * cos(env->angle - 2));
			y = (x * sin(env->angle)) + (y * sin(env->angle + 2)) + (z * sin(env->angle - 2));
			if (x >= 0 && x <= env->width && y >=0 && y <= env->height)
				my_pixel_put(&env->img, x, y, 0xFFFFFF);
			j++;
		}
		i++;
	}
	my_pixel_put(&env->img, env->origin.x, env->origin.y, 0xFF0000);
	mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->img.img_ptr, 0, 0);
}
