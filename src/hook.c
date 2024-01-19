/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 13:37:37 by momrane           #+#    #+#             */
/*   Updated: 2024/01/19 04:54:15 by momrane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

static int	ft_cross_hook(t_env *env)
{
	ft_free_everything(env);
	exit(0);
	return (0);
}

static int	ft_escape_hook(int keycode, t_env *env)
{
	if (keycode == XK_Escape)
	{
		ft_free_everything(env);
		exit(0);
	}
	return (0);
}

static int ft_key_hook(int keycode, t_env *env)
{
	(void)env;
	(void)keycode;
	// ft_printf("keycode: %d\n", keycode);
	return (0);
}

static int ft_mouse_hook(int button, int x, int y, t_env *env)
{
	ft_printf("button: %d\n", button);
	(void)x;
	(void)y;
	if (button == 4)
	{
		// env->altitude += 0.8;
		// env->space += 1;
		env->angle -= 1;
		ft_printf("angle: %d\n", env->angle);
		ft_draw(env);
	}
	else if (button == 5)
	{
		// env->altitude -= 0.8;
		// env->space -= 1;
		env->angle += 1;
		ft_printf("angle: %d\n", env->angle);
		ft_draw(env);
	}
	return (0);
}

void	ft_trigger_hooks(t_env *env)
{
	mlx_key_hook(env->win_ptr, ft_key_hook, env);
	mlx_mouse_hook(env->win_ptr, ft_mouse_hook, env);
	mlx_hook(env->win_ptr, 2, 1L << 0, ft_escape_hook, env);
	mlx_hook(env->win_ptr, 17, 1L << 2, ft_cross_hook, env);
}
