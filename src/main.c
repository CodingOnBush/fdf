/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 09:27:43 by momrane           #+#    #+#             */
/*   Updated: 2024/01/18 20:29:12 by momrane          ###   ########.fr       */
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
	ft_printf("row = %d, col = %d\n", env.data.row, env.data.col);
	ft_printf("r = %d, c = %d\n", env.data.r, env.data.c);
	
	env = ft_init_env(data);
	
	ft_trigger_hooks(&env);
	ft_prep_img(&env);
	ft_draw(&env);
	
	mlx_loop(env.mlx_ptr);
	ft_free_everything(&env);
	return (0);
}
