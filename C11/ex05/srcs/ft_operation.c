/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-bouh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 16:18:51 by tel-bouh          #+#    #+#             */
/*   Updated: 2021/08/24 17:44:22 by tel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_do_op.h"

void	ft_add(int nbr1, int nbr2)
{
	ft_putnbr(nbr1 + nbr2);
}

void	ft_sub(int nbr1, int nbr2)
{
	ft_putnbr(nbr1 - nbr2);
}

void	ft_div(int nbr1, int nbr2)
{
	if (nbr2 == 0)
		write(1, "Stop : division by zero\n", 24);
	else
		ft_putnbr(nbr1 / nbr2);
}

void	ft_mult(int nbr1, int nbr2)
{
	ft_putnbr(nbr1 * nbr2);
}

void	ft_mod(int nbr1, int nbr2)
{
	if (nbr2 == 0)
		write(1, "Stop : modulo by zero\n", 22);
	else
		ft_putnbr(nbr1 % nbr2);
}
