/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-bouh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 15:05:50 by tel-bouh          #+#    #+#             */
/*   Updated: 2021/08/15 13:44:45 by tel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int	index_i;
	int	index_j;

	if (argc > 1)
	{
		index_i = 0;
		while (index_i < argc - 1)
		{
			index_j = 0;
			while (argv[index_i + 1][index_j] != '\0')
			{
				write(1, &argv[index_i + 1][index_j], 1);
				index_j++;
			}
			write(1, "\n", 1);
			index_i++;
		}
	}
	return (0);
}
