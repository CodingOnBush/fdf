/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 13:37:37 by momrane           #+#    #+#             */
/*   Updated: 2024/01/21 12:34:11 by momrane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

static int	ft_win_cross(t_env *env)
{
	ft_free_env(env);
	exit(0);
	return (0);
}

static int ft_key_hook(int keycode, t_env *env)
{
	if (keycode == XK_Right)
	{
		env->angle -= 0.2;
		printf("[➡️]new angle: %.3f\n", env->angle);
		ft_draw(env);
	}
	else if (keycode == XK_Left)
	{
		env->angle += 0.2;
		printf("[⬅️]new angle: %.3f\n", env->angle);
		ft_draw(env);
	}
	else if (keycode == XK_Down)
	{
		env->altitude -= 0.2;
		printf("[⬇️]new altitude: %.3f\n", env->altitude);
		ft_draw(env);
	}
	else if (keycode == XK_Up)
	{
		env->altitude += 0.2;
		printf("[⬆️]new altitude: %.3f\n", env->altitude);
		ft_draw(env);
	}
	else if (keycode == XK_w)
	{
		env->origin.y -= 100;
		printf("[🔼]new origin: (%d, %d)\n", env->origin.x, env->origin.y);
		ft_draw(env);
	}
	else if (keycode == XK_s)
	{
		env->origin.y += 100;
		printf("[🔽]new origin: (%d, %d)\n", env->origin.x, env->origin.y);
		ft_draw(env);
	}
	else if (keycode == XK_a)
	{
		env->origin.x -= 50;
		printf("[◀️]new origin: (%d, %d)\n", env->origin.x, env->origin.y);
		ft_draw(env);
	}
	else if (keycode == XK_d)
	{
		env->origin.x += 50;
		printf("[▶️]new origin: (%d, %d)\n", env->origin.x, env->origin.y);
		ft_draw(env);
	}
	else if (keycode == XK_Escape)
	{
		ft_free_env(env);
		exit(0);
	}
	return (0);
}

static int ft_mouse_hook(int button, int x, int y, t_env *env)
{
	// ft_printf("button: %d\n", button);
	(void)x;
	(void)y;
	if (button == 4)
	{
		env->space += 1;
		printf("new space: %d\n", env->space);
		ft_draw(env);
	}
	else if (button == 5)
	{
		env->space -= 1;
		printf("new space: %d\n", env->space);
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
