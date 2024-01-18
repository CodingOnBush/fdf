/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 09:27:43 by momrane           #+#    #+#             */
/*   Updated: 2024/01/18 11:24:25 by momrane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

static void	ft_print_matrix(t_env *env)
{
	int	i;
	int	j;

	i = 0;
	while (i < env->data.row)
	{
		j = 0;
		while (j < env->data.col)
		{
			ft_printf("[x: %d, y: %d]", env->data.matrix[i][j].x, env->data.matrix[i][j].y);
			j++;
		}
		ft_printf("\n");
		i++;
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
	// ft_print_matrix(&env);
	// ft_print_matrix(&env);
	ft_prep_img(&env);
	// mlx_loop_hook(env.mlx_ptr, ft_draw, &env);
	ft_draw(&env);
	mlx_loop(env.mlx_ptr);
	return (0);
}
