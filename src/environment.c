/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allblue <allblue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:28:38 by momrane           #+#    #+#             */
/*   Updated: 2024/01/20 11:56:50 by allblue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

static int	ft_init_map_sizes(t_env *env)
{
	char	*line;
	int		fd;

	if (env->filename == NULL)
		return (-1);
	fd = open(env->filename, O_RDONLY);
	if (fd < 0)
		return (-1);
	line = ft_gnl(fd);
	if (!line)
		return (-1);
	env->cols = ft_count_cols(line);
	while (line)
	{
		env->rows++;
		free(line);
		line = ft_gnl(fd);
	}
	close(fd);
	return (1);
}

static void	ft_init_values(t_env *env)
{
	env->width = 1200;
	env->height = 800;
	env->angle = 5;
	env->zoom = 20;
	env->altitude = 1.3;
	env->scale = 0.7;
	env->space = 20;
	env->origin.x = env->width / 2;
	env->origin.y = env->height / 2;
}

int	ft_init_env(t_env *env)
{
	ft_init_values(env);
	ft_init_map_sizes(env);
	env->mlx_ptr = mlx_init();
	if (!env->mlx_ptr)
		return (-1);
	env->win_ptr = mlx_new_window(env->mlx_ptr, env->width, env->height, "FDF");
	if (!env->win_ptr)
		return (-1);
	env->mat = ft_new_matrix(env->rows, env->cols);
	if (!env->mat)
		return (-1);
	env->map = ft_new_matrix(env->rows, env->cols);
	if (!env->map)
		return (-1);
	if (ft_init_map_sizes(env) < 0)
		return (-1);
	return (1);
}
