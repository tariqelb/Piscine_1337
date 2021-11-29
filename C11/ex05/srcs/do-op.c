/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-bouh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 15:40:50 by tel-bouh          #+#    #+#             */
/*   Updated: 2021/08/25 10:09:50 by tel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_do_op.h"

int	ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	nbr;

	nbr = 0;
	sign = 1;
	i = 0;
	while (str[i] == '\t' || str[i] == '\f' || str[i] == '\r'
		|| str[i] == '\v' || str[i] == '\n' || str[i] == ' ')
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = sign * -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr = nbr * 10;
		nbr = nbr + (str[i] - 48);
		i++;
	}
	return (nbr * sign);
}

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
	write(1, "\n", 1);
}

int	ft_oper(char *op)
{
	int		index;
	char	*tab;

	tab = "+-/*%";
	index = 0;
	while (index < 5)
	{
		if (*op == tab[index])
			return (index);
		index++;
	}
	write(1, "0\n", 2);
	return (-1);
}

int	main(int ac, char **av)
{
	int			nbr1;
	int			nbr2;
	int			op;
	t_funptr	op_f;

	if (ac != 4)
		return (0);
	nbr1 = ft_atoi(av[1]);
	nbr2 = ft_atoi(av[3]);
	op = ft_oper(av[2]);
	if (op == -1)
		return (0);
	op_f[0] = &ft_add;
	op_f[1] = &ft_sub;
	op_f[2] = &ft_div;
	op_f[3] = &ft_mult;
	op_f[4] = &ft_mod;
	op_f[op](nbr1, nbr2);
	return (0);
}
