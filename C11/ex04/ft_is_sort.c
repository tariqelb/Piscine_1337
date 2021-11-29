/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-bouh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 14:52:17 by tel-bouh          #+#    #+#             */
/*   Updated: 2021/08/25 10:08:13 by tel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int	*tab, int length, int (*f)(int, int))
{
	int	a_order;
	int	d_order;
	int	index;

	if (length == 0)
		return (1);
	index = 0;
	a_order = 1;
	d_order = 1;
	while (index < length - 1)
	{
		if (f(tab[index], tab[index + 1]) < 0)
			a_order += 1;
		if (f(tab[index], tab[index + 1]) > 0)
			d_order += 1;
		if (f(tab[index], tab[index + 1]) == 0)
		{
			a_order += 1;
			d_order += 1;
		}
		index++;
	}
	if (a_order == length || d_order == length)
		return (1);
	return (0);
}
