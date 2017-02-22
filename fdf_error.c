/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-mino <rle-mino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 10:30:28 by rle-mino          #+#    #+#             */
/*   Updated: 2016/02/18 15:49:23 by rle-mino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			fdf_usage(void)
{
	fpf("usage : ./fdf <file>\n");
	return (0);
}

int			fdf_error(int flag)
{
	if (flag == MAP_ERROR)
	{
		fpf("map error\n");
		exit(0);
	}
	else if (flag == OPEN_ERROR)
	{
		ft_putendl_fd("open error", 2);
		exit(0);
	}
	return (0);
}
