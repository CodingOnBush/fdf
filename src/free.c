/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allblue <allblue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 13:42:49 by momrane           #+#    #+#             */
/*   Updated: 2024/01/20 10:35:43 by allblue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	ft_free_matrix(t_env *env)
{
	int	i;

	i = 0;
	while (i < env->data.row)
	{
		if (env->data.matrix[i])
			free(env->data.matrix[i]);
		i++;
	}
	free(env->data.matrix);
}

int	ft_free_mlx_ptr(t_env *env, int return_value)
{
	if (!(env->mlx_ptr))
	{
		mlx_destroy_display(env->mlx_ptr);
		free(env->mlx_ptr);
	}
	return (return_value);
}

int	ft_free_everything(t_env *env, int return_value)
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

void	ft_free_env(t_env *env)
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
