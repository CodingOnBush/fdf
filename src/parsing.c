/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 11:18:10 by momrane           #+#    #+#             */
/*   Updated: 2024/01/14 15:51:40 by momrane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

static int	ft_get_color(char *str)
{
	char	*substr;
	int		i;
	int		nb;

	nb = 0;
	i = 0;
	substr = ft_strchr(str, ',');
	if (substr == NULL)
		return (0);
	substr++;
	while (substr[i])
	{
		if (substr[i] >= 'A' && substr[i] <= 'F')
			nb = nb * 16 + (substr[i] - 'A' + 10);
		else if (substr[i] >= 'a' && substr[i] <= 'f')
			nb = nb * 16 + (substr[i] - 'a' + 10);
		else
			nb = nb * 16 + (substr[i] - '0');
		i++;
	}
	return (nb);
}

static int	ft_handle_line(char *line, int row, t_env **env)
{
	char	**split;
	t_point	*new;
	int		col;
	int		z;

	split = ft_split(line, ' ');
	if (!split)
		return (0);
	col = 0;
	while (split[col] && ft_strchr(split[col], '\n') == NULL)
	{
		z = ft_atoi(split[col]);
		new = ft_new_point(col, row, z, ft_get_color(split[col]));
		if (!new)
			return (0);
		ft_add_point(&(*env)->lst, new);
		col++;
	}
	col = 0;
	while (split[col])
		free(split[col++]);
	free(split);
	(*env)->col = col;
	return (1);
}

static void	ft_create_points(t_env **env)
{
	char	*line;
	int		row;
	int		fd;

	fd = open((*env)->filename, O_RDONLY);
	if (fd < 0)
		return ;
	(*env)->lst = NULL;
	row = 0;
	while (1)
	{
		line = ft_gnl(fd);
		if (!line)
			break ;
		if (ft_handle_line(line, row, env) == 0)
		{
			ft_free_points(&(*env)->lst);
			return ;
		}
		row++;
		free(line);
	}
	(*env)->row = row;
	close(fd);
}

int	ft_init_env(t_env **env, int ac, char **av)
{
	if (ac != 2)
		return (0);
	*env = (t_env *)malloc(sizeof(t_env));
	if (!(*env))
		return (0);
	(*env)->filename = av[1];
	ft_create_points(env);
	if (!(*env)->lst)
		return (0);
	return (1);
}
