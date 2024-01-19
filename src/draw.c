/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 13:24:05 by momrane           #+#    #+#             */
/*   Updated: 2024/01/19 04:23:16 by momrane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

static void	my_pixel_put(t_env *env, int x, int y, int color)
{
	char	*dst;

	// int	offset;
	//🚨 Line len is in bytes. WIDTH 800 len_line ~3200 (can differ for alignment)
	// offset = (img->size_line * y) + (x * (img->bpp / 8));
	// *((unsigned int *)(offset + img->img_data)) = color;
	if (x > env->width - 1 || y > env->height - 1 || x < 0 || y < 0)
		return ;
	dst = env->img.img_data + (y * env->img.size_line + x * (env->img.bpp / 8));
	*(unsigned int *)dst = color;
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

void	draw_line_dda(t_env *env, t_pt pt1, t_pt pt2)
{
	int		steps;
	float	x = pt1.x, y;
	float	dx = pt2.x - pt1.x, dy;
	int		i;

	float xIncrement, yIncrement;
	x = pt1.x, y = pt1.y;
	dx = pt2.x - pt1.x, dy = pt2.y - pt1.y;
	steps = (abs(dx) > abs(dy)) ? abs(dx) : abs(dy);
	xIncrement = dx / (float)steps;
	yIncrement = dy / (float)steps;
	i = 0;
	while (i <= steps)
	{
		if (x >= 0 && x < env->width && y >= 0 && y < env->height)
			my_pixel_put(env, (int)x, (int)y, 0xFFFFFF);
		x += xIncrement;
		y += yIncrement;
		i++;
	}
}

void	ft_draw_lines_dda(t_env *env, t_pt **mat)
{
	int	r;
	int	c;

	r = 0;
	while (r < env->data.row)
	{
		c = 0;
		while (c < env->data.col)
		{
			if (c < env->data.col - 1)
				draw_line_dda(env, mat[r][c], mat[r][c + 1]);
			if (r < env->data.row - 1)
				draw_line_dda(env, mat[r][c], mat[r + 1][c]);
			c++;
		}
		r++;
	}
}

void	ft_draw(t_env *env)
{
	int		r;
	int		c;
	int		x;
	int		y;
	int		new_x;
	int		new_y;
	t_pt	**new;

	new = ft_new_matrix(env->data.row, env->data.col);
	if (!new)
		ft_exit_error("malloc failed");
	ft_bzero(env->img.img_data, env->img.size_line * env->height);
	r = 0;
	while (r < env->data.row)
	{
		c = 0;
		while (c < env->data.col)
		{
			x = env->data.matrix[r][c].x + 1;
			y = env->data.matrix[r][c].y + 1;
			x *= 10;
			y *= 10;
			new_x = x - y;
			new_y = (x + y) / 2 - env->data.matrix[r][c].z * env->altitude;
			new_x += env->origin.x;
			new_y += env->origin.y;
			new[r][c].x = new_x;
			new[r][c].y = new_y;
			new[r][c].z = env->data.matrix[r][c].z;	
			// if (new_x >= 0 && new_x <= env->width && new_y >=0
				// && new_y <= env->height)
			// {
			// 	if (ft_get_new_z(env, r, c) * env->altitude > 0)
			// 	{
			// 		my_pixel_put(env, new_x, new_y, 0xFF0000);
			// 		ft_printf("X");
			// 	}
			// 	else
			// 	{
			// 		my_pixel_put(env, new_x, new_y, 0x00FF00);
			// 		ft_printf("O");
			// 	}
			// }
			c++;
		}
		r++;
	}
	ft_draw_lines_dda(env, new);
	mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->img.img_ptr, 0, 0);
}
