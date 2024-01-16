/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 12:17:51 by momrane           #+#    #+#             */
/*   Updated: 2024/01/16 14:57:23 by momrane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

typedef struct s_img
{
	void			*img_ptr;
	char			*img_pixels_ptr;
	int				bits_per_pixel;
	int				endian;
	int				line_len;
}					t_img;

typedef struct s_point
{
	int				x;
	int				y;
	int				z;
	int				color;
	struct s_point	*next;
}					t_point;

typedef struct s_pt
{
	int				x;
	int				y;
	int				z;
	int				color;
}					t_pt;

typedef struct s_parsing
{
	struct s_pt		**matrix;
	int				row;
	int				col;
	int				r;
	int				c;
	char			*filename;
}					t_parsing;

typedef struct s_env
{
	void				*mlx_ptr;
	void				*win_ptr;
	int					width;
	int					height;
	struct s_parsing	data;
	struct s_img		img;
}					t_env;

#endif