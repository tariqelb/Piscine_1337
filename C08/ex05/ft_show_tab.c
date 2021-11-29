/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-bouh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 09:40:49 by tel-bouh          #+#    #+#             */
/*   Updated: 2021/08/21 12:14:15 by tel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <unistd.h>

struct	s_stock_str	*ft_strs_to_tab(int	ac, char **av);

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

void	ft_putstr(char *str)
{
	int	index;

	index = 0;
	while (str[index] != '\0')
	{
		write(1, &str[index], 1);
		index++;
	}
}

void	ft_show_tab(struct s_stock_str *par)
{
	int	index;

	index = 0;
	while (par[index].str != 0)
	{
		ft_putstr(par[index].str);
		ft_putstr("\n");
		ft_putnbr(par[index].size);
		ft_putstr("\n");
		ft_putstr(par[index].copy);
		ft_putstr("\n");
		index++;
	}
}
