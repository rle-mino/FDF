/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_putoctal_ll.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-mino <rle-mino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 14:46:30 by rle-mino          #+#    #+#             */
/*   Updated: 2016/02/02 15:33:48 by rle-mino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		pf_retoctal_ll(unsigned long long nbr, int lower)
{
	int					i;
	unsigned long long	nbr2;

	nbr2 = nbr;
	i = 0;
	while (nbr2 >= 8)
	{
		nbr2 /= 8;
		i++;
	}
	if (lower != 2)
		pf_putoctal_noflag_ll(nbr);
	return (i + 1);
}

void	pf_putoctal_noflag_ll(unsigned long long nbr)
{
	if (nbr >= 8)
	{
		pf_putoctal_noflag_ll(nbr / 8);
		ft_putchar((nbr % 8) + '0');
	}
	else
		ft_putchar((nbr % 8) + '0');
}
