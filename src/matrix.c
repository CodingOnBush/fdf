/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 16:06:22 by momrane           #+#    #+#             */
/*   Updated: 2024/01/19 16:25:19 by momrane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

t_pt	**ft_new_matrix(int r, int c)
{
	t_pt	**new;
	int		i;

	i = 0;
	new = (t_pt **)malloc(sizeof(t_pt *) * r);
	while (i < r)
	{
		new[i] = (t_pt *)malloc(sizeof(t_pt) * c);
		i++;
	}
	return (new);
}

void	ft_print_point(t_env *env, int r, int c)
{
	ft_printf("[x: %d, y: %d]", env->data.matrix[r][c].x, env->data.matrix[r][c].y);
	if (c == env->data.col - 1)
		ft_printf("\n");
}

void	ft_parse_matrix(t_env *env, void (*f)(t_env *env, int r, int c))
{
	int	r;
	int	c;

	r = 0;
	while (r < env->data.row)
	{
		c = 0;
		while (c < env->data.col)
		{
			f(env, r, c);
			c++;
		}
		r++;
	}
}
