#ifndef DEFINES_H
# define DEFINES_H

typedef struct s_data
{
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
}					t_data;

typedef struct s_point
{
	int				x;
	int				y;
	int				z;
	int				color;
}					t_point;

typedef struct s_env
{
	int				row;
	int				col;
	char			*filename;
	struct s_point	**map;
}					t_env;

#endif