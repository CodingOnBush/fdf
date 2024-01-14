/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allblue <allblue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 09:27:51 by momrane           #+#    #+#             */
/*   Updated: 2024/01/14 20:34:41 by allblue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "../lib/ft_printf/include/ft_printf.h"
# include "../lib/libft/libft.h"
# include "../lib/mlx/mlx.h"
# include "get_next_line.h"
# include "struct.h"
# include "/opt/X11/include/X11/X.h"
# include "/opt/X11/include/X11/keysymdef.h"
# include "/opt/X11/include/X11/keysym.h"
# include <stdlib.h>

void	ft_free_points(t_point **lst);
void	ft_free_env(t_env **env);

int		ft_init_env(t_env **env, int ac, char **av);
void	ft_error(char *str);

t_point	*ft_new_point(int x, int y, int z, int color);
void	ft_add_point(t_point **lst, t_point *new);

#endif