/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 09:27:43 by momrane           #+#    #+#             */
/*   Updated: 2024/01/12 15:16:10 by momrane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

// static void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
// 	*(unsigned int*)dst = color;
// }

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
// 			if ((i - size / 2) * (i - size / 2) + (j - size / 2) * (j - size / 2) <= (size / 2) * (size / 2))
// 				my_mlx_pixel_put(data, x + j, y + i, 0x00FF0000);
// 			j++;
// 		}
// 		i++;
// 	}
// }

// static void	ft_trace_line(t_data *data, int x1, int y1, int x2, int y2)
// {
// 	int		dx;
// 	int		dy;
// 	int		x;
// 	int		y;
// 	int		i;

// 	dx = x2 - x1;
// 	dy = y2 - y1;
// 	x = x1;
// 	y = y1;
// 	i = 0;
// 	while (i <= dx)
// 	{
// 		my_mlx_pixel_put(data, x, y, 0x00FF0000);
// 		x++;
// 		y = y1 + dy * (x - x1) / dx;
// 		i++;
// 	}
// }

// static void	ft_print_map(t_point **map)
// {
// 	int i;
// 	int j;

// 	i = 0;
// 	while (map[i])
// 	{
// 		j = 0;
// 		while (map[i][j].x != -1)
// 		{
// 			ft_putnbr(map[i][j].x);
// 			ft_putchar(' ');
// 			ft_putnbr(map[i][j].y);
// 			ft_putchar(' ');
// 			ft_putnbr(map[i][j].z);
// 			ft_putchar(' ');
// 			ft_putnbr(map[i][j].color);
// 			ft_putchar('\n');
// 			j++;
// 		}
// 		ft_putchar('\n');
// 		i++;
// 	}
// }

int	main(int ac, char **av)
{
	// void	*mlx;
	// void	*mlx_win;
	// t_data	img;

	// mlx = mlx_init();
	// mlx_win = mlx_new_window(mlx, 500, 500, "Hello world!");
	// img.img = mlx_new_image(mlx, 500, 500);
	// img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
	// 		&img.endian);
	// my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
	// my_mlx_pixel_put(&img, 100, 100, 0x00FF0000);
	// ft_trace_line(&img, 0, 0, 100, 100);
	// mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	// mlx_loop(mlx);
	t_env	*env;

	if (ac != 2)
		return (ft_printf("Usage: ./fdf <filename>\n"));
	env = (t_env *)malloc(sizeof(t_env));
	if (!env)
		ft_error("Error: malloc failed");
	env->filename = av[1];
	ft_init_env(&env);
	(void)env;
	return (0);
}
