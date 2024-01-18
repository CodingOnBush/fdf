/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 13:37:37 by momrane           #+#    #+#             */
/*   Updated: 2024/01/18 18:04:35 by momrane          ###   ########.fr       */
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
	ft_printf("keycode: %d\n", keycode);
	if (keycode == 65293)
		env->scale += 1;
	return (0);
}

static int ft_mouse_hook(int button, int x, int y, t_env *env)
{
	ft_printf("button: %d\n", button);
	(void)x;
	(void)y;
	if (button == 4)
	{
		env->scale += 0.1;
		ft_draw(env);
	}
	else if (button == 5)
	{
		env->scale -= 0.1;
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
