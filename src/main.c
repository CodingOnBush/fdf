/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 09:27:43 by momrane           #+#    #+#             */
/*   Updated: 2024/01/15 10:38:43 by momrane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

// static void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
// {
// 	int	offset;

// 	//🚨 Line len is in bytes. WIDTH 800 len_line ~3200 (can differ for alignment)
// 	offset = (img->line_length * y) + (x * (img->bits_per_pixel / 8));

// 	*((unsigned int *)(offset + img->addr)) = color;
// 	// char	*dst;

// 	// dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel
// / 8));
// 	// *(unsigned int *)dst = color;
// }

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

// static void	ft_put_pixels(t_env *env)
// {
// 	t_point	*tmp;

// 	tmp = env->lst;
// 	while (tmp)
// 	{
// 		my_mlx_pixel_put(&env->img, (tmp->x)*10, (tmp->y)*10, 0x00FFFFFF);
// 		tmp = tmp->next;
// 	}
// }

// static void	ft_draw_fdf(t_env *env)
// {
// 	// put pixels
// 	// draw lines
// 	(void)env;
// }

// static int	ft_render(t_env *env)
// {
// 	ft_draw_fdf(env);
// 	mlx_put_image_to_window(env->mlx, env->win, env->img.img, 0, 0);
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
	mlx_key_hook(env->win, ft_key_hook, env);
	mlx_loop(env->mlx);
	return (0);
}
