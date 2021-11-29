/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-bouh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 09:05:46 by tel-bouh          #+#    #+#             */
/*   Updated: 2021/08/07 14:02:49 by tel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb(void)
{
	char	index_i;
	char	index_j;
	char	index_k;

	index_i = '0';
	while (index_i < '8')
	{
		index_j = index_i + 1;
		while (index_j < '9')
		{
			index_k = index_j + 1;
			while (index_k <= '9')
			{
				write(1, &index_i, 1);
				write(1, &index_j, 1);
				write(1, &index_k, 1);
				if (index_i != '7')
					write(1, ", ", 2);
				index_k++;
			}
			index_j++;
		}
		index_i++;
	}
}
