/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 13:37:37 by momrane           #+#    #+#             */
/*   Updated: 2024/01/15 13:54:38 by momrane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int	ft_cross_hook(t_env *env)
{
	ft_free_everything(env);
	exit(0);
	return (0);
}

int	ft_key_hook(int keycode, t_env *env)
{
	if (keycode == XK_Escape)
		ft_free_everything(env);
	exit(0);
	return (0);
}

void	ft_init_hooks(t_env *env)
{
	mlx_hook(env->win, 2, 1L << 0, ft_key_hook, env);
	mlx_hook(env->win, 17, 1L << 2, ft_cross_hook, env);
}
