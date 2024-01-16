/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 11:18:10 by momrane           #+#    #+#             */
/*   Updated: 2024/01/16 12:08:23 by momrane          ###   ########.fr       */
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

static void	ft_reset_env(t_env **env)
{
	(*env)->mlx = NULL;
	(*env)->win = NULL;
	(*env)->row = 0;
	(*env)->col = 0;
	(*env)->width = 1526; // 1920 * 0.8
	(*env)->height = 864; // 1080 * 0.8
	(*env)->lst = NULL;
	(*env)->img.img_ptr = NULL;
	(*env)->img.img_pixels_ptr = NULL;
	(*env)->img.bits_per_pixel = 0;
	(*env)->img.endian = 0;
	(*env)->img.line_len = 0;
}

void	ft_init_env(t_env **env, int ac, char **av)
{
	if (ac != 2)
		ft_exit_error("wrong nb of arg");
	*env = (t_env *)malloc(sizeof(t_env));
	if (!(*env))
		ft_exit_error("env malloc failed");
	ft_reset_env(env);
	(*env)->filename = av[1];
	ft_create_points(env);
	if (!(*env)->lst)
	{
		ft_free_everything(*env);
		ft_exit_error("Error: parsing failed");
	}
	(*env)->mlx = mlx_init();
	if (!((*env)->mlx))
	{
		ft_free_everything(*env);
		ft_exit_error("Error: mlx_init failed");
	}
	(*env)->win = mlx_new_window((*env)->mlx, (*env)->width, (*env)->height,
			"Hello world!");
	if (!((*env)->win))
	{
		ft_free_everything(*env);
		ft_exit_error("Error: mlx_new_window failed");
	}
}

// static int	ft_power(int nb, int power)
// {
// 	int	i;
// 	int	result;

// 	i = 0;
// 	result = 1;
// 	while (i < power)
// 	{
// 		result *= nb;
// 		i++;
// 	}
// 	return (result);
// }

static void	ft_init_parsing(t_parsing *data)
{
	data->matrix = NULL;
	data->row = 0;
	data->col = 0;
	data->filename = NULL;
}

// static void	ft_point_detected(t_parsing *data, char *line)
// {
// 	int r;
// 	int c;

// 	c = data->col_cursor;
// 	r = data->row_cursor;
// 	data->max_col++;
// 	if (data->points[r] == NULL)
// 		ft_extend_cols(data);
// 	data->points[r][c].x = c;
// 	data->points[r][c].y = c;
// 	data->points[r][c].z = ft_atoi(line);
// 	if (ft_strchr("+-", *line))
// 		line++;
// 	while (ft_isdigit(*line))
// 		line++;
// 	if (*line == ',')
// 	{
// 		line += 3;
// 		data->points[r][c].color = ft_get_color(line);
// 		while (ft_isdigit(*line) || ft_strchr("abcdefABCDEF", *line))
// 			line++;
// 	}
// 	else
// 		data->points[r][c].color = 0x00FF00;
// 	data->col_cursor++;
// 	while (*line == ' ')
// 		line++;
// }

// static void	ft_parse_line(t_parsing *data, char *line)
// {
// 	if (!line)
// 		return ;
// 	ft_extend_rows(data);
// 	ft_extend_cols(data);
// 	while(*line)
// 	{
// 		if (ft_isdigit(*line) || ft_strchr("+-", *line))
// 			ft_point_detected(data, line);
// 		if (*line == '\0')
// 		{
// 			data->row_cursor++;
// 			data->col_cursor = 0;
// 		}
// 	}
// }

// static void ft_cut_unused(t_parsing *data)
// {
// 	(void)data;
// }

static int	ft_count_col(char *line)
{
	int	col;

	col = 0;
	while (*line)
	{
		if (ft_isdigit(*line) || ft_strchr("+-", *line))
		{
			col++;
			if (ft_strchr("+-", *line))
				line++;
			while (ft_isdigit(*line) || *line == ',')
				line++;
		}
		else
			line++;
	}
	return (col);
}

static void	ft_set_matrix_size(t_parsing *data)
{
	char	*line;
	int		fd;

	fd = open(data->filename, O_RDONLY);
	if (fd < 0)
		ft_exit_error("Error: open failed");
	line = ft_gnl(fd);
	if (!line)
		ft_exit_error("Error: empty file");
	data->col = ft_count_col(line);
	while (line)
	{
		data->row++;
		free(line);
		line = ft_gnl(fd);
	}
	close(fd);
}

void	ft_start_parsing(int ac, char **av)
{
	t_parsing	data;
	int			fd;
	char		*line;

	if (ac != 2)
		ft_exit_error("wrong nb of arg");
	ft_init_parsing(&data);
	data.filename = av[1];
	ft_set_matrix_size(&data);
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		ft_exit_error("Error: open failed");
	while (1)
	{
		line = ft_gnl(fd);
		if (!line)
			break ;
		ft_printf("%s", line);
		free(line);
	}
	close(fd);
	ft_printf("\nrow: %d\ncol: %d\n", data.row, data.col);
}
