/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-bouh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 19:33:46 by tel-bouh          #+#    #+#             */
/*   Updated: 2021/08/25 17:16:16 by tel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_address(long int address)
{
	char	*hex;
	int		tab[16];
	int		index;
	int		index_j;

	index = 0;
	hex = "0123456789abcdef";
	while (address > 0)
	{
		tab[index++] = address % 16;
		address /= 16;
	}
	index_j = index;
	while (index_j < 16)
	{
		write(1, "0", 1);
		index_j++;
	}
	while (--index >= 0)
		write(1, &hex[tab[index]], 1);
	write(1, ":", 1);
}

void	ft_print_hex(char *str, int index_i, int size)
{
	int		index_j;
	char	*hex;

	hex = "0123456789abcdef";
	index_j = index_i + 16;
	while (index_i < index_j && index_i < size)
	{
		if (index_i % 2 == 0)
			write(1, " ", 1);
		write(1, &hex[str[index_i] / 16], 1);
		write(1, &hex[str[index_i] % 16], 1);
		index_i++;
	}
	while (index_i < index_j)
	{
		write(1, "  ", 2);
		if (index_i % 2 == 0)
			write(1, " ", 1);
		index_i++;
	}
}

int	ft_putstr(char *str, int index_i, int size)
{
	int	index_j;

	index_j = index_i + 16;
	write(1, " ", 1);
	while (index_i < index_j && index_i < size)
	{
		if (str[index_i] >= 32 && str[index_i] <= 127)
		{
			write(1, &str[index_i], 1);
		}
		else
			write(1, ".", 1);
		index_i++;
	}
	write(1, "\n", 1);
	return (16);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	index_i;
	char			*str;

	str = (char *) addr;
	index_i = 0;
	while (index_i < size)
	{
		ft_print_address((long int)&str[index_i]);
		ft_print_hex(str, index_i, size);
		index_i += ft_putstr(str, index_i, size);
	}
	return (addr);
}
