/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allblue <allblue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 13:37:37 by momrane           #+#    #+#             */
/*   Updated: 2024/01/20 11:59:15 by allblue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

static int	ft_win_cross(t_env *env)
{
	ft_free_all(env);
	exit(0);
	return (0);
}

static int ft_key_hook(int keycode, t_env *env)
{
	(void)env;
	(void)keycode;
	ft_printf("keycode: %d\n", keycode);
	if (keycode == XK_Right)
	{
		env->angle += 0.1;
		ft_printf("right\n");
		ft_draw(env);
	}
	else if (keycode == XK_Left)
	{
		env->angle -= 0.1;
		ft_printf("left\n");
		ft_draw(env);
	}
	else if (keycode == XK_Down)
	{
		env->altitude -= 0.1;
		ft_printf("down\n");
		ft_draw(env);
	}
	else if (keycode == XK_Up)
	{
		env->altitude += 0.1;
		ft_printf("up\n");
		ft_draw(env);
	}
	if (keycode == XK_Escape)
	{
		ft_free_env(env);
		exit(0);
	}
	return (0);
}

static int ft_mouse_hook(int button, int x, int y, t_env *env)
{
	ft_printf("button: %d\n", button);
	(void)x;
	(void)y;
	if (button == 4)
	{
		// env->altitude += 0.2;
		// env->space += 1;
		env->angle -= 0.1;
		// ft_printf("angle: %d\n", env->angle);
		ft_draw(env);
	}
	else if (button == 5)
	{
		// env->altitude -= 0.2;
		// env->space -= 1;
		env->angle += 0.1;
		// ft_printf("angle: %d\n", env->angle);
		ft_draw(env);
	}
	return (0);
}

void	ft_trigger_hooks(t_env *env)
{
	mlx_key_hook(env->win_ptr, ft_key_hook, env);
	mlx_mouse_hook(env->win_ptr, ft_mouse_hook, env);
	mlx_hook(env->win_ptr, 17, 1L << 2, ft_win_cross, env);
}
