/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allblue <allblue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 11:18:10 by momrane           #+#    #+#             */
/*   Updated: 2024/01/20 11:50:51 by allblue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

static int	ft_point_detected(t_env *env, char *line)
{
	int	i;

	i = 0;
	if (ft_strchr("+-", line[i]))
		i++;
	if (!ft_isdigit(line[i]))
		return (-1);
	env->map[env->r][env->c].x = env->c;
	env->map[env->r][env->c].y = env->r;
	env->map[env->r][env->c].z = ft_atoi(line);
	while (ft_isdigit(line[i]) && line[i] != '\0')
		i++;
	if (line[i] == ',')
	{
		i += 3;
		env->map[env->r][env->c].color = ft_get_color(&line[i]);
		while (ft_isdigit(line[i]) || ft_strchr("abcdefABCDEF", line[i]))
			i++;
	}
	else
		env->map[env->r][env->c].color = 0xFFFFFF;
	env->c++;
	return (i);
}

static int	ft_parse_line(t_env *env, char *line)
{
	int	step;

	step = 0;
	while(*line)
	{
		if (ft_isdigit(*line) || ft_strchr("+-", *line))
		{
			step = ft_point_detected(env, line);
			if (step < 0)
				return (-1);
			line += step;
		}
		else
			line++;
	}
	env->r++;
	env->c = 0;
	return (1);
}

static int	ft_parse(t_env *env)
{
	char		*line;
	int			fd;

	fd = open(env->filename, O_RDONLY);
	if (fd < 0)
		return (-1);
	while (1)
	{
		line = ft_gnl(fd);
		if (!line)
			break ;
		if (ft_parse_line(env, line) < 0)
		{
			free(line);
			close(fd);
			return (-1);
		}
		free(line);
	}
	close(fd);
	env->r = env->rows / 2;
	env->c = env->cols / 2;
	return (1);
}

int	ft_parse_map(t_env *env)
{
	if (env->map == NULL)
		return (-1);
	ft_init_map_sizes(env);
	if (env->rows == 0 || env->cols == 0)
		return (-1);
	if (ft_parse(env) < 0)
		return (-1);
	return (1);
}
