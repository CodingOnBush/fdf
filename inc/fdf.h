/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 09:27:51 by momrane           #+#    #+#             */
/*   Updated: 2024/02/29 17:16:21 by momrane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "../lib/ft_printf/include/ft_printf.h"
# include "../lib/libft/libft.h"
# include "../lib/mlx/mlx.h"
# include "get_next_line.h"
# include "struct.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <math.h>
# include <stdlib.h>

# include <stdio.h>

void	ft_draw_dda(t_env *env, int r, int c);

void	ft_put_pixel(t_env *env, int x, int y, int color);
void	ft_draw(t_env *env);

void	ft_init_env_values(t_env *env, char *filename);
int		ft_init_env(t_env *env, char *f);

void	ft_exit_error(char *str);
void	*ft_free_matrix(t_pt **matrix, int rows);
void	ft_free_env(t_env *env);
int		ft_free_env_err(t_env *env, char *msg);

int		ft_key_hook(int keycode, t_env *env);

void	ft_trigger_hooks(t_env *env);

void	ft_init_img(t_env *env);
void	ft_clear_img(t_env *env);

t_pt	**ft_new_matrix(int r, int c);
void	ft_parse_matrix(t_env *env, void (*f)(t_env *env, int r, int c));

int		ft_parse_map(t_env *env);

void	ft_move_map_points(t_env *env, int r, int c);
void	ft_convert_points(t_env *env, int r, int c);

int		ft_count_cols(char *line);
int		ft_get_color(char *str);
void	ft_set_zoom(t_env *env);

#endif