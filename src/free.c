/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 13:42:49 by momrane           #+#    #+#             */
/*   Updated: 2024/01/18 17:22:41 by momrane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

static void	ft_free_matrix(t_env *env)
{
	int	i;

	i = 0;
	while (i < env->data.row)
	{
		free(env->data.matrix[i]);
		i++;
	}
	free(env->data.matrix);
}

void	ft_free_everything(t_env *env)
{
	if (env)
	{
		if (env->mlx_ptr)
		{
			if (env->win_ptr)
			{
				if (env->img.img_ptr != NULL)
					mlx_destroy_image(env->mlx_ptr, env->img.img_ptr);
				mlx_clear_window(env->mlx_ptr, env->win_ptr);
				mlx_destroy_window(env->mlx_ptr, env->win_ptr);
			}
			mlx_destroy_display(env->mlx_ptr);
			free(env->mlx_ptr);
		}
		if (env->data.matrix)
			ft_free_matrix(env);
	}
}
