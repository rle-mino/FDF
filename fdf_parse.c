/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-mino <rle-mino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 19:18:50 by rle-mino          #+#    #+#             */
/*   Updated: 2016/02/21 01:12:28 by rle-mino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int				fdf_is_valid(char c)
{
	if ((c <= '9' && c >= '0') || c == '\n' || c == ' ' || c == '-')
		return (1);
	return (0);
}

static void		fdf_fill_struct(t_fdf **grid, int *x, int y, char *map)
{
	(*grid)->y = y;
	(*grid)->x = *x;
	(*grid)->z = ft_atoi(map);
	(*grid)->next = NULL;
	*x += 1;
}

static void		fdf_for_ret(char *tab, int *y, int *x, t_fdf **grid)
{
	int		i;

	i = 0;
	while (tab[i])
	{
		if (is_atoiable(tab + 1 + i) && tab[i] == '\n')
		{
			(*grid)->next = ft_memalloc(sizeof(t_fdf));
			(*grid) = (*grid)->next;
			*y -= 1;
			*x = 0;
			fdf_fill_struct(grid, x, *y, tab + i + 1);
		}
		i++;
	}
}

int				fdf_parse_map(t_fdf **grid, char *map, int x, int y)
{
	char	**tab;
	int		i;
	t_fdf	*save;

	i = 0;
	tab = ft_strsplit(map, ' ');
	*grid = ft_memalloc(sizeof(t_fdf));
	save = *grid;
	fdf_fill_struct(grid, &x, y, tab[i]);
	while (tab[++i])
	{
		if (tab[i][0] == '\n' && tab[i]++)
			y--;
		if (is_atoiable(tab[i]))
		{
			(*grid)->next = ft_memalloc(sizeof(t_fdf));
			*grid = (*grid)->next;
			fdf_fill_struct(grid, &x, y, tab[i]);
			fdf_for_ret(tab[i], &y, &x, grid);
		}
	}
	*grid = save;
	return (fdf_parse_struct(*grid));
}
