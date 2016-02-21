/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-mino <rle-mino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 14:20:23 by rle-mino          #+#    #+#             */
/*   Updated: 2016/02/18 15:55:18 by rle-mino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	no_digit(char *map)
{
	int		i;

	i = -1;
	while (map[++i])
	{
		if (ft_isdigit(map[i]))
			return (1);
	}
	return (0);
}

char		*fdf_fill_map(int fd)
{
	char	*line;
	char	*map;
	char	*tmp;

	map = ft_memalloc(1);
	while (get_next_line(fd, &line) > 0)
	{
		tmp = map;
		map = ft_strjoin(map, line);
		free(tmp);
		tmp = map;
		map = ft_strjoin(map, "\n");
		free(line);
		free(tmp);
		if (fdf_is_valid(map[0]) == 0)
		{
			free(map);
			return (NULL);
		}
	}
	map[ft_strlen(map) - 1] = '\0';
	if (no_digit(map) == 0)
		return (NULL);
	return (map);
}
