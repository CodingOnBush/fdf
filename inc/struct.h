/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 12:17:51 by momrane           #+#    #+#             */
/*   Updated: 2024/01/16 11:30:33 by momrane          ###   ########.fr       */
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

typedef struct s_px
{
	int				x;
	int				y;
	int				z;
	int				color;
}					t_px;

typedef struct s_parsing
{
	t_pt			**matrix;
	int				row_cursor;
	int				col_cursor;
	int				max_row;
	int				max_col;
	int				r_power;
	int				c_power;
}					t_parsing;

typedef struct s_env
{
	void			*mlx;
	void			*win;
	char			*filename;
	int				row;
	int				col;
	int				width;
	int				height;
	struct s_point	*lst;
	struct s_img	img;
}					t_env;

#endif