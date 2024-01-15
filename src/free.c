/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 13:42:49 by momrane           #+#    #+#             */
/*   Updated: 2024/01/15 13:25:13 by momrane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	ft_free_points(t_point **lst)
{
	t_point	*tmp;

	while (*lst)
	{
		tmp = (*lst)->next;
		free(*lst);
		*lst = tmp;
	}
}

void	ft_free_everything(t_env *env)
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
		if (env->lst != NULL)
			ft_free_points(&env->lst);
		free(env);
	}
}
