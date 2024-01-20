/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allblue <allblue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 13:42:49 by momrane           #+#    #+#             */
/*   Updated: 2024/01/20 12:01:27 by allblue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	*ft_free_matrix(t_pt **matrix, int rows)
{
	int	i;

	i = 0;
	while (i < rows)
	{
		if (matrix[i])
			free(matrix[i]);
		i++;
	}
	free(matrix);
	return (NULL);
}

void	ft_free_env(t_env *env)
{
	if (!env)
		return ;
	if (env->map)
		ft_free_matrix(env->map, env->rows);
	if (env->mat)
		ft_free_matrix(env->mat, env->rows);
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
}

int	ft_free_env_err(t_env *env, char *msg)
{
	ft_free_env(env);
	ft_printf("%s\n", msg);
	return (-1);
}
