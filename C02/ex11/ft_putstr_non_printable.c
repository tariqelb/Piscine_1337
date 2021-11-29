/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-bouh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 18:28:33 by tel-bouh          #+#    #+#             */
/*   Updated: 2021/08/25 17:26:05 by tel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_convert_non_printable(int nb)
{
	char	*hex;
	int		tab[2];

	hex = "0123456789abcdef";
	if (nb < 16)
	{
		write(1, "\\0", 2);
		write(1, &hex[nb], 1);
	}
	else
	{
		tab[1] = nb / 16;
		tab[0] = nb % 16;
		write(1, "\\", 1);
		write(1, &hex[tab[1]], 1);
		write(1, &hex[tab[0]], 1);
	}
}

void	ft_putstr_non_printable(char *str)
{
	int	index;

	index = 0;
	while (str[index] != '\0')
	{
		if ((str[index] >= 0 && str[index] < 32) || str[index] == 127)
			ft_convert_non_printable((int) str[index]);
		else
			write(1, &str[index], 1);
		index++;
	}
}
