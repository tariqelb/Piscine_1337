/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-bouh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 09:59:47 by tel-bouh          #+#    #+#             */
/*   Updated: 2021/08/15 13:42:11 by tel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int	index_i;
	int	index_j;

	if (argc > 1)
	{
		index_i = argc - 1;
		while (index_i > 0)
		{
			index_j = 0;
			while (argv[index_i][index_j] != '\0')
				write(1, &argv[index_i][index_j++], 1);
			write(1, "\n", 1);
			index_i--;
		}
	}
	return (0);
}
