/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-mino <rle-mino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 09:40:40 by rle-mino          #+#    #+#             */
/*   Updated: 2016/02/21 07:56:21 by rle-mino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <math.h>
# include <mlx.h>
# include "libft.h"
# include <fcntl.h>
# include <stdio.h>

# define MAP_ERROR 3
# define RATIO_Y 50
# define RATIO_X 700
# define OPEN_ERROR 2
# define X_TO_X 0
# define X_TO_Y 1
# define MAX_X 0
# define MAX_Y 1
# define DEBUG fpf("%s - %d - %s\n", __func__, __LINE__, __FILE__);

typedef	struct	s_fdf
{
	int				x;
	int				y;
	int				z;
	int				fact;
	void			*mlx;
	void			*win;
	int				x_max;
	int				y_max;
	struct s_fdf	*next;
}				t_fdf;

typedef struct	s_line
{
	int				x;
	int				y;
	int				z;
	int				x2;
	int				y2;
	int				dx;
	int				dy;
	int				sx;
	int				sy;
	int				e1;
	int				e2;
}				t_line;

int				fdf_usage(void);
void			show_me(t_fdf *grid);
int				fdf_error(int flag);
char			*fdf_fill_map(int fd);
int				is_atoiable(char *tab);
int				fdf_parse_map(t_fdf **grid, char *map, int x, int y);
int				fdf_parse_struct(t_fdf *grid);
int				fdf_is_valid(char c);
void			fdf_to_mlx(t_fdf *grid, int size);
void			fdf_link_dot(t_fdf *grid, void *mlx, void *win);
void			fdf_max_value(t_fdf *grid, int *y, int *x);
int				fdf_max_size(int x, int y);
int				sel_col(t_fdf *grid, t_line coord);
t_line			init_t_line(t_fdf *grid, int dim, int x_max);
void			fdf_link_dots(void *mlx, void *win, t_line coord, t_fdf *grid);

#endif
