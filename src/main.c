/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 09:27:43 by momrane           #+#    #+#             */
/*   Updated: 2024/01/14 15:54:00 by momrane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

static void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	int	offset;

	//🚨 Line len is in bytes. WIDTH 800 len_line ~3200 (can differ for alignment)
	offset = (img->line_length * y) + (x * (img->bits_per_pixel / 8));	

	*((unsigned int *)(offset + img->addr)) = color;
	// char	*dst;

	// dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	// *(unsigned int *)dst = color;
}

static int	key_hook(int keycode, t_env *env)
{
	if (keycode == XK_Escape)
	{
		ft_printf("Bye!\n");
		ft_free_points(&env->lst);
		mlx_destroy_window(env->mlx, env->win);
		mlx_destroy_display(env->mlx);
		free(env->mlx);
		free(env);
		exit(1);
	}
	ft_printf("keycode: %d\n", keycode);
	return (0);
}

static void	ft_put_pixels(t_env *env)
{
	t_point	*tmp;

	tmp = env->lst;
	while (tmp)
	{
		my_mlx_pixel_put(&env->img, (tmp->x)*10, (tmp->y)*10, 0x00FFFFFF);
		tmp = tmp->next;
	}
}

int	main(int ac, char **av)
{
	t_env	*env;

	if (ft_init_env(&env, ac, av) == 0)
		ft_error("Error: init failed");
	ft_printf("row: %d\n", env->row);
	ft_printf("col: %d\n", env->col);
	env->mlx = mlx_init();
	if (!(env->mlx))
	{
		ft_free_env(&env);
		ft_error("Error: mlx_init failed");
	}
	env->win = mlx_new_window(env->mlx, 1000, 1000, "Hello world!");
	if (!(env->win))
	{
		mlx_destroy_display(env->mlx);
		ft_free_env(&env);
		ft_error("Error: mlx_new_window failed");
	}
	mlx_key_hook(env->win, key_hook, env);

	/* we have our display, we have to create the image and then put it on the screen */
	env->img.img = mlx_new_image(env->mlx, 1000, 1000);
	env->img.addr = mlx_get_data_addr(env->img.img, &env->img.bits_per_pixel, &env->img.line_length, &env->img.endian);

	ft_put_pixels(env);

	mlx_put_image_to_window(env->mlx, env->win, env->img.img, (500 - (env->row * 2)), (500 - (env->col * 2)));

	mlx_loop(env->mlx);
	return (0);
}
