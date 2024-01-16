/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 14:49:37 by momrane           #+#    #+#             */
/*   Updated: 2024/01/16 10:36:36 by momrane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	ft_exit_error(char *str)
{
	ft_printf("Error: %s\n", str);
	exit(0);
}

void	ft_free_parsing(t_parsing *data)
{
	int	i;

	i = 0;
	if (data != NULL)
	{
		if (data->points != NULL)
		{
			while (i < data->max_row)
			{
				if (data->points[i] == NULL)
					break;
				free(data->points[i]);
				i++;
			}
			free(data->points);
		}
	}
}
