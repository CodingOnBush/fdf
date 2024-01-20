/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allblue <allblue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 09:27:43 by momrane           #+#    #+#             */
/*   Updated: 2024/01/20 12:01:15 by allblue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

static void	ft_print_matrix(t_env *env)
{
	int	r;
	int	c;

	r = 0;
	while (r < env->rows)
	{
		c = 0;
		while (c < env->cols)
		{
			ft_printf("%d ", env->map[r][c].z);
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
		ft_exit_error("./fdf <filename>");
	env.filename = av[1];
	if (ft_init_env(&env) < 0)
		return (ft_free_env_err(&env, "Error: mlx init failed"));
	if (ft_parse_map(&env))
		return (ft_free_env_err(&env, "Error: parsing failed"));
	ft_trigger_hooks(&env);
	ft_prep_img(&env);
	ft_draw(&env);
	mlx_loop(env.mlx_ptr);
	ft_free_env(&env);
	return (0);
}
