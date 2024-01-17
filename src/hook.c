/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 13:37:37 by momrane           #+#    #+#             */
/*   Updated: 2024/01/17 13:06:18 by momrane          ###   ########.fr       */
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
	{
		env->scale += 1;
		mlx_clear_window(env->mlx_ptr, env->win_ptr);
		ft_draw(env);
	}
	return (0);
}

static int ft_mouse_hook(int button, int x, int y, t_env *env)
{
	ft_printf("button: %d\n", button);
	if (button == 4)
		env->scale += 10;
	else if (button == 5)
		env->scale -= 10;
	ft_printf("x: %d\n", x);
	ft_printf("y: %d\n", y);
	return (0);
}

void	ft_trigger_hooks(t_env *env)
{
	mlx_key_hook(env->win_ptr, ft_key_hook, env);//				keyboard
	mlx_mouse_hook(env->win_ptr, ft_mouse_hook, env);//			mouse
	mlx_hook(env->win_ptr, 2, 1L << 0, ft_escape_hook, env);//	XK_Escape
	mlx_hook(env->win_ptr, 17, 1L << 2, ft_cross_hook, env);//	window cross
}
