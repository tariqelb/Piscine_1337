/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-bouh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 10:28:59 by tel-bouh          #+#    #+#             */
/*   Updated: 2021/08/12 18:10:20 by tel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_check_base(char *base)
{
	int	i;
	int	j;

	i = -1;
	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	while (base[++i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
	}
	i = 0;
	while (base[i] != '\0')
	{
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (i);
}

void	ft_convert_base(int nbr, char *base, int base_len)
{
	int	tab[33];
	int	i;

	i = 0;
	if (nbr == -2147483648)
	{
		tab[i] = -(nbr % base_len);
		nbr /= base_len;
		i++;
		nbr *= -1;
	}
	else if (nbr < 0)
		nbr = nbr * -1;
	while (nbr > 0)
	{
		tab[i] = nbr % base_len;
		nbr /= base_len;
		i++;
	}
	while (--i >= 0)
	{
		write(1, &base[tab[i]], 1);
	}
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		base_len;

	base_len = ft_check_base(base);
	if (base_len > 0)
	{
		if (nbr < 0)
			write(1, "-", 1);
		if (nbr == 0)
			write(1, "0", 1);
		ft_convert_base(nbr, base, base_len);
	}
}
