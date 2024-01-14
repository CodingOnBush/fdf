/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 09:27:43 by momrane           #+#    #+#             */
/*   Updated: 2024/01/14 15:23:07 by momrane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

// static void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
// 	*(unsigned int *)dst = color;
// }

int	key_hook(int keycode, t_env *env)
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

int	main(int ac, char **av)
{
	t_env	*env;

	if (ft_init_env(&env, ac, av) == 0)
		ft_error("Error: init failed");
	env->mlx = mlx_init();
	if (!(env->mlx))
	{
		ft_free_env(&env);
		ft_error("Error: mlx_init failed");
	}
	env->win = mlx_new_window(env->mlx, 500, 500, "Hello world!");
	if (!(env->win))
	{
		mlx_destroy_display(env->mlx);
		ft_free_env(&env);
		ft_error("Error: mlx_new_window failed");
	}
	mlx_key_hook(env->win, key_hook, env);
	mlx_loop(env->mlx);
	return (0);
}
