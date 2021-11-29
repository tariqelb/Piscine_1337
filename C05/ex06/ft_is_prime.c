/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-bouh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 09:49:13 by tel-bouh          #+#    #+#             */
/*   Updated: 2021/08/19 17:10:24 by tel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	i;

	i = 3;
	if (nb < 2 || nb % 2 == 0)
		return (0);
	if (nb == 2)
		return (1);
	while (i * i < nb)
	{
		if (nb % i == 0)
			return (0);
		i = i + 2;;
	}
	return (1);
}

#include <stdio.h>

int	main()
{
	printf("%d\n", ft_is_prime(2147483647));
	return (0);
}
