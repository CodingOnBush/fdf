/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 09:27:43 by momrane           #+#    #+#             */
/*   Updated: 2024/01/15 12:29:16 by momrane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

static void	ft_free_everything(t_env *env)
{
	if (env)
	{
		if (env->mlx)
		{
			if (env->win)
				mlx_destroy_window(env->mlx, env->win);
			if (env->img != NULL && env->img->img)
				mlx_destroy_image(env->mlx, env->img->img);
			mlx_destroy_display(env->mlx);
			free(env->mlx);
		}
		if (env->lst)
			ft_free_points(&env->lst);
		free(env);
	}
}

static int	ft_cross_pressed(t_env *env)
{
	ft_free_everything(env);
	exit(0);
	return (0);
}

static int	ft_key_hook(int keycode, t_env *env)
{
	ft_printf("keycode: %d\n", keycode);
	if (keycode == XK_Escape)
		ft_free_everything(env);
	exit(0);
	return (0);
}

int	main(int ac, char **av)
{
	t_env	*env;

	if (ft_init_env(&env, ac, av) == 0)
		ft_error("Error: init failed");
	ft_printf("row: %d\ncol: %d\n", env->row, env->col);
	env->mlx = mlx_init();
	if (!(env->mlx))
	{
		ft_free_everything(env);
		ft_error("Error: mlx_init failed");
	}
	env->win = mlx_new_window(env->mlx, 1000, 1000, "Hello world!");
	if (!(env->win))
	{
		ft_free_everything(env);
		ft_error("Error: mlx_new_window failed");
	}
	mlx_hook(env->win, 2, 1L << 0, ft_key_hook, env);
	mlx_hook(env->win, 17, 1L << 2, ft_cross_pressed, env);
	mlx_loop(env->mlx);
	ft_free_everything(env);
	return (0);
}
