/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-bouh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 12:12:18 by tel-bouh          #+#    #+#             */
/*   Updated: 2021/08/12 18:01:09 by tel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nb)
{
	char	tab[11];
	int		i;

	i = 0;
	if (nb < 0)
	{
		write(1, "-", 1);
		if (nb < -999999999)
		{
			tab[i++] = -(nb % 10) + 48;
			nb /= 10;
		}
		nb *= -1;
	}
	while (nb > 9)
	{
		tab[i] = (nb % 10) + 48;
		nb /= 10;
		i++;
	}
	tab[i] = nb + 48;
	while (i >= 0)
		write(1, &tab[i--], 1);
}
