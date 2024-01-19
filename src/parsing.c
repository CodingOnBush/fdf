/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 11:18:10 by momrane           #+#    #+#             */
/*   Updated: 2024/01/19 01:47:02 by momrane          ###   ########.fr       */
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

static int	ft_point_detected(t_parsing *data, char *line)
{
	int	i;

	i = 0;
	if (ft_strchr("+-", line[i]))
		i++;
	data->matrix[data->r][data->c].x = data->c;
	data->matrix[data->r][data->c].y = data->r;
	data->matrix[data->r][data->c].z = ft_atoi(line);
	while (ft_isdigit(line[i]) && line[i] != '\0')
		i++;
	if (line[i] == ',')
	{
		i += 3;
		data->matrix[data->r][data->c].color = ft_get_color(&line[i]);
		while (ft_isdigit(line[i]) || ft_strchr("abcdefABCDEF", line[i]))
			i++;
	}
	else
		data->matrix[data->r][data->c].color = 65280;
	data->c++;
	return (i);
}

static void	ft_parse_line(t_parsing *data, char *line)
{
	int	step;

	step = 0;
	while(*line)
	{
		if (ft_isdigit(*line) || ft_strchr("+-", *line))
		{
			step = ft_point_detected(data, line);
			line += step;
		}
		else
			line++;
	}
	data->r++;
	data->c = 0;
}

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

	if (data->filename == NULL)
		ft_exit_error("Error: no file");
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

static void	*ft_free_rows(t_pt **matrix, int i)
{
	while (i > 0)
	{
		i--;
		free(matrix[i]);
	}
	free(matrix);
	exit(1);
}

static void	ft_malloc_matrix(t_parsing *data)
{
	int	i;

	if (data->matrix != NULL)
		return ;
	ft_set_matrix_size(data);
	data->matrix = (t_pt **)malloc(sizeof(t_pt *) * data->row);
	if (!(data->matrix))
		ft_exit_error("Error: malloc failed");
	i = 0;
	while (i < data->row)
	{
		data->matrix[i] = (t_pt *)malloc(sizeof(t_pt) * data->col);
		if (!(data->matrix[i]))
			ft_free_rows(data->matrix, i);
		i++;
	}
}

static void	ft_init_parsing(t_parsing *data, char *filename)
{
	data->matrix = NULL;
	data->row = 0;
	data->col = 0;
	data->r = 0;
	data->c = 0;
	data->filename = filename;
	ft_malloc_matrix(data);
}

t_parsing	ft_start_parsing(char *filename)
{
	t_parsing 	data;
	int			fd;
	char		*line;

	ft_init_parsing(&data, filename);
	fd = open(data.filename, O_RDONLY);
	if (fd < 0)
		ft_exit_error("Error: open failed");
	while (1)
	{
		line = ft_gnl(fd);
		if (!line)
			break ;
		// ft_printf("%s", line);
		ft_parse_line(&data, line);
		free(line);
	}
	close(fd);
	data.r = data.row / 2;
	data.c = data.col / 2;
	return (data);
}
