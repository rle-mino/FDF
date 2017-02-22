/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_to_mlx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-mino <rle-mino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 19:59:11 by rle-mino          #+#    #+#             */
/*   Updated: 2016/02/21 08:13:57 by rle-mino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			key_func(int keycode, void *param)
{
	param = 0;
	if (keycode == 53)
		exit(0);
	return (0);
}

void		revert_y(t_fdf *grid)
{
	while (grid)
	{
		grid->y = ft_abs(grid->y);
		grid = grid->next;
	}
}

t_line		init_t_line(t_fdf *grid, int dim, int x_max)
{
	t_line		coord;
	int			size;

	size = ft_abs(dim) / 3;
	x_max++;
	coord.z = x_max;
	coord.x = ((grid->x - grid->y) * size) + RATIO_X;
	coord.y = ((grid->x + grid->y - (grid->z / 2)) * size) + RATIO_Y;
	if (dim < 0)
		while (grid->next && x_max-- > 0)
			grid = grid->next;
	else if (grid->next && grid->y == grid->next->y)
		grid = grid->next;
	coord.x2 = ((grid->x - grid->y) * size) + RATIO_X;
	coord.y2 = ((grid->x + grid->y - grid->z / 2) * size) + RATIO_Y;
	coord.dx = ft_abs(coord.x2 - coord.x);
	coord.dy = ft_abs(coord.y2 - coord.y);
	coord.sx = coord.x < coord.x2 ? 1 : -1;
	coord.sy = coord.y < coord.y2 ? 1 : -1;
	coord.e1 = (coord.dx > coord.dy ? coord.dx : -(coord.dy)) / 2;
	return (coord);
}

void		fdf_link_dots(void *mlx, void *win, t_line coord, t_fdf *grid)
{
	while (42)
	{
		mlx_pixel_put(mlx, win, coord.x, coord.y, sel_col(grid, coord));
		if (coord.x == coord.x2 && coord.y == coord.y2)
			break ;
		coord.e2 = coord.e1;
		if (coord.e2 > -coord.dx)
		{
			coord.e1 -= coord.dy;
			coord.x += coord.sx;
		}
		if (coord.e2 < coord.dy)
		{
			coord.e1 += coord.dx;
			coord.y += coord.sy;
		}
	}
}

void		fdf_to_mlx(t_fdf *grid, int si)
{
	void	*mlx;
	void	*win;
	int		y_max;
	int		x_max;

	show_me(grid);
	mlx = mlx_init();
	revert_y(grid);
	fdf_max_value(grid, &y_max, &x_max);
	si = y_max > 1080 || x_max > 1920 ? 1 : fdf_max_size(x_max, y_max);
	win = mlx_new_window(mlx, 1600, 1000, "fdf");
	while (grid)
	{
		if (grid->y <= y_max)
			fdf_link_dots(mlx, win, init_t_line(grid, -si, x_max), grid);
		if (grid->x <= x_max)
			fdf_link_dots(mlx, win, init_t_line(grid, si, x_max), grid);
		grid = grid->next;
	}
	mlx_hook(win, 2, 0, key_func, 0);
	mlx_loop(mlx);
}
