/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-bouh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 11:37:42 by tel-bouh          #+#    #+#             */
/*   Updated: 2021/08/24 19:09:23 by tel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int	*tab, int length, int(*f)(int))
{
	int	index;
	int	*table;

	table = (void *) 0;
	table = (int *) malloc(sizeof(int) * length);
	if (table != (void *) 0)
	{
		index = 0;
		while (index < length)
		{
			table[index] = f(tab[index]);
			index++;
		}
	}
	return (table);
}
