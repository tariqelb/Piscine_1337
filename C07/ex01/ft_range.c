/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-bouh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 15:35:37 by tel-bouh          #+#    #+#             */
/*   Updated: 2021/08/26 15:56:32 by tel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*tab;
	int	size;

	tab = (void *) 0;
	if (min >= max)
		return (0);
	tab = (int *) malloc(sizeof(int) * (max - min));
	if (tab != (void *) 0)
	{
		size = 0;
		while (min < max)
			tab[size++] = min++;
	}
	return (tab);
}
