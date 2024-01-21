/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 15:23:27 by momrane           #+#    #+#             */
/*   Updated: 2024/01/21 12:36:31 by momrane          ###   ########.fr       */
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
			while (ft_isdigit(*line) || ft_strchr(",xabcdefABCDEF", *line))
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
	// t_pt	topleft;
	// t_pt	topright;
	// t_pt	botleft;
	// t_pt	botright;

	// topleft = (t_pt){50, 50, 0, 0xFFFFFF};
	// topright = (t_pt){50, env->width - 50, 0, 0xFFFFFF};
	// botleft = (t_pt){env->height - 50, 50, 0, 0xFFFFFF};
	// botright = (t_pt){env->height - 50, env->width - 50, 0, 0xFFFFFF};

	env->space = (env->width - 100) / (env->cols - 1);
	if (env->space > (env->height - 100) / (env->rows - 1))
		env->space = (env->height - 100) / (env->rows - 1);
	printf("SPACE : %d\n", env->space);
}
