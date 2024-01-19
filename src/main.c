/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 09:27:43 by momrane           #+#    #+#             */
/*   Updated: 2024/01/19 03:04:56 by momrane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

static void	ft_print_matrix(t_env *env)
{
	int	r;
	int	c;

	r = 0;
	while (r < env->data.row)
	{
		c = 0;
		while (c < env->data.col)
		{
			ft_printf("%d ", env->data.matrix[r][c].z);
			c++;
		}
		ft_printf("\n");
		r++;
	}
}

int	main(int ac, char **av)
{
	t_parsing	data;
	t_env		env;

	if (ac != 2)
		ft_exit_error("Usage: ./fdf <filename>");
	data = ft_start_parsing(av[1]);
	env = ft_init_env(data);
	ft_trigger_hooks(&env);
	ft_prep_img(&env);
	ft_draw(&env);
	mlx_loop(env.mlx_ptr);
	ft_free_everything(&env);
	return (0);
}
