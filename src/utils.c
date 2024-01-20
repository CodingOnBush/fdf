/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 15:23:27 by momrane           #+#    #+#             */
/*   Updated: 2024/01/20 18:39:06 by momrane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int	ft_count_cols(char *line)
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

int	ft_get_color(char *str)
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

void	ft_set_space(t_env *env)
{
	t_pt	top_rigth;
	// int	refx;
	// int	refy;
	int		space;

	// refx = env->width - 100;
	// refy = 100;
	
	// if (refx )

	top_rigth = ft_get_converted_point(env, env->rows - 1, env->cols - 1);
	space = (env->width - top_rigth.x) / (env->cols + env->rows);
	ft_printf("SPAACE = %d\n", space);
	if (space < 1)
		space = 1;
	env->space = 20;
}
