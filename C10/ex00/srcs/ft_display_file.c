/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-bouh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 10:28:36 by tel-bouh          #+#    #+#             */
/*   Updated: 2021/08/24 10:20:20 by tel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_display_file.h"

void	ft_display_file(int fd)
{
	char	tab[20000];
	int		r_bytes;
	int		rd;

	rd = read(fd, tab, 0);
	if (rd == -1)
		write(2, "Cannot read file.\n", 18);
	else
	{
		r_bytes = read(fd, tab, 20000);
		while (r_bytes > 0)
		{
			write(1, tab, r_bytes);
			r_bytes = read(fd, tab, 20000);
		}
	}
}

int	main(int ac, char **av)
{
	int	fd;

	if (ac == 1)
		write(2, "File name missing.\n", 19);
	else if (ac > 2)
		write(2, "Too many arguments.\n", 20);
	else
	{
		fd = -1;
		fd = open(av[1], O_RDONLY);
		if (fd > 2)
		{
			ft_display_file(fd);
			close(fd);
		}
		else
			write(2, "Cannot read file.\n", 18);
	}
	return (0);
}
