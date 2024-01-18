/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 16:06:22 by momrane           #+#    #+#             */
/*   Updated: 2024/01/18 16:11:12 by momrane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	ft_print_point(t_env *env, int i, int j)
{
	ft_printf("[x: %d, y: %d]", env->data.matrix[i][j].x, env->data.matrix[i][j].y);
	if (j == env->data.col - 1)
		ft_printf("\n");
}

void	ft_parse_matrix(t_env *env, void (*f)(t_env *env, int i, int j))
{
	int	i;
	int	j;

	i = 0;
	while (i < env->data.row)
	{
		j = 0;
		while (j < env->data.col)
		{
			f(env, i, j);
			j++;
		}
		i++;
	}
}
