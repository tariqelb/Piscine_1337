/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-bouh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 14:37:30 by tel-bouh          #+#    #+#             */
/*   Updated: 2021/08/24 18:56:51 by tel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_if(char **tab, int length, int(*f)(char *))
{
	int	index;
	int	rst;

	rst = 0;
	index = 0;
	while (index < length)
	{
		if (f(tab[index]) > 0)
			rst = rst + 1;
		index++;
	}
	return (rst);
}
