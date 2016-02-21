/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-mino <rle-mino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 09:38:50 by rle-mino          #+#    #+#             */
/*   Updated: 2016/02/21 01:07:59 by rle-mino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			main(int argc, char **argv)
{
	int		fd;
	char	*map;
	t_fdf	*grid;

	if (argc != 2)
		return (fdf_usage());
	if ((fd = open(argv[1], O_RDONLY)) <= 0)
		fdf_error(OPEN_ERROR);
	if ((map = fdf_fill_map(fd)) == NULL || ft_strlen(map) == 0)
		return (fdf_error(MAP_ERROR));
	if (fdf_parse_map(&grid, map, 0, 0) == 0)
		return (fdf_error(MAP_ERROR));
	fdf_to_mlx(grid, 0);
	return (0);
}
