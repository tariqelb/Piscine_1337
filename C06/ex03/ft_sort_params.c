/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-bouh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 10:08:15 by tel-bouh          #+#    #+#             */
/*   Updated: 2021/08/15 13:58:55 by tel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_swap_str(char **s1, char **s2)
{
	char	*temp;

	temp = *s1;
	*s1 = *s2;
	*s2 = temp;
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

void	ft_sort_params(char **argv, int argc)
{
	int	i;

	i = 1;
	while (i < argc - 1)
	{
		if (ft_strcmp(argv[i], argv[i + 1]) > 0)
		{
			ft_swap_str(&argv[i], &argv[i + 1]);
			i = 0;
		}
		i++;
	}	
}

int	main(int argc, char **argv)
{
	int	index_i;
	int	index_j;

	if (argc > 1)
	{
		ft_sort_params(argv, argc);
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
