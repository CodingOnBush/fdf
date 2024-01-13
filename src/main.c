/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 09:27:43 by momrane           #+#    #+#             */
/*   Updated: 2024/01/13 14:04:13 by momrane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

static void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

// static void ft_print_square(t_data *data, int x, int y, int size)
// {
// 	int i;
// 	int j;

// 	i = 0;
// 	while (i < size)
// 	{
// 		j = 0;
// 		while (j < size)
// 			my_mlx_pixel_put(data, x + j++, y + i, 0x00FF0000);
// 		i++;
// 	}
// }

// static void ft_print_circle(t_data *data, int x, int y, int size)
// {
// 	int i;
// 	int j;

// 	i = 0;
// 	while (i < size)
// 	{
// 		j = 0;
// 		while (j < size)
// 		{
// 			if ((i - size / 2) * (i - size / 2) + (j - size / 2) * (j - size
// / 2) <= (size / 2) * (size / 2))
// 				my_mlx_pixel_put(data, x + j, y + i, 0x00FF0000);
// 			j++;
// 		}
// 		i++;
// 	}
// }

// static void	ft_print_points(t_env *env)//TODO: remove this function
// {
// 	t_point	*tmp;

// 	tmp = env->lst;
// 	while (tmp)
// 	{
// 		ft_printf("x: %d, y: %d, z: %d, color: %d\n", tmp->x, tmp->y, tmp->z,
// tmp->color);
// 		tmp = tmp->next;
// 	}
// }

int	main(int ac, char **av)
{
	t_env	*env;
	// t_data	*img;

	if (ac != 2)
		return (ft_printf("Usage: ./fdf <filename>\n"));
	env = (t_env *)malloc(sizeof(t_env));
	if (!env)
		ft_error("Error: malloc failed");
	if (ft_init_env(&env, av[1]) == 0)
		ft_error("Error: invalid map");
	// env->mlx = mlx_init();
	// env->win = mlx_new_window(env->mlx, 500, 500, "Hello world!");
	// img = (t_data *)malloc(sizeof(t_data));
	// if (!img)
	// {
	// 	ft_free_env(&env);
	// 	ft_error("Error: malloc failed");
	// }
	// img->img = mlx_new_image(env->mlx, 500, 500);
	// img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
	// 		&img->line_length, &img->endian);
	// my_mlx_pixel_put(img, 5, 5, 0x00FF0000);
	// mlx_put_image_to_window(env->mlx, env->win, img->img, 0, 0);
	// mlx_loop(env->mlx);
	ft_free_env(&env);
	return (0);
}
