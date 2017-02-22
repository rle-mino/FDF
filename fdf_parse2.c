/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_parse2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-mino <rle-mino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 00:41:05 by rle-mino          #+#    #+#             */
/*   Updated: 2016/02/21 08:13:16 by rle-mino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			fdf_max_size(int x, int y)
{
	int		i;

	i = 0;
	while (x * i < 1600 && y * i < 1000)
		i++;
	return (i);
}

void		fdf_max_value(t_fdf *grid, int *y, int *x)
{
	*x = 0;
	*y = 0;
	while (grid)
	{
		if (*x != grid->x)
			*x = grid->x;
		if (*y != ft_abs(grid->y))
			*y = ft_abs(grid->y);
		grid = grid->next;
	}
}

int			is_atoiable(char *tab)
{
	int		i;

	i = -1;
	while (tab[++i])
	{
		if (tab[i] == '\n')
			return (0);
		if (ft_isdigit(tab[i]) || (tab[i] == '-' && ft_isdigit(tab[i + 1])))
			return (1);
	}
	return (0);
}

int			fdf_parse_struct(t_fdf *grid)
{
	int		y;
	int		i;
	int		x;

	y = 0;
	i = 0;
	while (grid && grid->y == y)
	{
		i++;
		grid = grid->next;
	}
	while (grid)
	{
		y--;
		x = 0;
		while (grid && grid->y == y)
		{
			grid = grid->next;
			x++;
		}
		if (x != i)
			return (0);
	}
	return (1);
}
