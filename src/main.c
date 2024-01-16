/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 09:27:43 by momrane           #+#    #+#             */
/*   Updated: 2024/01/16 15:34:13 by momrane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int	main(int ac, char **av)
{
	t_parsing	data;
	t_env		env;

	if (ac != 2)
		ft_exit_error("Usage: ./fdf <filename>");
	data = ft_start_parsing(av[1]);
	env = ft_init_env(data);
	ft_trigger_hooks(&env);
	mlx_loop_hook(env.mlx_ptr, ft_draw, &env);
	mlx_loop(env.mlx_ptr);
	return (0);
}
