/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 11:18:10 by momrane           #+#    #+#             */
/*   Updated: 2024/01/12 15:17:37 by momrane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

static int	ft_count_lines(char *file)
{
	char	*line;
	int		fd;
	int		out;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (0);
	out = 0;
	while (1)
	{
		line = ft_gnl(fd);
		if (!line)
			break ;
		out++;
		free(line);
	}
	close(fd);
	ft_printf("row number : %d\n", out);
	return (out);
}

// t_point	**ft_new_map(char *file)
// {
// 	t_point	**new_map;
// 	int		row;

// 	row = ft_count_lines(file);
// 	if (row == 0)
// 		return (NULL);
// 	new_map = (t_point **)malloc((row + 1) * sizeof(t_point *));
// 	if (!new_map)
// 		return (NULL);
// 	new_map[row] = NULL;
// 	return (new_map);
// }

// static int	ft_atoi_base(char *str, int base)
// {
// 	int	out;
// 	int	sign;

// 	out = 0;
// 	sign = 1;
// 	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\v'
// 		|| *str == '\f' || *str == '\r')
// 		str++;
// 	if (*str == '-')
// 		sign = -1;
// 	if (*str == '-' || *str == '+')
// 		str++;
// 	if (base == 16 && *str == '0' && *(str + 1) == 'x')
// 		str += 2;
// 	while ((*str >= '0' && *str <= '9') || (*str >= 'A' && *str <= 'F')
// 		|| (*str >= 'a' && *str <= 'f'))
// 	{
// 		if (*str >= '0' && *str <= '9')
// 			out = out * base + *str - '0';
// 		else if (*str >= 'A' && *str <= 'F')
// 			out = out * base + *str - 'A' + 10;
// 		else if (*str >= 'a' && *str <= 'f')
// 			out = out * base + *str - 'a' + 10;
// 		str++;
// 	}
// 	return (out * sign);
// }

// static void	ft_fill_row(int row, t_point **map, char *line)
// {
// 	char	**split;
// 	int		j;

// 	split = ft_split(line, ' ');
// 	if (!split)
// 		return ;
// 	map[row] = (t_point *)malloc(ft_strlen(split[0]) * sizeof(t_point));
// 	if (!(map[row]))
// 		return ;
// 	j = 0;
// 	while (split[j])
// 	{
// 		map[row][j].x = j;
// 		map[row][j].y = row;
// 		map[row][j].z = ft_atoi(split[j]);
// 		if (ft_strchr(split[j], ',') != NULL)
// 			map[row][j].color = ft_atoi_base(ft_strchr(split[j], ',') + 1, 16);
// 		else
// 			map[row][j].color = 0xFFFFFF;
// 		j++;
// 	}
// }

// static t_point	**ft_read_map(char *file)
// {
// 	char	*line;
// 	int		fd;
// 	t_point	**map;
// 	int		row;

// 	fd = open(file, O_RDONLY);
// 	if (fd < 0)
// 		return (NULL);
// 	map = ft_new_map(file);
// 	if (!map)
// 		return (NULL);
// 	row = 0;
// 	while (1)
// 	{
// 		line = ft_gnl(fd);
// 		if (!line)
// 			break ;
// 		ft_fill_row(row, map, line);
// 		row++;
// 		free(line);
// 	}
// 	close(fd);
// 	return (NULL);
// }

static int	ft_count_words(const char *str, char sep)
{
	int	out;

	out = 0;
	while (*str)
	{
		while (*str == sep)
			str++;
		if (*str != sep && *str != '\0' && *str != '\n')
			out++;
		while (*str != sep && *str != '\0')
			str++;
	}
	return (out);
}

static int	ft_count_max_col(char *file)
{
	char	*line;
	int		fd;
	int		out;
	int		tmp;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (0);
	out = 0;
	while (1)
	{
		line = ft_gnl(fd);
		if (!line)
			break ;
		tmp = ft_count_words(line, ' ');
		if (tmp > out)
			out = tmp;
		free(line);
	}
	close(fd);
	ft_printf("col number : %d\n", out);
	return (out);
}

static void	ft_init_sizes(t_env **env)
{
	char	*line;
	int		fd;
	int		col;
	int		tmp;
	int		row;

	fd = open((*env)->filename , O_RDONLY);
	if (fd < 0)
		return ;
	col = 0;
	row = 0;
	while (row++ > 0)
	{
		line = ft_gnl(fd);
		if (!line)
			break ;
		tmp = ft_count_words(line, ' ');
		if (tmp > col)
			col = tmp;
		free(line);
	}
	close(fd);
	(*env)->row = row;
	(*env)->col = col;
}

int	ft_init_env(t_env **env)
{
	ft_init_sizes(env);
	ft_printf("row : %d\n", (*env)->row);
	ft_printf("col : %d\n", (*env)->col);
	(*env)->map = NULL;
	return (1);
}
