/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disply_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-mino <rle-mino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 02:42:15 by rle-mino          #+#    #+#             */
/*   Updated: 2016/02/21 05:38:18 by rle-mino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int				sel_col(t_fdf *grid, t_line coord)
{
	if (grid->z != 0 || (grid->next && grid->next->z))
		return (0x70C6D9);
	while (grid->next && coord.z-- > 0)
		grid = grid->next;
	if (grid->z != 0 || (grid->next && grid->next->z))
		return (0x70C6D9);
	return (0xFFFFFF);
}

void			show_me(t_fdf *grid)
{
	int		g;

	g = 0;
	while (grid)
	{
		if (grid->y < g)
		{
			g--;
			fpf("\n");
		}
		fpf("%-3d", grid->z);
		grid = grid->next;
	}
	fpf("\n");
}
