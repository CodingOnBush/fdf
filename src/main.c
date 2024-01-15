/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 09:27:43 by momrane           #+#    #+#             */
/*   Updated: 2024/01/15 11:09:25 by momrane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

static void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	int	offset;

	offset = (img->line_length * y) + (x * (img->bits_per_pixel / 8));
	*((unsigned int *)(offset + img->addr)) = color;
	// char	*dst;

	// dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel/ 8));
	// *(unsigned int *)dst = color;
}

static int	ft_key_hook(int keycode, t_env *env)
{
	if (keycode == XK_Escape)
	{
		ft_free_env(&env);
		
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

static void	ft_draw_fdf(t_env *env)
{
	env->img.img = mlx_new_image(env->mlx, 1000, 1000);
	env->img.addr = mlx_get_data_addr(env->img.img, &env->img.bits_per_pixel, &env->img.line_length, &env->img.endian);
	ft_put_pixels(env);
	mlx_put_image_to_window(env->mlx, env->win, env->img.img, 0, 0);
}

// static int	ft_render(t_env *env)
// {
// 	(void)env;
// 	ft_printf("render\n");
// 	// ft_draw_fdf(env);
// 	// mlx_put_image_to_window(env->mlx, env->win, env->img.img, 0, 0);
// 	return (0);
// }

// static int	ft_close_cross(t_env *env)
// {
// 	ft_printf("Bye!\n");
// 	// ft_free_env(&env);
// 	mlx_destroy_window(env->mlx, env->win);
// 	// exit(1);
// 	return (0);
// }

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
	// mlx_hook(env->win, 17, 0, ft_close_cross, &env);
	// mlx_loop_hook(env->mlx, ft_render, &env);
	// ft_draw_fdf(env);
	mlx_key_hook(env->win, ft_key_hook, env);
	mlx_loop(env->mlx);
	return (0);
}
