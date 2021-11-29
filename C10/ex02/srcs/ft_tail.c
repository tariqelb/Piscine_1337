/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-bouh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 18:11:31 by tel-bouh          #+#    #+#             */
/*   Updated: 2021/08/25 18:01:51 by tel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_tail.h>

int	ft_get_nbr(char *av)
{
	int	index;
	int	nbr;

	index = 0;
	nbr = 0;
	while (av[index] != '\0')
	{
		if (!(av[index] >= '0' && av[index] <= '9'))
		{
			write(2, "tail: illegal offset -- ", 24);
			write(2, av, ft_strlen(av));
			write(2, "\n", 1);
			return (-1);
		}
		index++;
	}
	index = 0;
	while (av[index] != '\0')
	{
		nbr = nbr * 10;
		nbr = nbr + (av[index] - 48);
		index++;
	}
	return (nbr);
}

int	ft_display_bytes(int fd, int limit, int bytes)
{
	char	*tab;
	int		rd;

	tab = (void *) 0;
	if (bytes >= 0)
	{
		tab = (char *) malloc(sizeof(char) * limit);
		if (tab != (void *) 0)
			rd = read(fd, tab, limit);
		free(tab);
		tab = (void *) 0;
		tab = (char *) malloc(sizeof(char) * bytes);
		if (tab != (void *) 0)
		{
			rd = read(fd, tab, bytes);
			write(1, tab, rd);
		}
		free(tab);
	}
	return (1);
}

int	ft_display(int fd, char *av, int bytes)
{
	int		size;
	int		limit;

	size = ft_strlen_file(av);
	if (bytes <= size)
		limit = size - bytes;
	else
		limit = 0;
	if (bytes == -1)
		return (0);
	return (ft_display_bytes(fd, limit, bytes));
}

void	ft_manage_files(int index, int ac, char **av, int bytes)
{
	int		error;
	int		fd;
	int		dsp;

	error = 0;
	while (index < ac)
	{
		fd = open(av[index], O_RDONLY);
		if (fd == -1)
			error = ft_put_error(strerror(errno), av[index], 1);
		else
		{
			ft_display_header(ac, av, index);
			dsp = ft_display(fd, av[index], bytes);
		}
		ft_close(fd, av[index], error, dsp);
		index++;
	}
}

int	main(int ac, char **av)
{
	int		index;
	int		bytes;
	char	tab[100];

	if (ac == 1)
		ft_put_error(tab, *av, 0);
	else if (ac == 2)
	{
		bytes = ft_get_nbr(av[1]);
		if (bytes != -1)
			while (1)
				read(1, tab, BUFF);
	}
	else
	{
		index = 2;
		bytes = ft_get_nbr(av[1]);
		if (bytes == -1)
			return (0);
		ft_manage_files(index, ac, av, bytes);
	}
	return (0);
}
