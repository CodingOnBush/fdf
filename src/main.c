/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 09:27:43 by momrane           #+#    #+#             */
/*   Updated: 2024/01/20 17:13:17 by momrane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int	main(int ac, char **av)
{
	t_env		env;

	if (ac != 2)
		ft_exit_error("./fdf <filename>");
	if (ft_init_env(&env, av[1]) < 0)
		return (ft_free_env_err(&env, "Error: init failed"));
	if (ft_parse_map(&env) < 0)
		return (ft_free_env_err(&env, "Error: parsing failed"));
	ft_trigger_hooks(&env);
	ft_draw(&env);
	mlx_loop(env.mlx_ptr);
	ft_free_env(&env);
	return (0);
}
