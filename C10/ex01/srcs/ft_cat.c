/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-bouh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 13:29:32 by tel-bouh          #+#    #+#             */
/*   Updated: 2021/08/24 10:28:05 by tel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cat.h"

void	ft_display_error(char *av, int error)
{
	char	*str;
	int		i;

	write(2, "cat: ", 5);
	write(2, av, ft_strlen(av));
	write(2, ": ", 2);
	i = 0;
	str = strerror(error);
	while (str[i] != '\0')
	{
		write(2, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

void	ft_display_stdin(void)
{
	char	c;

	while (read(0, &c, 1))
		write(1, &c, 1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_display_file(char *av, int fd)
{
	int	rd;
	int	tab[BUFF];

	rd = read(fd, tab, 0);
	if (rd == -1)
		ft_display_error(av, errno);
	else
	{
		rd = read(fd, tab, BUFF);
		while (rd > 0)
		{
			write(1, tab, rd);
			rd = read(fd, tab, BUFF);
		}
		return (1);
	}
	return (0);
}

int	main(int ac, char **av)
{
	int	i;
	int	fd;
	int	cls;
	int	wrt;

	if (ac == 1)
		ft_display_stdin();
	i = 1;
	while (i < ac)
	{
		if (av[i][0] == '-')
			ft_display_stdin();
		fd = open(av[i], O_RDONLY);
		if (fd == -1)
			ft_display_error(av[i], errno);
		else
		{
			wrt = ft_display_file(av[i], fd);
			cls = close(fd);
			if (cls == -1 && wrt == 1)
				ft_display_error(av[i], errno);
		}
		i++;
	}
	return (0);
}
